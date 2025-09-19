#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <iostream>

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

/*
 * printDirectoryContent
 */

inline void printDirectoryContent(const fs::path& path) {

  fs::directory_iterator current(path);
  const fs::directory_iterator end;

  for(/*empty*/; current != end; ++current) {
    fs::directory_entry entry = *current;

    if(fs::is_regular_file(entry.path())) {
      std::cout << "F " << entry << std::endl;
    } else if(fs::is_directory(entry.path())) {
      std::cout << "D " << entry << std::endl;
    } else if(fs::is_symlink(entry.path())) {
      std::cout << "L " << entry << std::endl;
    } else {
      std::cout << "? " << entry << std::endl;
    }
  }
}
