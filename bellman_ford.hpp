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

typedef std::vector<std::vector<int>> Matrix;
const int INF = 99; // infinity, 99 for readable output

namespace impl {

bool update(const Matrix& graph, std::vector<int>& dist, std::vector<int>& prev, int u, int v) {
  if(dist[v] > dist[u] + graph[u][v]) {
    dist[v] = dist[u] + graph[u][v];
    prev[v] = u;

    return true;
  } else {
    return false;
  }
}

} // namespace impl

std::pair<std::vector<int> /* dist */, std::vector<int> /* prev */> bellmanFord(const Matrix& graph, int start = 0) {
  const int size = graph.size();

  std::vector<int> dist(size, INF);
  std::vector<int> prev(size, -1);
  dist[start] = 0;

  for(int repetition = 0; repetition < size - 1; ++repetition) {
    for(int u = 0; u < size; ++u) {
      for(int v = 0; v < size; ++v) {
        if(u == v) {
          continue;
        }

        if(graph[u][v] == INF) {
          continue;
        }

        impl::update(graph, dist, prev, u, v);
      }
    }
  }

  { // one more time to detect a cycle
    for(int u = 0; u < size; ++u) {
      for(int v = 0; v < size; ++v) {
        if(u == v) {
          continue;
        }

        if(graph[u][v] == INF) {
          continue;
        }

        if(impl::update(graph, dist, prev, u, v) == true) {
          return std::pair<std::vector<int>, std::vector<int>>();
        }
      }
    }
  }

  return std::make_pair(dist, prev);
}

std::vector<int> decodeShortestPath(const std::vector<int>& prev, const int start, int end) {
  std::vector<int> path(1, end);

  while(prev[end] != -1) {
    path.push_back(prev[end]);
    end = prev[end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}
