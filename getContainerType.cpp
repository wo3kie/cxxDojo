/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 getContainerType.cpp -o getContainerType
 *
 * Usage:
 *      $ ./getContainerType
 */

#include <iterator>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

template<typename T>
std::vector<T> getContainerTypeImpl(typename std::vector<T>::iterator) {
  return {};
}

template<typename T>
std::vector<T> getContainerTypeImpl(typename std::vector<T>::const_iterator) {
  return {};
}

template<typename T>
std::list<T> getContainerTypeImpl(typename std::list<T>::iterator) {
  return {};
}

template<typename T>
std::list<T> getContainerTypeImpl(typename std::list<T>::const_iterator) {
  return {};
}

template<typename T>
std::set<T> getContainerTypeImpl(typename std::set<T>::iterator) {
  return {};
}

template<typename Iterator>
auto getContainerType(Iterator i) {
  return getContainerTypeImpl<typename std::iterator_traits<Iterator>::value_type>(i);
}

/*
 * getContainerTypeTest
 */

void getContainerTypeTest() {
  std::vector<int>::iterator vectorIterator;
  decltype(getContainerType(vectorIterator)) vector = std::vector<int>();

  std::vector<int>::const_iterator vectorConstIterator;
  decltype(getContainerType(vectorConstIterator)) vector2 = std::vector<int>();

  std::list<int>::iterator listIterator;
  decltype(getContainerType(listIterator)) list = std::list<int>();

  std::list<int>::iterator listConstIterator;
  decltype(getContainerType(listConstIterator)) list2 = std::list<int>();

  std::set<int>::iterator setIterator;
  decltype(getContainerType(setIterator)) set = std::set<int>();

  std::set<int>::const_iterator setConstIterator;
  decltype(getContainerType(setConstIterator)) set2 = std::set<int>();

  std::map<int, int>::iterator mapIterator;
  decltype(getContainerType(mapIterator)) set3 = std::set<std::pair<const int, int>>();
}

/*
 * main
 */

int main() {
  getContainerTypeTest();
}
