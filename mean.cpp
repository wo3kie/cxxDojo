/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 mean.cpp -o mean
 *
 * Usage:
 *      $ ./mean
 */

#include <cassert>

#include "./mean.hpp"

int main(){
    assert( 2.0 == mean<double>( { 1.0, 2.0, 3.0 } ) );
    assert( 0.0 == mean<double>( { - 1.0, 0, 1.0 } ) );
}
