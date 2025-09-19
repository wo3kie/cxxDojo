#pragma once

/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 */

#pragma once

#include <tuple>
#include <type_traits>

namespace parameter_pack {

/*
 * Size
 */

template<typename... Types>
struct Size {
  static constexpr std::size_t value = sizeof...(Types);
};

/*
 * Head
 */

template<typename... Types>
struct Head {
  using type = std::tuple_element_t<0, std::tuple<Types...>>;
};

/*
 * Front
 */

template<typename... Types>
using Front = Head<Types...>;

/*
 * Tail
 */

template<typename... Types>
struct Tail {
  using type = decltype(std::apply(
      [](auto, auto... t) {
        return std::make_tuple(t...);
      },
      std::declval<std::tuple<Types...>>()));
};

/*
 * Back
 */

template<typename... Types>
struct Back {
  using type = std::tuple_element_t<sizeof...(Types) - 1, std::tuple<Types...>>;
};

/*
 * Any
 */

template<template<typename> class F, typename T, typename... Ts>
struct Any {
  static constexpr bool value = F<T>::value || (F<Ts>::value || ...);
};

/*
 * All
 */

template<template<typename> class F, typename T, typename... Ts>
struct All {
  static constexpr bool value = F<T>::value && (F<Ts>::value && ...);
};

/*
 * None
 */

template<template<typename> class F, typename T, typename... Ts>
struct None {
  static constexpr bool value = ! Any<F, T, Ts...>::value;
};

} // namespace parameter_pack
