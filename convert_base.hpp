#pragma once

/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 */

#include <stdexcept>
#include <string>

namespace impl {

inline char toChar(int i) {
  char chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  if(i < 36) {
    return chars[i];
  }

  throw std::out_of_range(std::to_string(i));
}

inline int fromChar(char c) {
  if(c >= '0' && c <= '9') {
    return c - '0';
  }

  if(c >= 'A' && c <= 'Z') {
    return 10 + c - 'A';
  }

  throw std::out_of_range(std::to_string(c));
}

} // namespace impl

inline std::string fromBase10(int number, int base) {
  std::string result;

  while(number > 0) {
    result += impl::toChar(number % base);
    number = number / base;
  }

  return std::string(result.rbegin(), result.rend());
}

inline int toBase10(const std::string& number, int base) {
  int result = 0;

  for(char c : number) {
    result = result * base + impl::fromChar(c);
  }

  return result;
}

inline std::string convertBase(const std::string& number, int fromBase, int toBase) {
  return fromBase10(toBase10(number, fromBase), toBase);
}
