/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 */

#include "./ring_buffer.hpp"
#include "./assert.hpp"
#include "./demangle.hpp"
#include "./ring_buffer_mutex.hpp"
#include "./ring_buffer_spmc.hpp"
#include "./ring_buffer_spsc.hpp"
#include "./timer.hpp"

#include <iostream>
#include <numeric>
#include <random>

/*
 * test_ring_buffer_random
 */

template<typename TRBuffer>
void test_ring_buffer_random_spsc() {
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

        if(v == N) {
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

  Assert(counter.load(std::memory_order_relaxed) == N)
      .on_error([](const char* file, int line, const char* op, const auto& actual, const auto& expected) -> void {
        std::cerr << "Assertion failed: actual: " << actual << ", expected: " << expected << " on " << demangle(typeid(TRBuffer).name()) << std::endl;
      });
}

template<size_t P /* Producers */, size_t C /* Consumers */, typename TRBuffer>
void test_ring_buffer_random_mpmc() {
  static_assert(P > 0 && C > 0);

  constexpr size_t K = 100 * TRBuffer::capacity();
  constexpr size_t TOTAL = P * K;

  TRBuffer rBuffer;

  std::atomic<size_t> produced_total{0};
  std::atomic<size_t> consumed_total{0};

  // --- PRODUCERS ---
  std::vector<std::thread> producers;
  producers.reserve(P);

  for(size_t pid = 0; pid < P; ++pid) {
    producers.emplace_back([&, pid] {
      for(size_t i = 0; i < K; ++i) {
        typename TRBuffer::value_type v = static_cast<typename TRBuffer::value_type>(i + pid * K);

        while(! rBuffer.push(v)) {
          std::this_thread::yield();
        }

        produced_total.fetch_add(1, std::memory_order_relaxed);
      }
    });
  }

  // --- CONSUMERS ---
  std::vector<std::thread> consumers;
  consumers.reserve(C);

  for(size_t cid = 0; cid < C; ++cid) {
    consumers.emplace_back([&] {
      typename TRBuffer::value_type v;

      while(true) {
        if(consumed_total.load(std::memory_order_acquire) == TOTAL) {
          break;
        }

        if(rBuffer.pop(v)) {
          consumed_total.fetch_add(1, std::memory_order_relaxed);
          continue;
        }

        std::this_thread::yield();
      }
    });
  }

  // --- JOIN ---
  for(auto& t : producers)
    t.join();
    
  for(auto& t : consumers)
    t.join();

  // --- ASSERT ---
  Assert(consumed_total.load(std::memory_order_relaxed) == TOTAL)
      .on_error([](const char* file, int line, const char* op, const auto& actual, const auto& expected) {
        std::cerr << "Assertion failed: actual: " << actual << ", "
                  << "expected: " << expected << " "
                  << "on " << demangle(typeid(TRBuffer).name()) << std::endl;
      });
}

template<typename TRBuffer>
void test_ring_buffer_random_spmc() {
  test_ring_buffer_random_mpmc<1, 3, TRBuffer>();
}

/*
 * main
 */

int main() {
  // SPSC

  timer([]() {
    test_ring_buffer_random_spsc<RingBufferMT<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferMT<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spsc<RingBufferSPSC<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPSC<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spsc<RingBuffer<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBuffer<int, 2>: " << fmt << std::endl << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spsc<RingBufferMT<int, 1024>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferMT<int, 1024>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spsc<RingBufferSPSC<int, 1024>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPSC<int, 1024>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spsc<RingBuffer<int, 1024>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBuffer<int, 1024>: " << fmt << std::endl << std::endl;
  });

  // SPMC

  timer([]() {
    test_ring_buffer_random_spmc<RingBufferSPMC<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPMC<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer_random_spmc<RingBufferSPMC<int, 1024>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPMC<int, 1024>: " << fmt << std::endl;
  });
}
