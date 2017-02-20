#include <stdio.h>
#include "mathlib.h"

static int math_average(lua_State *L) {
	int n = lua_gettop(L);
	double sum = 0;
	int i;

	for (i = 1; i <= n; i++) {
		sum += lua_tonumber(L, i);
	}
	// ѹ��ƽ��ֵ 
	lua_pushnumber(L, sum / n);
	// ѹ���
	lua_pushnumber(L, sum);

	// �����������
	return 2;                   
}

static int math_hello(lua_State* L) {
	printf("hello world!");
	return 0;
}

static const struct luaL_Reg tstlib[] = {
	{ "average", math_average },
	{ "hello", math_hello },
	{ NULL, NULL }
};

LUA_TSTAPI int luaopen_tstlib(lua_State *L) {
	luaL_newlib(L, tstlib);
	lua_pushvalue(L, -1);
	lua_setglobal(L, "tst");
	return 1;
}