#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cpp-dojo
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <future>
#include <type_traits>
#include <utility>

#include "./task_worker.hpp"

template<std::size_t QueueSize, typename IdlePolicy = YieldIdlePolicy>
class TaskExecutorSPSC
{
public:
  TaskExecutorSPSC() = default;

  TaskExecutorSPSC(TaskExecutorSPSC&&) = delete;
  TaskExecutorSPSC(const TaskExecutorSPSC&) = delete;

  TaskExecutorSPSC& operator=(TaskExecutorSPSC&&) = delete;
  TaskExecutorSPSC& operator=(const TaskExecutorSPSC&) = delete;

public:
  template<typename F, typename... TArgs>
  auto submit(F&& f, TArgs&&... args) -> std::future<std::invoke_result_t<std::decay_t<F>, std::decay_t<TArgs>...>>
  {
    using TResult = std::invoke_result_t<std::decay_t<F>, std::decay_t<TArgs>...>;

    std::packaged_task<TResult()> task([fn = std::forward<F>(f), ... task_args = std::forward<TArgs>(args)]() mutable -> TResult {
      return std::invoke(std::move(fn), std::move(task_args)...);
    });

    std::future<TResult> result = task.get_future();

    std::packaged_task<void()> queue_task([task = std::move(task)]() mutable {
      task();
    });

    while(! _worker.push(std::move(queue_task))) {
      IdlePolicy::doIt();
    }

    return result;
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
  TaskWorkerSPSC<QueueSize, std::packaged_task<void()>, IdlePolicy> _worker;
};
