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
 * jaccard_index_test
 */

void jaccard_index_test() {
  Assert(jaccard_index<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) == 1);
  Assert(jaccard_index<int>({1, 2, 3, 4, 5}, {6, 7, 8, 9}) == 0);
  Assert(jaccard_index<int>({1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}) == approx(3.0 / 7.0));
}

/*
 * main
 */

int main() {
  jaccard_index_test();
}
