/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Training set:
 *      http://www.dt.fee.unicamp.br/~tiago/smsspamcollection/smsspamcollection.zip
 *
 * Compilation:
 *      g++ --std=c++20 bayes.cpp -o bayes
 *
 * Usage:
 *      $ ./bayes
 *      URGENT! You have won a 1 week FREE membership in our £100,000 Prize Jackpot!
 *      ...
 *      {{ham,-118.253},{spam,-89.9372}}
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include "./output.hpp"

struct ItemStats {
  unsigned counter_ = 0;
  double probability_ = 0;
};

struct ClassStats {
  unsigned itemCounter_ = 0;
  double minProbability_ = 1;
  std::map<std::string, ItemStats> itemStats_;
};

class NaiveBayes {
public:
  void learn(std::string const className, std::vector<std::string> const& items) {
    itemCounter_ += 1;

    ClassStats& classStats = stats_[className];
    classStats.itemCounter_ += 1;

    for(auto const& item : items) {
      classStats.itemStats_[item].counter_ += 1;
    }
  }

  void recalculateStats() {
    for(auto& clazz : stats_) {
      recalculateClass(clazz);
    }
  }

  std::map<std::string, double> classify(std::vector<std::string> const& items) const {
    std::map<std::string, double> classes;

    for(auto const& pair : stats_) {
      std::string const& name = pair.first;
      ClassStats const& stat = pair.second;

      double const classProbability = 1.0 * stat.itemCounter_ / itemCounter_;
      classes[name] = std::log(classProbability) + classifyClass(pair, items);

      std::cout << "class '" << name << "'"
                << " has probability: " << classProbability << " (" << std::log(classProbability) << ")"
                << " and a final result: " << classes[name] << std::endl;
    }

    return classes;
  }

private:
  static double
  classifyClass(std::pair<std::string const, ClassStats> const& clazz, std::vector<std::string> const& items) {
    std::string const& name = clazz.first;
    ClassStats const& stats = clazz.second;

    double probability = 0;

    for(auto const& item : items) {
      auto const& itemIterator = stats.itemStats_.find(item);

      if(itemIterator == stats.itemStats_.end()) {
        probability += std::log(stats.minProbability_);

        std::cout << "class '" << name << "'"
                  << " item '" << item << "'"
                  << " not found: " << stats.minProbability_ << " (" << std::log(stats.minProbability_) << ")"
                  << std::endl;
      } else {
        probability += std::log(itemIterator->second.probability_);

        std::cout << "class '" << name << "'"
                  << " item '" << item << "'"
                  << " found: " << itemIterator->second.probability_ << " ("
                  << std::log(itemIterator->second.probability_) << ")" << std::endl;
      }
    }

    return probability;
  }

  static void recalculateClass(std::pair<std::string const, ClassStats>& clazz) {
    unsigned allItemsCounter = 0;
    ClassStats& classStats = clazz.second;

    for(auto const& pair : classStats.itemStats_) {
      ItemStats const& itemStats = pair.second;

      allItemsCounter += itemStats.counter_;
    }

    for(auto& pair : classStats.itemStats_) {
      ItemStats& itemStats = pair.second;

      itemStats.probability_ = 1.0 * itemStats.counter_ / allItemsCounter;
    }

    double minProbability = 1;

    for(auto const& pair : clazz.second.itemStats_) {
      ItemStats const& itemStats = pair.second;

      if(minProbability > itemStats.probability_) {
        minProbability = itemStats.probability_;
      }
    }

    classStats.minProbability_ = minProbability;
  }

private:
  unsigned itemCounter_ = 0;
  std::map<std::string, ClassStats> stats_;
};

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

    for(std::string const& token : tokenizer) {
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

    for(std::string const& token : tokenizer) {
      items.push_back(boost::algorithm::to_lower_copy(token));
    }

    bayes.learn("ham", items);
  }

  bayes.recalculateStats();

  while(std::getline(std::cin, line)) {
    std::vector<std::string> items;
    boost::tokenizer<> tokenizer(line);

    for(std::string const& token : tokenizer) {
      items.push_back(boost::algorithm::to_lower_copy(token));
    }

    std::map<std::string, double> const& classesProbability = bayes.classify(items);

    std::cout << classesProbability << std::endl;

    return 0;
  }
}
