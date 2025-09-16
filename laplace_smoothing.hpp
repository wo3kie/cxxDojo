#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <algorithm>
#include <map>
#include <numeric>

template<typename T>
std::map<T, double> laplaceSmoothing(const std::map<T, unsigned>& data) {
  std::map<T, double> result;

  const auto allCounter = std::accumulate(
      data.begin(), //
      data.end(),
      0u,
      [](unsigned init, const auto& current) -> unsigned {
        return init + current.second;
      });

  const auto size = data.size();

  for(auto& pair : data) {
    result[pair.first] = 1.0 * (pair.second + 1) / (allCounter + size);
  }

  return result;
}
