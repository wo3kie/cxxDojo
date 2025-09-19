#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <boost/preprocessor/repetition/repeat.hpp>

constexpr int countBits8(unsigned char i) {
  return i == 0 ? 0 : (i & 1) + countBits8(i / 2);
}

#define COUNT_BITS_CALCULATE(z, n, data) countBits8(n),

inline int countBits(const unsigned char* begin, const unsigned char* const end) {
  constexpr int bits[256] = {BOOST_PP_REPEAT(256, COUNT_BITS_CALCULATE, "")};

  /*
   * g++ -E count_bits.hpp | less 
   *
   * inline int countBits(unsigned char const* begin, unsigned char const* const end) {
   *   constexpr int bits[256] = {countBits8(0), countBits8(1), ..., countBits8(255),};
   */

  int result = 0;

  for(; begin != end; ++begin) {
    result += bits[*begin];
  }

  return result;
}

template<typename T>
int countBits(const T& t) {
  const unsigned char* const begin = reinterpret_cast<const unsigned char*>(&t);
  return countBits(begin, begin + sizeof(T));
}
