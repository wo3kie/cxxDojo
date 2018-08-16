/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 allocator.cpp -o allocator
 *
 * Usage:
 *      $ ./allocator
 */

#include <vector>
#include <limits>

#include "./allocator.hpp"

int main(){
    std::vector< int, Allocator< int > > vector;
}

