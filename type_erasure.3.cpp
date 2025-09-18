/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 typeErasure.3.cpp -o typeErasure.3
 *
 * Usage:
 *      $ ./typeErasure.3
 */

#include <cassert>
#include <functional>
#include <list>
#include <vector>

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
 * PreIncrementTypeErasure
 */

struct PreIncrementTypeErasure {
  PreIncrementTypeErasure() = default;
  PreIncrementTypeErasure(const PreIncrementTypeErasure&) = default;
  PreIncrementTypeErasure(PreIncrementTypeErasure&&) noexcept = default;

  ~PreIncrementTypeErasure() = default;

  PreIncrementTypeErasure& operator=(const PreIncrementTypeErasure&) = default;
  PreIncrementTypeErasure& operator=(PreIncrementTypeErasure&&) noexcept = default;

  template<typename T>
  void init() {
    _pre_increment = [](void* ptr) {
      ++(*static_cast<T*>(ptr));
    };
  }

  std::function<void(void*)> _pre_increment;
};

/*
 * DereferenceTypeErasure<T>
 */

template<typename T>
struct DereferenceTypeErasure {
  DereferenceTypeErasure() = default;
  DereferenceTypeErasure(const DereferenceTypeErasure&) = default;
  DereferenceTypeErasure(DereferenceTypeErasure&&) noexcept = default;

  ~DereferenceTypeErasure() = default;

  DereferenceTypeErasure& operator=(const DereferenceTypeErasure&) = default;
  DereferenceTypeErasure& operator=(DereferenceTypeErasure&&) noexcept = default;

  template<typename U>
  void init() {
    _dereference = [](void* ptr) -> T& {
      return **static_cast<U*>(ptr);
    };
  }

  std::function<T&(void*)> _dereference;
};

/*
 * EqualTypeErasure
 */

struct EqualTypeErasure {
  EqualTypeErasure() = default;
  EqualTypeErasure(const EqualTypeErasure&) = default;
  EqualTypeErasure(EqualTypeErasure&&) noexcept = default;

  ~EqualTypeErasure() = default;

  EqualTypeErasure& operator=(const EqualTypeErasure&) = default;
  EqualTypeErasure& operator=(EqualTypeErasure&&) noexcept = default;

  template<typename T>
  void init() {
    _equal = [](const void* ptr1, const void* ptr2) -> bool {
      if(ptr1 == nullptr && ptr2 == nullptr) {
        return true;
      }

      if(ptr1 == nullptr || ptr2 == nullptr) {
        return false;
      }

      return *static_cast<const T*>(ptr1) == *static_cast<const T*>(ptr2);
    };
  }

  std::function<bool(const void*, const void*)> _equal;
};

/*
 * IteratorTypeErasure
 */

template<typename Value>
struct IteratorTypeErasure: TypeErasureBase, PreIncrementTypeErasure, DereferenceTypeErasure<int>, EqualTypeErasure {
  template<typename Iterator>
  IteratorTypeErasure(const Iterator& iterator)
      : TypeErasureBase(iterator) {
    PreIncrementTypeErasure::init<Iterator>();
    DereferenceTypeErasure<int>::init<Iterator>();
    EqualTypeErasure::init<Iterator>();
  }

  IteratorTypeErasure(const IteratorTypeErasure& other) = default;
  IteratorTypeErasure(IteratorTypeErasure&& other) noexcept = default;

  ~IteratorTypeErasure() = default;

  IteratorTypeErasure& operator=(const IteratorTypeErasure& other) = default;
  IteratorTypeErasure& operator=(IteratorTypeErasure&& other) noexcept = default;

  IteratorTypeErasure& operator++() {
    _pre_increment(_ptr);
    return *this;
  }

  Value& operator*() {
    return _dereference(_ptr);
  }

  bool operator==(const IteratorTypeErasure& other) const {
    return _equal(_ptr, other._ptr);
  }
};

/*
 * CTAD - Class Template Argument Deduction
 */

template<typename Iterator>
IteratorTypeErasure(Iterator) -> IteratorTypeErasure<typename std::iterator_traits<Iterator>::value_type>;

/*
 * test
 */

void IteratorTypeErasure_test_1() {
  std::vector<int> v{1, 2, 3};

  IteratorTypeErasure begin(v.begin());
  IteratorTypeErasure end(v.end());

  assert(*begin == 1);
  ++begin;
  assert(*begin == 2);
  ++begin;
  assert(*begin == 3);
  ++begin;
  assert(begin == end);
}

void IteratorTypeErasure_test_2() {
  std::list<int> v{1, 2, 3};

  IteratorTypeErasure begin(v.begin());
  IteratorTypeErasure end(v.begin());

  IteratorTypeErasure copy = begin;
  assert(copy == begin);

  IteratorTypeErasure move = std::move(copy);
  assert(move == begin);

  copy = begin;
  assert(copy == begin);

  move = std::move(copy);
  assert(move == begin);
}

/*
 * main
 */

int main() {
  IteratorTypeErasure_test_1();
  IteratorTypeErasure_test_2();

  return 0;
}
