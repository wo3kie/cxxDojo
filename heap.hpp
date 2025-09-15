#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <algorithm>
#include <vector>

namespace stl {

/*
 * Simple implementation of a heap using STL algorithms
 */

template<typename T>
struct Heap {
  void push(const T& t) {
    _data.push_back(t);
    std::make_heap(_data.begin(), _data.end());
  }

  const T& top() const {
    return _data.front();
  }

  void pop() {
    std::pop_heap(_data.begin(), _data.end());
    _data.pop_back();
  }

  bool empty() const {
    return _data.empty();
  }

private:
  std::vector<T> _data;
};

} // namespace stl

namespace cxxdojo {

/*
 * Hand made implementation of a heap
 */

template<typename T>
struct Heap {
  void push(const T& t) {
    _data.push_back(t);
    heapifyUp(_data, _data.size() - 1);
  }

  const T& top() const {
    return _data.front();
  }

  void pop() {
    std::swap(_data.front(), _data.back());
    _data.pop_back();
    heapifyDown(_data, 0);
  }

  bool empty() const {
    return _data.empty();
  }

private:
  static void heapifyUp(std::vector<T>& data, int currentIndex) {
    for(; currentIndex != 0; currentIndex /= 2) {
      const int parentIndex = getParentIndex(currentIndex);

      T& current = data[currentIndex];
      T& parent = data[parentIndex];

      if(parent >= current) {
        return;
      }

      std::swap(current, parent);
    }
  }

  static void heapifyDown(std::vector<T>& data, int currentIndex) {
    while(true) {
      const int leftChildIndex = getLeftChildIndex(currentIndex);

      if(leftChildIndex >= data.size()) {
        return;
      }

      T& current = data[currentIndex];
      T& leftChild = data[leftChildIndex];

      int maxItemIndex = currentIndex;

      if(leftChild > current) {
        maxItemIndex = leftChildIndex;
      }

      const int rightChildIndex = getRightChildIndex(currentIndex);

      if(rightChildIndex < data.size()) {
        T& rightChild = data[rightChildIndex];

        if(rightChild > leftChild) {
          maxItemIndex = rightChildIndex;
        }
      }

      if(maxItemIndex == currentIndex) {
        return;
      }

      std::swap(data[maxItemIndex], data[currentIndex]);

      currentIndex = maxItemIndex;
    }
  }

  static int getParentIndex(int index) {
    return index == 0 ? 0 : (index - 1) / 2;
  }

  static int getLeftChildIndex(int index) {
    return 2 * index + 1;
  }

  static int getRightChildIndex(int index) {
    return 2 * index + 2;
  }

private:
  std::vector<T> _data;
};

} // namespace cxxdojo
