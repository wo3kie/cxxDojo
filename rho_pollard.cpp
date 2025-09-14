/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 rhoPollard.cpp -o rhoPollard
 *
 * Usage:
 *      $ ./rhoPollard
 */

/*
 * https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
 */

#include <cmath>

#include "./gcd.hpp"

int f1(int x, int n) {
  return (x * x + 1) % n;
}

/*
 * return -1 for prime number
 * return factor for a composite number
 */

int rhoPollard(int n, int (*f)(int, int) = f1) {
  if(n == 1) {
    return 1;
  }

  int x = 2;
  int y = 2;
  int d = 1;

  while(d == 1) {
    x = f(x, n);
    y = f(f(y, n), n);
    d = gcd(std::abs(x - y), n);
  }

  if(d == n) {
    return -1;
  } else {
    return d;
  }
}

#include <cassert>

void rhoPollard_test() {
  assert(rhoPollard(1) == 1);
  assert(rhoPollard(2) == -1);
  assert(rhoPollard(3) == -1);
  assert(rhoPollard(5) == -1);
  assert(rhoPollard(7) == -1);
  assert(rhoPollard(9) == 3);
  assert(rhoPollard(11) == -1);
  assert(rhoPollard(13) == -1);
  assert(rhoPollard(15) == 3);
  assert(rhoPollard(17) == -1);

  assert(rhoPollard(101 * 103 /*10403*/) == 101);
}

int main() {
  rhoPollard_test();
}
