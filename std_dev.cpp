/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski strongly based on:
 *
 * Compilation:
 *      g++ --std=c++20 std_dev.cpp -o std_dev
 *
 * Usage:
 *      $ ./std_dev
 */

#include <cassert>

#include "./feq.hpp"
#include "./std_dev.hpp"

/*
 * stdDev_test
 */

void stdDev_test() {
  assert(feq(stdDev<int>({1, 1, 1, 1, 1}), 0.0));
  assert(feq(stdDev<int>({1, 2, 3, 4, 5}), 1.58114));
}

/*
 * main
 */

int main() {
  stdDev_test();
}
