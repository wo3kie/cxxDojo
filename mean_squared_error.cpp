/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/mean_squared_error
 */

#include <vector>

#include "./assert.hpp"
#include "./mean_squared_error.hpp"

/*
 * meanSquaredError_test
 */

void meanSquaredError_test() {
  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{1, 2, 3};

    Assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == 0);
  }

  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{2, 3, 4};

    Assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == 1);
  }

  {
    const std::vector<double> expected{1, 2, 3};
    const std::vector<double> actual{3, 2, 1};

    Assert(meanSquaredError(expected.begin(), expected.end(), actual.begin()) == (4.0 + 4.0) / 3.0);
  }
}

/*
 * main
 */

int main() {
  meanSquaredError_test();
}
