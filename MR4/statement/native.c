#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/native.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file26_name = "statement/native.3.mr";
#endif
#define MR_FILE_NAME _mr_file26_name

/* MR4 compiler - Syntax tree native nodes */

/* Parse "native" keyword in the root tree */
#if MR_STAGE == MR_DECLARATIONS
Returncode parse_native(SyntaxTreeRoot* root, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_parse_native = "parse-native";
#define MR_FUNC_NAME _func_name_parse_native
Returncode parse_native(SyntaxTreeRoot* root, Char* end) {
  String* keyword = NULL;
  Int _Int157;
  CHECK(6, read_until(&(String){2, 1, " "}, false, &(keyword), &((*end)), &(_Int157)) )
  if ((*end) != ' ') {
    CHECK(8, SyntaxTreeNode_m_syntax_error_c(&(root->_base._base._base._base), &(String){43, 42, "expected space after \"native\" keyword, got"}, (*end)) )
  }
  
  Bool _Bool158;
  CHECK(11, String_equal(keyword, &(String){5, 4, "func"}, &(_Bool158)) )
  if (_Bool158) {
    NativeFunction* _NativeFunction159;
    CHECK(12, NativeFunction_parse_new(NULL, &((*end)), &(_NativeFunction159)) )
    CHECK(12, List_add(root->_base._base.functions, &(_NativeFunction159->_base)) )
    
  }
  else {
    Bool _Bool160;
    CHECK(14, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool160)) )
    if (_Bool160) {
      NativeVariable* _NativeVariable161;
      CHECK(15, NativeVariable_parse_new(NULL, &((*end)), &(_NativeVariable161)) )
      CHECK(15, List_add(root->_base._base._base.variables, &(_NativeVariable161->_base)) )
      
    }
    else {
      Bool _Bool162;
      CHECK(17, String_equal(keyword, &(String){5, 4, "type"}, &(_Bool162)) )
      if (_Bool162) {
        NativeType* _NativeType163;
        CHECK(18, NativeType_parse_new(NULL, &((*end)), &(_NativeType163)) )
        CHECK(18, List_add(root->_base.types, &(_NativeType163->_base)) )
        
      }
      else {
        CHECK(21, SyntaxTreeNode_m_syntax_error(&(root->_base._base._base._base), &(String){25, 24, "unknown \"native\" keyword"}, keyword) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Native function declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct NativeFunction NativeFunction;
#elif MR_STAGE == MR_TYPES(4)
struct NativeFunction {
  SyntaxTreeFunction _base;
  ModuleMembers* outer_module;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeFunction_parse_new(NativeFunction* self, Char* end, NativeFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeFunction_parse_new = "NativeFunction.parse-new";
#define MR_FUNC_NAME _func_name_NativeFunction_parse_new
Returncode NativeFunction_parse_new(NativeFunction* self, Char* end, NativeFunction** new_node) {
  (*new_node) = malloc(sizeof(NativeFunction));
  if ((*new_node) == NULL) RAISE(29)
  *(*new_node) = (NativeFunction){NativeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, NULL};
  (*new_node)->_base._base._base._base._dtl = NativeFunction__dtl;
  CHECK(30, NativeFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeFunction_parse(NativeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeFunction_parse = "NativeFunction.parse";
#define MR_FUNC_NAME _func_name_NativeFunction_parse
Returncode NativeFunction_parse(NativeFunction* self, Char* end) {
  CHECK(33, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
  self->outer_module = glob->current_module;
  CHECK(35, SyntaxTreeFunction_parse_header(&(self->_base), true, &((*end))) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(36)
  *self->_base._base.code_nodes = (List){NULL, NULL};
  self->_base._base._base.variables = malloc(sizeof(List));
  if (self->_base._base._base.variables == NULL) RAISE(37)
  *self->_base._base._base.variables = (List){NULL, NULL};
  CHECK(38, NameMap_add(glob->global_module->function_map, self->_base.name, &(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeFunction_link_types(NativeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeFunction_link_types = "NativeFunction.link-types";
#define MR_FUNC_NAME _func_name_NativeFunction_link_types
Returncode NativeFunction_link_types(NativeFunction* self) {
  glob->current_module = self->outer_module;
  CHECK(42, SyntaxTreeFunction_link_types(&(self->_base)) )
  glob->current_module = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeFunction_analyze(NativeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeFunction_analyze = "NativeFunction.analyze";
#define MR_FUNC_NAME _func_name_NativeFunction_analyze
Returncode NativeFunction_analyze(NativeFunction* self) {
  glob->current_module = self->outer_module;
  CHECK(47, SyntaxTreeFunction_analyze(&(self->_base)) )
  glob->current_module = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeFunction_write(NativeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeFunction_write = "NativeFunction.write";
#define MR_FUNC_NAME _func_name_NativeFunction_write
Returncode NativeFunction_write(NativeFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NativeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NativeFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)NativeFunction_link_types, (void*)NativeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)NativeFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Native variable declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct NativeVariable NativeVariable;
#elif MR_STAGE == MR_TYPES(3)
struct NativeVariable {
  SyntaxTreeVariable _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeVariable_parse_new(NativeVariable* self, Char* end, NativeVariable** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeVariable_parse_new = "NativeVariable.parse-new";
#define MR_FUNC_NAME _func_name_NativeVariable_parse_new
Returncode NativeVariable_parse_new(NativeVariable* self, Char* end, NativeVariable** new_node) {
  (*new_node) = malloc(sizeof(NativeVariable));
  if ((*new_node) == NULL) RAISE(57)
  *(*new_node) = (NativeVariable){NativeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  (*new_node)->_base._base._base._dtl = NativeVariable__dtl;
  CHECK(58, SyntaxTreeVariable_parse(&((*new_node)->_base), ACCESS_VAR, false, NULL, NULL, glob->global_module, &((*end))) )
  (*new_node)->_base.is_native = true;
  (*new_node)->_base.my_module = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeVariable_analyze(NativeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeVariable_analyze = "NativeVariable.analyze";
#define MR_FUNC_NAME _func_name_NativeVariable_analyze
Returncode NativeVariable_analyze(NativeVariable* self) {
  if (!self->_base.type_instance->type_data->is_primitive) {
    CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){56, 55, "only primitive types supported for native variable, got"}, self->_base.type_instance->type_data->name) )
  }
  CHECK(69, SyntaxTreeVariable_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeVariable_write(NativeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeVariable_write = "NativeVariable.write";
#define MR_FUNC_NAME _func_name_NativeVariable_write
Returncode NativeVariable_write(NativeVariable* self) {
  CHECK(72, write(&(String){9, 8, "\nextern "}) )
  CHECK(73, SyntaxTreeVariable_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NativeVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NativeVariable__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)SyntaxTreeVariable_link_types, (void*)NativeVariable_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)NativeVariable_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_find_variable, (void*)SyntaxTreeVariable_write_sequence};
#endif


/* Native variable declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct NativeType NativeType;
#elif MR_STAGE == MR_TYPES(4)
struct NativeType {
  TypeData _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_parse_new(NativeType* self, Char* end, NativeType** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_parse_new = "NativeType.parse-new";
#define MR_FUNC_NAME _func_name_NativeType_parse_new
Returncode NativeType_parse_new(NativeType* self, Char* end, NativeType** new_node) {
  (*new_node) = malloc(sizeof(NativeType));
  if ((*new_node) == NULL) RAISE(79)
  *(*new_node) = (NativeType){NativeType__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false, false, false};
  (*new_node)->_base._base._base._base._dtl = NativeType__dtl;
  CHECK(80, NativeType_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_parse(NativeType* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_parse = "NativeType.parse";
#define MR_FUNC_NAME _func_name_NativeType_parse
Returncode NativeType_parse(NativeType* self, Char* end) {
  self->_base.is_primitive = true;
  CHECK(84, read_new(&(String){1, 0, ""}, &(self->_base.name), &((*end))) )
  CHECK(85, TypeData_add_type(&(self->_base), glob->global_module) )
  CHECK(86, SyntaxTreeNamespace_init(&(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_analyze(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_analyze = "NativeType.analyze";
#define MR_FUNC_NAME _func_name_NativeType_analyze
Returncode NativeType_analyze(NativeType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_write_declaration(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_write_declaration = "NativeType.write-declaration";
#define MR_FUNC_NAME _func_name_NativeType_write_declaration
Returncode NativeType_write_declaration(NativeType* self) {
  /* typedef void* `name`; */
  CHECK(93, write(&(String){16, 15, "\ntypedef void* "}) )
  CHECK(94, write_cname(self->_base.name) )
  CHECK(95, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_write_methods_declaration(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_write_methods_declaration = "NativeType.write-methods-declaration";
#define MR_FUNC_NAME _func_name_NativeType_write_methods_declaration
Returncode NativeType_write_methods_declaration(NativeType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_write_methods_body(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_write_methods_body = "NativeType.write-methods-body";
#define MR_FUNC_NAME _func_name_NativeType_write_methods_body
Returncode NativeType_write_methods_body(NativeType* self) {
  /* do nothing */
  
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_write_global(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_write_global = "NativeType.write-global";
#define MR_FUNC_NAME _func_name_NativeType_write_global
Returncode NativeType_write_global(NativeType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NativeType_write(NativeType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NativeType_write = "NativeType.write";
#define MR_FUNC_NAME _func_name_NativeType_write
Returncode NativeType_write(NativeType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NativeType__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NativeType__dtl[] = {(void*)TypeData_get_parent_type, (void*)TypeData_link_types, (void*)NativeType_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)NativeType_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)TypeData_parse_child, (void*)SyntaxTreeBranch_find_variable, (void*)NativeType_write_declaration, (void*)NativeType_write_methods_declaration, (void*)NativeType_write_global, (void*)NativeType_write_methods_body, (void*)TypeData_write_me};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
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
