/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/timer
 */

#include "./timer.hpp"

/*
 * main
 */

int main() {
  test([]() -> void {
    for(int i = 0; i < 10; ++i) {
      std::cout << i << std::endl;
    }
  });
}
