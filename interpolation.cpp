/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 interpolation.cpp -o interpolation
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

namespace ublas = boost::numeric::ublas;

struct Point
{
    double x_;
    double y_;
};

ublas::vector< double > interpolation_ublas( std::vector< Point > const & points ){
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

gsl_vector * interpolation_gsl( std::vector< Point > const & points ){
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

void interpolation_ublas_test(){
    ublas::vector< double > expected( 3 );
    expected( 0 ) = 7;
    expected( 1 ) = 6;
    expected( 2 ) = -1;

    ublas::vector< double > const actual = interpolation_ublas(
        std::vector< Point >{ { 1, 12 }, { 2, 15 }, { 3, 16 } }
    );

    assert( std::equal( actual.begin(), actual.end(), expected.begin() ) );
}

void interpolation_gsl_test(){
    gsl_vector * expected = gsl_vector_alloc( 3 );
    gsl_vector_set( expected, 0, 7 );
    gsl_vector_set( expected, 1, 6 );
    gsl_vector_set( expected, 2, -1 );

    gsl_vector * actual = interpolation_gsl( 
        std::vector< Point >{ { 1, 12 }, { 2, 15 }, { 3, 16 } } 
    );

    for( std::size_t i = 0 ; i < 3 ; ++ i ){
        assert(( gsl_vector_get( actual, i ) == gsl_vector_get( expected, i ) ));
    }

    gsl_vector_free( actual );
    gsl_vector_free( expected );
}

int main(){
    interpolation_ublas_test();
    interpolation_gsl_test();
}

