/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/heap
 */

#include <iostream>

#include "./assert.hpp"
#include "./heap.hpp"

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

  Assert(heap.top() == 5);
  heap.pop();

  Assert(heap.top() == 4);
  heap.pop();

  Assert(heap.top() == 3);
  heap.pop();

  Assert(heap.top() == 2);
  heap.pop();

  Assert(heap.top() == 1);
  heap.pop();

  Assert(heap.empty() == true);
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

  Assert(heap.top() == 5);
  heap.pop();

  Assert(heap.top() == 4);
  heap.pop();

  Assert(heap.top() == 3);
  heap.pop();

  Assert(heap.top() == 2);
  heap.pop();

  Assert(heap.top() == 1);
  heap.pop();

  Assert(heap.empty() == true);
}

/*
 * main
 */

int main() {
  stl_Heap_test();
  cxxdojo_Heap_test();
}
