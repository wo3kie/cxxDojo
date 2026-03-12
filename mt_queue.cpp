/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/MTQueue
 *      OK
 */

#include <iostream>
#include <thread>

#include "./assert.hpp"
#include "./mt_queue.hpp"

/*
 * producer
 */

void producer(MTQueue<int>& queue) {
  for(int i = 0; i < 1000; ++i) {
    queue.push(i);
  }
}

/*
 * consumer
 */

void consumer(MTQueue<int>& queue) {
  int sum = 0;

  for(int i = 0; i < 1000; ++i) {
    sum += queue.pop();
  }

  Assert(sum == (0 + 999) * (1000 / 2));

  std::cout << "OK" << std::endl;
}

/*
 * main
 */

int main() {
  MTQueue<int> buffer(100);

  std::thread p(&producer, std::ref(buffer));
  std::thread c(&consumer, std::ref(buffer));

  c.join();
  p.join();

  return 0;
}
