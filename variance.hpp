#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <vector>

#include "./covariance.hpp"
#include "./mean.hpp"

/* From Wikipedia, https://en.wikipedia.org/wiki/Variance
 *
 * Variance(x) = E((x - E(x))^2), whre E means expected value (mean)
 *
 */

template<typename Iterator>
double variance(const Iterator begin, const Iterator end) {
  const double meanValue = mean(begin, end);
  unsigned size = 0;

  double meanValueDiffSquareSum = 0;

  for(Iterator current = begin; current != end; ++current) {
    size += 1;
    const double meanValueDiff = meanValue - *current;
    meanValueDiffSquareSum += meanValueDiff * meanValueDiff;
  }

  return meanValueDiffSquareSum / (size - 1);
}

template<typename T>
double variance(const std::vector<T>& array) {
  return variance(array.begin(), array.end());
}

/*
 * Covariance(x, x) = Variance(x)
 * 
 * Covariance(x, y) = E(x - E(x)) * E(y - E(y)), where E means expected value
 * Covariance(x, x) = E(x - E(x)) * E(x - E(x)) = E(x - E(x))^2
 */
template<typename Iterator>
double variance2(Iterator begin, const Iterator end) {
  return covariance(begin, end, begin, end);
}

template<typename T>
double variance2(const std::vector<T>& array) {
  return variance2(array.begin(), array.end());
}

/*
 * Variance(x) = E((x - E(x))^2)
 * 			   = E(x^2 - 2*x*E(x) + E(x)^2)
 *             = E(x^2) - 2*E(x)E(x) + E(x)^2
 *             = E(x^2) - E(x)^2
 */

template<typename Iterator>
double variance3(const Iterator begin, const Iterator end) {
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
double variance3(const std::vector<T>& array) {
  return variance(array.begin(), array.end());
}
