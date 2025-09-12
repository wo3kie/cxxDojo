/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <algorithm>
#include <vector>

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

typedef std::vector<std::vector<int>> Matrix;
int const INF = 99; // infinity, 99 for readable output

namespace impl {


bool update(Matrix const& graph, std::vector<int>& dist, std::vector<int>& prev, int u, int v) {
  if(dist[v] > dist[u] + graph[u][v]) {
    dist[v] = dist[u] + graph[u][v];
    prev[v] = u;

    return true;
  } else {
    return false;
  }
}

}

std::pair<std::vector<int> /* dist */, std::vector<int> /* prev */> bellmanFord(Matrix const& graph, int start = 0) {
  int const size = graph.size();

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

std::vector<int> decodeShortestPath(std::vector<int> const& prev, int const start, int end) {
  std::vector<int> path(1, end);

  while(prev[end] != -1) {
    path.push_back(prev[end]);
    end = prev[end];
  }

  std::reverse(path.begin(), path.end());

  return path;
}

