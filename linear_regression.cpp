/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/linear_regression
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./feq.hpp"
#include "./linear_regression.hpp"

/*
 * main
 */

int main() {
  {
    double a;
    double b;
    const std::vector<Point> points{{1, 10}, {2, 20}, {3, 20}, {3, 25}, {4, 30}};

    Assert(linearRegression(points, a, b));
    Assert(a == approx(6.1539));
    Assert(b == approx(5.0000));

    Assert(linearRegression2(points, a, b));
    Assert(a == approx(6.1539));
    Assert(b == approx(5.0000));
  }

  {
    double a;
    double b;
    const std::vector<Point> points{{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};

    Assert(linearRegression(points, a, b));
    Assert(a == approx(0.0000));
    Assert(b == approx(1.0000));

    Assert(linearRegression2(points, a, b));
    Assert(a == approx(0.0000));
    Assert(b == approx(1.0000));
  }

  {
    double a;
    double b;
    const std::vector<Point> points{{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};

    Assert(! linearRegression(points, a, b));
    Assert(! linearRegression2(points, a, b));
  }
}
