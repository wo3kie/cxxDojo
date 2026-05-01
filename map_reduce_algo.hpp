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
    auto task = [&](auto&& val) {
        return std::async(std::launch::async, [this, v = std::forward<decltype(val)>(val)]() mutable {
            return this->_map_fn(std::move(v));
        });
    };

    std::array futures = {
      task(std::forward<TIns>(values))...
    };

    auto init = this->_map_fn(std::forward<TIn>(value));

    for(auto& future : futures) {
      init = this->_reduce_fn(std::move(init), future.get());
    }

    return init;
  }

  template<typename TOut, typename TIn, typename... TIns>
  [[nodiscard]] auto run_with_init(TOut&& init, TIn&& value, TIns&&... values)
  {
    auto task = [&](auto&& val) {
        return std::async(std::launch::async, [this, v = std::forward<decltype(val)>(val)]() mutable {
            return this->_map_fn(std::move(v));
        });
    };

    std::array futures = {
      task(std::forward<TIns>(values))...
    };

    init = _reduce_fn(std::forward<TOut>(init), _map_fn(std::forward<TIn>(value)));

    for(auto& future : futures) {
      init = _reduce_fn(std::forward<TOut>(init), future.get());
    }

    return init;
  }

private:
  TMapFn _map_fn;
  TReduceFn _reduce_fn;
};

template<typename TMapFn, typename TReduceFn>
MapReduce(TMapFn map_fn, TReduceFn reduce_fn) -> MapReduce<TMapFn, TReduceFn>;
