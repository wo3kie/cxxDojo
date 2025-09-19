#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <stdio.h>

/*
 * exec
 */

inline bool exec(const char* const command, const std::function<void(const char*)> onRead) {
  FILE* const pipe = popen(command, "r");

  if(! pipe) {
    return false;
  }

  char buffer[4 * 1024];

  while(! feof(pipe)) {
    if(fgets(buffer, sizeof(buffer), pipe)) {
      onRead(buffer);
    }
  }

  pclose(pipe);

  return true;
}
