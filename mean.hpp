/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_MEAN_HPP
#define CXX_DOJO_MEAN_HPP

#include <vector>

template<typename Iterator>
double mean(Iterator begin, Iterator const end) {
  double totalSum = 0;
  unsigned counter = 0;

  for(; begin != end; ++begin) {
    totalSum += *begin;
    counter += 1;
  }

  return totalSum / counter;
}

template<typename T>
double mean(std::vector<T> const& array) {
  return mean(array.begin(), array.end());
}

#endif
