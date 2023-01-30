CFLAGS=-O3 -g -std=gnu99 

all: jit-demo

jit-demo: dynasm-driver.c jit.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o jit-demo dynasm-driver.c
jit.h: jit.dasc
	./minilua dynasm/dynasm.lua jit.dasc > jit.c