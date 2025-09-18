#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <algorithm>
#include <iterator>
#include <stddef.h>

template<typename Iterator>
void rotate_left_1(Iterator begin, Iterator pivot, Iterator end) {
  Iterator next = pivot;

  /*
   * [1 2'3 4 5 6 7] ->
   *    [3 4] + [1 2'5 6 7] ->
   *        [3 4] + [5 6'1 2 7] ->
   *            [3 4] + [5 6] + [1 2'7] ->
   *                [3 4] + [5 6] + [7 2'1] ->
   *                    [3 4] + [5 6] + [7] + [2'1] ->
   *                        [3 4 5 6 7 2 1]
   */

  while(begin != end) {
    std::swap(*begin++, *next++);

    if(next == end) {
      next = pivot;
    } else if(begin == pivot) {
      pivot = next;
    }
  }
}

template<typename Iterator>
void rotate_left_2(Iterator begin, Iterator pivot, Iterator end) {
  pivot = begin + (end - pivot);

  /*
     * [1 2 3'4 5 6 7] -> [7 6 5 4 3 2 1]
     */
  std::reverse(begin, end);

  /*
     * [7 6 5 4'3 2 1] -> [4 5 6 7] + [3 2 1]
     */
  std::reverse(begin, pivot);

  /*
     * [4 5 6 7'3 2 1] -> [4 5 6 7] + [1 2 3]
     */
  std::reverse(pivot, end);
}

template<typename Iterator>
void rotate_left(Iterator begin, Iterator pivot, Iterator end) {
  /*
     * Default implementation
     */
  return rotate_left_2(begin, pivot, end);
}

template<typename Iterator>
void rotate_right_1(Iterator begin, Iterator pivot, Iterator end) {
  const size_t leftSize = std::distance(begin, pivot);
  const size_t rightSize = std::distance(pivot, end);

  if(leftSize == 0 || rightSize == 0) {
    return;
  }

  if(leftSize == rightSize) {
    while(pivot != end) {
      std::iter_swap(begin++, pivot++);
    }
  } else if(leftSize < rightSize) {
    /*
     * [1 2 3'4 5 6 7] ->
     *      [1] + [2 3 4'5 6 7] ->
     *          [1] + [5 6 7 2 3 4] ->
     *              [1 5 6 7 2 3 4]
     */
    rotate_right_1(begin + (rightSize - leftSize), pivot + (rightSize - leftSize), end);

    /*
     * [1 5 6'7 2 3 4] ->
     *      [1 5 6'7] + [2 3 4] ->
     *          [5 6 7'1] + [2 3 4] ->
     *              [5 6 7 1 2 3 4]
     */
    rotate_right_1(begin, pivot, pivot + (rightSize - leftSize));
  } else {
    /*
     * [1 2 3 4'5 6 7] ->
     *      [1'2 3 4] + [5 6 7] ->
     *          [4'1 2 3] + [5 6 7] ->
     *              [4 1 2 3 5 6 7]
     */
    rotate_right_1(begin, begin + (leftSize - rightSize), pivot);

    /*
     * [4] + [1 2 3'5 6 7] ->
     *      [4] + [5 6 7'1 2 3] ->
     *          [4 5 6 7 1 2 3]
     */
    rotate_right_1(begin + (leftSize - rightSize), pivot, end);
  }
}

template<typename Iterator>
void rotate_right_2(Iterator begin, Iterator pivot, Iterator end) {
  /*
   * [1 2 3'4 5 6 7] -> [7 6 5 4 3 2 1]
   */

  std::reverse(begin, end);

  /*
   * [7 6 5'4 3 2 1] -> [5 6 7] + [4 3 2 1]
   */

  std::reverse(begin, pivot);

  /*
   * [5 6 7'4 3 2 1] -> [5 6 7] + [1 2 3 4]
   */

  std::reverse(pivot, end);
}

template<typename Iterator>
void rorate_right(Iterator begin, Iterator pivot, Iterator end) {
  /*
     * Default implementation
     */
  return rotate_right_2(begin, pivot, end);
}
