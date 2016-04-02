/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 covariance.cpp -o covariance -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./correlation
 */

#include <cassert>

#include <gsl/gsl_statistics.h>

#include "./feq.hpp"
#include "./covariance.hpp"

int main(){
    std::vector<double> const array1{
        1.2, 2.0, 2.5, 4.0, 3.0, 6.0, 5.5, 6.3, 7.1, 5.4
    };

    std::vector<double> const array2{
        3.4, 3.3, 3.0, 5.5, 1.2, 2.4, 3.2, 3.1, 2.9, 3.2
    };

    {
        double const covarianceValue = covariance<double>(
            array1,
            array2
        );

        assert(feq(covarianceValue, -0.108889));
    }

    {
        double const covarianceValue = gsl_stats_covariance(
            &array1.front(), 1,
            &array2.front(), 1, array2.size()
        );

        assert(feq(covarianceValue, -0.108889));
    }
}
