#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

inline constexpr unsigned gcd(unsigned a, unsigned b) {
  return b == 0 ? a : gcd(b, a % b);
}

template<unsigned A, unsigned B>
struct GCD {
  enum { value = GCD<B, A % B>::value };
};

template<unsigned A>
struct GCD<A, 0> {
  enum { value = A };
};
