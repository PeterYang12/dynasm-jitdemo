CFLAGS=-O0 -g

all : jit-demo

jit-demo : dynasm-driver.c jit.h
	$(CC) $(CFLAGS) -o jit-demo dynasm-driver.c -DJIT="jit2.h"
jit.h : jit.dasc
	./minilua dynasm/dynasm.lua jit.dasc > jit.h

clean : 
		-rm jit.h jit-demo