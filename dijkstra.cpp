/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 dijkstra.cpp -o dijkstra
 *
 * Usage:
 *      $ ./dijkstra
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

#include "./output.hpp"

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

typedef std::vector<std::vector<int>> Matrix;

std::pair<std::vector<int> /*dist*/, std::vector<int> /*prev*/> dijkstra(Matrix const& graph, int start = 0) {
  int const size = graph.size();

  std::vector<int> dist(size, std::numeric_limits<int>::max());
  std::vector<int> prev(size, -1);
  dist[start] = 0;

  auto cmp = [&](int i1, int i2) {
    return dist[i1] > dist[i2];
  };

  std::vector<int> H(size, 0);

  for(int i = 0; i < size; ++i) {
    H[i] = i;
  }

  std::make_heap(H.begin(), H.end(), cmp);

  while(H.empty() == false) {
    std::pop_heap(H.begin(), H.end(), cmp);
    int const u = H.back();
    H.pop_back();

    for(int v = 0; v < size; ++v) {
      if(u == v) {
        continue;
      }

      if(graph[u][v] == -1) {
        continue;
      }

      if(dist[v] > dist[u] + graph[u][v]) {
        dist[v] = dist[u] + graph[u][v];
        prev[v] = u;

        std::make_heap(H.begin(), H.end(), cmp);
      }
    }
  }

  return std::make_pair(dist, prev);
}

std::vector<int> decodeShortestPath(std::vector<int> const& prev, int const start, int end) {
  std::vector<int> path(1, end);

  while(prev[end] != -1) {
    path.push_back(prev[end]);
    end = prev[end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}

int main() {
  Matrix matrix{
      {0, 4, 2, -1, -1},
      {-1, 0, 3, 2, 3},
      {-1, 1, 0, 4, 5},
      {-1, -1, -1, 0, -1},
      {-1, -1, -1, 1, 0},
  };

  std::vector<int> dist;
  std::vector<int> prev;

  std::tie(dist, prev) = dijkstra(matrix, 0);

  typedef std::vector<int> VI;

  assert((dist == VI{0, 3, 2, 5, 6}));
  assert((prev == VI{-1, 2, 0, 1, 1}));

  assert((decodeShortestPath(prev, 0, 0) == VI{0}));
  assert((decodeShortestPath(prev, 0, 1) == VI{0, 2, 1}));
  assert((decodeShortestPath(prev, 0, 2) == VI{0, 2}));
  assert((decodeShortestPath(prev, 0, 3) == VI{0, 2, 1, 3}));
  assert((decodeShortestPath(prev, 0, 4) == VI{0, 2, 1, 4}));
}
