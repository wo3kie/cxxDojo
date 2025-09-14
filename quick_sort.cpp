/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 quickSort.cpp -o quickSort
 *
 * Usage:
 *      $ ./quickSort
 */

#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

template<typename Iterator>
void quickSort(Iterator const begin, Iterator const end) {
  if(begin == end) {
    return;
  }

  typedef typename std::iterator_traits<Iterator>::value_type value_type;

  value_type const pivot = *(begin + (end - begin) / 2);

  auto const lessThanPivot = [&pivot](value_type const& item) {
    return item < pivot;
  };

  auto const equalPivot = [&pivot](value_type const& item) {
    return item == pivot;
  };

  Iterator const middle1 = std::partition(begin, end, lessThanPivot);
  Iterator const middle2 = std::partition(middle1, end, equalPivot);

  quickSort(begin, middle1);
  quickSort(middle2, end);
}

int main() {
  std::vector<int> actual{3, 7, 9, 1, 2, 0, 4, 8, 6, 5};
  std::vector<int> const expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  quickSort(actual.begin(), actual.end());
  assert(actual == expected);
}
