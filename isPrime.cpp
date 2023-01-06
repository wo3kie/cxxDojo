/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 isPrime.cpp -o isPrime
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
#include <cstdlib>

#include "./modexp.hpp"

bool isPrime(unsigned long long N) {
  if(N == 1) {
    return false;
  }

  if(N == 2) {
    return true;
  }

  int const a = 2 + (rand() % (N - 2));

  if(modexp(a, N - 1, N) == 1) {
    return true;
  } else {
    return false;
  }
}

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

  assert(isPrime(11 * 31 /*341*/) == true);
  assert(isPrime(3 * 11 * 17 /*561*/) == true);
}

int main() {
  isPrime_test();
}
