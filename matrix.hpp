#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#pragma once

#include <iomanip>
#include <vector>

#include "./feq.hpp"
#include "./float_formatter.hpp"
#include "./output.hpp"

/*
 * Vector
 */

class Vector {
public:
  Vector() = default;
  Vector(const Vector&) = default;
  Vector(Vector&&) = default;

  Vector& operator=(const Vector&) = default;
  Vector& operator=(Vector&&) = default;

  Vector(unsigned size, double init = 0.0)
      : _data(size, init) {
  }

  Vector(const std::initializer_list<double>& data)
      : _data(data) {
  }

  double& operator[](unsigned i) {
    return _data.at(i);
  }

  const double& operator[](unsigned i) const {
    return _data.at(i);
  }

  unsigned size() const {
    return _data.size();
  }

private:
  std::vector<double> _data;
};

inline std::ostream& operator<<(std::ostream& out, const Vector& vector) {
  out << "[";

  if(vector.size() != 0) {
    out << FloatFormatter(vector[0], 8);

    for(unsigned i = 1; i < vector.size(); ++i) {
      out << ' ' << FloatFormatter(vector[i], 8);
    }
  }

  out << "]";

  return out;
}

inline Vector operator+(const Vector& vector1, const Vector& vector2) {
  Vector result(vector1.size());

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result[i] = vector1[i] + vector2[i];
  }

  return result;
}

inline Vector operator-(const Vector& vector1, const Vector& vector2) {
  Vector result(vector1.size());

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result[i] = vector1[i] - vector2[i];
  }

  return result;
}

inline Vector operator*(double scalar, const Vector& vector) {
  Vector result(vector.size());

  for(unsigned i = 0; i < vector.size(); ++i) {
    result[i] = scalar * vector[i];
  }

  return result;
}

inline double dot(const Vector& vector1, const Vector vector2) {
  double result = 0;

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result += vector1[i] * vector2[i];
  }

  return result;
}

inline double norm2(const Vector& vector) {
  return sqrt(dot(vector, vector));
}

inline Vector unit(Vector vector) {
  const double norm = norm2(vector);

  if(norm == 0 || norm == 1) {
    return vector;
  }

  for(unsigned i = 0; i < vector.size(); ++i) {
    vector[i] /= norm;
  }

  return vector;
}

inline Vector projection(const Vector& what, const Vector& where) {
  return dot(where, what) / dot(where, where) * where;
}


/*
 * Matrix
 */

class Matrix {
public:
  Matrix() = default;
  Matrix(const Matrix&) = default;
  Matrix(Matrix&&) = default;

  Matrix& operator=(const Matrix&) = default;
  Matrix& operator=(Matrix&&) = default;

  Matrix(unsigned rows, unsigned columns, double init = 0.0)
      : _matrix(rows, Vector(columns, init)) {
  }

  Matrix(const std::initializer_list<std::initializer_list<double>>& data)
      : _matrix(data.begin(), data.end()) {
  }

  Vector& operator[](unsigned i) {
    return _matrix.at(i);
  }

  const Vector& operator[](unsigned i) const {
    return _matrix.at(i);
  }

  unsigned rows() const {
    return _matrix.size();
  }

  unsigned columns() const {
    if(rows() == 0) {
      return 0;
    }

    return _matrix[0].size();
  }

private:
  std::vector<Vector> _matrix;
};

/*
 * operator<<
 */

inline std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
  out << "[";

  if(matrix.rows() != 0) {
    out << matrix[0];

    for(unsigned i = 1; i < matrix.rows(); ++i) {
      out << "\n ";
      out << matrix[i];
    }
  }

  out << "]";

  return out;
}

/*
 * operator==
 */

inline bool operator==(const Matrix& matrix1, const Matrix& matrix2) {
  const unsigned rows1 = matrix1.rows();
  const unsigned rows2 = matrix2.rows();

  if(rows1 != rows2) {
    return false;
  }

  for(unsigned row = 0; row < rows1; ++row) {
    const unsigned columns1 = matrix1[row].size();
    const unsigned columns2 = matrix2[row].size();

    if(columns1 != columns2) {
      return false;
    }

    for(unsigned column = 0; column < columns1; ++column) {
      if(! matrix1[row][column] == approx(matrix2[row][column])) {
        return false;
      }
    }
  }

  return true;
}

/*
 * operator!=
 */

inline bool operator!=(const Matrix& matrix1, const Matrix& matrix2) {
  return ! (matrix1 == matrix2);
}

/*
 * operator+
 */

inline Matrix operator+(const Matrix& matrix1, double d) {
  Matrix result = Matrix(matrix1.rows(), matrix1.columns());

  for(unsigned i = 0; i < matrix1.rows(); ++i) {
    for(unsigned j = 0; j < matrix1[0].size(); ++j) {
      result[i][j] = matrix1[i][j] + d;
    }
  }

  return result;
}

/*
 * operator+
 */

inline Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
  Matrix result = Matrix(matrix1.rows(), matrix1.columns());

  for(unsigned i = 0; i < matrix1.rows(); ++i) {
    for(unsigned j = 0; j < matrix1.columns(); ++j) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  return result;
}

/*
 * operator*
 */

inline Matrix operator*(const Matrix& matrix1, double d) {
  Matrix result = Matrix(matrix1.rows(), matrix1.columns());

  for(unsigned i = 0; i < matrix1.rows(); ++i) {
    for(unsigned j = 0; j < matrix1[0].size(); ++j) {
      result[i][j] = matrix1[i][j] * d;
    }
  }

  return result;
}

/*
 * operator*
 */

inline Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
  Matrix result = Matrix(matrix1.rows(), matrix1.columns());

  for(unsigned i = 0; i < matrix1.rows(); ++i) {
    for(unsigned j = 0; j < matrix2.columns(); ++j) {
      for(unsigned k = 0; k < matrix2.rows(); ++k) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

/*
 * dot
 */

inline Matrix dot(const Matrix& matrix1, const Matrix& matrix2) {
  return matrix1 * matrix2;
}

/*
 * transpose
 */

inline Matrix transpose(const Matrix& matrix) {
  Matrix result = Matrix(matrix.rows(), matrix.columns());

  for(unsigned i = 0; i < matrix.rows(); ++i) {
    for(unsigned j = 0; j < matrix.columns(); ++j) {
      result[i][j] = matrix[j][i];
    }
  }

  return result;
}

/*
 * eye
 */

inline Matrix eye(unsigned size) {
  Matrix result(size, size, 0);

  for(unsigned i = 0; i < size; ++i) {
    result[i][i] = 1;
  }

  return result;
}

/*
 * operator-
 */

inline Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
  return matrix1 + (matrix2 * -1);
}
