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

#include "./parameter_pack.hpp"

/*
 * concat_view
 */

template<std::ranges::range... Ranges>
struct concat_view: public std::ranges::view_interface<concat_view<Ranges...>> {
  static constexpr bool IsAnyConst = parameter_pack::Any<std::is_const, Ranges...>::value;

public:
  /*
   * iterator
   */

  struct iterator {
  public:
    using value_type = std::common_type_t<std::ranges::range_value_t<Ranges>...>;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using reference = std::conditional<IsAnyConst, const value_type&, value_type&>::type;
    using pointer = std::conditional<IsAnyConst, const value_type*, value_type*>::type;

  public:
    iterator(std::tuple<Ranges&...>* ranges, size_t idx)
        : _idx(idx)
        , _ranges(ranges) {
      if(_idx < sizeof...(Ranges)) {
        _set_iterator(_idx);
      } else if(_idx == sizeof...(Ranges)) {
        /*
         * End iterator
         */
      } else {
        throw std::out_of_range("concat_view iterator index out of range");
      }
    }

    reference operator*() {
      return _dereference<0>(_idx);
    }

    iterator& operator++() {
      _increment<0>(_idx);

      if(_at_end()) {
        _idx += 1;

        if(_idx < sizeof...(Ranges)) {
          _set_iterator<0>(_idx);
        } else if(_idx == sizeof...(Ranges)) {
          /*
           * End iterator
           */
        } else {
          throw std::out_of_range("concat_view iterator index out of range");
        }
      }

      return *this;
    }

    bool operator==(const iterator& other) const {
      return _ranges == other._ranges && _idx == other._idx && (_idx == sizeof...(Ranges) || _iterator == other._iterator);
    }

  private:
    template<size_t I = 0>
    void _set_iterator(const size_t idx) {
      if constexpr(I < sizeof...(Ranges)) {
        if(idx == I) {
          _iterator = std::ranges::begin(std::get<I>(*_ranges));
        } else {
          _set_iterator<I + 1>(idx);
        }
      }
    }

    template<size_t I = 0>
    bool _at_end() const {
      if constexpr(I < sizeof...(Ranges)) {
        if(_idx == I) {
          return std::get<I>(_iterator) == std::ranges::end(std::get<I>(*_ranges));
        } else {
          return _at_end<I + 1>();
        }
      } else {
        return true;
      }
    }

    template<size_t I = 0>
    void _increment(const size_t idx) {
      if constexpr(I < sizeof...(Ranges)) {
        if(idx == I) {
          ++std::get<I>(_iterator);
        } else {
          _increment<I + 1>(idx);
        }
      }
    }

    template<size_t I = 0>
    reference _dereference(const size_t idx) {
      if constexpr(I < sizeof...(Ranges)) {
        if(idx == I) {
          return *std::get<I>(_iterator);
        } else {
          return _dereference<I + 1>(idx);
        }
      } else {
        throw std::out_of_range("concat_view iterator out of range");
      }
    }

  private:
    size_t _idx;
    std::tuple<Ranges&...>* _ranges;
    std::variant<std::ranges::iterator_t<Ranges>...> _iterator;
  };

public:
  using pointer = iterator::pointer;
  using reference = iterator::reference;
  using value_type = iterator::value_type;
  using difference_type = iterator::difference_type;
  using iterator_category = iterator::iterator_category;

public:
  concat_view(Ranges&... ranges)
      : _ranges(ranges...) {
  }

  iterator begin() {
    return iterator(&_ranges, 0);
  }

  iterator end() {
    return iterator(&_ranges, sizeof...(Ranges));
  }

private:
  std::tuple<Ranges&...> _ranges;
};

/*
 * uniform_concat_view
 *
 * A lightweight, zero‑allocation view that concatenates multiple ranges
 * of the same type into a single forward range.
 *
 * This view is designed for high‑performance scenarios where:
 *   - all input ranges have the same type, (enforced by static_assert).
 *   - all iterators have the same iterator type, (enforced by static_assert).
 *   - all iterators must satisfy forward iterator requirements, (enforced by static_assert).
 *
 * Key properties:
 *   - Zero allocations: all storage is in a fixed-size std::array.
 *   - Zero type erasure: iterator type is uniform across all ranges.
 *   - Zero overhead: iteration is equivalent to a hand-written loop.
 *   - Reference integrity: dereferencing yields true references to the
 *     underlying elements; modifying through the view modifies the source.
 *   - Const-correct: const uniform_concat_view iterates using const iterators.
 *   - No surprises: iteration stops when all segments are exhausted.
 */

template<std::ranges::range Range, std::size_t N /* CTAD Deducted */>
struct uniform_concat_view final : std::ranges::view_interface<uniform_concat_view<Range, N>> {
  using iterator_t = std::ranges::iterator_t<Range>;

  struct iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::ranges::range_value_t<Range>;
    using difference_type = std::ptrdiff_t;
    using reference = std::ranges::range_reference_t<Range>;
    using pointer = std::add_pointer_t<reference>;

    iterator(const std::array<std::pair<iterator_t, iterator_t>, N>* segments, std::size_t idx)
        : _segments(segments)
        , _idx(idx) 
    {
      if (_idx < N) {
        _it = (*_segments)[_idx].first;
        _skip_empty();
      }
    }

    reference operator*() const {
      return *_it;
    }

    iterator& operator++() {
      ++_it;

      if (_it == (*_segments)[_idx].second) {
        ++_idx;
        _skip_empty();
      }
      
      return *this;
    }

    bool operator==(const iterator& other) const {
      return _idx == other._idx && (_idx == N || _it == other._it);
    }

  private:
    void _skip_empty() {
      while ((_idx < N) && ((*_segments)[_idx].first == (*_segments)[_idx].second)) {
        ++_idx;
      }

      if (_idx < N) {
        _it = (*_segments)[_idx].first;
      }
    }

    const std::array<std::pair<iterator_t, iterator_t>, N>* _segments;
    size_t _idx;
    iterator_t _it;
  };

public:
  uniform_concat_view(uniform_concat_view&&) = delete;
  uniform_concat_view(const uniform_concat_view&) = delete;

  uniform_concat_view& operator=(uniform_concat_view&&) = delete;
  uniform_concat_view& operator=(const uniform_concat_view&) = delete;

  template<typename... Rs>
  uniform_concat_view(Rs&... rs) {
    static_assert((std::same_as<Range, Rs> && ...),
                  "All ranges must have the same type");

    static_assert(std::forward_iterator<std::ranges::iterator_t<Range>>,
                  "Range must provide a forward iterator");

    _fill(0, rs...);
  }

  [[nodiscard]] iterator begin() const {
    return iterator(&_segments, 0);
  }

  [[nodiscard]] iterator end() const {
    return iterator(&_segments, N);
  }

private:
  template<typename R, typename... Rs>
  void _fill(std::size_t i, R& r, Rs&... rs) {
    _segments[i] = {std::ranges::begin(r), std::ranges::end(r)};

    if constexpr(sizeof...(Rs) > 0) {
      _fill(i + 1, rs...);
    }
  }

  std::array<std::pair<iterator_t, iterator_t>, N> _segments;
};

template<typename Range, typename... Rs>
uniform_concat_view(Range&, Rs&...) -> uniform_concat_view<Range, 1 + sizeof...(Rs)>;
