/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/set_utils
 */


#include "./assert.hpp"
#include "./set_utils.hpp"


using namespace stl;

template<typename T>
struct MyHash {
  size_t operator()(const T& i) const noexcept {
    return std::hash<T>()(i);
  }
};

template<typename Set1, typename Set2>
void test_union_impl() {
  Set1 s1{1, 2, 3};
  Set2 s2{4, 5, 6};

  s1 += s2;
  Assert(s1 == Set1({1, 2, 3, 4, 5, 6}));
}

void test_union() {
  using T1 = std::set<int, std::less<int>>;
  using T2 = std::set<int, std::greater<int>>;
  using T3 = std::unordered_set<int, std::hash<int>>;
  using T4 = std::unordered_set<int, MyHash<int>>;

  test_union_impl<T1, T1>();
  test_union_impl<T1, T2>();
  test_union_impl<T1, T3>();
  test_union_impl<T1, T4>();

  test_union_impl<T2, T1>();
  test_union_impl<T2, T2>();
  test_union_impl<T2, T3>();
  test_union_impl<T2, T4>();

  test_union_impl<T3, T1>();
  test_union_impl<T3, T2>();
  test_union_impl<T3, T3>();
  test_union_impl<T3, T4>();

  test_union_impl<T4, T1>();
  test_union_impl<T4, T2>();
  test_union_impl<T4, T3>();
  test_union_impl<T4, T4>();
}

template<typename Set1, typename Set2>
void test_difference_impl() {
  Set1 s1{1, 2, 3, 4, 5, 6};
  Set2 s2{4, 5, 6};

  s1 -= s2;
  Assert(s1 == Set1({1, 2, 3}));
}

void test_difference() {
  using T1 = std::set<int, std::less<int>>;
  using T2 = std::set<int, std::greater<int>>;
  using T3 = std::unordered_set<int, std::hash<int>>;
  using T4 = std::unordered_set<int, MyHash<int>>;

  test_difference_impl<T1, T1>();
  test_difference_impl<T1, T2>();
  test_difference_impl<T1, T3>();
  test_difference_impl<T1, T4>();

  test_difference_impl<T2, T1>();
  test_difference_impl<T2, T2>();
  test_difference_impl<T2, T3>();
  test_difference_impl<T2, T4>();

  test_difference_impl<T3, T1>();
  test_difference_impl<T3, T2>();
  test_difference_impl<T3, T3>();
  test_difference_impl<T3, T4>();

  test_difference_impl<T4, T1>();
  test_difference_impl<T4, T2>();
  test_difference_impl<T4, T3>();
  test_difference_impl<T4, T4>();
}

template<typename Set1, typename Set2>
void test_intersection_impl() {
  Set1 s1{1, 2, 3, 4, 5, 6};
  Set1 s2{4, 5, 6, 7, 8, 9};

  s1 &= s2;
  Assert(s1 == Set1({4, 5, 6}));
}

void test_intersection() {
  using T1 = std::set<int, std::less<int>>;
  using T2 = std::set<int, std::greater<int>>;
  using T3 = std::unordered_set<int, std::hash<int>>;
  using T4 = std::unordered_set<int, MyHash<int>>;

  test_intersection_impl<T1, T1>();
  test_intersection_impl<T1, T2>();
  test_intersection_impl<T1, T3>();
  test_intersection_impl<T1, T4>();

  test_intersection_impl<T2, T1>();
  test_intersection_impl<T2, T2>();
  test_intersection_impl<T2, T3>();
  test_intersection_impl<T2, T4>();

  test_intersection_impl<T3, T1>();
  test_intersection_impl<T3, T2>();
  test_intersection_impl<T3, T3>();
  test_intersection_impl<T3, T4>();

  test_intersection_impl<T4, T1>();
  test_intersection_impl<T4, T2>();
  test_intersection_impl<T4, T3>();
  test_intersection_impl<T4, T4>();
}

template<typename Set1, typename Set2>
void test_symmetric_difference_impl() {
  Set1 s1{1, 2, 3, 4, 5, 6};
  Set1 s2{4, 5, 6, 7, 8, 9};

  s1 ^= s2;
  Assert(s1 == Set1({1, 2, 3, 7, 8, 9}));
}

void test_symmetric_difference() {
  using T1 = std::set<int, std::less<int>>;
  using T2 = std::set<int, std::greater<int>>;
  using T3 = std::unordered_set<int, std::hash<int>>;
  using T4 = std::unordered_set<int, MyHash<int>>;

  test_symmetric_difference_impl<T1, T1>();
  test_symmetric_difference_impl<T1, T2>();
  test_symmetric_difference_impl<T1, T3>();
  test_symmetric_difference_impl<T1, T4>();

  test_symmetric_difference_impl<T2, T1>();
  test_symmetric_difference_impl<T2, T2>();
  test_symmetric_difference_impl<T2, T3>();
  test_symmetric_difference_impl<T2, T4>();

  test_symmetric_difference_impl<T3, T1>();
  test_symmetric_difference_impl<T3, T2>();
  test_symmetric_difference_impl<T3, T3>();
  test_symmetric_difference_impl<T3, T4>();

  test_symmetric_difference_impl<T4, T1>();
  test_symmetric_difference_impl<T4, T2>();
  test_symmetric_difference_impl<T4, T3>();
  test_symmetric_difference_impl<T4, T4>();
}

int main() {
  test_union();
  test_difference();
  test_intersection();
  test_symmetric_difference();

  return 0;
}