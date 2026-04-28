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
#include <stdexcept>
#include <utility>

template<typename TValue, std::size_t Capacity>
class RingBufferSPMC
{
  template<typename T>
  struct alignas(64) Padded
  {
    T value;
  };

  static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be equal to 2^N");
  static_assert(sizeof(TValue) <= 64, "TValue must be less equal than 64 bytes");

public:
  using value_type = TValue;

public:
  RingBufferSPMC() noexcept
    : _pushed(0)
    , _popped(0)
    , _claim(0)
  {
  }

  RingBufferSPMC(RingBufferSPMC&&) = delete;
  RingBufferSPMC(const RingBufferSPMC&) = delete;

  ~RingBufferSPMC() = default;

  RingBufferSPMC& operator=(RingBufferSPMC&&) = delete;
  RingBufferSPMC& operator=(const RingBufferSPMC&) = delete;

public:
  template<typename TT>
  bool push(TT&& value) noexcept
  {
    const std::size_t popped = _popped.load(std::memory_order_acquire);
    const std::size_t pushed = _pushed.load(std::memory_order_relaxed);

    if(_full(pushed, popped)) {
      return false;
    }

    const std::size_t index = _index(pushed);
    _buffer[index].value = std::forward<TT>(value);

    _pushed.store(pushed + 1, std::memory_order_release);
    return true;
  }

  bool pop(TValue& out) noexcept
  {
    std::size_t claim;

    {
      /*
       * Try to find an item to reserve 
       */

      claim = _claim.load(std::memory_order_acquire);

      while(true) {
        const std::size_t pushed = _pushed.load(std::memory_order_acquire);

        if(claim >= pushed) {
          return false;
        }

        if(_claim.compare_exchange_weak(/* ref */ claim, claim + 1, std::memory_order_acq_rel, std::memory_order_relaxed)) {
          break;
        }
      }
    }

    {
      /* 
       * Take the item out from the buffer 
       */

      const std::size_t index = _index(claim);
      out = std::move(_buffer[index].value);
    }

    {
      /* 
       * Marked the item as popped 
       */

      while(true) {
        /*
         * invariant: assert(_popped <= claim);
         */

        std::size_t claim2 = claim;

        if(_popped.compare_exchange_weak(/* ref */ claim2, claim + 1, std::memory_order_release, std::memory_order_relaxed)) {
          break;
        }
      }
    }

    return true;
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept
  {
    return Capacity;
  }

  [[nodiscard]] static constexpr size_t _index(size_t i) noexcept
  {
    return i & (Capacity - 1);
  }

  /* approximate */ [[nodiscard]] bool _empty(size_t pushed, size_t popped) const noexcept
  {
    return popped >= pushed;
  }

  /* approximate */ [[nodiscard]] bool _empty() const noexcept
  {
    const size_t pushed = _pushed.load(std::memory_order_acquire);
    const size_t popped = _popped.load(std::memory_order_acquire);
    return _empty(pushed, popped);
  }

  /* approximate */ [[nodiscard]] bool _full(size_t pushed, size_t popped) const noexcept
  {
    return (pushed - popped) >= Capacity;
  }

  /* approximate */ [[nodiscard]] bool _full() const noexcept
  {
    const size_t pushed = _pushed.load(std::memory_order_acquire);
    const size_t popped = _popped.load(std::memory_order_acquire);
    return _full(pushed, popped);
  }

  /* extension */ [[nodiscard]] TValue pop()
  {
    TValue out;

    if(pop(out) == false) {
      throw std::runtime_error("Buffer is empty");
    }

    return out;
  }

private:
  alignas(64) std::atomic<std::size_t> _pushed;
  alignas(64) std::atomic<std::size_t> _popped;
  alignas(64) std::atomic<std::size_t> _claim;
  alignas(64) Padded<TValue> _buffer[Capacity];
};