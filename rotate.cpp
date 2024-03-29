/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 rotate.cpp -o rotate
 *
 * Usage:
 *      $ ./rotate
 */

#include <cassert>
#include <vector>

#include "./rotate.hpp"
#include "./output.hpp"

using VI = std::vector<int>;

template<typename Rotate>
void rotate_right_test(Rotate r) {
  VI array;

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 0, array.end());
  assert((array == VI{1, 2, 3, 4, 5, 6, 7}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 1, array.end());
  assert((array == VI{7, 1, 2, 3, 4, 5, 6}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 2, array.end());
  assert((array == VI{6, 7, 1, 2, 3, 4, 5}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 3, array.end());
  assert((array == VI{5, 6, 7, 1, 2, 3, 4}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 4, array.end());
  assert((array == VI{4, 5, 6, 7, 1, 2, 3}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 5, array.end());
  assert((array == VI{3, 4, 5, 6, 7, 1, 2}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 6, array.end());
  assert((array == VI{2, 3, 4, 5, 6, 7, 1}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 7, array.end());
  assert((array == VI{1, 2, 3, 4, 5, 6, 7}));
}

template<typename Rotate>
void rotate_left_test(Rotate r) {
  VI array;

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 0, array.end());
  assert((array == VI{1, 2, 3, 4, 5, 6, 7}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 1, array.end());
  assert((array == VI{2, 3, 4, 5, 6, 7, 1}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 2, array.end());
  assert((array == VI{3, 4, 5, 6, 7, 1, 2}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 3, array.end());
  assert((array == VI{4, 5, 6, 7, 1, 2, 3}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 4, array.end());
  assert((array == VI{5, 6, 7, 1, 2, 3, 4}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 5, array.end());
  assert((array == VI{6, 7, 1, 2, 3, 4, 5}));

  array = {1, 2, 3, 4, 5, 6, 7};
  r(array.begin(), array.begin() + 6, array.end());
  assert((array == VI{7, 1, 2, 3, 4, 5, 6}));
}

int main() {
  rotate_left_test(rotate_left_1<VI::iterator>);
  rotate_left_test(rotate_left_2<VI::iterator>);

  rotate_right_test(rotate_right_1<VI::iterator>);
  rotate_right_test(rotate_right_2<VI::iterator>);
}
