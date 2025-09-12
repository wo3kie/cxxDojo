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

 /*
  * SafeBool
  */
 
template<typename T>
struct SafeBool {
  operator bool() const {
    return static_cast<const T*>(this)->getBool();
  }
};

/*
 * MyClass
 */

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

/*
 * main
 */

int main() {
  assert(MyClass(true) == true);
  assert(MyClass(false) == false);
}
