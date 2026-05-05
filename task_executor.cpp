/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cstdint>
#include <vector>

#include "./assert.hpp"
#include "./task_executor.hpp"

#include <cassert>
#include <iostream>
#include <chrono>

void test_simple_return()
{
  TaskExecutor<8> exec;

  auto h = exec.submit([]() {
    return 123;
  });

  int v = h.get();
  assert(v == 123);
}

void test_void_task()
{
  TaskExecutor<8> exec;

  bool flag = false;

  auto h = exec.submit([&flag]() {
    flag = true;
  });

  h.get();
  assert(flag == true);
}

void test_multiple_tasks()
{
  TaskExecutor<32> exec;

  auto h1 = exec.submit([]() { return 1; });
  auto h2 = exec.submit([]() { return 2; });
  auto h3 = exec.submit([]() { return 3; });

  assert(h1.get() == 1);
  assert(h2.get() == 2);
  assert(h3.get() == 3);
}

int main()
{
  test_simple_return();
  test_void_task();
  test_multiple_tasks();
}

