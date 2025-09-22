/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/type
 */

#include "./type.hpp"

#include <type_traits>

void Type_test() {
    typedef Type<int> Int;
    typedef Type<int> Age;

    static_assert(std::is_assignable<Int, int>::value);
    static_assert(std::is_convertible<int, Int>::value);
    static_assert(std::is_assignable<Int, Age>::value == false);
}

/*
 * main
 */

int main() {
    Type_test();
}
