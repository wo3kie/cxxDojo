#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <cmath>
#include <cstdlib>

#include "./gcd.hpp"
#include "./modexp.hpp"

/*
 * Is prime using Fermat's little theorem
 */

inline bool isPrime(unsigned long long value) {
  if(value == 1) {
    return false;
  }

  if(value == 2) {
    return true;
  }

  const int a = 2 + (rand() % (value - 2));

  if(modexp(a, value - 1, value) == 1) {
    return true;
  } else {
    return false;
  }
}

/*
 * Is prime using Rho Pollard algorithm
 */

inline int f1(int x, int n) {
  return (x * x + 1) % n;
}

/*
 * return -1 for prime number
 * return factor for a composite number
 */

inline int rhoPollard(int n, int (*f)(int, int) = f1) {
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
