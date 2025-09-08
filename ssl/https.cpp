/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 https.cpp -o https -lssl
 *
 * Usage:
 *      $ ./https "test" "oRCO/U6JyPR/Og..."
 *
 *      <feed xmlns:base="https://api.datamarket.azure.com/Data.ashx/Bing/Search/Web"
 *        xmlns:d="http://schemas.microsoft.com/ado/2007/08/dataservices"
 *        xmlns:m="http://schemas.microsoft.com/ado/2007/08/dataservices/metadata"
 *        xmlns="http://www.w3.org/2005/Atom"
 *      >
 *        <title type="text">test</title>
 *        <subtitle type="text">Bing Web Search</subtitle>
 *        <id>https://api.datamarket.azure.com/Data.ashx/Bing/Search/Web?Query='test'</id>
 *        <rights type="text" />
 *        ...
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

#include <boost/algorithm/string/replace.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/bind.hpp>

#include "../base64.encode.hpp"

class HttpsClient {
public:
  HttpsClient(
      boost::asio::io_service& io_service,
      boost::asio::ssl::context& context,
      boost::asio::ip::tcp::resolver::iterator endpoint_iterator,
      std::string const host,
      std::string const& resource,
      std::string const& basicAuthenticationToken,
      std::function<void(char const*, unsigned)> responseCallback)
      : socket_(io_service, context)
      , host_(host)
      , resource_(resource)
      , basicAuthenticationToken_(basicAuthenticationToken)
      , responseCallback_(responseCallback) {
    socket_.set_verify_mode(boost::asio::ssl::context::verify_none);
    socket_.set_verify_callback(boost::bind(&HttpsClient::verify_certificate, this, _1, _2));

    boost::asio::async_connect(
        socket_.lowest_layer(),
        endpoint_iterator,
        boost::bind(&HttpsClient::handle_connect, this, boost::asio::placeholders::error));
  }

private:
  bool verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx) {
    char subject_name[4 * 1024];
    X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
    X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
    return preverified;
  }

  void handle_connect(const boost::system::error_code& error) {
    if(error) {
      std::cout << "Connect failed: " << error.message() << std::endl;
    } else {
      socket_.async_handshake(
          boost::asio::ssl::stream_base::client,
          boost::bind(&HttpsClient::handle_handshake, this, boost::asio::placeholders::error));
    }
  }

  void handle_handshake(const boost::system::error_code& error) {
    if(error) {
      std::cout << "Handshake failed: " << error.message() << std::endl;
    } else {
      std::stringstream request_;

      request_ << "POST " + resource_ + " HTTP/1.1\r\n";
      request_ << "Host: " + host_ + "\r\n";
      request_ << "Accept-Encoding: none\r\n";
      request_ << "Connection: close\r\n";
      request_ << "Accept: */*\r\n";
      request_ << "Authorization: Basic " + basicAuthenticationToken_ + "\r\n";
      request_ << "Content-Length: 0\r\n";
      request_ << "\r\n";

      boost::asio::async_write(
          socket_,
          boost::asio::buffer(request_.str()),
          boost::bind(
              &HttpsClient::handle_write,
              this,
              boost::asio::placeholders::error,
              boost::asio::placeholders::bytes_transferred));
    }
  }

  void handle_write(const boost::system::error_code& error, size_t bytesTransferred) {
    if(! error) {
      boost::asio::async_read(
          socket_,
          boost::asio::buffer(reply_),
          boost::bind(
              &HttpsClient::handleRead,
              this,
              boost::asio::placeholders::error,
              boost::asio::placeholders::bytes_transferred));
    } else {
      std::cout << "Write failed: " << error.message() << std::endl;
    }
  }

  void handleRead(const boost::system::error_code& error, size_t bytesTransferred) {
    if(bytesTransferred == 0) {
      return;
    }

    if(! error) {
      std::cout.write(reply_, bytesTransferred);

      boost::asio::async_read(
          socket_,
          boost::asio::buffer(reply_),
          boost::asio::transfer_at_least(1),
          boost::bind(
              &HttpsClient::handleRead,
              this,
              boost::asio::placeholders::error,
              boost::asio::placeholders::bytes_transferred));
    } else if(error != boost::asio::error::eof) {
      std::cout << "Read failed: " << error.message() << std::endl;
    }
  }

private:
  boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;

  std::string host_;
  std::string resource_;
  std::string basicAuthenticationToken_;

  std::function<void(char const*, unsigned)> responseCallback_;

  char reply_[4 * 1024];
};

std::string
getHttpsResponse(std::string const host, std::string const resource, std::string const basicAuthenticationToken) {
  std::string response;

  boost::asio::io_service io_service;
  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(host, "https");
  boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);
  boost::asio::ssl::context context(boost::asio::ssl::context::sslv23);

  auto const responseCallback = [&response](char const* data, unsigned size) {
    response += std::string(data, data + size);
  };

  HttpsClient client(io_service, context, iterator, host, resource, basicAuthenticationToken, responseCallback);

  io_service.run();

  return response;
}

std::string encodeQuery(std::string query) {
  boost::algorithm::replace_all(query, "+", "%2B");
  boost::algorithm::replace_all(query, " ", "+");

  return query;
}

std::string bingWebSearchQuery(std::string const query, std::string const basicAuthenticationToken) {
  // todo white spaces escaping in query

  std::string const host = "api.datamarket.azure.com";
  std::string const resource = "/Bing/Search/Web?Query=%27" + encodeQuery(query) + "%27";

  std::string const response = getHttpsResponse("api.datamarket.azure.com", resource, basicAuthenticationToken);

  return response;
}

int main(int argc, char* argv[]) {
  try {
    std::string const query = argv[1];

    std::string const bingKeyId = argv[2];

    std::string const basicAuthenticationToken = base64encode(bingKeyId + ":" + bingKeyId);

    std::string const response = bingWebSearchQuery(query, basicAuthenticationToken);

    std::cout << response << std::endl;
  } catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
