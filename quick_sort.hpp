#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <iterator>

template<std::random_access_iterator Iterator>
void quick_sort(const Iterator begin, const Iterator end) {
  using value_type = typename std::iterator_traits<Iterator>::value_type;

  if(end - begin <= 1) {
    return;
  }

  const value_type pivot = *(begin + (end - begin) / 2);

  const auto lessThanPivot = [&pivot](const value_type& item) {
    return item < pivot;
  };

  const auto equalPivot = [&pivot](const value_type& item) {
    return item == pivot;
  };

  const Iterator middle1 = std::partition(begin, end, lessThanPivot);
  const Iterator middle2 = std::partition(middle1, end, equalPivot);

  quick_sort(begin, middle1);
  quick_sort(middle2, end);
}

