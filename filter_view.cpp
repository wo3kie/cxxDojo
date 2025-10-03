/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/filter_view
 */

#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./filter_view.hpp"

/*
 * filter_view_test_1
 */

void filter_view_test_1() {
  const auto isOdd = [](const int& i) -> bool { return i % 2 == 1; };
  
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  filter_view f(vec, isOdd);

  const std::vector<int> actual{f.begin(), f.end()};
  const std::vector<int> expected{1, 3, 5, 7, 9};

  Assert(actual == expected);
}

/*
 * filter_view_test_2
 */

void filter_view_test_2() {
  const auto isEven = [](const int& i) -> bool { return i % 2 == 0; };
  
  const std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  filter_view f(vec, isEven);

  const std::vector<int> actual{f.begin(), f.end()};
  const std::vector<int> expected{2, 4, 6, 8, 10};

  Assert(actual == expected);
}

/*
 * main
 */

int main() {
  filter_view_test_1();
  filter_view_test_2();
}
