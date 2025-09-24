/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/enumerate
 */

#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./enumerate.hpp"

/*
 * enumrate_view_test
 */

void enumerate_view_test() {
  std::vector<char> vec{'a', 'b', 'c'};
  enumerate_view e(vec);

  const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
  const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};

  assert(actual == expected);
}

/*
 * enumerate_test
 */

void enumerate_test() {
  std::vector<char> vec{'a'};

  for(auto [idx, value] : enumerate(vec)) {
    Assert(idx == 0);
    Assert(value == 'a');
  }
}

/*
 * main
 */

int main() {
  enumerate_view_test();

  return 0;
}