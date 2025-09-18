#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include "./union_cast.hpp"

template<typename Type, typename Class>
long long getMemberOffset(Type(Class::* member)) {
  return union_cast<long long>(member);
}
