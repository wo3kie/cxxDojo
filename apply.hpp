#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

/* 
 * Simplified version without move semantic, 
 * for full version please refer to "GN13 Andrei Alexandrescu Exploding Tuple".
 *
 * More details can be found here, http://en.cppreference.com/w/cpp/utility/apply
 */

/*
 * Brief Idea
 *                                  ---- copy ----
 *                                 /              \
 *                                /                v
 * apply( Function, TupleIndex, Tuple          , Args...     ){ recursive call }
 * 
 * apply( f       , 3         , { 1, 2.f, 3.0 },         3.0 ){ recursive call }
 * 
 * apply( f       , 2         , { 1, 2.f, 3.0 },    2.f, 3.0 ){ recursive call }
 * 
 * apply( f       , 1         , { 1, 2.f, 3.0 }, 1, 2.f, 3.0 ){ recursuve call }
 * 
 * apply( f       , 0         , { 1, 2.f, 3.0 }, 1, 2.f, 3.0 ){ return f(1, 2.f, 3.0); }
 */

#include <tuple>

namespace impl {

template<unsigned TupleIndex, typename Return, typename Function, typename Tuple>
struct Apply {
  template<typename... Args>
  static Return apply(Function function, Tuple tuple, Args... args) {
    return Apply<TupleIndex - 1, Return, Function, Tuple>::apply(function, tuple, std::get<TupleIndex - 1>(tuple), args...);
  }
};

template<typename Return, typename Function, typename Tuple>
struct Apply<0, Return, Function, Tuple> {
  template<typename... Args>
  static Return apply(Function function, Tuple /* unused */, Args... args) {
    return function(args...);
  }
};

} // namespace impl

/*
 * apply
 */

template<typename Function, typename... Args>
auto apply(Function function, std::tuple<Args...> tuple) -> std::invoke_result_t<Function, Args...> {
  return impl::Apply<sizeof...(Args), std::invoke_result_t<Function, Args...>, Function, std::tuple<Args...>>::apply(function, tuple);
}
