/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/enumerate_view
 */

#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./enumerate_view.hpp"

/*
 * enumerate_view_test_1
 */

void enumerate_view_test_1() {
  std::vector<char> vec{'a', 'b', 'c'};
  enumerate_view e(vec);

  const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
  const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};

  assert(actual == expected);
}

/*
 * enumerate_view_test_2
 */

void enumerate_view_test_2() {
  std::vector<char> vec{'a'};

  for(auto [idx, value] : enumerate_view(vec)) {
    Assert(idx == 0);
    Assert(value == 'a');
  }
}

/*
 * main
 */

int main() {
  enumerate_view_test_1();
  enumerate_view_test_2();
}
