/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 fold.cpp -o fold
 *
 * Usage:
 *      $ ./fold
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "./functional.hpp"

void fold_test() {
  std::vector<int> v{1, 2, 3, 4, 5};

  assert((1 + 2 + 3 + 4 + 5 == dojo::sum(v)));
  assert((1 * 2 * 3 * 4 * 5 == dojo::product(v)));
  assert((1 == dojo::min(v)));
  assert((5 == dojo::max(v)));
}

#include "./output.hpp"

void filter_test() {
  std::vector<int> v{1, 2, 3, 4, 5};

  std::vector<int> actual = dojo::filter(v, [](int i) {
    return i % 2 == 0;
  });
  std::vector<int> expected = {4, 2}; // or {2, 4}

  assert((std::equal(actual.begin(), actual.end(), expected.begin())));
}

void filter_test_copy() {
  const std::vector<int> v{1, 2, 3, 4, 5};

  std::vector<int> actual = dojo::filter_copy(v, [](int i) {
    return i % 2 == 0;
  });
  std::vector<int> expected = {2, 4};

  assert((std::equal(actual.begin(), actual.end(), expected.begin())));
}

void map_test() {
  const std::vector<int> v{1, 2, 3, 4, 5};

  std::string (*function)(int) = std::to_string;
  std::function<std::string(int)> functor = function;
  std::vector<std::string> actual = dojo::map(v, functor);
  std::vector<std::string> expected{"1", "2", "3", "4", "5"};

  assert((std::equal(actual.begin(), actual.end(), expected.begin())));
}

int main() {
  fold_test();
  filter_test();
  filter_test_copy();
  map_test();
}
