#include <neko.h>

value test() {
	return alloc_string("module Hello world\n");
}

DEFINE_PRIM(test,0); // function test with 0 arguments

