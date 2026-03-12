#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <condition_variable>
#include <mutex>

#include "./queue.hpp"

/*
 * MTQueue
 */

template<typename TValue>
class MTQueue {
public:
  using value_type = TValue;
  
  explicit MTQueue(size_t capacity)
      : _queue(capacity)
  {
  }

  MTQueue(MTQueue&&) = delete;
  MTQueue(const MTQueue&) = delete;
  
  MTQueue& operator=(MTQueue&&) = delete;
  MTQueue& operator=(const MTQueue&) = delete;

public:
  template<typename TT>
  void push(TT&& t) {
    std::unique_lock<std::mutex> lock(_mutex);

    _notFull.wait(lock, [this]() {
      return !this->_queue.full();
    });

    _queue.push(std::forward<TT>(t));
    _notEmpty.notify_one();
  }

  TValue pop() {
    std::unique_lock<std::mutex> lock(_mutex);

    _notEmpty.wait(lock, [this]() {
      return !this->_queue.empty();
    });

    TValue t = std::move(_queue.pop());
    _notFull.notify_one();

    return t;
  }

  [[nodiscard]] size_t capacity() const noexcept {
    return _queue.capacity();
  }

private:
  std::mutex _mutex;

  std::condition_variable _notFull;
  std::condition_variable _notEmpty;

  Queue<TValue> _queue;
};
