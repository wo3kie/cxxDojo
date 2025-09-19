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

#include <cassert>
#include <exception>
#include <iostream>
#include <tuple>

template<typename T, int Size>
struct CircularBuffer {
  static_assert(Size > 0, ":(");

  T _data[Size];
  int _end = 0;
  int _size = 0;

  void push(const T& t) {
    _data[_end] = t;

    _end = (_end + 1) % Size;
    _size = std::min(_size + 1, Size);
  }

  T get() {
    if(_size == 0) {
      throw std::out_of_range(":(");
    }

    int head = _end - _size;

    if(head < 0) {
      head = Size + head;
    }

    const T result = _data[head];
    _size -= 1;

    return result;
  }
};

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
    assert(cb.get() == 1);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    assert(cb.get() == 1);
    assert(cb.get() == 2);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    assert(cb.get() == 1);
    assert(cb.get() == 2);
    assert(cb.get() == 3);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    assert(cb.get() == 1);
    assert(cb.get() == 2);
    assert(cb.get() == 3);
    assert(cb.get() == 4);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    assert(cb.get() == 2);
    assert(cb.get() == 3);
    assert(cb.get() == 4);
    assert(cb.get() == 5);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    cb.push(6);
    assert(cb.get() == 3);
    assert(cb.get() == 4);
    assert(cb.get() == 5);
    assert(cb.get() == 6);
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
    assert(cb.get() == 4);
    assert(cb.get() == 5);
    assert(cb.get() == 6);
    assert(cb.get() == 7);
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
    assert(cb.get() == 5);
    assert(cb.get() == 6);
    assert(cb.get() == 7);
    assert(cb.get() == 8);
  }
  {
    CircularBuffer<int, 4> cb;
    cb.push(1);            // [1, , , ]
    cb.push(2);            // [1,2, , ]
    assert(cb.get() == 1); // [ ,2, , ]
    cb.push(3);            // [ ,2,3, ]
    cb.push(4);            // [ ,2,3,4]
    assert(cb.get() == 2); // [ , ,3,4]
    cb.push(5);            // [5, ,3,4]
    cb.push(6);            // [5,6,3,4]
    assert(cb.get() == 3); // [5,6, ,4]
    cb.push(7);            // [5,6,7,4]
    cb.push(8);            // [5,6,7,8]
    assert(cb.get() == 5); // [ ,6,7,8]
  }
}
