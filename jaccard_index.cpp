/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 jaccard_index.cpp -o jaccard_index
 *
 * Usage:
 *      $ ./jaccard_index
 */

#include <cassert>

#include "./feq.hpp"
#include "./jaccard_index.hpp"

/*
 * jaccardIndex_test
 */

void jaccardIndex_test() {
  assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) == 1);
  assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {6, 7, 8, 9}) == 0);
  assert(feq(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}), 3.0 / 7));
}

/*
 * main
 */

int main() {
  jaccardIndex_test();
}
