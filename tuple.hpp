#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstddef>
#include <functional>
#include <tuple>

namespace composition {

template<typename T, typename... Ts>
struct Tuple {
  Tuple(T t, Ts... ts)
      : _t(t)
      , _ts(ts...) {
  }

  T _t;
  Tuple<Ts...> _ts;
};

template<typename T>
struct Tuple<T> {
  Tuple(T t)
      : _t(t) {
  }

  T _t;
};

template<typename... Ts>
Tuple<Ts...> makeTuple(Ts&&... ts) {
  return Tuple<Ts...>(std::forward<Ts>(ts)...);
}

template<size_t N, typename T, typename... Ts>
struct Get {
  static auto get(Tuple<T, Ts...> tuple) {
    return Get<N - 1, Ts...>::get(tuple._ts);
  }
};

template<typename T, typename... Ts>
struct Get<0, T, Ts...> {
  static auto get(Tuple<T, Ts...> tuple) {
    return tuple._t;
  }
};

template<size_t N, typename T, typename... Ts>
auto get(Tuple<T, Ts...> tuple) {
  return Get<N, T, Ts...>::get(tuple);
}

template<typename T, typename... Ts>
size_t size(const Tuple<T, Ts...>& tuple) {
  return 1 + size(tuple._ts);
}

template<typename T>
size_t size(const Tuple<T>& tuple) {
  return 1;
}

} // namespace composition

namespace inheritance {

template<typename T, typename... Ts>
struct Tuple: Tuple<Ts...> {
  Tuple(T t, Ts... ts)
      : Tuple<Ts...>(ts...)
      , _t(t) {
  }

  T _t;
};

template<typename T>
struct Tuple<T> {
  Tuple(T t)
      : _t(t) {
  }

  T _t;
};

template<typename T, typename... Ts>
Tuple<T, Ts...> makeTuple(T t, Ts... ts) {
  return Tuple<T, Ts...>(t, ts...);
}

template<size_t N, typename T, typename... Ts>
struct Get {
  static auto get(Tuple<T, Ts...> tuple) {
    // object slicing, Tuple<T, Ts...> --{sliced to base class}-->  Tuple<Ts...>
    return Get<N - 1, Ts...>::get(tuple);
  }
};

template<typename T, typename... Ts>
struct Get<0, T, Ts...> {
  static auto get(Tuple<T, Ts...> tuple) {
    return tuple._t;
  }
};

template<size_t N, typename T, typename... Ts>
auto get(Tuple<T, Ts...> tuple) {
  return Get<N, T, Ts...>::get(tuple);
}

template<typename T, typename... Ts>
size_t size(const Tuple<T, Ts...>& tuple) {
  return 1 + sizeof...(Ts);
}

} // namespace inheritance

namespace stl {


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

template<typename Tuple1, typename Tuple2>
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
 * print(std::cout, make_tuple(1, 'b', 3.3), ',');
 */

template<typename... Ts>
std::ostream& print(std::ostream& out, const std::tuple<Ts...>& tuple, const std::string& delim=", ") {
    const auto f = [&delim](std::reference_wrapper<std::ostream> out, const auto& a) -> std::reference_wrapper<std::ostream> { 
        out.get() << delim << a; 
        return out; 
    };

    return out << head(tuple), foldl(f, std::ref(out), tail(tuple));
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
  static constexpr bool value = ! Any<Predicate, std::tuple<Ts...>>::value;
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

} // namespace stl
