/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_MODEXP_HPP__
#define __CXX_DOJO_MODEXP_HPP__

namespace {

inline constexpr unsigned pow2(unsigned a) {
  return a * a;
}

} // namespace

inline constexpr unsigned modexp(unsigned a, unsigned exp, unsigned mod) {
  return exp == 0 ? 1

                  //: exp % 2 == 0
                  //	? (    pow2(modexp(a, exp/2, mod))) % mod
                  //	: (a * pow2(modexp(a, exp/2, mod))) % mod;

                  : ((exp % 2 == 0 ? 1 : a) * pow2(modexp(a, exp / 2, mod)) % mod);
}

#endif
