#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cmath>
#include <iostream>

/*
 * feq
 */

template<typename T>
inline constexpr bool feq(T lhs, T rhs, T atol = T(0.0001)) {
    static_assert(std::is_floating_point_v<T>);
    return std::fabs(lhs - rhs) < atol;
}

/*
 * approx
 */

template<typename T = double>
struct approx {
  static_assert(std::is_arithmetic_v<T>);

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
    const bool result = std::abs(_d - d) <= _atol;
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
std::ostream& operator<<(std::ostream& out, const approx<T>& a) {
  return (out << *a);
}
