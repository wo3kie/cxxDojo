#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <algorithm>
#include <limits>
#include <vector>

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

typedef std::vector<std::vector<int>> Matrix;

inline std::pair<std::vector<int> /*dist*/, std::vector<int> /*prev*/> dijkstra(const Matrix& graph, int start = 0) {
  const int size = graph.size();

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
    const int u = H.back();
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

inline std::vector<int> decodeShortestPath(const std::vector<int>& prev, const int start, int end) {
  std::vector<int> path(1, end);

  while(prev[end] != -1) {
    path.push_back(prev[end]);
    end = prev[end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}
