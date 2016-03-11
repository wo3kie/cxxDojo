/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ main.cpp -o main --std=c++11 -g -I/usr/local/include /usr/local/lib/liblua.a -ldl
 *
 * Usage:
 *      $ ./main
 */

#include <cassert>
#include <iostream>

#include <lua.hpp>

int main(int argc, char* argv[]){
    lua_State * const L = luaL_newstate();

    if (luaL_loadfile(L, "main.lua")) {
        std::cerr << "Error reading lua file 'main.lua': " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
        return 1;
    }

    if(lua_pcall(L, 0, LUA_MULTRET, 0)){
        std::cerr << "Error during execution: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
        return 2;
    }

    lua_getglobal(L, "f");
    lua_pushnumber(L, 2.0);
    lua_pushnumber(L, 5.0);
    
    if(lua_pcall(L, 2, 1, 0) != 0){
        std::cerr << "Error running function 'f': " << lua_tostring(L, -1) << std::endl;
        return 3;
    }

    if( ! lua_isnumber(L, -1)){
        std::cerr << "Function 'f' must return a number" << std::endl;
        return 4;
    }

    assert(10 == lua_tonumber(L, -1));

    lua_pop(L, 1);

    lua_close(L);

    return 0;
}

