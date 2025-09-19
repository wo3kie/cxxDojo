#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#pragma once

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
