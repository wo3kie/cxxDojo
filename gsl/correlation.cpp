/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/gsl_correlation
 */

#include <cassert>
#include <vector>

#include <gsl/gsl_statistics.h>

#include "../feq.hpp"

/*
 * main
 */

int main() {
  const std::vector<double> array1{1.2, 2.0, 2.5, 4.0, 3.0, 6.0, 5.5, 6.3, 7.1, 5.4};
  const std::vector<double> array2{3.4, 3.3, 3.0, 5.5, 1.2, 2.4, 3.2, 3.1, 2.9, 3.2};

  const double correlationValue = gsl_stats_correlation(&array1.front(), 1, &array2.front(), 1, array2.size());
  assert(feq(correlationValue, -0.050601));
}
