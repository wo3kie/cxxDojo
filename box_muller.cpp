/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 boxMuller.cpp -o boxMuller
 *
 * Usage:
 *      $ ./boxMuller
 * 
 * Uniform distrution
 *  0 ************
 *  1 *************************
 *  2 *************************
 *  3 *************************
 *  4 *************************
 *  5 ************************
 *  6 *************************
 *  7 ************************
 *  8 ************************
 *  9 *************************
 * 10 ************
 * 
 * Normal distrution
 * -7 
 * -6 
 * -5 *
 * -4 **
 * -3 ***
 * -2 *****
 * -1 *******
 *  0 ***********
 *  1 ***************
 *  2 ******************
 *  3 *********************
 *  4 ************************
 *  5 ************************
 *  6 ***********************
 *  7 *********************
 *  8 *******************
 *  9 **************
 * 10 ***********
 * 11 ********
 * 12 *****
 * 13 ***
 * 14 **
 * 15 *
 * 16 
 */

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>

#include "./box_muller.hpp"

/*
 * get_distribution
 */

std::map<int, int> get_distribution(const std::function<double()>& f) {
  std::map<int, int> result;

  for(int i = 0; i < 50 * 1000; i++) {
    result[std::round(f())] += 1;
  }

  for(auto& pair : result) {
    pair.second /= 200;
  }

  return result;
}

/*
 * print_distrubution
 */

void print_distrubution(const std::map<int, int>& map) {
  for(const auto& pair : map) {
    std::cout << std::fixed << std::setprecision(1) << std::setw(2) << pair.first << " " << std::string(pair.second, '*') << std::endl;
  }
}

/*
 * main
 */

int main() {
  std::cout << "Uniform distrution" << std::endl;

  print_distrubution(get_distribution([]() {
    return 10.0 * get_uniform_random();
  }));

  std::cout << "\nNormal distrution" << std::endl;

  print_distrubution(get_distribution([]() {
    return get_normal_random(5, 4);
  }));
}
