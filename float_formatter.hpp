#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

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
      : _value(value)
      , _length(length) {
  }

  std::ostream& toStream(std::ostream& out) const {
    return out << toString();
  }

  std::string toString() const {
    std::ostringstream oss;

    if(_value < 0) {
      toStreamImpl(oss, _value, _length - 1);
    } else {
      toStreamImpl(oss, _value, _length);
    }

    const std::string string = oss.str();

    return std::string(_length - string.length(), ' ') + string;
  }

private:
  static std::ostream& toStreamImpl(std::ostream& out, double value, int length) {
    if(value == 0) {
      out << 0;
    } else {
      if(std::fabs(value) >= std::pow(10, length)) {
        out << std::scientific << std::setprecision(std::max(0, length - 6)) << value;
      } else if(std::fabs(value) < 1) {
        const int numberOfDigits = std::abs(std::log10(value));

        if(length - numberOfDigits > 2) {
          out << std::fixed << std::setprecision(length - 2) << round(value, length - 2);
        } else {
          out << std::scientific << std::setprecision(std::max(0, length - 6)) << value;
        }
      } else {
        if(value == int(value)) {
          out << std::fixed << int(value);
        } else {
          const int numberOfDigits = std::log10(std::fabs(value)) + 1;

          if(numberOfDigits == length) {
            out << std::fixed << std::setprecision(0) << round(value, 1);
          } else {
            const double rounded = round(value, length - numberOfDigits - 1);
            const int numberOfDigits2 = std::log10(std::fabs(rounded)) + 1;

            if(numberOfDigits == numberOfDigits2) {
              out << std::fixed << std::setprecision(length - numberOfDigits - 1) << round(value, length - numberOfDigits - 1);
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
  double _value;
  int _length;
};

inline std::ostream& operator<<(std::ostream& out, const FloatFormatter& floatFormatter) {
  return floatFormatter.toStream(out);
}
