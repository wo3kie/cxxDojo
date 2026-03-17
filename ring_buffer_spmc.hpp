#pragma once

/*
 * Project:
 *      CxxDojo (www.github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (www.lukaszczerwinski.pl)
 */

#include <atomic>
#include <cstddef>
#include <utility>

template<typename TValue, std::size_t Capacity>
class RingBufferSPMC {
  static_assert(Capacity >= 2, "Capacity must be at least 2");
  static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be a power of two");

public:
  using value_type = TValue;

public:
  RingBufferSPMC() noexcept
      : _pushed(0)
      , _popped(0) {
  }

  RingBufferSPMC(RingBufferSPMC&&) = delete;
  RingBufferSPMC(const RingBufferSPMC&) = delete;

  ~RingBufferSPMC() = default;

  RingBufferSPMC& operator=(RingBufferSPMC&&) = delete;
  RingBufferSPMC& operator=(const RingBufferSPMC&) = delete;

public:
  template<typename TT>
  bool push(TT&& value) noexcept {
    const std::size_t popped = _popped.load(std::memory_order_acquire);
    const std::size_t pushed = _pushed.load(std::memory_order_relaxed);

    if(_full(pushed, popped)) {
      return false;
    }

    const std::size_t index = _index(pushed);
    _buffer[index] = std::forward<TT>(value);

    _pushed.store(pushed + 1, std::memory_order_release);
    return true;
  }

  bool pop(TValue& out) noexcept {
    std::size_t popped = _popped.load(std::memory_order_acquire);

    while(true) {
      const std::size_t pushed = _pushed.load(std::memory_order_acquire);

      if(_empty(pushed, popped)) {
        return false;
      }

      const std::size_t new_popped = popped + 1;

      if(_popped.compare_exchange_weak(popped, new_popped, std::memory_order_acquire, std::memory_order_relaxed)) {
        const std::size_t index = _index(popped);
        out = std::move(_buffer[index]);
        return true;
      }
    }
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept {
    return Capacity;
  }
  
  [[nodiscard]] static constexpr size_t _index(size_t i) noexcept {
    return i & (Capacity - 1);
  }

  /* approximate */ [[nodiscard]] bool _empty(size_t pushed, size_t popped) const noexcept {
    return popped >= pushed;
  }

  /* approximate */ [[nodiscard]] bool _empty() const noexcept {
    const size_t pushed = _pushed.load(std::memory_order_acquire);
    const size_t popped = _popped.load(std::memory_order_acquire);

    return _empty(pushed, popped);
  }

  /* approximate */ [[nodiscard]] bool _full(size_t pushed, size_t popped) const noexcept {
    return (pushed - popped) >= Capacity;
  }

  /* approximate */ [[nodiscard]] bool _full() const noexcept {
    const size_t pushed = _pushed.load(std::memory_order_acquire);
    const size_t popped = _popped.load(std::memory_order_acquire);

    return _full(pushed, popped);
  }

  /* extension */ [[nodiscard]] TValue pop() {
    TValue out;
   
    if(pop(out) == false) {
      throw std::runtime_error("Buffer is empty");
    }

    return out;
  }

private:
  alignas(64) std::atomic<std::size_t> _pushed; 
  alignas(64) std::atomic<std::size_t> _popped;
  alignas(64) TValue _buffer[Capacity];
};