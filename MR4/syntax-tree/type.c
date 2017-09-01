#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/type.c"
#define DEPTH 5
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
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_parse_new(SyntaxTreeType* self, Char* end, SyntaxTreeType** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_parse_new = "SyntaxTreeType.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_parse_new
Returncode SyntaxTreeType_parse_new(SyntaxTreeType* self, Char* end, SyntaxTreeType** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeType));
  if ((*new_node) == NULL) RAISE(8)
  *(*new_node) = (SyntaxTreeType){SyntaxTreeType__dtl, 0, NULL, NULL, NULL, NULL};
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
  String* name = NULL;
  CHECK(14, read_new(&(String){1, 0, ""}, &(name), &((*end))) )
  CHECK(15, Global_add_user_type(glob, name, &(self->type_data)) )
  self->_base._base.indentation_spaces = 2;
  CHECK(17, SyntaxTreeBranch_parse_block_children(&(self->_base._base), self, &((*end))) )
  self->_base._base.indentation_spaces = 0;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_parse_child(SyntaxTreeType* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_parse_child = "SyntaxTreeType.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_parse_child
Returncode SyntaxTreeType_parse_child(SyntaxTreeType* self, String* keyword, Char* end) {
  Bool _Bool74;
  CHECK(21, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, self, &((*end)), &(_Bool74)) )
  if (!_Bool74) {
    CHECK(22, f_syntax_error(&(String){16, 15, "unknown keyword"}, keyword) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_write_declaration(SyntaxTreeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_write_declaration = "SyntaxTreeType.write-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_write_declaration
Returncode SyntaxTreeType_write_declaration(SyntaxTreeType* self) {
  /* typedef struct `name` `name`; */
  if (!(NULL != self->type_data)) {
    RAISE(27)
  }
  CHECK(28, write(&(String){16, 15, "typedef struct "}) )
  CHECK(29, write_cname(self->type_data->name) )
  CHECK(30, write(&(String){2, 1, " "}) )
  CHECK(31, write_cname(self->type_data->name) )
  CHECK(32, write(&(String){3, 2, ";\n"}) )
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
  /* struct `name` { */
  /*   `variables...` */
  /* }; */
  /* `functions...` */
  CHECK(39, write(&(String){8, 7, "struct "}) )
  CHECK(40, write_cname(self->type_data->name) )
  CHECK(41, write(&(String){4, 3, " {\n"}) )
  self->_base._base.indentation_spaces = 2;
  CHECK(43, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base._base.variables) )
  self->_base._base.indentation_spaces = 0;
  CHECK(45, write(&(String){3, 2, "};"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_write_methods_declaration(SyntaxTreeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_write_methods_declaration = "SyntaxTreeType.write-methods-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_write_methods_declaration
Returncode SyntaxTreeType_write_methods_declaration(SyntaxTreeType* self) {
  CHECK(48, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_write_dtl(SyntaxTreeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_write_dtl = "SyntaxTreeType.write-dtl";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_write_dtl
Returncode SyntaxTreeType_write_dtl(SyntaxTreeType* self) {
  /* pass */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeType_write_methods_body(SyntaxTreeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeType_write_methods_body = "SyntaxTreeType.write-methods-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeType_write_methods_body
Returncode SyntaxTreeType_write_methods_body(SyntaxTreeType* self) {
  CHECK(54, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base.functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeType__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeType__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeType_write, (void*)SyntaxTreeType_parse_child};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTypeWriter SyntaxTreeTypeWriter;
#elif MR_STAGE == MR_TYPES(0)
struct SyntaxTreeTypeWriter {
  Func* _dtl;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTypeWriter_write(SyntaxTreeTypeWriter* self, SyntaxTreeType* type_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTypeWriter_write = "SyntaxTreeTypeWriter.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTypeWriter_write
Returncode SyntaxTreeTypeWriter_write(SyntaxTreeTypeWriter* self, SyntaxTreeType* type_node) {
  RAISE(59)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTypeWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTypeWriter__dtl[] = {(void*)SyntaxTreeTypeWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTypeDeclarationWriter SyntaxTreeTypeDeclarationWriter;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeTypeDeclarationWriter {
  SyntaxTreeTypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTypeDeclarationWriter_write(SyntaxTreeTypeDeclarationWriter* self, SyntaxTreeType* type_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTypeDeclarationWriter_write = "SyntaxTreeTypeDeclarationWriter.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTypeDeclarationWriter_write
Returncode SyntaxTreeTypeDeclarationWriter_write(SyntaxTreeTypeDeclarationWriter* self, SyntaxTreeType* type_node) {
  CHECK(63, SyntaxTreeType_write_declaration(type_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTypeDeclarationWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTypeDeclarationWriter__dtl[] = {(void*)SyntaxTreeTypeDeclarationWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTypeMethodsDeclarationWriter SyntaxTreeTypeMethodsDeclarationWriter;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeTypeMethodsDeclarationWriter {
  SyntaxTreeTypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTypeMethodsDeclarationWriter_write(SyntaxTreeTypeMethodsDeclarationWriter* self, SyntaxTreeType* type_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTypeMethodsDeclarationWriter_write = "SyntaxTreeTypeMethodsDeclarationWriter.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTypeMethodsDeclarationWriter_write
Returncode SyntaxTreeTypeMethodsDeclarationWriter_write(SyntaxTreeTypeMethodsDeclarationWriter* self, SyntaxTreeType* type_node) {
  CHECK(67, SyntaxTreeType_write_methods_declaration(type_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTypeMethodsDeclarationWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTypeMethodsDeclarationWriter__dtl[] = {(void*)SyntaxTreeTypeMethodsDeclarationWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTypeDtlWriter SyntaxTreeTypeDtlWriter;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeTypeDtlWriter {
  SyntaxTreeTypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTypeDtlWriter_write(SyntaxTreeTypeDtlWriter* self, SyntaxTreeType* type_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTypeDtlWriter_write = "SyntaxTreeTypeDtlWriter.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTypeDtlWriter_write
Returncode SyntaxTreeTypeDtlWriter_write(SyntaxTreeTypeDtlWriter* self, SyntaxTreeType* type_node) {
  CHECK(71, SyntaxTreeType_write_dtl(type_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTypeDtlWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTypeDtlWriter__dtl[] = {(void*)SyntaxTreeTypeDtlWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTypeMethodsBodyWriter SyntaxTreeTypeMethodsBodyWriter;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeTypeMethodsBodyWriter {
  SyntaxTreeTypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTypeMethodsBodyWriter_write(SyntaxTreeTypeMethodsBodyWriter* self, SyntaxTreeType* type_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTypeMethodsBodyWriter_write = "SyntaxTreeTypeMethodsBodyWriter.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTypeMethodsBodyWriter_write
Returncode SyntaxTreeTypeMethodsBodyWriter_write(SyntaxTreeTypeMethodsBodyWriter* self, SyntaxTreeType* type_node) {
  CHECK(75, SyntaxTreeType_write_methods_body(type_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTypeMethodsBodyWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTypeMethodsBodyWriter__dtl[] = {(void*)SyntaxTreeTypeMethodsBodyWriter_write};
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
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
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
