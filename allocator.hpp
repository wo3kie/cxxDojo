#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <limits>

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

  Allocator() = default;

  template<typename U>
  Allocator(const Allocator<U>&){};

  static pointer allocate(size_type n, const void* = 0) {
    return static_cast<pointer>(::operator new(n * sizeof(T)));
  }

  static void deallocate(pointer p, size_type) {
    ::operator delete(p);
  }

  bool operator==(const Allocator&) const {
    return true;
  }

  bool operator!=(const Allocator&) const {
    return false;
  }

  /*
   * DEPRECATED IN C++17, REMOVED IN C++20
   * template<typename... Args>
   * static void construct(pointer p, Args&&... args) {
   *   ::new(static_cast<void*>(p)) T(std::forward<Args>(args)...);
   * }
   */

  /*
   * DEPRECATED IN C++17, REMOVED IN C++20
   * static void destroy(pointer p) {
   *   std::destroy_at(p);
   * }
   */

  /*
   * DEPRECATED IN C++17, REMOVED IN C++20
   * static pointer address(reference r) {
   *   return &r;
   * }
   */

  /*
   * DEPRECATED IN C++17, REMOVED IN C++20
   * static const_pointer address(const_reference r) {
   *   return &r;
   * }
   */

  /*
   * DEPRECATED IN C++17, REMOVED IN C++20
   * static size_type max_size() {
   *   return std::numeric_limits<size_type>::max() / sizeof(T);
   * }
   */
};
