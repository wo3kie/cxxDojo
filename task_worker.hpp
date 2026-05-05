#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <atomic>
#include <cassert>
#include <thread>
#include <utility>

#include "./ring_buffer_spsc.hpp"

struct YieldIdlePolicy
{
  static void doIt()
  {
    std::this_thread::yield();
  }
};

template<std::size_t QueueSize, typename TTask, typename IdlePolicy = YieldIdlePolicy>
class TaskWorkerSPSC
{
  enum class WorkerState
  {
    Running,
    Stopping,
    HardStop
  };

public:
  TaskWorkerSPSC()
    : _thread([this]() { this->run(); })
  {
  }

  ~TaskWorkerSPSC() noexcept
  {
    if(_state.load(std::memory_order_relaxed) == WorkerState::Running) {
      _state.store(WorkerState::Stopping, std::memory_order_release);
    }

    if(_thread.joinable()) {
      _thread.join();
    }
  }

  TaskWorkerSPSC(TaskWorkerSPSC&&) = delete;
  TaskWorkerSPSC(const TaskWorkerSPSC&) = delete;

  TaskWorkerSPSC& operator=(TaskWorkerSPSC&&) = delete;
  TaskWorkerSPSC& operator=(const TaskWorkerSPSC&) = delete;

public:
  template<typename F>
  bool push(F&& f)
  {
    assert(_state.load(std::memory_order_relaxed) == WorkerState::Running);
    
    return _queue.push(std::forward<F>(f));
  }

  void stop()
  {
    assert(_state.load(std::memory_order_relaxed) != WorkerState::HardStop);

    _state.store(WorkerState::Stopping, std::memory_order_release);
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
      } else {
        IdlePolicy::doIt();
      }
    }

    while((_state.load(std::memory_order_acquire) == WorkerState::Stopping) && _queue.pop(task)) {
      task();
    }
  }

private:
  std::atomic<WorkerState> _state{WorkerState::Running};
  RingBufferSPSC<TTask, QueueSize> _queue;
  std::thread _thread;
};
