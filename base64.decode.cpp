/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 base64.decode.cpp -o base64.decode
 *
 * Usage:
 *      $ ./base64.decode SGVsbG8gV29ybGQ
 *      Hello World
 */

#include <iostream>
#include <string>

#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

std::string base64decode(std::string const& text) {
  using namespace boost::archive::iterators;

  typedef transform_width<binary_from_base64<std::string::const_iterator>, 8, 6> from_base64_text;

  std::string decoded;

  std::copy(from_base64_text(&*text.begin()), from_base64_text(&*text.end()), std::back_inserter(decoded));

  return decoded;
}

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cerr << "Usage: " << argv[0] << " text" << std::endl;
    return 1;
  }

  std::cout << base64decode(argv[1]) << std::endl;

  return 0;
}
