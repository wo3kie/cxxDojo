/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/jaccard_index
 */

#include "./assert.hpp"
#include "./feq.hpp"
#include "./jaccard_index.hpp"

/*
 * jaccardIndex_test
 */

void jaccardIndex_test() {
  Assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) == 1);
  Assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {6, 7, 8, 9}) == 0);
  Assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}) == approx(3.0 / 7.0));
}

/*
 * main
 */

int main() {
  jaccardIndex_test();
}
