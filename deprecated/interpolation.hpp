#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <map>
#include <vector>

/*
 * Point
 */
struct Point {
  double _x;
  double _y;
};

/*
 * newtonDividedDifference
 */

inline std::pair<std::vector<double> /* xs */, std::vector<double> /* coefficients */> newtonDividedDifference(const std::vector<Point>& points) {
  const unsigned size = points.size();

  std::vector<double> xs(size, 0);
  std::vector<double> cs(size, 0);
  std::map<unsigned, std::map<unsigned, double>> vs;

  for(unsigned j = 0; j < size; ++j) {
    vs[j][0] = points[j]._y;
  }

  for(unsigned i = 1; i < size; ++i) {
    for(unsigned j = 0; j < size - i; ++j) {
      const double y2 = vs[j + 1][i - 1];
      const double y1 = vs[j][i - 1];
      const double x2 = points[j + i]._x;
      const double x1 = points[j]._x;

      vs[j][i] = (y2 - y1) / (x2 - x1);
    }
  }

  for(unsigned i = 0; i < size; ++i) {
    xs[i] = points[i]._x;
    cs[i] = vs[0][i];
  }

  return std::make_pair(xs, cs);
}

/*
 * newtonDividedDifferencePolynominal
 */

inline double newtonDividedDifferencePolynominal(std::pair<std::vector<double> /* xs */, std::vector<double> /* cs */> xs_cs, double x) {
  double result = 0;

  for(unsigned i = 0; i < xs_cs.second.size(); ++i) {
    double factor = 1;

    for(unsigned j = 0; j < i; ++j) {
      factor *= (x - xs_cs.first[j]);
    }

    result += xs_cs.second[i] * factor;
  }

  return result;
}
