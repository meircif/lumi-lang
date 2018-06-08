#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "statement/enum.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file23_name = "statement/enum.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file23_name

/* TL4 compiler - Syntax tree Enum */

/* Enum node in the syntax tree  */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct EnumData EnumData;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct EnumData {
  SyntaxTreeNode _base;
  String* name;
  ModuleMembers* my_module;
  List* values;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumData_parse_new(EnumData* self, Char* end, EnumData** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumData_parse_new = "EnumData.parse-new";
#define LUMI_FUNC_NAME _func_name_EnumData_parse_new
Returncode EnumData_parse_new(EnumData* self, Char* end, EnumData** new_node) {
  (*new_node) = malloc(sizeof(EnumData));
  if ((*new_node) == NULL) RAISE(10)
  *(*new_node) = (EnumData){EnumData__dtl, NULL, 0, NULL, NULL, NULL};
  (*new_node)->_base._dtl = EnumData__dtl;
  CHECK(11, EnumData_parse((*new_node), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumData_parse(EnumData* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumData_parse = "EnumData.parse";
#define LUMI_FUNC_NAME _func_name_EnumData_parse
Returncode EnumData_parse(EnumData* self, Char* end) {
  CHECK(14, SyntaxTreeNode_set_location(&(self->_base)) )
  self->my_module = glob->current_module;
  CHECK(16, read_new(&(String){1, 0, ""}, &(self->name), &((*end))) )
  Bool _Bool133;
  CHECK(17, f_is_legal_name(self->name, NAME_TYPE, &(_Bool133)) )
  if (!_Bool133) {
    CHECK(18, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){18, 17, "illegal Enum name"}, self->name) )
  }
  TypeData* _TypeData134;
  CHECK(19, Global_find_type(glob, self->name, &(_TypeData134)) )
  if (NULL != _TypeData134) {
    CHECK(20, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){25, 24, "Enum name overrides type"}, self->name) )
  }
  EnumData* _EnumData135;
  CHECK(21, NameMap_find(self->my_module->enum_map, self->name, (void**)&(_EnumData135)) )
  if (NULL != _EnumData135) {
    CHECK(22, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){21, 20, "redefinition of Enum"}, self->name) )
  }
  self->values = malloc(sizeof(List));
  if (self->values == NULL) RAISE(23)
  *self->values = (List){NULL, NULL};
  while (true) {
    String* value = NULL;
    Int spaces = 0;
    CHECK(27, read_until(&(String){7, 6, " .([{?"}, true, &(value), &((*end)), &(spaces)) )
    if (!(spaces > 0)) break;
    if (spaces != 2) {
      CHECK(30, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), spaces, 2) )
    }
    Bool _Bool136;
    CHECK(31, f_is_legal_name(value, NAME_CONSTANT, &(_Bool136)) )
    if (!_Bool136) {
      CHECK(32, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){22, 21, "illegal constant name"}, value) )
    }
    if ((*end) != '\n') {
      CHECK(34, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){40, 39, "expected new-line after Enum value, got"}, (*end)) )
    }
    String* _String137;
    CHECK(36, string_new_copy(value, &(_String137)) )
    CHECK(36, List_add(self->values, _String137) )
  }
  if (!(NULL != self->values->first)) {
    CHECK(38, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){20, 19, "Enum with no values"}) )
  }
  glob->save_input = true;
  CHECK(40, NameMap_add(self->my_module->enum_map, self->name, self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumData_m_has_value(EnumData* self, String* value, Bool* has_value);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumData_m_has_value = "EnumData.m-has-value";
#define LUMI_FUNC_NAME _func_name_EnumData_m_has_value
Returncode EnumData_m_has_value(EnumData* self, String* value, Bool* has_value) {
  (*has_value) = true;
  Bool _Bool138;
  CHECK(44, String_equal(value, &(String){7, 6, "length"}, &(_Bool138)) )
  if (_Bool138) {
    return OK;
  }
  ListNode* node = self->values->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool139;
    CHECK(49, String_equal(value, node->item, &(_Bool139)) )
    if (_Bool139) {
      return OK;
    }
    node = node->next;
  }
  (*has_value) = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumData_write_cname(EnumData* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumData_write_cname = "EnumData.write-cname";
#define LUMI_FUNC_NAME _func_name_EnumData_write_cname
Returncode EnumData_write_cname(EnumData* self) {
  CHECK(55, ModuleMembers_write_prefix(self->my_module) )
  CHECK(56, write_cname(self->name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumData_write(EnumData* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumData_write = "EnumData.write";
#define LUMI_FUNC_NAME _func_name_EnumData_write
Returncode EnumData_write(EnumData* self) {
  CHECK(59, write(&(String){11, 10, "\nenum {\n  "}) )
  ListNode* node = self->values->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(63, EnumData_write_cname(self) )
    CHECK(64, write(&(String){2, 1, "_"}) )
    CHECK(65, write_cname(node->item) )
    if (node == self->values->first) {
      CHECK(67, write(&(String){5, 4, " = 0"}) )
    }
    node = node->next;
    CHECK(69, write(&(String){5, 4, ",\n  "}) )
  }
  CHECK(70, EnumData_write_cname(self) )
  CHECK(71, write(&(String){9, 8, "_length\n"}) )
  CHECK(72, write(&(String){4, 3, "};\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func EnumData__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func EnumData__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)EnumData_write};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
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
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
