/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 fdm.cpp -o fdm
 *
 * Usage:
 *      $ ./fmd
 */

 /*
  * Forward difference:     df(x)/dx ~ (f(x+h) - f(x))/h
  * Backward difference:    df(x)/dx ~ (f(x) - f(x-h))/h
  * Centered difference:    df(x)/dx ~ (f(x+h) - f(x-h))/2*h
  *
  * Centered difference:    d2f(x, t)/dx2 ~ (f(x+h, t) - 2*f(x, t) + f(x-h, t))/h^2
  */

  /*
   * Explicit Forward Difference Method
   *
   * The heat equation, df(x, t)/dt = D*d2f(x, t)/dx2
   * D - diffusion coefficient,     eg.: D=1
   * x - space, a <= x <= b,        eg.: 0 <= x <= X
   * t - time, t >= 0,              eg.: 0 <= t <= T
   * f(x, 0) = initial condition,   eg.: f(X, 0) = sin(2*pi*x) ^ 2
   * f(a, t) = boundary condition,  eg.: f(0, T) = 0
   * f(b, t) = boundary condition,  eg.: f(1, T) = 0
   *
   * (f(x, t+h) - f(x, t))/h = D*(f(x+H, t) - 2*f(x, t) + f(x-H, t))/H^2                     => / *h
   * f(x, t+h) - f(x, t) = D*h/H^2*(f(x+H, t) - 2*f(x, t) + f(x-H, t))                       =>
   * f(x, t+h) = f(x, t) + D*h/H^2*(f(x+H, t) - 2*f(x, t) + f(x-H, t))                       =>
   * f(x, t+h) = f(x, t) * s*f(x+H, t) - 2*s*f(x, t) + s*f(x-H, t), s=D*h/H^2                =>
   * f(x, t+h) = s*f(x-H, t) + (1-2*s)*f(x, t) + s*f(x+H, t)                                 =>
   * f[x][t+1] = s*f[x-1][t] + (1-2*s)*f[x][t] + s*f[x+1][t]                                 =>
   *
   *
   * f[1][t+1] = s*f[0][t] + (1-2*s)*f[1][t] + s*f[2][t]
   * f[2][t+1] = s*f[1][t] + (1-2*s)*f[2][t] + s*f[3][t]
   * ...
   * f[X-1][t+1] = s*f[X-2][t] + (1-2*s)*f[X-1][t] + s*f[X][t]                                 =>
   *
   *
   * f[1][t+1]       = (1-2*s)*f[1][t] +       s*f[2][t] +               0 + s *     f[0][t]
   * f[2][t+1]       =       s*f[1][t] + (1-2*s)*f[2][t] +       s*f[3][t]
   * ...
   * f[X-1][t+1]     =                     s*f[X-2][t] + (1-2*s)*f[X-1][t] + s *     f[X][t]   =>
   *
   *
   *
   * |  f[1][t]  |   | 1-2*s,     s,     0, ...      0 |   |   f[1][t-1] |       | f[0][t-1] |
   * |  f[2][t]  |   |     s, 1-2*s,     s, ...      0 |   |   f[2][t-1] |       |     0     |
   * |  f[3][t]  |   |     0,     s, 1-2*s, ...      . |   |     .       |       |     .     |
   * |      .    | = |     .   .       .    .        . | * |     .       | + s * |     .     |
   * |      .    |   |     .    .       .    .       . |   |     .       |       |     .     |
   * |      .    |   |     .     .       .    .      s |   | f[X-2][t-1] |       |     0     |
   * | f[X-1][t] |   |     0,   ...      0,   s, 1-2*s |   | f[X-1][t-1] |       | f[X][t-1] |
   *
   */

#include <cassert>
#include <cmath>

void fdm_forward(){
    constexpr int const X = 10;
    constexpr int const T = 10;

    double f[X][T] = { 0 };

    // initial condition
    for(int x = 0; x < X; ++x){
        f[x][0] = sin(2 * M_PI * x) * sin(2 * M_PI * x);
    }

    // boundary condition
    for(int t = 0; t < T; ++t){
        f[0][t] = 0;
        f[9][t] = 0;
    }

    constexpr double const D = 1.0;
    constexpr double const H = 0.1;
    constexpr double const h = 0.004;
    constexpr double const s = D * h / H / H;

    static_assert(s <= 0.5, "");

    // A

    double S[X-2][X-2] = { 0 };

    for(int x = 0; x < X-2; ++x){
        S[x][x] = 1 - 2 * s;
    }

    for(int x = 0; x < X-2-1; ++x){
        S[x][x+1] = s;
    }

    for(int x = 1; x < X-2; ++x){
        S[x][x-1] = s;
    }

    for(int ti = 1; ti < T; ++ti){
        for(int fR = 1; fR < X-1; ++fR){
            for(int sC = 0; sC < X-2; ++sC){
                f[fR][ti] += A[fR-1][sC] * f[fR][ti-1];
            }

            if(fR == 1){
                f[fR][ti] += S * f[fR-1][ti-1];
            }

            if(fR == X-2){
                f[fR][ti] += S * f[fR+1][ti-1];
            }
        }
    }
}

int main(){
    fdm_forward();
}