/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_COVARIANCE_HPP
#define CXX_DOJO_COVARIANCE_HPP

#include <vector>

#include "./mean.hpp"

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Covariance
 *
 *   covariance(x, y) = E((x - E(x))(y - E(y))), where E means expected value (mean)
 *   covariance(x, y) = E(x*y) - E(x)E(y),       where E means expected value (mean)
 *
 */

template<typename Iterator1, typename Iterator2>
double covariance(Iterator1 xBegin, Iterator1 const xEnd, Iterator2 yBegin, Iterator2 const yEnd) {
  double const xMean = mean(xBegin, xEnd);
  double const yMean = mean(yBegin, yEnd);
  unsigned xySize = 0;
  double totalSum = 0;

  for(; xBegin != xEnd; ++xBegin, ++yBegin) {
    xySize += 1;
    totalSum += (*xBegin - xMean) * (*yBegin - yMean);
  }

  return 1.0 * totalSum / (xySize - 1);
}

template<typename T>
double covariance(std::vector<T> const& xs, std::vector<T> const& ys) {
  return covariance(xs.begin(), xs.end(), ys.begin(), ys.end());
}

#endif
