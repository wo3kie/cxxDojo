/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 gram_schmidt.cpp -o gram_schmidt
 *
 * Usage:
 *      $ ./gram_schmidt
 */

#include <cassert>

#include "./gramSchmidt.hpp"

int main(){
    {
        Matrix matrix(2, 2);

        matrix[0][0] = 2;
        matrix[0][1] = 1;
        matrix[1][0] = 1;
        matrix[1][1] = 1;

        Matrix const orthonormal = gramSchmidt(matrix);

        assert((dot(transpose(orthonormal), orthonormal) == eye(matrix.rows())));
    }
}

