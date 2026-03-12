#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstddef>
#include <memory>
#include <stdexcept>

/*
 * Queue
 */

template<typename TValue>
class Queue {
public:
  using value_type = TValue;
  
  explicit Queue(size_t capacity)
      : _capacity(capacity) 
      , _head(0)
      , _size(0)  
  {
    _queue = std::make_unique<TValue[]>(capacity);
  }

  Queue(Queue&&) = default;
  Queue(const Queue&) = delete;
  
  Queue& operator=(Queue&&) = default;
  Queue& operator=(const Queue&) = delete;

public:
  template<typename TT>
  bool push(TT&& t) {
    if (full()) {
      return false;
    }
    
    _queue[(_head + _size) % _capacity] = std::forward<TT>(t);
    _size += 1;

    return true;
  }

  [[nodiscard]] const TValue& front() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }

    return _queue[_head];
  }

  [[nodiscard]] TValue& front() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }

    return _queue[_head];
  }

  [[nodiscard]] const TValue& back() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }

    return _queue[(_head + _size - 1) % _capacity];
  }

  [[nodiscard]] TValue& back() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }

    return _queue[(_head + _size - 1) % _capacity];
  }

  TValue pop() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }

    TValue result = std::move(_queue[_head]);

    _head = (_head + 1) % _capacity;
    _size -= 1;
    
    return result;
  }

  void clear() {
    _head = 0;
    _size = 0;
  }

  [[nodiscard]] size_t capacity() const noexcept {
    return _capacity;
  }

  [[nodiscard]] size_t size() const noexcept {
    return _size;
  }

  [[nodiscard]] bool empty() const noexcept {
    return size() == 0;
  }

  [[nodiscard]] bool full() const noexcept {
    return size() == _capacity;
  }

private:
  size_t _head;
  size_t _size;

  const size_t _capacity;
  std::unique_ptr<TValue[]> _queue;
};
