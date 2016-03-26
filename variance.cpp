/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 variance.cpp -o variance
 *
 * Usage:
 *      $ ./variance
 */

#include <cassert>

#include "./feq.hpp"
#include "./variance.hpp"

int main(){
    assert( feq(3.067, variance<double>( { 7, 6, 8, 4, 2, 7, 6, 7, 6, 5 } ) ) );
}
