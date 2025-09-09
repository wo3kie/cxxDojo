/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 linear.regression.cpp -o linear.regression
 *
 * Usage:
 *      $ ./linear.regression
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "./feq.hpp"
#include "./linearRegression.hpp"

int main() {
  {
    double a;
    double b;
    std::vector<Point> const points{{1, 10}, {2, 20}, {3, 20}, {3, 25}, {4, 30}};

    assert(linearRegression(points, a, b));
    assert(feq(a, 6.1539, 0.0001));
    assert(feq(b, 5.0000, 0.0001));

    assert(linearRegression2(points, a, b));
    assert(feq(a, 6.1539, 0.0001));
    assert(feq(b, 5.0000, 0.0001));
  }

  {
    double a;
    double b;
    std::vector<Point> const points{{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};

    assert(linearRegression(points, a, b));
    assert(feq(a, 0.0000, 0.0001));
    assert(feq(b, 1.0000, 0.0001));

    assert(linearRegression2(points, a, b));
    assert(feq(a, 0.0000, 0.0001));
    assert(feq(b, 1.0000, 0.0001));
  }

  {
    double a;
    double b;
    std::vector<Point> const points{{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};

    assert(! linearRegression(points, a, b));
    assert(! linearRegression2(points, a, b));
  }
}
