/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/hanoi size
 */

#include <iostream>

void hanoi(int size, int from, int to) {
  if(size == 0) {
    return;
  }

  const int middle = 1 + 2 + 3 - from - to;

  hanoi(size - 1, from, middle);

  std::cout << "Move from " << from << " to " << to << std::endl;

  hanoi(size - 1, middle, to);
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage: " << argv[0] << " number";
    return 1;
  }

  hanoi(atoi(argv[1]), 1, 2);
}
