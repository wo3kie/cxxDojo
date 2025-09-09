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

#include <tuple>

/*
 * Head
 */

template<typename... Types>
struct Head {
    using type = std::tuple_element_t<0, std::tuple<Types...>>;
};

/*
 * Front
 */

template<typename... Types>
using Front = Head<Types...>;

/*
 * Tail
 */

template<typename... Types>
struct Tail {
    using type = decltype(
        std::apply(
            [](auto, auto... t) { return std::make_tuple(t...); }, 
            std::declval<std::tuple<Types...>>()
        )
    );
};

/*
 * Back
 */

template<typename... Types>
struct Back {
    using type = std::tuple_element_t<sizeof...(Types) - 1, std::tuple<Types...>>;
};

/*
 * main
 */

int main() {
    static_assert(std::is_same_v<Head<int, double, bool>::type, int>);
    static_assert(std::is_same_v<Front<int, double, bool>::type, int>);
    static_assert(std::is_same_v<Tail<int, double, bool>::type, std::tuple<double, bool>>);
    static_assert(std::is_same_v<Back<int, double, bool>::type, bool>);
}