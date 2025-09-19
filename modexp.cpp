/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/modexp
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "./modexp.hpp"

/*
 * modexp_test
 */

void modexp_test() {
  for(unsigned a = 1; a < 10; ++a) {
    for(unsigned exp = 1; exp < 10; ++exp) {
      for(unsigned mod = 1; mod < 10; ++mod) {
        assert(modexp(a, exp, mod) == (unsigned)std::pow(a, exp) % mod);
      }
    }
  }
}

/*
 * main
 */

int main() {
  modexp_test();
}
