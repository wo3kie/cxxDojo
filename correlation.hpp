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

#include "./covariance.hpp"
#include "./stdDev.hpp"

template<typename Iterator1, typename Iterator2>
double correlation(Iterator1 xBegin, const Iterator1 xEnd, Iterator2 yBegin, const Iterator2 yEnd) {
  const double xyCovariance = covariance(xBegin, xEnd, yBegin, yEnd);
  const double xStdDev = stdDev(xBegin, xEnd);
  const double yStdDev = stdDev(yBegin, yEnd);

  return xyCovariance / xStdDev / yStdDev;
}

template<typename T>
double correlation(const std::vector<T>& xs, const std::vector<T>& ys) {
  return correlation(xs.begin(), xs.end(), ys.begin(), ys.end());
}
