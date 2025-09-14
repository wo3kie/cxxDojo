/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Named operators:
 *      https://github.com/klmr/named-operator
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 in.cpp -o in
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

/*
 * <in>
 */

struct In {
  const void* ptr_ = nullptr;
  std::size_t type_ = 0;
} in;

template<typename T>
In operator<(const T& t, In in) {
  assert(in.type_ = typeid(T).hash_code());
  in.ptr_ = &t;
  return in;
}

template<typename T>
bool operator>(const In& in, const std::vector<T>& v) {
  assert(in.type_ == typeid(T).hash_code());
  return std::find(v.begin(), v.end(), *(const T*)(in.ptr_)) != v.end();
}

template<typename T>
bool operator>(const In& in, const std::list<T>& l) {
  assert(in.type_ == typeid(T).hash_code());
  return std::find(l.begin(), l.end(), *(const T*)(in.ptr_)) != l.end();
}

template<typename T>
bool operator>(const In& in, const std::set<T>& s) {
  assert(in.type_ == typeid(T).hash_code());
  return s.count(*(const T*)(in.ptr_)) == 1;
}

template<typename K, typename V>
bool operator>(const In& in, const std::map<K, V>& m) {
  assert(in.type_ == typeid(K).hash_code());
  return m.count(*(const K*)(in.ptr_)) == 1;
}

bool operator>(const In& in, const std::string& s) {
  assert(in.type_ == typeid(std::string).hash_code());
  return std::find(s.begin(), s.end(), *(const char*)(in.ptr_)) != s.end();
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
