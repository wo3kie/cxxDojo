#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include "./matrix.hpp"

/*
 * matrix : row vectors matrix
 */

inline Matrix gramSchmidt_row(Matrix matrix, bool normalize = true) {
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

inline Matrix gramSchmidt_column(Matrix matrix, bool normalize = true) {
  matrix = transpose(matrix);

  Matrix result = gramSchmidt_row(matrix, normalize);

  return transpose(result);
}

/*
 * matrix : column vectors matrix
 */

inline Matrix gramSchmidt(Matrix matrix, bool normalize = true) {
  return gramSchmidt_column(matrix, normalize);
}
