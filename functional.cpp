/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/functional
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "./functional.hpp"

/*
 * fold_test
 */

void fold_test() {
  std::vector<int> v{1, 2, 3, 4, 5};

  assert((1 + 2 + 3 + 4 + 5 == sum(v)));
  assert((1 * 2 * 3 * 4 * 5 == product(v)));
  assert((1 == min(v)));
  assert((5 == max(v)));
}

/*
 * filter_test
 */

void filter_test() {
  std::vector<int> v{1, 2, 3, 4, 5};

  std::vector<int> actual = filter(v, [](int i) {
    return i % 2 == 0;
  });

  std::vector<int> expected = {4, 2}; // or {2, 4}

  assert((std::equal(actual.begin(), actual.end(), expected.begin())));
}

/*
 * filter_test_copy
 */

void filter_test_copy() {
  const std::vector<int> v{1, 2, 3, 4, 5};

  std::vector<int> actual = filter_copy(v, [](int i) {
    return i % 2 == 0;
  });

  std::vector<int> expected = {2, 4};

  assert((std::equal(actual.begin(), actual.end(), expected.begin())));
}

/*
 * main
 */

int main() {
  fold_test();
  filter_test();
  filter_test_copy();
}
