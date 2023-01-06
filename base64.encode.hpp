/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_BASE64_ENCODE_HPP
#define CXX_DOJO_BASE64_ENCODE_HPP

#include <iostream>
#include <string>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>

std::string base64encode(std::string const& text) {
  using namespace boost::archive::iterators;

  typedef base64_from_binary<transform_width<const char*, 6, 8>> base64_text;

  std::string encoded;

  std::copy(base64_text(&*text.begin()), base64_text(&*text.end()), std::back_inserter(encoded));

  return encoded;
}

#endif
