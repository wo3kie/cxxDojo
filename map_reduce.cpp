/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/map_reduce
 */

#include <vector>

#include "assert.hpp"
#include "map_reduce.hpp"

/*
 * map_test
 */

void map_test() {
  auto square = [](int x) { //
    return x * x;
  };

  std::vector<int> v{1, 2, 3, 4};
  auto m = v | Map(square);

  const std::vector<int> expected{1, 4, 9, 16};
  const std::vector<int> actual{m.begin(), m.end()};

  assert(actual == expected);
}

/*
 * reduce_test
 */

void reduce_test() {
  std::vector<int> v{1, 2, 3, 4};

  Assert((Reduce(0)(v) == 1 + 2 + 3 + 4));
  Assert(((v | Reduce(0)) == 1 + 2 + 3 + 4));

  Assert((Reduce(1, std::multiplies<int>{})(v) == 1 * 2 * 3 * 4));
  Assert(((v | Reduce(1, std::multiplies<int>{})) == 1 * 2 * 3 * 4));
}

/*
 * map_reduce_test
 */

void map_reduce_test() {
  struct S {
    int s;
  
    int get() const {
      return s;
    }
  };

  auto m = [](int i) { //
    return i * i;
  };

  auto r = [](int a, int b) -> int { //
    return a + b;
  };

  std::vector<S> v{{1}, {2}, {3}, {4}};
  
  auto i = v | Map(&S::get) | Map(m) | Reduce(0);
  Assert(i == 1 * 1 + 2 * 2 + 3 * 3 + 4 * 4);

  auto j = v | Map(&S::get) | Map(m) | Reduce(0, r);
  Assert(j == 1 * 1 + 2 * 2 + 3 * 3 + 4 * 4);

  auto k = v | Map(&S::get) | Map(m) | Reduce(0, std::plus<>{});
  Assert(k == 1 * 1 + 2 * 2 + 3 * 3 + 4 * 4);
}

/*
 * main
 */

int main() {
  map_test();
  reduce_test();
  map_reduce_test();

  return 0;
}
