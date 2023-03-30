#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

//gcc lua_parser.c -o lua_parser -llua -L../lua -I../lua -lm -ldl 


void setfield(lua_State *L,const char *index, int value, char *table_name)
{
        lua_newtable(L);
        lua_pushstring(L, index);
        lua_pushnumber(L, value);
        lua_settable(L, -3);
        lua_setglobal(L, table_name);
}


// idea interesante, yo te ejecuto el codigo de lua
// y tambien puedo hacer que me pases un json_t y convertirtelo a una table de lua
// ta bien
lua_State *execute_lua_code(char *lua_code)
{
        lua_State *L = luaL_newstate();
        luaL_openlibs(L);
        luaL_dofile(L ,lua_code);

        return L;
}

int main()
{
        char *table_name = "nombre_tabla";
        lua_State *L = execute_lua_code("script.lua");
        setfield(L, "key", 25, table_name);
        lua_getglobal(L, table_name);
        lua_pushstring(L, "key");
        lua_gettable(L, -2);
        int result = (int)lua_tonumber(L, -1);
        lua_pop(L, 1);

        printf("result := %i \n", result);

        return 0;
}