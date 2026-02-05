#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */


#include <numeric>
#include <ranges>

/*
 * Map
 */

inline constexpr decltype(std::views::transform) Map;

/*
 * Reduce
 */

template<typename T, typename Op>
struct _Reduce {
  T init;
  Op op;

  template<std::ranges::input_range R>
  constexpr T operator()(R&& r) const {
    return std::accumulate(std::ranges::begin(r), std::ranges::end(r), init, op);
  }

  template<std::ranges::input_range R>
  friend auto operator|(R&& r, const _Reduce& self) {
    return self(r);
  }
};

template<typename T, typename Op = std::plus<>>
constexpr _Reduce<T, Op> Reduce(T init, Op op = {}) {
  return _Reduce<T, Op>{.init = init, .op = op};
}

/*
 * Filter
 */

inline constexpr decltype(std::views::filter) Filter;

/*
 * To
 */

template<template<typename...> typename Container>
struct _To {
  template<std::ranges::input_range R>
  constexpr Container<std::ranges::range_value_t<R>> operator()(R&& r) const {
    return Container<std::ranges::range_value_t<R>>{std::ranges::begin(r), std::ranges::end(r)};
  }

  template<std::ranges::input_range R>
  friend auto operator|(R&& r, const _To<Container>& self) {
    return self(r);
  }
};

template<template<typename...> typename Container>
constexpr _To<Container> To() {
  return _To<Container>{};
}
