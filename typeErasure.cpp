/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 typeErasure.cpp -o typeErasure
 *
 * Usage:
 *      $ ./typeErasure
 */

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace dynamic {

/*
 * +-- Any ---------------------------------------------------+
 * |                                                          |
 * |               +-- InnerBase ----+                        |
 * |               |                 |                        |
 * |               +-----------------+                        |
 * |                     ^       ^                            |
 * |                    /         \                           |
 * | +-- Inner< int > ----+    +-- Inner< std::string > ----+ |
 * | | int value = 23     |    | std::string value = "C++"  | |
 * | +--------------------+    +----------------------------+ |
 * |                                                          |
 * +----------------------------------------------------------+
 *
 */

struct InnerBase {
  typedef std::unique_ptr<InnerBase> Ptr;

  virtual InnerBase* clone() const = 0;
};

template<typename T>
struct Inner: InnerBase {
  Inner(T t)
      : _value(t) {
  }

  virtual InnerBase* clone() const override {
    return new Inner(_value);
  }

  T& get() {
    return _value;
  }

  T const& get() const {
    return _value;
  }

  T _value;
};

struct Any {
  template<typename T>
  Any(T t)
      : _inner(new Inner<T>(t)) {
  }

  Any(Any const& other)
      : _inner(other._inner->clone()) {
  }

  template<typename T>
  Any& operator=(T const& t) {
    _inner = std::make_unique<Inner<T>>(t);
    return *this;
  }

  Any& operator=(const Any& other) {
    Any tmp(other);
    std::swap(tmp, *this);
    return *this;
  }

  template<typename T>
  T& cast() {
    return dynamic_cast<Inner<T>&>(*_inner).get();
  }

  template<typename T>
  T const& cast() const {
    return dynamic_cast<Inner<T>&>(*_inner).get();
  }

private:
  typename InnerBase::Ptr _inner;
};

void test() {
  Any v{23};
  assert(v.cast<int>() == 23);
  
  v = std::string("C++");
  assert(v.cast<std::string>() == "C++");
}

} // dynamic

namespace lambda {

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

//

struct S {
    char run(int i, double d) {
        return 's';
    }
};

struct T {
    char run(int i, double d){
        return 't';
    }
};

/*
 *
 */

struct Runnable {
    template<typename R>
    Runnable(R& r)
        : _ptr(&r)
        , _run([this](void* ptr) -> std::function<char (int, double)> {
            return [p = static_cast<R*>(this->_ptr)](int i, double d) -> char { return p->run(i, d); };
        })
    {
    }

    char run(int i, double d) {
        return _run(_ptr)(i, d);
    }

    void* _ptr;
    std::function<std::function<char (int, double)> (void*)> _run;
};

char f(Runnable r) {
    return r.run(1, 2.3);
}

void test() {
    S s;
    assert(f(Runnable{s}) == 's');
   
    T t;
    assert(f(Runnable{t}) == 't');
}

} // lambda

int main() {
  dynamic::test();
  lambda::test();
}
