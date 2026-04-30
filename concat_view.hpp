#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>

template<std::ranges::view TView, std::size_t N /* CTAD Deducted */>
struct uniform_concat_view final: std::ranges::view_interface<uniform_concat_view<TView, N>>
{
  struct iterator
  {
    using base_iterator = std::ranges::iterator_t<TView>;
    using reference = std::ranges::range_reference_t<TView>;
    using value_type = std::ranges::range_value_t<TView>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    iterator() = default;

    iterator(std::array<TView, N>* viewsPtr, std::size_t idx)
      : _viewsPtr(viewsPtr)
      , _idx(idx)
    {
      if(_idx < N) {
        _it = std::ranges::begin((*_viewsPtr)[_idx]);
        _skip_empty();
      }
    }

    reference operator*() const
    {
      return *_it;
    }

    iterator& operator++()
    {
      ++_it;

      if(_it == std::ranges::end((*_viewsPtr)[_idx])) {
        ++_idx;
        _skip_empty();
      }

      return *this;
    }

    bool operator==(const iterator& other) const
    {
      if(_viewsPtr != other._viewsPtr) {
        return false;
      }

      if(_idx == N && other._idx == N) {
        return true;
      }

      return _idx == other._idx && _it == other._it;
    }

  private:
    void _skip_empty()
    {
      while((_idx < N) && (std::ranges::begin((*_viewsPtr)[_idx]) == std::ranges::end((*_viewsPtr)[_idx]))) {
        ++_idx;
      }

      if(_idx < N) {
        _it = std::ranges::begin((*_viewsPtr)[_idx]);
      }
    }

    size_t _idx;
    base_iterator _it;
    std::array<TView, N>* _viewsPtr;
  };

public:
  uniform_concat_view(uniform_concat_view&&) = default;
  uniform_concat_view(const uniform_concat_view&) = default;

  ~uniform_concat_view() = default;

  uniform_concat_view& operator=(uniform_concat_view&&) = default;
  uniform_concat_view& operator=(const uniform_concat_view&) = default;

  template<typename... TViews>
  uniform_concat_view(TViews&&... views)
    : _views{std::forward<TViews>(views)...}
  {
  }

  iterator begin()
  {
    return iterator(&_views, 0);
  }

  iterator end()
  {
    return iterator(&_views, N);
  }

private:
  std::array<TView, N> _views;
};

template<typename TView, typename... TViews>
uniform_concat_view(TView&&, TViews&&...) -> uniform_concat_view<std::views::all_t<TView>, 1 + sizeof...(TViews)>;

struct uniform_concat_closure
{ 
  template<std::ranges::viewable_range R>
  friend auto operator|(R&& r, const uniform_concat_closure& self)
  {
    return self(std::forward<R>(r));
  }
};

struct uniform_concat_fn
{ 
  template<std::ranges::viewable_range... Rs>
  auto operator()(Rs&&... rs) const
  {
    return uniform_concat_view(std::views::all(std::forward<Rs>(rs))...);
  }
};

inline constexpr uniform_concat_fn uniform_concat{};
