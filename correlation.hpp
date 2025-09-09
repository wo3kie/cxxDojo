/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Pearson_correlation_coefficient
 *
 * p(x, y) = covariance(x, y) / stdDev(x) / stdDev(y)
 *
 */

#ifndef CXX_DOJO_CORRELATION_HPP
#define CXX_DOJO_CORRELATION_HPP

#include <cmath>
#include <vector>

#include "./covariance.hpp"
#include "./stdDev.hpp"

template<typename Iterator1, typename Iterator2>
double correlation(Iterator1 xBegin, Iterator1 const xEnd, Iterator2 yBegin, Iterator2 const yEnd) {
  double const xyCovariance = covariance(xBegin, xEnd, yBegin, yEnd);
  double const xStdDev = stdDev(xBegin, xEnd);
  double const yStdDev = stdDev(yBegin, yEnd);

  return xyCovariance / xStdDev / yStdDev;
}

template<typename T>
double correlation(std::vector<T> const& xs, std::vector<T> const& ys) {
  return correlation(xs.begin(), xs.end(), ys.begin(), ys.end());
}

#endif
