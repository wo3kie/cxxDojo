/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 * 
 * Compilation:
 *      g++ --std=c++20 variance.cpp -o variance
 *
 * Usage:
 *      $ ./variance
 */

#include <cassert>

#include "./feq.hpp"
#include "./variance.hpp"

/*
 * variance_test
 */

void variance_test() {
  assert(feq(variance<int>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}), 0));
  assert(feq(variance<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}), 9.16667));
}

/*
 * main
 */

 int main() {
  variance_test();
 }
