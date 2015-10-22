/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 get.request.cpp -o get.request -lboost_system -lboost_thread -pthread
 *
 * Usage:
 *      $ ./get.request http://www.boost.org LICENSE_1_0.txt www.boost.org 80 ""
 *      > Date: Sun, 04 Oct 2015 09:32:39 GMT
 *      > Server: Apache/2.2.15 (Red Hat)
 *      > Last-Modified: Sun, 15 Dec 2013 02:55:11 GMT
 *      > ETag: "2c53e9-53a-4ed89d2e171f1"
 *      > Accept-Ranges: bytes
 *      > Content-Length: 1338
 *      > Connection: close
 *      > Content-Type: text/plain
 *
 *      Boost Software License - Version 1.0 - August 17th, 2003
 *
 *      Permission is hereby granted, free of charge, to any person or organization
 *      obtaining a copy of the software and accompanying documentation covered by
 *      ...
 *
 * Usage:
 *      $ ./get.request http://www.boost.org LICENSE_1_0.txt proxy_server proxy_port \
 *          `echo -n "my_login:my_password" | base64`
 *
 */

#include <iostream>
#include <string>

#include <boost/asio.hpp>

namespace asio = boost::asio;

int main( int argc, char * argv[] )
{
    if( argc != 6 ){
        std::cerr << "Usage: " << argv[0] << " host file proxy_host proxt_port authorization" << std::endl;
        return 1;
    }

    std::string const host = argv[1];
    std::string const file = argv[2];
    std::string const proxyHost = argv[3];
    std::string const proxyPort = argv[4];
    std::string const authorization = argv[5];

    asio::io_service io_service;

    asio::ip::tcp::resolver resolver( io_service );
    asio::ip::tcp::resolver::query const query( proxyHost, proxyPort );
    asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve( query );

    asio::ip::tcp::socket socket( io_service );
    asio::connect( socket, endpointIterator );

    asio::streambuf requestBuffer;
    std::ostream requestStream( & requestBuffer );

    requestStream << "GET " << host << "/" << file << " HTTP/1.0\r\n";
    requestStream << "Host: " << host << "\r\n";
    requestStream << "Accept: */*\r\n";
    
    if( authorization != "" ){
        requestStream << "Proxy-Authorization: Basic " << authorization << "\n\r";
    }

    requestStream << "Connection: close\r\n\r\n";
    asio::write( socket, requestBuffer );

    asio::streambuf response_buffer;
    std::istream responseStream( & response_buffer );

    asio::read_until( socket, response_buffer, "\r\n");

    std::string httpVersion;
    responseStream >> httpVersion;

    unsigned status_code;
    responseStream >> status_code;

    std::string status_message;
    std::getline( responseStream, status_message );

    if( ! responseStream || httpVersion.substr( 0, 5 ) != "HTTP/" )
    {
        std::cerr << "Invalid response\n";
        return 2;
    }

    if( status_code != 200 )
    {
        std::cerr << "Response returned with status code " << status_code << "\n";
        return 3;
    }

    asio::read_until( socket, response_buffer, "\r\n\r\n" );

    std::string header;
    while( std::getline( responseStream, header ) && header != "\r" ){
        std::cout << "> " << header << "\n";
    }

    std::cout << std::endl;

    boost::system::error_code error;
    while( asio::read( socket, response_buffer, asio::transfer_at_least( 1 ), error ) ){
        std::cout << & response_buffer;
    }

    if( error != asio::error::eof ){
        std::cerr << boost::system::system_error( error ).what() << "\n";
        return 4;
    }

    return 0;
}

