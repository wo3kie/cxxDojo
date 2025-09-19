#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <string>
#include <vector>

namespace impl {

template<typename T>
T min(const T& t1, const T& t2, const T& t3) {
  return std::min(std::min(t1, t2), t3);
}

} // namespace impl

template<typename ArrayT>
std::size_t levensteinDistance(const ArrayT& array1, const ArrayT& array2) {
  const std::size_t array1Size = array1.size();
  const std::size_t array2Size = array2.size();

  if(array1Size == 0) {
    return array2Size;
  }

  if(array2Size == 0) {
    return array1Size;
  }

  std::vector<std::vector<std::size_t>> partialResults;

  const std::size_t partialResultsColumnsNo = array1Size + 1;
  const std::size_t partialResultsRowsNo = array2Size + 1;

  partialResults.resize(partialResultsRowsNo);

  for(std::size_t index = 0; index < partialResultsRowsNo; ++index) {
    partialResults[index].resize(partialResultsColumnsNo);
  }

  for(std::size_t index = 0; index < partialResultsRowsNo; ++index) {
    partialResults[index][0] = index;
  }

  for(std::size_t index = 0; index < partialResultsColumnsNo; ++index) {
    partialResults[0][index] = index;
  }

  for(std::size_t array1Index = 0; array1Index < array1Size; ++array1Index) {
    for(std::size_t array2Index = 0; array2Index < array2Size; ++array2Index) {
      if(array1[array1Index] == array2[array2Index]) {
        partialResults[array2Index + 1][array1Index + 1] = partialResults[array2Index + 1 - 1][array1Index + 1 - 1];
      } else {
        const size_t min1 = partialResults[array2Index + 1 - 1][array1Index + 1 - 1];
        const size_t min2 = partialResults[array2Index + 1 - 1][array1Index + 1];
        const size_t min3 = partialResults[array2Index + 1][array1Index + 1 - 1];

        partialResults[array2Index + 1][array1Index + 1] = 1 + impl::min(min1, min2, min3);
      }
    }
  }

  return partialResults.back().back();
}
