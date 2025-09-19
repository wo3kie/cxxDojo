#include <iostream>
#include <set>

#include "trie.hpp"

void test() {
  Trie trie;
  assert(! trie.getOrCreate(""));
  assert(trie.getOrCreate("A"));
  assert(trie.getOrCreate("Z"));
  assert(trie.getOrCreate("_"));
  assert(trie.getOrCreate("0"));
  assert(trie.getOrCreate("9"));

  assert(! trie.getOrCreate(""));
  assert(! trie.getOrCreate("A"));
  assert(! trie.getOrCreate("Z"));
  assert(! trie.getOrCreate("_"));
  assert(! trie.getOrCreate("0"));
  assert(! trie.getOrCreate("9"));

  assert(! trie.getOrCreate("A"));
  assert(trie.getOrCreate("AL"));
  assert(trie.getOrCreate("ALA"));
  assert(trie.getOrCreate("ALAN"));
  assert(trie.getOrCreate("ALANEK"));

  assert(! trie.getOrCreate("A"));
  assert(! trie.getOrCreate("AL"));
  assert(! trie.getOrCreate("ALA"));
  assert(! trie.getOrCreate("ALAN"));
  assert(! trie.getOrCreate("ALANEK"));

  assert(trie.getOrCreate("ALANE"));
  assert(! trie.getOrCreate("ALANE"));

  assert(trie.getOrCreate("A1B2C3D4"));
  assert(trie.getOrCreate("A1B2C3D"));
  assert(trie.getOrCreate("A1B2C3"));
  assert(trie.getOrCreate("A1B2C"));
  assert(trie.getOrCreate("A1B2"));
  assert(trie.getOrCreate("A1B"));
  assert(trie.getOrCreate("A1"));
  assert(! trie.getOrCreate("A"));

  assert(! trie.getOrCreate("A1B2C3D4"));
  assert(! trie.getOrCreate("A1B2C3D"));
  assert(! trie.getOrCreate("A1B2C3"));
  assert(! trie.getOrCreate("A1B2C"));
  assert(! trie.getOrCreate("A1B2"));
  assert(! trie.getOrCreate("A1B"));
  assert(! trie.getOrCreate("A1"));
  assert(! trie.getOrCreate("A"));

  std::set<std::string> actual;

  for(const std::string& word : trie.dump()) {
    actual.insert(word);
  }

  std::set<std::string> expected{
      "0",
      "9",
      "A",
      "Z",
      "_",
      "A1",
      "A1B",
      "A1B2",
      "A1B2C",
      "A1B2C3",
      "A1B2C3D",
      "A1B2C3D4",
      "AL",
      "ALA",
      "ALAN",
      "ALANE",
      "ALANEK",
  };

  assert(std::equal(actual.begin(), actual.end(), expected.begin()));
}

/*
 * main
 */

int main() {
  test();
}
