/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/floyd_warshall
 */

#include <cassert>
#include <vector>

#include "./floyd_warshall.hpp"
#include "./output.hpp"

const int INF = 99;

/*
 * main
 */

int main() {
  // clang-format off
  Matrix matrix{
    {  0,   2, INF, INF,   4},
    {INF,   0,   3, INF, INF},
    {INF, INF,   0,   5,   1},
    {  8, INF, INF,   0, INF},
    {INF, INF, INF,   7,   0},
  };
  // clang-format on

  Matrix dist = matrix;
  Matrix prev = matrix;

  std::tie(dist, prev) = floydWarshall(matrix);

  // clang-format off
  assert((dist == Matrix{{ 0,  2,  5, 10,  4}, //
                         {16,  0,  3,  8,  4}, 
                         {13, 15,  0,  5,  1}, 
                         { 8, 10, 13,  0, 12}, 
                         {15, 17, 20,  7,  0}}));
  // clang-format on

  typedef std::vector<int> VI;

  assert((decodeShortestPath(prev, 0, 0) == VI{0}));
  assert((decodeShortestPath(prev, 0, 1) == VI{1}));
  assert((decodeShortestPath(prev, 0, 2) == VI{1, 2}));
  assert((decodeShortestPath(prev, 0, 3) == VI{1, 2, 3}));
  assert((decodeShortestPath(prev, 0, 4) == VI{4}));
  assert((decodeShortestPath(prev, 1, 0) == VI{2, 3, 0}));
  assert((decodeShortestPath(prev, 1, 1) == VI{1}));
  assert((decodeShortestPath(prev, 1, 2) == VI{2}));
  assert((decodeShortestPath(prev, 1, 3) == VI{2, 3}));
  assert((decodeShortestPath(prev, 1, 4) == VI{2, 4}));
  assert((decodeShortestPath(prev, 2, 0) == VI{3, 0}));
  assert((decodeShortestPath(prev, 2, 1) == VI{3, 0, 1}));
  assert((decodeShortestPath(prev, 2, 2) == VI{2}));
  assert((decodeShortestPath(prev, 2, 3) == VI{3}));
  assert((decodeShortestPath(prev, 2, 4) == VI{4}));
  assert((decodeShortestPath(prev, 3, 0) == VI{0}));
  assert((decodeShortestPath(prev, 3, 1) == VI{0, 1}));
  assert((decodeShortestPath(prev, 3, 2) == VI{0, 1, 2}));
  assert((decodeShortestPath(prev, 3, 3) == VI{3}));
  assert((decodeShortestPath(prev, 3, 4) == VI{0, 4}));
  assert((decodeShortestPath(prev, 4, 0) == VI{3, 0}));
  assert((decodeShortestPath(prev, 4, 1) == VI{3, 0, 1}));
  assert((decodeShortestPath(prev, 4, 2) == VI{3, 0, 1, 2}));
  assert((decodeShortestPath(prev, 4, 3) == VI{3}));
  assert((decodeShortestPath(prev, 4, 4) == VI{4}));
}
