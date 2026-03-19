#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <vector>

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

#include <algorithm>
#include <limits>
#include <vector>

#include "./assert.hpp"

using Matrix = std::vector<std::vector<int>>;
constexpr int INF = std::numeric_limits<int>::max() / 4;

struct BellmanFordResult {
  std::vector<int> dist;
  std::vector<int> prev;
  bool hasNegativeCycle = false;

  std::vector<int> path(int start, int end) const {
    Assert(! hasNegativeCycle);

    std::vector<int> path;

    if(prev[end] == -1 && start != end)
      return path;

    for(int v = end; v != -1; v = prev[v]) {
      path.push_back(v);
    }

    std::reverse(path.begin(), path.end());

    return path;
  }
};

bool _bellman_ford_update(const Matrix& graph, std::vector<int>& dist, std::vector<int>& prev, int u, int v) {
  if(graph[u][v] == INF) {
    return false;
  }

  if(dist[u] == INF) {
    return false;
  }

  const int candidate = dist[u] + graph[u][v];

  if(candidate < dist[v]) {
    dist[v] = candidate;
    prev[v] = u;
    return true;
  }

  return false;
}

BellmanFordResult bellman_ford(const Matrix& graph, int start = 0) {
  const int n = graph.size();

  std::vector<int> dist(n, INF);
  std::vector<int> prev(n, -1);
  dist[start] = 0;

  for(int i = 0; i < n - 1; ++i)
    for(int u = 0; u < n; ++u)
      for(int v = 0; v < n; ++v)
        _bellman_ford_update(graph, dist, prev, u, v);

  // detect negative cycle
  for(int u = 0; u < n; ++u)
    for(int v = 0; v < n; ++v)
      if(_bellman_ford_update(graph, dist, prev, u, v))
        return {dist, prev, true};

  return {dist, prev, false};
}
