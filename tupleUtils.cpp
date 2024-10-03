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
#include <iostream>
#include <functional>
#include "tupleUtils.hpp"

void tuple_fold_test() {
    std::tuple<bool, int, double> tcid{true, 2, 3.3};

    const auto f = [](int i, auto a) -> int {
        return i + int(a);
    };

    assert(tuple::foldl(tcid, f, 0) == 1 + 2 + 3);
    assert(tuple::foldr(tcid, f, 0) == 1 + 2 + 3);
}

void tuple_hash_test() {
    std::tuple<bool> tb{false};
    tuple::hash(tb);

    std::tuple<bool, int> tbi{false, 1};
    tuple::hash(tbi);

    std::tuple<bool, int, float> tbif{false, 1, 1.11};
    tuple::hash(tbif);
}

int main() {
    tuple_fold_test();
    tuple_hash_test();
}