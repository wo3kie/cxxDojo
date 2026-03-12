/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/assert
 */

#include "./assert.hpp"

/*
 * main
 */

int main() {
  Assert(true);
  Assert(! false);

  Assert(false == false);
  Assert(0 == 0);
  Assert(1 == 1);
  Assert(1 != 0);

  Assert(2==2);
  Assert((2==2));

  {
    struct S {
      int i;

      bool operator==(const S& other) const {
        return i == other.i;
      }
    };

    /*
     * No `std::ostream& operator<<(std::ostream&, const S&)` defined
     */

    Assert(S{1} == S{1});
  }

  {
    /*
     * Print ".../cxxDojo/assert.cpp:22 Assertion failed 0 == 1"
     */

    bool asserted = false;

    Assert(false).on_error([&asserted](const char* file, int line, const auto& actual) -> void {
      asserted = true;
    });

    assert(asserted);
  }

  {
    /*
     * Print ".../cxxDojo/assert.cpp:22 Assertion failed 1 == 2"
     */

    bool asserted = false;

    Assert(1 == 2).on_error([&asserted](const char* file, int line, const char* op, const auto& actual, const auto& expected) -> void {
      asserted = true;
    });

    assert(asserted);
  }

  std::cout << "All assertions passed!" << std::endl;
}
