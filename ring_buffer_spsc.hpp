#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <utility>

/*
 * Circular Buffer, Single Producer Single Consumer, Lock Free
 */

template<typename TValue, std::size_t Capacity>
class RingBufferSPSC {
  template<typename T>
  struct alignas(64) Padded {
      T value;
  };

public:
  using value_type = TValue;

public:
  RingBufferSPSC() = default;

  RingBufferSPSC(RingBufferSPSC&&) = delete;
  RingBufferSPSC(const RingBufferSPSC&) = delete;

  RingBufferSPSC& operator=(RingBufferSPSC&&) = delete;
  RingBufferSPSC& operator=(const RingBufferSPSC&) = delete;

public:
  template<typename TT>
  bool push(TT&& value) noexcept {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_relaxed);

    if(head == _increment(tail)) {
      return false;
    }

    _buffer[tail].value = std::forward<TT>(value);
    _tail.store(_increment(tail), std::memory_order_release);

    return true;
  }

  bool pop(TValue& out) noexcept {
    const std::size_t head = _head.load(std::memory_order_relaxed);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    if(head == tail) {
      return false;
    }

    out = std::move(_buffer[head].value);
    _head.store(_increment(head), std::memory_order_release);
   
    return true;
  }

  [[nodiscard]] static constexpr std::size_t capacity() noexcept {
    return Capacity;
  }

  /* approximate */ [[nodiscard]] bool _empty() const noexcept {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    return head == tail ;
  }

  /* approximate */ [[nodiscard]] bool _full() const noexcept {
    const std::size_t head = _head.load(std::memory_order_acquire);
    const std::size_t tail = _tail.load(std::memory_order_acquire);

    return head == _increment(tail);
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;
   
    if(pop(out) == false) {
      throw std::runtime_error("Buffer is empty");
    }

    return out;
  }

private:
  static constexpr bool is_power_of_2(std::size_t n) noexcept {
    return (n & (n - 1)) == 0;
  }

  [[nodiscard]] static constexpr std::size_t _increment(std::size_t i) noexcept {
    constexpr std::size_t BufferSize = Capacity + 1;

    if constexpr(is_power_of_2(BufferSize)) {
      return (i + 1) & (BufferSize - 1);
    } else {
      return (i + 1) % BufferSize;
    }
  }

private:
  alignas(64) std::atomic<std::size_t> _head{0};
  alignas(64) std::atomic<std::size_t> _tail{0};
 
  alignas(64) std::array<Padded<TValue>, /* N+1 trick */ Capacity + 1> _buffer;
};