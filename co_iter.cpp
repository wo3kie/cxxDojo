/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 -fcoroutines co_iter.cpp -o co_iter
 *
 * Usage:
 *      $ ./co_iter
 *
 * References:
 *      https://www.youtube.com/watch?v=8sEe-4tig_A
 */

#include <coroutine>
#include <iostream>
#include <vector>

struct Coroutine {
  struct promise_type {
    std::suspend_never initial_suspend() noexcept {
      return {};
    }

    std::suspend_always final_suspend() noexcept {
      return {};
    }

    void unhandled_exception() noexcept {
      return;
    }

    Coroutine get_return_object() noexcept {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_always yield_value(int i) {
      value = i;
      return {};
    }

    void return_value(int i) {
      value = i;
      return;
    }

    int value{0};
  };

  using Handle = std::coroutine_handle<promise_type>;

  Coroutine(Handle h)
      : handle(h) {
  }

  ~Coroutine() {
    if(handle) {
      handle.destroy();
    }
  }

  bool done() const {
    return handle.done();
  }

  void resume() {
    if(! done()) {
      handle.resume();
    }
  }

  int value() {
    return handle.promise().value;
  }

  struct Iter {
    Handle handle;

    bool operator==(Iter) {
      return handle.done();
    }

    bool operator!=(Iter other) {
      return ! ((*this) == other);
    }

    Iter& operator++() {
      handle.resume();
      return *this;
    }

    int operator*() const {
      return handle.promise().value;
    }
  };

  Iter begin() {
    return Iter{handle};
  }

  Iter end() {
    return Iter{handle};
  }

  Handle handle;
};

Coroutine coro(const std::vector<int>& array1, const std::vector<int>& array2) {
  auto lambda = [](const std::vector<int>& array) -> Coroutine {
    for(int i : array) {
      co_yield i;
    }
  };

  Coroutine c1 = lambda(array1);
  Coroutine c2 = lambda(array2);

  while(c1.done() == false || c2.done() == false) {
    if(c1.done() == false){
      co_yield c1.value();
      c1.resume();
    }

    if(c2.done() == false){
      co_yield c2.value();
      c2.resume();
    }
  }
}

int main() {
  std::vector<int> array1{1, 3, 5};
  std::vector<int> array2{2, 4, 6, 7};
  Coroutine c = coro(array1, array2);

  Coroutine::Iter begin = c.begin();
  Coroutine::Iter end = c.end();

  for(; begin != end; ++begin) {
    std::cout << *begin << std::endl;
  }
}
