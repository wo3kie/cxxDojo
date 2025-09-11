/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 apply.cpp -o apply
 *
 * Usage:
 *      $ ./apply
 */

#include "apply.hpp"

#include <cassert>

/*
 * test
 */

double add(int i, float f, double d) {
  return i + f + d;
}

const auto add2 = [](int i, float f, double d) -> double { //
  return i + f + d;
};

int main() {
  assert(apply(add, std::make_tuple(1, 2.f, 3.0)) == 1 + 2.f + 3.0);
  assert(apply(add2, std::make_tuple(1, 2.f, 3.0)) == 1 + 2.f + 3.0);
}
