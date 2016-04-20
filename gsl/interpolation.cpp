/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 interpolation.cpp -o interpolation -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./interpolation
 */

#include <algorithm>
#include <vector>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>

#include <gsl/gsl_linalg.h>

#include "./feq.hpp"

namespace ublas = boost::numeric::ublas;

struct Point
{
    double x_;
    double y_;
};

ublas::vector< double > linear_interpolation_ublas(
    std::vector< Point > const & points
){
    assert( points.size() == 2 );

    ublas::vector< double > X( 2 );

    Point const & p1 = points[ 0 ];
    Point const & p2 = points[ 1 ];

    double const a = (p1.y_ - p2.y_) / (p1.x_ - p2.x_);
    double const b = p1.y_ - p1.x_ * ((p1.y_ - p2.y_) / (p1.x_ - p2.x_));

    X( 0 ) = a;
    X( 1 ) = b;

    return X;
}

ublas::vector< double > polynominal_interpolation_ublas( std::vector< Point > const & points ){
    std::size_t const size = points.size();

    ublas::matrix< double > A( size, size );

    for( std::size_t i = 0 ; i < size ; ++ i ){
        for( std::size_t j = 0 ; j < size ; ++ j ){
            A( i, j ) = std::pow( points[ i ].x_, j );
        }
    }

    ublas::vector< double > Y( size );

    for( std::size_t i = 0 ; i < size ; ++ i ){
        Y( i ) = points[ i ].y_;
    }

    ublas::permutation_matrix< double > PM( size );
    ublas::lu_factorize( A, PM );
    ublas::lu_substitute( A, PM, Y );

    return Y;
}

gsl_vector * linear_interpolation_gsl( std::vector< Point > const & points ){
    assert( points.size() == 2 );

    gsl_vector * X = gsl_vector_alloc( 2 );

    Point const & p1 = points[ 0 ];
    Point const & p2 = points[ 1 ];

    double const a = (p1.y_ - p2.y_) / (p1.x_ - p2.x_);
    double const b = p1.y_ - p1.x_ * ((p1.y_ - p2.y_) / (p1.x_ - p2.x_));

    gsl_vector_set( X, 0, a );
    gsl_vector_set( X, 1, b );

    return X;
}

gsl_vector * polynominal_interpolation_gsl( std::vector< Point > const & points ){
    std::size_t const size = points.size();

    gsl_matrix * A = gsl_matrix_alloc( size, size );

    for( std::size_t i = 0 ; i < size ; ++ i ){
        for( std::size_t j = 0 ; j < size ; ++ j ){
            gsl_matrix_set( A, i, j, std::pow( points[ i ].x_, j ) );
        }
    }

    gsl_vector * Y = gsl_vector_alloc( size );

    for( std::size_t i = 0 ; i < size ; ++ i ){
        gsl_vector_set( Y, i, points[ i ].y_ );
    }

    gsl_vector * X = gsl_vector_alloc( size );
    gsl_permutation * PM = gsl_permutation_alloc( size );

    int s = 0;
    gsl_linalg_LU_decomp( A, PM, &s );
    gsl_linalg_LU_solve( A, PM, Y, X );

    gsl_permutation_free( PM );
    gsl_vector_free( Y );
    gsl_matrix_free( A );

    return X;
}

void linear_interpolation_ublas_test(){
    ublas::vector< double > expected( 2 );
    expected( 0 ) = 5.0 / 2;
    expected( 1 ) = -13.0 / 2;

    ublas::vector< double > const actual = linear_interpolation_ublas(
        std::vector< Point >{ { 5, 6 }, { 7, 11 } }
    );

    auto feqDouble = [](double d1, double d2){
        return feq(d1, d2);
    };

    assert(
        std::equal(
            actual.begin(),
            actual.end(),
            expected.begin(),
            feqDouble
        )
    );
}

void polynominal_interpolation_ublas_test(){
    ublas::vector< double > expected( 3 );
    expected( 0 ) = 7;
    expected( 1 ) = 6;
    expected( 2 ) = -1;

    ublas::vector< double > const actual = polynominal_interpolation_ublas(
        std::vector< Point >{ { 1, 12 }, { 2, 15 }, { 3, 16 } }
    );

    auto feqDouble = [](double d1, double d2){
        return feq(d1, d2);
    };

    assert(
        std::equal(
            actual.begin(),
            actual.end(),
            expected.begin(),
            feqDouble
        )
    );
}

void linear_interpolation_gsl_test(){
    gsl_vector * expected = gsl_vector_alloc( 2 );
    gsl_vector_set( expected, 0, 5.0 / 2 );
    gsl_vector_set( expected, 1, -13.0 / 2 );

    gsl_vector * actual = linear_interpolation_gsl(
        std::vector< Point >{ { 5, 6 }, { 7, 11 } }
    );

    for( std::size_t i = 0 ; i < 2 ; ++ i ){
        assert((
            feq(
                gsl_vector_get( actual, i ),
                gsl_vector_get( expected, i )
            )
        ));
    }

    gsl_vector_free( actual );
    gsl_vector_free( expected );
}

void polynominal_interpolation_gsl_test(){
    gsl_vector * expected = gsl_vector_alloc( 3 );
    gsl_vector_set( expected, 0, 7 );
    gsl_vector_set( expected, 1, 6 );
    gsl_vector_set( expected, 2, -1 );

    gsl_vector * actual = polynominal_interpolation_gsl(
        std::vector< Point >{ { 1, 12 }, { 2, 15 }, { 3, 16 } }
    );

    for( std::size_t i = 0 ; i < 3 ; ++ i ){
        assert((
            feq(
                gsl_vector_get( actual, i ),
                gsl_vector_get( expected, i )
            )
        ));
    }

    gsl_vector_free( actual );
    gsl_vector_free( expected );
}

#include <vector>

int main(){
    linear_interpolation_ublas_test();
    linear_interpolation_gsl_test();

    polynominal_interpolation_ublas_test();
    polynominal_interpolation_gsl_test();
}
