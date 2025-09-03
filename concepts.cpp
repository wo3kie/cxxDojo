/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 concepts.cpp -o concepts
 *
 * Usage:
 *      $ ./concepts
 */

#include <concepts>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

Numeric auto add(Numeric auto a, Numeric auto b) {
    return a + b;
}

template<Numeric T>
T sub(T a, T b) {
    return a - b;
}     

template<typename T>
requires requires(T t) {
    t+t;
    t-t;
    t*t;
    t/t;
    t=0;
    t==t;
    t!=t;
    t<t;
    t<=t;
    t>t;
    t>=t;
}
T div(T a, T b) {
    return a / b;
}  

int main() {
    static_assert(Numeric<int>);
    static_assert(Numeric<double>);
    static_assert(!Numeric<void*>);

    return 0;
}
