/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 modexp.cpp -o modexp
 *
 * Usage:
 *      $ ./modexp
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "./modexp.hpp"

void modexp_test() {
  for(unsigned a = 1; a < 10; ++a) {
    for(unsigned exp = 1; exp < 10; ++exp) {
      for(unsigned mod = 1; mod < 10; ++mod) {
        assert(modexp(a, exp, mod) == (unsigned)std::pow(a, exp) % mod);
      }
    }
  }
}

int main() {
  modexp_test();
}
