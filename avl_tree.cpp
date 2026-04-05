/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <set>

#include "./assert.hpp"
#include "./avl_tree.hpp"
#include "./timer.hpp"

void test_avl_tree() {
  AvlTree<int> tree{};

  for(int i = 1; i <= 100; ++i) {
    assert(tree.insert(i));
  }

  for(int i = 1; i <= 100; ++i) {
    Assert(tree.contains(i) == true);
  }

  Assert(tree.contains(101) == false);

  for(int i = 1; i <= 100; ++i) {
    assert(tree.erase(i));
  }

  for(int i = 1; i <= 100; ++i) {
    Assert(tree.contains(i) == false);
  }
}

void test_avl_tree_benchmark(size_t size) {
  AvlTree<int> tree{};
  std::set<int> set{};

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { tree.insert(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "AVL Tree insert: " << formatted << std::endl;
      }
  );

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { set.insert(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "std::set insert: " << formatted << std::endl;
      }
  );

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { (void) tree.contains(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "AVL Tree contains: " << formatted << std::endl;
      }
  );

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { set.contains(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "std::set contains: " << formatted << std::endl;
      }
  );

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { tree.erase(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "AVL Tree erase: " << formatted << std::endl;
      }
  );

  timer([&](){
    for(size_t i = 1; i <= size; ++i) { set.erase(i); }}, 10).log(
      [](long int ns, const std::string& formatted) {
        std::cout << "std::set erase: " << formatted << std::endl;
      }
  );
}

int main() {
  test_avl_tree();
  test_avl_tree_benchmark(100'000);
  return 0;
}
