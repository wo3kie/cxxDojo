/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_FLOAT_FORMATTER_HPP
#define CXX_DOJO_FLOAT_FORMATTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

inline double round(double value, int place = 1) {
  return std::round(std::pow(10, place) * value) / std::pow(10, place);
}

struct FloatFormatter {
  FloatFormatter(double value, int length = 6 /*-1e-01*/)
      : value_(value)
      , length_(length) {
  }

  std::ostream& toStream(std::ostream& out) const {
    return out << toString();
  }

  std::string toString() const {
    std::ostringstream oss;

    if(value_ < 0) {
      toStreamImpl(oss, value_, length_ - 1);
    } else {
      toStreamImpl(oss, value_, length_);
    }

    std::string const string = oss.str();

    return std::string(length_ - string.length(), ' ') + string;
  }

private:
  static std::ostream& toStreamImpl(std::ostream& out, double value, int length) {
    if(value == 0) {
      out << 0;
    } else {
      if(std::fabs(value) >= std::pow(10, length)) {
        out << std::scientific << std::setprecision(std::max(0, length - 6)) << value;
      } else if(std::fabs(value) < 1) {
        int const numberOfDigits = std::abs(std::log10(value));

        if(length - numberOfDigits > 2) {
          out << std::fixed << std::setprecision(length - 2) << round(value, length - 2);
        } else {
          out << std::scientific << std::setprecision(std::max(0, length - 6)) << value;
        }
      } else {
        if(value == int(value)) {
          out << std::fixed << int(value);
        } else {
          int const numberOfDigits = std::log10(std::fabs(value)) + 1;

          if(numberOfDigits == length) {
            out << std::fixed << std::setprecision(0) << round(value, 1);
          } else {
            double const rounded = round(value, length - numberOfDigits - 1);
            int const numberOfDigits2 = std::log10(std::fabs(rounded)) + 1;

            if(numberOfDigits == numberOfDigits2) {
              out << std::fixed << std::setprecision(length - numberOfDigits - 1)
                  << round(value, length - numberOfDigits - 1);
            } else {
              toStreamImpl(out, rounded, length);
            }
          }
        }
      }
    }

    return out;
  }

private:
  double value_;
  int length_;
};

inline std::ostream& operator<<(std::ostream& out, FloatFormatter const& floatFormatter) {
  return floatFormatter.toStream(out);
}

#endif
