/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/laplace_smoothing
 */

#include <string>

#include "./assert.hpp"
#include "./laplace_smoothing.hpp"

/*
 * laplaceSmoothing_test
 */

void laplaceSmoothing_test() {
  std::map<std::string, unsigned> map = {{"a", 1}, {"b", 2}, {"c", 3}, {"x", 0}};

  std::map<std::string, double> actual = laplaceSmoothing(map);
  std::map<std::string, double> expected = {{"a", 0.2}, {"b", 0.3}, {"c", 0.4}, {"x", 0.1}};

  assert(actual == expected);
}

/*
 * main
 */

int main() {
  laplaceSmoothing_test();
}
