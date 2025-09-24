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
  Assert(1.67873 == approx(quadratureIntegration(sin, 0.5, 2.5, 100)));
  Assert(1.67873 == approx(trapezoidalIntegration(sin, 0.5, 2.5, 100)));
  Assert(1.67873 == approx(simpsonIntegration(sin, 0.5, 2.5, 100)));
}
