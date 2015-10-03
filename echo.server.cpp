/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 *  Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 echo.server.cpp -o echo.server -lboost_system
 *
 *  Usage:
 *      [console 1] $ ./echo.server
 *      [console 2] $ ./echo.client text
 *      [console 2] $ server echo: text
 */
#include <iostream>

#include <boost/asio.hpp>
namespace asio = boost::asio;

void handle_connections()
{
    asio::io_service io_service;
    asio::ip::tcp::endpoint endpoint( asio::ip::tcp::v4(), 8001 );
    asio::ip::tcp::acceptor acceptor( io_service, endpoint );

    char buffer[ 32 ];

    while( true )
    {
        asio::ip::tcp::socket socket( io_service );
        acceptor.accept( socket );

        int const bytes = socket.read_some( asio::buffer( buffer ) );
        socket.write_some( asio::buffer( buffer, bytes ) );

        socket.close();
    }
}

int main()
{
    handle_connections();
}

