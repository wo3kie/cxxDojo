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

#include "./task_worker.hpp"

#pragma once

#include <future>
#include <type_traits>
#include <utility>

template<std::size_t QueueSize, typename IdlePolicy = YieldIdlePolicy>
class TaskExecutor
{
private:
  using Task = std::packaged_task<void()>;
  using Worker = TaskWorkerSPSC<QueueSize, Task, IdlePolicy>;

public:
  TaskExecutor() = default;
  TaskExecutor(TaskExecutor&&) = delete;
  TaskExecutor(const TaskExecutor&) = delete;

  ~TaskExecutor() = default;

  TaskExecutor& operator=(TaskExecutor&&) = delete;
  TaskExecutor& operator=(const TaskExecutor&) = delete;

public:
  template<typename F>
  auto submit(F&& f) -> std::future<std::invoke_result_t<F>>
  {
    using R = std::invoke_result_t<F>;

    Assert(_worker.state() == Worker::WorkerState::Running);

    std::packaged_task<R()> pt{std::forward<F>(f)};
    std::future<R> future = pt.get_future();

    Task task{[pt = std::move(pt)]() mutable {
      pt();
    }};

    while(! _worker.push(std::move(task))) {
      IdlePolicy::doIt();
    }

    return future;
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
  Worker _worker;
};
