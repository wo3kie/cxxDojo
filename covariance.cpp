/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 covariance.cpp -o covariance
 *
 * Usage:
 *      $ ./covariance
 */

#include "./covariance.hpp"
#include "./feq.hpp"

#include <cassert>

/*
 * covariance_test
 */
void covariance_test_1() {
  std::vector<double> xs = {1, 2, 3, 4, 5};
  std::vector<double> ys = {5, 4, 3, 2, 1};

  assert(feq(covariance(xs, ys), -2.5));
}

void covariance_test_2() {
  std::vector<double> xs = {1, 2, 3, 4, 5};
  std::vector<double> ys = {1, 2, 3, 4, 5};

  assert(feq(covariance(xs, ys), 2.5));
}

/*
 * main
 */

int main() {
  covariance_test_1();
  covariance_test_2();
}
