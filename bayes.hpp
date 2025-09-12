#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include "./output.hpp"

namespace impl {

struct _ItemStats {
  unsigned counter_ = 0;
  double probability_ = 0;
};

struct _ClassStats {
  unsigned itemCounter_ = 0;
  double minProbability_ = 1;
  std::map<std::string, _ItemStats> itemStats_;
};

} // namespace impl

/*
 * NaiveBayes
 */

class NaiveBayes {
public:
  void learn(const std::string& className, const std::vector<std::string>& items) {
    itemCounter_ += 1;

    impl::_ClassStats& classStats = stats_[className];
    classStats.itemCounter_ += 1;

    for(const auto& item : items) {
      classStats.itemStats_[item].counter_ += 1;
    }
  }

  void recalculateStats() {
    for(auto& stat : stats_) {
      recalculateClass(stat);
    }
  }

  std::map<std::string, double> classify(const std::vector<std::string>& items) const {
    std::map<std::string, double> classes;

    for(const auto& pair : stats_) {
      const std::string& name = pair.first;
      const impl::_ClassStats& stat = pair.second;

      const double classProbability = 1.0 * stat.itemCounter_ / itemCounter_;
      classes[name] = std::log(classProbability) + classifyClass(pair, items);

      std::cout << "class '" << name << "'" << " has probability: " << classProbability << " (" << std::log(classProbability) << ")"
                << " and a final result: " << classes[name] << std::endl;
    }

    return classes;
  }

private:
  static double classifyClass(const std::pair<const std::string, impl::_ClassStats>& clazz, const std::vector<std::string>& items) {
    const std::string& name = clazz.first;
    const impl::_ClassStats& stats = clazz.second;

    double probability = 0;

    for(const auto& item : items) {
      const auto& itemIterator = stats.itemStats_.find(item);

      if(itemIterator == stats.itemStats_.end()) {
        probability += std::log(stats.minProbability_);

        std::cout << "class '" << name << "'" << " item '" << item << "'" << " not found: " << stats.minProbability_ << " (" << std::log(stats.minProbability_)
                  << ")" << std::endl;
      } else {
        probability += std::log(itemIterator->second.probability_);

        std::cout << "class '" << name << "'" << " item '" << item << "'" << " found: " << itemIterator->second.probability_ << " ("
                  << std::log(itemIterator->second.probability_) << ")" << std::endl;
      }
    }

    return probability;
  }

  static void recalculateClass(std::pair<const std::string, impl::_ClassStats>& clazz) {
    unsigned allItemsCounter = 0;
    impl::_ClassStats& classStats = clazz.second;

    for(const auto& pair : classStats.itemStats_) {
      const impl::_ItemStats& itemStats = pair.second;
      allItemsCounter += itemStats.counter_;
    }

    for(auto& pair : classStats.itemStats_) {
      impl::_ItemStats& itemStats = pair.second;
      itemStats.probability_ = 1.0 * itemStats.counter_ / allItemsCounter;
    }

    double minProbability = 1;

    for(const auto& pair : clazz.second.itemStats_) {
      const impl::_ItemStats& itemStats = pair.second;

      if(minProbability > itemStats.probability_) {
        minProbability = itemStats.probability_;
      }
    }

    classStats.minProbability_ = minProbability;
  }

private:
  unsigned itemCounter_ = 0;
  std::map<std::string, impl::_ClassStats> stats_;
};
