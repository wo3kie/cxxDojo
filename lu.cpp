/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 lu.cpp -o lu
 *
 * Usage:
 *      $ ./lu
 */

#include <cmath>
#include <vector>

#include "./feq.hpp"
#include "./matrix.hpp"

Matrix pivotaize(Matrix const & m){
    unsigned const size = m.rows();

    Matrix result = Matrix(size, size);

    for(unsigned i = 0; i < size; ++i){
        result[i][i] = 1;
    }

    for(unsigned row = 0; row < size; ++row){
        unsigned maxRow = row;

        for(unsigned row2 = maxRow + 1; row2 < size; ++row2){
            if(std::abs(m[row2][row]) > std::abs(m[maxRow][row])){
                maxRow = row2;
            }
        }

        if(row != maxRow){
            std::swap(result[row], result[maxRow]);
        }
    }

    return result;
}

void lu(Matrix const & A, Matrix & L, Matrix & U, Matrix & P){
    unsigned const size = A.rows();

    L = Matrix(size, size);
    U = Matrix(size, size);
    P = pivotaize(A);

    Matrix const A2 = P * A;

    for(unsigned a = 0; a < size; ++a){
        L[a][a] = 1.0;

        for(unsigned b = 0; b < a + 1; ++b){
            double s = 0;

            for(unsigned c = 0; c < b; ++c){
                s += U[c][a] * L[b][c];
            }

            U[b][a] = A2[b][a] - s;
        }

        for(unsigned b = a; b < size; ++b){
            double s = 0;

            for(unsigned c = 0; c < a; ++c){
                s += U[c][a] * L[b][c];
            }

            L[b][a] = (A2[b][a] - s) / U[a][a];
        }
    }
}

int main(){
    Matrix L;
    Matrix U;
    Matrix P;

    {
        Matrix A = {
            {4, 3},
            {6, 3}
        };

        lu(A, L, U, P);

        std::cout << "A: \n" << A << std::endl;
        std::cout << "P: \n" << P << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "L: \n" << L << std::endl;
        std::cout << "U: \n" << U << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "LU: \n" << L * U << std::endl << std::endl;

        assert(P * A == L * U);
    }

    {
        Matrix A = {
            {1, 3, 5},
            {2, 4, 7},
            {1, 1, 0}
        };

        lu(A, L, U, P);

        std::cout << "A: \n" << A << std::endl;
        std::cout << "P: \n" << P << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "L: \n" << L << std::endl;
        std::cout << "U: \n" << U << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "LU: \n" << L * U << std::endl << std::endl;

        assert(P * A == L * U);
    }

    {
        Matrix A = {
            {8, 2, 9},
            {4, 9, 4},
            {6, 7, 9}
        };

        lu(A, L, U, P);

        std::cout << "A: \n" << A << std::endl;
        std::cout << "P: \n" << P << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "L: \n" << L << std::endl;
        std::cout << "U: \n" << U << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "LU: \n" << L * U << std::endl << std::endl;

        assert(P * A == L * U);
    }

    {
        Matrix A = {
            {11, 9, 24, 2},
            {1, 5, 2, 6},
            {3, 17, 18, 1},
            {2, 5, 7, 1}
        };

        lu(A, L, U, P);

        std::cout << "A: \n" << A << std::endl;
        std::cout << "P: \n" << P << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "L: \n" << L << std::endl;
        std::cout << "U: \n" << U << std::endl;
        std::cout << "PA: \n" << P * A << std::endl;
        std::cout << "LU: \n" << L * U << std::endl << std::endl;

        assert(P * A == L * U);
    }
}
