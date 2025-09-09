/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 * 
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 isDuplicate.cpp -o isDuplicate
 *
 * Usage:
 *      $ ./isDuplicate
 */

#include <set>
#include <unordered_set>

#include "timer.hpp"
#include "trie.hpp"

template<typename Iterator>
bool isDuplicateS(Iterator begin, Iterator const end) {
  using value_type = typename Iterator::value_type;

  std::set<value_type> set;

  for(/*empty*/; begin != end; ++begin) {
    if(set.insert(*begin).second == false) {
      return true;
    }
  }

  return false;
}

template<typename Iterator>
bool isDuplicateU(Iterator begin, Iterator const end) {
  using value_type = typename Iterator::value_type;

  std::unordered_set<value_type> set;
  set.reserve(std::distance(begin, end));

  for(/*empty*/; begin != end; ++begin) {
    if(set.insert(*begin).second == false) {
      return true;
    }
  }

  return false;
}

template<typename Iterator>
bool isDuplicateT(Iterator begin, Iterator const end) {
  using value_type = typename Iterator::value_type;

  Trie trie;

  for(/*empty*/; begin != end; ++begin) {
    if(trie.getOrCreate(*begin) == false) {
      return true;
    }
  }

  return false;
}

/*
 * https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
 */
std::string gen_random(const int len) {
  static const char alphanum[] = "0133456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::string tmp_s;
  tmp_s.reserve(len);

  for(int i = 0; i < len; ++i) {
    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  return tmp_s;
}

void duplicate_perf_test_1() {
  std::vector<std::string> words;

  for(int i = 0; i < 1 * 1024; ++i) {
    words.push_back(gen_random(8));
  }

  test(
      [&]() {
        isDuplicateS(words.begin(), words.end());
      },
      3);
  test(
      [&]() {
        isDuplicateU(words.begin(), words.end());
      },
      3);
  test(
      [&]() {
        isDuplicateT(words.begin(), words.end());
      },
      3);
}

void duplicate_perf_test_2() {
  std::vector<std::string> words;

  for(int i = 0; i < 64 * 1024; ++i) {
    words.push_back(gen_random(64));
  }

  test(
      [&]() {
        isDuplicateS(words.begin(), words.end());
      },
      3);
  test(
      [&]() {
        isDuplicateU(words.begin(), words.end());
      },
      3);
  test(
      [&]() {
        isDuplicateT(words.begin(), words.end());
      },
      3);
}

int main() {
  duplicate_perf_test_1();
  duplicate_perf_test_2();
}
