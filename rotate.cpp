/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 rotate.cpp -o rotate
 *
 * Usage:
 *      $ ./rotate
 */

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename TIterator>
void rotate_cxx03(TIterator begin, TIterator pivot, TIterator const end) {
  TIterator next = pivot;

  while(begin != end) {
    std::swap(*begin++, *next++);

    if(next == end) {
      next = pivot;
    } else if(begin == pivot) {
      pivot = next;
    }
  }
}

template<typename TIterator>
TIterator rotate_cxx11(TIterator begin, TIterator pivot, TIterator end) {
  TIterator result = begin + (end - pivot);

  rotate_cxx03(begin, pivot, end);

  return result;
}

std::vector<int> getRandomVector(int maxSize = 32, int maxValue = 32) {
  int const size = std::max(1, std::rand() % maxSize);
  std::vector<int> result(size);

  for(int i = 0; i < size; ++i) {
    result[i] = std::rand() % maxValue;
  }

  return result;
}

void test() {
  for(int i = 0; i < 32 * 1024; ++i) {
    std::vector<int> v1 = getRandomVector();
    std::vector<int> v2 = v1;
    int const pivot = rand() % v1.size();

    rotate_cxx11(v1.begin(), v1.begin() + pivot, v1.end());
    std::rotate(v2.begin(), v2.begin() + pivot, v2.end());

    assert(v1 == v2);
  }
}

int main() {
  test();

  std::cout << "OK" << std::endl;
}
