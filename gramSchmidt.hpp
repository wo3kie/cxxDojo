/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_GRAM_SCHMIDT_HPP
#define CXX_DOJO_GRAM_SCHMIDT_HPP

#include "./matrix.hpp"

/*
 * https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process
 */

/*
 * matrix : row vectors matrix
 */

Matrix gramSchmidt_row(Matrix matrix, bool normalize = true) {
  Matrix result(matrix.rows(), matrix.columns());

  result[0] = matrix[0];

  for(unsigned i = 1; i < matrix.rows(); ++i) {
    result[i] = matrix[i];

    for(unsigned j = 0; j < i; ++j) {
      result[i] = result[i] - projection(matrix[i], result[j]);
    }
  }

  if(normalize) {
    for(unsigned i = 0; i < result.rows(); ++i) {
      result[i] = unit(result[i]);
    }
  }

  return result;
}

/*
 * matrix : column vectors matrix
 */

Matrix gramSchmidt_column(Matrix matrix, bool normalize = true) {
  matrix = transpose(matrix);

  Matrix result = gramSchmidt_row(matrix, normalize);

  return transpose(result);
}

/*
 * matrix : column vectors matrix
 */

Matrix gramSchmidt(Matrix matrix, bool normalize = true) {
  return gramSchmidt_column(matrix, normalize);
}

#endif
