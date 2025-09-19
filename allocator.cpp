/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/allocator
 */

#include <vector>

#include "./allocator.hpp"

int main() {
  std::vector<int, Allocator<int>> vector;
}
