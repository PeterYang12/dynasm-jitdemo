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
static const unsigned char dasm_actions[35] = {
  252,243,15,30,252,251,255,184,237,133,192,72,141,61,244,250,252,255,39,254,
  1,248,4,246,248,254,0,248,2,144,133,192,144,195,255
};

#line 7 "jit.dasc"
//|.section code, jmp_table
#define DASM_SECTION_CODE	0
#define DASM_SECTION_JMP_TABLE	1
#define DASM_MAXSECTION		2
#line 8 "jit.dasc"
//|.globals lbl_
enum {
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

static int yyh_jit(dasm_State **Dst, int num_test) {
  //|  ENDBR
  #if defined (__CET__) && (__CET__ & 1) != 0
  dasm_put(Dst, 0);
  #endif
#line 22 "jit.dasc"
  //|  mov eax, num_test
  //|  test eax, eax
  //|  lea rdi, aword [>4]
  //|  jmp aword [rdi]
  //|.jmp_table
  dasm_put(Dst, 7, num_test);
#line 27 "jit.dasc"
  //|4:
  //|  .aword >2
  //|.code
  dasm_put(Dst, 21);
#line 30 "jit.dasc"
  //|2:
  //|  nop
  //|  test eax, eax
  //|  nop
  //|  ret
  dasm_put(Dst, 27);
#line 35 "jit.dasc"

  return 1;
}
