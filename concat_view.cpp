/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 concat_view.cpp -o concat_view
 *
 * Usage:
 *      $ ./concat_view
 */

/*
 * test
 */

#include <deque>
#include <cassert>
#include <iostream>
#include <list>
#include <vector>

#include "concat_view.hpp"

void concat_view_test() {
  std::list<int> lst = {1, 2, 3};
  std::deque<int> deq = {4, 5, 6};
  std::vector<int> vec = {7, 8, 9};

  concat_view lst_view(lst);
  assert(std::vector<int>(lst_view.begin(), lst_view.end()) == std::vector<int>({1, 2, 3}));

  concat_view deq_view(deq);
  assert(std::vector<int>(deq_view.begin(), deq_view.end()) == std::vector<int>({4, 5, 6}));

  concat_view vec_view(vec);
  assert(std::vector<int>(vec_view.begin(), vec_view.end()) == std::vector<int>({7, 8, 9}));

  concat_view all_view(lst, deq, vec);
  assert(std::vector<int>(all_view.begin(), all_view.end()) == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

int main() {
  concat_view_test();
}
