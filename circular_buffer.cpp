/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/circular_buffer
 */

#include <iostream>
#include <tuple>

#include "./assert.hpp"
#include "./circular_buffer.hpp"

template<typename T, int Size>
std::ostream& operator<<(std::ostream& out, const CircularBuffer<T, Size>& buffer) {
  out << "{E: " << buffer._end << ", " << "S: " << buffer._size << " [";

  for(int i = 0; i < Size; ++i) {
    out << " " << buffer._data[i];
  }

  return out << "]}";
}

/*
 * main
 */

int main() {
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    Assert(cb.front() == 1);
  }
  
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    Assert(cb.pop() == 1);
    Assert(cb.pop() == 2);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    Assert(cb.pop() == 1);
    Assert(cb.pop() == 2);
    Assert(cb.pop() == 3);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    Assert(cb.pop() == 1);
    Assert(cb.pop() == 2);
    Assert(cb.pop() == 3);
    Assert(cb.pop() == 4);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    Assert(cb.pop() == 2);
    Assert(cb.pop() == 3);
    Assert(cb.pop() == 4);
    Assert(cb.pop() == 5);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    cb.push(6);
    Assert(cb.pop() == 3);
    Assert(cb.pop() == 4);
    Assert(cb.pop() == 5);
    Assert(cb.pop() == 6);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    cb.push(6);
    cb.push(7);
    Assert(cb.pop() == 4);
    Assert(cb.pop() == 5);
    Assert(cb.pop() == 6);
    Assert(cb.pop() == 7);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    cb.push(6);
    cb.push(7);
    cb.push(8);
    Assert(cb.pop() == 5);
    Assert(cb.pop() == 6);
    Assert(cb.pop() == 7);
    Assert(cb.pop() == 8);
  }

  {
    CircularBuffer<int, 4> cb;
    cb.push(1);            // [1, , , ]
    cb.push(2);            // [1,2, , ]
    Assert(cb.pop() == 1); // [ ,2, , ]
    cb.push(3);            // [ ,2,3, ]
    cb.push(4);            // [ ,2,3,4]
    Assert(cb.pop() == 2); // [ , ,3,4]
    cb.push(5);            // [5, ,3,4]
    cb.push(6);            // [5,6,3,4]
    Assert(cb.pop() == 3); // [5,6, ,4]
    cb.push(7);            // [5,6,7,4]
    cb.push(8);            // [5,6,7,8]
    Assert(cb.pop() == 5); // [ ,6,7,8]
  }
}
