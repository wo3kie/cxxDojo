/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/countBits
 */

#include <random>

#include "./assert.hpp"
#include "./count_bits.hpp"

/*
 * test_countBits8
 */

void test_countBits8() {
  Assert(countBits8(0b00000000) == 0);
  Assert(countBits8(0b00000001) == 1);
  Assert(countBits8(0b00000010) == 1);
  Assert(countBits8(0b00000011) == 2);
  Assert(countBits8(0b00000100) == 1);
  Assert(countBits8(0b00000101) == 2);
  Assert(countBits8(0b00000110) == 2);
  Assert(countBits8(0b00000111) == 3);
  Assert(countBits8(0b11111111) == 8);
}

/*
 * test_countBits
 */

void test_countBits() {
  for(int i = 0; i < 256; ++i) {
    Assert(countBits8(i) == __builtin_popcount(i));
  }

  for(int i = 0; i < 256; ++i) {
    Assert(countBits(i) == __builtin_popcount(i));
  }

  for(int i = 0; i < 1e4; ++i) {
    const int random = std::rand();
    Assert(countBits(random) == __builtin_popcount(random));
  }
}

/*
 * main
 */

int main() {
  test_countBits8();
  test_countBits();
}
