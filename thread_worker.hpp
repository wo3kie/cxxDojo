#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <atomic>
#include <thread>
#include <utility>

#include "./ring_buffer_spsc.hpp"

struct YieldIdlePolicy {
  __attribute__((always_inline))
  static void doIt() noexcept {
    std::this_thread::yield();
  }
};

template<std::size_t QueueSize, typename TTask, typename IdlePolicy = YieldIdlePolicy>
class ThreadWorkerSPSC {
public:
  ThreadWorkerSPSC()
      : _running(true)
      , _thread([this]() { this->run(); })
  {
  }

  ~ThreadWorkerSPSC() noexcept {
    stop();

    if(_thread.joinable()) {
      _thread.join();
    }
  }

  ThreadWorkerSPSC(ThreadWorkerSPSC&&) = delete;
  ThreadWorkerSPSC(const ThreadWorkerSPSC&) = delete;
 
  ThreadWorkerSPSC& operator=(ThreadWorkerSPSC&&) = delete;
  ThreadWorkerSPSC& operator=(const ThreadWorkerSPSC&) = delete;

public:
  template<typename F>
  bool push(F&& f) {
    if(! _running.load(std::memory_order_acquire)) {
      return false;
    }

    return _queue.push(std::forward<F>(f));
  }

  void stop() {
    _running.store(false, std::memory_order_release);
  }

private:
  void run() {
    TTask task;

    while(_running.load(std::memory_order_acquire)) {
      if(_queue.pop(task)) {
        task();
      } else {
        IdlePolicy::doIt();
      }
    }

    while(_queue.pop(task)) {
      task();
    }
  }

private:
  std::atomic<bool> _running;
  std::thread _thread;
  RingBufferSPSC<TTask, QueueSize> _queue;
};
