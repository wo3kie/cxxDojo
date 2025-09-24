#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cmath>
#include <exception>
#include <functional>

#include "./assert.hpp"

/*
 * bisectionNumberOfIteration
 */

inline unsigned bisectionNumberOfIteration(unsigned precision) {
  /*
     * 1/(2^(n+1)) < 0.5 * 10^(-precision)
     * n > precision / log10(2)
     */

  return std::ceil(1.0 * precision / log10(2));
}

/*
 * bisection
 */

inline double bisection(double begin, double end, const std::function<double(double)>& f, unsigned precision = 6) {
  assert(f(begin) * f(end) <= 0);

  double midpoint = 0;
  const double numberOfIteration = bisectionNumberOfIteration(precision);
  const double eps = std::pow(0.1, precision);

  for(unsigned i = 0; i < numberOfIteration; ++i) {
    midpoint = (begin + end) / 2;
    const double fMidpoint = f(midpoint);

    if(std::fabs(fMidpoint) < eps) {
      return midpoint;
    }

    const double fBegin = f(begin);
    const double fEnd = f(end);

    if(fBegin * fMidpoint < 0) {
      end = midpoint;
    } else {
      begin = midpoint;
    }
  }

  return midpoint;
}

/*
 * newton
 */

inline double
newton(double x, const double end, const std::function<double(double)>& f, const std::function<double(double)>& fdx, const unsigned precision = 6) {
  double xNext = 0;
  const double eps = std::pow(0.1, precision);

  while(x <= end) {
    xNext = x - f(x) / fdx(x);

    if(std::fabs(f(xNext)) < eps) {
      return xNext;
    }

    x = xNext;
  }

  return xNext;
}

inline double newton(double x, double end, const std::function<double(double)>& f, const unsigned precision = 6) {
  const double eps = std::pow(0.1, precision);

  return newton(
      x,
      end,
      f,
      [&](double x) -> double {
        return (f(x + eps) - f(x)) / eps;
      },
      precision);
}
