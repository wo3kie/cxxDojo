/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 * 
 * Usage:
 *      $ ./build/bin/variance
 */


#include "./assert.hpp"
#include "./feq.hpp"
#include "./variance.hpp"

/*
 * variance_test
 */

void variance_test() {
  Assert(variance<int>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) == approx(0));
  Assert(variance<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == approx(9.16667));
}

/*
 * main
 */

 int main() {
  variance_test();
 }
