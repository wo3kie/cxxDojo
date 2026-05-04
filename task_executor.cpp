/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstdint>
#include <numeric>
#include <vector>

#include "./assert.hpp"
#include "./task_executor.hpp"

int main()
{
  TaskExecutorSPSC<8> executor;

  std::future<int> product = executor.submit([](int a, int b) { return a * b; }, 6, 7);
  std::future<int> sum = executor.submit([](int a, int b, int c) { return a + b + c; }, 6, 7, 8);

  executor.stop();

  Assert(sum.get() == 21);
  Assert(product.get() == 42);

  return 0;
}
