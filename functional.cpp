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
#include <iostream>
#include <vector>

#include "./functional.hpp"

int main(){
    std::vector<int> v{1, 2, 3, 4, 5};

    assert((1+2+3+4+5 == dojo::sum(v.begin(), v.end())));
    assert((1*2*3*4*5 == dojo::product(v.begin(), v.end())));
    assert((1 == dojo::min(v.begin(), v.end())));
    assert((5 == dojo::max(v.begin(), v.end())));
}
