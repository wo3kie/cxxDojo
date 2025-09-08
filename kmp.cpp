/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 kmp.cpp -o kmp
 *
 * Usage:
 *      $ ./kmp 5 3.14159265359
 *      5 9 11 
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned> getPrefixSuffix(std::string const& pattern) {
  unsigned size = pattern.size();
  unsigned back = 0;
  unsigned front = 1;
  std::vector<unsigned> result(size, 0u);

  while(front < size) {
    if(pattern[back] == pattern[front]) {
      /* 
             * b   p            b   p
             * a n a n a s -> a n a n a s
             * 0 0            0 0 1
             */

      result[front] = back + 1;
      front += 1;
      back += 1;
    } else {
      if(back == 0) {
        /* 
                 * b p            b   p
                 * a n a n a s -> a n a n a s
                 * 0              0 0
                 */

        front += 1;
      } else {
        /* 
                 *       b   p      b       p
                 * a n a n a s -> a n a n a s
                 * 0 0 1 2 3      0 0 1 2 3
                 */

        back = result[back - 1];
      }
    }
  }

  return result;
}

std::vector<unsigned> kmp(std::string const& pattern, std::string const& text) {
  std::vector<unsigned> result;

  /*
     * pattern0text:    ananas0this is an ananas.
     * prefixSuffix:    0012300000000001201234560
     * matching    :                           ^
     */

  std::vector<unsigned> prefixSuffix = getPrefixSuffix(pattern + char(0) + text);

  for(unsigned u = 0; u < prefixSuffix.size(); ++u) {
    if(prefixSuffix[u] == pattern.size()) {
      result.push_back(u - 2 * pattern.size());
    }
  }

  return result;
}

void test() {
  assert((
      //         01234
      kmp("a", "aaaaa") == std::vector<unsigned>{0, 1, 2, 3, 4}));

  assert((
      //          01234
      kmp("aa", "aaaaa") == std::vector<unsigned>{0, 1, 2, 3}));

  assert((
      //           0123456789012345678901234567890
      kmp("c++", "c++ c++03 c++11 c++14 c++17 c++") == std::vector<unsigned>{0, 4, 10, 16, 22, 28}));
}

int main(int argc, char* argv[]) {
  test();

  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " pattern text\n";
    return 1;
  }

  std::vector<unsigned> positions = kmp(argv[1], argv[2]);

  for(unsigned u : positions) {
    std::cout << u << " ";
  }

  std::cout << std::endl;

  return 0;
}
