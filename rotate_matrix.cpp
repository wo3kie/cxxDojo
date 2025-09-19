/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/rotate_matrix
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "./output.hpp"

/*
 * swap
 */

void swap(int& i1, int& i2, int& i3, int& i4) {
  int tmp = i4;
  i4 = i3;
  i3 = i2;
  i2 = i1;
  i1 = tmp;
}

/*
 * rotateMatrix
 */

std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> m) {
  for(unsigned row = 0; row < m.size() / 2; ++row) {
    for(unsigned column = row; column < m.size() - row - 1; ++column) {
      swap(
          m[row][column], //
          m[column][m.size() - row - 1],
          m[m.size() - row - 1][m.size() - column - 1],
          m[m.size() - column - 1][row]);
    }
  }

  return m;
}

/*
 * test
 */

void test(int size) {
  std::vector<std::vector<int>> m(size, std::vector<int>(size, 0));

  for(unsigned r = 0; r < size; ++r) {
    for(unsigned c = 0; c < size; ++c) {
      m[r][c] = size * r + c + 1;
    }
  }

  std::cout << rotateMatrix(m) << std::endl;
}

/*
 * main
 */

int main() {
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(6);
}
