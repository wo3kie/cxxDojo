/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 floydWarshall.cpp -o floydWarshall
 *
 * Usage:
 *      $ ./floydWarshall
 */

#include <algorithm>
#include <cassert>
#include <vector>

#include "./output.hpp"

/*
 * Algorithms in a Nutshell
 */

int const IN = 99;

typedef std::vector<std::vector<int>> Matrix;

std::pair<Matrix /* dist */, Matrix /* prev */> floydWarshall(Matrix const& graph) {
  int const size = graph.size();

  Matrix dist = graph;
  Matrix prev = graph;

  for(int u = 0; u < size; ++u) {
    for(int v = 0; v < size; ++v) {
      prev[u][v] = u;
    }
  }

  for(int t = 0; t < size; ++t) {
    for(int u = 0; u < size; ++u) {
      for(int v = 0; v < size; ++v) {
        if(dist[u][v] > dist[u][t] + dist[t][v]) {
          dist[u][v] = dist[u][t] + dist[t][v];
          prev[u][v] = prev[t][v];
        }
      }
    }
  }

  return std::make_pair(dist, prev);
}

std::vector<int> decodeShortestPath(Matrix const& prev, int const start, int end) {
  std::vector<int> path(1, end);

  while(prev[start][end] != start) {
    path.push_back(prev[start][end]);
    end = prev[start][end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}

int main() {
  Matrix matrix{
      {0, 2, IN, IN, 4},
      {IN, 0, 3, IN, IN},
      {IN, IN, 0, 5, 1},
      {8, IN, IN, 0, IN},
      {IN, IN, IN, 7, 0},
  };

  Matrix dist = matrix;
  Matrix prev = matrix;

  std::tie(dist, prev) = floydWarshall(matrix);

  assert(
      (dist == Matrix{{0, 2, 5, 10, 4}, {16, 0, 3, 8, 4}, {13, 15, 0, 5, 1}, {8, 10, 13, 0, 12}, {15, 17, 20, 7, 0}}));

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
