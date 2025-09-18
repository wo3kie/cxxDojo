/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 countBits.cpp -o countBits
 *
 * Usage:
 *      $ ./countBits
 */

#include <cassert>
#include <random>

#include "./count_bits.hpp"

/*
 * test_countBits8
 */

void test_countBits8() {
  assert(countBits8(0b00000000) == 0);
  assert(countBits8(0b00000001) == 1);
  assert(countBits8(0b00000010) == 1);
  assert(countBits8(0b00000011) == 2);
  assert(countBits8(0b00000100) == 1);
  assert(countBits8(0b00000101) == 2);
  assert(countBits8(0b00000110) == 2);
  assert(countBits8(0b00000111) == 3);
  assert(countBits8(0b11111111) == 8);
}

/*
 * test_countBits
 */

void test_countBits() {
  for(int i = 0; i < 256; ++i) {
    assert(countBits8(i) == __builtin_popcount(i));
  }

  for(int i = 0; i < 256; ++i) {
    assert(countBits(i) == __builtin_popcount(i));
  }

  for(int i = 0; i < 1e4; ++i) {
    const int random = std::rand();
    assert(countBits(random) == __builtin_popcount(random));
  }
}

/*
 * main
 */

int main() {
  test_countBits8();
  test_countBits();
}
