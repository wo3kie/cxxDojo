#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <array>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./assert.hpp"
#include "./tuple.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v);

template<typename T, std::size_t Size>
std::ostream& operator<<(std::ostream& out, const std::array<T, Size>& a);

template<typename Iterator>
std::ostream& printList(std::ostream& out, Iterator begin, Iterator end);

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& v);

template<typename T1, typename T2>
std::ostream& printPair(std::ostream& out, const std::pair<T1, T2>& p);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p);

template<typename Iterator>
std::ostream& printMap(std::ostream& out, Iterator begin, Iterator end);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& m);

template<typename Iterator>
std::ostream& printSet(std::ostream& out, Iterator begin, Iterator end);

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& um);

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& us);

template<typename Iterator>
std::ostream& printImpl(std::ostream& out, const char beginning, Iterator begin, const char* const separator, const Iterator end, const char ending) {
  out << beginning;

  if(begin != end) {
    out << *begin;

    while(++begin != end) {
      out << separator << *begin;
    }
  }

  return out << ending;
}

template<typename Iterator>
std::ostream& printVector(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '[', begin, ", ", end, ']');
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  return printVector(out, v.begin(), v.end());
}

template<typename T, std::size_t Size>
std::ostream& operator<<(std::ostream& out, const std::array<T, Size>& a) {
  return printVector(out, a.begin(), a.end());
}

template<typename Iterator>
std::ostream& printList(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '(', begin, ", ", end, ')');
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& v) {
  return printList(out, v.begin(), v.end());
}

template<typename T1, typename T2>
std::ostream& printPair(std::ostream& out, const std::pair<T1, T2>& p) {
  return out << '{' << p.first << ", " << p.second << '}';
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p) {
  return printPair(out, p);
}

template<typename Iterator>
std::ostream& printMap(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '{', begin, ", ", end, '}');
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& m) {
  return printMap(out, m.begin(), m.end());
}

template<typename Iterator>
std::ostream& printSet(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '{', begin, ", ", end, '}');
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s) {
  return printSet(out, s.begin(), s.end());
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& um) {
  return printMap(out, um.begin(), um.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& us) {
  return printSet(out, us.begin(), us.end());
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& out, const std::tuple<Ts...>& tuple) {
  out << '(';
  stl::print(out, tuple, ", ");
  out << ')';
  return out;
}
