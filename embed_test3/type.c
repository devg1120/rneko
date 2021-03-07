#include <stdio.h>
#include <neko.h>

value print( value v ) {
	switch( val_type(v) ) {
	case VAL_NULL:
		printf("null");
		break;
	case VAL_INT:
		printf("int : %d",val_int(v));
		break;
	case VAL_FLOAT:
		printf("float : %f",val_float(v));
		break;
	case VAL_BOOL:
		printf("bool : %s",val_bool(v)?"true":"false");
		break;
	case VAL_ARRAY:
		printf("array : size %d",val_array_size(v));
		break;
	case VAL_FUNCTION:
		printf("function : %d args",val_fun_nargs(v));
		break;
	case VAL_STRING:
		printf("string : %s (%d bytes)",val_string(v),val_strlen(v));
		break;
	case VAL_OBJECT:
		printf("object");
		break;
	case VAL_ABSTRACT:
		printf("abstract of kind %X",val_kind(v));
		break;
	default:
		printf("?????");
		break;
	}
	return val_null;
}

DEFINE_PRIM(print,1);
