/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_GCD_HPP__
#define __CXX_DOJO_GCD_HPP__

inline constexpr unsigned gcd(unsigned a, unsigned b) {
  return b == 0 ? a : gcd(b, a % b);
}

template<unsigned A, unsigned B>
struct Gcd {
  enum { value = Gcd<B, A % B>::value };
};

template<unsigned A>
struct Gcd<A, 0> {
  enum { value = A };
};

#endif
