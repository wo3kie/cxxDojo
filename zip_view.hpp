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
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

#include "./assert.hpp"
#include "./tuple.hpp"

/*
 * zip_view
 */

#pragma once

#include <iterator>
#include <ranges>
#include <tuple>
#include <utility>

template<std::ranges::view... TViews>
struct zip_view: std::ranges::view_interface<zip_view<TViews...>>
{
public:
  struct iterator
  {
  public:
    using value_type = std::tuple<std::ranges::range_value_t<TViews>...>;
    using reference = std::tuple<std::ranges::range_reference_t<TViews>...>;
    using pointer = std::tuple<std::add_pointer_t<std::ranges::range_reference_t<TViews>>...>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

  public:
    explicit iterator(std::tuple<std::ranges::iterator_t<TViews>...> iterators)
      : _iterators(std::move(iterators))
    {
    }

    reference operator*() const
    {
      return deref(std::index_sequence_for<TViews...>{});
    }

    iterator& operator++()
    {
      inc(std::index_sequence_for<TViews...>{});
      return *this;
    }

    bool operator==(const iterator& other) const
    {
      return _iterators == other._iterators;
    }

  private:
    template<std::size_t... Is>
    reference deref(std::index_sequence<Is...>) const
    {
      return reference{*std::get<Is>(_iterators)...};
    }

    template<std::size_t... Is>
    void inc(std::index_sequence<Is...>)
    {
      (..., ++std::get<Is>(_iterators));
    }

  private:
    std::tuple<std::ranges::iterator_t<TViews>...> _iterators;
  };

public:
  explicit zip_view(TViews... views)
    : _views(std::move(views)...)
  {
  }

  iterator begin()
  {
    return make_iterator(false, std::index_sequence_for<TViews...>{});
  }

  iterator end()
  {
    return make_iterator(true, std::index_sequence_for<TViews...>{});
  }

private:
  template<std::size_t... Is>
  iterator make_iterator(bool isEnd, std::index_sequence<Is...>)
  {
    if(isEnd) {
      return iterator{std::make_tuple(std::ranges::end(std::get<Is>(_views))...)};
    } else {
      return iterator{std::make_tuple(std::ranges::begin(std::get<Is>(_views))...)};
    }
  }

private:
  std::tuple<TViews...> _views;
};

template<std::ranges::viewable_range... Rs>
zip_view(Rs&&...) -> zip_view<std::views::all_t<Rs>...>;

struct zip_closure
{
  template<std::ranges::viewable_range... Rs>
  friend auto operator|(std::tuple<Rs...>&& rs, const zip_closure& self)
  {
    return self(std::forward<Rs>(rs)...);
  }
};

struct zip_fn
{
  template<std::ranges::viewable_range... Rs>
  auto operator()(Rs&&... rs) const
  {
    return zip_view{std::views::all(std::forward<Rs>(rs))...};
  }
};

inline constexpr zip_fn zip{};
