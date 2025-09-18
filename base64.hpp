#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <iostream>
#include <string>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

inline std::string base64encode(const std::string& text) {
  using namespace boost::archive::iterators;

  typedef base64_from_binary<transform_width<const char*, 6, 8>> base64_text;

  std::string encoded;

  std::copy(base64_text(&*text.begin()), base64_text(&*text.end()), std::back_inserter(encoded));

  return encoded;
}

inline std::string base64decode(const std::string& text) {
  using namespace boost::archive::iterators;

  typedef transform_width<binary_from_base64<std::string::const_iterator>, 8, 6> from_base64_text;

  std::string decoded;

  std::copy(from_base64_text(&*text.begin()), from_base64_text(&*text.end()), std::back_inserter(decoded));

  return decoded;
}
