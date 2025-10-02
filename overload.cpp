/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/overload
 */

#include "./assert.hpp"
#include "./overload.hpp"
#include "./feq.hpp"

/*
 * overload_test
 */

void overload_test() {
  auto fs = Overload{
      [](int i) -> int { return i * i; },
      [](char c) -> char { return c; },
      [](double d) -> double { return 100 * d; }};

  Assert(fs('a') == 'a');
  Assert(fs(10) == 100);
  Assert(fs(1.1) == approx(110));
}

/*
 * main
 */

int main() {
  overload_test();
}
