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

  {
    struct S {
      int i;

      bool operator==(const S& other) const {
        return i == other.i;
      }
    };

    /*
     * Not implemented
     *
     * std::ostream& operator<<(std::ostream&, const S&)
     */

    Assert(S{1} == S{1});
  }

  {
    /*
     * Print ".../cxxDojo/assert.cpp:22 Assertion failed 1 == 2"
     */

    Assert(1 == 2).on_error([](const char* file, int line, const char* op, const auto& first, const auto& second) -> void {
      std::cerr << file << ':' << line << " Assertion failed " << first << ' ' << op << ' ' << second << std::endl;

      /*
       * Do not terminate the program yet
       *
       * std::abort();
       */
    });
  }

  {
    /*
     * Print ".../cxxDojo/assert.cpp:28 Assertion failed 3 == 4" and terminate the program by calling `std::abort`
     */

    const int actual = 3;
    const int expected = 4;
    Assert(actual == expected);
  }
}
