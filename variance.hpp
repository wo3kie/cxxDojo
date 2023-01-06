/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_VARIANCE_HPP
#define CXX_DOJO_VARIANCE_HPP

#include <vector>

#include "./covariance.hpp"
#include "./mean.hpp"

/* From Wikipedia, https://en.wikipedia.org/wiki/Variance
 *
 * Variance(x) = E((x - E(x))^2), whre E means expected value (mean)
 *
 */

template<typename Iterator>
double variance(Iterator const begin, Iterator const end) {
  double const meanValue = mean(begin, end);
  unsigned size = 0;

  double meanValueDiffSquareSum = 0;

  for(Iterator current = begin; current != end; ++current) {
    size += 1;
    double const meanValueDiff = meanValue - *current;
    meanValueDiffSquareSum += meanValueDiff * meanValueDiff;
  }

  return meanValueDiffSquareSum / (size - 1);
}

template<typename T>
double variance(std::vector<T> const& array) {
  return variance(array.begin(), array.end());
}

/*
 * Covariance(x, x) = Variance(x)
 * 
 * Covariance(x, y) = E(x - E(x)) * E(y - E(y)), where E means expected value
 * Covariance(x, x) = E(x - E(x)) * E(x - E(x)) = E(x - E(x))^2
 */
template<typename Iterator>
double variance2(Iterator begin, Iterator const end) {
  return covariance(begin, end, begin, end);
}

template<typename T>
double variance2(std::vector<T> const& array) {
  return variance2(array.begin(), array.end());
}

/*
 * Variance(x) = E((x - E(x))^2)
 * 			   = E(x^2 - 2*x*E(x) + E(x)^2)
 *             = E(x^2) - 2*E(x)E(x) + E(x)^2
 *             = E(x^2) - E(x)^2
 */

template<typename Iterator>
double variance3(Iterator const begin, Iterator const end) {
  unsigned size = 0;

  double xSquareMean = 0;
  double xMeanSquare = 0;

  for(Iterator current = begin; current != end; ++current) {
    size += 1;

    xSquareMean += *current * *current;
    xMeanSquare++* current;
  }

  // (xSquareMean / size) - (xMeanSquare / size);
  return (xSquareMean - xMeanSquare) / size;
}

template<typename T>
double variance3(std::vector<T> const& array) {
  return variance(array.begin(), array.end());
}

#endif
