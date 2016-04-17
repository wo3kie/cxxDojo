/*
 * Website:
 *      tttps://gittub.com/wo3kie/dojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 brownianMotion.cpp -o brownianMotion
 *
 * Usage:
 *      $ ./brownianMotion
 */

#include <cmath>
#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

double brownianMotion(double xt, double h){
    /*
     * X(t+h) - X(t) ~ sqrt(t) * N(0, 1) = N(0, t)
     *      = arithmeticBrownianMotion(xt, h, 0, 1)
     */

    double const xth = xt + std::normal_distribution<>(0, h)(gen);
    return xth;
}

double brownianMotion(double t){
    return brownianMotion(0, t);
}

double arithmeticBrownianMotion(double xt, double h, double u, double o){
    /*
     * X(t+h) - X(t) ~ uh + o[X(t+h) - X(t)] = uh + o[N(0, t)] = uh + N(0, oot) = N(uh, oot)
     */

    double const xth = xt + std::normal_distribution<>(u * h, o * o * h)(gen);
    return xth;
}

double arithmeticBrownianMotion(double t, double u, double o){
    return arithmeticBrownianMotion(0, t, u, o);
}

double geometricBrownianMotion(double xt, double h, double u, double o){
    /*
     * X(t+h)/X(t) = exp(u*h + o[X(t+h) - X(t)]) ~ exp(N(uh, oot))
     */

     double const xth = xt * std::exp(std::normal_distribution<>(u * h, o * o * h)(gen));
     return xth;
}

double geometricBrownianMotion(double t, double u, double o){
    return geometricBrownianMotion(0, t, u, o);
}

int main(){
    double bm = 1;
    double abm = 1;
    double gbm = 1;

    for(double d = 0; d < 10; d += 0.1){
        std::cout << d << " " << bm << " " << abm << " " << gbm << "\n";

        bm = brownianMotion(bm, 0.1);
        abm = arithmeticBrownianMotion(abm, 0.1, 1, 1);
        gbm = geometricBrownianMotion(gbm, 0.1, 0.4, 0.4);
    }
}
