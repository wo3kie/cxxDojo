#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <limits>

template<typename T>
struct Allocator {
  typedef T* pointer;
  typedef const T* const_pointer;

  typedef T& reference;
  typedef const T& const_reference;

  typedef T value_type;

  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  template<typename U>
  struct rebind {
    typedef Allocator<U> other;
  };

  Allocator() {
  }

  template<typename U>
  Allocator(const Allocator<U>&) {
  }

  static pointer allocate(size_type n, const void* = 0) {
    return (pointer) new char[n * sizeof(T)];
  }

  static void deallocate(const pointer p, const size_type) {
    delete[] p;
  }

  static void construct(pointer p, const_reference t) {
    new((void*)p) T(t);
  }

  static void destroy(pointer p) {
    p->~T();
  }

  static pointer address(reference r) {
    return &r;
  }

  static const_pointer address(const_reference r) {
    return &r;
  }

  static size_type max_size() {
    return (std::numeric_limits<size_type>::max)();
  }

  bool operator==(const Allocator&) const {
    return true;
  }

  bool operator!=(const Allocator&) const {
    return false;
  }
};
