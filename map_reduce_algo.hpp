#pragma once

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

namespace detail {

template <typename, template<typename, std::size_t> class>
struct is_specialization_of : std::false_type {};

template <typename T, std::size_t N, template<typename, std::size_t> class C>
struct is_specialization_of<C<T,N>, C> : std::true_type {};

template<typename T>
inline constexpr bool is_std_array_v =
  is_specialization_of<std::remove_cvref_t<T>, std::array>::value;


}

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
    requires (!detail::is_std_array_v<std::remove_cvref_t<TIn>>)
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

  template<typename TIn, std::size_t N>
  [[nodiscard]] auto run(const std::array<TIn, N>& arr)
  {
    return std::apply(
      [&](auto&&... elems) {
        return run(std::forward<decltype(elems)>(elems)...);
      },
      arr
    );
  }

  template<typename TOut, typename TIn, typename... TIns>
    requires (!detail::is_std_array_v<std::remove_cvref_t<TIn>>)
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

  template<typename TOut, typename TIn, std::size_t N>
  auto run_with_init(TOut&& init, const std::array<TIn, N>& arr)
  {
    return std::apply(
      [&](auto&&... elems) {
        return run_with_init(std::forward<TOut>(init), std::forward<decltype(elems)>(elems)...);
      },
      arr
    );
  }

private:
  TMapFn _map_fn;
  TReduceFn _reduce_fn;
};

template<typename TMapFn, typename TReduceFn>
MapReduce(TMapFn map_fn, TReduceFn reduce_fn) -> MapReduce<TMapFn, TReduceFn>;
