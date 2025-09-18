/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 black_scholes.cpp -o black_scholes
 *
 * Usage:
 *      $ ./black_scholes
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
    const double r,    // risk free rate               (%)
    const double o,    // annual volatility            (%)
    const double tMax, // expiry date,                 (y) 1.0=1y, 0.25=3m
    const double K,    // strike price                 ($)
    const double sMax, // max stock price to consider  ($)
    const double dT,   // time step                    (y) 1.0=1y, 0.25=3m
    const double dS    // stock price step             ($)
) {
  /*
     * Stability criterion is given by the formula: dT/(dSdS) <= 1/2
     */

  const double T = tMax / dT;
  const double S = sMax / dS;
  Matrix f = Matrix(T + 1, S + 1, -1);

  // f(0, t) = 0
  for(int t = 0; t <= T; t++) {
    f[t][0] = 0;
  }

  // f(S, t) = sMax - Ke^-r(T-t)
  for(int t = 0; t <= T; t++) {
    f[t][S] = sMax - K * std::exp(-r * (tMax - 1.0 * t * dT));
  }

  // f(s,T) = max(S-K, 0)
  for(int s = 0; s <= S; s++) {
    f[T][s] = std::max(1.0 * s * dS - K, 0.0);
  }

  for(int t = T - 1; t >= 0; t--) {
    for(int s = 1; s <= S - 1; s++) {
      const double a = (dT / 2) * (o * o * s * s - r * s);
      const double b = 1 - dT * (r + o * o * s * s);
      const double c = (dT / 2) * (o * o * s * s + r * s);

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

double N(double x) {
  const double a1 = 0.31938153;
  const double a2 = -0.356563782;
  const double a3 = 1.781477937;
  const double a4 = -1.821255978;
  const double a5 = 1.330274429;

  const double L = fabs(x);
  const double K = 1.0 / (1.0 + 0.2316419 * L);
  const double w = 1.0 - 1.0 / sqrt(2 * M_PI) * exp(-L * L / 2) * (a1 * K + a2 * K * K + a3 * pow(K, 3) + a4 * pow(K, 4) + a5 * pow(K, 5));

  if(x < 0) {
    return 1.0 - w;
  }

  return w;
}

Matrix blackScholes_Formula(
    const double r,    // risk free rate               (%)
    const double o,    // annual volatility            (%)
    const double tMax, // expiry date,                 (y) 1.0=1y, 0.25=3m
    const double K,    // strike price                 ($)
    const double sMax, // max stock price to consider  ($)
    const double dT,   // time step                    (y) 1.0=1y, 0.25=3m
    const double dS    // stock price step             ($)
) {
  const double T = tMax / dT;
  const double S = sMax / dS;
  Matrix f = Matrix(T + 1, S + 1, -1);

  for(int t = 0; t <= T; ++t) {
    for(int s = 0; s <= S; s++) {
      const double time = tMax - 1.0 * t * dT;
      const double price = 1.0 * s * dS;

      const double d1 = (1 / (o * std::sqrt(time))) * (std::log(price / K) + (r + o * o / 2) * time);

      const double d2 = d1 - o * std::sqrt(time);

      f[t][s] = N(d1) * price - N(d2) * K * std::exp(-r * time);
    }
  }

  return f;
}

/*
 * Monte Carlo
 */

#include <random>

Matrix monteCarlo(
    const double r,    // risk free rate               (%)
    const double o,    // annual volatility            (%)
    const double tMax, // expiry date,                 (y) 1.0=1y, 0.25=3m
    const double K,    // strike price                 ($)
    const double sMax, // max stock price to consider  ($)
    const double dT,   // time step                    (y) 1.0=1y, 0.25=3m
    const double dS    // stock price step             ($)
) {
  const double T = tMax / dT;
  const double S = sMax / dS;
  Matrix f = Matrix(T + 1, S + 1, -1);

  std::random_device rd;
  std::mt19937 gen(rd());

  for(int t = 0; t <= T; ++t) {
    for(int s = 0; s <= S; s++) {
      double N = 200;
      double runningSum = 0;
      const double price = 1.0 * s * dS;
      const double time = tMax - 1.0 * t * dT;

      for(unsigned long i = 0; i < N; i++) {
        const double wt = std::sqrt(time) * std::normal_distribution<>(0, 1)(gen);
        const double e = ((r - 0.5 * o * o) * time) + o * wt;
        const double S = price * std::exp(e);

        runningSum += std::max(S - K, 0.0);
      }

      f[t][s] = exp(-r * time) * (runningSum / N);
    }
  }

  return f;
}

/*
 * main
 */

int main(int argc, char** argv) {
  const Matrix fdme = blackScholes_FDM_Explicit(0.1, 0.4, 0.25, 10, 30, 0.001, 0.5);
  const Matrix form = blackScholes_Formula(0.1, 0.4, 0.25, 10, 30, 0.001, 0.5);
  const Matrix mc = monteCarlo(0.1, 0.4, 0.25, 10, 30, 0.001, 0.5);

  std::cout << (form + (fdme * -1)) << "\n\n" << (form + (mc * -1)) << "\n";

  return 0;
}
