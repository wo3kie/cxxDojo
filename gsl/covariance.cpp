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

#include <gsl/gsl_statistics.h>

#include "../assert.hpp"
#include "../covariance.hpp"
#include "../feq.hpp"

/*
 * main
 */

int main() {
  std::vector<double> const array1{1.2, 2.0, 2.5, 4.0, 3.0, 6.0, 5.5, 6.3, 7.1, 5.4};
  std::vector<double> const array2{3.4, 3.3, 3.0, 5.5, 1.2, 2.4, 3.2, 3.1, 2.9, 3.2};

  {
    double const covarianceValue = covariance(array1, array2);
    Assert(covarianceValue == approx(-0.108889));
  }

  {
    double const covarianceValue = gsl_stats_covariance(&array1.front(), 1, &array2.front(), 1, array2.size());
    Assert(covarianceValue == approx(-0.108889));
  }
}
