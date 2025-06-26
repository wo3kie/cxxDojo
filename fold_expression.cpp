/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++17 fold_expression.cpp -o fold_expression
 *
 * Usage:
 *      $ ./fold_expression
 */

#include <cassert>

 template<typename... Ts>
 auto sub_right_1(Ts... ts) {
    /*
     * Unary right fold 
     * (E @ ...) = (E₁ @ (... @ (Eₙ₋₁ @ Eₙ)))
     */
    return (ts - ...);
 }

 template<typename... Ts>
 auto sub_right_2(Ts... ts) {
    /*
     * Binary right fold 
     * (E @ ... @ I) = (E₁ @ (... @ (Eₙ₋₁ @ (Eₙ @ I))))
     */

    return (ts - ... - 0);
 }

 template<typename... Ts>
 auto sub_left_1(Ts... ts) {
    /*
     * Unary left fold 
     * (... @ E) = (((E₁ @ E₂) @ ...) @ Eₙ)
     */
    return (... - ts);
 }

 template<typename... Ts>
 auto sub_left_2(Ts... ts) {
    /*
     * Binary left fold 
     * (I @ ... @ E) = ((((I @ E₁) @ E₂) @ ...) @ Eₙ)
     */
    return (0 - ... - ts);
 }

int main() {
    assert(sub_left_1(1, 2, 3, 4) == ((1 - 2) - 3) - 4);
    assert(sub_left_1(1, 2, 3, 4) == (-1 - 3) - 4);
    assert(sub_left_1(1, 2, 3, 4) == -4 - 4);
    assert(sub_left_1(1, 2, 3, 4) == -8);

    assert(sub_left_2(1, 2, 3, 4) == (((0 - 1) - 2) - 3) - 4);
    assert(sub_left_2(1, 2, 3, 4) == ((-1 - 2) - 3) - 4);
    assert(sub_left_2(1, 2, 3, 4) == (-3 - 3) - 4);
    assert(sub_left_2(1, 2, 3, 4) == -6 - 4);
    assert(sub_left_2(1, 2, 3, 4) == -10);

    assert(sub_right_1(1, 2, 3, 4) == (1 - (2 - (3 - 4))));
    assert(sub_right_1(1, 2, 3, 4) == (1 - (2 + 1)));
    assert(sub_right_1(1, 2, 3, 4) == (1 - 3));
    assert(sub_right_1(1, 2, 3, 4) == -2);

    assert(sub_right_2(1, 2, 3, 4) == (1 - (2 - (3 - (4 - 0)))));
    assert(sub_right_2(1, 2, 3, 4) == (1 - (2 + 1)));
    assert(sub_right_2(1, 2, 3, 4) == (1 - 3));
    assert(sub_right_2(1, 2, 3, 4) == -2);
}
