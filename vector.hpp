/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_VECTOR_HPP
#define CXX_DOJO_VECTOR_HPP

class Vector {
public:
  Vector() = default;
  Vector(Vector const&) = default;
  Vector(Vector&&) = default;

  Vector& operator=(Vector const&) = default;
  Vector& operator=(Vector&&) = default;

  Vector(unsigned size, double init = 0.0)
      : data_(size, init) {
  }

  Vector(std::initializer_list<double> const& data)
      : data_(data) {
  }

  double& operator[](unsigned i) {
    return data_.at(i);
  }

  double const& operator[](unsigned i) const {
    return data_.at(i);
  }

  unsigned size() const {
    return data_.size();
  }

private:
  std::vector<double> data_;
};

inline std::ostream& operator<<(std::ostream& out, Vector const& vector) {
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

inline Vector operator+(Vector const& vector1, Vector const& vector2) {
  Vector result(vector1.size());

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result[i] = vector1[i] + vector2[i];
  }

  return result;
}

inline Vector operator-(Vector const& vector1, Vector const& vector2) {
  Vector result(vector1.size());

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result[i] = vector1[i] - vector2[i];
  }

  return result;
}

inline Vector operator*(double scalar, Vector const& vector) {
  Vector result(vector.size());

  for(unsigned i = 0; i < vector.size(); ++i) {
    result[i] = scalar * vector[i];
  }

  return result;
}

inline double dot(Vector const& vector1, Vector const vector2) {
  double result = 0;

  for(unsigned i = 0; i < vector1.size(); ++i) {
    result += vector1[i] * vector2[i];
  }

  return result;
}

inline double norm2(Vector const& vector) {
  return sqrt(dot(vector, vector));
}

inline Vector unit(Vector vector) {
  double const norm = norm2(vector);

  if(norm == 0 || norm == 1) {
    return vector;
  }

  for(unsigned i = 0; i < vector.size(); ++i) {
    vector[i] /= norm;
  }

  return vector;
}

inline Vector projection(Vector const& what, Vector const& where) {
  return dot(where, what) / dot(where, where) * where;
}

#endif
