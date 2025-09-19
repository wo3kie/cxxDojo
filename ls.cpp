/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/ls .
 *      F "./get.request.cpp"
 *      F "./par.cpp"
 *      F "./barrier.cpp"
 *      F "./ls.cpp"
 *      F "./scope_exit.cpp"
 *      ...
 */

#include "./ls.hpp"

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage: " << argv[0] << " directoryName" << std::endl;
    return 1;
  } else {
    printDirectoryContent(argv[1]);
    return 0;
  }
}
