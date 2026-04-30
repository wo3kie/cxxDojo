#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <condition_variable>
#include <mutex>

#include "./ring_buffer.hpp"

/*
 * RingBufferMT - Ring Buffer MuTex
 */

template<typename TValue, size_t Capacity>
class RingBufferMT {
public:
  using value_type = TValue;
  
  RingBufferMT() = default;
  RingBufferMT(RingBufferMT&&) = delete;
  RingBufferMT(const RingBufferMT&) = delete;
  
  ~RingBufferMT() = default;

  RingBufferMT& operator=(RingBufferMT&&) = delete;
  RingBufferMT& operator=(const RingBufferMT&) = delete;

public:
  template<typename TT>
  bool push(TT&& t) {
    std::unique_lock<std::mutex> lock(_mutex);

    _notFull.wait(lock, [this]() {
      return !this->_buffer.full();
    });

    _buffer.push(std::forward<TT>(t));
    _notEmpty.notify_one();

    return true;
  }

  bool pop(TValue& out) {
    std::unique_lock<std::mutex> lock(_mutex);

    _notEmpty.wait(lock, [this]() {
      return !this->_buffer.empty();
    });

    out = std::move(_buffer.pop());
    _notFull.notify_one();

    return true;
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept {
    return Capacity;
  }

  bool empty() const noexcept {
    std::lock_guard<std::mutex> lock(_mutex);
    return _buffer.empty();
  }

  bool full() const noexcept {
    std::lock_guard<std::mutex> lock(_mutex);
    return _buffer.full();
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;

    if (!pop(out)) {
      throw std::runtime_error("RingBufferMT is empty");
    }

    return out;
  }

private:
  std::mutex _mutex;

  std::condition_variable _notFull;
  std::condition_variable _notEmpty;

  RingBuffer<TValue, Capacity> _buffer;
};
