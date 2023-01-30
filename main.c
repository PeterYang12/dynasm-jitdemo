#include "dynasm_driver.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: jit2 <integer>\n");
        return 1;
    }

    int num = atoi(argv[1]);
    dasm_State *state;
    initjit(&state, dasm_actions);
    yyh_jit(&state, num);
    
    // Link the code and write it to executable memory.
    int (*fptr)() = jitcode(&state);

    // Call the JIT-ted function.
    int ret = fptr();
    assert(num == ret);

    // Free the machine code.
    free_jitcode(fptr);

    return ret;
}