#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <vector>

/*
 * exponentialSmoothing
 */

inline std::vector<double> exponentialSmoothing(const std::vector<double>& array, const double alpha) {
  std::vector<double> result(array.size() - 1);

  result[0] = array[0];

  for(std::size_t i = 1; i < result.size(); ++i) {
    result[i] = alpha * array[i] + (1 - alpha) * result[i - 1];
  }

  return result;
}
