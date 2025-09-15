/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 has_type.cpp -o has_type
 *
 * Usage:
 *      $ ./has_type
 */

#include <cassert>
#include <type_traits>

struct S {};
struct T {
  typedef void type;
};

/*
 * has_type_enum
 */

template<typename T, typename U = void>
struct has_type_enum {
  enum { value = 0 };
};

template<typename T>
struct has_type_enum<T, typename T::type> {
  enum { value = 1 };
};

/*
 * has_type
 */

template<typename T, typename U = void>
struct has_type: std::false_type {};

template<typename T>
struct has_type<T, typename T::type>: std::true_type {};

/*
 * has_type_void
 */

template<typename T, typename U = void>
struct has_type_void: std::false_type {};

template<typename T>
struct has_type_void<T, std::void_t<typename T::type>>: std::true_type {};

/*
 * has_type_concept
 */

template<typename T>
concept HasTypeConcept = requires { typename T::type; };

template<typename T>
struct has_type_concept {
  enum { value = 0 };
};

template<HasTypeConcept T>
struct has_type_concept<T> {
  enum { value = 1 };
};

/*
 * has_type_concept_2
 */

template<typename T, bool b>
struct _has_type_concept_2;

template<typename T>
struct _has_type_concept_2<T, false> {
  enum { value = 0 };
};

template<typename T>
struct _has_type_concept_2<T, true> {
  enum { value = 1 };
};

template<typename T>
using has_type_concept_2 = _has_type_concept_2<T, HasTypeConcept<T>>;

/*
 * main
 */

int main() {
  static_assert(has_type_enum<S>::value == 0);
  static_assert(has_type_enum<T>::value == 1);

  static_assert(has_type<S>::value == 0);
  static_assert(has_type<T>::value == 1);

  static_assert(has_type_void<S>::value == 0);
  static_assert(has_type_void<T>::value == 1);

  static_assert(has_type_concept<S>::value == 0);
  static_assert(has_type_concept<T>::value == 1);

  static_assert(has_type_concept_2<S>::value == 0);
  static_assert(has_type_concept_2<T>::value == 1);
}