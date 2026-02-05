/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Inspiration:
 *      Based on Type List written by Andrei Alexandrescu
 * 
 */

#include <iostream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class StaticInterface {
  StaticInterface();
  ~StaticInterface();
};

struct emptyValue: StaticInterface {
  enum { value = 65535 };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<int _head, typename _Tail>
struct ValueList: StaticInterface {

  typedef int Head;
  typedef _Tail Tail;

  enum { value = _head };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<int Int, int... Ints>
struct List_ {
  typedef ValueList<Int, typename List_<Ints...>::type> type;
};

template<int Int>
struct List_<Int> {
  typedef ValueList<Int, emptyValue> type;
};

template<int Int, int... Ints>
using List = typename List_<Int, Ints...>::type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<typename _VList, int _index>
struct ValueAt;

template<int _head, typename _Tail>
struct ValueAt<ValueList<_head, _Tail>, 0>: StaticInterface {
  enum { value = _head };
};

template<int _head, typename _Tail, int _index>
struct ValueAt<ValueList<_head, _Tail>, _index>: StaticInterface {
  enum { value = ValueAt<_Tail, _index - 1>::value };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<typename _VList, int _value, int _replaceWith>
struct Replace;

template<int _value, int _replaceWith>
struct Replace<emptyValue, _value, _replaceWith>: StaticInterface {
  typedef emptyValue ResultType;
};

template<int _head, typename _Tail, int _replaceWith>
struct Replace<ValueList<_head, _Tail>, _head, _replaceWith>: StaticInterface {
  enum { value = ValueList<_replaceWith, _Tail>::value };
  typedef ValueList<_replaceWith, _Tail> ResultType;
};

template<int _head, typename _Tail, int _value, int _replaceWith>
struct Replace<ValueList<_head, _Tail>, _value, _replaceWith>: StaticInterface {
  enum { value = ValueList<_head, Replace<_Tail, _value, _replaceWith>>::value };
  typedef ValueList<_head, typename Replace<_Tail, _value, _replaceWith>::ResultType> ResultType;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// It is not a real predicate since returns greater values instead of `true' or `false'

template<int _i1, int _i2>
struct Greater: StaticInterface {
  enum { value = (_i1 == emptyValue::value) ? _i2 : (_i2 == emptyValue::value) ? _i1 : (_i1 < _i2) ? _i2 : _i1 };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// It is not a real predicate since returns less values instead of `true' or `false'

template<int _i1, int _i2>
struct Less: StaticInterface {
  enum { value = (_i1 == emptyValue::value) ? _i2 : (_i2 == emptyValue::value) ? _i1 : (_i1 < _i2) ? _i1 : _i2 };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<typename _VList, template<int, int> class _Predicate>
struct Optimum;

template<template<int, int> class _Predicate>
struct Optimum<emptyValue, _Predicate>: StaticInterface {
  enum { value = emptyValue::value };
};

template<int _head, typename _Tail, template<int, int> class _Predicate>
struct Optimum<ValueList<_head, _Tail>, _Predicate>: StaticInterface {
  enum { value = _Predicate<_head, Optimum<_Tail, _Predicate>::value>::value };
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template<typename _VList, template<int, int> class _Predicate>
struct Sort_;

template<template<int, int> class _Predicate>
struct Sort_<emptyValue, _Predicate>: StaticInterface {
  enum { value = emptyValue::value };
  typedef emptyValue ResultType;
};

template<int _head, typename _Tail, template<int, int> class _Predicate>
struct Sort_<ValueList<_head, _Tail>, _Predicate>: StaticInterface {
  enum { value = _Predicate<_head, Optimum<_Tail, _Predicate>::value>::value };
  typedef typename Replace<_Tail, value, _head>::ResultType UnsortedTail;
  typedef ValueList<value, typename Sort_<UnsortedTail, _Predicate>::ResultType> ResultType;
};

template<typename _VList, template<int, int> class _Predicate>
using Sort = typename Sort_<_VList, _Predicate>::ResultType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main() {
  typedef Sort<List<1, 9, 2, 8, 3, 7, 4, 6, 5>, Greater> DiscendingSortedArray;

  std::cout << ValueAt<DiscendingSortedArray, 0>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 1>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 2>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 3>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 4>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 5>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 6>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 7>::value << ' ' //
            << ValueAt<DiscendingSortedArray, 8>::value << std::endl;

  typedef Sort<List<1, 9, 2, 8, 3, 7, 4, 6, 5>, Less> AscendingSortedArray;

  std::cout << ValueAt<AscendingSortedArray, 0>::value << ' ' //
            << ValueAt<AscendingSortedArray, 1>::value << ' ' //
            << ValueAt<AscendingSortedArray, 2>::value << ' ' //
            << ValueAt<AscendingSortedArray, 3>::value << ' ' //
            << ValueAt<AscendingSortedArray, 4>::value << ' ' //
            << ValueAt<AscendingSortedArray, 5>::value << ' ' //
            << ValueAt<AscendingSortedArray, 6>::value << ' ' //
            << ValueAt<AscendingSortedArray, 7>::value << ' ' //
            << ValueAt<AscendingSortedArray, 8>::value << std::endl;
}
