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
  unsigned _counter = 0;
  double _probability = 0;
};

struct _ClassStats {
  unsigned _itemCounter = 0;
  double _minProbability = 1;
  std::map<std::string, _ItemStats> _itemStats;
};

} // namespace impl

/*
 * NaiveBayes
 */

class NaiveBayes {
public:
  void learn(const std::string& className, const std::vector<std::string>& items) {
    _itemCounter += 1;

    impl::_ClassStats& classStats = _stats[className];
    classStats._itemCounter += 1;

    for(const auto& item : items) {
      classStats._itemStats[item]._counter += 1;
    }
  }

  void recalculateStats() {
    for(auto& stat : _stats) {
      recalculateClass(stat);
    }
  }

  std::map<std::string, double> classify(const std::vector<std::string>& items) const {
    std::map<std::string, double> classes;

    for(const auto& pair : _stats) {
      const std::string& name = pair.first;
      const impl::_ClassStats& stat = pair.second;

      const double classProbability = 1.0 * stat._itemCounter / _itemCounter;
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
      const auto& itemIterator = stats._itemStats.find(item);

      if(itemIterator == stats._itemStats.end()) {
        probability += std::log(stats._minProbability);

        std::cout << "class '" << name << "'" << " item '" << item << "'" << " not found: " << stats._minProbability << " (" << std::log(stats._minProbability)
                  << ")" << std::endl;
      } else {
        probability += std::log(itemIterator->second._probability);

        std::cout << "class '" << name << "'" << " item '" << item << "'" << " found: " << itemIterator->second._probability << " ("
                  << std::log(itemIterator->second._probability) << ")" << std::endl;
      }
    }

    return probability;
  }

  static void recalculateClass(std::pair<const std::string, impl::_ClassStats>& clazz) {
    unsigned allItemsCounter = 0;
    impl::_ClassStats& classStats = clazz.second;

    for(const auto& pair : classStats._itemStats) {
      const impl::_ItemStats& itemStats = pair.second;
      allItemsCounter += itemStats._counter;
    }

    for(auto& pair : classStats._itemStats) {
      impl::_ItemStats& itemStats = pair.second;
      itemStats._probability = 1.0 * itemStats._counter / allItemsCounter;
    }

    double minProbability = 1;

    for(const auto& pair : clazz.second._itemStats) {
      const impl::_ItemStats& itemStats = pair.second;

      if(minProbability > itemStats._probability) {
        minProbability = itemStats._probability;
      }
    }

    classStats._minProbability = minProbability;
  }

private:
  unsigned _itemCounter = 0;
  std::map<std::string, impl::_ClassStats> _stats;
};
