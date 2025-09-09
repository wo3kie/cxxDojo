/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 find_root.cpp -o find_root
 *
 * Usage:
 *      $ ./find_root
 */

#include <cassert>
#include <cmath>
#include <exception>
#include <functional>

unsigned bisectionNumberOfIteration(unsigned precision) {
  /*
     * 1/(2^(n+1)) < 0.5 * 10^(-precision)
     * n > precision / log10(2)
     */

  return std::ceil(1.0 * precision / log10(2));
}

double bisection(double begin, double end, std::function<double(double)> const& f, unsigned precision = 6) {
  assert(f(begin) * f(end) <= 0);

  double midpoint = 0;
  double const numberOfIteration = bisectionNumberOfIteration(precision);
  double const eps = std::pow(0.1, precision);

  for(unsigned i = 0; i < numberOfIteration; ++i) {
    midpoint = (begin + end) / 2;
    double const fMidpoint = f(midpoint);

    if(std::fabs(fMidpoint) < eps) {
      return midpoint;
    }

    double const fBegin = f(begin);
    double const fEnd = f(end);

    if(fBegin * fMidpoint < 0) {
      end = midpoint;
    } else {
      begin = midpoint;
    }
  }

  return midpoint;
}

double newton(
    double x,
    double const end,
    std::function<double(double)> const& f,
    std::function<double(double)> const& fdx,
    unsigned const precision = 6) {
  double xNext = 0;
  double const eps = std::pow(0.1, precision);

  while(x <= end) {
    xNext = x - f(x) / fdx(x);

    if(std::fabs(f(xNext)) < eps) {
      return xNext;
    }

    x = xNext;
  }

  return xNext;
}

double newton(double x, double end, std::function<double(double)> const& f, unsigned const precision = 6) {
  double const eps = std::pow(0.1, precision);

  return newton(
      x,
      end,
      f,
      [&](double x) -> double {
        return (f(x + eps) - f(x)) / eps;
      },
      precision);
}

#include "./feq.hpp"

void bisection_test() {
  assert(
      feq(bisection(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              }),
          0.6823));
}

void bisectionNumberOfIteration_test() {
  assert(bisectionNumberOfIteration(6) == 20);
}

void newton_test() {
  assert(
      feq(newton(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              },
              [](double x) {
                return 3 * x * x + 1;
              }),
          0.6823));

  assert(
      feq(newton(
              0,
              1,
              [](double x) {
                return x * x * x + x - 1;
              }),
          0.6823));
}

int main() {
  bisection_test();
  newton_test();
}
