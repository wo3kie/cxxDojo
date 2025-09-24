/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/find_union
 */

#include "./assert.hpp"
#include "./find_union.hpp"
#include "./output.hpp"

using V = std::vector<int>;

void findUnion_test() {
  {
    FindUnion fu(6);
    assert((fu.getData() == V{0, 1, 2, 3, 4, 5}));

    fu.merge(3, 2);
    assert((fu.getData() == V{0, 1, 2, 2, 4, 5}));

    fu.merge(4, 3);
    assert((fu.getData() == V{0, 1, 2, 2, 2, 5}));

    fu.merge(2, 1);
    assert((fu.getData() == V{0, 1, 1, 2, 2, 5}));
  }

  {
    FindUnion fu(6);
    assert((fu.getData() == V{0, 1, 2, 3, 4, 5}));

    fu.merge(4, 3);
    assert((fu.getData() == V{0, 1, 2, 3, 3, 5}));

    fu.merge(3, 2);
    assert((fu.getData() == V{0, 1, 2, 2, 3, 5}));

    fu.merge(2, 1);
    assert((fu.getData() == V{0, 1, 1, 2, 3, 5}));

    fu.find(4);
    assert((fu.getData() == V{0, 1, 1, 1, 1, 5}));
  }
}

/*
 * main
 */

int main() {
  findUnion_test();
}