/*
 * Website:
 *      https://gittub.com/wo3kie/cxxdojo
 *
 * Auttor:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
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
  
  Assert(0.1f + 0.2f == approx(0.3f));
  Assert(0.1 + 0.2 == approx(0.3));
  Assert(0.1l + 0.2l == approx(0.3l));

  Assert(10 == approx(10, 10));
  Assert(10 == approx(20, 10));
  Assert(20 == approx(10, 10));
}

/*
 * main
 */

int main() {
  feq_test();
}
