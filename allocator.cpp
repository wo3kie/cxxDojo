/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <vector>

#include "./allocator.hpp"

/*
 * main
 */

int main() {
  std::vector<int, Allocator<int>> vector;
}
