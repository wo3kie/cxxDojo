#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

 /*
  * union_cast
  */

template<typename ToType, typename FromType>
ToType union_cast(const FromType& fromValue) {
  static_assert(sizeof(ToType) == sizeof(FromType), "union_cast");

  union {
    ToType _toValue;
    FromType _fromValue;
  } _union;

  _union._fromValue = fromValue;
  return _union._toValue;
}
