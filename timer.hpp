#pragma once

#include <chrono>
#include <iostream>

template<typename T>
void test(T const& t, int rep = 1) {
  // typedef ratio< 1,  1000000000000000000 > atto;
  // typedef ratio< 1,     1000000000000000 > femto;
  // typedef ratio< 1,        1000000000000 > pico;
  // typedef ratio< 1,           1000000000 > nano;
  // typedef ratio< 1,              1000000 > micro;
  // typedef ratio< 1,                 1000 > milli;
  // typedef ratio< 1,                  100 > centi;
  // typedef ratio< 1,                   10 > deci;
  //
  // typedef ratio< 10,                   1 > deca;
  // typedef ratio< 100,                  1 > hecto;
  // typedef ratio< 1000,                 1 > kilo;
  // typedef ratio< 1000000,              1 > mega;
  // typedef ratio< 1000000000,           1 > giga;
  // typedef ratio< 1000000000000,        1 > tera;
  // typedef ratio< 1000000000000000,     1 > peta;
  // typedef ratio< 1000000000000000000,  1 > exa;

  // typedef duration<int64_t, nano       > nanoseconds;
  // typedef duration<int64_t, micro      > microseconds;
  // typedef duration<int64_t, milli      > milliseconds;
  // typedef duration<int64_t             > seconds;
  // typedef duration<int64_t, ratio<  60>> minutes;
  // typedef duration<int64_t, ratio<3600>> hours;

  using duration = std::chrono::duration<long int, std::nano>;

  using time_point = std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>;

  duration bestTime = duration::zero();

  for(int i = 0; i < rep; ++i) {
    time_point const& start = std::chrono::high_resolution_clock::now();

    t();

    time_point const& end = std::chrono::high_resolution_clock::now();

    duration const& diff = end - start;

    if(bestTime == duration::zero() || bestTime > diff) {
      bestTime = diff;
    }
  }

  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(bestTime).count() << "µs" << std::endl;
}
