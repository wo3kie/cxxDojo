#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

inline constexpr bool feq(const float lhs, const float rhs, const float eps = 0.0001f) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

inline constexpr bool feq(const double lhs, const double rhs, const double eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

inline constexpr bool feq(const long double lhs, const long double rhs, const long double eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}
