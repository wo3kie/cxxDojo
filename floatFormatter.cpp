/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 floatFormat.cpp -o floatFormat
 *
 * Usage:
 *      $ ./floatFormat
 */

#include <cassert>

#include "./floatFormatter.hpp"

int main(){
    assert(FloatFormatter(0, 1).toString() == "0");
    assert(FloatFormatter(0, 2).toString() == " 0");
    assert(FloatFormatter(0, 3).toString() == "  0");

    assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
    assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
    assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
    assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");

    assert(FloatFormatter(-0.0000001234, 6).toString() == "-1e-07");
    assert(FloatFormatter(-0.0000001234, 7).toString() == " -1e-07");
    assert(FloatFormatter(-0.0000001234, 8).toString() == "-1.2e-07");
    assert(FloatFormatter(-0.0000001234, 9).toString() == "-1.23e-07");
    assert(FloatFormatter(-0.0000001234, 10).toString() == "-1.234e-07");

    assert(FloatFormatter(0.12345678, 6).toString() == "0.1235");
    assert(FloatFormatter(0.12345678, 7).toString() == "0.12346");
    assert(FloatFormatter(0.12345678, 8).toString() == "0.123457");
    assert(FloatFormatter(0.12345678, 9).toString() == "0.1234568");

    assert(FloatFormatter(-0.12345678, 6).toString() == "-1e-01");
    assert(FloatFormatter(-0.12345678, 7).toString() == " -1e-01");
    assert(FloatFormatter(-0.12345678, 8).toString() == "-1.2e-01");
    assert(FloatFormatter(-0.12345678, 9).toString() == "-1.23e-01");

    assert(FloatFormatter(123456.789, 6).toString() == "123457");
    assert(FloatFormatter(123456.789, 7).toString() == " 123457");
    assert(FloatFormatter(123456.789, 8).toString() == "123456.8");
    assert(FloatFormatter(123456.789, 9).toString() == "123456.79");

    assert(FloatFormatter(-123456.789, 6).toString() == "-1e+05");
    assert(FloatFormatter(-123456.789, 7).toString() == "-123457");
    assert(FloatFormatter(-123456.789, 8).toString() == " -123457");
    assert(FloatFormatter(-123456.789, 9).toString() == "-123456.8");
}
