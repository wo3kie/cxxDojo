/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/feq
 */

#include "./feq.hpp"

#include <cassert>

/*
 * feq_test
 */

void feq_test() {
  assert(feq(0.1f + 0.2f, 0.3f));
  assert(feq(0.1 + 0.2, 0.3));
  assert(feq(0.1l + 0.2l, 0.3l));
}

/*
 * main
 */

int main() {
  feq_test();
}
