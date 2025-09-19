/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/base64 --encode "Hello World"
 *      SGVsbG8gV29ybGQ
 * 
 *      $ ./build/bin/base64 --decode SGVsbG8gV29ybGQ
 *      Hello World
 */

#include "./base64.hpp"

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cerr << "Usage:\n"
              << "  " << argv[0] << " --encode <string>\n"
              << "  " << argv[0] << " --decode <base64string>\n";
    return 1;
  }

  const std::string& mode = argv[1];

  if(mode != "--encode" && mode != "--decode") {
    std::cerr << "Error: first argument must be --encode or --decode\n";
    return 1;
  }

  if(mode == "--decode") {
    std::cout << base64decode(argv[2]) << std::endl;
  } else {
    std::cout << base64encode(argv[2]) << std::endl;
  }

  return 0;
}
