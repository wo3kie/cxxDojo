#include <iostream>
#include <set>

#include "./trie.hpp"

void test() {
  Trie trie;
  Assert(! trie.getOrCreate(""));
  Assert(trie.getOrCreate("A"));
  Assert(trie.getOrCreate("Z"));
  Assert(trie.getOrCreate("_"));
  Assert(trie.getOrCreate("0"));
  Assert(trie.getOrCreate("9"));

  Assert(! trie.getOrCreate(""));
  Assert(! trie.getOrCreate("A"));
  Assert(! trie.getOrCreate("Z"));
  Assert(! trie.getOrCreate("_"));
  Assert(! trie.getOrCreate("0"));
  Assert(! trie.getOrCreate("9"));

  Assert(! trie.getOrCreate("A"));
  Assert(trie.getOrCreate("AL"));
  Assert(trie.getOrCreate("ALA"));
  Assert(trie.getOrCreate("ALAN"));
  Assert(trie.getOrCreate("ALANEK"));

  Assert(! trie.getOrCreate("A"));
  Assert(! trie.getOrCreate("AL"));
  Assert(! trie.getOrCreate("ALA"));
  Assert(! trie.getOrCreate("ALAN"));
  Assert(! trie.getOrCreate("ALANEK"));

  Assert(trie.getOrCreate("ALANE"));
  Assert(! trie.getOrCreate("ALANE"));

  Assert(trie.getOrCreate("A1B2C3D4"));
  Assert(trie.getOrCreate("A1B2C3D"));
  Assert(trie.getOrCreate("A1B2C3"));
  Assert(trie.getOrCreate("A1B2C"));
  Assert(trie.getOrCreate("A1B2"));
  Assert(trie.getOrCreate("A1B"));
  Assert(trie.getOrCreate("A1"));
  Assert(! trie.getOrCreate("A"));

  Assert(! trie.getOrCreate("A1B2C3D4"));
  Assert(! trie.getOrCreate("A1B2C3D"));
  Assert(! trie.getOrCreate("A1B2C3"));
  Assert(! trie.getOrCreate("A1B2C"));
  Assert(! trie.getOrCreate("A1B2"));
  Assert(! trie.getOrCreate("A1B"));
  Assert(! trie.getOrCreate("A1"));
  Assert(! trie.getOrCreate("A"));

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

  Assert(std::equal(actual.begin(), actual.end(), expected.begin()));
}

/*
 * main
 */

int main() {
  test();
}
