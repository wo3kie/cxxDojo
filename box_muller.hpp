#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <cmath>

/*
 * get_uniform_random
 */

inline double get_uniform_random() {
  return 1.0 * rand() / RAND_MAX;
}

/*
 * box_muller
 */

inline double box_muller(double mu, double sigma) {
  static int counter = 0;

  const double u1 = 1.0 * rand() / RAND_MAX;
  const double u2 = 1.0 * rand() / RAND_MAX;

  if(counter++ % 2) {
    return sigma * sqrt(-2 * log(u1)) * cos(2 * M_PI * u2) + mu;
  } else {
    return sigma * sqrt(-2 * log(u2)) * cos(2 * M_PI * u1) + mu;
  }
}
/*
 * get_normal_random
 */

inline double get_normal_random(double mu, double sigma) {
  return box_muller(mu, sigma);
}
