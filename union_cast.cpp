/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/union_cast
 */

#include <cassert>

#include "./union_cast.hpp"

/*
 * S1
 */

struct S1 {
  int _i;
};

/*
 * S2
 */

struct S2 {
  float _f;
};

/*
 * main
 */

int main() {
  {
    S1 s1{123};
    assert(union_cast<S1>(union_cast<S2>(s1))._i == 123);
  }

  {
    S1 const s1{123};
    assert(union_cast<S1>(union_cast<S2>(s1))._i == 123);
  }

  { assert(union_cast<S1>(union_cast<S2>(S1{123}))._i == 123); }
}
