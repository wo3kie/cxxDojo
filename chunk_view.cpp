/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
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
#include "./chunk_view.hpp"
#include "./output.hpp"

/*
 * test_chunk_basic
 */

void test_chunk_basic()
{
  auto seq = std::views::iota(0, 16);

  {
    chunk_view z{seq, 1};
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : z) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }

  {
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : chunk_view{seq, 3}) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }

  {
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : chunk_view{std::views::iota(0, 16), 4}) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }

  {
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : std::views::iota(0, 16) | chunk(15)) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }

  {
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : chunk(std::views::iota(0, 16), 16)) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }

  {
    std::vector<int> actual;
    const std::vector<int> expected(seq.begin(), seq.end());

    for(const auto& [from, to] : std::views::iota(0, 16) | chunk(17)) {
      actual.insert(actual.end(), from, to);
    }

    Assert(actual == expected);
  }
}

/*
 * main
 */

int main()
{
  test_chunk_basic();
}
