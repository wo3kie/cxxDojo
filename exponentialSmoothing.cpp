/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 exponentialSmoothing.cpp -o exponentialSmoothing
 *
 * Usage:
 *      $ ./exponentialSmoothing
 */

#include <vector>

#include "./output.hpp"

std::vector<double> exponentialSmoothing(std::vector<double> const& array, double const alpha) {
  std::vector<double> result(array.size() - 1);

  result[0] = array[0];

  for(std::size_t i = 1; i < result.size(); ++i) {
    result[i] = alpha * array[i] + (1 - alpha) * result[i - 1];
  }

  return result;
}

template<typename Iterator, typename Iterator2>
double meanSquaredError(Iterator expectedBegin, Iterator const expectedEnd, Iterator2 actualBegin) {
  std::size_t counter = 0;
  double error2Sum = 0;

  for(; expectedBegin != expectedEnd; ++expectedBegin, ++actualBegin) {
    double const error = *expectedBegin - *actualBegin;
    double const error2 = error * error;

    counter += 1;
    error2Sum += error2;
  }

  return error2Sum / counter;
}

std::vector<double>
findBestExponentialSmoothing(std::vector<double> const values, double& alpha, double from = 0.0, double to = 1.0) {
  alpha = 1;
  std::vector<double> smoothed = exponentialSmoothing(values, to);
  double minError = meanSquaredError(values.begin() + 1, values.end(), smoothed.begin());

  for(double alpha2 = from; alpha2 < to; alpha2 += (to - from) / 10) {
    std::vector<double> smoothed2 = exponentialSmoothing(values, alpha2);

    double const error2 = meanSquaredError(values.begin() + 1, values.end(), smoothed2.begin());

    if(error2 < minError) {
      alpha = alpha2;
      minError = error2;
      smoothed = smoothed2;
    }
  }

  return smoothed;
}

int main() {
  double alpha;
  std::vector<double> const values{39, 44, 40, 45, 38, 43, 39};

  std::cout << findBestExponentialSmoothing(values, alpha) << "\n";

  std::cout << alpha << std::endl;
}
