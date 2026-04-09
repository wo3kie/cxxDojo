/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/member_offset
 */

#include <iostream>

#include "./assert.hpp"
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
  Assert(getMemberOffset(&S::i) == 0LL);
  Assert(getMemberOffset(&S::f) == 4LL);
  Assert(getMemberOffset(&S::c) == 8LL);
}
