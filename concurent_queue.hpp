#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <condition_variable>
#include <mutex>
#include <queue>

/*
 * concurent_queue
 */

template<typename T>
class concurent_queue {
public:
  concurent_queue(unsigned maxCapacity)
      : _maxCapacity(maxCapacity)
      , _size(0) {
  }

  void push(T t) {
    std::unique_lock<std::mutex> lock(_mutex);

    _notFull.wait(lock, [this]() {
      return this->_size + 1 < this->_maxCapacity;
    });

    _queue.push(std::move(t));
    _size += 1;

    _notEmpty.notify_one();
  }

  T get() {
    std::unique_lock<std::mutex> lock(_mutex);

    _notEmpty.wait(lock, [this]() {
      return this->_size > 0;
    });

    _size -= 1;
    T t = _queue.front();
    _queue.pop();

    _notFull.notify_one();

    return t;
  }

private:
  std::mutex _mutex;

  std::condition_variable _notFull;
  std::condition_variable _notEmpty;

  unsigned _size;
  unsigned _maxCapacity;
  std::queue<T> _queue;
};
