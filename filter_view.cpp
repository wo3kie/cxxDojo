#include <iostream>
#include <vector>

#include "./assert.hpp"
#include "./filter_view.hpp"

/*
 * filter_view_test_1
 */

void filter_view_test_1() {
  std::function<bool(const int&)> isOdd = [](const int& i) -> bool { //
    return i % 2 == 1; };
 
  std::function<bool(const int&)> isEven = [](const int& i) -> bool { //
    return i % 2 == 0; };

  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  {

    filter_view f(vec, isOdd);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{1, 3, 5, 7, 9};
    Assert(actual == expected);
  }

  {
    filter_view f(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, isOdd);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{1, 3, 5, 7, 9};
    Assert(actual == expected);
  }

  {
    auto f = filter_view(vec, isOdd);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{1, 3, 5, 7, 9};
    Assert(actual == expected);
  }

  {
    auto f = filter_view(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, isOdd);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{1, 3, 5, 7, 9};
    Assert(actual == expected);
  }

  {
    auto f = vec | filter(isEven);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{2, 4, 6, 8, 10};
    Assert(actual == expected);
  }

  {
    auto f = filter(vec, isEven);
   
    const std::vector<int> actual{f.begin(), f.end()};
    const std::vector<int> expected{2, 4, 6, 8, 10};
    Assert(actual == expected);
  }
}

/*
 * main
 */

int main() {
  filter_view_test_1();
}
