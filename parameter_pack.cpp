/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 parameter_pack.cpp -o parameter_pack
 *
 * Usage:
 *      $ ./parameter_pack
 */

#include "./parameter_pack.hpp"

/*
 * size_test
 */

void size_test() {
  using namespace parameter_pack;

  static_assert(Size<>::value == 0);
  static_assert(Size<int>::value == 1);
  static_assert(Size<int, double>::value == 2);
  static_assert(Size<int, double, char>::value == 3);
}

/*
 * head_test
 */

void head_test() {
  using namespace parameter_pack;

  static_assert(std::is_same_v<Head<int>::type, int>);
  static_assert(std::is_same_v<Head<int, double>::type, int>);
  static_assert(std::is_same_v<Head<int, double, char>::type, int>);
}

/*
 * tail_test
 */

void tail_test() {
  using namespace parameter_pack;

  static_assert(std::is_same_v<Tail<int>::type, std::tuple<>>);
  static_assert(std::is_same_v<Tail<int, double>::type, std::tuple<double>>);
  static_assert(std::is_same_v<Tail<int, double, char>::type, std::tuple<double, char>>);
}

/*
 * back_test
 */

void back_test() {
  using namespace parameter_pack;

  static_assert(std::is_same_v<Back<int>::type, int>);
  static_assert(std::is_same_v<Back<int, double>::type, double>);
  static_assert(std::is_same_v<Back<int, double, char>::type, char>);
}

/*
 * any_test
 */

void any_test() {
  using namespace parameter_pack;

  static_assert(All<std::is_integral, int, long, char>::value);
  static_assert(! All<std::is_integral, int, double, char>::value);
}

/*
 * all_test
 */

void all_test() {
  using namespace parameter_pack;

  static_assert(Any<std::is_integral, double, char, long>::value);
  static_assert(! Any<std::is_integral, double, float>::value);
}

/*
 * none_test
 */

void none_test() {
  using namespace parameter_pack;

  static_assert(None<std::is_integral, double, float>::value);
  static_assert(! None<std::is_integral, double, int>::value);
}

/*
 * main
 */

int main() {
  size_test();
  head_test();
  tail_test();
  back_test();
  any_test();
  all_test();
  none_test();
}
