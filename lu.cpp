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
#include "./output.hpp"

typedef std::vector<double> Vector;
typedef std::vector<Vector> Matrix;

Matrix makeMatrix(unsigned numRows, unsigned numColumns){
    return Matrix(numRows, Vector(numColumns, 0));
}

bool matrixEq(Matrix const & m1, Matrix const & m2){
    unsigned const rows1 = m1.size();
    unsigned const rows2 = m2.size();

    if(rows1 != rows2){
        return false;
    }

    for(unsigned row = 0; row < rows1; ++row){
        unsigned const columns1 = m1[row].size();
        unsigned const columns2 = m2[row].size();

        if(columns1 != columns2){
            return false;
        }

        for(unsigned column = 0; column < columns1; ++column){
            if(!feq(m1[row][column], m2[row][column])){
                return false;
            }
        }
    }

    return true;
}

Matrix matrixMul(Matrix const & m1, Matrix const & m2){
    Matrix result = makeMatrix(m1.size(), m2[0].size());

    for(unsigned i = 0; i < m1.size(); ++i){
        for(unsigned j = 0; j < m2[0].size(); ++j){
            for(unsigned k = 0; k < m2.size(); ++k){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}

Matrix pivotaize(Matrix const & m){
    unsigned const size = m.size();

    Matrix result = makeMatrix(size, size);

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
    unsigned const size = A.size();

    L = makeMatrix(size, size);
    U = makeMatrix(size, size);
    P = pivotaize(A);

    Matrix const A2 = matrixMul(P, A);

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

        std::cout << "A: " << A << std::endl;
        std::cout << "P: " << P << std::endl;
        std::cout << "PA: " << matrixMul(P, A) << std::endl;
        std::cout << "L: " << L << std::endl;
        std::cout << "U: " << U << std::endl;
        std::cout << "PA: " << matrixMul(P, A) << std::endl;
        std::cout << "LU: " << matrixMul(L, U) << std::endl << std::endl;

        assert(
            matrixEq(
                matrixMul(P, A),
                matrixMul(L, U)
            )
        );
    }

    {
        Matrix A = {
            {1, 3, 5},
            {2, 4, 7},
            {1, 1, 0}
        };

        lu(A, L, U, P);

        std::cout << "A: " << A << std::endl;
        std::cout << "P: " << P << std::endl;
        std::cout << "L: " << L << std::endl;
        std::cout << "U: " << U << std::endl;
        std::cout << "PA: " << matrixMul(P, A) << std::endl;
        std::cout << "LU: " << matrixMul(L, U) << std::endl << std::endl;

        assert(
            matrixEq(
                matrixMul(P, A),
                matrixMul(L, U)
            )
        );
    }

    {
        Matrix A = {
            {8, 2, 9},
            {4, 9, 4},
            {6, 7, 9}
        };

        lu(A, L, U, P);

        std::cout << "A: " << A << std::endl;
        std::cout << "P: " << P << std::endl;
        std::cout << "L: " << L << std::endl;
        std::cout << "U: " << U << std::endl;
        std::cout << "PA: " << matrixMul(P, A) << std::endl;
        std::cout << "LU: " << matrixMul(L, U) << std::endl << std::endl;

        assert(
            matrixEq(
                matrixMul(P, A),
                matrixMul(L, U)
            )
        );
    }

    {
        Matrix A = {
            {11, 9, 24, 2},
            {1, 5, 2, 6},
            {3, 17, 18, 1},
            {2, 5, 7, 1}
        };

        lu(A, L, U, P);

        std::cout << "A: " << A << std::endl;
        std::cout << "P: " << P << std::endl;
        std::cout << "L: " << L << std::endl;
        std::cout << "U: " << U << std::endl;
        std::cout << "PA: " << matrixMul(P, A) << std::endl;
        std::cout << "LU: " << matrixMul(L, U) << std::endl << std::endl;

        assert(
            matrixEq(
                matrixMul(P, A),
                matrixMul(L, U)
            )
        );
    }
}
