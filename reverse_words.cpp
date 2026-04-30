/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "./assert.hpp"

/*
 * reverse_words
 */

std::string reverse_words(std::string string) {
  std::reverse(string.begin(), string.end());

  size_t wordBegin = 0;
  size_t wordEnd = 0;
  const size_t end = string.size();

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

namespace ranges {

std::string reverse_words(std::string s) {
    std::reverse(s.begin(), s.end());

    for(auto&& word : s | std::views::split(' ')) {
        auto begin = word.begin();
        auto end = word.end();
        std::reverse(begin, end);
    }

    return s;
}

}

/*
 * main
 */

int main() {
  Assert(reverse_words("This is a test") == "test a is This");
  Assert(ranges::reverse_words("This is a test") == "test a is This");
}
