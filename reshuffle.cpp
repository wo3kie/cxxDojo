

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./reshuffle.hpp"
#include <iostream>

void test_reshuffle(size_t size, int stddev) {
  std::vector<int> values;
  
  for(int i = 0; i < size; ++i) {
    values.push_back(i);
  }

  reshuffle(values, stddev);

  for(const auto& value : values) {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

int main() {
  test_reshuffle(20, /* stddev */ 0);
  test_reshuffle(20, /* stddev */ 3);
  test_reshuffle(20, /* stddev */ 9);

  return 0;
}