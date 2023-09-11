CFLAGS=-O0 -g

all : jit-demo

jit-demo : dynasm-driver.c jit.h
	$(CC) $(CFLAGS) -o jit-demo main.c dynasm-driver.c -DJIT=\"jit.h\"
jit.h : jit.dasc
	./minilua dynasm/dynasm.lua -D X64=1 jit.dasc > jit.h

clean : 
	rm -f jit.h jit-demo