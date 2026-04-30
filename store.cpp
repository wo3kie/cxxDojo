/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./store.hpp"
#include "./assert.hpp"

void test_store() {
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

void test_store_min() {
  auto storeMin = make_store_min<int>();
  storeMin << 5;
  storeMin << 3;
  storeMin << 1;
  storeMin << 2;
  storeMin << 4;
  Assert(storeMin.value() == 1);
}

void test_store_max() {
  auto storeMax = make_store_max<int>();
  storeMax << 1;
  storeMax << 3;
  storeMax << 5;
  storeMax << 4;
  storeMax << 2;
  Assert(storeMax.value() == 5);
}

void test_store_first() {
  auto store = make_store_first<int>();
  store << 1;
  store << 2;
  store << 3;
  store << 0;
  Assert(store.value() == 1);
}

void test_make_store_true() {
  auto store = make_store_true();
  store << false;
  store << false;
  Assert(!store.has_value());

  store << true;
  store << false;
  Assert(store.value());
}

void test_make_store_false() {
  auto store = make_store_false();
  store << true;
  store << true;
  Assert(!store.has_value());

  store << false;
  store << true;
  Assert(!store.value());
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
  test_store();
  test_store_min();
  test_store_max();
  test_store_first();
  test_make_store_true();
  test_make_store_false();
  
  test_storeN();
}
