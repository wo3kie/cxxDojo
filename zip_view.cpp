/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/concat_view
 */

/*
 * test
 */

#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <tuple>
#include <vector>

#include "./assert.hpp"
#include "./zip_view.hpp"

#include "./output.hpp"

/*
 * zip_view_test_1
 */

void zip_view_test_1() {
  std::list<int> lst = {1, 2, 3};
  std::deque<int> deq = {4, 5, 6};
  std::vector<int> vec = {7, 8, 9};
  zip_view zip{lst, deq, vec};

  const std::vector<std::tuple<int, int, int>> actual(zip.begin(), zip.end());
  const std::vector<std::tuple<int, int, int>> expected({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
  Assert(actual == expected);
}

/*
 * zip_view_test_2
 */

void zip_view_test_2() {
  std::list<int> lst = {1, 2, 3};
  std::deque<int> deq = {4, 5, 6};
  const std::vector<int> vec = {7, 8, 9};
  zip_view zip{lst, deq, vec};

  const std::vector<std::tuple<int, int, int>> actual(zip.begin(), zip.end());
  const std::vector<std::tuple<int, int, int>> expected({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
  Assert(actual == expected);
}

/*
 * main
 */

int main() {
  zip_view_test_1();
  zip_view_test_2();
}
