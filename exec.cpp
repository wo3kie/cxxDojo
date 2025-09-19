/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/exec ls
 *      exec
 *      exec.cpp
 */

#include <iostream>

#include "./exec.hpp"

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage: " << argv[0] << " command" << std::endl;
    return 1;
  }

  const auto print = [](const char* p) {
    std::cout << p;
  };

  return exec(argv[1], print) ? 0 : 1;
}
