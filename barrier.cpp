/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 barrier.cpp -o barrier
 *
 * Usage:
 *      $ ./barrier
 *      hello thread...hello thread...hello thread...00
 *
 *      hello thread...0
 *      1
 *      hello thread...1
 *      hello thread...0
 *      hello thread...0
 *      hello thread...0
 */

#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

class barrier {
public:
  barrier(unsigned threshold)
      : m_threshold(threshold)
      , m_local(0)
      , m_global(0) {
  }

  bool wait() {
    std::unique_lock<std::mutex> lock(m_mutex);

    const unsigned oldGlobal = m_global;

    if(++m_local == m_threshold) {
      m_local = 0;
      m_global += 1;

      m_condition.notify_all();

      return true;
    }

    m_condition.wait(lock, [oldGlobal, this]() {
      return oldGlobal != m_global;
    });

    return false;
  }

private:
  const unsigned m_threshold;

  unsigned m_local;
  unsigned m_global;

  std::mutex m_mutex;
  std::condition_variable m_condition;
};

void thread_impl(barrier& b) {
  while(true) {
    std::cout << "hello thread..." << b.wait() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}

int main() {
  barrier b(4);

  std::vector<std::thread> threads;

  for(int i = 0; i < 4; ++i) {
    threads.push_back(std::move(std::thread(std::bind(&thread_impl, std::ref(b)))));
  }

  for(int i = 0; i < 4; ++i) {
    threads[i].join();
  }
}
