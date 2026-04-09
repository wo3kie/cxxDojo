/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */


#include <gsl/gsl_statistics.h>

#include "../assert.hpp"
#include "../feq.hpp"

/*
 * main
 */

int main() {
  std::vector<double> array{7, 6, 8, 4, 2, 7, 6, 7, 6, 5};

  Assert(3.0666 == approx(gsl_stats_variance(&array.front(), 1, array.size())));
}
