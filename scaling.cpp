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

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Feature_scaling
 */

#include <algorithm>
#include <cassert>
#include <tuple>

#include "./feq.hpp"
#include "./stdDev.hpp"

template<typename IteratorIn, typename IteratorOut>
void rescale(IteratorIn const begin, IteratorIn const end, IteratorOut out) {
  typedef typename std::iterator_traits<IteratorIn>::value_type value_type;

  if(begin == end) {
    return;
  }

  IteratorIn minIt;
  IteratorIn maxIt;

  std::tie(minIt, maxIt) = std::minmax_element(begin, end);

  value_type const min = *minIt;
  value_type const max = *maxIt;

  if(min == max) {
    std::copy(begin, end, out);
    return;
  }

  auto const f = [&min, &max](value_type x) -> double {
    return 1.0 * (x - min) / (max - min);
  };

  std::transform(begin, end, out, f);
}

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

template<typename IteratorIn, typename IteratorOut>
void standardize(IteratorIn const begin, IteratorIn const end, IteratorOut out) {
  typedef typename std::iterator_traits<IteratorIn>::value_type value_type;

  if(begin == end) {
    return;
  }

  double const sD = stdDev(begin, end);

  if(sD == 0) {
    std::copy(begin, end, out);
    return;
  }

  double const m = mean(begin, end);

  auto const f = [&sD, &m](value_type x) -> double {
    return 1.0 * (x - m) / sD;
  };

  std::transform(begin, end, out, f);
}

void standardize_test() {
  auto const feqDouble = [](double d1, double d2) -> bool {
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

int main() {
  rescale_test();
  standardize_test();
}
