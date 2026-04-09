/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <map>
#include <vector>

#include "./assert.hpp"
#include "./concat_view.hpp"

void test_basic_vector()
{
  std::vector<int> a{1, 2, 3};
  std::vector<int> b{4, 5, 6};

  {
    uniform_concat_view view1(a);
    const std::vector<int> actual1{view1.begin(), view1.end()};
    const std::vector<int> expected1{1, 2, 3};
    Assert(actual1 == expected1);

    uniform_concat_view view2(a, b);
    const std::vector<int> actual2{view2.begin(), view2.end()};
    const std::vector<int> expected2{1, 2, 3, 4, 5, 6};
    Assert(actual2 == expected2);
  }

  {
    uniform_concat_view view1(std::vector<int>{1, 2, 3});
    const std::vector<int> actual1{view1.begin(), view1.end()};
    const std::vector<int> expected1{1, 2, 3};
    Assert(actual1 == expected1);

    uniform_concat_view view2(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6});
    const std::vector<int> actual2{view2.begin(), view2.end()};
    const std::vector<int> expected2{1, 2, 3, 4, 5, 6};
    Assert(actual2 == expected2);
  }

  {
    auto view1 = uniform_concat(a);
    const std::vector<int> actual1{view1.begin(), view1.end()};
    const std::vector<int> expected1{1, 2, 3};
    Assert(actual1 == expected1);

    auto view2 = uniform_concat(a, b);
    const std::vector<int> actual2{view2.begin(), view2.end()};
    const std::vector<int> expected2{1, 2, 3, 4, 5, 6};
    Assert(actual2 == expected2);
  }
}

void test_basic_vectors()
{
  const std::vector<int> a{};
  const std::vector<int> b{1};
  const std::vector<int> c{};
  const std::vector<int> d{2, 3};
  const std::vector<int> e{};
  const std::vector<int> f{};
  const std::vector<int> g{4, 5};
  const std::vector<int> h{};

  auto view = uniform_concat(a, b, c, d, e, f, g, h);
  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 4, 5};
  Assert(actual == expected);
}

void test_basic_map()
{
  std::map<std::string, int> a{};
  std::map<std::string, int> b{{"c++", 3}};
  std::map<std::string, int> c{};
  std::map<std::string, int> d{{"haskell", 7}, {"python", 6}};
  std::map<std::string, int> e{};
  std::map<std::string, int> f{};

  auto view = uniform_concat(a, b, c, d, e, f);
  const std::vector<std::pair<std::string, int>> actual = {view.begin(), view.end()};
  const std::vector<std::pair<std::string, int>> expected{{"c++", 3}, {"haskell", 7}, {"python", 6}};
  Assert(actual == expected);
}

int main()
{
  test_basic_vector();
  test_basic_vectors();
  test_basic_map();
}
