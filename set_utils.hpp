#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <set>
#include <unordered_set>

namespace stl {

/*
 * Set union
 * {1, 2, 3} + {4, 5, 6} = {1, 2, 3, 4, 5, 6}
 */

template<typename T, typename Cmp, typename Container>
std::set<T, Cmp>& operator+=(std::set<T, Cmp>& lhs, const Container& rhs) {
  lhs.insert(rhs.begin(), rhs.end());
  return lhs;
}

/*
 * Set union
 * {1, 2, 3} + {4, 5, 6} = {1, 2, 3, 4, 5, 6}
 */

template<typename T, typename Hash, typename Container>
std::unordered_set<T, Hash>& operator+=(std::unordered_set<T, Hash>& lhs, const Container& rhs) {
  lhs.insert(rhs.begin(), rhs.end());
  return lhs;
}

/*
 * Set union
 * {1, 2, 3} | {4, 5, 6} = {1, 2, 3, 4, 5, 6}
 */

template<typename T, typename Cmp, typename Container>
std::set<T, Cmp>& operator|=(std::set<T, Cmp>& lhs, const Container& rhs) {
  return (lhs += rhs);
}

/*
 * Set union
 * {1, 2, 3} | {4, 5, 6} = {1, 2, 3, 4, 5, 6}
 */

template<typename T, typename Hash, typename Container>
std::unordered_set<T, Hash>& operator|=(std::unordered_set<T, Hash>& lhs, const Container& rhs) {
  return (lhs += rhs);
}

/*
 * Set difference
 * {1, 2, 3, 4, 5, 6} - {4, 5, 6} = {1, 2, 3}
 */

template<typename T, typename Cmp, typename Container>
std::set<T, Cmp>& operator-=(std::set<T, Cmp>& lhs, const Container& rhs) {
  for (const auto& item : rhs) {
    lhs.erase(item);
  }

  return lhs;
}

/*
 * Set difference
 * 
 */

template<typename T, typename Hash, typename Container>
std::unordered_set<T, Hash>& operator-=(std::unordered_set<T, Hash>& lhs, const Container& rhs) {
  for (const auto& item : rhs) {
    lhs.erase(item);
  }
  
  return lhs;
}

/*
 * Set intersection
 * {1, 2, 3, 4, 5, 6} & {4, 5, 6, 7, 8, 9} = {4, 5, 6}
 */

template<typename T, typename Cmp, typename Cmp2>
std::set<T, Cmp>& operator&=(std::set<T, Cmp>& lhs, const std::set<T, Cmp2>& rhs) {
  auto begin = lhs.begin();
  auto end = lhs.end();

  while(begin != end) {
    if (rhs.count(*begin) != 0) {
      ++begin;
    } else {
      begin = lhs.erase(begin);
    }
  }

  return lhs;
}

/*
 * Set intersection
 * {1, 2, 3, 4, 5, 6} & {4, 5, 6, 7, 8, 9} = {4, 5, 6}
 */

template<typename T, typename Hash,  typename Hash2>
std::unordered_set<T, Hash>& operator&=(std::unordered_set<T, Hash>& lhs, const std::unordered_set<T, Hash2>& rhs) {
  auto begin = lhs.begin();
  auto end = lhs.end();

  while(begin != end) {
    if (rhs.count(*begin) != 0) {
      ++begin;
    } else {
      begin = lhs.erase(begin);
    }
  }

  return lhs;
}

/*
 * Set symmetric difference
 * {1, 2, 3, 4, 5, 6} ^ {4, 5, 6, 7, 8, 9} = {1, 2, 3, 7, 8, 9}
 */

template<typename T, typename Cmp, typename Cmp2>
std::set<T, Cmp>& operator^=(std::set<T, Cmp>& lhs, const std::set<T, Cmp2>& rhs) {
  std::set<T, Cmp> temp;

  for (const auto& item : lhs) {
    if (rhs.count(item) == 0) {
      temp.insert(item);
    }
  }

  for (const auto& item : rhs) {
    if (lhs.count(item) == 0) {
      temp.insert(item);
    }
  }

  return (lhs = std::move(temp));
}

/*
 * Set symmetric difference
 * {1, 2, 3, 4, 5, 6} ^ {4, 5, 6, 7, 8, 9} = {1, 2, 3, 7, 8, 9}
 */

template<typename T,  typename Hash,  typename Hash2>
std::unordered_set<T, Hash>& operator^=(std::unordered_set<T, Hash>& lhs, const std::unordered_set<T, Hash2>& rhs) {
  std::unordered_set<T, Hash> temp;

  for (const auto& item : lhs) {
    if (rhs.count(item) == 0) {
      temp.insert(item);
    }
  }

  for (const auto& item : rhs) {
    if (lhs.count(item) == 0) {
      temp.insert(item);
    }
  }

  return (lhs = std::move(temp));
}

} // namespace stl