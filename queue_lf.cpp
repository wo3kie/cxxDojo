#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <utility>

template<typename T, std::size_t Capacity>
class SpscRingBuffer {
  static_assert(Capacity >= 2, "Capacity must be at least 2");
  static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be a power of two for fast masking");

public:
  using value_type = T;

  SpscRingBuffer() = default;

  SpscRingBuffer(SpscRingBuffer&&) = delete;
  SpscRingBuffer(const SpscRingBuffer&) = delete;

  SpscRingBuffer& operator=(SpscRingBuffer&&) = delete;
  SpscRingBuffer& operator=(const SpscRingBuffer&) = delete;

public:
  bool push(T value) {
    const size_t _begin = _begin.load(std::memory_order_acquire);
    const size_t _end = _end.load(std::memory_order_relaxed);

    if(_full()) {
      return false;
    }

    _buffer[_end] = std::move(value);
    _end.store(_increment(_end), std::memory_order_release);

    return true;
  }

  bool pop(T& out) {
    const size_t _begin = _begin.load(std::memory_order_relaxed);
    const size_t _end = _end.load(std::memory_order_acquire);

    if(_empty()) {
      return false;
    }

    out = std::move(_buffer[_begin]);
    _begin.store(_increment(_begin), std::memory_order_release);
    
    return true;
  }

  /* approximate */ [[nodiscard]] bool _empty() const noexcept {
    const size_t _begin = _begin.load(std::memory_order_acquire);
    const size_t _end = _end.load(std::memory_order_acquire);

    return _begin == _end ;
  }

  /* approximate */ [[nodiscard]] bool _full() const noexcept {
    const size_t _begin = _begin.load(std::memory_order_acquire);
    const size_t _end = _end.load(std::memory_order_acquire);

    return _begin == _increment(_end);
  }

  [[nodiscard]] constexpr size_t capacity() const noexcept {
    return Capacity;
  }

private:
  static constexpr size_t _increment(size_t i) noexcept {
    return (i + 1) & (Capacity - 1);
  }

private:
  /*
  * _begin: stored only by a consumer thread, so: - the consumer thread may read it as `relaxed` order
  *                                              - other threads have to read it as `acquire` order
  */
  std::atomic<size_t> _begin{0};

  /*
   * _end: stored only by a producer thread, so: - the producer thread may read it as `relaxed` order
   *                                              - other threads have to read it as `acquire` order
   */
  std::atomic<size_t> _end{0};
  
  std::array<T, Capacity> _buffer{};
};