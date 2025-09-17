/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 mean_squared_error.cpp -o mean_squared_error
 *
 * Usage:
 *      $ ./mean_squared_error
 */

#include "./mean_squared_error.hpp"

#include <cassert>
#include <vector>

/*
 * meanSquaredError_test
 */

void meanSquaredError_test() {
  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{1, 2, 3};

    assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == 0);
  }

  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{2, 3, 4};

    assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == 1);
  }

  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{3, 2, 1};

    assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == (4 + 4) / 3);
  }
}

/*
 * main
 */

int main() {
  meanSquaredError_test();
}
