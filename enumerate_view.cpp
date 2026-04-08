/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)

 */

#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./enumerate_view.hpp"

void test_basic()
{
  std::vector<char> vec{'a', 'b', 'c'};

  {
    enumerate_view e(vec);
    const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
    const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};
    assert(actual == expected);
    static_assert(std::is_same_v<decltype(e), enumerate_view<std::ranges::ref_view<std::vector<char>>>>);
  }

  {
    enumerate_view e(std::vector<char>{'a', 'b', 'c'});
    const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
    const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};
    assert(actual == expected);
    static_assert(std::is_same_v<decltype(e), enumerate_view<std::ranges::owning_view<std::vector<char>>>>);
  }

  {
    auto e = enumerate_view(vec);
    const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
    const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};
    assert(actual == expected);
  }

  {
    auto e = vec | enumerate();
    const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
    const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};
    assert(actual == expected);
  }

  {
    auto e = enumerate(vec);
    const std::vector<std::tuple<size_t, char>> actual{e.begin(), e.end()};
    const std::vector<std::tuple<size_t, char>> expected{{0, 'a'}, {1, 'b'}, {2, 'c'}};
    assert(actual == expected);
  }
}

int main()
{
  test_basic();
}
