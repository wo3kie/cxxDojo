/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/quickSort
 */

#include <vector>

#include "./assert.hpp"
#include "./quick_sort.hpp"

/*
 * main
 */

int main() {
  std::vector<int> actual{3, 7, 9, 1, 2, 0, 4, 8, 6, 5};
  const std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  quickSort(actual.begin(), actual.end());
  assert(actual == expected);
}
