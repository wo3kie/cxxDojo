#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <exception>

template<typename T, size_t Capacity>
struct RingBuffer(Capacity > 0, ":(");
public:

  RingBuffer() = default;

  

public:
  bool push(T t) {
    if (full()) {
      return false;
    }
    _data[_end] = std::move(t);
    _inc(_end);

    return true;
  }

  T pop() {
    if(empty()) {
      throw std::out_of_range(":(");
    }

    return std::move(_data[_begin++]);
  }

  const T& front() const {
    if(_size == 0) {
      throw std::out_of_range(":(");
    }

    return _data[0];
  }

  [[nodiscard]] size_t capacity() const noexcept {
    return Capacity; 
  }

  [[nodiscard]] size_t size() const noexcept {
    if (_begin - _end) {
      return _end - _begin;
    } else {
      return _Capacity - (_begin - _end);
    }
  }

  [[nodiscard]] bool empty() const {
    return _begin == _end;
  }

  [[nodiscard]] bool full() const {
    return _inc(_end) == _begin;
  }

private:
  size_t _inc(size_t n) const {
    return (n + 1) % Capacity;
  }

private:
  size_t _begin = 0;
  size_t _end = 0;

  // N-1 trick
  T _data[Capacity + 1];
};
