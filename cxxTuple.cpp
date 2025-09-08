/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 cxxTuple.cpp -o cxxTuple
 *
 * Usage:
 *      $ ./cxxTuple
 */

#include <cassert>
#include <iostream>
#include <string>

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

template<int N, typename T, typename... Ts>
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

template<int N, typename T, typename... Ts>
auto get(Tuple<T, Ts...> tuple) {
  return Get<N, T, Ts...>::get(tuple);
}

template<typename T, typename... Ts>
int size(Tuple<T, Ts...> const& tuple) {
  return 1 + size(tuple._ts);
}

template<typename T>
int size(Tuple<T> const& tuple) {
  return 1;
}

void test() {
  auto tuple = makeTuple(0, 1.0, '2');

  assert(get<0>(tuple) == 0);
  assert(get<1>(tuple) == 1.0);
  assert(get<2>(tuple) == '2');

  assert(size(tuple) == 3);
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

template<int N, typename T, typename... Ts>
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

template<int N, typename T, typename... Ts>
auto get(Tuple<T, Ts...> tuple) {
  return Get<N, T, Ts...>::get(tuple);
}

template<typename T, typename... Ts>
int size(Tuple<T, Ts...> const& tuple) {
  return 1 + sizeof...(Ts);
}

void test() {
  auto tuple = makeTuple(0, 1.0, '2');

  assert(get<0>(tuple) == 0);
  assert(get<1>(tuple) == 1.0);
  assert(get<2>(tuple) == '2');

  assert(size(tuple) == 3);
}
} // namespace inheritance

int main() {
  composition::test();
  inheritance::test();
}
