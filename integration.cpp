/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 integration.cpp -o integration
 *
 * Usage:
 *      $ ./integration
 */

#include <cassert>
#include <cmath>

#include "./feq.hpp"
#include "./integration.hpp"

int main() {
  assert((feq(1.67873, quadratureIntegration(sin, 0.5, 2.5, 100))));

  assert((feq(1.67873, trapezoidalIntegration(sin, 0.5, 2.5, 100))));

  assert((feq(1.67873, simpsonIntegration(sin, 0.5, 2.5, 100))));
}
