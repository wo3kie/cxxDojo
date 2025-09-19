/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/gcd
 */

#include "./gcd.hpp"

void gcd_test() {
  static_assert(gcd(0, 7) == 7, "");
  static_assert(gcd(1, 7) == 1, "");
  static_assert(gcd(2, 7) == 1, "");
  static_assert(gcd(3, 7) == 1, "");
  static_assert(gcd(4, 7) == 1, "");
  static_assert(gcd(5, 7) == 1, "");
  static_assert(gcd(6, 7) == 1, "");
  static_assert(gcd(7, 7) == 7, "");
  static_assert(gcd(8, 7) == 1, "");
  static_assert(gcd(9, 7) == 1, "");
  static_assert(gcd(10, 7) == 1, "");
  static_assert(gcd(11, 7) == 1, "");
  static_assert(gcd(12, 7) == 1, "");
  static_assert(gcd(13, 7) == 1, "");
  static_assert(gcd(14, 7) == 7, "");
}

void GCD_test() {
  static_assert(GCD<0, 7>::value == 7, "");
  static_assert(GCD<1, 7>::value == 1, "");
  static_assert(GCD<2, 7>::value == 1, "");
  static_assert(GCD<3, 7>::value == 1, "");
  static_assert(GCD<4, 7>::value == 1, "");
  static_assert(GCD<5, 7>::value == 1, "");
  static_assert(GCD<6, 7>::value == 1, "");
  static_assert(GCD<7, 7>::value == 7, "");
  static_assert(GCD<8, 7>::value == 1, "");
  static_assert(GCD<9, 7>::value == 1, "");
  static_assert(GCD<10, 7>::value == 1, "");
  static_assert(GCD<11, 7>::value == 1, "");
  static_assert(GCD<12, 7>::value == 1, "");
  static_assert(GCD<13, 7>::value == 1, "");
  static_assert(GCD<14, 7>::value == 7, "");
}

/*
 * main
 */

int main() {
  gcd_test();
  GCD_test();
}
