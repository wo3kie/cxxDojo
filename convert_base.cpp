/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/convert_base number fromBase toBase
 */

#include <iostream>
#include <stdexcept>
#include <string>

#include "./assert.hpp"
#include "./convert_base.hpp"

void convertBase_test() {
  Assert(convertBase("101010", 2, 8) == "52");
  Assert(convertBase("101010", 2, 10) == "42");
  Assert(convertBase("101010", 2, 16) == "2A");

  Assert(convertBase("52", 8, 2) == "101010");
  Assert(convertBase("52", 8, 10) == "42");
  Assert(convertBase("52", 8, 16) == "2A");

  Assert(convertBase("42", 10, 2) == "101010");
  Assert(convertBase("42", 10, 8) == "52");
  Assert(convertBase("42", 10, 16) == "2A");

  Assert(convertBase("2A", 16, 2) == "101010");
  Assert(convertBase("2A", 16, 8) == "52");
  Assert(convertBase("2A", 16, 10) == "42");
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  convertBase_test();

  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " number fromBase toBase\n";
    return 1;
  }

  const std::string number = argv[1];
  const int fromBase = std::stoi(argv[2]);
  const int toBase = std::stoi(argv[3]);

  std::cout << convertBase(number, fromBase, toBase) << std::endl;

  return 0;
}
