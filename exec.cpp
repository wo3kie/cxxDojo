/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 exec.cpp -o exec
 *
 * Usage:
 *      $ ./exec ls
 *      exec
 *      exec.cpp
 */

#include <iostream>
#include <functional>
#include <string>
#include <stdio.h>

bool exec(
    char const * const command,
    std::function< void ( char const * ) > const onRead
)
{
    FILE * const pipe = popen( command, "r" );

    if( ! pipe ){
        return false;
    }

    char buffer[ 4 * 1024 ];

    while( ! feof( pipe ) )
    {
        if( fgets( buffer, sizeof( buffer ), pipe ) ){
            onRead( buffer );
        }
    }

    pclose( pipe );

    return true;
}

int main( int argc, char* argv[] )
{
    if( argc != 2 )
    {
        std::cerr << "Usage: " << argv[0] << " command" << std::endl;
        return 1;
    }

    auto const print = []( char const * p ){
        std::cout << p;
    };

    return exec( argv[ 1 ], print ) ? 0 : 1;
}

