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

template<typename Iterator>
void quickSort(const Iterator begin, const Iterator end) {
  if(begin == end) {
    return;
  }

  typedef typename std::iterator_traits<Iterator>::value_type value_type;

  const value_type pivot = *(begin + (end - begin) / 2);

  const auto lessThanPivot = [&pivot](const value_type& item) {
    return item < pivot;
  };

  const auto equalPivot = [&pivot](const value_type& item) {
    return item == pivot;
  };

  const Iterator middle1 = std::partition(begin, end, lessThanPivot);
  const Iterator middle2 = std::partition(middle1, end, equalPivot);

  quickSort(begin, middle1);
  quickSort(middle2, end);
}
