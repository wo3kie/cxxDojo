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

#include "./matrix.hpp"

/*
 * https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process
 */

Matrix gramSchmidt(Matrix const & matrix, bool normalize = true){
    Matrix result(matrix.rows(), matrix.columns());

    result[0] = matrix[0];

    for(unsigned i = 1; i < matrix.rows(); ++i){
        result[i] = matrix[i];

        for(unsigned j = 0; j < i; ++j){
            result[i] = result[i] - projection(matrix[i], result[j]);
        }
    }

    if(normalize){
        for(unsigned i = 0; i < result.rows(); ++i){
            result[i] = unit(result[i]);
        }
    }

    return result;
}

#include <cassert>

int main(){
    {
        Matrix matrix(2, 2);

        matrix[0][0] = 2;
        matrix[0][1] = 1;
        matrix[1][0] = 1;
        matrix[1][1] = 1;

        Matrix const orthonormal = gramSchmidt(matrix);

        assert((dot(orthonormal, transpose(orthonormal)) == eye(matrix.rows())));
    }
}

