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
constexpr auto Reduce(T init, Op op = {}) {
  return _Reduce<T, Op>{.init = init, .op = op};
}
