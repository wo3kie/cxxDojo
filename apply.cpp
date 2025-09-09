/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 apply.cpp -o apply
 *
 * Usage:
 *      $ ./apply
 */

#include <tuple>

/* Simplified version without move semantic, for full version please refer to
 * "GN13 Andrei Alexandrescu Exploding Tuple"
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
 * apply( f       , 3         , { 1, 2.2, '3' },         '3' ){ recursive call }
 * 
 * apply( f       , 2         , { 1, 2.2, '3' },    2.2, '3' ){ recursive call }
 * 
 * apply( f       , 1         , { 1, 2.2, '3' }, 1, 2.2, '3' ){ recursuve call }
 * 
 * apply( f       , 0         , { 1, 2.2, '3' }, 1, 2.2, '3' ){ return f(1, 2.2, 3); }
 */

template<unsigned TupleIndex, typename Return, typename Function, typename Tuple>
struct Apply {
  template<typename... Args>
  static Return apply(Function function, Tuple tuple, Args... args) {
    return Apply<TupleIndex - 1, Return, Function, Tuple>::apply(
        function, tuple, std::get<TupleIndex - 1>(tuple), args...);
  }
};

template<typename Return, typename Function, typename Tuple>
struct Apply<0, Return, Function, Tuple> {
  template<typename... Args>
  static Return apply(Function function, Tuple /* unused */, Args... args) {
    return function(args...);
  }
};

template<typename Function, typename... Args>
auto apply(Function function, std::tuple<Args...> tuple) -> typename std::result_of<Function(Args...)>::type {
  return Apply<sizeof...(Args), typename std::result_of<Function(Args...)>::type, Function, std::tuple<Args...>>::apply(
      function, tuple);
}

/*
 *
 */

#include <cassert>
#include <iostream>

double f(int i, float f, char c) {
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "char: " << c << std::endl;

  return 3.14;
}

int main() {
  assert(3.14 == apply(f, std::make_tuple(1, 2.2, '3')));
}
