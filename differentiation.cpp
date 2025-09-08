/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 differentiation.cpp -o differentiation
 *
 * Usage:
 *      $ ./differentiation
 */

#include <functional>

// first derivative
double first_twoPointForward(std::function<double(double)> f, double x, double h = 0.001) {
  return (f(x + h) - f(x)) / h;
}

// first derivative
double first_threePointCentered(std::function<double(double)> f, double x, double h = 0.001) {
  return (f(x + h) - f(x - h)) / 2 / h;
}

// second derivative
double second_threePointCentered(std::function<double(double)> f, double x, double h = 0.001) {
  return (f(x - h) - 2 * f(x) + f(x + h)) / h / h;
}

// third derivative
double third_fourPointsCentered(std::function<double(double)> f, double x, double h = 0.001) {
  return (-f(x - 2 * h) + 2 * f(x - h) - 2 * f(x + h) + f(x + 2 * h)) / 2 / h / h / h;
}

double third_fivePointsCentered(std::function<double(double)> f, double x, double h = 0.001) {
  return (f(x - 3 * h) - 6 * f(x - 2 * h) + 12 * f(x - h) - 10 * f(x) + 3 * f(x + h)) / 2 / h / h / h;
}

#include <cassert>
#include <iostream>

#include "./feq.hpp"

int main() {
  auto f = [](double x) {
    return 2 * x * x * x * x - 4 * x * x * x + 6 * x * x - 8 * x + 10;
  };
  auto df_dx = [](double x) {
    return 2 * 4 * x * x * x - 4 * 3 * x * x + 6 * 2 * x - 8;
  };
  auto d2f_dx2 = [](double x) {
    return 2 * 4 * 3 * x * x - 4 * 3 * 2 * x + 6 * 2;
  };
  auto d3f_dx3 = [](double x) {
    return 2 * 4 * 3 * 2 * x - 4 * 3 * 2;
  };

  assert(feq(first_twoPointForward(f, 2), df_dx(2) + 0.03));
  assert(feq(first_threePointCentered(f, 2), df_dx(2)));

  assert(feq(second_threePointCentered(f, 2), d2f_dx2(2)));

  assert(feq(third_fourPointsCentered(f, 2), d3f_dx3(2)));
  assert(feq(third_fivePointsCentered(f, 2), d3f_dx3(2)));
}
