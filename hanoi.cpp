/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 hanoi.cpp -o hanoi
 *
 * Usage:
 *      $ ./hanoi size
 */

#include <iostream>

void hanoi(int size, int from, int to) {
  if(size == 0) {
    return;
  }

  int const middle = 1 + 2 + 3 - from - to;

  hanoi(size - 1, from, middle);
  std::cout << "Move from " << from << " to " << to << std::endl;
  hanoi(size - 1, middle, to);
}

int main(int argc, char* argv[]) {
  hanoi(atoi(argv[1]), 1, 2);
}
