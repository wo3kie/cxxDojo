/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 isPrime.cpp -o isPrime
 *
 * Usage:
 *      $ ./isPrime
 */

/*
 * Fermat primality test:
 *   isPrime(n)
 *     If n is prime, then for every a, 1 < a < n, 
 *       a^(n-1) ||| 1 (mod n)
 *       a^(n-1) % n = 1
 *
 */

#include <cassert>

#include "./is_prime.hpp"

/*
 * isPrime_test
 */

void isPrime_test() {
  assert(isPrime(1) == false);
  assert(isPrime(2) == true);
  assert(isPrime(3) == true);
  assert(isPrime(4) == false);
  assert(isPrime(5) == true);
  assert(isPrime(6) == false);
  assert(isPrime(7) == true);
  assert(isPrime(8) == false);
  assert(isPrime(9) == false);
  assert(isPrime(10) == false);
  assert(isPrime(11) == true);

  assert(isPrime(11 * 31 /* 341 */) == true);
  assert(isPrime(3 * 11 * 17 /* 561 */) == true);
}

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

/*
 * main
 */

int main() {
  isPrime_test();
  rhoPollard_test();
}
