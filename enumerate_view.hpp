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

template<std::ranges::view TView>
struct enumerate_view: public std::ranges::view_interface<enumerate_view<TView>>
{
  struct iterator
  {
    using base_iterator = std::ranges::iterator_t<TView>;
    using reference = std::tuple<std::size_t, std::ranges::range_reference_t<TView>>;
    using value_type = std::tuple<std::size_t, std::ranges::range_value_t<TView>>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::input_iterator_tag;

    iterator() = default;

    iterator(base_iterator it, std::size_t idx)
      : _it(it)
      , _idx(idx)
    {
    }

    reference operator*() const
    {
      return {_idx, *_it};
    }

    iterator& operator++()
    {
      ++_idx;
      ++_it;
      return *this;
    }

    void operator++(int)
    {
      ++(*this);
    }

    friend bool operator==(const iterator& lhs, const iterator& rhs)
    {
      return lhs._it == rhs._it;
    }

  private:
    base_iterator _it{};
    std::size_t _idx{0};
  };

public:
  enumerate_view() = default;

  explicit enumerate_view(TView view)
    : _view(std::move(view))
  {
  }

  enumerate_view(enumerate_view&&) = default;
  enumerate_view(const enumerate_view&) = default;

  ~enumerate_view() = default;

  enumerate_view& operator=(enumerate_view&&) = default;
  enumerate_view& operator=(const enumerate_view&) = default;

  iterator begin()
  {
    return iterator(std::ranges::begin(_view), 0);
  }

  iterator end()
  {
    return iterator(std::ranges::end(_view), std::ranges::distance(_view));
  }

private:
  TView _view{};
};

template<std::ranges::viewable_range R>
enumerate_view(R&&) -> enumerate_view<std::views::all_t<R>>;

struct enumerate_closure
{
  template<std::ranges::viewable_range R>
  auto operator()(R&& r) const
  {
    return enumerate_view(std::views::all(std::forward<R>(r)));
  }
  
  template<std::ranges::viewable_range R>
  friend auto operator|(R&& r, const enumerate_closure& self)
  {
    return self(std::forward<R>(r));
  }
};

struct enumerate_fn
{
  auto operator()() const
  {
    return enumerate_closure{};
  }
  
  template<std::ranges::viewable_range R>
  auto operator()(R&& r) const
  {
    return enumerate_view(std::views::all(std::forward<R>(r)));
  }
};

inline constexpr enumerate_fn enumerate{};
