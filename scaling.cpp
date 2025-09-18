/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ scaling.cpp -o scaling
 *
 * Usage:
 *      $ ./scaling
 */

#include <cassert>

#include "./feq.hpp"
#include "./scaling.hpp"

/*
 * rescale_test
 */

void rescale_test() {
  {
    std::vector<int> array({0, 0, 0, 0, 0});
    std::vector<double> actual;
    std::vector<double> expected({0, 0, 0, 0, 0});

    rescale(array.begin(), array.end(), std::back_inserter(actual));
    assert(actual == expected);
  }
  {
    std::vector<int> array({0, 1, 2, 3, 4});
    std::vector<double> actual;
    std::vector<double> expected({0, 0.25, 0.5, 0.75, 1});

    rescale(array.begin(), array.end(), std::back_inserter(actual));
    assert(actual == expected);
  }
  {
    std::vector<int> array({-4, -3, -2, -1, 0, 1, 2, 3, 4});
    std::vector<double> actual;
    std::vector<double> expected({0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1});

    rescale(array.begin(), array.end(), std::back_inserter(actual));
    assert(actual == expected);
  }
}

/*
 * standardize_test
 */

void standardize_test() {
  const auto feqDouble = [](double d1, double d2) -> bool {
    return feq(d1, d2);
  };

  {
    std::vector<int> array({0, 0, 0, 0, 0});
    std::vector<double> actual;
    std::vector<double> expected({0, 0, 0, 0, 0});

    standardize(array.begin(), array.end(), std::back_inserter(actual));

    assert(std::equal(actual.begin(), actual.end(), expected.begin(), expected.end(), feqDouble));
  }
  {
    std::vector<int> array({0, 1, 2, 3, 4});
    std::vector<double> actual;
    std::vector<double> expected({-1.26491, -0.632456, 0, 0.632456, 1.26491});

    standardize(array.begin(), array.end(), std::back_inserter(actual));

    assert(std::equal(actual.begin(), actual.end(), expected.begin(), expected.end(), feqDouble));
  }
  {
    std::vector<int> array({-4, -3, -2, -1, 0, 1, 2, 3, 4});
    std::vector<double> actual;
    std::vector<double> expected({-1.46059, -1.09545, -0.730297, -0.365148, 0, 0.365148, 0.730297, 1.09545, 1.46059});

    standardize(array.begin(), array.end(), std::back_inserter(actual));

    assert(std::equal(actual.begin(), actual.end(), expected.begin(), expected.end(), feqDouble));
  }
}

/*
 * main
 */

int main() {
  rescale_test();
  standardize_test();
}
