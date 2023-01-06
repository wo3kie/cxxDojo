/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 longestIncreasingSubsequence.cpp \
 *          -o longestIncreasingSubsequence.cpp 
 *
 * Usage:
 *      $ ./longestIncreasingSubsequence
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "./output.hpp"

struct Node {
  int value;
  int size;
  int previous;
};

std::ostream& operator<<(std::ostream& out, Node const& node) {
  return out << "{" << node.value << ", " << node.size << ", " << node.previous << "}";
}

int findBest(std::vector<Node> const& solutions, unsigned current) {
  int best = -1;

  for(unsigned i = 0; i < current; ++i) {
    if(solutions[i].value > solutions[current].value) {
      continue;
    }

    if(best == -1) {
      best = i;
    } else {
      if(solutions[best].size < solutions[i].size) {
        best = i;
      } else {
        continue;
      }
    }
  }

  return best;
}

std::vector<Node> getSubsolutions(std::vector<int> const& array) {
  std::vector<Node> ss(array.size());
  ss[0] = Node{array[0], 1, -1};

  for(unsigned current = 1; current < array.size(); ++current) {
    ss[current].value = array[current];
    int const best = findBest(ss, current);

    if(best == -1) {
      ss[current] = Node{array[current], 1, -1};
    } else {
      ss[current] = Node{array[current], ss[best].size + 1, best};
    }
  }

  return ss;
}

std::vector<int> getSolution(std::vector<Node> const& ss) {
  int best = -1;

  for(unsigned i = 0; i < ss.size(); ++i) {
    if(best == -1) {
      best = i;
    } else {
      if(ss[best].size < ss[i].size) {
        best = i;
      } else {
        continue;
      }
    }
  }

  std::vector<int> solution;

  if(best == -1) {
    return solution;
  }

  do {
    solution.push_back(best);
    best = ss[best].previous;
  } while(best != -1);

  std::reverse(solution.begin(), solution.end());

  return solution;
}

std::vector<int> lis(std::vector<int> const& array) {
  std::vector<Node> const ss = getSubsolutions(array);
  return getSolution(ss);
}

int main() {
  typedef std::vector<int> VI;

  assert((lis({1, 2, 3, 4, 5, 6}) == VI{0, 1, 2, 3, 4, 5}));
  assert((lis({6, 5, 4, 3, 2, 1}) == VI{0}));
  assert((lis({1, 0, 2, 0, 3, 0}) == VI{0, 2, 4}));
  assert((lis({7, 8, 9, 1, 2, 1}) == VI{0, 1, 2}));
}
