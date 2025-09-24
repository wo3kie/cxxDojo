/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/reverseWords
 */

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "./assert.hpp"

/*
 * reverseWords
 */

std::string reverseWords(std::string string) {
  std::reverse(string.begin(), string.end());

  int wordBegin = 0;
  int wordEnd = 0;
  const int end = string.size();

  while(wordEnd < end) {
    while(wordEnd < end) {
      if(string[wordEnd] == ' ') {
        break;
      }

      wordEnd += 1;
    }

    std::reverse(string.begin() + wordBegin, string.begin() + wordEnd);

    wordEnd += 1;
    wordBegin = wordEnd;
  }

  return string;
}

/*
 * main
 */

int main() {
  Assert(reverseWords("This is a test") == "test a is This");
}
