/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./assert.hpp"
#include "./avl_tree.hpp"

void test_avl_tree() {
  AvlTree<int> tree{};

  for(int i = 1; i <= 100; ++i) {
    tree.insert(i);
  }

  for(int i = 1; i <= 100; ++i) {
    Assert((*tree.find(i)) == i);
  }

  Assert(tree.find(101) == nullptr);

  for(int i = 1; i <= 100; ++i) {
    tree.remove(i);
  }

  for(int i = 1; i <= 100; ++i) {
    Assert((tree.find(i)) == nullptr);
  }
}

int main() {
  test_avl_tree();

  return 0;
}
