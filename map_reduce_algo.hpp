/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <array>
#include <future>
#include <utility>

#include <iostream>

template<typename TMapFn, typename TReduceFn>
struct MapReduce
{
  MapReduce(TMapFn map_fn, TReduceFn reduce_fn)
    : _map_fn(std::move(map_fn))
    , _reduce_fn(std::move(reduce_fn))
  {
  }

  MapReduce(const MapReduce&) = delete;
  MapReduce(MapReduce&&) = delete;

  ~MapReduce() = default;

  MapReduce& operator=(const MapReduce&) = delete;
  MapReduce& operator=(MapReduce&&) = delete;

  template<typename TIn, typename... TIns>
  [[nodiscard]] auto run(TIn&& value, TIns&&... values)
  {
    using TOut = decltype(_map_fn(std::declval<TIn>()));
    return run2(TOut(), std::forward<TIn>(value), std::forward<TIns>(values)...);
  }

  template<typename TOut, typename TIn, typename... TIns>
  [[nodiscard]] auto run2(TOut init, TIn&& value, TIns&&... values)
  {
    constexpr size_t N = 1 + sizeof...(TIns);
    std::array<std::future<TOut>, N> futures;

    _push<0, N>(futures, std::forward<TIn>(value), std::forward<TIns>(values)...);
    return _reduce<0, N>(std::move(init), futures);
  }

  template<size_t I, size_t N, typename Futures, typename TIn, typename... TIns>
  void _push(Futures& futures, TIn&& value, TIns&&... values)
  {
    using X = std::decay_t<TIn>;

    futures[I] = std::async(std::launch::async, [this, v = X(std::forward<TIn>(value))]() mutable {
      return this->_map_fn(std::move(v));
    });

    if constexpr(I + 1 != N) {
      _push<I + 1, N>(futures, std::forward<TIns>(values)...);
    }
  }

  template<size_t I, size_t N, typename TOut, typename Futures>
  TOut _reduce(TOut&& result, Futures& futures)
  {
    if constexpr(I != N) {
      return _reduce<I + 1, N>(_reduce_fn(std::move(result), futures[I].get()), futures);
    } else {
      return result;
    }
  }

private:
  TMapFn _map_fn;
  TReduceFn _reduce_fn;
};

template<typename TMapFn, typename TReduceFn>
MapReduce(TMapFn map_fn, TReduceFn reduce_fn) -> MapReduce<TMapFn, TReduceFn>;
