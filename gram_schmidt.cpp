/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 gram_schmidt.cpp -o gram_schmidt
 *
 * Usage:
 *      $ ./gram_schmidt
 */

#include <cassert>

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

  assert((dot(transpose(orthonormal), orthonormal) == eye(matrix.rows())));
}
