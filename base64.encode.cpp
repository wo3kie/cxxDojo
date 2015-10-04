/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 *  Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 base64.encode.cpp -o base64.encode
 *
 *  Usage:
 *      $ ./base64.encode "Hello World"
 *      SGVsbG8gV29ybGQ
 */

#include <iostream>
#include <string>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>

std::string base64encode( std::string const & text )
{
    using namespace boost::archive::iterators;

    typedef base64_from_binary< transform_width< const char *, 6, 8 > >  base64_text;

    std::string encoded;

    std::copy(
        base64_text( & * text.begin() ),
        base64_text( & * text.end() ),
        std::back_inserter( encoded )
    );  

    return encoded;
}

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

