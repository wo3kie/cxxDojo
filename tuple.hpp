/*
 * Website:
 *      https://github.com/wo3kie/dojo
 * 
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++17 trie.cpp -o trie
 *
 * Usage:
 *      $ ./trie
 */

#ifndef __CXX_DOJO_TRIE_HPP__
#define __CXX_DOJO_TRIE_HPP__

#include <tuple>

namespace tuple {

template<typename Head, typename... Tail>
const Head& head(const std::tuple<Head, Tail...>& tuple) {
    return std::get<0>(tuple);
}

template<typename Head, typename... Tail>
std::tuple<Tail...> tail(const std::tuple<Head, Tail...>& tuple) {
    const auto make_tail = [](const Head& /* h */, const Tail&... t) {
        return std::make_tuple(t...);
    };

    return std::apply(make_tail, tuple);
}

template<typename I, typename F, typename T>
I foldl(std::tuple<T> t, F f, I i) {
    return f(i, std::get<0>(t));
}

template<typename I, typename F, typename T, typename... Ts>
I foldl(std::tuple<T, Ts...> t, F f, I i) {
    return foldl(tail(t), f, f(i, head(t)));
}

template<typename I, typename F, typename T>
I foldr(std::tuple<T> t, F f, I i) {
    return f(i, std::get<0>(t));
}

template<typename I, typename F, typename T, typename... Ts>
I foldr(std::tuple<T, Ts...> t, F f, I i) {
    return f(foldr(tail(t), f, i), head(t));
}

}

#endif
