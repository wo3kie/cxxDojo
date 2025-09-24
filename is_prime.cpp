/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/isPrime
 */

/*
 * Fermat primality test:
 *   isPrime(n)
 *     If n is prime, then for every a, 1 < a < n, 
 *       a^(n-1) ||| 1 (mod n)
 *       a^(n-1) % n = 1
 *
 */

#include "./assert.hpp"
#include "./is_prime.hpp"

/*
 * isPrime_test
 */

void isPrime_test() {
  Assert(isPrime(1) == false);
  Assert(isPrime(2) == true);
  Assert(isPrime(3) == true);
  Assert(isPrime(4) == false);
  Assert(isPrime(5) == true);
  Assert(isPrime(6) == false);
  Assert(isPrime(7) == true);
  Assert(isPrime(8) == false);
  Assert(isPrime(9) == false);
  Assert(isPrime(10) == false);
  Assert(isPrime(11) == true);

  Assert(isPrime(11 * 31 /* 341 */) == true);
  Assert(isPrime(3 * 11 * 17 /* 561 */) == true);
}

void rhoPollard_test() {
  Assert(rhoPollard(1) == 1);
  Assert(rhoPollard(2) == -1);
  Assert(rhoPollard(3) == -1);
  Assert(rhoPollard(5) == -1);
  Assert(rhoPollard(7) == -1);
  Assert(rhoPollard(9) == 3);
  Assert(rhoPollard(11) == -1);
  Assert(rhoPollard(13) == -1);
  Assert(rhoPollard(15) == 3);
  Assert(rhoPollard(17) == -1);

  Assert(rhoPollard(101 * 103 /*10403*/) == 101);
}

/*
 * main
 */

int main() {
  isPrime_test();
  rhoPollard_test();
}
