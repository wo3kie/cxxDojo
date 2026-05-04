#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <optional>

#include <functional>
#include <memory>
#include <optional>
#include <queue>
#include <tuple>

template<typename TValue, typename TCompare, typename... TPredicates>
class Store {
public:
  explicit Store(TCompare compare, TPredicates... preds)
      : m_compare(std::move(compare))
      , m_preds(std::move(preds)...) {
  }

  Store(Store&&) = default;
  Store& operator=(Store&&) = default;

  ~Store() = default;

  Store& operator=(const Store&) = default;
  Store(const Store&) = default;

public:
  bool insert(TValue value) {
    if(! std::apply([&](auto&... preds) { return (preds(value) && ...); }, m_preds)) {
      return false;
    }

    if(! m_data) {
      m_data = std::move(value);
      return true;
    }

    if (! m_compare(value, *m_data)) {
      return false;
    }

    m_data = std::move(value);
    return true;
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
  std::optional<TValue> m_data;

  TCompare m_compare;
  std::tuple<TPredicates...> m_preds;
};

template<typename TValue, typename TCompare, typename... TPredicates>
auto make_store(TCompare compare, TPredicates... preds) -> Store<TValue, TCompare, TPredicates...> {
  return Store<TValue, TCompare, TPredicates...>(std::move(compare), std::move(preds)...);
}

template<typename TValue>
auto make_store_min() {
  return Store<TValue, std::less<TValue>>(std::less<TValue>());
}

template<typename TValue>
auto make_store_max() {
  return Store<TValue, std::greater<TValue>>(std::greater<TValue>());
}

template<typename TValue, typename... TPredicates>
auto make_store_first(TPredicates... preds) {
  auto compare = [](bool, bool) -> bool { //
    return false;
  };

  return Store<TValue, decltype(compare), TPredicates...>(compare, std::move(preds)...);
}

auto make_store_true() {
  auto compare = [](bool, bool) -> bool { //
    return false;
  };

  auto predicate = [](bool newValue) -> bool { //
    return newValue;
  };

  return Store<bool, decltype(compare), decltype(predicate)>(compare, predicate);
}

auto make_store_false() {
  auto compare = [](bool, bool) -> bool { //
    return false;
  };

  auto predicate = [](bool newValue) -> bool { //
    return !newValue;
  };

  return Store<bool, decltype(compare), decltype(predicate)>(compare, predicate);
}

template<typename TValue, typename TCompare, typename... TPredicates>
struct StoreN {
public:
  using const_reference = const TValue&;
  using const_iterator = const TValue*;

public:
  explicit StoreN(std::size_t n, TCompare compare = TCompare(), TPredicates... preds)
      : _size(0)
      , _capacity(n)
      , _data(std::make_unique<TValue[]>(n))
      , _compare(std::move(compare))
      , _predicates(std::move(preds)...) {
  }

  StoreN(StoreN&&) = default;
  StoreN(const StoreN&) = delete;

  ~StoreN() = default;

  StoreN& operator=(StoreN&&) = default;
  StoreN& operator=(const StoreN&) = delete;

public:
  bool insert(TValue value) {
    if(! std::apply([&](auto&... preds) { return (preds(value) && ...); }, _predicates)) {
      return false;
    }

    if(_size < _capacity) {
      _data[_size] = std::move(value);
      heapify(_data.get(), _size++);
      return true;
    }

    if(! _compare(value, _data[_capacity - 1])) {
      return false;
    }

    _data[_size - 1] = std::move(value);
    heapify(_data.get(), _size - 1);
    return true;
  }

  bool operator<<(TValue value) {
    return insert(std::move(value));
  }

  [[nodiscard]] std::size_t size() const {
    return _size;
  }

  [[nodiscard]] std::size_t capacity() const {
    return _capacity;
  }

  const_iterator begin() const {
    return &_data[0];
  }

  const_iterator end() const {
    return &_data[_size];
  }

private:
  void heapify(TValue* data, std::size_t currentIndex) {
    while(currentIndex != 0) {
      const std::size_t parentIndex = getParentIndex(currentIndex);

      TValue& current = data[currentIndex];
      TValue& parent = data[parentIndex];

      if(_compare(parent, current)) {
        return;
      }

      std::swap(current, parent);
      currentIndex = parentIndex;
    }
  }

  static int getParentIndex(std::size_t index) {
    return (index - 1) / 2;
  }

private:
  std::size_t _size;
  std::size_t _capacity;

  std::unique_ptr<TValue[]> _data;
  TCompare _compare;
  std::tuple<TPredicates...> _predicates;
};

template<typename TValue, typename TCompare, typename... TPredicates>
auto make_store_n(std::size_t n, TCompare compare, TPredicates... preds) -> StoreN<TValue, TCompare, TPredicates...> {
  return StoreN<TValue, TCompare, TPredicates...>(n, std::move(compare), std::move(preds)...);
}
