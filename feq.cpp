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

#include "./assert.hpp"

/*
 * feq_test
 */

void feq_test() {
  Assert(feq(0.1f + 0.2f, 0.3f));
  Assert(feq(0.1 + 0.2, 0.3));
  Assert(feq(0.1l + 0.2l, 0.3l));
}

/*
 * main
 */

int main() {
  feq_test();
}
