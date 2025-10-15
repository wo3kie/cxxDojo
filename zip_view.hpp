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
#include "./parameter_pack.hpp"
#include "./tuple.hpp"

/*
 * zip_view
 */

template<std::ranges::range... Ranges>
struct zip_view: public std::ranges::view_interface<zip_view<Ranges...>> {
  static constexpr bool IsAnyConst = parameter_pack::Any<std::is_const, Ranges...>::value;

public:
  /*
   * iterator
   */

  struct iterator {
  public:
    using value_type = std::tuple<std::ranges::range_value_t<Ranges>...>;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    using reference = std::conditional<
        IsAnyConst, //
        std::tuple<const std::ranges::range_value_t<Ranges>&...>,
        std::tuple<std::ranges::range_value_t<Ranges>&...>>::type;

    using pointer = std::conditional<
        IsAnyConst, //
        std::tuple<const std::ranges::range_value_t<Ranges>*...>,
        std::tuple<std::ranges::range_value_t<Ranges>*...>>::type;

  public:
    iterator(std::tuple<Ranges&...>* rangesPtr, bool isEnd = false)
        : _rangesPtr(rangesPtr) //
    {
      const auto equalSize = [expected = std::get<0>(*_rangesPtr).size()](const auto& range) -> bool { //
        Assert(range.size() == expected);
        return range.size() == expected;
      };

      assert(stl::all(equalSize, *rangesPtr));

      if(isEnd) {
        _iterators = std::make_tuple(std::ranges::end(std::get<Ranges&>(*_rangesPtr))...);
      } else {
        _iterators = std::make_tuple(std::ranges::begin(std::get<Ranges&>(*_rangesPtr))...);
      }
    }

    reference operator*() {
      return {*std::get<std::ranges::iterator_t<Ranges>>(_iterators)...};
    }

    iterator& operator++() {
      return (_iterators = std::make_tuple(++std::get<std::ranges::iterator_t<Ranges>>(_iterators)...)), *this;
    }

    bool operator==(const iterator& other) const {
      return _iterators == other._iterators;
    }

  private:
    std::tuple<Ranges&...>* _rangesPtr;
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
      : _rangesPtr(ranges...) {
  }

  iterator begin() {
    return iterator(&_rangesPtr, /* isEnd */ false);
  }

  iterator end() {
    return iterator(&_rangesPtr, /* isEnd */ true);
  }

private:
  std::tuple<Ranges&...> _rangesPtr;
};
