#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <vector>

#include "./mean.hpp"

template<typename Iterator1, typename Iterator2>
double covariance(Iterator1 xBegin, const Iterator1 xEnd, Iterator2 yBegin, const Iterator2 yEnd) {
  const double xMean = mean(xBegin, xEnd);
  const double yMean = mean(yBegin, yEnd);
  unsigned xySize = 0;
  double totalSum = 0;

  for(; xBegin != xEnd; ++xBegin, ++yBegin) {
    xySize += 1;
    totalSum += (*xBegin - xMean) * (*yBegin - yMean);
  }

  return 1.0 * totalSum / (xySize - 1);
}

template<typename T>
double covariance(const std::vector<T>& xs, const std::vector<T>& ys) {
  return covariance(xs.begin(), xs.end(), ys.begin(), ys.end());
}
