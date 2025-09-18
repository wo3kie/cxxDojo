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

/*
 * stdDev
 */

template<typename Iterator>
double stdDev(Iterator begin, const Iterator end) {
  return std::sqrt(variance(begin, end));
}

/*
 * stdDev
 */

template<typename T>
double stdDev(const std::vector<T>& array) {
  return stdDev(array.begin(), array.end());
}
