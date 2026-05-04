#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <array>
#include <functional>
#include <optional>
#include <thread>

#include "./assert.hpp"
#include "./ring_buffer_spsc.hpp"

/*
 * RingBuffer Load Balancer (RingBufferLB) is a single-producer multi-consumer queue.
 */

template<
  typename TValue, //
  std::size_t NumBuffers,
  std::size_t Capacity = NumBuffers * NumBuffers
>
struct RingBufferLB {
public:
  using value_type = TValue;

public:
  RingBufferLB() = default;

  RingBufferLB(RingBufferLB&&) = delete;
  RingBufferLB(const RingBufferLB&) = delete;

  ~RingBufferLB() = default;

  RingBufferLB& operator=(RingBufferLB&&) = delete;
  RingBufferLB& operator=(const RingBufferLB&) = delete;

public:
  bool push(const TValue& value, std::size_t queue_id) {
    assert(queue_id < NumBuffers);

    if(_buffers[queue_id].push(value)) {
      return true;
    } else {
      return false;
    }
  }

  bool push(const TValue& value) {
    for(std::size_t i = 0; i < NumBuffers; ++i) {
      const std::size_t index = _index(_increment(_round_robin_push_id));

      if (push(value, index)) {
        return true;
      }
    }

    return false;
  }

  bool pop(TValue& out, std::size_t consumer_id) {
    assert(consumer_id < NumBuffers);

    if(_buffers[consumer_id].pop(out)) {
      return true;
    } else {
      return false;
    }
  }

  bool pop(TValue& out) {
     for(std::size_t i = 0; i < NumBuffers; ++i) {
      const std::size_t index = _index(_increment(_round_robin_pop_id));

      if (pop(out, index)) {
        return true;
      }
    }

    return false;
  }

  auto pop_factory(std::size_t consumer_id) {
    assert(consumer_id < NumBuffers);

    return [this, consumer_id](TValue& out) {
      return pop(out, consumer_id);
    };
  }

  [[nodiscard]] static constexpr std::size_t capacity() noexcept {
    return Capacity;
  }

  [[nodiscard]] static constexpr std::size_t num_buffers() noexcept {
    return NumBuffers;
  }

private:
  static constexpr std::size_t _index(std::size_t id) noexcept {
    if constexpr (NumBuffers & (NumBuffers - 1)) {
      return id % NumBuffers;
    } else {
      return id & (NumBuffers - 1);
    }
  }

  static std::size_t _increment(std::atomic<std::size_t>& counter) noexcept {
    return counter.fetch_add(1, std::memory_order_relaxed);
  }

private:
  alignas(64) std::atomic<std::size_t> _round_robin_push_id{0};
  alignas(64) std::atomic<std::size_t> _round_robin_pop_id{0};

  std::array<RingBufferSPSC<TValue, Capacity>, NumBuffers> _buffers;
};
