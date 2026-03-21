/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *       $ ./build/bin/aho_corasick aho_corasick.dct aho_corasick.cpp
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

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " dictionary_file text_file" << std::endl;
    return 1;
  }

  constexpr const char* RED_DARK    = "\033[31m";
  constexpr const char* RED_LIGHT   = "\033[91m";

  constexpr const char* GREEN_DARK  = "\033[32m";
  constexpr const char* GREEN_LIGHT = "\033[92m";

  constexpr const char* BLUE_DARK   = "\033[34m";
  constexpr const char* BLUE_LIGHT  = "\033[94m";

  constexpr const char* RESET       = "\033[0m";


  AhoCorasick ac;
  std::string line;
  std::ifstream dictFile(argv[1]);
  std::ifstream textFile(argv[2]);

  while(std::getline(dictFile, line)) {
    ac.insert(line);
  }

  ac.build();

  while(std::getline(textFile, line)) {
    const auto print = [&](const size_t pos, const std::string& word) {
      std::cout << "> " << std::string(pos, ' ') << word << "\n";
      std::cout << "> " << line << "\n\n";
    };

    auto print_color = [&](const char* color) {
      return [&, color](const size_t pos, const std::string& word) {
        const size_t start = pos;
        const size_t end = pos + word.size();
        std::cout << line.substr(0, start) << color << line.substr(start, word.size()) << RESET << line.substr(end) << "\n";
      };
    };

    ac.search(line, print_color(GREEN_LIGHT));
  }
}
