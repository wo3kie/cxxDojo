/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 laplaceSmoothing.cpp -o laplaceSmoothing
 *
 * Usage:
 *      $ ./laplaceSmoothing
 */

#include <algorithm>
#include <map>
#include <numeric>

template<typename T>
std::map<T, double> laplaceSmoothing(std::map<T, unsigned> const& map) {
  std::map<T, double> result;

  auto const allCounter = std::accumulate(
      map.begin(), map.end(), 0u, [](unsigned init, auto const& current) -> unsigned {
        return init + current.second;
      });

  auto const size = map.size();

  for(auto& pair : map) {
    result[pair.first] = 1.0 * (pair.second + 1) / (allCounter + size);
  }

  return result;
}

#include <cassert>
#include <string>

int main() {
  std::map<std::string, unsigned> map = {{"a", 1}, {"b", 2}, {"c", 3}, {"x", 0}};

  std::map<std::string, double> actual = laplaceSmoothing(map);

  std::map<std::string, double> expected = {{"a", 0.2}, {"b", 0.3}, {"c", 0.4}, {"x", 0.1}};

  assert(actual == expected);
}
