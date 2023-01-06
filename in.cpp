/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Named operators:
 *      https://github.com/klmr/named-operator
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 in.cpp -o in
 *
 * Usage:
 *      $ ./in
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <vector>

struct In {
  void const* ptr_ = nullptr;
  std::size_t type_ = 0;
} in;

template<typename T>
In operator<(T const& t, In in) {
  assert(in.type_ = typeid(T).hash_code());
  in.ptr_ = &t;
  return in;
}

template<typename T>
bool operator>(In const& in, std::vector<T> const& v) {
  assert(in.type_ == typeid(T).hash_code());
  return std::find(v.begin(), v.end(), *(T const*)(in.ptr_)) != v.end();
}

template<typename T>
bool operator>(In const& in, std::list<T> const& l) {
  assert(in.type_ == typeid(T).hash_code());
  return std::find(l.begin(), l.end(), *(T const*)(in.ptr_)) != l.end();
}

template<typename T>
bool operator>(In const& in, std::set<T> const& s) {
  assert(in.type_ == typeid(T).hash_code());
  return s.count(*(T const*)(in.ptr_)) == 1;
}

template<typename K, typename V>
bool operator>(In const& in, std::map<K, V> const& m) {
  assert(in.type_ == typeid(K).hash_code());
  return m.count(*(K const*)(in.ptr_)) == 1;
}

bool operator>(In const& in, std::string const& s) {
  assert(in.type_ == typeid(std::string).hash_code());
  return std::find(s.begin(), s.end(), *(char const*)(in.ptr_)) != s.end();
}

int main() {
  assert(1 < in > std::vector<int>{1});
  assert(! (2 < in > std::vector<int>{1}));

  assert(1 < in > std::list<int>{1});
  assert(! (2 < in > std::list<int>{1}));

  assert(1 < in > std::set<int>{1});
  assert(! (2 < in > std::set<int>{1}));

  assert((1 < in > std::map<int, int>{{1, 1}}));
  assert((! (2 < in > std::map<int, int>{{1, 1}})));

  assert(1 < in > std::string("1"));
  assert(! (2 < in > std::string("2")));
}
