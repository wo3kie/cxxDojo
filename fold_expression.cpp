/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/fold_expression
 */

#include "./assert.hpp"

template<typename... Ts>
auto right_1(Ts... ts) {
  /*
     * Unary right fold 
     * (E @ ...) = (E₁ @ (... @ (Eₙ₋₁ @ Eₙ)))
     */
  return (ts - ...);
}

template<typename... Ts>
auto right_2(Ts... ts) {
  /*
     * Binary right fold 
     * (E @ ... @ I) = (E₁ @ (... @ (Eₙ₋₁ @ (Eₙ @ I))))
     */

  return (ts - ... - 0);
}

template<typename... Ts>
auto left_1(Ts... ts) {
  /*
     * Unary left fold 
     * (... @ E) = (((E₁ @ E₂) @ ...) @ Eₙ)
     */
  return (... - ts);
}

template<typename... Ts>
auto left_2(Ts... ts) {
  /*
     * Binary left fold 
     * (I @ ... @ E) = ((((I @ E₁) @ E₂) @ ...) @ Eₙ)
     */
  return (0 - ... - ts);
}

/*
 * main
 */

int main() {
  Assert(left_1(1, 2, 3, 4) == ((1 - 2) - 3) - 4);
  Assert(left_1(1, 2, 3, 4) == (-1 - 3) - 4);
  Assert(left_1(1, 2, 3, 4) == -4 - 4);
  Assert(left_1(1, 2, 3, 4) == -8);

  Assert(left_2(1, 2, 3, 4) == (((0 - 1) - 2) - 3) - 4);
  Assert(left_2(1, 2, 3, 4) == ((-1 - 2) - 3) - 4);
  Assert(left_2(1, 2, 3, 4) == (-3 - 3) - 4);
  Assert(left_2(1, 2, 3, 4) == -6 - 4);
  Assert(left_2(1, 2, 3, 4) == -10);

  Assert(right_1(1, 2, 3, 4) == (1 - (2 - (3 - 4))));
  Assert(right_1(1, 2, 3, 4) == (1 - (2 + 1)));
  Assert(right_1(1, 2, 3, 4) == (1 - 3));
  Assert(right_1(1, 2, 3, 4) == -2);

  Assert(right_2(1, 2, 3, 4) == (1 - (2 - (3 - (4 - 0)))));
  Assert(right_2(1, 2, 3, 4) == (1 - (2 + 1)));
  Assert(right_2(1, 2, 3, 4) == (1 - 3));
  Assert(right_2(1, 2, 3, 4) == -2);
}
