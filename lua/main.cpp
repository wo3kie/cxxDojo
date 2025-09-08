/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ main.cpp -o main --std=c++20 -g -I/usr/local/include /usr/local/lib/liblua.a -ldl
 *
 * Usage:
 *      $ ./main
 */

#include <cassert>
#include <iostream>

#include <stdarg.h>
#include <string.h>

#include <lua.hpp>

/*
 * pushArg
 */

template<typename T>
void pushArg(lua_State* L, T arg) /*
 * linker error
 */
    ;

void pushArg(lua_State* L, int arg) {
  lua_pushnumber(L, arg);
}

void pushArg(lua_State* L, double arg) {
  lua_pushnumber(L, arg);
}

void pushArg(lua_State* L, char const* arg) {
  lua_pushstring(L, arg);
}

/*
 * pushArgs
 */

void pushArgs(lua_State* L) {
}

template<typename Arg, typename... Args>
void pushArgs(lua_State* L, Arg arg, Args... args) {
  pushArg(L, arg);
  pushArgs(L, args...);
}

/*
 * getResult
 */

template<typename T>
T getResult(lua_State* L) /*
 * linker error
 */
    ;

template<>
void getResult<void>(lua_State* L) {
}

template<>
int getResult<int>(lua_State* L) {
  if(! lua_isnumber(L, -1)) {
    throw std::runtime_error("Function must return a number");
  }

  int const result = lua_tonumber(L, -1);
  lua_pop(L, 1);
  return result;
}

template<>
double getResult<double>(lua_State* L) {
  if(! lua_isnumber(L, -1)) {
    throw std::runtime_error("Function must return a number");
  }

  double const result = lua_tonumber(L, -1);
  lua_pop(L, 1);
  return result;
}

template<>
char const* getResult<char const*>(lua_State* L) {
  if(! lua_isstring(L, -1)) {
    throw std::runtime_error("Function must return a string");
  }

  char const* result = strdup(lua_tostring(L, -1));
  lua_pop(L, 1);
  return result;
}

/*
 * luaCall
 */

template<typename Return, typename... Args>
Return luaCall(lua_State* L, char const* const functionName, Args... args) {
  lua_getglobal(L, functionName);

  pushArgs(L, args...);

  if(lua_pcall(L, sizeof...(args), 1, 0) != 0) {
    throw std::runtime_error(lua_tostring(L, -1));
  }

  return getResult<Return>(L);
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  lua_State* const L = luaL_newstate();

  if(luaL_loadfile(L, "main.lua")) {
    std::cerr << "Error reading lua file 'main.lua': " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1);
    return 1;
  }

  luaL_openlibs(L);

  if(lua_pcall(L, 0, LUA_MULTRET, 0)) {
    std::cerr << "Error during execution: " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1);
    return 2;
  }

  luaCall<void>(L, "hello");
  assert(1 == luaCall<int>(L, "get1"));
  assert(3.14 == luaCall<double>(L, "getPi"));
  assert(24 == luaCall<int>(L, "factorial", 4));
  assert(25 == luaCall<int>(L, "pow", 5, 2));

  lua_close(L);

  return 0;
}
