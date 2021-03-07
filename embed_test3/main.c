#include <stdio.h>
#include <time.h>
#include <neko_vm.h>



value load( char *file ) {
    value loader;
    value args[2];
    value exc = NULL;
    value ret;
    loader = neko_default_loader(NULL,0);
    args[0] = alloc_string(file);
    args[1] = loader;
    ret = val_callEx(loader,val_field(loader,val_id("loadmodule")),args,2,&exc);
    if( exc != NULL ) {
        buffer b = alloc_buffer(NULL);
        val_buffer(b,exc);
        printf("Uncaught exception - %s\n",val_string(buffer_to_string(b)));
        return NULL;
    }
    return ret;
}

void execute( value module ) {
    value x = val_field(module,val_id("x"));
    value f = val_field(module,val_id("f"));
    value fib = val_field(module,val_id("fib"));
    value ret;
    value fibret;

    if( !val_is_int(x) )
         return;
    printf("x = %d\n",val_int(x));
    if( !val_is_function(f) || val_fun_nargs(f) != 1 )
         return;
    ret = val_call1(f,x);
    if( !val_is_int(ret) )
         return;
    printf("f(x) = %d\n",val_int(ret));

    value input = alloc_int(35);
    fibret = val_call1(fib,input);
    if( !val_is_int(fibret) )
         return;
    printf("fib(x) = %d\n",val_int(fibret));

    exec();
//    value ret2 = val_call1(*function_storage,alloc_string("Hello"));

}


int main( int argc, char *argv[] ) {
    int jit = 1;
    neko_vm *vm;
    value module;
    //neko_global_init(NULL);
    neko_global_init();
    vm = neko_vm_alloc(NULL);
    neko_vm_select(vm);

    neko_vm_jit(vm,jit);

    module = load("mymodule.n");
    if( module == NULL ) {
         printf("Failed to load module !\n");
         return -1;
    }

    clock_t start,end;
    start = clock();

    printf("--start\n");
    execute(module);

    neko_global_free();

    end = clock();

    printf("----------------end: %2f\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
