
#gcc main.c -o test   -I../neko/vm -I../neko/build -L../neko/build/bin   -pthread -lneko_static -ldl -lgc -lm

#gcc main.c -o test   -I../neko/vm -I../neko/build -L../neko/build/bin   -pthread -lneko -ldl -lgc -lm

gcc -shared -fPIC     -I../neko/vm -I../neko/build -o hello.ndll hello.c
gcc -shared -fPIC  -w -I../neko/vm -I../neko/build -o type.ndll type.c
gcc -shared -fPIC  -w -I../neko/vm -I../neko/build -o set.ndll set.c

../neko/build/bin/nekoc ./mymodule.neko

gcc main.c -o test   -I../neko/vm -I../neko/build -L../neko/build/bin  ./set.ndll -pthread -lneko -ldl -lgc -lm
