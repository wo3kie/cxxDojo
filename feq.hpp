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

inline constexpr bool feq(const float lhs, const float rhs, const float atol = 0.0001f) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < atol;
}

/*
 * feq
 */

inline constexpr bool feq(const double lhs, const double rhs, const double atol = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < atol;
}

/*
 * feq
 */

inline constexpr bool feq(const long double lhs, const long double rhs, const long double atol = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < atol;
}

/*
 * approx
 */

template<typename T = double>
struct approx {
public:
  explicit approx(T d, T atol = T(0.0001))
      : _d(d)
      , _atol(atol) {
  }

  T get() const {
    return _d;
  }

  T operator*() const {
    return _d;
  }

  T atol() const {
    return _atol;
  }

  bool operator==(T d) const {
    bool result;
    
    if constexpr (std::is_floating_point_v<T>) {
      result = std::fabs(_d - d) <= _atol;
    } else if constexpr (std::is_integral_v<T>) {
      result = std::abs(_d - d) <= _atol;
    } else {
      static_assert(false, "T must be a floating point or integral type");
    }
    
    return result;
  }

  bool operator!=(T d) const {
    return ! operator==(d);
  }

private:
  T _d;
  T _atol;
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
