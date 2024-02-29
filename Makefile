CFLAGS=-O0 -g

all : jit-demo
.PHONY : all

jit-demo : dynasm-driver.c jit.h
	$(CC) $(CFLAGS) -o jit-demo main.c dynasm-driver.c -DJIT=\"jit.h\"
jit.h : jit.dasc
	./minilua dynasm/dynasm.lua -D X64=1 jit.dasc > jit.h

# .PHONY 表示clean是个伪目标文件
# rm前面的-表示某些文件出现问题但不要管，继续后面的事
.PHONY : clean
clean : 
	-rm -f jit.h jit-demo
