#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <vector>

/*
 * FindUnion
 */

class FindUnion {
public:
  FindUnion(int size)
      : _data(size) {
    for(int i = 0; i < size; ++i) {
      _data[i] = i;
    }
  }

  int cfind(int i) const {
    while(_data[i] != i) {
      i = _data[i];
    }

    return i;
  }

  int find(int i) {
    if(_data[i] == i) {
      return i;
    }

    const int root = find(_data[i]);

    _data[i] = root;
    return i;
  }

  void merge(int i, int j) {
    const int i_pos = cfind(i);
    const int j_pos = cfind(j);

    _data[i_pos] = j_pos;
  }

  unsigned size() const {
    return _data.size();
  }

  std::vector<int> getData() const {
    return _data;
  }

private:
  std::vector<int> _data;
};
