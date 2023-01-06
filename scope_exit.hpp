/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_SCOPE_EXIT_HPP__
#define __CXX_DOJO_SCOPE_EXIT_HPP__

#include <iostream>
#include <type_traits>

template<typename F>
struct scope_exit {
private:
  F m_function;
  bool m_doIt;

private:
  scope_exit(scope_exit const&) = delete;

  scope_exit& operator=(scope_exit const&) = delete;
  scope_exit& operator=(scope_exit&&) = delete;

public:
  explicit scope_exit(F&& f) noexcept(noexcept(std::move(f)))
      : m_function(std::move(f))
      , m_doIt(true) {
  }

  scope_exit(scope_exit&& other) noexcept(noexcept(std::move(other.m_function)))
      : m_function(std::move(other.m_function))
      , m_doIt(other.m_doIt) {
    other.release();
  }

  ~scope_exit() noexcept(noexcept(m_function())) {
    if(m_doIt) {
      m_function();
    }
  }

  void release() noexcept {
    m_doIt = false;
  }
};

template<typename F>
scope_exit<typename std::remove_reference<F>::type> make_scope_exit(F&& f) {
  return scope_exit<typename std::remove_reference<F>::type>(std::forward<F>(f));
}

#endif
