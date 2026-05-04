#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

 #include <cassert>
 #include <ranges>

template<std::ranges::view TView>
class chunk_view: public std::ranges::view_interface<chunk_view<TView>>
{
  struct iterator
  {
    using base_iterator = std::ranges::iterator_t<TView>;
    using value_type = std::ranges::subrange<base_iterator>;
    using reference = std::ranges::subrange<base_iterator>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;
    using pointer = void;

    iterator() = default;

    iterator(base_iterator current, base_iterator end, std::size_t chunk_size)
      : _chunk_size{chunk_size}
      , _from{current}
      , _to{current}
      , _end{end}
    {
      std::ranges::advance(_to, _chunk_size, _end);
    }

    reference operator*() const
    {
      return {_from, _to};
    }

    iterator& operator++()
    {
      _from = _to;
      std::ranges::advance(_to, _chunk_size, _end);
      return *this;
    }

    iterator operator++(int)
    {
      iterator copy = *this;
      ++(*this);
      return copy;
    }

    bool operator==(const iterator& other) const
    {
      return _from == other._from;
    }

  private:
    std::size_t _chunk_size{};

    std::ranges::iterator_t<TView> _from{};
    std::ranges::iterator_t<TView> _to{};
    std::ranges::iterator_t<TView> _end{};
  };

public:
  auto begin() const
  {
    return iterator{std::ranges::begin(_view), std::ranges::end(_view), _chunk_size};
  }

  auto begin()
  {
    return iterator{std::ranges::begin(_view), std::ranges::end(_view), _chunk_size};
  }

  auto end() const
  {
    return iterator{std::ranges::end(_view), std::ranges::end(_view), _chunk_size};
  }

  auto end()
  {
    return iterator{std::ranges::end(_view), std::ranges::end(_view), _chunk_size};
  }

public:
  chunk_view() = default;

  chunk_view(TView base, std::size_t chunk_size)
    : _view{std::move(base)}
    , _chunk_size{chunk_size}
  {
    assert(_chunk_size > 0);
  }

private:
  TView _view{};
  std::size_t _chunk_size{};
};

template<std::ranges::viewable_range R>
chunk_view(R&&, std::size_t) -> chunk_view<std::views::all_t<R>>;

struct chunk_closure
{
  std::size_t _chunk_size{};

  template<std::ranges::viewable_range R>
  auto operator()(R&& r) const
  {
    return chunk_view{std::views::all(std::forward<R>(r)), _chunk_size};
  }

  template<std::ranges::viewable_range R>
  friend auto operator|(R&& r, const chunk_closure& self)
  {
    return self(std::forward<R>(r));
  }
};

struct chunk_fn
{
  auto operator()(std::size_t chunk_size) const
  {
    return chunk_closure{chunk_size};
  }

  template<std::ranges::viewable_range R>
  auto operator()(R&& r, std::size_t chunk_size) const
  {
    return chunk_view{std::views::all(std::forward<R>(r)), chunk_size};
  }
};

inline constexpr chunk_fn chunk{};
