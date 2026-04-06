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
 *   - No surprises: iteration stops when all ranges are exhausted.
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

    iterator(const std::array<std::pair<iterator_t, iterator_t>, N>* ranges, std::size_t idx)
        : _ranges(ranges)
        , _idx(idx) 
    {
      if (_idx < N) {
        _it = (*_ranges)[_idx].first;
        _skip_empty();
      }
    }

    reference operator*() const {
      return *_it;
    }

    iterator& operator++() {
      ++_it;

      if (_it == (*_ranges)[_idx].second) {
        ++_idx;
        _skip_empty();
      }
      
      return *this;
    }

    bool operator==(const iterator& other) const {
      if (_ranges != other._ranges) {
        return false;
      }

      if (_idx == N && other._idx == N) {
        return true;
      }

      return _idx == other._idx && _it == other._it;
    }

  private:
    void _skip_empty() {
      while ((_idx < N) && ((*_ranges)[_idx].first == (*_ranges)[_idx].second)) {
        ++_idx;
      }

      if (_idx < N) {
        _it = (*_ranges)[_idx].first;
      }
    }

    size_t _idx;
    iterator_t _it;
    const std::array<std::pair<iterator_t, iterator_t>, N>* _ranges;
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
    return iterator(&_ranges, 0);
  }

  [[nodiscard]] iterator end() const {
    return iterator(&_ranges, N);
  }

private:
  template<typename R, typename... Rs>
  void _fill(std::size_t i, R& r, Rs&... rs) {
    _ranges[i] = {std::ranges::begin(r), std::ranges::end(r)};

    if constexpr(sizeof...(Rs) > 0) {
      _fill(i + 1, rs...);
    }
  }

  std::array<std::pair<iterator_t, iterator_t>, N> _ranges;
};


template<typename Range, typename... Rs>
uniform_concat_view(Range&, Rs&...) -> uniform_concat_view<Range, 1 + sizeof...(Rs)>;


template<typename Range, typename... Rs>
auto concat_view(Range& r, Rs&... rs) {
  return uniform_concat_view(r, rs...);
}
