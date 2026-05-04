/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <iostream>

#include "./assert.hpp"
#include "./task_worker.hpp"

int main()
{
  std::size_t counter = 0;

  {
    TaskWorkerSPSC<4, std::function<void()>> worker;

    for(std::size_t i = 0; i < 1024; ++i) {
      while(! worker.push([i, &counter]() {
        counter += 1;
      })) {
      };
    }

    worker.stop();
  }

  Assert(counter == 1024);

  return 0;
}
