#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <iterator>
#include <stddef.h>
#include <concepts>

template<std::random_access_iterator Iterator>
void rotate_left_cycle(Iterator begin, Iterator pivot, Iterator end) {
  /*
   * [1 2'3 4 5 6 7] ->
   *    [3 4] + [1 2'5 6 7] ->
   *        [3 4] + [5 6'1 2 7] ->
   *            [3 4] + [5 6] + [1 2'7] ->
   *                [3 4] + [5 6] + [7 2'1] ->
   *                    [3 4] + [5 6] + [7] + [2'1] ->
   *                        [3 4 5 6 7 2 1]
   */

  if(begin == pivot || pivot == end) {
    return;
  }

  Iterator next = pivot;

  while(begin != end) {
    std::swap(*begin++, *next++);

    if(next == end) {
      next = pivot;
    } else if(begin == pivot) {
      pivot = next;
    }
  }
}

template<std::random_access_iterator Iterator>
void rotate_left_reverse(Iterator begin, Iterator pivot, Iterator end) {
  if(begin == pivot || pivot == end) {
    return;
  }

  /*
   * [1 2 3'4 5 6 7] -> [7 6 5 4 3 2 1]
   */
  std::reverse(begin, end);

  /*
   * [7 6 5 4'3 2 1] -> [4 5 6 7] + [3 2 1]
   */
  Iterator newPivot = begin + (end - pivot);
  std::reverse(begin, newPivot);

  /*
   * [4 5 6 7'3 2 1] -> [4 5 6 7] + [1 2 3]
   */
  std::reverse(newPivot, end);
}

template<std::random_access_iterator Iterator>
void rotate_left(Iterator begin, Iterator pivot, Iterator end) {
  return rotate_left_reverse(begin, pivot, end);
}

template<std::random_access_iterator Iterator>
void rotate_right_cycle(Iterator begin, Iterator pivot, Iterator end) {
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
    rotate_right_cycle(begin + (rightSize - leftSize), pivot + (rightSize - leftSize), end);

    /*
     * [1 5 6'7 2 3 4] ->
     *      [1 5 6'7] + [2 3 4] ->
     *          [5 6 7'1] + [2 3 4] ->
     *              [5 6 7 1 2 3 4]
     */
    rotate_right_cycle(begin, pivot, pivot + (rightSize - leftSize));
  } else {
    /*
     * [1 2 3 4'5 6 7] ->
     *      [1'2 3 4] + [5 6 7] ->
     *          [4'1 2 3] + [5 6 7] ->
     *              [4 1 2 3 5 6 7]
     */
    rotate_right_cycle(begin, begin + (leftSize - rightSize), pivot);

    /*
     * [4] + [1 2 3'5 6 7] ->
     *      [4] + [5 6 7'1 2 3] ->
     *          [4 5 6 7 1 2 3]
     */
    rotate_right_cycle(begin + (leftSize - rightSize), pivot, end);
  }
}

template<std::random_access_iterator Iterator>
void rotate_right_reverse(Iterator begin, Iterator pivot, Iterator end) {
  if(begin == pivot || pivot == end) {
    return;
  }

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

template<std::random_access_iterator Iterator>
void rotate_right(Iterator begin, Iterator pivot, Iterator end) {
  return rotate_right_reverse(begin, pivot, end);
}
