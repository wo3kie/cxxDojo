/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/store
 */

#include "./store.hpp"
#include "./assert.hpp"

void test_store1() {
  auto predicate = [](int newValue) -> bool { //
    return newValue % 2 == 1;
  };

  auto compare = [](int newValue, int oldValue) -> bool {
    return newValue < oldValue;
  };

  auto store1 = make_store<int>(compare, predicate);
  store1 << 0;
  store1 << 2;
  store1 << 1;
  store1 << 3;
  Assert(store1.value() == 1);
}

void test_storeN() {
  auto predicate = [](int newValue) -> bool { //
    return newValue % 2 == 1;
  };

  auto compare = [](int newValue, int oldValue) -> bool {
    return newValue < oldValue;
  };

  auto storeN = make_store_n<int>(3, compare, predicate);
  storeN << 0;
  storeN << 1;
  storeN << 2;
  storeN << 3;
  storeN << 4;
  storeN << 5;
  storeN << 6;
  storeN << 7;
  storeN << 8;

  const std::set<int> actual(storeN.begin(), storeN.end());
  const std::set<int> expected{1, 3, 5};
  Assert(actual == expected);
}

int main() {
  test_store1();
  test_storeN();
}
