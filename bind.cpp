/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 bind.cpp -o bind
 */

#include <boost/bind.hpp>
#include <boost/bind/apply.hpp>
#include <boost/bind/protect.hpp>

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * boost::bind apply
 */

int i1(int i) {
  return i;
}
int i2(int i) {
  return 2 * i;
}
int i3(int i) {
  return 3 * i;
}

void apply() {
  std::vector<int (*)(int)> fs{{&i1, &i2, &i3}};

  /*
     * This does not work
     *
     * std::for_each(
     *     fs.begin(),
     *     fs.end(),
     *     boost::bind< int >( _1, 5 ) );
     *
     * /usr/local/include/boost/bind/bind.hpp:243:16: error: type 'boost::arg<1>' does not provide a call operator
     *    return unwrapper<F>::unwrap(f, 0)(a[base_type::a1_]);
     *           ^~~~~~~~~~~~~~~~~~~~~~~~~~
     */

  std::for_each(fs.begin(), fs.end(), boost::bind(boost::apply<int>(), _1, 5));
}

/*
 * boost::bind protect
 */

struct Fi: public std::unary_function<int, int> {
  int operator()(int i) const {
    return i;
  }
};

struct Ff {
  template<typename F>
  int operator()(F f) const {
    return f(5);
  }

  typedef int result_type;
};

void protect() {
  /*
     * This does not work
     *
     * boost::bind( Ff(), boost::bind( Fi(), _1 ) )( 5 );
     *
     * bind.cpp:55:16: error: called object type 'int' is not a function or function pointer
     *         return f( 5 );
     *                ^
     */

  boost::bind(Ff(), boost::protect(boost::bind(Fi(), _1)));
}

/*
 * main
 */

int main() {
  apply();
  protect();
}
