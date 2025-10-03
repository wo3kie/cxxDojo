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

/*
 * enumerate_view
 */

template<std::ranges::range Range>
struct enumerate_view: public std::ranges::view_interface<enumerate_view<Range>> {
public:
  /*
   * iterator
   */

  struct iterator {
  public:
    using reference = std::tuple<size_t, std::ranges::range_reference_t<Range>>;
    using value_type = std::tuple<size_t, std::ranges::range_value_t<Range>>;
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;

  public:
    iterator(std::ranges::iterator_t<Range> iterator, size_t idx = 0)
        : _idx(idx)
        , _iterator(iterator) {
    }

    reference operator*() {
      return {_idx, *_iterator};
    }

    iterator& operator++() {
      ++_idx;
      ++_iterator;

      return *this;
    }

    bool operator==(const iterator& other) const {
      return (_idx == other._idx) && (_iterator == other._iterator);
    }

    bool operator!=(const iterator& other) const {
      return ! (*this == other);
    }

  private:
    size_t _idx;
    std::ranges::iterator_t<Range> _iterator;
  };

public:
  using pointer = iterator::pointer;
  using reference = iterator::reference;
  using value_type = iterator::value_type;
  using difference_type = iterator::difference_type;
  using iterator_category = iterator::iterator_category;

public:
  enumerate_view(Range& range)
      : _range(range) {
  }

  iterator begin() {
    return iterator(_range.begin(), 0);
  }

  iterator end() {
    return iterator(_range.end(), _range.size());
  }

private:
  Range& _range;
};
