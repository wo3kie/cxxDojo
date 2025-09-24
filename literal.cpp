/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/literal
 */

#include <string>

#include "./assert.hpp"

/*
 * operator"" _bin(const char* text, size_t length)
 */

int operator"" _bin(const char* text, size_t length) {
  int result = 0;

  for(size_t i = 0; i < length; ++i) {
    result = 2 * result + (text[i] - '0');
  }

  return result;
}

/*
 * operator"" _bin(const char* text)
 */

int operator"" _bin(const char* text) {
  int result = 0;

  for(size_t i = 0; text[i] != char(0); ++i) {
    result = 2 * result + (text[i] - '0');
  }

  return result;
}

/*
 * main
 */

int main() {
  Assert(561 == "1000110001"_bin); // int operator"" _bin(const char* text, size_t length)
  Assert(561 == 1000110001_bin);   // int operator"" _bin(const char* text)
}
