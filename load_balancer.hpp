#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <array>
#include <functional>
#include <thread>

#include "./assert.hpp"
#include "./ring_buffer_spsc.hpp"

/*
 * Single Producer, Multiple Consumer/Worker Load Balancer
 */

template<
  typename TValue, //
  size_t NumBuffers,
  size_t Capacity = NumBuffers
>
struct LoadBalancer {
public:
  using value_type = TValue;

public:
  LoadBalancer() = default;

  LoadBalancer(LoadBalancer&&) = delete;
  LoadBalancer(const LoadBalancer&) = delete;

  ~LoadBalancer() = default;

  LoadBalancer& operator=(LoadBalancer&&) = delete;
  LoadBalancer& operator=(const LoadBalancer&) = delete;

public:
  bool push(const TValue& value, size_t queue_id) {
    assert(queue_id < NumBuffers);

    if(_buffers[queue_id].push(value)) {
      return true;
    } else {
      return false;
    }
  }

  bool push(const TValue& value) {
    for(size_t i = 0; i < NumBuffers; ++i) {
      const size_t index = _increment(_round_robin_push_id);

      if (push(value, _index(index))) {
        return true;
      }
    }

    return false;
  }

  bool pop(TValue& out, size_t consumer_id) {
    assert(consumer_id < NumBuffers);

    if(_buffers[consumer_id].pop(out)) {
      return true;
    } else {
      return false;
    }
  }

  bool pop(TValue& out) {
     for(size_t i = 0; i < NumBuffers; ++i) {
      const size_t index = _increment(_round_robin_pop_id);

      if (pop(out, _index(index))) {
        return true;
      }
    }

    return false;
  }

  auto pop_factory(size_t consumer_id) {
    assert(consumer_id < NumBuffers);

    return [this, consumer_id](TValue& out) {
      return pop(out, consumer_id);
    };
  }

  [[nodiscard]] static constexpr size_t capacity() noexcept {
    return Capacity;
  }

  [[nodiscard]] static constexpr size_t num_buffers() noexcept {
    return NumBuffers;
  }

private:
  static constexpr size_t _index(size_t id) noexcept {
    if constexpr (NumBuffers & (NumBuffers - 1)) {
      return id % NumBuffers;
    } else {
      return id & (NumBuffers - 1);
    }
  }

  static size_t _increment(std::atomic<size_t>& counter) noexcept {
    return counter.fetch_add(1, std::memory_order_relaxed);
  }

private:
  alignas(64) std::atomic<size_t> _round_robin_push_id{0};
  alignas(64) std::atomic<size_t> _round_robin_pop_id{0};

  std::array<RingBufferSPSC<TValue, Capacity>, NumBuffers> _buffers;
};
