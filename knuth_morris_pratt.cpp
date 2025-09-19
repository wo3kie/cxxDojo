/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/knuth_morris_pratt 5 3.14159265359
 *      5 9 11 
 */

#include <cassert>
#include <iostream>

#include "./knuth_morris_pratt.hpp"

/*
 * kmp_test
 */
void kmp_test() {
  assert((
      //         01234
      kmp("a", "aaaaa") == std::vector<unsigned>{0, 1, 2, 3, 4}));

  assert((
      //          01234
      kmp("aa", "aaaaa") == std::vector<unsigned>{0, 1, 2, 3}));

  assert((
      //           0123456789012345678901234567890
      kmp("c++", "c++ c++03 c++11 c++14 c++17 c++") == std::vector<unsigned>{0, 4, 10, 16, 22, 28}));
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  kmp_test();

  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " pattern text\n";
    return 1;
  }

  std::vector<unsigned> positions = kmp(argv[1], argv[2]);

  for(unsigned u : positions) {
    std::cout << u << " ";
  }

  std::cout << std::endl;

  return 0;
}
