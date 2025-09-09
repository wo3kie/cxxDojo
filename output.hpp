/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_OUTPUT_HPP
#define CXX_DOJO_OUTPUT_HPP

#include <array>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> const& v);

template<typename T, std::size_t Size>
std::ostream& operator<<(std::ostream& out, std::array<T, Size> const& a);

template<typename Iterator>
std::ostream& printList(std::ostream& out, Iterator begin, Iterator end);

template<typename T>
std::ostream& operator<<(std::ostream& out, std::list<T> const& v);

template<typename T1, typename T2>
std::ostream& printPair(std::ostream& out, std::pair<T1, T2> const& p);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> const& p);

template<typename Iterator>
std::ostream& printMap(std::ostream& out, Iterator begin, Iterator end);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::map<T1, T2> const& m);

template<typename Iterator>
std::ostream& printSet(std::ostream& out, Iterator begin, Iterator end);

template<typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> const& s);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::unordered_map<T1, T2> const& u);

template<typename T>
std::ostream& operator<<(std::ostream& out, std::unordered_set<T> const& s);

template<typename Iterator>
std::ostream& printImpl(
    std::ostream& out,
    char const beginning,
    Iterator begin,
    char const* const separator,
    Iterator const end,
    char const ending) {
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
std::ostream& operator<<(std::ostream& out, std::vector<T> const& v) {
  return printVector(out, v.begin(), v.end());
}

template<typename T, std::size_t Size>
std::ostream& operator<<(std::ostream& out, std::array<T, Size> const& a) {
  return printVector(out, a.begin(), a.end());
}

template<typename Iterator>
std::ostream& printList(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '(', begin, ", ", end, ')');
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::list<T> const& v) {
  return printList(out, v.begin(), v.end());
}

template<typename T1, typename T2>
std::ostream& printPair(std::ostream& out, std::pair<T1, T2> const& p) {
  return out << '{' << p.first << ", " << p.second << '}';
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> const& p) {
  return printPair(out, p);
}

template<typename Iterator>
std::ostream& printMap(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '{', begin, ", ", end, '}');
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::map<T1, T2> const& m) {
  return printMap(out, m.begin(), m.end());
}

template<typename Iterator>
std::ostream& printSet(std::ostream& out, Iterator begin, Iterator end) {
  return printImpl(out, '{', begin, ", ", end, '}');
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> const& s) {
  return printSet(out, s.begin(), s.end());
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::unordered_map<T1, T2> const& u) {
  return printMap(out, u.begin(), u.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::unordered_set<T> const& s) {
  return printSet(out, s.begin(), s.end());
}

template<typename T1>
void print(T1 const& t1, char end = '\n') {
  std::cout << t1 << end;
}

template<typename T1, typename T2>
void print(T1 const& t1, T2 const& t2, char end = '\n') {
  std::cout << t1 << ' ' << t2 << end;
}

template<typename T1, typename T2, typename T3>
void print(T1 const& t1, T2 const& t2, T3 const& t3, char end = '\n') {
  std::cout << t1 << ' ' << t2 << ' ' << t3 << end;
}

template<typename T1, typename T2, typename T3, typename T4>
void print(T1 const& t1, T2 const& t2, T3 const& t3, T4 const& t4, char end = '\n') {
  std::cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << end;
}

template<typename T1, typename T2, typename T3, typename T4, typename T5>
void print(T1 const& t1, T2 const& t2, T3 const& t3, T4 const& t4, T5 const& t5, char end = '\n') {
  std::cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << ' ' << t5 << end;
}

#endif
