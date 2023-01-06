/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 member_offset.cpp -o member_offset
 *
 * Usage:
 *      $ ./member_offset
 */

#include <cassert>
#include <iostream>

#include "./union_cast.hpp"

template<typename Type, typename Class>
long long getMemberOffset(Type(Class::*member)) {
  return union_cast<long long>(member);
}

struct S {
  int i;
  float f;
  char c;
};

int main() {
  assert(getMemberOffset(&S::i) == 0LL);
  assert(getMemberOffset(&S::f) == 4LL);
  assert(getMemberOffset(&S::c) == 8LL);
}
