/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 levenstein.cpp -o levenstein
 *
 * Usage:
 *      $ ./levenstein distance distant
 *      2
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "./levenstein.hpp"

/*
 *levensteinDistance_test_1
 */

void levensteinDistance_test_1() {
  assert(0 == levensteinDistance<std::string>("", ""));
  assert(0 == levensteinDistance<std::string>("euler", "euler"));
}

/*
 * levensteinDistance_test_2
 */

void levensteinDistance_test_2() {
  assert(1 == levensteinDistance<std::string>("", "e"));

  assert(1 == levensteinDistance<std::string>("euler", "uler"));
  assert(1 == levensteinDistance<std::string>("euler", "eler"));
  assert(1 == levensteinDistance<std::string>("euler", "euer"));
  assert(1 == levensteinDistance<std::string>("euler", "eulr"));
  assert(1 == levensteinDistance<std::string>("euler", "eule"));

  assert(1 == levensteinDistance<std::string>("euler", "_euler"));
  assert(1 == levensteinDistance<std::string>("euler", "e_uler"));
  assert(1 == levensteinDistance<std::string>("euler", "eu_ler"));
  assert(1 == levensteinDistance<std::string>("euler", "eul_er"));
  assert(1 == levensteinDistance<std::string>("euler", "eule_r"));
  assert(1 == levensteinDistance<std::string>("euler", "euler_"));

  assert(1 == levensteinDistance<std::string>("euler", "_uler"));
  assert(1 == levensteinDistance<std::string>("euler", "e_ler"));
  assert(1 == levensteinDistance<std::string>("euler", "eu_er"));
  assert(1 == levensteinDistance<std::string>("euler", "eul_r"));
  assert(1 == levensteinDistance<std::string>("euler", "eule_"));
}

/*
 * levensteinDistance_test_3
 */

void levensteinDistance_test_3() {
  assert(2 == levensteinDistance<std::string>("c++", "c++++"));
  assert(2 == levensteinDistance<std::string>("c++", "++c++"));

  assert(2 == levensteinDistance<std::string>("c++", "c"));
  assert(2 == levensteinDistance<std::string>("c++", "+"));

  assert(2 == levensteinDistance<std::string>("c++", "c__"));
  assert(2 == levensteinDistance<std::string>("c++", "_+_"));
  assert(2 == levensteinDistance<std::string>("c++", "__+"));
}

/*
 * levensteinDistance_test_4
 */

void levensteinDistance_test_4() {
  assert(3 == levensteinDistance<std::string>("c++", "___"));
  assert(3 == levensteinDistance<std::string>("Levenshtein", "Le_ensteins"));
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  levensteinDistance_test_1();
  levensteinDistance_test_2();
  levensteinDistance_test_3();
  levensteinDistance_test_4();

  if(argc != 3) {
    std::cerr << "Usage " << argv[0] << " word word\n";
    return 1;
  }

  std::cout << levensteinDistance<std::string>(argv[1], argv[2]) << std::endl;
}
