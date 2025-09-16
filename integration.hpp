#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <functional>

/* 
 * integrationBase
 */
inline double integrationBase(std::function<double(double, double)> approx, std::function<double(double)> f, double from, double to, unsigned numIterations) {
  double x = from;
  double result = 0;
  const double stepSize = (to - from) / numIterations;

  for(unsigned i = 0; i < numIterations; ++i) {
    result += approx(x, x + stepSize);
    x += stepSize;
  }

  return result;
}

/*
 * quadratureIntegration
 */

inline double quadratureIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  const auto approx = [&f](double a, double b) -> double {
    return (b - a) * f((b + a) / 2);
  };

  return integrationBase(approx, f, from, to, numIterations);
}

/*
 * trapezoidalIntegration
 */

inline double trapezoidalIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  const auto approx = [&f](double a, double b) -> double {
    return 0.5 * (b - a) * (f(a) + f(b));
  };

  return integrationBase(approx, f, from, to, numIterations);
}

/*
 * simpsonIntegration
 */

inline double simpsonIntegration(double (*f)(double), double from, double to, unsigned numIterations) {
  const auto approx = [&f](double a, double b) -> double {
    return ((b - a) / 6) * (f(a) + f(b) + 4 * f((a + b) / 2));
  };

  return integrationBase(approx, f, from, to, numIterations);
}
