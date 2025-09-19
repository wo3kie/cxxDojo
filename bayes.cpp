/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Training set:
 *      http://www.dt.fee.unicamp.br/~tiago/smsspamcollection/smsspamcollection.zip
 *
 * Usage:
 *      $ ./build/bin/bayes
 *      URGENT! You have won a 1 week FREE membership in our £100,000 Prize Jackpot!
 *      ...
 *      {{ham,-118.253},{spam,-89.9372}}
 */

#include <cmath>
#include <fstream>
#include <map>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include "./bayes.hpp"
#include "./output.hpp"

/*
 * main
 */

int main() {
  NaiveBayes bayes;

  std::ifstream spamFile("bayes.spam.txt");

  if(! spamFile) {
    std::cerr << "ERROR: Can not open a file 'bayes.spam.txt'" << std::endl;
    return 1;
  }

  std::string line;

  while(std::getline(spamFile, line)) {
    boost::tokenizer<> tokenizer(line);
    std::vector<std::string> items;

    for(const std::string& token : tokenizer) {
      items.push_back(boost::algorithm::to_lower_copy(token));
    }

    bayes.learn("spam", items);
  }

  std::ifstream hamFile("bayes.ham.txt");

  if(! hamFile) {
    std::cerr << "ERROR: Can not open a file 'bayes.ham.txt'" << std::endl;
    return 2;
  }

  while(std::getline(hamFile, line)) {
    boost::tokenizer<> tokenizer(line);
    std::vector<std::string> items;

    for(const std::string& token : tokenizer) {
      items.push_back(boost::algorithm::to_lower_copy(token));
    }

    bayes.learn("ham", items);
  }

  bayes.recalculateStats();

  while(std::getline(std::cin, line)) {
    std::vector<std::string> items;
    boost::tokenizer<> tokenizer(line);

    for(const std::string& token : tokenizer) {
      items.push_back(boost::algorithm::to_lower_copy(token));
    }

    const std::map<std::string, double>& classesProbability = bayes.classify(items);
    std::cout << classesProbability << std::endl;

    return 0;
  }
}
