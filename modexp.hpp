#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

inline constexpr unsigned pow2(unsigned a) {
  return a * a;
}

inline constexpr unsigned modexp(unsigned a, unsigned exp, unsigned mod) {
  return exp == 0 ? 1 : ((exp % 2 == 0 ? 1 : a) * pow2(modexp(a, exp / 2, mod)) % mod);
}
