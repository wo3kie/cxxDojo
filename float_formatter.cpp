/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/float_formatter
 */

#include "./assert.hpp"
#include "./float_formatter.hpp"

/*
 * main
 */

int main() {
  Assert(FloatFormatter(0, 1).toString() == "0");
  Assert(FloatFormatter(0, 2).toString() == " 0");
  Assert(FloatFormatter(0, 3).toString() == "  0");

  Assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
  Assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
  Assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
  Assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");

  Assert(FloatFormatter(-0.0000001234, 6).toString() == "-1e-07");
  Assert(FloatFormatter(-0.0000001234, 7).toString() == " -1e-07");
  Assert(FloatFormatter(-0.0000001234, 8).toString() == "-1.2e-07");
  Assert(FloatFormatter(-0.0000001234, 9).toString() == "-1.23e-07");
  Assert(FloatFormatter(-0.0000001234, 10).toString() == "-1.234e-07");

  Assert(FloatFormatter(0.12345678, 6).toString() == "0.1235");
  Assert(FloatFormatter(0.12345678, 7).toString() == "0.12346");
  Assert(FloatFormatter(0.12345678, 8).toString() == "0.123457");
  Assert(FloatFormatter(0.12345678, 9).toString() == "0.1234568");

  Assert(FloatFormatter(-0.12345678, 6).toString() == "-1e-01");
  Assert(FloatFormatter(-0.12345678, 7).toString() == " -1e-01");
  Assert(FloatFormatter(-0.12345678, 8).toString() == "-1.2e-01");
  Assert(FloatFormatter(-0.12345678, 9).toString() == "-1.23e-01");

  Assert(FloatFormatter(123456.789, 6).toString() == "123457");
  Assert(FloatFormatter(123456.789, 7).toString() == " 123457");
  Assert(FloatFormatter(123456.789, 8).toString() == "123456.8");
  Assert(FloatFormatter(123456.789, 9).toString() == "123456.79");

  Assert(FloatFormatter(-123456.789, 6).toString() == "-1e+05");
  Assert(FloatFormatter(-123456.789, 7).toString() == "-123457");
  Assert(FloatFormatter(-123456.789, 8).toString() == " -123457");
  Assert(FloatFormatter(-123456.789, 9).toString() == "-123456.8");

  Assert(FloatFormatter(9.989898, 6).toString() == "9.9899");
  Assert(FloatFormatter(9.989898, 7).toString() == "9.98990");
  Assert(FloatFormatter(9.989898, 8).toString() == "9.989898");
  Assert(FloatFormatter(9.989898, 9).toString() == "9.9898980");

  Assert(FloatFormatter(9.999999, 6).toString() == "    10");
  Assert(FloatFormatter(9.999999, 7).toString() == "     10");
  Assert(FloatFormatter(9.999999, 8).toString() == "9.999999");
  Assert(FloatFormatter(9.999999, 9).toString() == "9.9999990");
}
