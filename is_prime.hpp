#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <cstdlib>

#include "./modexp.hpp"

/*
 * isPrime
 */
bool isPrime(unsigned long long value) {
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
