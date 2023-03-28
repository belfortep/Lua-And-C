#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

//cc lua_parser.c -o lua_parser -llua -L../lua -I../lua -lm -ldl 

const void *execute_lua_code(char *lua_code)
{
        lua_State *L = luaL_newstate();
        luaL_openlibs(L);
        //luaL_dostring(L, lua_code);
        luaL_dofile(L, "script.lua");
        return lua_topointer(L, -1);;
}

int main()
{
        const char *sarasa = execute_lua_code("return 'hello'");
        //printf("sarasa es: %s", sarasa);


        return 0;
}