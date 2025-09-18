/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 member_offset.cpp -o member_offset
 *
 * Usage:
 *      $ ./member_offset
 */

#include <cassert>
#include <iostream>

#include "./member_offset.hpp"

/*
 * struct S
 */
struct S {
  int i;
  float f;
  char c;
};

/*
 * main
 */

int main() {
  assert(getMemberOffset(&S::i) == 0LL);
  assert(getMemberOffset(&S::f) == 4LL);
  assert(getMemberOffset(&S::c) == 8LL);
}
