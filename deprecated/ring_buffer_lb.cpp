/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <atomic>
#include <cmath>
#include <future>
#include <iostream>

#include "./assert.hpp"
#include "./feq.hpp"
#include "./ring_buffer_lb.hpp"

using Queue = RingBufferLB<int, 4>;

void producer(Queue& queue, std::size_t count, std::atomic<bool>& all_done) {
  std::size_t inserted = 0;

  do {
    if (queue.push(static_cast<int>(inserted))) {
      ++inserted;
    } 
  } while (inserted < count);

  all_done = true;
}

std::size_t consumer(Queue& queue, std::size_t id, std::atomic<bool>& all_done) {
  std::size_t count = 0;
  int value;

  while (true) {
    if (queue.pop(value, id)) {
      ++count;
    } else if (all_done) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

      if (queue.pop(value, id)) {
        ++count;
      } else {
        break;
      }
    }
  }

  return count;
}

void test_load_balancer(std::size_t N) {
  Queue queue;
  std::atomic<bool> all_done{false};

  std::future<void> producer_future = std::async(producer, std::ref(queue), N, std::ref(all_done));

  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  std::future<std::size_t> consumer_future1 = std::async(consumer, std::ref(queue), 0, std::ref(all_done));
  std::future<std::size_t> consumer_future2 = std::async(consumer, std::ref(queue), 1, std::ref(all_done));
  std::future<std::size_t> consumer_future3 = std::async(consumer, std::ref(queue), 2, std::ref(all_done));
  std::future<std::size_t> consumer_future4 = std::async(consumer, std::ref(queue), 3, std::ref(all_done));

  producer_future.get();
  std::size_t count1 = consumer_future1.get();
  std::size_t count2 = consumer_future2.get();
  std::size_t count3 = consumer_future3.get(); 
  std::size_t count4 = consumer_future4.get(); 

  auto symm_diff = [](std::size_t a, std::size_t b) -> std::size_t {
    return (a > b) ? (a - b) : (b - a);
  };

  Assert(symm_diff(N/4, count1) == approx<int>(0, 0.1 * N));
  Assert(symm_diff(N/4, count2) == approx<int>(0, 0.1 * N));
  Assert(symm_diff(N/4, count3) == approx<int>(0, 0.1 * N));
  Assert(symm_diff(N/4, count4) == approx<int>(0, 0.1 * N));

  Assert(N == (count1 + count2 + count3 + count4));
}

int main(){
  test_load_balancer(100'000);
  // test_load_balancer(1'000'000);
}
