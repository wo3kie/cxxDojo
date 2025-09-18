#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <vector>

/*
 * mean
 */

template<typename Iterator>
double mean(Iterator begin, const Iterator end) {
  double totalSum = 0;
  unsigned counter = 0;

  for(; begin != end; ++begin) {
    totalSum += *begin;
    counter += 1;
  }

  return totalSum / counter;
}

template<typename T>
double mean(const std::vector<T>& array) {
  return mean(array.begin(), array.end());
}
