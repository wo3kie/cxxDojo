#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

 /*
  * union_cast
  */

template<typename ToType, typename FromType>
ToType union_cast(const FromType& fromValue) {
  static_assert(sizeof(ToType) == sizeof(FromType), "union_cast");

  union {
    ToType toValue_;
    FromType fromValue_;
  } union_;

  union_.fromValue_ = fromValue;
  return union_.toValue_;
}
