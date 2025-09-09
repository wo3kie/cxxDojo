/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_STANDARD_DEVIATION_HPP
#define CXX_DOJO_STANDARD_DEVIATION_HPP

#include <cmath>
#include <vector>

#include "./variance.hpp"

template<typename Iterator>
double stdDev(Iterator begin, Iterator const end) {
  return std::sqrt(variance(begin, end));
}

template<typename T>
double stdDev(std::vector<T> const& array) {
  return stdDev(array.begin(), array.end());
}

#endif
