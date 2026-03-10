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

void test_store_if_unary() {
  auto unary = [](int newValue) -> bool { //
    return newValue % 2 == 0;
  };

  StoreIf<int, decltype(unary)> storeU(unary);
  storeU << 0;
  storeU << 1;
  storeU << 2;
  storeU << 3;
  storeU << 4;
  storeU << 5;
  Assert(storeU.value() == 4);
}

void test_store_if_binary() {
  auto binary = [](int newValue, int oldValue) -> bool {
    return newValue < oldValue;
  };

  StoreIf<int, decltype(binary)> storeB(binary);
  storeB << 1;
  storeB << 3;
  storeB << 0;
  storeB << 2;
  Assert(storeB.value() == 0);
}

void test_store_if_mixed() {
  auto unary = [](int newValue) -> bool { //
    return newValue % 2 == 1;
  };

  auto binary = [](int newValue, int oldValue) -> bool {
    return newValue < oldValue;
  };

  StoreIf<int, decltype(unary), decltype(binary)> storeM(unary, binary);
  storeM << 0;
  storeM << 2;
  storeM << 1;
  storeM << 3;
  Assert(storeM.value() == 1);
}

void test_make_store_if() {
  auto unary = [](int newValue) -> bool { //
    return newValue % 2 == 1;
  };

  auto binary = [](int newValue, int oldValue) -> bool {
    return newValue < oldValue;
  };

  auto storeM = make_store_if<int>(unary, binary);
  storeM << 0;
  storeM << 2;
  storeM << 1;
  storeM << 3;
  Assert(storeM.value() == 1);
}

int main() {
  test_store_if_unary();
  test_store_if_binary();
  test_store_if_mixed();
  test_make_store_if();
}
