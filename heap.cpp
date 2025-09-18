/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 heap.cpp -o heap
 *
 * Usage:
 *      $ ./heap
 */

#include "./heap.hpp"

#include <cassert>
#include <iostream>

/*
 * stl_Heap_test
 */

void stl_Heap_test() {
  stl::Heap<int> heap;

  heap.push(2);
  heap.push(1);
  heap.push(3);
  heap.push(5);
  heap.push(4);

  assert(heap.top() == 5);
  heap.pop();

  assert(heap.top() == 4);
  heap.pop();

  assert(heap.top() == 3);
  heap.pop();

  assert(heap.top() == 2);
  heap.pop();

  assert(heap.top() == 1);
  heap.pop();

  assert(heap.empty() == true);
}

/*
 * cxxdojo_Heap_test
 */

void cxxdojo_Heap_test() {
  cxxdojo::Heap<int> heap;

  heap.push(2);
  heap.push(1);
  heap.push(3);
  heap.push(5);
  heap.push(4);

  assert(heap.top() == 5);
  heap.pop();

  assert(heap.top() == 4);
  heap.pop();

  assert(heap.top() == 3);
  heap.pop();

  assert(heap.top() == 2);
  heap.pop();

  assert(heap.top() == 1);
  heap.pop();

  assert(heap.empty() == true);
}

/*
 * main
 */

int main() {
  stl_Heap_test();
  cxxdojo_Heap_test();
}
