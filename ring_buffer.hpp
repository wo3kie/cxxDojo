#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstddef>
#include <stdexcept>

/*
 * RingBuffer
 */

template<typename TValue, size_t Capacity>
class RingBuffer {
public:
  using value_type = TValue;
  
  RingBuffer() = default;
  RingBuffer(RingBuffer&&) = delete;
  RingBuffer(const RingBuffer&) = delete;
  
  ~RingBuffer() = default;

  RingBuffer& operator=(RingBuffer&&) = delete;
  RingBuffer& operator=(const RingBuffer&) = delete;

public:
  template<typename TT>
  bool push(TT&& t) {
    if (full()) {
      return false;
    }
    
    _buffer[_end] = std::forward<TT>(t);
    _end = _increment(_end);

    return true;
  }

  bool pop(TValue& out) {
    if (empty()) {
      return false;
    }

    out = std::move(_buffer[_begin]);
    _begin = _increment(_begin);
    
    return true;
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept {
    return Capacity;
  }

  [[nodiscard]] bool empty() const noexcept {
    return _begin == _end;
  }

  [[nodiscard]] bool full() const noexcept {
    return _increment(_end) == _begin;
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;

    if (!pop(out)) {
      throw std::runtime_error("RingBuffer is empty");
    }

    return out;
  }

private:
  static size_t _increment(size_t i) noexcept {
    return (i + 1) % Capacity;
  }

private:
  size_t _begin{0};
  size_t _end{0};

  std::array<TValue, /* N+1 trick */ Capacity + 1> _buffer;
};
