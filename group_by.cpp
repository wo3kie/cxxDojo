/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/group_by
 */

#include "./group_by.hpp"
#include "./assert.hpp"

struct T {
  int i;
  float f;
  char c;
};

bool operator==(const T& lhs, const T& rhs) {
  return lhs.i == rhs.i && lhs.f == rhs.f && lhs.c == rhs.c;
}

int get_i(const T& t) {
  return t.i;
}

const int& get_cir(const T& t) {
  return t.i;
}

struct Get_f {
  float operator()(const T& t) const {
    return t.f;
  }
};

const auto get_c = [](const T& t) {
  return t.c;
};

int main() {
  std::vector<T> v{
      {T{1, 1.1f, 'a'}, //
       T{2, 2.2f, 'b'},
       T{2, 2.2f, 'c'},
       T{3, 3.3f, 'd'},
       T{3, 3.3f, 'e'},
       T{3, 3.3f, 'f'}}};

  {
    const std::map<int, std::vector<T>> actual = groupBy(v.begin(), v.end(), &get_i);

    const std::map<int, std::vector<T>> expected{
        {{1, {T{1, 1.1f, 'a'}}}, //
         {2, {T{2, 2.2f, 'b'}, T{2, 2.2f, 'c'}}},
         {3, {T{3, 3.3f, 'd'}, T{3, 3.3f, 'e'}, T{3, 3.3f, 'f'}}}}};

    assert(actual == expected);
  }

  {
    const std::map<int, std::vector<T>> actual = groupBy(v.begin(), v.end(), &get_cir);

    const std::map<int, std::vector<T>> expected{
        {{1, {T{1, 1.1f, 'a'}}}, //
         {2, {T{2, 2.2f, 'b'}, T{2, 2.2f, 'c'}}},
         {3, {T{3, 3.3f, 'd'}, T{3, 3.3f, 'e'}, T{3, 3.3f, 'f'}}}}};

    assert(actual == expected);
  }

  {
    const std::map<int, std::map<float, std::vector<T>>> actual = groupBy(v.begin(), v.end(), &get_i, Get_f());

    const std::map<int, std::map<float, std::vector<T>>> expected{
        {{1, {{1.1f, {T{1, 1.1f, 'a'}}}}},
         {2, {{2.2f, {T{2, 2.2f, 'b'}, T{2, 2.2f, 'c'}}}}},
         {3, {{3.3f, {T{3, 3.3f, 'd'}, T{3, 3.3f, 'e'}, T{3, 3.3f, 'f'}}}}}}};

    assert(actual == expected);
  }

  {
    const std::map<int, std::map<float, std::map<char, std::vector<T>>>> actual = groupBy(v.begin(), v.end(), &get_i, Get_f(), get_c);

    const std::map<int, std::map<float, std::map<char, std::vector<T>>>> expected{
        {{1, {{1.1f, {{'a', {T{1, 1.1f, 'a'}}}}}}},
         {2, {{2.2f, {{'b', {T{2, 2.2f, 'b'}}}, {'c', {T{2, 2.2f, 'c'}}}}}}},
         {3, {{3.3f, {{'d', {T{3, 3.3f, 'd'}}}, {'e', {T{3, 3.3f, 'e'}}}, {'f', {T{3, 3.3f, 'f'}}}}}}}}};

    assert(actual == expected);
  }
}
