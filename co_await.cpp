/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 -fcoroutines co_await.cpp -o co_await
 *
 * Usage:
 *      $ ./co_await
 *
 * References:
 *      https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html
 */

#include <coroutine>
#include <exception>
#include <iostream>

template<typename PromiseT>
struct Awaiter {
  bool await_ready() const noexcept {
    // if it returns true,
    //   co_await DOES NOT suspend the function
    return false;
  }

  bool await_suspend(std::coroutine_handle<PromiseT> h) noexcept {
    // if await_suspend returns void,
    //   control is returned to the caller
    // if await_suspend returns bool,
    //   the value true returns control to the caller
    //   the value false resumes the current coroutine.
    // if await_suspend returns a coroutine handle for some other coroutine,
    //   that handle is resumed
    // if await_suspend throws an exception,
    //   the exception is caught,
    //   the coroutine is resumed,
    //   and the exception is immediately re-thrown.

    PromiseT& promiseRef = h.promise();
    promisePtr = &promiseRef;

    return false;
  }

  PromiseT* await_resume() const noexcept {
    return promisePtr;
  }

  PromiseT* promisePtr{nullptr};
};

struct Coroutine {
  struct promise_type {
    Coroutine get_return_object() {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_never initial_suspend() {
      return {};
    }

    std::suspend_never final_suspend() noexcept {
      return {};
    }

    void unhandled_exception() {
      return;
    }

    int value{0};
  };

  std::coroutine_handle<promise_type> handle{};
};

Coroutine coAwait() {
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

  Coroutine::promise_type* promise = co_await Awaiter<Coroutine::promise_type>{};
  // if (Awaiter::await_ready() == true){
  //   promise = Awaiter<Coroutine::promise_type>::await_resume();
  // } else if (Awaiter<Coroutine::promise_type>::await_suspend(coroutine.handle) == false){
  //   promise = Awaiter<Coroutine::promise_type>::await_resume();
  // } else {
  //   return coroutine;
  //   @SUSPEND_2;
  //   @RESUME_2;
  //   promise = Awaiter<Coroutine::promise_type>::await_resume();
  // }

  for(int i = 0; true; i += 10) {
    promise->value = i;

    co_await std::suspend_always{};
    // if (Awaiter::await_ready() == true){
    //   promise = Awaiter<Coroutine::promise_type>::await_resume();
    // } else if (Awaiter<Coroutine::promise_type>::await_suspend(coroutine.handle) == false){
    //   promise = Awaiter<Coroutine::promise_type>::await_resume();
    // } else {
    //   return coroutine;
    //   @SUSPEND_n;
    //   @RESUME_n;
    //   promise = Awaiter<Coroutine::promise_type>::await_resume();
    // }
  }
}

int main() {
  {
    Coroutine coroutine = coAwait();

    for(int i = 0; i < 3; ++i) {
      std::cout << "In main function (coAwait): " << coroutine.handle.promise().value << std::endl;
      coroutine.handle.resume();
    }

    coroutine.handle.destroy();
  }
}