/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_INTEGRATION_HPP__
#define __CXX_DOJO_INTEGRATION_HPP__

#include <functional>

inline double integrationBase(
    std::function<double(double, double)> approx,
    std::function<double(double)> f,
    double from,
    double to,
    unsigned numIterations) {
  double x = from;
  double result = 0;
  double const stepSize = (to - from) / numIterations;

  for(unsigned i = 0; i < numIterations; ++i) {
    result += approx(x, x + stepSize);
    x += stepSize;
  }

  return result;
}

inline double quadratureIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  auto const approx = [&f](double a, double b) -> double {
    return (b - a) * f((b + a) / 2);
  };

  return integrationBase(approx, f, from, to, numIterations);
}

inline double trapezoidalIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  auto const approx = [&f](double a, double b) -> double {
    return 0.5 * (b - a) * (f(a) + f(b));
  };

  return integrationBase(approx, f, from, to, numIterations);
}

inline double simpsonIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  auto const approx = [&f](double a, double b) -> double {
    return ((b - a) / 6) * (f(a) + f(b) + 4 * f((a + b) / 2));
  };

  return integrationBase(approx, f, from, to, numIterations);
}

#endif
