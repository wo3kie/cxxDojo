/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
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
      return _ranges == other._ranges && 
              _idx == other._idx && 
              (_idx == sizeof...(Ranges) || _iterator == other._iterator);
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
