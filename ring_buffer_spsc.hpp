#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <stdexcept>
#include <utility>

/*
 * Circular Buffer, Single Producer Single Consumer, Lock Free
 */

template<typename TValue, std::size_t Capacity>
class RingBufferSPSC {
public:
  using value_type = TValue;

public:
  RingBufferSPSC() = default;

  RingBufferSPSC(RingBufferSPSC&&) = delete;
  RingBufferSPSC(const RingBufferSPSC&) = delete;

  RingBufferSPSC& operator=(RingBufferSPSC&&) = delete;
  RingBufferSPSC& operator=(const RingBufferSPSC&) = delete;

public:
  template<typename T>
  bool push(T&& value) {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_relaxed);

    if(head == _index(tail + 1)) {
      return false;
    }

    _buffer[tail] = std::forward<T>(value);
    _tail.store(_index(tail + 1), std::memory_order_release);

    return true;
  }

  bool pop(TValue& out) {
    const std::size_t head = _head.load(std::memory_order_relaxed);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    if(head == tail) {
      return false;
    }

    out = std::move(_buffer[head]);
    _head.store(_index(head + 1), std::memory_order_release);
   
    return true;
  }

  [[nodiscard]] static constexpr std::size_t capacity() noexcept {
    return Capacity;
  }

  /* approximate */ [[nodiscard]] bool empty_approx() const noexcept {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    return head == tail ;
  }

  /* approximate */ [[nodiscard]] bool full_approx() const noexcept {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    return head == _index(tail + 1);
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;
   
    if(pop(out) == false) {
      throw std::runtime_error("Buffer is empty");
    }

    return out;
  }

private:
  [[nodiscard]] static constexpr std::size_t _index(std::size_t i) noexcept {
    constexpr bool isPowerOf2 = ((Capacity + 1) & Capacity) == 0;

    if constexpr(isPowerOf2) {
      return i & Capacity;
    } else {
      return i % (Capacity + 1);
    }
  }

private:
  alignas(64) std::atomic<std::size_t> _head{0};
  alignas(64) std::atomic<std::size_t> _tail{0};
  alignas(64) std::array<TValue, /* N+1 trick */ Capacity + 1> _buffer;
};