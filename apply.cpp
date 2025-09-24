/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/apply
 */

#include "./apply.hpp"
#include "./assert.hpp"

/*
 * test
 */

double add(int i, float f, double d) {
  return i + f + d;
}

const auto add2 = [](int i, float f, double d) -> double { //
  return i + f + d;
};

/*
 * main
 */

int main() {
  Assert(apply(add, std::make_tuple(1, 2.f, 3.0)) == 1 + 2.f + 3.0);
  Assert(apply(add2, std::make_tuple(1, 2.f, 3.0)) == 1 + 2.f + 3.0);
}
