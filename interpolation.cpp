/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 interpolation.cpp -o interpolation
 *
 * Usage:
 *      $ ./interpolation
 */

#include <cassert>

#include "./interpolation.hpp"

int main() {
  {
    std::vector<Point> points({{0, 1}, {2, 2}, {3, 4}});
    const std::pair<std::vector<double>, std::vector<double>> xs_cs = newtonDividedDifference(points);
    const std::pair<std::vector<double>, std::vector<double>> expected = {{0, 2, 3}, {1, 0.5, 0.5}};

    assert(xs_cs == expected);

    for(const Point& point : points) {
      assert(newtonDividedDifferencePolynominal(xs_cs, point._x) == point._y);
    }
  }

  {
    std::vector<Point> points({{-1, -5}, {0, -1}, {2, 1}, {3, 11}});
    const std::pair<std::vector<double>, std::vector<double>> xs_cs = newtonDividedDifference(points);
    const std::pair<std::vector<double>, std::vector<double>> expected = {{-1, 0, 2, 3}, {-5, 4, -1, 1}};

    assert(xs_cs == expected);

    for(const Point& point : points) {
      assert(newtonDividedDifferencePolynominal(xs_cs, point._x) == point._y);
    }
  }
}
