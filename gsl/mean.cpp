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

  Assert(2.0 == approx(mean<double>(array1)));
  Assert(0.0 == approx(mean<double>(array2)));

  Assert(2.0 == approx(gsl_stats_mean(&array1.front(), 1, array1.size())));
  Assert(0.0 == approx(gsl_stats_mean(&array2.front(), 1, array2.size())));
}
