/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 timer.cpp -o timer
 *
 * Usage:
 *      $ ./timer
 */

#include "timer.hpp"

int main()
{
    test(
        []() -> void
        {   
            for( int i = 0 ; i < 10 ; ++ i ){
                std::cout << i << std::endl;
            }
        }
    );
}

