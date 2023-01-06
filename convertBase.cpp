#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

char toChar(int i) {
  char chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  if(i < 36) {
    return chars[i];
  }

  throw std::out_of_range(std::to_string(i));
}

int fromChar(char c) {
  if(c >= '0' && c <= '9') {
    return c - '0';
  }

  if(c >= 'A' && c <= 'Z') {
    return 10 + c - 'A';
  }

  throw std::out_of_range(std::to_string(c));
}

std::string fromBase10(int number, int base) {
  std::string result;

  while(number > 0) {
    result += toChar(number % base);
    number = number / base;
  }

  return std::string(result.rbegin(), result.rend());
}

int toBase10(std::string const& number, int base) {
  int result = 0;

  for(char c : number) {
    result = result * base + fromChar(c);
  }

  return result;
}

std::string convertBase(std::string const& number, int fromBase, int toBase) {
  return fromBase10(toBase10(number, fromBase), toBase);
}

void test() {
  assert(convertBase("101010", 2, 8) == "52");
  assert(convertBase("101010", 2, 10) == "42");
  assert(convertBase("101010", 2, 16) == "2A");

  assert(convertBase("52", 8, 2) == "101010");
  assert(convertBase("52", 8, 10) == "42");
  assert(convertBase("52", 8, 16) == "2A");

  assert(convertBase("42", 10, 2) == "101010");
  assert(convertBase("42", 10, 8) == "52");
  assert(convertBase("42", 10, 16) == "2A");

  assert(convertBase("2A", 16, 2) == "101010");
  assert(convertBase("2A", 16, 8) == "52");
  assert(convertBase("2A", 16, 10) == "42");
}

int main(int argc, char* argv[]) {
  test();

  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " number fromBase toBase\n";
    return 1;
  }

  std::string const number = argv[1];
  int const fromBase = std::stoi(argv[2]);
  int const toBase = std::stoi(argv[3]);

  std::cout << convertBase(number, fromBase, toBase) << std::endl;

  return 0;
}
