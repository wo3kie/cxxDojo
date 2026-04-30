#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>

/*
 * Set of functions with no special logic but encapsulating type erasure of iterators. 
 * They are used as vtable entries in AnyIterator.
 * 
 * void (*ptr1)(void*) = nullptr;
 * ptr1 = &_destroy_impl< iterator_type_1 >;
 * ptr1 = &_destroy_impl< iterator_type_2 >;
 * ptr1 = &_destroy_impl< iterator_type_3 >;
 * and so on...
 */

template<typename Iter>
static void _destroy_impl(void* p) noexcept {
  reinterpret_cast<Iter*>(p)->~Iter();
}

template<typename Iter>
static void _copy_impl(const void* src, void* dst) {
  const auto& i = *reinterpret_cast<const Iter*>(src);
  new(dst) Iter(i);
}

template<typename Iter>
static void _move_impl(void* src, void* dst) {
  auto& i = *reinterpret_cast<Iter*>(src);
  new(dst) Iter(std::move(i));
}

template<typename Reference, typename Iter>
static Reference _dereference_impl(void* p) {
  const auto& i = *reinterpret_cast<Iter*>(p);
  return *i;
}

template<typename Iter>
static void _pre_increment_impl(void* p) {
  auto& i = *reinterpret_cast<Iter*>(p);
  ++i;
}

template<typename Iter>
static bool _equals_impl(const void* lhs, const void* rhs) {
  const auto& l = *reinterpret_cast<const Iter*>(lhs);
  const auto& r = *reinterpret_cast<const Iter*>(rhs);
  return l == r;
}

/*
 * AnyIterator
 *
 * A lightweight, zero‑allocation type‑erased forward iterator.
 *
 * This iterator is designed for high‑performance scenarios where:
 *   - the concrete iterator type is not known at compile time,
 *   - all iterators produce the same value_type T,
 *   - all iterators satisfy forward iterator requirements,
 *   - no dynamic allocation or RTTI is acceptable.
 *
 * Key properties:
 *   - Zero allocations: the underlying iterator is stored in a fixed-size
 *     inline buffer using placement-new.
 *
 *   - Zero virtual dispatch: dynamic behavior is implemented through a
 *     statically generated vtable (one per iterator type), with no runtime
 *     overhead beyond a single function pointer indirection.
 *
 *   - Zero RTTI: no typeid, no dynamic_cast, no std::any/std::function.
 *     All type information is erased at compile time.
 *
 *   - Strong value semantics: copying and moving the iterator preserves
 *     the underlying iterator state via vtable-provided operations.
 *
 *   - Reference integrity: dereferencing yields true references to the
 *     underlying elements; modifying through the iterator modifies the source.
 */

template<typename T, std::size_t MaxSize, std::size_t MaxAlign = alignof(std::max_align_t)>
class AnyIterator final {
public: // types
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using reference = T&;
  using pointer = T*;
  using iterator_category = std::forward_iterator_tag;

public: // ctors and assignment
  AnyIterator() noexcept
      : _vtable{nullptr} {
  }

  template<typename Iter>
  explicit AnyIterator(Iter it)
      : AnyIterator() 
  {
    static_assert(sizeof(Iter) <= MaxSize);
    static_assert(alignof(Iter) <= MaxAlign);
    static_assert(std::is_same_v<std::remove_reference_t<decltype(*it)>, T>);

    new(&_storage) Iter(std::move(it));
    _vtable = &vtable_for_type<Iter>;
  }

  AnyIterator(const AnyIterator& other)
      : AnyIterator() 
  {
    if(other._vtable == nullptr) {
      return;
    }

    other._vtable->copy_to(&other._storage, &_storage);
    _vtable = other._vtable;
  }

  AnyIterator(AnyIterator&& other) noexcept
      : AnyIterator() 
  {
    if(other._vtable == nullptr) {
      return;
    }

    other._vtable->move_to(&other._storage, &this->_storage);
    other._vtable->destroy(&other._storage);
    this->_vtable = other._vtable;
    other._vtable = nullptr;
  }

