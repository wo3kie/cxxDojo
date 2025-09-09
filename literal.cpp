/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 literal.cpp -o literal
 *
 * Usage:
 *      $ ./literal
 */

#include <cassert>
#include <string>

int operator"" _bin(const char* text, size_t length) {
  int result = 0;

  for(size_t i = 0; i < length; ++i) {
    result = 2 * result + (text[i] - '0');
  }

  return result;
}

int operator"" _bin(const char* text) {
  int result = 0;

  for(size_t i = 0; text[i] != char(0); ++i) {
    result = 2 * result + (text[i] - '0');
  }

  return result;
}

int main() {
  assert(561 == "1000110001"_bin);
  assert(561 == 1000110001_bin);
}
