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

enum class WorkerState {
    Running,
    Stopping,
    HardStop
};

struct YieldIdlePolicy
{
  inline static void doIt() noexcept
  {
    std::this_thread::yield();
  }
};

struct SpinIdlePolicy
{
  inline static void doIt() noexcept
  {
  }
};

template<std::size_t QueueSize, typename TTask, typename IdlePolicy = YieldIdlePolicy>
class ThreadWorkerSPSC
{
public:
  ThreadWorkerSPSC()
    : _state(WorkerState::Running)
    , _thread([this]() { this->run(); })
  {
  }

  ~ThreadWorkerSPSC() noexcept
  {
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
  bool push(F&& f)
  {
    if(_state.load(std::memory_order_acquire) != WorkerState::Running) {
      return false;
    }

    return _queue.push(std::forward<F>(f));
  }

  void stop()
  {
    WorkerState expected = WorkerState::Running;
    _state.compare_exchange_strong(expected, WorkerState::Stopping, std::memory_order_release);
  }

  void hard_stop()
  {
      _state.store(WorkerState::HardStop, std::memory_order_release);
  }

private:
void run()
{
    TTask task;

    while(_state.load(std::memory_order_acquire) == WorkerState::Running) {
        if(_queue.pop(task)) {
            task();
            task = TTask();
        } else {
            IdlePolicy::doIt();
        }
    }

    if (_state.load(std::memory_order_acquire) == WorkerState::Stopping) {
        while(_queue.pop(task)) {
            task();
            task = TTask();
        }
    }
}

private:
  std::atomic<WorkerState> _state{WorkerState::Running};
  std::thread _thread;
  RingBufferSPSC<TTask, QueueSize> _queue;
};
