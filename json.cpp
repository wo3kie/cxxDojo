/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 json.cpp -o json
 *
 * Usage:
 *      $ ./json
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

void print(boost::property_tree::ptree const& pt, int indent = 0) {
  for(auto const& object : pt) {
    if(object.first == "names") {
      auto const& objectName = object.first;
      auto const& array = object.second;

      std::cout << std::string(indent, ' ') << objectName << std::endl;

      for(auto const& item : array) {
        auto const& name = item.first;
        assert(name == ""); // for array a key is an empty string

        auto const& attrs = item.second;

        std::cout << std::string(indent + 4, ' ');

        for(auto const& attr : attrs) {
          auto const& attrName = attr.first;
          auto const& attrValue = attr.second.get_value<std::string>();

          std::cout << " " << attrName << ": " << attrValue;
        }

        std::cout << std::endl;
      }
    } else if(object.first == "doc") {
      std::cout << std::string(indent, ' ') << object.first << std::endl;
    }

    print(object.second, indent + 4);
  }
}

int main() {
  std::ifstream input("./json.json");

  boost::property_tree::ptree propertyTree;
  read_json(input, propertyTree);
  print(propertyTree);

  return 0;
}
