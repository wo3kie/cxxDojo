/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 print_tuple.cpp -o print_tuple
 *
 * Usage:
 *      $ ./print_tuple
 */

#include <cassert>
#include <iostream>
#include <tuple>

template<int I, int Size, typename... Args>
struct PrintTuple {
  void operator()(std::tuple<Args...> const& tuple) const {
    std::cout << std::get<I>(tuple) << std::endl;
    PrintTuple<I + 1, Size, Args...>()(tuple);
  }
};

template<int Size, typename... Args>
struct PrintTuple<Size, Size, Args...> {
  void operator()(std::tuple<Args...> const&) const {
  }
};

template<typename... Args>
void printTuple(std::tuple<Args...> const& tuple) {
  PrintTuple<0, sizeof...(Args), Args...>()(tuple);
}

template<typename... Args>
constexpr int sizeTuple(std::tuple<Args...> const&) {
  return sizeof...(Args);
}

int main() {
  auto const tuple = std::make_tuple(1, 2.0, '3', "4");

  static_assert(4 == sizeTuple(tuple), ":(");
  printTuple(tuple);
}
