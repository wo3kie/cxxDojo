#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cmath>
#include <iostream>

/*
 * feq
 */

inline constexpr bool feq(const float lhs, const float rhs, const float eps = 0.0001f) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

/*
 * feq
 */

inline constexpr bool feq(const double lhs, const double rhs, const double eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

/*
 * feq
 */

inline constexpr bool feq(const long double lhs, const long double rhs, const long double eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

/*
 * approx
 */

template<typename T = double>
struct approx {
public:
  explicit approx(T d, T eps = T(0.0001))
      : _d(d)
      , _eps(eps) {
  }

  T get() const {
    return _d;
  }

  T operator*() const {
    return _d;
  }

  T eps() const {
    return _eps;
  }

  bool operator==(T d) const {
    return std::fabs(_d - d) <= _eps;
  }

  bool operator!=(T d) const {
    return ! operator==(d);
  }

private:
  T _d;
  T _eps;
};

/*
 * operator==
 */

template<typename T>
bool operator==(double d, approx<T> approx) {
  return approx.operator==(d);
}

/*
 * operator!=
 */

template<typename T>
bool operator!=(double d, approx<T> approx) {
  return approx.operator!=(d);
}

/*
 * operator<<
 */

template<typename T>
std::ostream& operator<<(std::ostream& out, approx<T> a) {
  return (out << *a);
}
