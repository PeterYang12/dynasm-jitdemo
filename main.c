#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

extern void initjit(int num);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: jit2 <integer>\n");
        return 1;
    }

    int num = atoi(argv[1]);
    initjit(num);
    fprintf(stderr, "Finished!! \n");
    return 1;
}