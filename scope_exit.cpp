/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski strongly based on:
 *
 *      Peter Sommerland and Andrew L. Sandoval
 *      http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4189.pdf
 *
 * Compilation:
 *      g++ --std=c++20 scope_exit.cpp -o scope_exit
 *
 * Usage:
 *      $ ./scope_exit
 *      OK
 */

#include "./scope_exit.hpp"

int main() {
  auto sg = make_scope_exit([]() {
    std::cout << "OK" << std::endl;
  });
}
