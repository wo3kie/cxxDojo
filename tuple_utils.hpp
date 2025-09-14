/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 * 
 * Author:
 *      Lukasz Czerwinski
 */

#pragma once

#include <functional>
#include <tuple>

namespace tuple {

/*
 * head : (a, b, c, ...) -> a
 */

template<typename Head, typename... Tail>
const Head& head(const std::tuple<Head, Tail...>& tuple) {
    return std::get<0>(tuple);
}

/*
 * tail : (a, b, c, ...) -> (b, c, ...)
 */

template<typename Head, typename... Tail>
std::tuple<Tail...> tail(const std::tuple<Head, Tail...>& tuple) {
    const auto make_tail = [](const Head& /* h */, const Tail&... t) {
        return std::make_tuple(t...);
    };

    return std::apply(make_tail, tuple);
}

/*
 * foldl : (f, acc, (a, b, c, ...)) -> f(...f(f(acc, a), b), c)
 */

template<typename Acc, typename F, typename T>
Acc foldl(F f, Acc acc, std::tuple<T> t) {
    return f(acc, std::get<0>(t));
}

/*
 * foldl : (f, acc, (a, b, c, ...)) -> f(...f(f(acc, a), b), c)
 */

template<typename Acc, typename F, typename T, typename... Ts>
Acc foldl(F f, Acc acc, std::tuple<T, Ts...> t) {
    return foldl(f, f(acc, head(t)), tail(t));
}

/*
 * foldr : (f, acc, (a, b, c, ...)) -> f(a, f(b, f(c, acc)))
 */

template<typename Acc, typename F, typename T>
Acc foldr(F f, Acc acc, std::tuple<T> t) {
    return f(acc, std::get<0>(t));
}

/*
 * foldr : (f, acc, (a, b, c, ...)) -> f(a, f(b, f(c, acc)))
 */

template<typename Acc, typename F, typename T, typename... Ts>
Acc foldr(F f, Acc acc, std::tuple<T, Ts...> t) {
    return f(head(t), foldr(f, acc, tail(t)));
}

/*
 * merge : ((a, b), (c, d)) -> (a, b, c, d)
 */

template <typename Tuple1, typename Tuple2>
struct merge {
    using type = decltype(std::tuple_cat(std::declval<Tuple1>(), std::declval<Tuple2>()));
};

/*
 * hash : (a, b, c, ...) -> size_t
 */ 

template<typename T, typename... Ts>
std::size_t hash(const std::tuple<T, Ts...>& tuple) {
    const auto combine = [](std::size_t h1, auto value) -> std::size_t {
        return h1 + 0x9e3779b9 + (std::hash<std::decay_t<decltype(value)>>()(value) << 2);
    };

    return foldl(combine, 0, tuple);
}

/*
 * All : (Predicate, (a, b, c, ...)) -> bool
 */

template<template<typename> class Predicate, typename... Ts>
struct All {
    static_assert(false);
};

template<template<typename> class Predicate, typename... Ts>
struct All<Predicate, std::tuple<Ts...>> {
    static constexpr bool value = (Predicate<Ts>::value && ...);
};

/*
 * Any : (Predicate, (a, b, c, ...)) -> bool
 */

template<template<typename> class Predicate, typename... Ts>
struct Any {
    static_assert(false);
};

template<template<typename> class Predicate, typename... Ts>
struct Any<Predicate, std::tuple<Ts...>> {
    static constexpr bool value = (Predicate<Ts>::value || ...);
};

/*
 * None : (Predicate, (a, b, c, ...)) -> bool
 */

template<template<typename> class Predicate, typename... Ts>
struct None {
    static_assert(false);
};

template<template<typename> class Predicate, typename... Ts>
struct None<Predicate, std::tuple<Ts...>> {
    static constexpr bool value = !Any<Predicate, std::tuple<Ts...>>::value;
};

/*
 * Foldl : (BinaryMetafunction, (a, b, c, ...)) -> X
 */

template<template<typename, typename> class F, typename... Ts>
struct Foldl {
    static_assert(false);
};

template<template<typename, typename> class F, typename T1, typename T2>
struct Foldl<F, std::tuple<T1, T2>> {
    using type = typename F<T1, T2>::type;
};

template<template<typename, typename> class F, typename T1, typename T2, typename... Ts>
struct Foldl<F, std::tuple<T1, T2, Ts...>> {
    using type = typename Foldl<F, std::tuple<typename F<T1, T2>::type, Ts...>>::type;
};

} // namespace tuple

