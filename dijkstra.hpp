#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <limits>
#include <vector>

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

typedef std::vector<std::vector<int>> Matrix;

struct DijkstraResult {
  std::vector<int> dist;
  std::vector<int> prev;

  std::vector<int> path(const int start, int end) const {
    std::vector<int> path(1, end);

    while(prev[end] != -1) {
      path.push_back(prev[end]);
      end = prev[end];
    }

    std::reverse(path.begin(), path.end());

    return path;
  }
};

inline DijkstraResult dijkstra(const Matrix& graph, int start = 0) {
  const int size = graph.size();

  std::vector<int> dist(size, std::numeric_limits<int>::max());
  std::vector<int> prev(size, -1);
  std::vector<bool> visited(size, false);

  dist[start] = 0;

  auto cmp = [&](int i1, int i2) {
    return dist[i1] > dist[i2];
  };

  std::vector<int> H;
  H.reserve(size);
  H.push_back(start);
  std::push_heap(H.begin(), H.end(), cmp);

  while(!H.empty()) {
    std::pop_heap(H.begin(), H.end(), cmp);

    int u = H.back();
    H.pop_back();

    if (visited[u]) {
      continue;
    }

    visited[u] = true;

    for(int v = 0; v < size; ++v) {
      if (graph[u][v] == -1) {
        continue;
      }

      int alt = dist[u] + graph[u][v];
      
      if (alt < dist[v]) {
        dist[v] = alt;
        prev[v] = u;

        H.push_back(v);
        std::push_heap(H.begin(), H.end(), cmp);
      }
    }
  }

  return {dist, prev};
}
