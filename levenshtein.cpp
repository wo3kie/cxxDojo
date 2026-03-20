/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Usage:
 *      $ ./levenshtein distance distant
 *      2
 */

#include <iostream>
#include <string>
#include <vector>

#include "./assert.hpp"
#include "./levenshtein.hpp"

/*
 * levenshtein_distance_test_1
 */

void levenshtein_distance_test_1() {
  Assert(0 == levenshtein_distance<std::string>("", ""));
  Assert(0 == levenshtein_distance<std::string>("euler", "euler"));
}

/*
 * levenshtein_distance_test_2
 */

void levenshtein_distance_test_2() {
  Assert(1 == levenshtein_distance<std::string>("", "e"));

  Assert(1 == levenshtein_distance<std::string>("euler", "uler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "euer"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eulr"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eule"));

  Assert(1 == levenshtein_distance<std::string>("euler", "_euler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "e_uler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eu_ler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eul_er"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eule_r"));
  Assert(1 == levenshtein_distance<std::string>("euler", "euler_"));

  Assert(1 == levenshtein_distance<std::string>("euler", "_uler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "e_ler"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eu_er"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eul_r"));
  Assert(1 == levenshtein_distance<std::string>("euler", "eule_"));
}

/*
 * levenshtein_distance_test_3
 */

void levenshtein_distance_test_3() {
  Assert(2 == levenshtein_distance<std::string>("c++", "c++++"));
  Assert(2 == levenshtein_distance<std::string>("c++", "++c++"));

  Assert(2 == levenshtein_distance<std::string>("c++", "c"));
  Assert(2 == levenshtein_distance<std::string>("c++", "+"));

  Assert(2 == levenshtein_distance<std::string>("c++", "c__"));
  Assert(2 == levenshtein_distance<std::string>("c++", "_+_"));
  Assert(2 == levenshtein_distance<std::string>("c++", "__+"));
}

/*
 * levenshtein_distance_test_4
 */

void levenshtein_distance_test_4() {
  Assert(3 == levenshtein_distance<std::string>("c++", "___"));
  Assert(3 == levenshtein_distance<std::string>("Levenshtein", "Le_ensteins"));
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  levenshtein_distance_test_1();
  levenshtein_distance_test_2();
  levenshtein_distance_test_3();
  levenshtein_distance_test_4();

  if(argc != 3) {
    std::cerr << "Usage " << argv[0] << " word word\n";
    return 1;
  }

  std::cout << levenshtein_distance<std::string>(argv[1], argv[2]) << std::endl;
}
