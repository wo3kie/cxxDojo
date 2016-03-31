/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 ode.euler.cpp -o ode.euler
 *
 * Usage:
 *      $ ./ode.euler
 */

#include <cassert>
#include <functional>

#include "./feq.hpp"

double solveOdeEuler(
    std::function<double (double, double)> f,
    double x0,
    double xN,
    double h,
    double y0
){
    double x = x0 + h;
    double y = y0;

    while(x <= xN){
        {
            // basic
            // y = y + h * f(x - h, y);
        }

        {
            // midpoint
            double const k1 = h * f(x - h, y);
            double const k2 = h * f(x - h/2, y + h*k1/2);
            y = y + k2;
        }

        x += h;
    }

    return y;
}

double f(double x, double y){
    // f(x) = 3x^3
    // f'(x) = x * x
    return x * x;
}

int main(){
    assert(feq(9.9775, solveOdeEuler(f, 0, 3, 0.3, 1)));
}
