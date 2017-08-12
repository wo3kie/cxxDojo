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

void lu(Matrix const & A, Matrix & L, Matrix & U){
    /*
     *      major column
     *       |
     *       v
     * [ .   . . .       ]
     * [  .  . . .       ]
     * [   . . . .       ]
     * [ ... a b c ... x ] <- major row
     * [ ... d e f ... y ]  <- minor row
     * [     . . . .     ]  <- minor row
     * [     . . .  .    ]  <- minor row
     * [     . . .   .   ]  <- minor row
     * [     g h i ... z ]  <- minor row
     *
     *       ^ ^ ^     ^
     *       | | | ... |
     *      minor column
     */

    unsigned const size = A.rows();

    L = Matrix(size, size);
    U = A;

    for(unsigned majorColumn = 0; majorColumn < size; ++majorColumn){
        unsigned const majorRow = majorColumn;

        if(U[majorColumn][majorColumn] == 0){
            throw std::runtime_error("0 has been found on the main diagnonal, please use LUP algorithm instead");
        }

        L[majorColumn][majorColumn] = 1;

        for(unsigned minorRow = majorColumn + 1; minorRow < size; ++minorRow){
            double const coeff = U[minorRow][majorColumn] / U[majorRow][majorRow];

            for(unsigned minorColumn = majorColumn; minorColumn < size; ++minorColumn){
                U[minorRow][minorColumn] -= coeff * U[majorRow][minorColumn];
            }

            L[minorRow][majorColumn] = coeff;
        }
    }
}

void lup(Matrix const & A, Matrix & L, Matrix & U, Matrix & P){
    unsigned const size = A.rows();

    L = Matrix(size, size);
    U = A;

    for(unsigned majorColumn = 0; majorColumn < size; ++majorColumn){
        unsigned const majorRow = majorColumn;

        { // partial pivoting
            unsigned maxRowId = majorRow;

            for(unsigned row = majorRow + 1; row < size; ++row){
                if(abs(U[maxRowId][majorColumn]) < abs(U[row][majorColumn])){
                    maxRowId = row;
                }
            }

            if(maxRowId != majorRow){
                std::swap(L[maxRowId], L[majorRow]);
                std::swap(U[maxRowId], U[majorRow]);
                std::swap(P[maxRowId], P[majorRow]);
            }
        }

        if(U[majorColumn][majorColumn] == 0){
            throw std::runtime_error("0 has been found on the main diagnonal");
        }

        L[majorColumn][majorColumn] = 1;

        for(unsigned minorRow = majorColumn + 1; minorRow < size; ++minorRow){
            double const coeff = U[minorRow][majorColumn] / U[majorRow][majorRow];

            for(unsigned minorColumn = majorColumn; minorColumn < size; ++minorColumn){
                U[minorRow][minorColumn] -= coeff * U[majorRow][minorColumn];
            }

            L[minorRow][majorColumn] = coeff;
        }
    }
}

int main(){
    Matrix L;
    Matrix U;

    {
        Matrix A = {
            {1, 2, 3},
            {4, 5, 6},
            {3,-3, 5}
        };

        lu(A, L, U);

        std::cout << "A: \n" << A << "\n\n";
        std::cout << "L: \n" << L << "\n\n";
        std::cout << "U: \n" << U << "\n\n";

        assert(L * U == A);
    }

    {
        do{
            Matrix A = {
                {1, 2, 3},
                {4, 8, 7},  // {4, 8, 7} + (-4) * {1, 2, 3} == {0, 0, 1}
                {3,-3, 5}
            };

            try{
                lu(A, L, U);
            }
            catch(std::runtime_error const &){
                break;
            }

            assert(false);
        }
        while(false);
    }

    {
        do{
            Matrix A = {
                {1, 2, 3},
                {4, 8, 7},  // {4, 8, 7} + (-4) * {1, 2, 3} == {0, 0, 1}
                {3,-3, 5}
            };

            Matrix P = eye(3);

            lup(A, L, U, P);

            std::cout << "A: \n" << A << "\n\n";
            std::cout << "L: \n" << L << "\n\n";
            std::cout << "U: \n" << U << "\n\n";
            std::cout << "P: \n" << P << "\n\n";
            std::cout << "PA: \n" << P*A << "\n\n";
            std::cout << "LU: \n" << L*U << "\n\n";

            assert(P * A == L * U);
        }
        while(false);
    }

    {
        do{
            Matrix A = {
                {2, 1, 5},
                {4, 4, -4},
                {1, 3, 1}
            };

            Matrix P = eye(3);

            lup(A, L, U, P);

            std::cout << "A: \n" << A << "\n\n";
            std::cout << "L: \n" << L << "\n\n";
            std::cout << "U: \n" << U << "\n\n";
            std::cout << "P: \n" << P << "\n\n";
            std::cout << "PA: \n" << P*A << "\n\n";
            std::cout << "LU: \n" << L*U << "\n\n";

            assert(P * A == L * U);
        }
        while(false);
    }
    return 0;
}

