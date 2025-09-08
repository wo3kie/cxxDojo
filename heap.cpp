/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 heap.cpp -o heap
 *
 * Usage:
 *      $ ./heap
 */

#include <algorithm>
#include <vector>

/*
 * Simple implementation of a heap using STL algorithms
 */

template<typename T>
struct Heap1 {
  void push(T const& t) {
    data_.push_back(t);
    std::make_heap(data_.begin(), data_.end());
  }

  T const& top() const {
    return data_.front();
  }

  void pop() {
    std::pop_heap(data_.begin(), data_.end());
    std::move(data_.back());
    data_.pop_back();
  }

  bool empty() const {
    return data_.empty();
  }

  std::vector<T> data_;
};

/*
 * Hand made implementation of a heap
 */

template<typename T>
struct Heap2 {
  void push(T const& t) {
    data_.push_back(t);
    heapifyUp(data_, data_.size() - 1);
  }

  T const& top() const {
    return data_.front();
  }

  void pop() {
    std::swap(data_.front(), data_.back());
    data_.pop_back();
    heapifyDown(data_, 0);
  }

  bool empty() const {
    return data_.empty();
  }

private:
  static void heapifyUp(std::vector<T>& data, int currentIndex) {
    for(; currentIndex != 0; currentIndex /= 2) {
      int const parentIndex = getParentIndex(currentIndex);

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
      int const leftChildIndex = getLeftChildIndex(currentIndex);

      if(leftChildIndex >= data.size()) {
        return;
      }

      T& current = data[currentIndex];
      T& leftChild = data[leftChildIndex];

      int maxItemIndex = currentIndex;

      if(leftChild > current) {
        maxItemIndex = leftChildIndex;
      }

      int const rightChildIndex = getRightChildIndex(currentIndex);

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

  std::vector<T> data_;
};

#include <cassert>
#include <iostream>

void test_Heap1() {
  Heap1<int> heap;

  heap.push(2);
  heap.push(1);
  heap.push(3);
  heap.push(5);
  heap.push(4);

  assert(heap.top() == 5);
  heap.pop();

  assert(heap.top() == 4);
  heap.pop();

  assert(heap.top() == 3);
  heap.pop();

  assert(heap.top() == 2);
  heap.pop();

  assert(heap.top() == 1);
  heap.pop();

  assert(heap.empty() == true);
}

void test_Heap2() {
  Heap2<int> heap;

  heap.push(2);
  heap.push(1);
  heap.push(3);
  heap.push(5);
  heap.push(4);

  assert(heap.top() == 5);
  heap.pop();

  assert(heap.top() == 4);
  heap.pop();

  assert(heap.top() == 3);
  heap.pop();

  assert(heap.top() == 2);
  heap.pop();

  assert(heap.top() == 1);
  heap.pop();

  assert(heap.empty() == true);
}

int main() {
  test_Heap1();
  test_Heap2();
}
