/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
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
