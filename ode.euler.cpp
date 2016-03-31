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
    unsigned n,
    double x0,
    double y0,
    double c
){
    double x = x0;
    double y = y0;
    double h = (c - x0) / n;

    for(unsigned i = 0; i < n; ++i){
        double const fx = f(x, y);
        double const fxh = f(x + h, y + h * fx);

        x += h;
        y += h * (fx + fxh) / 2;
    }

    return y;
}

double f(double x, double y){
    return 3 * x + 2 * y + 1;
}

int main(){
    assert(feq(77.5625, solveOdeEuler(f, 100, 0, 0.25, 2)));
}
