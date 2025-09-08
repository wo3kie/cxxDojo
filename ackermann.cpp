/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 ackermann.cpp -o ackermann
 *
 * Usage:
 *      $ ./ackermann
 */

/*
 * https://en.wikipedia.org/wiki/Ackermann_function
 */

#include <cassert>

int ackermann(int m, int n) {
  if(m == 0) {
    return n + 1;
  }

  if(m > 0 && n == 0) {
    return ackermann(m - 1, 1);
  }

  if(m > 0 && n > 0) {
    return ackermann(m - 1, ackermann(m, n - 1));
  }

  assert(false);
}

void ackermann_test() {
  assert(ackermann(1, 1) == 3);
  assert(ackermann(1, 2) == 4);
  assert(ackermann(1, 3) == 5);

  assert(ackermann(2, 1) == 5);
  assert(ackermann(2, 2) == 7);
  assert(ackermann(2, 3) == 9);

  assert(ackermann(3, 1) == 13);
  assert(ackermann(3, 2) == 29);
  assert(ackermann(3, 3) == 61);

  // do you have enough time to try 4 ?
}

int main() {
  ackermann_test();
}
