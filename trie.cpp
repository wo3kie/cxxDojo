#include <iostream>

#include "trie.hpp"

void test() {
    Trie trie;
    assert(!trie.getOrCreate(""));
    assert(trie.getOrCreate("A"));
    assert(trie.getOrCreate("Z"));
    assert(trie.getOrCreate("_"));
    assert(trie.getOrCreate("0"));
    assert(trie.getOrCreate("9"));

    assert(!trie.getOrCreate(""));
    assert(!trie.getOrCreate("A"));
    assert(!trie.getOrCreate("Z"));
    assert(!trie.getOrCreate("_"));
    assert(!trie.getOrCreate("0"));
    assert(!trie.getOrCreate("9"));

    assert(!trie.getOrCreate("A"));
    assert(trie.getOrCreate("AL"));
    assert(trie.getOrCreate("ALA"));
    assert(trie.getOrCreate("ALAN"));
    assert(trie.getOrCreate("ALANEK"));

    assert(!trie.getOrCreate("A"));
    assert(!trie.getOrCreate("AL"));
    assert(!trie.getOrCreate("ALA"));
    assert(!trie.getOrCreate("ALAN"));
    assert(!trie.getOrCreate("ALANEK"));

    assert(trie.getOrCreate("ALANE"));
    assert(!trie.getOrCreate("ALANE"));

    assert(trie.getOrCreate("A1B2C3D4"));
    assert(trie.getOrCreate("A1B2C3D"));
    assert(trie.getOrCreate("A1B2C3"));
    assert(trie.getOrCreate("A1B2C"));
    assert(trie.getOrCreate("A1B2"));
    assert(trie.getOrCreate("A1B"));
    assert(trie.getOrCreate("A1"));
    assert(!trie.getOrCreate("A"));

    assert(!trie.getOrCreate("A1B2C3D4"));
    assert(!trie.getOrCreate("A1B2C3D"));
    assert(!trie.getOrCreate("A1B2C3"));
    assert(!trie.getOrCreate("A1B2C"));
    assert(!trie.getOrCreate("A1B2"));
    assert(!trie.getOrCreate("A1B"));
    assert(!trie.getOrCreate("A1"));
    assert(!trie.getOrCreate("A"));
}

int main(){
    test();
}
