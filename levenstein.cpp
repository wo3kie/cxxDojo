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

#include <iostream>
#include <string>
#include <vector>

#include "./assert.hpp"
#include "./levenstein.hpp"

/*
 * levensteinDistance_test_1
 */

void levensteinDistance_test_1() {
  Assert(0 == levensteinDistance<std::string>("", ""));
  Assert(0 == levensteinDistance<std::string>("euler", "euler"));
}

/*
 * levensteinDistance_test_2
 */

void levensteinDistance_test_2() {
  Assert(1 == levensteinDistance<std::string>("", "e"));

  Assert(1 == levensteinDistance<std::string>("euler", "uler"));
  Assert(1 == levensteinDistance<std::string>("euler", "eler"));
  Assert(1 == levensteinDistance<std::string>("euler", "euer"));
  Assert(1 == levensteinDistance<std::string>("euler", "eulr"));
  Assert(1 == levensteinDistance<std::string>("euler", "eule"));

  Assert(1 == levensteinDistance<std::string>("euler", "_euler"));
  Assert(1 == levensteinDistance<std::string>("euler", "e_uler"));
  Assert(1 == levensteinDistance<std::string>("euler", "eu_ler"));
  Assert(1 == levensteinDistance<std::string>("euler", "eul_er"));
  Assert(1 == levensteinDistance<std::string>("euler", "eule_r"));
  Assert(1 == levensteinDistance<std::string>("euler", "euler_"));

  Assert(1 == levensteinDistance<std::string>("euler", "_uler"));
  Assert(1 == levensteinDistance<std::string>("euler", "e_ler"));
  Assert(1 == levensteinDistance<std::string>("euler", "eu_er"));
  Assert(1 == levensteinDistance<std::string>("euler", "eul_r"));
  Assert(1 == levensteinDistance<std::string>("euler", "eule_"));
}

/*
 * levensteinDistance_test_3
 */

void levensteinDistance_test_3() {
  Assert(2 == levensteinDistance<std::string>("c++", "c++++"));
  Assert(2 == levensteinDistance<std::string>("c++", "++c++"));

  Assert(2 == levensteinDistance<std::string>("c++", "c"));
  Assert(2 == levensteinDistance<std::string>("c++", "+"));

  Assert(2 == levensteinDistance<std::string>("c++", "c__"));
  Assert(2 == levensteinDistance<std::string>("c++", "_+_"));
  Assert(2 == levensteinDistance<std::string>("c++", "__+"));
}

/*
 * levensteinDistance_test_4
 */

void levensteinDistance_test_4() {
  Assert(3 == levensteinDistance<std::string>("c++", "___"));
  Assert(3 == levensteinDistance<std::string>("Levenshtein", "Le_ensteins"));
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
