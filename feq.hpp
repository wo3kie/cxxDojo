/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_FEQ_HPP
#define CXX_DOJO_FEQ_HPP

constexpr bool feq( float const f1, float const f2, float const eps = 0.0001f ){
    return (f1-f2) < eps || (f2 - f1) < eps;
}

constexpr bool feq( double const f1, double const f2, double const eps = 0.0001 ){
    return (f1-f2) < eps || (f2 - f1) < eps;
}


constexpr bool feq( long double const f1, long double const f2, long double const eps = 0.0001 ){
    return (f1-f2) < eps || (f2 - f1) < eps;
}

#endif

