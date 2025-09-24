/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/gsl_variance
 */


#include <gsl/gsl_statistics.h>

#include "../assert.hpp"
#include "../feq.hpp"
#include "../variance.hpp"

/*
 * main
 */

int main() {
  {
    std::vector<double> array{7, 6, 8, 4, 2, 7, 6, 7, 6, 5};

    Assert(feq(3.0666, variance<double>(array)));
    Assert(feq(3.0666, variance2<double>(array)));
    Assert(feq(3.0666, variance3<double>(array)));
    Assert(feq(3.0666, gsl_stats_variance(&array.front(), 1, array.size())));
  }
  {
    std::vector<double> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    Assert(feq(9.1666, variance<double>(array)));
    Assert(feq(9.1666, variance2<double>(array)));
    Assert(feq(9.1666, variance3<double>(array)));
    Assert(feq(9.1666, gsl_stats_variance(&array.front(), 1, array.size())));
  }
}
