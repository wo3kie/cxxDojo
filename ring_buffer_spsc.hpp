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

  static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be equal to 2^N");
  static_assert(sizeof(TValue) <= 64, "TValue must be less equal than 64 bytes");

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
  bool push(TT&& value) {
    const size_t begin = _begin.load(std::memory_order_acquire);
    const size_t end = _end.load(std::memory_order_relaxed);

    if(begin == _increment(end)) {
      return false;
    }

    _buffer[end].value = std::forward<TT>(value);
    _end.store(_increment(end), std::memory_order_release);

    return true;
  }

  bool pop(TValue& out) {
    const size_t begin = _begin.load(std::memory_order_relaxed);
    const size_t end = _end.load(std::memory_order_acquire);

    if(begin == end) {
      return false;
    }

    out = std::move(_buffer[begin].value);
    _begin.store(_increment(begin), std::memory_order_release);
   
    return true;
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept {
    return Capacity;
  }

  /* approximate */ [[nodiscard]] bool _empty() const noexcept {
    const size_t begin = _begin.load(std::memory_order_acquire);
    const size_t end = _end.load(std::memory_order_acquire);

    return begin == end ;
  }

  /* approximate */ [[nodiscard]] bool _full() const noexcept {
    const size_t begin = _begin.load(std::memory_order_acquire);
    const size_t end = _end.load(std::memory_order_acquire);

    return begin == _increment(end);
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;
   
    if(pop(out) == false) {
      throw std::runtime_error("Buffer is empty");
    }

    return out;
  }

private:
  [[nodiscard]] static constexpr size_t _increment(size_t i) noexcept {
    const size_t result = (i + 1) & (Capacity - 1);
    return result;
  }

private:
  /*
  * _begin: stored only by a consumer thread, so: - the consumer thread may read it as `relaxed` order
  *                                               - other threads have to read it as `acquire` order
  */
  alignas(64) std::atomic<size_t> _begin{0};

  /*
   * _end: stored only by a producer thread, so: - the producer thread may read it as `relaxed` order
   *                                             - other threads have to read it as `acquire` order
   */
  alignas(64) std::atomic<size_t> _end{0};
 
  alignas(64) std::array<Padded<TValue>, /* N+1 trick */ Capacity> _buffer;
};