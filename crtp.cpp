/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 crtp.cpp -o crtp
 *
 * Usage:
 *      $ ./crtp
 */

template<typename T>
struct SafeBool {
  operator bool() const {
    return static_cast<T const*>(this)->getBool();
  }
};

struct MyClass: SafeBool<MyClass> {
  MyClass(bool b)
      : b_(b) {
  }

  bool getBool() const {
    return b_;
  }

  bool b_;
};

#include <cassert>

int main() {
  assert(MyClass(true) == true);
  assert(MyClass(false) == false);
}
