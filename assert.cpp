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

  Assert(1 == 2).on_error([](const char* file, int line, const char* op, const auto& first, const auto& second) -> void {
    std::cerr << file << ':' << line << " Assertion failed " << first << ' ' << op << ' ' << second << std::endl;
  });

  const int actual = 3;
  const int expected = 4;
  Assert(actual == expected);
}
