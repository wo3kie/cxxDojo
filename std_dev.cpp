/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/) strongly based on:
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
  Assert(feq(stdDev<int>({1, 1, 1, 1, 1}), 0.0));
  Assert(feq(stdDev<int>({1, 2, 3, 4, 5}), 1.58114));
}

/*
 * main
 */

int main() {
  stdDev_test();
}
