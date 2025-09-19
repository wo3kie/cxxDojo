/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/matrix
 */

#include <cassert>

#include "./matrix.hpp"

int main() {
  {
    const Matrix m1(2, 3, 1);
    const Matrix m2{{1, 1, 1}, {1, 1, 1}};
    assert(m1 == m2);
  }
  {
    const Matrix m1(2, 3, 1);
    const Matrix m2{{1, 1}, {1, 1}, {1, 1}};
    assert(m1 != m2);
  }
  {
    const Matrix m1{{1, 2}, {3, 4}, {5, 6}};
    const Matrix expected{{2, 4}, {6, 8}, {10, 12}};
    assert(m1 * 2 == expected);
  }
  {
    const Matrix m1{{1, 2}, {3, 4}, {5, 6}};
    const Matrix m2{{7, 8}, {9, 0}, {1, 2}};
    const Matrix expected{{8, 10}, {12, 4}, {6, 8}};
    assert(m1 + m2 == expected);
  }
  {
    const Matrix m1{{0, -1}, {1, 0}};
    const Matrix m2{{1, 2}, {3, 4}};
    const Matrix expected{{-3, -4}, {1, 2}};
    assert(m1 * m2 == expected);
  }
}
