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
#include <map>
#include <tuple>
#include <vector>

#include "./assert.hpp"
#include "./output.hpp"
#include "./zip_view.hpp"

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
 * zip_view_test_3
 */

void zip_view_test_3() {
  std::list<int> lst1 = {1, 2, 3};
  std::list<int> lst2 = {4, 5, 6};
  zip_view zip{lst1, lst2};

  const std::vector<std::tuple<int, int>> actual(zip.begin(), zip.end());
  const std::vector<std::tuple<int, int>> expected({{1, 4}, {2, 5}, {3, 6}});
  Assert(actual == expected);
}

/*
 * zip_view_test_4
 */

void zip_view_test_4() {
  std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}};
  std::map<std::string, int> map2 = {{"c", 3}, {"d", 4}};
  zip_view zip{map1, map2};

  using value = std::pair<const std::string, int>;

  std::vector<std::tuple<value, value>> actual(zip.begin(), zip.end());
  const std::vector<std::tuple<value, value>> expected({{{"a", 1}, {"c", 3}}, {{"b", 2}, {"d", 4}}});
  Assert(actual == expected);
}

/*
 * main
 */

int main() {
  zip_view_test_1();
  zip_view_test_2();
  zip_view_test_3();
  zip_view_test_4();
}
