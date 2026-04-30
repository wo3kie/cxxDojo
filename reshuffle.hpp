#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <random>
#include <vector>

template<typename TValue>
void reshuffle(std::vector<TValue>& values, int stddev, int seed=-1) {
  std::random_device rd;
  std::mt19937 gen(seed == -1 ? rd() : seed);
  std::normal_distribution<> dis(0, stddev);

  const size_t size = values.size();
  
  for(size_t i = 1; i < values.size() - 1; ++i) {
    const size_t index_from = i;
    const size_t index_to = std::min(size - 1, std::max(size_t(0), i + size_t(dis(gen))));

    std::swap(values[index_from], values[index_to]);
  }
}
