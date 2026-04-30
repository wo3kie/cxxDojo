#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */
#pragma once

#include <ranges>
#include <type_traits>
#include <utility>

template<std::ranges::view TView, class TPred>
struct filter_view: std::ranges::view_interface<filter_view<TView, TPred>>
{
  struct iterator
  {
  public:
    using base_iterator = std::ranges::iterator_t<TView>;
    using value_type = std::ranges::range_value_t<TView>;
    using reference = std::ranges::range_reference_t<TView>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    iterator() = default;

    iterator(filter_view* parent, base_iterator it, base_iterator end)
      : _parent(parent)
      , _it(it)
      , _end(end)
    {
      set();
    }

    reference operator*() const
    {
      return *_it;
    }

    iterator& operator++()
    {
      ++_it;
      set();
      return *this;
    }

    void operator++(int)
    {
      ++(*this);
    }

    friend bool operator==(const iterator& a, const iterator& b)
    {
      return a._it == b._it;
    }

    friend bool operator!=(const iterator& a, const iterator& b)
    {
      return ! (a == b);
    }

  private:
    void set()
    {
      while(_it != _end && ! _parent->_pred(*_it)) {
        ++_it;
      }
    }

    filter_view* _parent = nullptr;
    base_iterator _it{};
    base_iterator _end{};
  };

public:
  using value_type = std::ranges::range_value_t<TView>;
  using reference = std::ranges::range_reference_t<TView>;

  filter_view() = default;

  filter_view(TView view, TPred pred)
    : _view(std::move(view))
    , _pred(std::move(pred))
  {
  }

  filter_view(filter_view&&) = default;
  filter_view(const filter_view&) = default;
  filter_view& operator=(filter_view&&) = default;
  filter_view& operator=(const filter_view&) = default;

  iterator begin()
  {
    return iterator(this, std::ranges::begin(_view), std::ranges::end(_view));
  }

  iterator end()
  {
    auto e = std::ranges::end(_view);
    return iterator(this, e, e);
  }

private:
  TView _view;
  TPred _pred;
};

template<std::ranges::viewable_range R, class Pred>
filter_view(R&&, Pred) -> filter_view<std::views::all_t<R>, std::decay_t<Pred>>;

template<typename TValue, class TPred>
struct filter_closure
{
  TPred _pred;

  template<std::ranges::viewable_range R>
  auto operator()(R&& r) const
  {
    return filter_view<std::views::all_t<R>, TPred>(std::views::all(std::forward<R>(r)), _pred);
  }

  template<std::ranges::viewable_range R>
  friend auto operator|(R&& r, const filter_closure& self)
  {
    return self(std::forward<R>(r));
  }
};

struct filter_fn
{
  template<class Pred>
  auto operator()(Pred pred) const
  {
    using TValue = void;
    return filter_closure<TValue, std::decay_t<Pred>>{std::move(pred)};
  }

  template<std::ranges::viewable_range R, class Pred>
  auto operator()(R&& r, Pred pred) const
  {
    return filter_view<std::views::all_t<R>, std::decay_t<Pred>>(std::views::all(std::forward<R>(r)), std::move(pred));
  }
};

inline constexpr filter_fn filter{};
