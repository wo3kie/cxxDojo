/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 base64.encode.cpp -o base64.encode
 *
 * Usage:
 *      $ ./base64.encode "Hello World"
 *      SGVsbG8gV29ybGQ
 */

#include "./base64.encode.hpp"

int main( int argc, char * argv[] )
{
    if( argc != 2 )
    {
        std::cerr << "Usage: " << argv[0] << " text" << std::endl;
        return 1;
    }

    std::cout << base64encode( argv[1] ) << std::endl;

    return 0;
}
