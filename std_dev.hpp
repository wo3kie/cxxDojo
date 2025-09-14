#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

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

