/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 correlation.cpp -o correlation
 *
 * Usage:
 *      $ ./correlation
 */

#include "./correlation.hpp"
#include "./feq.hpp"

#include <cassert>

/*
 * correlation_test
 */

void correlation_test_1() {
  std::vector<double> xs = {1, 2, 3, 4, 5};
  std::vector<double> ys = {5, 4, 3, 2, 1};

  double d = correlation(xs, ys);

  assert(feq(correlation(xs, ys), -1.0));
}

void correlation_test_2() {
  std::vector<double> xs = {1, 2, 3, 4, 5};
  std::vector<double> ys = {1, 2, 3, 4, 5};

  assert(feq(correlation(xs, ys), 1.0));
}

/*
 * main
 */

int main() {
  correlation_test_1();
  correlation_test_2();
}