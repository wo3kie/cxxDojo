/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 rSquared.cpp -o rSquared
 *
 * Usage:
 *      $ ./rSquared
 */

#include <cassert>
#include <initializer_list>

#include "./feq.hpp"

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Coefficient_of_determination
 *
 *   r_squared = 1 - ss_res / ss_tot
 *   ss_res = SUM(actual[i] - predicted[i])^2
 *   ss_tot = SUM(actual[i] - mean(actual))^2
 *
 *   In linear leat squares regression with an estimated intercept term,
 *   r_squared equals the square of the Pearson correlation coefficent
 *   between te observed and modeled data values of the dependent variable.
 */

class RSquared {
public:
  RSquared() {
    reset();
  }

  void add(double actual, double predicted) {
    count_ += 1;
    actual_sum_ += actual;
    actual2_sum_ += actual * actual;
    ss_res_ += (actual - predicted) * (actual - predicted);
  }

  template<typename Iterator1, typename Iterator2>
  void add(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2) {
    for(/* empty */; begin1 != end1; ++begin1, ++begin2) {
      add(*begin1, *begin2);
    }
  }

  void add(std::initializer_list<double> const& list1, std::initializer_list<double> const& list2) {
    add(list1.begin(), list1.end(), list2.begin(), list2.end());
  }

  double getScore() const {
    double const actual_avg = actual_sum_ / count_;
    double const ss_tot = actual2_sum_ - 2 * actual_avg * actual_sum_ + count_ * actual_avg * actual_avg;
    double const rSquared = 1.0 - ss_res_ / ss_tot;

    return rSquared;
  }

  void reset() {
    ss_res_ = 0;
    count_ = 0;
    actual_sum_ = 0;
    actual2_sum_ = 0;
  }

private:
  double ss_res_;
  unsigned count_;
  double actual_sum_;
  double actual2_sum_;
};

#include <iostream>

int main() {
  {
    RSquared rs;

    auto const list1 = {1, 2, 3, 4, 5};
    auto const list2 = {1, 2, 3, 4, 5};

    rs.add(list1.begin(), list1.end(), list2.begin(), list2.end());

    double const actual = rs.getScore();
    double const expected = 1;

    assert(feq(actual, expected));
  }
  {
    RSquared rs;

    rs.add({1, 2, 3, 4, 5}, {1, 3, 2, 4, 5});

    double const actual = rs.getScore();
    double const expected = 0.80;

    assert(feq(actual, expected));
  }
}
