#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <iterator>
#include <ranges>
#include <tuple>
#include <type_traits>

/*
 * filter_view
 */

template<std::ranges::range Range>
struct filter_view: public std::ranges::view_interface<filter_view<Range>> {
public:
  /*
   * iterator
   */

  struct iterator {
  public:
    using value_type = std::ranges::range_value_t<Range>;
    using reference = std::conditional_t<std::is_const_v<Range>, const value_type&, value_type&>;
    using pointer = std::conditional_t<std::is_const_v<Range>, const value_type*, value_type*>;
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;

  public:
    iterator(std::ranges::iterator_t<Range> begin, std::ranges::iterator_t<Range> end, std::function<bool(const reference)> f)
        : _begin(begin)
        , _end(end)
        , _f(f) {
      for(/* empty */; _begin != _end; ++_begin) {
        if(_f(*_begin)) {
          break;
        }
      }
    }

    reference operator*() {
      return *_begin;
    }

    iterator& operator++() {
      for(++_begin; _begin != _end; ++_begin) {
        if(_f(*_begin)) {
          break;
        }
      }

      return *this;
    }

    bool operator==(const iterator& other) const {
      return (_begin == other._begin) && (_end == other._end);
    }

    bool operator!=(const iterator& other) const {
      return ! (*this == other);
    }

  private:
    std::ranges::iterator_t<Range> _begin;
    std::ranges::iterator_t<Range> _end;
    std::function<bool(const reference)> _f;
  };

public:
  using pointer = iterator::pointer;
  using reference = iterator::reference;
  using value_type = iterator::value_type;
  using difference_type = iterator::difference_type;
  using iterator_category = iterator::iterator_category;

public:
  filter_view(Range& range, std::function<bool(const value_type&)> f)
      : _range(range)
      , _f(f) {
  }

  iterator begin() {
    return iterator(_range.begin(), _range.end(), _f);
  }

  iterator end() {
    return iterator(_range.end(), _range.end(), _f);
  }

private:
  Range& _range;
  std::function<bool(const value_type&)> _f;
};
