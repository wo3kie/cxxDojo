/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 matrix.cpp -o matrix
 *
 * Usage:
 *      $ ./matrix
 */

#include <cassert>

#include "./matrix.hpp"

int main() {
  {
    Matrix const m1(2, 3, 1);
    Matrix const m2{{1, 1, 1}, {1, 1, 1}};
    assert(m1 == m2);
  }
  {
    Matrix const m1(2, 3, 1);
    Matrix const m2{{1, 1}, {1, 1}, {1, 1}};
    assert(m1 != m2);
  }
  {
    Matrix const m1{{1, 2}, {3, 4}, {5, 6}};
    Matrix const expected{{2, 4}, {6, 8}, {10, 12}};
    assert(m1 * 2 == expected);
  }
  {
    Matrix const m1{{1, 2}, {3, 4}, {5, 6}};
    Matrix const m2{{7, 8}, {9, 0}, {1, 2}};
    Matrix const expected{{8, 10}, {12, 4}, {6, 8}};
    assert(m1 + m2 == expected);
  }
  {
    Matrix const m1{{0, -1}, {1, 0}};
    Matrix const m2{{1, 2}, {3, 4}};
    Matrix const expected{{-3, -4}, {1, 2}};
    assert(m1 * m2 == expected);
  }
}
