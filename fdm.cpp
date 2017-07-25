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
 *      $ ./fmd | gnuplot5 -p
 */

 /*
  * Forward difference:     df(x)/dx ~ (f(x+h) - f(x))/h
  * Backward difference:    df(x)/dx ~ (f(x) - f(x-h))/h
  * Centered difference:    df(x)/dx ~ (f(x+h) - f(x-h))/2*h
  *
  * Centered difference:    d2f(x, t)/dx2 ~ (f(x+h, t) - 2*f(x, t) + f(x-h, t))/h^2
  */

#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>

template<int N, int M>
void print(double (&f)[N][M]){
    for(int n = 0; n < N; ++n){
        std::cout << '[';

        for(int m = 0; m < M; ++m){
            std::cout << std::setprecision(5) << f[n][m] << ' ';
        }

        std::cout << "]\n";
    }

    std::cout << '\n';
}

void fdm_forward(){
    /*
    * Explicit Forward Difference Method
    *
    * The heat equation, df(x, t)/dt = D*d2f(x, t)/dx2
    * D - diffusion coefficient,     eg.: D=1
    * x - space,                     eg.: 0 <= x <= X
    * t - time,                      eg.: 0 <= t <= T
    * f(x, 0) = initial condition,   eg.: f(X, 0) = sin(2*pi*x) ^ 2
    * f(a, t) = boundary condition,  eg.: f(0, T) = 0
    * f(b, t) = boundary condition,  eg.: f(1, T) = 0
    *
    * (f(x, t+dt) - f(x, t))/dt = D*(f(x+dx, t) - 2*f(x, t) + f(x-dx, t))/dx^2              => / *dt
    * f(x, t+dt) - f(x, t) = D*dt/dx^2*(f(x+dx, t) - 2*f(x, t) + f(x-dx, t))                =>
    * f(x, t+dt) = f(x, t) + D*dt/dx^2*(f(x+dx, t) - 2*f(x, t) + f(x-dx, t))                =>
    * f(x, t+dt) = f(x, t) * s*f(x+dx, t) - 2*s*f(x, t) + s*f(x-dx, t), s=D*dt/dx^2         =>
    * f(x, t+dt) = s*f(x-dx, t) + (1-2*s)*f(x, t) + s*f(x+dx, t)                            =>
    * f[x][t+1]  = s*f[x-1][t] + (1-2*s)*f[x][t] + s*f[x+1][t]                              =>
    *
    *
    * f[1][t]   = s*f[0][t-1] + (1-2*s)*f[1][t-1] + s*f[2][t-1]
    * f[2][t]   = s*f[1][t-1] + (1-2*s)*f[2][t-1] + s*f[3][t-1]
    * ...
    * f[X-1][t] = s*f[X-2][t-1] + (1-2*s)*f[X-1][t-1] + s*f[X][t-1]                         =>
    *
    *
    * |  f[1][t]  |   | 1-2*s,     s,     0, ...      0 |   |   f[1][t-1] |       | f[0][t-1] |
    * |  f[2][t]  |   |     s, 1-2*s,     s, ...      0 |   |   f[2][t-1] |       |     0     |
    * |  f[3][t]  |   |     0,     s, 1-2*s, ...      . |   |       .     |       |     .     |
    * |     .     | = |     .   .       .    .        . | * |       .     | + s * |     .     |
    * |     .     |   |     .    .       .    .       . |   |       .     |       |     .     |
    * |     .     |   |     .     .       .    .      s |   | f[X-2][t-1] |       |     0     |
    * | f[X-1][t] |   |     0,   ...      0,   s, 1-2*s |   | f[X-1][t-1] |       | f[X][t-1] |
    *
    */

    constexpr double const D = 1.0;
    constexpr double const dx = 0.1;
    constexpr double const dt = 0.004;
    constexpr double const s = D * dt / dx / dx;

    //static_assert(s <= 0.5, "");

    constexpr int const X = 1 + 1 / dx;
    constexpr int const T = 1 + 1 / dt;

    double f[X][T] = { 0 };
    double S[X-2][X-2] = { 0 };

    for(int x = 0; x < X; ++x){
        f[x][0] = sin(2 * M_PI * x * dx) * sin(2 * M_PI * x * dx);
    }

    for(int t = 0; t < T; ++t){
        f[0][t] = 0;
        f[9][t] = 0;
    }

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
        f[1][ti] += s * f[0][ti-1];

        for(int fR = 1; fR < X-1; ++fR){
            for(int sC = 0; sC < X-2; ++sC){
                f[fR][ti] += S[fR-1][sC] * f[sC+1][ti-1];
            }
        }

        f[X-2][ti] += s * f[X-1][ti-1];
    }

    {
        std::cout
            << "# gnuplot 5.1 file script\n"
            << "$data << EOD\n";

        for(int x = 0; x < X; ++x){
            for(int t = 0; t < T; ++t){
                std::cout << (x*dx) << " " << (t*dt) << " " << std::setprecision(5) << f[x][t] << '\n';
            }
        }

        std::cout
            << "EOD\n"
            << "set xrange [0:1]\n"
            << "set xlabel \"X\"\n"
            << "set yrange [0:1]\n"
            << "set ylabel \"Time\"\n"
            << "set zrange [0:0.2]\n"
            << "set zlabel \"Temp\"\n"
            << "set dgrid3d 50, 50\n"
            << "set hidden3d\n"
            << "splot \"$data\" with lines\n";
    }
}

int main(){
    fdm_forward();
}
