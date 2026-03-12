#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <exception>

template<typename T, size_t Size>
struct CircularBuffer {
  static_assert(Size > 0, ":(");

  T _data[Size];
  size_t _end = 0;
  size_t _size = 0;

  void push(T t) {
    _data[_end] = std::move(t);
    _end = (_end + 1) % Size;

    if (_size < Size) {
      _size += 1;
    }
  }

  const T& front() const {
    if(_size == 0) {
      throw std::out_of_range(":(");
    }

    return _data[0];
  }

  T pop() {
    if(_size == 0) {
      throw std::out_of_range(":(");
    }

    const size_t head = (_end + Size - _size) % Size;
    _size -= 1;
    return std::move(_data[head]);
  }

  [[nodiscard]] bool empty() const noexcept {
    return _size == 0;
  }

  [[nodiscard]] bool full() const noexcept {
    return _size == Size;
  }

  [[nodiscard]] size_t size() const noexcept {
    return _size;
  }

  [[nodiscard]] size_t capacity() const noexcept {
    return Size; 
  }
};
