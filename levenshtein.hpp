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

template<typename ArrayT>
std::size_t levenshtein_distance(const ArrayT& array1, const ArrayT& array2) {
    const std::size_t size1 = array1.size();
    const std::size_t size2 = array2.size();

    if(size1 == 0) {
      return size2;
    }

    if(size2 == 0) {
      return size1;
    }
    
    /*
     * For memory optimization we can use only two rows of the matrix (2, size1 +1),
     * however the difference reconstruction would be more difficult.
     */

    /*
     * levenshtein_distance("back", "book")
     *
     *      | " | b | o | o | k |
     *   ---+---+---+---+---+---+
     *    " | 0 | 1 | 2 | 3 | 4 |
     *   ---+---+---+---+---+---+
     *    b | 1 | 0 | 1 | 2 | 3 |
     *   ---+---+---+---+---+---+
     *    a | 2 | 1 | 1 | 2 | 3 |
     *   ---+---+---+---+---+---+
     *    c | 3 | 2 | 2 | 2 | 3 |
     *   ---+---+---+---+---+---+
     *    k | 4 | 3 | 3 | 3 | 2 |
     *   ---+---+---+---+---+---+
     */

    std::vector<std::vector<std::size_t>> M(
        size1 + 1, 
        std::vector<std::size_t>(size2 + 1)
    );

    for(std::size_t i = 0; i <= size1; ++i) {
      M[i][0] = i;
    }

    for(std::size_t j = 0; j <= size2; ++j) {
      M[0][j] = j;
    }

    for(std::size_t i1 = 1; i1 <= size1; ++i1) {
        for(std::size_t i2 = 1; i2 <= size2; ++i2) {

            if(array2[i2-1] == array1[i1-1]) {
                M[i1][i2] = M[i1-1][i2-1];
            } else {
                M[i1][i2] = 1 + std::min({
                    M[i1-1][i2-1],
                    M[i1-1][  i2],
                    M[  i1][i2-1]
                });
            }

        }
    }

    return M[size1][size2];
}
