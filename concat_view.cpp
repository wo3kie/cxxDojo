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

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "./assert.hpp"
#include "./concat_view.hpp"

void concat_view_test_1() {
  std::list<int> lst = {1, 2, 3};
  std::deque<int> deq = {4, 5, 6};
  const std::vector<int> vec = {7, 8, 9};

  concat_view lst_view(lst);
  assert(std::vector<int>(lst_view.begin(), lst_view.end()) == std::vector<int>({1, 2, 3}));

  concat_view deq_view(deq);
  assert(std::vector<int>(deq_view.begin(), deq_view.end()) == std::vector<int>({4, 5, 6}));

  concat_view vec_view(vec);
  assert(std::vector<int>(vec_view.begin(), vec_view.end()) == std::vector<int>({7, 8, 9}));

  concat_view lst_deq_view(lst, deq);
  assert(std::vector<int>(lst_deq_view.begin(), lst_deq_view.end()) == std::vector<int>({1, 2, 3, 4, 5, 6}));

  concat_view all_view(lst, deq, vec);
  assert(std::vector<int>(all_view.begin(), all_view.end()) == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

void concat_view_test_2() {
  std::list<int> lst = {1, 2, 3};

  concat_view lst_view(lst);

  for(int& i : lst_view) {
    i = 0;
  }

  assert(std::vector<int>(lst_view.begin(), lst_view.end()) == std::vector<int>({0, 0, 0}));
}

void concat_view_test_3() {
  const std::list<int> lst = {1, 1, 1};

  concat_view lst_view(lst);

  for(const int& i : lst_view) {
    assert(i == 1);
  }
}

void uniform_concat_view_test_basic() {
  std::vector<int> a{1, 2, 3};
  std::vector<int> b{4, 5};
  std::vector<int> c{6, 7, 8, 9};

  uniform_concat_view view(a, b, c);

  std::vector<int> result;
  for(int x : view) {
    result.push_back(x);
  }

  assert((result == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

void uniform_concat_view_test_empty_segments() {
  std::vector<int> a{};
  std::vector<int> b{1, 2};
  std::vector<int> c{};

  uniform_concat_view view(a, b, c);

  std::vector<int> result;
  for(int x : view) {
    result.push_back(x);
  }

  assert((result == std::vector<int>{1, 2}));
}

void uniform_concat_view_test_all_empty() {
  std::vector<int> a{};
  std::vector<int> b{};
  std::vector<int> c{};

  uniform_concat_view view(a, b, c);

  auto it = view.begin();
  auto end = view.end();

  assert(it == end);
}

void uniform_concat_view_test_iterator_equality() {
  std::vector<int> a{1, 2};
  std::vector<int> b{3};

  uniform_concat_view view(a, b);

  auto it1 = view.begin();
  auto it2 = view.begin();

  assert(it1 == it2);

  ++it1;
  assert(! (it1 == it2));

  ++it2;
  assert(it1 == it2);
}

void uniform_concat_view_test_const_correctness() {
  const std::vector<int> a{1, 2};
  const std::vector<int> b{3, 4};

  const uniform_concat_view view(a, b);

  int sum = 0;
  for(int x : view) {
    sum += x;
  }

  assert(sum == 10);
}

void uniform_concat_view_test_reference_integrity() {
  std::vector<int> a{1, 2};
  std::vector<int> b{3};

  uniform_concat_view view(a, b);

  for(int& x : view) {
    x *= 10;
  }

  assert((a == std::vector<int>{10, 20}));
  assert((b == std::vector<int>{30}));
}

void uniform_concat_view_test_ctad() {
  std::vector<int> a{1};
  std::vector<int> b{2};
  std::vector<int> c{3};

  uniform_concat_view view(a, b, c);

  std::vector<int> result;
  for(int x : view) {
    result.push_back(x);
  }

  assert((result == std::vector<int>{1, 2, 3}));
}

void uniform_concat_view_test_map() {
  std::map<int, std::string> a{{1, "one"}, {2, "two"}};
  std::map<int, std::string> b{{3, "three"}, {4, "four"}};

  std::vector<std::pair<int, std::string>> result;

  for(auto& [k, v] : uniform_concat_view(a, b)) {
    result.emplace_back(k, v);
  }

  const std::vector<std::pair<int, std::string>> expected{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
  assert((result == expected));
}

int main() {
  concat_view_test_1();
  concat_view_test_2();
  concat_view_test_3();

  uniform_concat_view_test_basic();
  uniform_concat_view_test_empty_segments();
  uniform_concat_view_test_all_empty();
  uniform_concat_view_test_iterator_equality();
  uniform_concat_view_test_const_correctness();
  uniform_concat_view_test_reference_integrity();
  uniform_concat_view_test_ctad();
  uniform_concat_view_test_map();
}
