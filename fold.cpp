/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 fold.cpp -o fold
 *
 * Usage:
 *      $ ./fold
 */

#include <cassert>

#include "./fold.hpp"

int main(){
    std::function<int (int, int)> add = [](int i, int j) -> int { return i + j; };
    assert(rfold(add, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 45);
    assert(lfold(add, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 45);

    std::function<int (int, int)> sub = [](int i, int j) -> int { return i - j; };
    assert(rfold(sub, 1, 2, 3, 4, 5, 6, 7, 8, 9) == (1-(2-(3-(4-(5-(6-(7-(8-9)))))))));
    assert(lfold(sub, 1, 2, 3, 4, 5, 6, 7, 8, 9) == (((((((1-2)-3)-4)-5)-6)-7)-8)-9);

    std::function<int (int, int)> min = [](int i, int j) -> int { return i < j ? i : j; };
    assert(rfold(min, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 1);
    assert(lfold(min, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 1);

    std::function<int (int, int)> max = [](int i, int j) -> int { return i > j ? i : j; };
    assert(rfold(max, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 9);
    assert(lfold(max, 1, 2, 3, 4, 5, 6, 7, 8, 9) == 9);
}

