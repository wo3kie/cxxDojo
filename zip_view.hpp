#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <iterator>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

#include "./assert.hpp"
#include "./tuple.hpp"

/*
 * zip_view
 */

template<std::ranges::range... Ranges>
struct zip_view: public std::ranges::view_interface<zip_view<Ranges...>> {
public:
  /*
   * iterator
   */

  struct iterator {
  public:
    using value_type = std::tuple<std::ranges::range_value_t<Ranges>...>;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using reference = std::tuple<std::ranges::range_reference_t<Ranges>...>;
    using pointer = std::tuple<std::add_pointer_t<std::ranges::range_reference_t<Ranges>>...>;

  public:
    iterator(std::tuple<std::ranges::iterator_t<Ranges>...> its)
        : _iterators(std::move(its)) {
    }

    template<std::size_t... Is>
    reference _dereference(std::index_sequence<Is...>) const {
      return {*std::get<Is>(_iterators)...};
    }

    reference operator*() const {
      return _dereference(std::index_sequence_for<Ranges...>{});
    }

    template<std::size_t... Is>
    void _increment(std::index_sequence<Is...>) {
      (..., ++std::get<Is>(_iterators));
    }

    iterator& operator++() {
      _increment(std::index_sequence_for<Ranges...>{});
      return *this;
    }

    bool operator==(const iterator& other) const {
      return _iterators == other._iterators;
    }

  private:
    std::tuple<std::ranges::iterator_t<Ranges>...> _iterators;
  };

public:
  using pointer = iterator::pointer;
  using reference = iterator::reference;
  using value_type = iterator::value_type;
  using difference_type = iterator::difference_type;
  using iterator_category = iterator::iterator_category;

public:
  zip_view(Ranges&... ranges)
      : _ranges(ranges...) {
  }

  iterator begin() {
    return _make_iterator(/* isEnd */ false, std::index_sequence_for<Ranges...>{});
  }

  iterator end() {
    return _make_iterator(/* isEnd */ true, std::index_sequence_for<Ranges...>{});
  }

private:
  template<std::size_t... Is>
  iterator _make_iterator(bool isEnd, std::index_sequence<Is...>) {
    if(isEnd) {
      return iterator{std::make_tuple(std::ranges::end(std::get<Is>(_ranges))...)};
    } else {
      return iterator{std::make_tuple(std::ranges::begin(std::get<Is>(_ranges))...)};
    }
  }

private:
  std::tuple<Ranges&...> _ranges;
};
