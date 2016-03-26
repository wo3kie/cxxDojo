/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 correlation.cpp -o correlation
 *
 * Usage:
 *      $ ./correlation
 */

#include <cassert>

#include "./feq.hpp"
#include "./correlation.hpp"

int main(){
    double const correlationValue = correlation<double>(
        { 1.2, 2.0, 2.5, 4.0, 3.0, 6.0, 5.5, 6.3, 7.1, 5.4 },
        { 3.4, 3.3, 3.0, 5.5, 1.2, 2.4, 3.2, 3.1, 2.9, 3.2 }
    );

    assert(feq(correlationValue, -0.050601));
}
