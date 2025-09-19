#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./rotate.hpp"

/*
 * partition_if
 */

template<typename Iterator, typename UnaryPredicate>
Iterator partition_if(Iterator begin, Iterator end, UnaryPredicate pred) {
  /*
     * isEven [1 2 3 4 5 6 7] ->
     *
     *  .            .       .          .       .         .   
     * [1 2 3 4 5 6 7] -> [1 2 3 4 5 6 7] -> [1 7 3 4 5 6 2] ->
     *
     *           .       .            .     .            .   .   
     *      [1 7 3 4 5 6 2] -> [1 7 3 4 5 6 2] -> [1 7 3 6 5 4 2] ->
     *
     *                 . .                  :      
     *          [1 7 3 5 6 4 2] -> [1 7 3 5 6 4 2]
     */

  while(begin != end) {
    if(pred(*begin)) {
      ++begin;
    } else {
      --end;
      std::iter_swap(begin, end);
    }
  }

  return end;
}

/*
 * partition_if
 */

template<typename Container, typename UnaryPredicate>
typename Container::iterator partition_if(Container& container, UnaryPredicate pred) {
  return partition_if(container.begin(), container.end(), pred);
}

/*
 * stable_partition_if
 */

template<typename Iterator, typename UnaryPredicate>
Iterator stable_partition_if(Iterator begin, Iterator end, UnaryPredicate pred) {
  /*
     * isEven [1 2 3 4 5 6 7] ->
     *  |                \
     * sp[1 2 3]         sp[4 5 6 7]
     *  |      \          |         \
     * [1]     sp[2 3]   sp[4 5]    sp[6 7]
     *  |       |         |          |
     * [1]     [rl(2'3)] [rl(4'5)]  [rl(6'7)]
     *  |      /          |          /
     * [1 3 2]           [5 rl(4'7) 6]
     *  |                 |
     * [1 3 2]           [5 7 4 6]
     *  |                /
     * [1 3 rl(2'5 7) 4 6]
     *  |
     * [1 3 5 7 2 4 6]
     */

  const std::size_t size = std::distance(begin, end);

  if(size == 0) {
    return end;
  }

  const Iterator pivot = begin + size / 2;

  if(size == 1) {
    if(pred(*begin)) {
      return end;
    } else {
      return begin;
    }
  } else {
    const Iterator pivotL = stable_partition_if(begin, begin + size / 2, pred);
    const Iterator pivotR = stable_partition_if(begin + size / 2, end, pred);

    rotate_left(pivotL, begin + size / 2, pivotR);

    return pivotL + (pivotR - pivot);
  }
}

/*
 * stable_partition_if
 */

template<typename Container, typename UnaryPredicate>
typename Container::iterator stable_partition_if(Container& container, UnaryPredicate pred) {
  return stable_partition_if(container.begin(), container.end(), pred);
}
