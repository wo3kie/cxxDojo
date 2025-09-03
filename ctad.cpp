/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 ctad.cpp -o ctad
 * 
 * Reference:
 *      CTAD Class template argument deduction
 *      https://en.cppreference.com/w/cpp/language/class_template_argument_deduction.html
 */

#include <utility>
#include <vector>

using std::declval;

/*
 * std::vector
 */

void test1() {
  auto v1 = std::vector<int>{1, 2, 3};
  auto v2 = std::vector{1, 2, 3};
  static_assert(std::is_same_v<decltype(v2), std::vector<int>>);
}

/*
 * User class
 */

template<typename T>
struct S2 {
  S2(T t) {
  }
};

void test2() {
  auto s1 = S2<int>{1};
  auto s2 = S2{1};
  static_assert(std::is_same_v<decltype(s2), S2<int>>);
};

/*
 * User deduction guideline
 */

template<typename T>
struct S3 {
  S3(T t) {
  }
};

template<typename T>
S3(T t) -> S3<T>;

void test3() {
  auto s1 = S3<int>{1};
  auto s2 = S3{1};
  static_assert(std::is_same_v<decltype(s2), S3<int>>);
}

/*
 * User deduction guideline (2)
 */

template<typename T>
struct S4 {
  S4(T t) {
  }

  template<typename I>
  S4(I begin, I end) {
  }
};

template<typename T>
S4(T t) -> S4<T>;

template<typename I>
S4(I, I) -> S4<typename std::iterator_traits<I>::value_type>;

void test4() {
  int array[] = {1, 2, 3, 4};

  auto s1 = S4<int>{1};
  auto s2 = S4{1};
  static_assert(std::is_same_v<decltype(s2), S4<int>>);

  auto s3 = S4{&array[0], &array[sizeof(array) / sizeof(array[0])]};
  static_assert(std::is_same_v<decltype(s3), S4<int>>);
}

/*
 * User deduction guideline (3)
 */

template<typename S>
struct S5 {
  template<typename I>
  S5(I begin, I end) {
  }
};

template<typename I>
S5(I, I) -> S5<std::remove_reference_t<decltype(*declval<I>())>>;

void test5() {
  int array[] = {1, 2, 3, 4};

  auto s1 = S5<int>{&array[0], &array[sizeof(array) / sizeof(array[0])]};
  auto s2 = S5{&array[0], &array[sizeof(array) / sizeof(array[0])]};
  static_assert(std::is_same_v<decltype(s2), S5<int>>);
}

/*
  * main
  */

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
