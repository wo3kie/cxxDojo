/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 bond.cpp -o bond -lboost_date_time
 *
 * Usage:
 *      $ ./bond 2015/12/31 100 0.08 0.08 2014/12/31
 *        PV( F ): 92.5926
 *        PV( Coupon ): 7.40741
 *      P: 100
 */

/*
 *                                                                      Maturity Date
 *                                                                       |
 *                     /-- 1 year -----------    -- 1 year------------\  |
 *                    /                      \  /                      \ |
 *                   v                        \v                        \v
 * ... - 2 - 4 - 6 - 8 - 10 - 12 - 2 - 4 - 6 - 8 - 10 - 12 - 2 - 4 - 6 - 8 - 10 - ...
 *       ^           ^                         ^                         ^
 *       |           |                         |                         |
 *       |          Coupon                    Coupon                    Face Value
 *      Price Day                                                       Coupon
 */

#include <cmath>
#include <iostream>

#include <boost/date_time/gregorian/gregorian.hpp>

namespace date = boost::gregorian;
namespace date_time = boost::date_time;

double bondPrice(date::date maturityDate, double faceValue, double yield, double intrestRate, date::date priceDay) {
  using std::pow;

  int days = (maturityDate - priceDay).days();

  if(days < 0) {
    return 0;
  }

  double result = 0;

  {
    /*
         * Face value
         */

    result = faceValue / pow((1.0 + intrestRate), 1.0 * days / 365);

    std::cout << "  PV( F ): " << result << std::endl;
  }

  while(days > 0) {
    /*
         * Coupons
         */

    double coupon = (faceValue * yield) / pow((1.0 + intrestRate), 1.0 * days / 365);

    std::cout << "  PV( Coupon ): " << coupon << std::endl;

    result += coupon;

    maturityDate = maturityDate - date::years(1);

    days = (maturityDate - priceDay).days();
  }

  std::cout << "P: " << result << std::endl;

  return result;
}

int main(int argc, char* argv[]) {
  if(argc != 6) {
    std::cerr << "Usage: " << argv[0] << " maturityDate faceValue yield intrestRate priceDate" << std::endl;
    std::cerr << "       " << argv[0] << " 2015/12/31 100 0.08 0.08 2014/12/31" << std::endl;

    return 1;
  }

  bondPrice(
      date::from_string(argv[1]),
      std::stoi(argv[2]),
      std::stof(argv[3]),
      std::stof(argv[4]),
      date::from_string(argv[5]));

  return 0;
}
