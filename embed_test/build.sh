
#gcc main.c -o test   -I../neko/vm -I../neko/build -L../neko/build/bin   -pthread -lneko_static -ldl -lgc -lm

gcc main.c -o test   -I../neko/vm -I../neko/build -L../neko/build/bin   -pthread -lneko -ldl -lgc -lm

../neko/build/bin/nekoc ./mymodule.neko
