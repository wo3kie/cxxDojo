/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/gsl_mean
 */


#include <gsl/gsl_statistics.h>

#include "../assert.hpp"
#include "../feq.hpp"
#include "../mean.hpp"

int main() {
  std::vector<double> const array1{1.0, 2.0, 3.0};
  std::vector<double> const array2{-1.0, 0, 1.0};

  Assert(feq(2.0, mean<double>(array1)));
  Assert(feq(0.0, mean<double>(array2)));

  Assert(feq(2.0, gsl_stats_mean(&array1.front(), 1, array1.size())));
  Assert(feq(0.0, gsl_stats_mean(&array2.front(), 1, array2.size())));
}
