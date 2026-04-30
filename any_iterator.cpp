/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <deque>
#include <list>
#include <iostream>
#include <vector>

#include "./any_iterator.hpp"
#include "./assert.hpp"

void test_1() {
  std::vector<int> v{1, 2, 3};

  AnyIterator<int, 8> begin(v.begin());
  AnyIterator<int, 8> end(v.end());

  assert(*begin == 1);
  ++begin;
  assert(*begin == 2);
  ++begin;
  assert(*begin == 3);
  ++begin;
  assert(begin == end);
}

void test_CTAD() {
  std::vector<int> v{1, 2, 3};

  AnyIterator begin(v.begin());
  AnyIterator end(v.end());

  assert(*begin == 1);
  ++begin;
  assert(*begin == 2);
  ++begin;
  assert(*begin == 3);
  ++begin;
  assert(begin == end);
}

void test_copy() {
  std::vector<int> v{1, 2, 3};

  AnyIterator begin(v.begin());
  AnyIterator end(v.end());

  AnyIterator begin_copy = begin;
  AnyIterator end_copy = end;

  assert(*begin_copy == 1);
  ++begin_copy;
  assert(*begin_copy == 2);
  ++begin_copy;
  assert(*begin_copy == 3);
  ++begin_copy;
  assert(begin_copy == end_copy);
}

void test_move() {
  std::vector<int> v{1, 2, 3};

  AnyIterator begin(v.begin());
  AnyIterator end(v.end());

  AnyIterator begin_copy = std::move(begin);
  AnyIterator end_copy = std::move(end);

  assert(*begin_copy == 1);
  ++begin_copy;
  assert(*begin_copy == 2);
  ++begin_copy;
  assert(*begin_copy == 3);
  ++begin_copy;
  assert(begin_copy == end_copy);
}

void test_vector_list_deque() {
  std::vector<int> v{1, 2, 3};
  std::list<int> l{4, 5, 6};
  std::deque<int> d{7, 8, 9};

  AnyIterator begin_v(v.begin());
  AnyIterator end_v(v.end());

  AnyIterator begin_l(l.begin());
  AnyIterator end_l(l.end());

  AnyIterator begin_d(d.begin());
  AnyIterator end_d(d.end());

  assert(*begin_v == 1);
  ++begin_v;
  assert(*begin_v == 2);
  ++begin_v;
  assert(*begin_v == 3);
  ++begin_v;
  assert(begin_v == end_v);

  assert(*begin_l == 4);
  ++begin_l;
  assert(*begin_l == 5);
  ++begin_l;
  assert(*begin_l == 6);
  ++begin_l;
  assert(begin_l == end_l);

  assert(*begin_d == 7);
  ++begin_d;
  assert(*begin_d == 8);
  ++begin_d;
  assert(*begin_d == 9);
  ++begin_d;
  assert(begin_d == end_d);
}

int main() {
  test_1();
  test_CTAD();
  test_copy();
  test_move();
  test_vector_list_deque();
}