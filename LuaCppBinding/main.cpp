#include <lua.hpp>
#include <cassert>
#include <cstdlib>

/*
	to-do:
		konsola z interpreterem LUA w silniku
*/

class Foo
{
	public:
		Foo() : m_Bar(0) {}

		void setBar(int bar)
		{
			m_Bar = bar;
		}

		int getBar(void)
		{
			return m_Bar;
		}

		int m_Bar;
};

extern "C"
{
	static int l_set_bar(lua_State *L)
	{
		assert(lua_gettop(L) == 2);
		Foo **ud = static_cast<Foo **>(luaL_checkudata(L, 1, "FooMT"));
		int v = luaL_checkint(L, 2);
		(*ud)->setBar(v);

		return 0;
	}

	static int l_get_bar(lua_State *L)
	{
		assert(lua_gettop(L) == 1);
		Foo **ud = static_cast<Foo **>(luaL_checkudata(L, 1, "FooMT"));
		lua_pushnumber(L, (*ud)->getBar());

		return 1;
	}
}

// http://rubenlaguna.com/wp/2012/12/09/accessing-cpp-objects-from-lua/

int main()
{
	Foo foo;

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	luaL_newmetatable(L, "FooMT");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, l_get_bar);
	lua_setfield(L, -2, "get_bar");
	lua_pushcfunction(L, l_set_bar);
	lua_setfield(L, -2, "set_bar");

	Foo **ud = static_cast<Foo**>(lua_newuserdata(L, sizeof(Foo*)));
	*(ud) = &foo;

	luaL_setmetatable(L, "FooMT");
	lua_setglobal(L, "foo");
	
	lua_settop(L, 0);
	
	if(luaL_dofile(L, "./foo_bar_example.lua"))
	{
		fprintf(stderr, "error: %s\n", lua_tostring(L, -1));
		lua_pop(L, 1);

		system("PAUSE");
		return 1;
	}
	assert(lua_gettop(L) == 0);

	lua_close(L);

	printf("From Cpp: %d\n", foo.getBar());

	system("PAUSE");

	return 0;
}