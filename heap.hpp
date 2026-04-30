#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <vector>

namespace stl {

/*
 * Simple implementation of a heap using STL algorithms
 */

/*
 * Using `std::greater<T>` would cause the smallest element to appear as the `top()`
 */

template<typename TValue, typename TLess = std::less<TValue>>
struct Heap {
  Heap(TLess compare = TLess())
      : _less(compare) {
  }

  void push(const TValue& t) {
    _data.push_back(t);
    std::push_heap(_data.begin(), _data.end(), _less);
  }

  const TValue& top() const {
    /*
     * Precondition
     */
    Assert(!_data.empty());
    
    return _data.front();
  }

  void pop() {
    /*
     * Precondition
     */
    Assert(!_data.empty());

    std::pop_heap(_data.begin(), _data.end(), _less);
    _data.pop_back();
  }

  [[nodiscard]] bool empty() const {
    return _data.empty();
  }

  [[nodiscard]] size_t size() const {
    return _data.size();
  }

  void clear() {
    _data.clear();
  }

private:
  TLess _less;
  std::vector<TValue> _data;
};

} // namespace stl

namespace cxxdojo {

/*
 * Hand made implementation of a heap
 */

/*
 * Using `std::greater<T>` would cause the smallest element to appear as the `top()`
 */

template<typename TValue, typename TLess = std::less<TValue>>
struct Heap {
  Heap(TLess compare = TLess())
      : _less(compare) {
  }

  void push(const TValue& t) {
    _data.push_back(t);
    heapifyUp(_data, _data.size() - 1);

    /*
     * Postcondition
     */
    Assert(std::is_heap(_data.begin(), _data.end(), _less));
  }

  const TValue& top() const {
    /*
     * Precondition
     */
    Assert(!_data.empty());

    return _data.front();
  }

  void pop() {
    /*
     * Precondition
     */
    Assert(!_data.empty());

    std::swap(_data.front(), _data.back());
    _data.pop_back();
    heapifyDown(_data, 0);

    /*
     * Postcondition
     */
    Assert(std::is_heap(_data.begin(), _data.end(), _less));
  }

  [[nodiscard]] bool empty() const {
    return _data.empty();
  }

  [[nodiscard]] size_t size() const {
    return _data.size();
  }

  void clear() {
    _data.clear();
  }

private:
  void heapifyUp(std::vector<TValue>& data, size_t currentIndex) {
    while(currentIndex != 0) {
      const size_t parentIndex = getParent(currentIndex);

      TValue& current = data[currentIndex];
      TValue& parent = data[parentIndex];

      if(_less(current, parent)) {
        return;
      }

      std::swap(current, parent);
      currentIndex = parentIndex;
    }
  }

  void heapifyDown(std::vector<TValue>& data, size_t current) {
    while(true) {
      size_t max = current;
      size_t left = getLeft(current);
      size_t right = getRight(current);

      if(left < data.size() && _less(data[max], data[left])) {
          max = left;
      }

      if(right < data.size() && _less(data[max], data[right])) {
          max = right;
      }

      if(max == current) {
        return;
      }

      std::swap(data[max], data[current]);
      current = max;
    }
  }

  static size_t getParent(size_t index) {
    Assert(index != 0);
    return (index - 1) / 2;
  }

  static size_t getLeft(size_t index) {
    return 2 * index + 1;
  }

  static size_t getRight(size_t index) {
    return 2 * index + 2;
  }

private:
  TLess _less;
  std::vector<TValue> _data;
};

} // namespace cxxdojo
