/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/queue
 */

#include "./assert.hpp"
#include "./queue.hpp"
#include "./reshuffle.hpp"

#include <numeric>
#include <random>

void test_queue_1() {
  Queue<int> queue(1);
  Assert(queue.size() == 0);
  Assert(queue.empty());
  Assert(!queue.full());

  queue.push(1);
  Assert(queue.size() == 1);
  Assert(!queue.empty());
  Assert(queue.full());
  Assert(queue.front() == 1);
  Assert(queue.pop() == 1);
}
  
void test_queue_2() {
  Queue<int> queue(2);
  Assert(queue.size() == 0);
  Assert(queue.empty());
  Assert(!queue.full());

  queue.push(1);
  Assert(queue.size() == 1);
  Assert(!queue.empty());
  Assert(!queue.full());
  Assert(queue.front() == 1);

  queue.push(2);
  Assert(queue.size() == 2);
  Assert(!queue.empty());
  Assert(queue.full());
  Assert(queue.front() == 1);
  
  Assert(queue.pop() == 1);
  Assert(queue.size() == 1);
  Assert(!queue.empty());
  Assert(!queue.full());
  Assert(queue.front() == 2);

  Assert(queue.pop() == 2);
  Assert(queue.size() == 0);
  Assert(queue.empty());
  Assert(!queue.full());
}

void test_queue_random(size_t size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::discrete_distribution<int> dis({1, 2});

  std::vector<int> array(10 * size);
  std::iota(array.begin(), array.end(), 0);

  size_t write_index = 0;
  size_t read_index = 0;

  Queue<int> queue(size);

  for (size_t i = 0 ; i < array.size(); ++i) {
    if (dis(gen) == 0) {
      if (queue.full() == false) {
        queue.push(array[write_index++]);
      }
    } else {
      if (queue.empty() == false) {
        Assert(queue.pop() == array[read_index++]);
      }
    }
  }

  while(read_index < write_index) {
    Assert(queue.pop() == array[read_index++]);
  }
}

int main() {
  test_queue_1();
  test_queue_2();

  test_queue_random(1);
  test_queue_random(2);
  test_queue_random(5);
  test_queue_random(10);
}
