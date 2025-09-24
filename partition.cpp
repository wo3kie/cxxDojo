/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/partition
 */

#include <vector>

#include "./assert.hpp"
#include "./output.hpp"
#include "./partition.hpp"

typedef std::vector<int> VI;

/*
 * partition_if_test
 */

void partition_if_test() {
  const auto isEven = [](int i) {
    return i % 2 == 0;
  };
  const auto isOdd = [](int i) {
    return i % 2 != 0;
  };

  std::vector<int> array;

  {
    array = {};
    assert(partition_if(array, isEven) == array.end());
  }

  {
    array = {0};
    assert(partition_if(array, isEven) == array.end());
  }

  {
    array = {1};
    assert(partition_if(array, isEven) == array.begin());
  }

  {
    array = {1, 2};
    assert(*partition_if(array, isEven) == 1);
    assert((array == VI{2, 1}));
  }

  {
    array = {1, 2};
    assert(*partition_if(array, isOdd) == 2);
    assert((array == VI{1, 2}));
  }

  {
    array = {1, 2, 3};
    assert(*partition_if(array, isEven) == 3);
    assert((array == VI{2, 3, 1}));
  }

  {
    array = {1, 2, 3};
    assert(*partition_if(array, isOdd) == 2);
    assert((array == VI{1, 3, 2}));
  }

  {
    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(*partition_if(array, isEven) == 5);
    assert((array == VI{0, 8, 2, 6, 4, 5, 7, 3, 9, 1}));
  }

  {
    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(*partition_if(array, isOdd) == 6);
    assert((array == VI{9, 1, 7, 3, 5, 6, 4, 8, 2, 0}));
  }
}

/*
 * stable_partition_if_test
 */

void stable_partition_if_test() {
  const auto isEven = [](int i) {
    return i % 2 == 0;
  };
  const auto isOdd = [](int i) {
    return i % 2 != 0;
  };

  std::vector<int> array;

  {
    array = {};
    assert(stable_partition_if(array, isEven) == array.end());
  }

  {
    array = {0};
    assert(stable_partition_if(array, isEven) == array.end());
  }

  {
    array = {1};
    assert(stable_partition_if(array, isEven) == array.begin());
  }

  {
    array = {1, 2};
    assert(*stable_partition_if(array, isEven) == 1);
    assert((array == VI{2, 1}));
  }

  {
    array = {1, 2};
    assert(*stable_partition_if(array, isOdd) == 2);
    assert((array == VI{1, 2}));
  }

  {
    array = {1, 2, 3};
    assert(*stable_partition_if(array, isEven) == 1);
    assert((array == VI{2, 1, 3}));
  }

  {
    array = {1, 2, 3};
    assert(*stable_partition_if(array, isOdd) == 2);
    assert((array == VI{1, 3, 2}));
  }

  {
    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(*stable_partition_if(array, isEven) == 1);
    assert((array == VI{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}));
  }

  {
    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(*stable_partition_if(array, isOdd) == 0);
    assert((array == VI{1, 3, 5, 7, 9, 0, 2, 4, 6, 8}));
  }
}

/*
 * main
 */

int main() {
  partition_if_test();
  stable_partition_if_test();
}
