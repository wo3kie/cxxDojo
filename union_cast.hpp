/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_UNION_CAST_HPP
#define CXX_DOJO_UNION_CAST_HPP

template<typename ToType, typename FromType>
ToType union_cast(FromType const& fromValue) {
  static_assert(sizeof(ToType) == sizeof(FromType), "union_cast");

  union {
    ToType toValue_;
    FromType fromValue_;
  } union_;

  union_.fromValue_ = fromValue;
  return union_.toValue_;
}

#endif
