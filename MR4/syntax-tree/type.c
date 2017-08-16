#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/type.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file19_name = "syntax-tree/type.3.mr";
#endif
#define MR_FILE_NAME _mr_file19_name

/* MR4 compiler - Syntax tree type */

/* Type node in the syntax tree  */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeType SyntaxTreeType;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeType {
  SyntaxTreeNamespace _base;
  TypeData* type_data;
/* todo... */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_parse_new(SyntaxTreeType* self, Char* end, SyntaxTreeType** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_parse_new = "SyntaxTreeType.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_parse_new
Returncode SyntaxTreeType_parse_new(SyntaxTreeType* self, Char* end, SyntaxTreeType** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeType));
  if ((*new_node) == NULL) RAISE(8)
  *(*new_node) = (SyntaxTreeType){SyntaxTreeType__dtl, 0, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeType__dtl;
  CHECK(9, SyntaxTreeType_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_parse(SyntaxTreeType* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_parse = "SyntaxTreeType.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_parse
Returncode SyntaxTreeType_parse(SyntaxTreeType* self, Char* end) {
  CHECK(12, SyntaxTreeNamespace_init(&(self->_base)) )
  self->_base._base.indentation_spaces = 2;
  String* name = NULL;
  CHECK(15, read_new(&(String){1, 0, ""}, &(name), &((*end))) )
  CHECK(16, Global_add_user_type(glob, name, &(self->type_data)) )
  CHECK(17, SyntaxTreeBranch_parse_children(&(self->_base._base), self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* todo... */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_parse_child(SyntaxTreeType* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_parse_child = "SyntaxTreeType.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_parse_child
Returncode SyntaxTreeType_parse_child(SyntaxTreeType* self, String* keyword, Char* end) {
  Bool _Bool46;
  CHECK(21, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, self, &((*end)), &(_Bool46)) )
  if (!_Bool46) {
    CHECK(22, f_syntax_error(&(String){16, 15, "unknown keyword"}, keyword) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_write(SyntaxTreeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_write = "SyntaxTreeType.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_write
Returncode SyntaxTreeType_write(SyntaxTreeType* self) {
  CHECK(25, write(&(String){6, 5, "Type("}) )
  if (!(NULL != self->type_data)) {
    RAISE(27)
  }
  if (!(NULL != self->type_data->name)) {
    RAISE(29)
  }
  CHECK(30, write(self->type_data->name) )
  CHECK(31, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeType__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeType__dtl[] = {(void*)SyntaxTreeType_write, (void*)SyntaxTreeType_parse_child};
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
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
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
