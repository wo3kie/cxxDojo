/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 typeErasure.cpp.1 -o typeErasure.1
 *
 * Usage:
 *      $ ./typeErasure.1
 */

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

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

 /*
  * InnerBase
  */

struct InnerBase {
  typedef std::unique_ptr<InnerBase> Ptr;

  virtual InnerBase* clone() const = 0;
};

/*
 * Inner
 */

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

/*
 * Any
 */

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

/*
 * test
 */

void test() {
  Any v{23};
  assert(v.cast<int>() == 23);
  
  v = std::string("C++");
  assert(v.cast<std::string>() == "C++");
}

/*
 * main
 */

int main() {
  test();
}
