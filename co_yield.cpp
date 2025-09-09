/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 -fcoroutines co_yield.cpp -o co_yield
 *
 * Usage:
 *      $ ./co_yield
 *
 * References:
 *      https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html
 */

#include <coroutine>
#include <exception>
#include <iostream>

#define FINAL_SUSPEND_ALWAYS

struct Coroutine {
  struct promise_type {
    Coroutine get_return_object() {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_never initial_suspend() {
      return {};
    }

#ifdef FINAL_SUSPEND_ALWAYS
    std::suspend_always final_suspend() noexcept
#else
    std::suspend_never final_suspend() noexcept
#endif
    {
      return {};
    }

    std::suspend_always yield_value(unsigned v) {
      value = v;
      return {};
    }

    void return_value(unsigned v) {
      value = v;
    }

    // void return_void() {
    //
    // }

    void unhandled_exception() {
      return;
    }

    int value{0};
  };

  std::coroutine_handle<promise_type> handle{};
};

Coroutine coYield() {
  // Coroutine coroutine;
  // Coroutine::promise_type* promise;
  //
  // coroutine = Coroutine::promise_type::get_return_object();
  //
  // if (Coroutine::promise_type::initial_suspend() == std::suspend_always){
  //   return coroutine;
  //   @SUSPEND_1;
  //   @RESUME_1;
  // }

  for(int i = 0; i < 40; i += 10) {
    // Coroutine::promise_type::yield_value(i);
    // @SUSPEND_n;
    // @RESUME_n;
    // coroutine_handle::resume();
    co_yield i;
  }

  // Coroutine::promise_type::return_value(40);
  // Coroutine::promise_type::final_suspend();

#ifdef FINAL_SUSPEND_ALWAYS
  // empty
#else
  // coroutine.handle.destroy();
#endif

  co_return 40;
}

int main() {
  {
    Coroutine coroutine = coYield();

    for(int i = 0; i < 4; ++i) {
      std::cout << "In main function (coYield): " << coroutine.handle.promise().value << std::endl;
      coroutine.handle.resume();
    }

    std::cout << "In main function (coReturn): " << coroutine.handle.promise().value << std::endl;

#ifdef FINAL_SUSPEND_ALWAYS
    coroutine.handle.destroy();
#else
    // empty
#endif
  }
}
