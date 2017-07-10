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
        double const k2 = h * f(x0 + h/2, y + h * k1/2);
        return k2;
    };

    return solveOdeImpl(approx, x0, xN, h, y0);
}

double solveOdeTrapezoid(
    std::function<double (double, double)> f,
    double x0,
    double xN,
    double h,
    double y0
){
    auto approx = [&f](double x0, double x1, double y){
        double const h = (x1 - x0);
        double const x0Slope = h * f(x0, y);
        double const x1Slope = h * f(x1, y + h * f(x0, y));

        return (x0Slope + x1Slope) / 2;
    };

    return solveOdeImpl(approx, x0, xN, h, y0);
}

double solveOdeRungeKutta4(
    std::function<double (double, double)> f,
    double x0,
    double xN,
    double h,
    double y0
){
    auto approx = [&f](double x0, double x1, double y){
        double const h = (x1 - x0);
        double const k1 = h * f(x0, y);
        double const k2 = h * f(x0 + h/2, y + k1/2);
        double const k3 = h * f(x0 + h/2, y + k2/2);
        double const k4 = h * f(x0 + h, y + k3);
        return (k1 + 2*k2 + 2*k3 + k4) / 6;
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
    assert(feq(10.045, solveOdeTrapezoid(f, 0, 3, 0.3, 1)));
    assert(feq(9.9775, solveOdeEulerMidpoint(f, 0, 3, 0.3, 1)));
    assert(feq(10.000, solveOdeRungeKutta4(f, 0, 3, 0.3, 1)));
}
