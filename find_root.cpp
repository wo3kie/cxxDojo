/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 find_root.cpp -o find_root
 *
 * Usage:
 *      $ ./find_root
 */

#include <cassert>

#include "./feq.hpp"
#include "./find_root.hpp"

void bisection_test() {
  assert(
      feq(bisection(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              }),
          0.6823));
}

void bisectionNumberOfIteration_test() {
  assert(bisectionNumberOfIteration(6) == 20);
}

void newton_test() {
  assert(
      feq(newton(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              },
              [](double x) {
                return 3 * x * x + 1;
              }),
          0.6823));

  assert(
      feq(newton(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              }),
          0.6823));
}

/*
 * main
 */

int main() {
  bisection_test();
  newton_test();
}
