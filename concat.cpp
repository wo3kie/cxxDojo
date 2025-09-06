#include <cassert>
#include <functional>
#include <list>
#include <vector>

/*
 * IteratorTypeErasure
 */

template<typename T>
struct IteratorTypeErasure {
public:
  template<typename I>
  IteratorTypeErasure(I&& i)
      : _ptr(new I(std::move(i)))
      , _destroy([](void* ptr) -> void {
        delete static_cast<I*>(ptr);
      })
      , _pre_increment([](void* ptr) -> void {
        ++(*static_cast<I*>(ptr));
      })
      , _post_increment([](void* ptr) -> void {
        (*static_cast<I*>(ptr))++;
      })
      , _dereference([](void* ptr) -> T& {
        return *(*static_cast<I*>(ptr));
      })
      , _equal([](void const* ptr1, void const* ptr2) -> bool {
        return (*static_cast<I const*>(ptr1)) == (*static_cast<I const*>(ptr2));
      }) {
  }

  ~IteratorTypeErasure() {
    _destroy(_ptr);
  }

public:
  void pre_increment() {
    return _pre_increment(_ptr);
  }

  void post_increment() {
    return _post_increment(_ptr);
  }

  T& dereference() {
    return _dereference(_ptr);
  }

  bool equal(const IteratorTypeErasure& other) const {
    return _equal(_ptr, other.ptr());
  }

public:
  void const* ptr() const {
    return _ptr;
  }

private:
  void* _ptr{nullptr};

  std::function<void(void*)> _destroy;
  std::function<void(void*)> _pre_increment;
  std::function<void(void*)> _post_increment;
  std::function<T&(void*)> _dereference;
  std::function<bool(void const*, void const*)> _equal;
};

/*
 * CTAD - Class Template Argument Deduction
 */

template<typename I>
IteratorTypeErasure(I) -> IteratorTypeErasure<typename std::iterator_traits<I>::value_type>;

/*
 * IteretorTypeErasure_test
 */

void IteretorTypeErasure_test() {
  std::vector<int> vi{1, 2, 3};

  IteratorTypeErasure viBegin(vi.begin());
  IteratorTypeErasure viEnd(vi.end());

  assert(viBegin.equal(viEnd) == false);
  assert(viBegin.dereference() == 1);
  viBegin.pre_increment();

  assert(viBegin.equal(viEnd) == false);
  assert(viBegin.dereference() == 2);
  viBegin.pre_increment();

  assert(viBegin.equal(viEnd) == false);
  assert(viBegin.dereference() == 3);
  viBegin.pre_increment();

  assert(viBegin.equal(viEnd) == true);
}

int main() {
  IteretorTypeErasure_test();
}