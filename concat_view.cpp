/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <deque>
#include <list>
#include <vector>

#include "./any_iterator.hpp"
#include "./assert.hpp"
#include "./concat_view.hpp"

void test_basic_vector() {
  std::vector<int> v;

  auto view = concat_view(v);
  
  const std::vector<int> actual{view.begin(), view.end()};
  const std::vector<int> expected{};
  Assert(actual == expected);
}

void test_all_empty() {
  std::vector<int> a{};
  std::vector<int> b{};
  std::vector<int> c{};

  auto view = concat_view(a, b, c);

  Assert(view.begin() == view.end());
}

void test_basic_vectors() {
  std::vector<int> a{};
  std::vector<int> b{1};
  std::vector<int> c{};
  std::vector<int> d{2, 3};
  std::vector<int> e{};
  std::vector<int> f{};
  std::vector<int> g{4, 5};
  std::vector<int> h{};
  
  auto view = concat_view(a, b, c, d, e, f, g, h);

  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 4, 5}; 
  Assert(actual == expected);
}

void test_basic_const_vectors() {
  const std::vector<int> a{};
  const std::vector<int> b{1};
  const std::vector<int> c{};
  const std::vector<int> d{2, 3};
  const std::vector<int> e{};
  const std::vector<int> f{};
  const std::vector<int> g{4, 5};
  const std::vector<int> h{};
  
  auto view = concat_view(a, b, c, d, e, f, g, h);

  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 4, 5}; 
  Assert(actual == expected);
}

void test_iterator_copies_equal() {
  const std::vector<int> v{1, 2, 3};

  auto view = concat_view(v);

  auto it1 = view.begin();
  auto it2 = view.begin();
  auto it3 = it1;

  Assert(it1 == it2);
  Assert(it2 == it3);

  ++it1;
  Assert(it1 != it2);
}

void test_basic_map() {
  std::map<std::string, int> a{};
  std::map<std::string, int> b{{"c++", 3}};
  std::map<std::string, int> c{};
  std::map<std::string, int> d{{"haskell", 7}, {"python", 6}};
  std::map<std::string, int> e{};
  std::map<std::string, int> f{};

  auto view = concat_view(a, b, c, d, e, f);
  const std::vector<std::pair<std::string, int>> actual = {view.begin(), view.end()};
  const std::vector<std::pair<std::string, int>> expected{{"c++", 3}, {"haskell", 7}, {"python", 6}}; 
  Assert(actual == expected);
}

void test_non_uniform() {
  std::vector<int> v{1, 2, 3};
  std::list<int> l{4, 5, 6};
  
  AnyRange<int, 8, 8> v_any_view = any_range(v);
  AnyRange<int, 8, 8> l_any_view = any_range(l);
  
  auto view = concat_view(v_any_view, l_any_view);
  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 4, 5, 6}; 
  Assert(actual == expected);
}

void test_const_non_uniform() {
  const std::vector<int> v{1, 2, 3};
  std::list<int> l{4, 5, 6};
  
  AnyRange<const int, 8, 8> v_any_view = any_range(v);
  AnyRange<const int, 8, 8> l_any_view = any_range(std::as_const(l));
  
  auto view = concat_view(v_any_view, l_any_view);
  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 4, 5, 6}; 
  Assert(actual == expected);
}

void test_const_reference() {
  static std::vector<int> v{1, 2, 3};

  auto get_seq_1 = [&]() -> const std::vector<int>& {
    return v;
  };

  auto get_seq_2 = [&]() -> const std::vector<int>& {
    return v;
  };

  auto view = concat_view(get_seq_1(), get_seq_2());
  const std::vector<int> actual = {view.begin(), view.end()};
  const std::vector<int> expected{1, 2, 3, 1, 2, 3}; 
  Assert(actual == expected);
}

int main() {
  test_basic_vector();
  test_all_empty();
  test_basic_vectors();
  test_basic_const_vectors();
  test_iterator_copies_equal();
  test_basic_map();
  test_non_uniform();
  test_const_non_uniform();
  test_const_reference();
}
