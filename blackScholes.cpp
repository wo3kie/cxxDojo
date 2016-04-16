/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 blackScholes.cpp -o blackScholes
 *
 * Usage:
 *      $ ./blackScholes
 */

#include <cmath>
#include <vector>

#include "./matrix.hpp"
#include "./output.hpp"

/* Black-Scholes Explicit Finite Difference Method for Call Options
 *
 * df/dt + 1/2 * o^2 * S^2 * d2f/dS2 + r * S * df/dS - r * f = 0, where
 *   f - option price function, f(S, t)
 *   t - time, 0<=t<T
 *   S - stock price, 0<=S<sMax
 *   sMax - maximum stock price to consider
 *   o - sigma - annual volatility
 *   r - risk free interest rate
 *
 * With Taylor Series
 *   f(x + dx) = f(x) + f'(x)dx + f''(x)(dx)(dx)/2! + ...
 * we can get a following approximations
 *
 * Forward  f'(t*dt, s*ds)ds  ~ (f[t][s+1] - f[t][s])/ds
 * Forward  f'(t*dt, s*ds)dt  ~ (f[t+1][s] - f[t][s])/dt
 *
 * Backward f'(t*dt, s*ds)ds  ~ (f[t][s] - f[t][s-1])/ds
 * Backward f'(t*dt, s*ds)dt  ~ (f[t][s] - f[t-1][s])/dt
 *
 * Central  f'(t*dt, s*ds)ds  ~ (f[t][s+1] - f[t][s-1])/2ds
 * Central  f'(t*dt, s*ds)dt  ~ (f[t+1][s] - f[t-1][s])/2dt
 *
 *          f''(t*dt, s*ds)ds ~ (f[t][s+1] - 2f[t][s] + f[t][s-1])/(dsds)
 *          f''(t*dt, s*ds)dt ~ (f[t+1][s] - 2f[t][s] + f[t-1][s])/(dtdt)
 *
 *
 * Using backward approximation for df/dt <- (f[t][s] - f[t-1][s])/dt
 *        central approximation for df/dS <- (f[t][s+1] - f[t][s-1])/2ds
 *                        and for d2f/dS2 <- (f[t][s+1] + f[t][s-1] - 2f[t][s])/dsds
 * we can get explicit method equation
 *
 * f[t][s] = a[s] * f[t+1][s-1] + b[s] * f[t+1][s] + c[s] * f[t+1][s+1], where
 *   a[s] = (k/2) * (o * o * s * s - r * s)
 *   b[s] = (1-k) * (r * o * o * m * m)
 *   c[s] = (k/2) * (o * o * s * s + r * s)
 *
 * Further reading:
 *   http://mathtm.blogspot.co.uk/2014/08/analysis-of-black-scholes-pde.html
 *   http://www.goddardconsulting.ca/matlab-finite-diff-explicit.html
 *   https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes
 */

Matrix blackScholes_FDM_Explicit(
    double const r,       // risk free rate               (%)
    double const o,       // annual volatility            (%)
    double const tMax,    // expiry date,                 (y) 1.0=1y, 0.25=3m
    double const K,       // strike price                 ($)
    double const sMax,    // max stock price to consider  ($)
    double const dT,      // time step                    (y) 1.0=1y, 0.25=3m
    double const dS       // stock price step             ($)
)
{
    double const T = tMax / dT;
    double const S = sMax / dS;
    Matrix f = Matrix(T + 1, S + 1, -1);

    // f(0, t) = 0
    for(int t = 0; t <= T; t++){
        f[t][0] = 0;
    }

    // f(S, t) = sMax - Ke^-r(T-t)
    for(int t = 0; t <= T; t++){
        f[t][S] = sMax - K * std::exp(-r * (tMax - 1.0 * t * dT));
    }

    // f(s,T) = max(S-K, 0)
    for(int s = 0; s <= S; s++){
        f[T][s] = std::max(1.0 * s * dS - K, 0.0);
    }

    for(int t = T - 1; t >= 0; t--){
        for(int s = 1; s <= S - 1; s++){
            double const a = (dT / 2) * (o * o * s * s - r * s);
            double const b = 1 - dT * (r + o * o * s * s);
            double const c = (dT / 2) * (o * o * s * s + r * s);

            f[t][s] = a * f[t + 1][s - 1] + b * f[t + 1][s] + c * f[t + 1][s + 1];
        }
    }

    return f;
}

/*
 * Analytical solution
 *
 * C(S, t) = N(d1) * S - N(d2) * K * e ^(-r * (T - t))
 *   d1 = (1 / (o * sqrt(T - t))) * (ln(S / K) + (r + o * o / 2)(T - t)
 *   d2 = d1 - o * sqrt(T - t)
 *
 * where
 *
 *   N(x) - cumulative distribution function of the standard normal distribution
 *   T - expiry time
 *   T - t - time to maturity
 *   S - spot price of the underlying asset
 *   K - strike price
 *   r - risk free interest rate
 *   o - sigma - the volatility of returns of the underlying asset
 */

double N(double x)
{
    double const a1 = 0.31938153;
    double const a2 = -0.356563782;
    double const a3 = 1.781477937;
    double const a4 = -1.821255978;
    double const a5 = 1.330274429;

    double const L = fabs(x);
    double const K = 1.0 / (1.0 + 0.2316419 * L);
    double const w = 1.0 - 1.0 / sqrt(2 * M_PI) * exp(-L * L / 2)
        * (a1 * K + a2 * K * K + a3 * pow(K, 3) + a4 * pow(K, 4) + a5 * pow(K, 5));

    if (x < 0){
        return 1.0 - w;
    }

    return w;
}

Matrix blackScholes_Formula(
    double const r,       // risk free rate               (%)
    double const o,       // annual volatility            (%)
    double const tMax,    // expiry date,                 (y) 1.0=1y, 0.25=3m
    double const K,       // strike price                 ($)
    double const sMax,    // max stock price to consider  ($)
    double const dT,      // time step                    (y) 1.0=1y, 0.25=3m
    double const dS       // stock price step             ($)
){
    double const T = tMax / dT;
    double const S = sMax / dS;
    Matrix f = Matrix(T + 1, S + 1, -1);

    for(int t = 0; t <= T; ++t){
        for(int s = 0; s <= S; s++){
            double const time = tMax - 1.0 * t * dT;
            double const price = 1.0 * s * dS;

            double const d1 = (1 / (o * std::sqrt(time)))
                * (std::log(price / K) + (r + o * o / 2) * (time));

            double const d2 = d1 - o * std::sqrt(time);

            f[t][s] = N(d1) * price - N(d2) * K * std::exp(-r * (time));
        }
    }

    return f;
}

/*
 * main
 */

int main(int argc, char **argv) {
    Matrix const fdme = blackScholes_FDM_Explicit(
        0.1,
        0.4,
        0.25,
        10,
        30,
        0.001,
        0.5
    );

    Matrix const form = blackScholes_Formula(
        0.1,
        0.4,
        0.25,
        10,
        30,
        0.001,
        0.5
    );

    // fdm - fm
    std::cout << (fdme + (form * -1)) << "\n";

    return 0;
}
