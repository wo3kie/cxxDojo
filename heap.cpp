/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <iostream>

#include "./assert.hpp"
#include "./heap.hpp"
#include "./reshuffle.hpp"

/*
 * stl_Heap_test
 */

template<typename TCompare>
void test_heap(std::size_t size) {
  /*
   * Assuming STL implementation of a heap is correct, 
   * we can compare hand-made implementation with it
   */

  stl::Heap<int, TCompare> stl_heap;
  cxxdojo::Heap<int, TCompare> dojo_heap;

  std::vector<int> array;

  for(std::size_t i = 0; i < size; ++i) {
    array.push_back(i);
  }

  reshuffle(array, /* stddev */ 3);

  for(const auto& value : array) {
    stl_heap.push(value);
    dojo_heap.push(value);

    Assert(stl_heap.top() == dojo_heap.top());
  }

  for(std::size_t i = 0; i < size; ++i) {
    const int stl_top = stl_heap.top();
    const int dojo_top = dojo_heap.top();

    Assert(stl_top == dojo_top);

    stl_heap.pop();
    dojo_heap.pop();
  }
}

/*
 * main
 */

int main() {
  test_heap<std::greater<int>>(10);
  test_heap<std::less<int>>(10);

  test_heap<std::greater<int>>(100);
  test_heap<std::less<int>>(100);

  test_heap<std::greater<int>>(1000);
  test_heap<std::less<int>>(1000);
}
