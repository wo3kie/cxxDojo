/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 pi.cpp -o pi
 *
 * Usage:
 *      $ ./pi
 */

#include <iostream>
#include <random>

double getPi(unsigned const iterations) {
  unsigned inside = 0;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(0.0, 2.0);

  for(int i = 0; i < iterations; ++i) {
    double const x = dist(gen) - 1.0;
    double const y = dist(gen) - 1.0;

    if(x * x + y * y <= 1) {
      inside += 1;
    }
  }

  return 4.0 * inside / iterations;
}

int main(int argc, char* argv[]) {
  std::cout << getPi(10) << std::endl;
  std::cout << getPi(100) << std::endl;
  std::cout << getPi(1000) << std::endl;
  std::cout << getPi(10000) << std::endl;
  std::cout << getPi(100000) << std::endl;
}
