/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 bloom_filter.cpp -o bloom_filter
 *
 * Usage:
 *      $ ./bloom_filter
 */

#include <cassert>
#include <iostream>
#include <string>

#include "./bloom_filter.hpp"

/*
 * main
 */

int main() {
  BloomFilter<std::string> bf(32);

  const auto hash1 = [](const std::string& s) {
    int result = 0;

    for(char c : s) {
      result += c;
    }

    return result;
  };

  const auto hash2 = [](const std::string& s) {
    int result = 0;

    for(unsigned i = 0; i < s.size(); ++i) {
      result += (i * s[i]);
    }

    return result;
  };

  const auto hash3 = [](const std::string& s) {
    return std::hash<std::string>()(s);
  };

  bf.addHash(hash1);
  bf.addHash(hash2);
  bf.addHash(hash3);

  bf.insert("c++");
  bf.insert("python");
  bf.insert("haskell");

  assert(bf.find("c++") == Maybe);
  assert(bf.find("python") == Maybe);
  assert(bf.find("haskell") == Maybe);

  assert(bf.find("java") == None);
  assert(bf.find("c#") == None);
  assert(bf.find("perl") == None);

  assert(optimalNumberOfBits(1e3, 0.01) == 9586 /* 1.2kB */);
  assert(optimalNumberOfBits(1e3, 0.001) == 14378 /* 1.7kB */);
  assert(optimalNumberOfBits(1e3, 0.0001) == 19171 /* 2.3kB */);

  assert(optimalNumberOfHashFunctions(1e3, 9586) == 7);
  assert(optimalNumberOfHashFunctions(1e3, 14378) == 10);
  assert(optimalNumberOfHashFunctions(1e3, 19171) == 14);

  assert(optimalNumberOfBits(1e6, 0.001) == 14377578 /* 1.7MB */);
  assert(optimalNumberOfBits(1e6, 0.0001) == 19170104 /* 2.3MB */);
  assert(optimalNumberOfBits(1e6, 0.00001) == 23962630 /* 2.9MB */);

  assert(optimalNumberOfHashFunctions(1e6, 14377578) == 10);
  assert(optimalNumberOfHashFunctions(1e6, 19170104) == 14);
  assert(optimalNumberOfHashFunctions(1e6, 23962630) == 17);

  assert(optimalNumberOfBits(1e9, 0.001) == 1492676007 /* 177MB */);
  assert(optimalNumberOfBits(1e9, 0.0001) == 1990234676 /* 237MB */);
  assert(optimalNumberOfBits(1e9, 0.00001) == 2487793345 /* 296MB */);

  assert(optimalNumberOfHashFunctions(1e9, 1492676007) == 2);
  assert(optimalNumberOfHashFunctions(1e9, 1990234676) == 2);
  assert(optimalNumberOfHashFunctions(1e9, 2487793345) == 2);
}
