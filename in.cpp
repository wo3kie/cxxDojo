/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Named operators:
 *      https://github.com/klmr/named-operator
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/in
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

/*
 * <in>
 */

struct In {
  const void* _ptr = nullptr;
  std::size_t _type = 0;
} in;

template<typename T>
In operator<(const T& t, In in) {
  assert(in._type = typeid(T).hash_code());
  in._ptr = &t;
  return in;
}

template<typename T>
bool operator>(const In& in, const std::vector<T>& v) {
  assert(in._type == typeid(T).hash_code());
  return std::find(v.begin(), v.end(), *(const T*)(in._ptr)) != v.end();
}

template<typename T>
bool operator>(const In& in, const std::list<T>& l) {
  assert(in._type == typeid(T).hash_code());
  return std::find(l.begin(), l.end(), *(const T*)(in._ptr)) != l.end();
}

template<typename T>
bool operator>(const In& in, const std::set<T>& s) {
  assert(in._type == typeid(T).hash_code());
  return s.count(*(const T*)(in._ptr)) == 1;
}

template<typename K, typename V>
bool operator>(const In& in, const std::map<K, V>& m) {
  assert(in._type == typeid(K).hash_code());
  return m.count(*(const K*)(in._ptr)) == 1;
}

bool operator>(const In& in, const std::string& s) {
  assert(in._type == typeid(std::string).hash_code());
  return std::find(s.begin(), s.end(), *(const char*)(in._ptr)) != s.end();
}

/*
 * main
 */

int main() {
  // clang-format off
  assert(1 <in> std::vector<int>{1});
  assert(! (2 <in> std::vector<int>{1}));
  
  assert(1 <in> std::list<int>{1});
  assert(! (2 <in> std::list<int>{1}));
  
  assert(1 <in> std::set<int>{1});
  assert(! (2 <in> std::set<int>{1}));
  
  assert((1 <in> std::map<int, int>{{1, 1}}));
  assert((! (2 <in> std::map<int, int>{{1, 1}})));
  
  assert(1 <in> std::string("1"));
  assert(! (2 <in> std::string("2")));
  // clang-format on
}
