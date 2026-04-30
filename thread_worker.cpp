/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/parameter_pack
 */

#include <iostream>
#include <functional>

#include "./thread_worker.hpp"

int main() {
  ThreadWorkerSPSC<4, std::function<void()>> worker;

  for (size_t i = 0; i < 10; ++i) {
    worker.push([i]() {
      std::cout << "Task " << i << " executed." << std::endl;
    });
  }

  worker.stop();

  return 0;
}