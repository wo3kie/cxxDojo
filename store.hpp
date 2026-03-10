#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <optional>

template<typename TValue, typename... TPredicates>
class StoreIf {
public:
  explicit StoreIf(TPredicates... preds)
  : m_preds(std::move(preds)...)
  {}

  StoreIf(StoreIf&&) = default;
  StoreIf& operator=(StoreIf&&) = default;

  ~StoreIf() = default;

  StoreIf& operator=(const StoreIf&) = default;
  StoreIf(const StoreIf&) = default;

public:
  bool insert(TValue value) {
    return std::apply(
      [&](auto&... preds) {
        return (check_predicate(preds, value) && ...) 
                ? (m_data = std::move(value), true) 
                : false;
      },
      m_preds
    );
  }

  bool operator<<(TValue value) {
    return insert(std::move(value));
  }

  bool has_value() const noexcept {
    return m_data.has_value();
  }

  explicit operator bool() const noexcept {
    return has_value();
  }

  const TValue& value() const {
    return m_data.value();
  }

  const TValue& operator*() const {
    return value();
  }

  const std::optional<TValue>& data() const noexcept {
    return m_data;
  }

  void reset() {
    m_data.reset();
  }

private:
  template<typename P>
  bool check_predicate(P& p, const TValue& value) {
    if constexpr (std::predicate<P, TValue>) {
      return p(value);
    } else if constexpr (std::predicate<P, TValue, TValue>) {
      return !m_data || p(value, *m_data);
    } else {
      static_assert(sizeof(P) == 0, "Predicate must be unary or binary");
    }
  }

private:
  std::optional<TValue> m_data;
  std::tuple<TPredicates...> m_preds;
};

template<typename TValue, typename... TPredicates>
auto make_store_if(TPredicates... preds) -> StoreIf<TValue, TPredicates...> {
  return StoreIf<TValue, TPredicates...>(std::move(preds)...);
}
