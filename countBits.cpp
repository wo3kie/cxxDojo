/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 countBits.cpp -o countBits
 *
 * Usage:
 *      $ ./countBits
 */


#include <cassert>
#include <random>

#include <boost/preprocessor/repetition/repeat.hpp>

constexpr int countBits8(unsigned char i){
    return 
        i == 0
        ? 0
        : (i & 1) + countBits8(i / 2);
}

#define COUNT_BITS_CALCULATE(z, n, data) \
    countBits8(n),

int countBits(
    unsigned char const * begin, 
    unsigned char const * const end
){
    constexpr int bits[256] = {
        BOOST_PP_REPEAT(256, COUNT_BITS_CALCULATE, "")
    };

    int result = 0;

    for( ; begin != end; ++begin){
        result += bits[ * begin ];
    }

    return result;
}

template<typename T>
int countBits(T const & t){
    unsigned char const * const begin 
        = reinterpret_cast< unsigned char const * >( & t );

    return countBits(begin, begin + sizeof(T));
}


int main(){
    for(int i = 0; i < 256; ++i){
        assert(countBits8(i) == __builtin_popcount(i));
    }

    for(int i = 0; i < 256; ++i){
        assert(countBits(i) == __builtin_popcount(i));
    }

    for(int i = 0; i < 1e4; ++i){
        int const random = std::rand();
        assert(countBits(random) == __builtin_popcount(random));
    }
}

