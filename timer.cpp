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


#include <chrono>
#include <iostream>

template< typename T > 
void test( T const & t ) 
{
    // typedef ratio< 1,  1000000000000000000 > atto;
    // typedef ratio< 1,     1000000000000000 > femto;
    // typedef ratio< 1,        1000000000000 > pico;
    // typedef ratio< 1,           1000000000 > nano;
    // typedef ratio< 1,              1000000 > micro;
    // typedef ratio< 1,                 1000 > milli;
    // typedef ratio< 1,                  100 > centi;
    // typedef ratio< 1,                   10 > deci;
    //
    // typedef ratio< 10,                   1 > deca;
    // typedef ratio< 100,                  1 > hecto;
    // typedef ratio< 1000,                 1 > kilo;
    // typedef ratio< 1000000,              1 > mega;
    // typedef ratio< 1000000000,           1 > giga;
    // typedef ratio< 1000000000000,        1 > tera;
    // typedef ratio< 1000000000000000,     1 > peta;
    // typedef ratio< 1000000000000000000,  1 > exa;


    // typedef duration<int64_t, nano       > nanoseconds;
    // typedef duration<int64_t, micro      > microseconds;
    // typedef duration<int64_t, milli      > milliseconds;
    // typedef duration<int64_t             > seconds;
    // typedef duration<int64_t, ratio<  60>> minutes;
    // typedef duration<int64_t, ratio<3600>> hours;    

    std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::nanoseconds
    >   
    const & start = std::chrono::high_resolution_clock::now();

    t(); 

    std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::nanoseconds
    >   
    const & end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<
        long int,
        std::nano
    >   
    const & diff = end - start;

    std::cout
        << std::chrono::duration_cast< std::chrono::microseconds >( diff ).count()
        << "µs"
        << std::endl;
}

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

