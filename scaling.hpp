#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Feature_scaling
 */

#include <algorithm>

#include "./std_dev.hpp"

/* 
 * rescale
 */

template<typename IteratorIn, typename IteratorOut>
void rescale(const IteratorIn begin, const IteratorIn end, IteratorOut out) {
  typedef typename std::iterator_traits<IteratorIn>::value_type value_type;

  if(begin == end) {
    return;
  }

  IteratorIn minIt;
  IteratorIn maxIt;

  std::tie(minIt, maxIt) = std::minmax_element(begin, end);

  const value_type min = *minIt;
  const value_type max = *maxIt;

  if(min == max) {
    std::copy(begin, end, out);
    return;
  }

  const auto f = [&min, &max](value_type x) -> double {
    return 1.0 * (x - min) / (max - min);
  };

  std::transform(begin, end, out, f);
}

/* 
 * standardize
 */

template<typename IteratorIn, typename IteratorOut>
void standardize(const IteratorIn begin, const IteratorIn end, IteratorOut out) {
  typedef typename std::iterator_traits<IteratorIn>::value_type value_type;

  if(begin == end) {
    return;
  }

  const double sD = stdDev(begin, end);

  if(sD == 0) {
    std::copy(begin, end, out);
    return;
  }

  const double m = mean(begin, end);

  const auto f = [&sD, &m](value_type x) -> double {
    return 1.0 * (x - m) / sD;
  };

  std::transform(begin, end, out, f);
}
