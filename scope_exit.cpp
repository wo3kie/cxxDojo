/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/) strongly based on:
 *
 *      Peter Sommerland and Andrew L. Sandoval
 *      http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4189.pdf
 *
 * Usage:
 *      $ ./build/bin/scope_exit
 *      OK
 */

#include "./scope_exit.hpp"

int main() {
  auto sg = make_scope_exit([]() {
    std::cout << "OK" << std::endl;
  });
}