  ~AnyIterator() {
    reset();
  }

  AnyIterator& operator=(const AnyIterator& other) {
    if(this == std::addressof(other)) {
      return *this;
    }

    this->reset();

    if(other._vtable == nullptr) {
      return *this;
    }

    other._vtable->copy_to(&other._storage, &this->_storage);
    this->_vtable = other._vtable;

    return *this;
  }

  AnyIterator& operator=(AnyIterator&& other) noexcept {
    if(this == std::addressof(other)) {
      return *this;
    }

    this->reset();

    if(other._vtable == nullptr) {
      return *this;
    }

    other._vtable->move_to(&other._storage, &this->_storage);
    other._vtable->destroy(&other._storage);
    this->_vtable = other._vtable;
    other._vtable = nullptr;

    return *this;
  }

  void reset() noexcept {
    if(_vtable != nullptr) {
      _vtable->destroy(&_storage);
      _vtable = nullptr;
    }
  }

public: // api
  [[nodiscard]] reference operator*() const {
    return _vtable->dereference(const_cast<void*>(static_cast<const void*>(&_storage)));
  }

  pointer operator->() const {
    return std::addressof(operator*());
  }

  AnyIterator& operator++() {
    _vtable->pre_increment(&_storage);
    return *this;
  }

  AnyIterator operator++(int) {
    AnyIterator tmp(*this);
    _vtable->pre_increment(&_storage);
    return tmp;
  }

  [[nodiscard]] friend bool operator==(const AnyIterator& lhs, const AnyIterator& rhs) {
    if(lhs._vtable == nullptr && rhs._vtable == nullptr) {
      return true;
    }

    if(lhs._vtable == nullptr || rhs._vtable == nullptr) {
      return false;
    }

    if(lhs._vtable != rhs._vtable) {
      return false;
    }

    return lhs._vtable->equals(&lhs._storage, &rhs._storage);
  }

  [[nodiscard]] friend bool operator!=(const AnyIterator& lhs, const AnyIterator& rhs) {
    return ! (lhs == rhs);
  }

private: // vtable
  struct vtable_t {
    void (*destroy)(void*) noexcept;
    void (*copy_to)(const void*, void*);
    void (*move_to)(void*, void*);

    void (*pre_increment)(void*);
    reference (*dereference)(void*);

    bool (*equals)(const void*, const void*);
  };

  template<typename Iter>
  static inline const vtable_t vtable_for_type = {
      &_destroy_impl<Iter>, //
      &_copy_impl<Iter>,
      &_move_impl<Iter>,
      &_pre_increment_impl<Iter>,
      &_dereference_impl<reference, Iter>,
      &_equals_impl<Iter>};

  const vtable_t* _vtable{nullptr};

private: // storage
  alignas(MaxAlign) std::byte _storage[MaxSize];
};

template<typename Iter>
AnyIterator(Iter) -> AnyIterator<typename std::iterator_traits<Iter>::value_type, sizeof(Iter), alignof(Iter)>;

template<typename T, std::size_t MaxSize, std::size_t MaxAlign>
struct AnyRange {
  template<typename Range>
  AnyRange(Range&& range)
      : _begin(range.begin()), _end(range.end()) 
  {
  }

  using iterator = AnyIterator<T, MaxSize, MaxAlign>;

  iterator _begin;
  iterator _end;

  iterator begin() const {
    return _begin;
  }

  iterator end() const {
    return _end;
  }
};

template<typename Range>
auto any_range(Range& range) {
  using Iter = decltype(std::ranges::begin(range));
  using Value = typename std::iterator_traits<Iter>::value_type;
  return AnyRange<Value, sizeof(Iter), alignof(Iter)>(range);
}

template<typename Range>
auto any_range(const Range& range) {
  using Iter = decltype(std::ranges::begin(range));
  using Value = typename std::iterator_traits<Iter>::value_type;
  return AnyRange<const Value, sizeof(Iter), alignof(Iter)>(range);
}
