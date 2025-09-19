/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/exponential_smoothing alpha value1 value2 ...
 * 
 * Example:
 *      $ ./build/bin/exponential_smoothing 0.8 9 1 8 2 7 3 6 4 5
 *      [9, 2.6, 6.92, 2.984, 6.1968, 3.63936, 5.52787, 4.30557]
 */

#include <vector>

#include "./exponential_smoothing.hpp"
#include "./output.hpp"

/*
 * main
 */

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cerr << "Usage: " << argv[0] << " alpha value1 value2 ..." << std::endl;
    return 1;
  }

  std::vector<double> array;
  const double alpha = std::stod(argv[1]);

  for(int i = 2; i < argc; ++i) {
    array.push_back(std::stod(argv[i]));
  }

  const std::vector<double> smoothed = exponentialSmoothing(array, alpha);

  std::cout << smoothed << std::endl;
}
