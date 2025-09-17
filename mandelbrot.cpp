/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 mandelbrot.cpp -o mandelbrot
 *
 * Usage:
 *      $ ./mandelbrot
 */

#include <iostream>

char digit(int iteration, int maxIteration) {
  return '0' + (iteration % 10);
}

char hash(int iteration, int maxIteration) {
  return (iteration == maxIteration) ? '#' : ' ';
}

char space(int iteration, int maxIteration) {
  return (iteration == maxIteration) ? ' ' : '#';
}

char asciiArt1(int iteration, int maxIteration) {
  char const* const ascii = " .,:;^*&#@";
  return ascii[iteration % 10];
}

char asciiArt2(int iteration, int maxIteration) {
  char const* const ascii = "@#&*^;:,. ";
  return ascii[iteration % 10];
}

void mandelbrot(char (*getAscii)(int, int), unsigned const rows = 51, unsigned const columns = 2.5 * 50) {
  int const maxIteration = 50;

  for(double r = -1.5; r < 1.5; r += (3.0 / rows)) {
    for(double c = -2.5; c < 1.5; c += (4.0 / columns)) {
      int iteration = 0;

      for(double x = 0, y = 0; x * x + y * y < 4 && iteration < maxIteration; ++iteration) {
        double const temp = c + (x * x - y * y);
        y = r + (2 * x * y);
        x = temp;
      }

      std::cout << getAscii(iteration, maxIteration);
    }

    std::cout << std::endl;
  }
}

/*
 * main
 */

int main() {
  mandelbrot(&digit);
  mandelbrot(&hash);
  mandelbrot(&space);
  mandelbrot(&asciiArt1);
  mandelbrot(&asciiArt2);
}
