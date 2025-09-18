/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * void_t:
 *      http://en.cppreference.com/w/cpp/types/void_t
 *
 *      "Modern Template Metaprogramming", Walter E. Brown
 *      http://www.youtube.com/watch?v=a0FliKwcwXE
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 void_t.cpp -o void_t
 *
 * Usage:
 *      $ ./void_t
 */

#include <type_traits>
#include <utility>

template<typename...>
using void_t = void;

/*
 * HasMember
 */

template<typename, typename = void_t<>>
struct HasMember_type: std::false_type {};

template<typename T>
struct HasMember_type<T, void_t<typename T::type>>: std::true_type {};

struct S {
  typedef int type;
};

struct T {
  T& operator=(const T&) = delete;
};

void HasMemberTest() {
  static_assert(HasMember_type<S>::value, "");
  static_assert(! HasMember_type<T>::value, "");
}

/*
 * CopyAssignable
 */

template<typename T>
using CopyAssignableT = decltype(std::declval<T&>() = std::declval<const T&>());

template<class T, class = void>
struct CopyAssignable: std::false_type {};

template<class T>
struct CopyAssignable<T, void_t<CopyAssignableT<T>>>: std::is_same<CopyAssignableT<T>, T&>::type {};

void CopyAssignableTest() {
  static_assert(CopyAssignable<S>::value, "");
  static_assert(! CopyAssignable<T>::value, "");
}

/*
 * main
 */

int main() {
}
