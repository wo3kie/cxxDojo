/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <tuple>
#include <vector>

#include "./bellman_ford.hpp"
#include "./output.hpp"

/*
 * main
 */

int main() {
  // clang-format off
  Matrix matrix{
    //  S,   A,   B,   C,   D,   E,   F,   G
    {   0,  10, INF, INF, INF, INF, INF,   8},  // S
    { INF,   0, INF, INF, INF,   2, INF, INF},  // A
    { INF,   1,   0,   1, INF, INF, INF, INF},  // B
    { INF, INF, INF,   0,   3, INF, INF, INF},  // C
    { INF, INF, INF, INF,   0,  -1, INF, INF},  // D
    { INF, INF,  -2, INF, INF,   0, INF, INF},  // E
    { INF,  -4, INF, INF, INF,  -1,   0, INF},  // F
    { INF, INF, INF, INF, INF, INF,   1,   0},  // G
  };
  // clang-format on

  typedef std::vector<int> VI;

  BellmanFordResult result = bellman_ford(matrix, 0);
  
  Assert(! result.hasNegativeCycle);
  Assert((result.dist == VI{0, 5, 5, 6, 9, 7, 9, 8}));
  Assert((result.path(0, 0) == VI{0}));
  Assert((result.path(0, 1) == VI{0, 7, 6, 1}));
  Assert((result.path(0, 2) == VI{0, 7, 6, 1, 5, 2}));
  Assert((result.path(0, 3) == VI{0, 7, 6, 1, 5, 2, 3}));
  Assert((result.path(0, 4) == VI{0, 7, 6, 1, 5, 2, 3, 4}));
  Assert((result.path(0, 5) == VI{0, 7, 6, 1, 5}));
  Assert((result.path(0, 6) == VI{0, 7, 6}));
  Assert((result.path(0, 7) == VI{0, 7}));
}
