/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 -fcoroutines co_transform.cpp -o co_yield
 *
 * Usage:
 *      $ ./co_transform
 *
 * References:
 *      https://www.youtube.com/watch?v=8sEe-4tig_A
 */

#include <coroutine>
#include <exception>
#include <iostream>

using namespace std::literals;

template<typename Out, typename In>
struct Coroutine {
public:
  struct promise_type {
    Out out{};
    In in{};

    Coroutine get_return_object() {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_always initial_suspend() noexcept {
      return {};
    }

    std::suspend_always final_suspend() noexcept {
      return {};
    }

    std::suspend_always yield_value(Out o) noexcept {
      out = std::move(o);
      return {};
    }

    void return_value(Out o) noexcept {
      out = std::move(o);
    }

    auto await_transform(Out /* overload */) noexcept {
      struct awaiter {
        promise_type& promise;

        constexpr bool await_ready() const noexcept {
          return true;
        }

        In await_resume() const noexcept {
          return std::move(promise.in);
        }

        void await_suspend(std::coroutine_handle<>) const noexcept {
          return;
        }
      };

      return awaiter{*this};
    }

    void unhandled_exception() noexcept {
      return;
    }
  };

public:
  std::coroutine_handle<promise_type> handle{};

public:
  Out getFrom() {
    if(handle.done() == false){
      handle.resume();
    }

    return handle.promise().out;
  }

  void sendTo(In s) {
    handle.promise().in = s;

    if(handle.done() == false){
      handle.resume();
    }
  }
};

Coroutine<std::string, std::string> chat() {
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

  // Coroutine::promise_type::yield_value("Hello!\n"s);
  // @SUSPEND_n;
  // @RESUME_n;
  // coroutine_handle::resume();
  co_yield "Hello!\n"s;

  // Coroutine::promise_type::await_transform( std::string{} );
  //
  // if (Coroutine::promise_type::await_transform::awaiter::await_ready() == true){
  //   promise = Coroutine::promise_type::await_transform::awaiter::await_resume();
  // } else if (Coroutine::promise_type::await_transform::awaiter::await_suspend(coroutine.handle) == false){
  //   promise = Coroutine::promise_type::await_transform::awaiter::await_resume();
  // } else {
  //   return coroutine;
  //   @SUSPEND_n;
  //   @RESUME_n;
  //   promise = Coroutine::promise_type::await_transform::awaiter::await_resume();
  // }
  std::cout << co_await std::string{};

  co_return "Here!\n"s;
}

int main() {
  auto coroutine = chat();

  std::cout << coroutine.getFrom();
  coroutine.sendTo("Where are you?\n"s);
  std::cout << coroutine.getFrom();
}
