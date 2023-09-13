/*
** This file has been pre-processed with DynASM.
** https://luajit.org/dynasm.html
** DynASM version 1.5.0, DynASM x64 version 1.5.0
** DO NOT EDIT! The original file is in "jit.dasc".
*/

#line 1 "jit.dasc"
// Most basic DynASM JIT; generates a trivial function that
// returns a given value, and executes it.

// DynASM directives.
//|.arch x64
#if DASM_VERSION != 10500
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 6 "jit.dasc"
//|.actionlist dasm_actions
static const unsigned char dasm_actions[50] = {
  250,7,248,10,255,252,243,15,30,252,250,255,144,195,255,250,7,255,184,237,
  133,192,252,233,245,72,141,61,244,250,252,255,39,254,1,250,15,248,4,246,248,
  254,0,249,144,133,192,144,195,255
};

#line 7 "jit.dasc"
//|.section code, jmp_table
#define DASM_SECTION_CODE	0
#define DASM_SECTION_JMP_TABLE	1
#define DASM_MAXSECTION		2
#line 8 "jit.dasc"
//|.globals lbl_
enum {
  lbl_hello,
  lbl__MAX
};
#line 9 "jit.dasc"

//|.macro ENDBR
//||#if defined (__CET__) && (__CET__ & 1) != 0
//|	.if X64
//|		endbr64
//|	.else
//|		endbr32
//|	.endif
//||#endif
//|.endmacro

static int leave(dasm_State **Dst){
  //|.align 8
  //|->hello:
  //| ENDBR
  dasm_put(Dst, 0);
  #if defined (__CET__) && (__CET__ & 1) != 0
  dasm_put(Dst, 5);
  #endif
#line 24 "jit.dasc"
  //| nop
  //| ret
  dasm_put(Dst, 12);
#line 26 "jit.dasc"
}

static int yyh_jit(dasm_State **Dst, int num_test, unsigned int target_label) {
  //|.align 8
  //|  ENDBR
  dasm_put(Dst, 15);
  #if defined (__CET__) && (__CET__ & 1) != 0
  dasm_put(Dst, 5);
  #endif
#line 31 "jit.dasc"
  //|  mov eax, num_test
  //|  test eax, eax
  //|  jmp =>target_label
  //|  lea rdi, aword [>4]
  //|  jmp aword [rdi]
  //|.jmp_table
  dasm_put(Dst, 18, num_test, target_label);
#line 37 "jit.dasc"
  //|.align 16
  //|4:
  //|  .aword >2
  //|.code
  dasm_put(Dst, 35);
#line 41 "jit.dasc"
  //|  ENDBR
  #if defined (__CET__) && (__CET__ & 1) != 0
  dasm_put(Dst, 5);
  #endif
#line 42 "jit.dasc"
  //|=>1:
  //|  nop
  //|  test eax, eax
  //|  nop
  //|  ret
  dasm_put(Dst, 43, 1);
#line 47 "jit.dasc"

  return 1;
}
