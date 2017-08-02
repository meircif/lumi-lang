#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/root.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file17_name = "syntax-tree/root.3.mr";
#endif
#define MR_FILE_NAME _mr_file17_name

/* MR4 compiler - Syntax tree root */

/* The syntax tree root */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeRoot {
  SyntaxTreeNamespace _base;
  List* types;
/* todo... *//*  write C file in this order:
  1. type typedefs
  2. type structs (ordered by depth)
  3. function headers
  4. global variables
  5. function bodies
   */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse = "SyntaxTreeRoot.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv) {
  CHECK(8, SyntaxTreeNamespace_init(&(self->_base)) )
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(9)
  *self->types = (List){NULL, NULL};
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(11)
    glob->input_file_name = (&(((String*)((argv)->values))[n]));
    glob->line_number = 0;
    
    CHECK(14, SyntaxTreeBranch_parse_children(&(self->_base._base), NULL) )
    
    if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
      CHECK(17, f_syntax_error_msg(&(String){28, 27, "no new-line before file end"}) )
    }
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif/* todo... */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse_child = "SyntaxTreeRoot.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse_child
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char end) {
  Bool _Bool42;
  CHECK(21, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, end, NULL, &(_Bool42)) )
  if (_Bool42) {
    return OK;
  }
  Bool _Bool43;
  CHECK(23, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool43)) )
  if (_Bool43) {
    SyntaxTreeType* _SyntaxTreeType44;
    CHECK(24, SyntaxTreeType_parse_new(NULL, &(_SyntaxTreeType44)) )
    CHECK(24, List_add(self->types, _SyntaxTreeType44) )
  }
  else {
    Bool _Bool45;
    CHECK(25, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool45)) )
    if (_Bool45) {
      SyntaxTreeType* _SyntaxTreeType46;
      CHECK(26, SyntaxTreeType_parse_new(NULL, &(_SyntaxTreeType46)) )
      CHECK(26, List_add(self->types, _SyntaxTreeType46) )
    }
    else {
      CHECK(28, f_syntax_error(&(String){16, 15, "unknown keyword"}, keyword) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/*  write C file in this order:
  1. type typedefs
  2. type structs (ordered by depth)
  3. function headers
  4. global variables
  5. function bodies
   */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(38, SyntaxTreeBranch_write_children(&(self->_base._base), self->types) )
  CHECK(39, SyntaxTreeNamespace_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_child};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/function.c"
#include "syntax-tree/loop.c"
#include "syntax-tree/node.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/variable.c"
#include "mr4-compiler.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#endif
#undef MR_INCLUDES
#endif

#endif
