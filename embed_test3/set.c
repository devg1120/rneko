#include <stdio.h>
#include <neko.h>

value *function_storage = NULL;

static value set_handler( value f ) {
	val_check_function(f,1); // checks that f has 1 argument
	if( function_storage == NULL )
		function_storage = alloc_root(1);
	*function_storage = f;
	return val_null;
}

void exec(void) {
  value ret2 = val_call1(*function_storage,alloc_string("Hello"));  
}

DEFINE_PRIM(set_handler,1);

