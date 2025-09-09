/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 mean.cpp -o mean -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./mean
 */

#include <cassert>

#include <gsl/gsl_statistics.h>

#include "./feq.hpp"
#include "./mean.hpp"

int main() {
  std::vector<double> const array1{1.0, 2.0, 3.0};
  std::vector<double> const array2{-1.0, 0, 1.0};

  assert(feq(2.0, mean<double>(array1)));
  assert(feq(0.0, mean<double>(array2)));

  assert(feq(2.0, gsl_stats_mean(&array1.front(), 1, array1.size())));
  assert(feq(0.0, gsl_stats_mean(&array2.front(), 1, array2.size())));
}
