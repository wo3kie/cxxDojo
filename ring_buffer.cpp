/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/queue
 */

#include "./ring_buffer.hpp"
#include "./assert.hpp"
#include "./ring_buffer_mutex.hpp"
#include "./ring_buffer_spsc.hpp"
#include "./timer.hpp"

#include <iostream>
#include <numeric>
#include <random>

/*
 * test_ring_buffer_random
 */

template<typename TRBuffer>
size_t test_ring_buffer_random() {
  const size_t N = 100 * TRBuffer::capacity();

  TRBuffer rBuffer;

  std::atomic<size_t> counter{0};
  std::atomic<bool> producer_done{false};

  std::thread producer([&] {
    for(size_t i = 1; i <= N; ++i) {
      while(! rBuffer.push(i)) {
        std::this_thread::yield();
      }
    }

    producer_done.store(true, std::memory_order_release);
  });

  std::thread consumer([&] {
    typename TRBuffer::value_type v;

    while(true) {
      if(rBuffer.pop(v)) {
        counter.fetch_add(1, std::memory_order_relaxed);

        if (v == N) {
          break;
        } else {
          continue;
        }

        continue;
      }

      std::this_thread::yield();
    }
  });

  producer.join();
  consumer.join();

  return counter.load(std::memory_order_relaxed);
}

/*
 * test_ring_buffer
 */

template<typename TRBuffer>
void test_ring_buffer() {
  size_t N = TRBuffer::capacity();
  size_t result = test_ring_buffer_random<TRBuffer>();

  std::cout << demangle(typeid(TRBuffer).name()) << ": " << result << "/" << 100 * N << ": " << (100 * N == result ? "OK" : "Failed") << std::endl;
}

/*
 * main
 */

int main() {
  timer([](){test_ring_buffer_random<RingBufferSPSC<int, 2>>()});
  timer([](){test_ring_buffer_random<RingBufferSPSC<int, 4>>()});
  timer([](){test_ring_buffer_random<RingBufferSPSC<int, 8>>()});
  timer([](){test_ring_buffer_random<RingBufferSPSC<int, 1024>>()});
  timer([](){test_ring_buffer_random<RingBufferSPSC<int, 32*1024>>()});
  timer([](){test_ring_buffer_random<RingBuffer<int, 2>>()});
  timer([](){test_ring_buffer_random<RingBuffer<int, 4>>()});
  timer([](){test_ring_buffer_random<RingBuffer<int, 8>>()});
  timer([](){test_ring_buffer_random<RingBuffer<int, 1024>>()});
  timer([](){test_ring_buffer_random<RingBuffer<int, 32*1024>>()});
  timer([](){test_ring_buffer_random<RingBufferMT<int, 2>>()});
  timer([](){test_ring_buffer_random<RingBufferMT<int, 4>>()});
  timer([](){test_ring_buffer_random<RingBufferMT<int, 8>>()});
  timer([](){test_ring_buffer_random<RingBufferMT<int, 1024>>()});
  timer([](){test_ring_buffer_random<RingBufferMT<int, 32*1024>>()});
}
