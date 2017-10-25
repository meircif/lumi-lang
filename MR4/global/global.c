#ifndef MR_MAINFILE
#define MR_MAINFILE "global/global.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file4_name = "global/global.3.mr";
#endif
#define MR_FILE_NAME _mr_file4_name

/* MR4 compiler - Global compiler data */

#if MR_STAGE == MR_TYPEDEFS
typedef struct Global Global;
#elif MR_STAGE == MR_TYPES(0)
struct Global {
/* stores all language operators */  SyntaxTreeRoot* root;
/* stores all language operators */  NameMap* operator_map;
/* stores all types - language built-ins and user defined */  NameMap* type_map;
/* the currently parsed input file object */  File* input_file;
/* the currently written output file object */  File* output_file;
/* holds the name of the input-file and the line number of the code currently *//* been worked with */  String* input_file_name;
  Int line_number;
/* current indentation */  Int spaces;
/* input reading state */  String* input_buffer;
  Char input_end;
  Int input_spaces;
  Bool got_new_line;
  Bool save_input;
/* built-in types */  TypeData* type_char;
  TypeData* type_bool;
  TypeData* type_int;
  TypeData* type_empty;
  TypeData* type_func;
  TypeData* type_string;
  TypeData* type_array;
  TypeData* type_type;
  TypeData* type_file;
  TypeData* type_sys;
};
#endif/* stores all language operators *//* stores all language operators *//* stores all types - language built-ins and user defined *//* the currently parsed input file object *//* the currently written output file object *//* holds the name of the input-file and the line number of the code currently *//* been worked with *//* current indentation *//* input reading state *//* built-in types */
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init = "Global.init";
#define MR_FUNC_NAME _func_name_Global_init
Returncode Global_init(Global* self) {
  self->root = malloc(sizeof(SyntaxTreeRoot));
  if (self->root == NULL) RAISE(47)
  *self->root = (SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL};
  self->root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  self->input_buffer = _new_string(1024);
  if (self->input_buffer == NULL) RAISE(48)
  CHECK(49, Global_init_operator_map(self) )
  CHECK(50, Global_init_builtin_types(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init_operator_map(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init_operator_map = "Global.init-operator-map";
#define MR_FUNC_NAME _func_name_Global_init_operator_map
Returncode Global_init_operator_map(Global* self) {
  self->operator_map = malloc(sizeof(NameMap));
  if (self->operator_map == NULL) RAISE(53)
  *self->operator_map = (NameMap){NULL, NULL};
  CHECK(54, Global_add_operator_copy(self, &(String){2, 1, "+"}, 0, 0) )
  CHECK(55, Global_add_operator_copy(self, &(String){2, 1, "-"}, 0, 0) )
  CHECK(56, Global_add_operator_copy(self, &(String){2, 1, "*"}, 0, 1) )
  CHECK(57, Global_add_operator_copy(self, &(String){2, 1, "/"}, 0, 1) )
  CHECK(58, Global_add_operator(self, &(String){2, 1, "="}, &(String){3, 2, "=="}, 1, 0) )
  CHECK(59, Global_add_operator_copy(self, &(String){3, 2, "!="}, 1, 0) )
  CHECK(60, Global_add_operator_copy(self, &(String){2, 1, ">"}, 1, 0) )
  CHECK(61, Global_add_operator_copy(self, &(String){2, 1, "<"}, 1, 0) )
  CHECK(62, Global_add_operator_copy(self, &(String){3, 2, ">="}, 1, 0) )
  CHECK(63, Global_add_operator_copy(self, &(String){3, 2, "<="}, 1, 0) )
  CHECK(64, Global_add_operator(self, &(String){4, 3, "not"}, &(String){2, 1, "!"}, 2, 0) )
  CHECK(65, Global_add_operator(self, &(String){3, 2, "or"}, &(String){3, 2, "||"}, 3, 0) )
  CHECK(66, Global_add_operator(self, &(String){4, 3, "and"}, &(String){3, 2, "&&"}, 3, 1) )
  CHECK(67, Global_add_operator(self, &(String){3, 2, ":="}, &(String){2, 1, "="}, 4, 0) )
  CHECK(68, Global_add_operator_copy(self, &(String){3, 2, "+="}, 4, 0) )
  CHECK(69, Global_add_operator_copy(self, &(String){3, 2, "-="}, 4, 0) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator = "Global.add-operator";
#define MR_FUNC_NAME _func_name_Global_add_operator
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index) {
  Operator* operator = malloc(sizeof(Operator));
  if (operator == NULL) RAISE(76)
  *operator = (Operator){NULL, NULL, 0, 0};
  CHECK(77, Operator_init(operator, name, c_name, order, group_index) )
  CHECK(78, NameMap_add(self->operator_map, operator->name, operator) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator_copy = "Global.add-operator-copy";
#define MR_FUNC_NAME _func_name_Global_add_operator_copy
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index) {
  CHECK(84, Global_add_operator(self, name, name, order, group_index) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init_builtin_types(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init_builtin_types = "Global.init-builtin-types";
#define MR_FUNC_NAME _func_name_Global_init_builtin_types
Returncode Global_init_builtin_types(Global* self) {
  self->type_map = malloc(sizeof(NameMap));
  if (self->type_map == NULL) RAISE(87)
  *self->type_map = (NameMap){NULL, NULL};
  CHECK(88, Global_add_builtin_type(self, &(String){5, 4, "Char"}, true, &(self->type_char)) )
  CHECK(89, Global_add_builtin_type(self, &(String){5, 4, "Bool"}, true, &(self->type_bool)) )
  CHECK(90, Global_add_builtin_type(self, &(String){4, 3, "Int"}, true, &(self->type_int)) )
  CHECK(91, Global_add_builtin_type(self, &(String){6, 5, "Empty"}, false, &(self->type_empty)) )
  CHECK(92, Global_add_builtin_type(self, &(String){5, 4, "Func"}, true, &(self->type_func)) )
  CHECK(93, Global_add_builtin_type(self, &(String){7, 6, "String"}, false, &(self->type_string)) )
  CHECK(94, Global_add_builtin_type(self, &(String){6, 5, "Array"}, false, &(self->type_array)) )
  CHECK(95, Global_add_builtin_type(self, &(String){5, 4, "Type"}, false, &(self->type_type)) )
  CHECK(96, Global_add_builtin_type(self, &(String){5, 4, "File"}, false, &(self->type_file)) )
  CHECK(97, Global_add_builtin_type(self, &(String){4, 3, "Sys"}, false, &(self->type_sys)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, TypeData** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_type = "Global.add-builtin-type";
#define MR_FUNC_NAME _func_name_Global_add_builtin_type
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, TypeData** type_data) {
  (*type_data) = malloc(sizeof(TypeData));
  if ((*type_data) == NULL) RAISE(101)
  *(*type_data) = (TypeData){TypeData__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false};
  (*type_data)->_base._base._base._dtl = TypeData__dtl;
  CHECK(102, string_new_copy(name, &((*type_data)->name)) )
  (*type_data)->is_primitive = is_primitive;
  CHECK(104, Global_add_type(self, (*type_data)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_type(Global* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_type = "Global.add-type";
#define MR_FUNC_NAME _func_name_Global_add_type
Returncode Global_add_type(Global* self, TypeData* type_data) {
  CHECK(107, SyntaxTreeNamespace_init(&(type_data->_base)) )
  CHECK(108, NameMap_add(self->type_map, type_data->name, type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
extern Global* glob;
#elif MR_STAGE == MR_FUNCTIONS
Global* glob = &(Global){NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, '\0', 0, false, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/list.c"
#include "global/map.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
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
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
