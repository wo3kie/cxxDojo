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

double solveOdeImpl(
    std::function<double (double, double, double)> approx,
    double x0,
    double const xN,
    double const h,
    double y0
){
    while(x0 + h <= xN){
        y0 += approx(x0, x0 + h, y0);
        x0 += h;
    }

    return y0;
}

double solveOdeEulerForward(
    std::function<double (double, double)> f,
    double x0,
    double xN,
    double h,
    double y0
){
    auto approx = [&f](double x0, double x1, double y){
        double const h = x1 - x0;
        return h * f(x0, y);
    };

    return solveOdeImpl(approx, x0, xN, h, y0);
}

double solveOdeEulerMidpoint(
    std::function<double (double, double)> f,
    double x0,
    double xN,
    double h,
    double y0
){
    auto approx = [&f](double x0, double x1, double y){
        double const h = (x1 - x0);
        double const k1 = h * f(x0, y);
        double const k2 = h * f(x0 + h / 2, y + h * k1 / 2);
        return k2;
    };

    return solveOdeImpl(approx, x0, xN, h, y0);
}

double f(double x, double y){
    // f(x) = 3x^3
    // f'(x) = x * x
    return x * x;
}

#include <iostream>

int main(){
    assert(feq(8.6950, solveOdeEulerForward(f, 0, 3, 0.3, 1)));
    assert(feq(9.9775, solveOdeEulerMidpoint(f, 0, 3, 0.3, 1)));
}
