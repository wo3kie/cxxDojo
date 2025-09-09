/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 async.cpp -o async
 *
 * Usage:
 *      $ ./async
 */

#include <algorithm>
#include <cassert>
#include <future>
#include <optional>
#include <utility>
#include <vector>

template<typename Iterator>
std::pair<Iterator, Iterator> _minmax(Iterator begin, Iterator end) {
  if(begin == end) {
    return {begin, end};
  }

  const auto size = std::distance(begin, end);

  if(size < 128) {
    return std::minmax_element(begin, end);
  }

  std::future<std::pair<Iterator, Iterator>> left_part = std::async(
      std::launch::async, _minmax<Iterator>, begin, begin + size / 2);
  std::future<std::pair<Iterator, Iterator>> right_part = std::async(
      std::launch::async, _minmax<Iterator>, begin + size / 2, end);

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

int random_test() {
  for(int test = 0; test < 1024; ++test) {
    std::vector<int> array;
    const auto max_size = 1 + rand() % 1024;

    for(int size = 0; size < max_size; ++size) {
      array.push_back(rand() % 1024);
    }

    auto actual = _minmax(array.begin(), array.end());
    auto expected = std::minmax_element(array.begin(), array.end());

    assert(*actual.first == *expected.first);
    assert(*actual.second == *expected.second);
  }
}

int main() {
  random_test();
}
