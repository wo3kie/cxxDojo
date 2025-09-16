/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <string>
#include <vector>

/*
 * getPrefixSuffix
 */

inline std::vector<unsigned> getPrefixSuffix(const std::string& pattern) {
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

/*
 * kmp
 */

inline std::vector<unsigned> kmp(const std::string& pattern, const std::string& text) {
  std::vector<unsigned> result;
  std::vector<unsigned> prefixSuffix = getPrefixSuffix(pattern + char(0) + text);

  for(unsigned u = 0; u < prefixSuffix.size(); ++u) {
    if(prefixSuffix[u] == pattern.size()) {
      result.push_back(u - 2 * pattern.size());
    }
  }

  return result;
}

