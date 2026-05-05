#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <exception>
#include <future>
#include <memory>
#include <optional>
#include <type_traits>
#include <utility>

#include "./assert.hpp"
#include "./task_worker.hpp"

/*
 * Channel
 */

template<class TType>
struct Channel
{
public:
  Channel() = default;

  Channel(Channel&&) = delete;
  Channel(const Channel&) = delete;

  Channel& operator=(Channel&&) = delete;
  Channel& operator=(const Channel&) = delete;

public:
  void set(TType value) 
  {
    _value = std::move(value);
    _ready.store(true, std::memory_order_release);
  }
  
  [[nodiscard]] TType& get(bool yield = true)
  {
    while(! _ready.load(std::memory_order_acquire)) {
      if(yield) {
        std::this_thread::yield();
      }
    }

    return _value;
  }

private:
  TType _value;
  std::atomic<bool> _ready{false};
};

/*
 * TaskExecutor
 */

template<std::size_t QueueSize, typename IdlePolicy = YieldIdlePolicy>
class TaskExecutor
{
public:
  TaskExecutor() = default;
  TaskExecutor(TaskExecutor&&) = delete;
  TaskExecutor(const TaskExecutor&) = delete;

  ~TaskExecutor() = default;

  TaskExecutor& operator=(TaskExecutor&&) = delete;
  TaskExecutor& operator=(const TaskExecutor&) = delete;

public:
  template<class F, typename T>
  bool try_submit(F&& f, Channel<T>& channel)
  {
    assert(_worker.running_approx());
    
    if(_worker.full_approx()) {
      return false;
    }
    
    std::function<void()> task = [f = std::forward<F>(f), &channel]() mutable {
      static_assert(noexcept(f(channel)));
      f(channel);
    };

    assert(_worker.push(std::move(task)));
    return true;
  }

  template<class F, typename T>
  void submit(F&& f, Channel<T>& channel)
  {
    while(!try_submit(std::forward<F>(f), channel)) {
      IdlePolicy::doIt();
    }
  }

  void stop()
  {
    _worker.stop();
  }

  void hard_stop()
  {
    _worker.hard_stop();
  }

private:
  TaskWorkerSPSC<QueueSize, std::function<void()>, IdlePolicy> _worker;
};
