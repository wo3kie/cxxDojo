/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 reverseWords.cpp -o reverseWords
 *
 * Usage:
 *      $ ./reverseWords
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string reverseWords(std::string string) {
  std::reverse(string.begin(), string.end());

  int wordBegin = 0;
  int wordEnd = 0;
  int const end = string.size();

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

int main() {
  assert(reverseWords("This is a test") == "test a is This");
}
