#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cxxabi.h>
#include <cstdlib>
#include <string>

inline std::string demangle(const char* mangled_name) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);

    if (status != 0) {
        return mangled_name;
    }

    std::string result(demangled);
    std::free(demangled);

    return result;
}
