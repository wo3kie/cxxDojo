/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 variance.cpp -o variance -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./variance
 */

#include <cassert>

#include <gsl/gsl_statistics.h>

#include "./feq.hpp"
#include "./variance.hpp"

int main() {
  {
    std::vector<double> array{7, 6, 8, 4, 2, 7, 6, 7, 6, 5};

    assert(feq(3.0666, variance<double>(array)));
    assert(feq(3.0666, variance2<double>(array)));
    assert(feq(3.0666, variance3<double>(array)));
    assert(feq(3.0666, gsl_stats_variance(&array.front(), 1, array.size())));
  }
  {
    std::vector<double> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    assert(feq(9.1666, variance<double>(array)));
    assert(feq(9.1666, variance2<double>(array)));
    assert(feq(9.1666, variance3<double>(array)));
    assert(feq(9.1666, gsl_stats_variance(&array.front(), 1, array.size())));
  }
}
