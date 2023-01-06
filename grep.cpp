/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 grep.cpp -o grep
 *
 * Usage:
 *      $ cat grep.cpp | ./grep ".*line.*"
 *          std::string line;
 *          while( std::getline( input, line ) )
 *                  if( std::regex_match( line, std::regex( argv[2] ) ) )
 *                      std::cout << line << std::endl;
 */

#include <iostream>
#include <regex>

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage " << argv[0] << " regex" << std::endl;
    return 1;
  }

  std::string line;

  while(std::getline(std::cin, line)) {
    if(std::regex_match(line, std::regex(argv[1]))) {
      std::cout << line << std::endl;
    }
  }
}
