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
#include <cstring>
#include <optional>
#include <thread>
#include <utility>

#include <pthread.h>

#include "./ring_buffer_spsc.hpp"

static constexpr std::size_t NoAffinity = std::numeric_limits<std::size_t>::max();

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
public:
  enum class WorkerState
  {
    Running,
    Stopping,
    HardStop
  };

public:
  explicit TaskWorkerSPSC(std::size_t cpuAffinity = NoAffinity)
    : _thread([this, cpuAffinity]() { this->_run(cpuAffinity); })
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

  /* approximate */ [[nodiscard]] bool running_approx() const noexcept
  {
    return _state.load(std::memory_order_acquire) == WorkerState::Running;
  }

  /* approximate */ [[nodiscard]] bool empty_approx() const noexcept
  {
    return _queue.empty_approx();
  }

  /* approximate */ [[nodiscard]] bool full_approx() const noexcept
  {
    return _queue.full_approx();
  }

private:
  void _setThreadAffinity(std::size_t cpuAffinity) const noexcept
  {
    if (cpuAffinity == NoAffinity) {
      return;
    }

    if (cpuAffinity >= std::thread::hardware_concurrency()) {
      return;
    }

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpuAffinity, &cpuset);
   
    if(pthread_t thread = pthread_self(); pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset) != 0) {
      // Failed to set thread affinity, continue anyway.
    }
  }

  void _run(std::size_t cpuAffinity)
  {
    _setThreadAffinity(cpuAffinity);
    _run();
  }

  void _run()
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
