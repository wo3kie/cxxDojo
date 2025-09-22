/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/tuple
 */

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

#include "./tuple.hpp"

/*
 * test
 */

namespace composition {

void test() {
  auto tuple = makeTuple(0, 1.0, '2');

  assert(get<0>(tuple) == 0);
  assert(get<1>(tuple) == 1.0);
  assert(get<2>(tuple) == '2');

  assert(size(tuple) == 3);
}

} // namespace composition

namespace inheritance {

void test() {
  auto tuple = makeTuple(0, 1.0, '2');

  assert(get<0>(tuple) == 0);
  assert(get<1>(tuple) == 1.0);
  assert(get<2>(tuple) == '2');

  assert(size(tuple) == 3);
}

} // namespace inheritance

namespace stl {

void foldl_test() {
  std::tuple<bool, int, double> tcid{true, 2, 3.3};

  const auto fl = [](int acc, auto a) -> int {
    return acc + int(a);
  };

  assert(foldl(fl, 0, tcid) == 1 + 2 + 3);
}

void foldr_test() {
  std::tuple<bool, int, double> tcid{true, 2, 3.3};

  const auto fr = [](auto a, int acc) -> int {
    return int(a) + acc;
  };

  assert(foldr(fr, 0, tcid) == 1 + 2 + 3);
}

void hash_test() {
  std::tuple<bool> tb{false};
  hash(tb);

  std::tuple<bool, int> tbi{false, 1};
  hash(tbi);

  std::tuple<bool, int, float> tbif{false, 1, 1.11};
  hash(tbif);
}

template<typename T>
struct IsBig: std::conditional_t<(sizeof(T) > 4), std::true_type, std::false_type> {};

void IsBig_test() {
  static_assert(IsBig<char>::value == false);
  static_assert(IsBig<double>::value == true);
}

void All_test() {
  static_assert(All<IsBig, std::tuple<char, int, float>>::value == false);
  static_assert(All<IsBig, std::tuple<double, long, long double>>::value == true);
}

void Any_test() {
  static_assert(Any<IsBig, std::tuple<char, int, float>>::value == false);
  static_assert(Any<IsBig, std::tuple<char, int, double>>::value == true);
}

void None_test() {
  static_assert(None<IsBig, std::tuple<char, int, float>>::value == true);
  static_assert(None<IsBig, std::tuple<char, int, double>>::value == false);
}

void Foldl_test() {
  std::tuple<bool, int, float> tbif{false, 1, 1.11};

  static_assert(std::is_same_v<int, Foldl<std::common_type, std::tuple<short, int>>::type>);
  static_assert(std::is_same_v<double, Foldl<std::common_type, std::tuple<short, int, double>>::type>);
}

void print_test() {
  std::ostringstream oss;
  print(oss, std::make_tuple(1, 'b', 3.3), ", ");
  assert(oss.str() == "1, b, 3.3");
}

} // namespace stl

/*
 * main
 */

int main() {
  composition::test();
  inheritance::test();

  stl::foldl_test();
  stl::foldr_test();
  stl::hash_test();
  stl::IsBig_test();
  stl::All_test();
  stl::Any_test();
  stl::None_test();
  stl::Foldl_test();
  stl::print_test();
}
