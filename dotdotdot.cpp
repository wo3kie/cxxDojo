/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 dotdotdot.cpp -o dotdotdot
 *
 * Usage:
 *      $ ./dotdotdot
 */

#include <type_traits>

#include "./dotdotdot.hpp"

void Head_test() {
    static_assert(std::is_same_v<Head<int, double, bool>::type, int>);
}

void Front_test() {
    static_assert(std::is_same_v<Front<int, double, bool>::type, int>);
}

void Tail_test() {
    static_assert(std::is_same_v<Tail<int, double, bool>::type, std::tuple<double, bool>>);
}

void Back_test() {
    static_assert(std::is_same_v<Back<int, double, bool>::type, bool>);
}

void Any_test() {
  static_assert(!Any<std::is_const, int, double, bool>::value);
  static_assert(Any<std::is_const, const int, double, bool>::value);
}

void All_test() {
  static_assert(!All<std::is_const, const int, double, const bool>::value);
  static_assert(All<std::is_const, const int, const double, const bool>::value);
}

void None_test() {
  static_assert(None<std::is_const, int, double, bool>::value);
  static_assert(!None<std::is_const, const int, const double, const bool>::value);
}

/*
 * main
 */

int main() {
    Head_test();
    Front_test();
    Tail_test();
    Back_test();

    Any_test();
    All_test();
    None_test();
}