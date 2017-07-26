/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 cholesky.cpp -o cholesky
 *
 * Usage:
 *      $ ./cholesky
 */

#include "matrix.hpp"

Matrix cholesky(Matrix a){
    // Cholesky decomposition: r.T * r = a

    Matrix r(a.rows(), a.columns(), 0);

    for(unsigned diag = 0; diag < a.rows(); ++diag){
        r[diag][diag] = sqrt(a[diag][diag]);

        for(unsigned column = diag + 1; column < a.columns(); ++column){
            r[diag][column] = a[diag][column] / r[diag][diag];
        }

        for(unsigned row = 0; row < a.rows() - diag - 1; ++row){
            for(unsigned column = 0; column < a.columns() - diag - 1; ++column){
                double const uut = r[diag][diag + 1 + row] * r[diag][diag + 1 + column];

                a[diag + 1 + row][diag + 1 + column] -= uut;
            }
        }
    }

    return r;
}

#include <cassert>
#include <iostream>

int main(){
    {
        Matrix a(2, 2);
        a[0][0] = 4;
        a[0][1] = -2;
        a[1][0] = -2;
        a[1][1] = 2;
        Matrix r = cholesky(a);

        assert(transpose(r) * r == a);
    }
    {
        Matrix a(3, 3);
        a[0][0] = 4;
        a[0][1] = -2;
        a[0][2] = 2;
        a[1][0] = -2;
        a[1][1] = 2;
        a[1][2] = -4;
        a[2][0] = 2;
        a[2][1] = -4;
        a[2][2] = 11;

        Matrix r = cholesky(a);

        assert(transpose(r) * r == a);
    }
    {
        Matrix a(3, 3);
        a[0][0] = 4;
        a[0][1] = -2;
        a[0][2] = 2;
        a[1][0] = -2;
        a[1][1] = 2;
        a[1][2] = -4;
        a[2][0] = 2;
        a[2][1] = -4;
        a[2][2] = 11;

        Matrix r = cholesky(a);

        assert(transpose(r) * r == a);
    }
    {
        Matrix a(4, 4);
        a[0][0] = 15;
        a[0][1] = -5;
        a[0][2] = 0;
        a[0][3] = -5;
        a[1][0] = -5;
        a[1][1] = 12;
        a[1][2] = -2;
        a[1][3] = 0;
        a[2][0] = 0;
        a[2][1] = -2;
        a[2][2] = 6;
        a[2][3] = -2;
        a[3][0] = -5;
        a[3][1] = 0;
        a[3][2] = -2;
        a[3][3] = 9;

        Matrix r = cholesky(a);

        std::cout << r << std::endl;
        std::cout << transpose(r) * r << std::endl;

        assert(transpose(r) * r == a);
    }
}
