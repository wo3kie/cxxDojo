/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/dijkstra
 */

#include "./dijkstra.hpp"
#include "./output.hpp"

/*
 * dijkstra_test
 */
void dijkstra_test() {
  // clang-format off
  Matrix matrix{
      { 0,  4,  2, -1, -1},
      {-1,  0,  3,  2,  3},
      {-1,  1,  0,  4,  5},
      {-1, -1, -1,  0, -1},
      {-1, -1, -1,  1,  0},
  };
  // clang-format on

  DijkstraResult result = dijkstra(matrix, 0);

  typedef std::vector<int> VI;

  Assert((result.dist == VI{0, 3, 2, 5, 6}));
  Assert((result.prev == VI{-1, 2, 0, 1, 1}));

  Assert((result.path(0, 0) == VI{0}));
  Assert((result.path(0, 1) == VI{0, 2, 1}));
  Assert((result.path(0, 2) == VI{0, 2}));
  Assert((result.path(0, 3) == VI{0, 2, 1, 3}));
  Assert((result.path(0, 4) == VI{0, 2, 1, 4}));
}

/*
 * main
 */

int main() {
  dijkstra_test();
}
