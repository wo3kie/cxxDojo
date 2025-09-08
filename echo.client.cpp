/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 echo.client.cpp -o echo.client -lboost_system
 *
 * Usage:
 *      [console 1] $ ./echo.server
 *      [console 2] $ ./echo.client text
 *      [console 2] server echo: text
 */

#include <iostream>

#include <boost/asio.hpp>
namespace asio = boost::asio;

void echo(std::string message) {
  message += "\n";

  asio::io_service service;

  asio::ip::tcp::endpoint endpoint(asio::ip::address::from_string("127.0.0.1"), 8001);

  asio::ip::tcp::socket socket(service);
  socket.connect(endpoint);

  socket.write_some(asio::buffer(message));

  char buffer[32];
  int const bytes = socket.read_some(asio::buffer(buffer));

  std::cout << "server echo: " << std::string(buffer, bytes) << std::endl;
}

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage: " << argv[0] << " text" << std::endl;
    return 1;
  }

  echo(argv[1]);

  return 0;
}
