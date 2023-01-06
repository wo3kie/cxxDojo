// g++ -g3 -fpic -c shared.cpp -o shared.o
// g++ -g3 -shared shared.o -o libshared.so

#include <iostream>

#include "shared.h"

extern "C" {
void helloWorld() {
  std::cout << "Hello World!" << std::endl;
}
}
