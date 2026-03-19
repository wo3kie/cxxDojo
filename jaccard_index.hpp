#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>

#include "./feq.hpp"

template<typename Iterator1, typename Iterator2>
double jaccard_index(Iterator1 begin1, Iterator1 end1,
                    Iterator2 begin2, Iterator2 end2) {
  using T1 = typename std::iterator_traits<Iterator1>::value_type;
  using T2 = typename std::iterator_traits<Iterator2>::value_type;

  static_assert(std::is_same<T1, T2>::value, "value types must match");

  assert(std::is_sorted(begin1, end1));
  assert(std::is_sorted(begin2, end2));

  std::size_t intersection_size = 0;
  std::size_t union_size = 0;

  auto it1 = begin1;
  auto it2 = begin2;

  while (it1 != end1 && it2 != end2) {
    if (*it1 < *it2) {
      ++union_size;
      ++it1;
    } else if (*it2 < *it1) {
      ++union_size;
      ++it2;
    } else {
      ++intersection_size;
      ++union_size;
      ++it1;
      ++it2;
    }
  }

  union_size += static_cast<std::size_t>(std::distance(it1, end1));
  union_size += static_cast<std::size_t>(std::distance(it2, end2));

  if (union_size == 0) {
    return 1.0; 
  }

  return static_cast<double>(intersection_size) /
         static_cast<double>(union_size);

}

template<typename T>
double jaccard_index(const std::vector<T>& a, const std::vector<T>& b) {
  return jaccard_index(a.begin(), a.end(), b.begin(), b.end());
}
