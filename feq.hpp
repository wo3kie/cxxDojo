#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

inline constexpr bool feq(float const lhs, float const rhs, float const eps = 0.0001f) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

inline constexpr bool feq(double const lhs, double const rhs, double const eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}

inline constexpr bool feq(long double const lhs, long double const rhs, long double const eps = 0.0001) {
  return ((lhs - rhs) >= 0 ? (lhs - rhs) : (rhs - lhs)) < eps;
}
