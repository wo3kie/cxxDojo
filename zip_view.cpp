/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
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

void test_zip_basic()
{
  std::list<int> lst = {1, 2, 3};
  std::deque<int> deq = {4, 5, 6};
  std::vector<int> vec = {7, 8, 9};
  zip_view zip{lst, deq, vec};

  {
    zip_view z{lst, deq, vec};
    const std::vector<std::tuple<int, int, int>> actual{z.begin(), z.end()};
    const std::vector<std::tuple<int, int, int>> expected({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    Assert(actual == expected);
  }

  {
    zip_view z(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}, std::vector<int>{7, 8, 9});
    const std::vector<std::tuple<int, int, int>> actual{z.begin(), z.end()};
    const std::vector<std::tuple<int, int, int>> expected({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    Assert(actual == expected);
  }

  {
    auto z = zip_view(lst, deq, vec);
    const std::vector<std::tuple<int, int, int>> actual{z.begin(), z.end()};
    const std::vector<std::tuple<int, int, int>> expected({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    Assert(actual == expected);
  }
}

/*
 * main
 */

int main()
{
  test_zip_basic();
}
