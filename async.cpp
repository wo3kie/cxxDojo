/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/async
 */

#include <algorithm>
#include <future>
#include <optional>
#include <utility>
#include <vector>

#include "./assert.hpp"

/*
 * min_max
 */

template<typename Iterator>
std::pair<Iterator, Iterator> min_max(Iterator begin, Iterator end) {
  if(begin == end) {
    return {begin, end};
  }

  const auto size = std::distance(begin, end);

  if(size < 128) {
    return std::minmax_element(begin, end);
  }

  std::future<std::pair<Iterator, Iterator>> left_part = std::async(std::launch::async, min_max<Iterator>, begin, begin + size / 2);
  std::future<std::pair<Iterator, Iterator>> right_part = std::async(std::launch::async, min_max<Iterator>, begin + size / 2, end);

  const std::pair<Iterator, Iterator> left_result = left_part.get();
  const std::pair<Iterator, Iterator> right_result = right_part.get();

  if(*left_result.first < *right_result.first) {
    if(*left_result.second > *right_result.second) {
      return {left_result.first, left_result.second};
    } else {
      return {left_result.first, right_result.second};
    }
  } else {
    if(*left_result.second > *right_result.second) {
      return {right_result.first, left_result.second};
    } else {
      return {right_result.first, right_result.second};
    }
  }
}

/*
 * test
 */

void min_max_test() {
  for(int test = 0; test < 1024; ++test) {
    std::vector<int> array;
    const auto max_size = 1 + rand() % 1024;

    for(int size = 0; size < max_size; ++size) {
      array.push_back(rand() % 1024);
    }

    auto actual = min_max(array.begin(), array.end());
    auto expected = std::minmax_element(array.begin(), array.end());

    Assert(*actual.first == *expected.first);
    Assert(*actual.second == *expected.second);
  }
}

/*
 * main
 */

int main() {
  min_max_test();
}
