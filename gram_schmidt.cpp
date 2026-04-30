/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./assert.hpp"
#include "./gram_schmidt.hpp"

/*
 * main
 */

int main() {
  Matrix matrix(2, 2);

  matrix[0][0] = 2;
  matrix[0][1] = 1;
  matrix[1][0] = 1;
  matrix[1][1] = 1;

  const Matrix orthonormal = gramSchmidt(matrix);

  Assert((dot(transpose(orthonormal), orthonormal) == eye(matrix.rows())));
}
