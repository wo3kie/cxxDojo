#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <cassert>
#include <vector>

#include "./output.hpp"

/*
 * Algorithms in a Nutshell
 */

typedef std::vector<std::vector<int>> Matrix;

inline std::pair<Matrix /* dist */, Matrix /* prev */> floydWarshall(const Matrix& graph) {
  const int size = graph.size();

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

inline std::vector<int> decodeShortestPath(const Matrix& prev, const int start, int end) {
  std::vector<int> path(1, end);

  while(prev[start][end] != start) {
    path.push_back(prev[start][end]);
    end = prev[start][end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}
