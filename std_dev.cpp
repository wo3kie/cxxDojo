/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/std_dev
 */

#include "./assert.hpp"
#include "./feq.hpp"
#include "./std_dev.hpp"

/*
 * stdDev_test
 */

void stdDev_test() {
  Assert(stdDev<int>({1, 1, 1, 1, 1}) == approx(0.0));
  Assert(stdDev<int>({1, 2, 3, 4, 5}) == approx(1.58114));
}

/*
 * main
 */

int main() {
  stdDev_test();
}
