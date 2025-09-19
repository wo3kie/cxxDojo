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
double jaccardIndex(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2) {
  typedef typename std::iterator_traits<Iterator1>::value_type type1;
  typedef typename std::iterator_traits<Iterator2>::value_type type2;

  static_assert(std::is_same<type1, type2>::value, "type1 != type2");

  std::vector<type1> set_intersection;
  std::set_intersection(begin1, end1, begin2, end2, std::back_inserter(set_intersection));

  std::vector<type1> set_union;
  std::set_union(begin1, end1, begin2, end2, std::back_inserter(set_union));

  if(set_union.empty()) {
    return 1;
  }

  return 1.0 * set_intersection.size() / set_union.size();
}

template<typename T>
double jaccardIndex(const std::vector<T>& vector1, const std::vector<T>& vector2) {
  return jaccardIndex(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
}
