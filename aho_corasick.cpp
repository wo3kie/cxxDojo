/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 aho_corasick.cpp -o aho_corasick
 *
 * Usage:
 * $ ./aho_corasick aho_corasick.dct aho_corasick.cpp
 * 
 * --------------------------------------------------------------------------------
 * >     auto const print = []( size_t const pos, std::string const & word ){
 * >     auto
 * >          const
 * >                  int
 * >                                   const
 * >                                                          const
 * >                                                                   or
 * --------------------------------------------------------------------------------
 */

#include <fstream>
#include <iostream>
#include <string>

#include "./aho_corasick.hpp"

int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " dictionary_file text_file" << std::endl;
    return 1;
  }

  aho_corasick::AhoCorasick ac;

  auto const print = [](size_t const pos, std::string const& word) {
    std::cout << "> " << std::string(pos, ' ') << word << std::endl;
  };

  std::string line;
  std::ifstream dictFile(argv[1]);
  std::ifstream textFile(argv[2]);

  while(std::getline(dictFile, line)) {
    ac.insert(line);
  }

  while(std::getline(textFile, line)) {
    std::cout << "> " << line << "\n";
    ac.search(line, print);
    std::cout << std::string(80, '-') << "\n";
  }
}
