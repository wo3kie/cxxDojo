/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 mean.cpp -o mean
 *
 * Usage:
 *      $ ./mean
 */

#include <cassert>

#include "./mean.hpp"

void mean_test() {
  {
    const std::vector<int> array{1, 2, 3, 4, 5};
    assert(mean(array) == 3);
  }
  {
    const std::vector<double> array{1.5, 2.5, 3.5, 4.5, 5.5};
    assert(mean(array) == 3.5);
  }
}

/*
 * main
 */

int main() {
  mean_test();
}
