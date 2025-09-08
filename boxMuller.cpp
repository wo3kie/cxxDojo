/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 boxMuller.cpp -o boxMuller
 *
 * Usage:
 *      $ ./boxMuller
 */

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>

double getUniformRandom() {
  return 1.0 * rand() / RAND_MAX;
}

double boxMuller(double mu, double sigma) {
  static int counter = 0;

  double const u1 = 1.0 * rand() / RAND_MAX;
  double const u2 = 1.0 * rand() / RAND_MAX;

  if(counter++ % 2) {
    return sigma * sqrt(-2 * log(u1)) * cos(2 * M_PI * u2) + mu;
  } else {
    return sigma * sqrt(-2 * log(u2)) * cos(2 * M_PI * u1) + mu;
  }
}

double getNormalRandom(double mu, double sigma) {
  return boxMuller(mu, sigma);
}

std::map<int, int> getDistribution(std::function<double()> const& f) {
  std::map<int, int> result;

  for(int i = 0; i < 50 * 1000; i++) {
    result[std::round(f())] += 1;
  }

  for(auto& pair : result) {
    pair.second /= 200;
  }

  return result;
}

void printDistrubution(std::map<int, int> const& map) {
  for(auto const& pair : map) {
    std::cout << std::fixed << std::setprecision(1) << std::setw(2) << pair.first << " "
              << std::string(pair.second, '*') << std::endl;
  }
}

int main() {
  std::cout << "Uniform distrution" << std::endl;
  printDistrubution(getDistribution([]() {
    return 20.0 * getUniformRandom();
  }));

  std::cout << "\nNormal distrution" << std::endl;
  printDistrubution(getDistribution([]() {
    return getNormalRandom(10, 4);
  }));
}
