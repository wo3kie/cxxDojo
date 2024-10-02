/*
 * Website:
 *      https://github.com/wo3kie/dojo
 * 
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++17 trie.cpp -o trie
 *
 * Usage:
 *      $ ./trie
 */

#include <cassert>
#include "tupleUtils.hpp"

void tuple_test() {
    std::tuple<bool, int, double> tcid{true, 2, 3.3};

    const auto f = [](int i, auto a) -> int {
        return i + int(a);
    };

    assert(tuple::foldl(tcid, f, 0) == 1 + 2 + 3);
    assert(tuple::foldr(tcid, f, 0) == 1 + 2 + 3);
}

int main() {
    tuple_test();
}