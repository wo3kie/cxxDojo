/*
 * Website:
 *      https://github.com/wo3kie/dojo
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

double round(double value, int place = 1){
    return std::round(std::pow(10, place) * value) / std::pow(10, place);
}

struct FloatFormatter
{
    FloatFormatter(double value, int length = 5)
        : value_(value)
        , length_(length)
    {
    }

    std::ostream & toStream(std::ostream & out) const {
        std::string s = toString();
        return out << std::string(length_ - s.length(), ' ') << std::move(s);
    }

    std::string toString() const {
        std::ostringstream oss;
        toStreamImpl(oss);
        return oss.str();
    }

private:

    std::ostream & toStreamImpl(std::ostream & out) const {
        if(value_ == 0){
            out << 0;
        }
        else if(value_ > 0 ){
            if(value_ >= std::pow(10, length_)){
                out
                    << std::scientific
                    << std::setprecision(std::max(0, length_ - 5))
                    << value_;
            }
            else if(value_ < 1){
                int const numberOfDigits = std::abs(std::log10(value_));

                if(length_ - numberOfDigits > 2){
                    out
                        << std::fixed
                        << std::setprecision(length_ - 2)
                        << round(value_, length_ - 2);
                }
                else{
                    out
                        << std::scientific
                        << std::setprecision(std::max(0, length_ - 6))
                        << value_;
                }
            }
            else
            {
                int const numerator = value_;

                if(numerator == value_){
                    out
                        << std::fixed
                        << int(value_);
                }
                else{
                    int const numberOfDigits = std::log10(numerator) + 1;

                    if(length_ - numberOfDigits > 1){
                        out
                            << std::setprecision(length_ - numberOfDigits - 1)
                            << round(value_, length_ - numberOfDigits - 1);
                    }
                    else{
                        out
                            << std::fixed
                            << int(round(value_, 0));
                    }
                }
            }
        }
        else{
        }

        return out;
    }

private:
    double value_;
    int length_;
};

inline
std::ostream & operator<<(std::ostream & out, FloatFormatter const & floatFormatter){
    return floatFormatter.toStream(out);
}

#endif
