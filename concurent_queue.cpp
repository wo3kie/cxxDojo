/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/concurent_queue
 *      OK
 */

#include <cassert>
#include <iostream>
#include <thread>

#include "./concurent_queue.hpp"

/*
 * producer
 */

void producer(concurent_queue<int>& queue) {
  for(int i = 0; i < 1000; ++i) {
    queue.push(i);
  }
}

/*
 * consumer
 */

void consumer(concurent_queue<int>& queue) {
  int sum = 0;

  for(int i = 0; i < 1000; ++i) {
    sum += queue.get();
  }

  assert(sum == (0 + 999) * (1000 / 2));

  std::cout << "OK" << std::endl;
}

/*
 * main
 */

int main() {
  concurent_queue<int> buffer(100);

  std::thread p(&producer, std::ref(buffer));
  std::thread c(&consumer, std::ref(buffer));

  c.join();
  p.join();

  return 0;
}
