/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 entropy.cpp -o entropy
 *
 * Usage:
 *      $ ./entropy
 */

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Entropy_(information_theory)
 */

#include "./entropy.hpp"

#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./feq.hpp"

/*
 * entropy_test
 */

void entropy_test() {
  {
    std::vector<int> array({1, 2});
    Assert(entropy(array.begin(), array.end()) == 1);
  }

  {
    std::vector<int> array({1, 2, 2, 2});
    Assert(entropy(array.begin(), array.end()) == approx(0.811278));
  }

  {
    std::vector<int> array({1, 1, 1, 1, 1});
    Assert(entropy(array.begin(), array.end()) == approx(0));
  }
}

/*
 * main
 */

int main() {
  entropy_test();
}
