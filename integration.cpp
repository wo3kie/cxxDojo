/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/integration
 */

#include <cmath>

#include "./assert.hpp"
#include "./feq.hpp"
#include "./integration.hpp"

/*
 * main
 */

int main() {
  Assert((feq(1.67873, quadratureIntegration(sin, 0.5, 2.5, 100))));
  Assert((feq(1.67873, trapezoidalIntegration(sin, 0.5, 2.5, 100))));
  Assert((feq(1.67873, simpsonIntegration(sin, 0.5, 2.5, 100))));
}
