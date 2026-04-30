/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 */

#include "./assert.hpp"
#include "./demangle.hpp"
#include "./timer.hpp"

#include "./ring_buffer.hpp"
#include "./ring_buffer_mutex.hpp"
#include "./ring_buffer_spmc.hpp"
#include "./ring_buffer_spsc.hpp"

#include <iostream>
#include <numeric>
#include <random>

/*
 * test_ring_buffer
 */

template<size_t P /* Producers */, size_t C /* Consumers */, typename TRBuffer>
void test_ring_buffer() {
  static_assert(P > 0 && C > 0);

  constexpr size_t K = 100 * TRBuffer::capacity();
  constexpr size_t TOTAL = P * K;

  TRBuffer rBuffer;

  std::atomic<size_t> produced_total{0};
  std::atomic<size_t> consumed_total{0};

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

  for(auto& t : producers) {
    t.join();
  }
    
  for(auto& t : consumers) {
    t.join();
  }

  Assert(consumed_total.load(std::memory_order_relaxed) == TOTAL)
      .on_error([](const char* file, int line, const char* op, const auto& actual, const auto& expected) {
        std::cerr << "Assertion failed: actual: " << actual << ", "
                  << "expected: " << expected << " "
                  << "on " << demangle(typeid(TRBuffer).name()) << std::endl;
      });
}

/*
 * main
 */

int main() {
  timer([]() {
    test_ring_buffer<1, 1, RingBuffer<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBuffer<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<1, 1, RingBufferSPSC<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPSC<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<1, 4, RingBufferSPMC<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPMC<int, 2>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<4, 1, RingBufferMT<int, 2>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferMT<int, 2>: " << fmt << std::endl << std::endl;
  });

  timer([]() {
    test_ring_buffer<1, 1, RingBuffer<int, 1023>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBuffer<int, 1023>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<1, 1, RingBufferSPSC<int, 1023>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPSC<int, 1023>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<1, 4, RingBufferSPMC<int, 1023>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferSPMC<int, 1023>: " << fmt << std::endl;
  });

  timer([]() {
    test_ring_buffer<4, 1, RingBufferMT<int, 1023>>();
  }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "RingBufferMT<int, 1023>: " << fmt << std::endl;
  });
}
