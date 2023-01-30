#include <assert.h>
#include <stdio.h>
#include <sys/mman.h>

#include "dynasm/dasm_proto.h"
#include "dynasm/dasm_x86.h"

#include "jit.h"

void* labels[lbl__MAX];

void initjit(int num);
void *jitcode(dasm_State **state);
void free_jitcode(void *code);