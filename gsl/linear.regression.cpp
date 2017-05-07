/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 linear.regression.cpp -o linear.regression
 *
 * Usage:
 *      $ ./linear.regression
 */

#include <cmath>
#include <iostream>

#include "./feq.hpp"
#include "../linear.regression.hpp"

#include <gsl/gsl_fit.h>

int main(){
    {
        double const xs[] { 1, 2, 3, 3, 4 };
        double const ys[] { 10, 20, 20, 25, 30 };

		double a, b, cov00, cov01, cov11, sumsg;

		gsl_fit_linear(
			xs,
			1,
			ys,
			1,
			sizeof(xs) / sizeof(xs[0]),
			&b,
			&a,
			&cov00,
			&cov01,
			&cov11,
			&sumsg
		);

        assert( feq( a, 6.1539, 0.0001 ) );
        assert( feq( b, 5.0000, 0.0001 ) );
    }

	{
        double const xs[] { 1, 2, 3, 4, 5 };
        double const ys[] { 1, 1, 1, 1, 1 };

		double a, b, cov00, cov01, cov11, sumsg;

		gsl_fit_linear(
			xs,
			1,
			ys,
			1,
			sizeof(xs) / sizeof(xs[0]),
			&b,
			&a,
			&cov00,
			&cov01,
			&cov11,
			&sumsg
		);

        assert( feq( a, 0.0000, 0.0001 ) );
        assert( feq( b, 1.0000, 0.0001 ) );
	}
}

