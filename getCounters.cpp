/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 getCounters.cpp -o getCounters
 *
 * Usage:
 *      $ ./getCounters
 */

#include <cassert>
#include <vector>

#include "./getCounters.hpp"

int main() {
  {
    std::vector<int> const vi{5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1};

    std::map<int, unsigned> const actual = getCounters(vi.begin(), vi.end());
    std::map<int, unsigned> const expected = {{1, 5}, {2, 4}, {3, 3}, {4, 2}, {5, 1}};

    assert(actual == expected);
  }
}
