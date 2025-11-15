/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/virtual_range
 */

#include <functional>

/*
 * IteratorTypeErasure
 */

struct TypeErasureBase {
  template<typename T>
  TypeErasureBase(const T& t)
      : _ptr(new T(t)) {
    _destroy = [](void* ptr) {
      if(ptr != nullptr) {
        delete static_cast<T*>(ptr);
      }
    };

    _copy = [](void** dst, void* src) {
      if(src == nullptr) {
        *dst = nullptr;
      } else {
        *dst = new T(*static_cast<T*>(src));
      }
    };
  }

  TypeErasureBase(const TypeErasureBase& other) {
    other._copy(&_ptr, other._ptr);

    _destroy = other._destroy;
    _copy = other._copy;
  }

  TypeErasureBase(TypeErasureBase&& other) noexcept
      : _ptr(other._ptr)
      , _destroy(other._destroy)
      , _copy(other._copy) {
    other._ptr = nullptr;
  }

  ~TypeErasureBase() {
    _destroy(_ptr);
  }

  TypeErasureBase& operator=(const TypeErasureBase& other) {
    if(this != &other) {
      _destroy(_ptr);
      other._copy(&_ptr, other._ptr);

      _destroy = other._destroy;
      _copy = other._copy;
    }

    return *this;
  }

  TypeErasureBase& operator=(TypeErasureBase&& other) noexcept {
    if(this != &other) {
      _destroy(_ptr);
      _ptr = other._ptr;
      other._ptr = nullptr;

      _destroy = other._destroy;
      _copy = other._copy;
    }

    return *this;
  }

  void* _ptr{nullptr};

  std::function<void(void**, void*)> _copy;
  std::function<void(void*)> _destroy;
};

/*
 * IteratorTypeErasure<V>
 * IteratorTypeErasure<const V>
 */

template<typename V>
struct IteratorTypeErasure: TypeErasureBase {
  using Value = std::conditional_t<std::is_const_v<V>, V, V&>;

  template<typename Iterator>
  IteratorTypeErasure(const Iterator& iterator)
      : TypeErasureBase(iterator) {
    _pre_increment = [](void* ptr) {
      ++(*static_cast<Iterator*>(ptr));
    };

    _dereference = [](void* ptr) -> Value {
      return *(*static_cast<Iterator*>(ptr));
    };

    _equal = [](const void* ptr1, const void* ptr2) -> bool {
      if(ptr1 == nullptr && ptr2 == nullptr) {
        return true;
      }

      if(ptr1 == nullptr || ptr2 == nullptr) {
        return false;
      }

      return *static_cast<const Iterator*>(ptr1) == *static_cast<const Iterator*>(ptr2);
    };
  }

  IteratorTypeErasure(const IteratorTypeErasure& other) = default;
  IteratorTypeErasure(IteratorTypeErasure&& other) noexcept = default;

  ~IteratorTypeErasure() = default;

  IteratorTypeErasure& operator=(const IteratorTypeErasure& other) = default;
  IteratorTypeErasure& operator=(IteratorTypeErasure&& other) noexcept = default;

  IteratorTypeErasure& operator++() {
    return this->_pre_increment(_ptr), *this;
  }

  Value operator*() {
    return this->_dereference(_ptr);
  }

  bool operator==(const IteratorTypeErasure& other) const {
    return this->_equal(_ptr, other._ptr);
  }

  bool operator!=(const IteratorTypeErasure& other) const {
    return !(*this == other);
  }

  std::function<void(void*)> _pre_increment;
  std::function<Value(void*)> _dereference;
  std::function<bool(const void*, const void*)> _equal;
};

#include <iostream>

/*
 * Virtual function + std::range
 */

using IntIterator = IteratorTypeErasure<int>;
using ConstIntIterator = IteratorTypeErasure<const int>;

struct Runner {
  virtual void print(ConstIntIterator begin, ConstIntIterator end) {
    for(auto it = begin; it != end; ++it) {
      std::cout << *it << " ";
    }

    std::cout << std::endl;
  }

  template<typename Range>
  void print(Range& range) {
    print(ConstIntIterator(std::begin(range)), ConstIntIterator(std::end(range)));
  }

  virtual void clear(IntIterator begin, IntIterator end) {
    for(auto it = begin; it != end; ++it) {
      *it = 0;
    }
  }

  template<typename Range>
  void clear(Range& range) {
    clear(IntIterator(std::begin(range)), IntIterator(std::end(range)));
  }
};

/*
 * main
 */

#include <vector>
#include <ranges>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};

  auto range = vec | std::views::filter([](int v) { return v % 2 == 0; });

  Runner().clear(range.begin(), range.end());
  Runner().clear(range);

  auto const_range = vec | std::views::filter([](int v) { return v % 2 == 0; })
                         | std::views::transform([](int v) { return v * v; });

  Runner().print(const_range.begin(), const_range.end());
  Runner().print(vec);

  std::cout << std::endl;
  return 0;
}
