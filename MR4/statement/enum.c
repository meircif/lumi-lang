#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/enum.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file22_name = "statement/enum.3.mr";
#endif
#define MR_FILE_NAME _mr_file22_name

/* MR4 compiler - Syntax tree Enum */

/* Enum node in the syntax tree  */
#if MR_STAGE == MR_TYPEDEFS
typedef struct EnumData EnumData;
#elif MR_STAGE == MR_TYPES(1)
struct EnumData {
  SyntaxTreeNode _base;
  String* name;
  List* values;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EnumData_parse_new(EnumData* self, Char* end, EnumData** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EnumData_parse_new = "EnumData.parse-new";
#define MR_FUNC_NAME _func_name_EnumData_parse_new
Returncode EnumData_parse_new(EnumData* self, Char* end, EnumData** new_node) {
  (*new_node) = malloc(sizeof(EnumData));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (EnumData){EnumData__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._dtl = EnumData__dtl;
  CHECK(10, EnumData_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EnumData_parse(EnumData* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EnumData_parse = "EnumData.parse";
#define MR_FUNC_NAME _func_name_EnumData_parse
Returncode EnumData_parse(EnumData* self, Char* end) {
  CHECK(13, SyntaxTreeNode_set_location(&(self->_base)) )
  CHECK(14, read_new(&(String){1, 0, ""}, &(self->name), &((*end))) )
  Bool _Bool116;
  CHECK(15, f_is_legal_name(self->name, NAME_TYPE, &(_Bool116)) )
  if (!_Bool116) {
    CHECK(16, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){18, 17, "illegal Enum name"}, self->name) )
  }
  self->values = malloc(sizeof(List));
  if (self->values == NULL) RAISE(17)
  *self->values = (List){NULL, NULL};
  while (true) {
    String* value = NULL;
    Int spaces = 0;
    CHECK(21, read_until(&(String){7, 6, " .([{?"}, true, &(value), &((*end)), &(spaces)) )
    if (!(spaces > 0)) break;
    if (spaces != 2) {
      CHECK(24, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), spaces, 2) )
    }
    Bool _Bool117;
    CHECK(25, f_is_legal_name(value, NAME_CONSTANT, &(_Bool117)) )
    if (!_Bool117) {
      CHECK(26, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){22, 21, "illegal constant name"}, value) )
    }
    if ((*end) != '\n') {
      CHECK(28, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){40, 39, "expected new-line after Enum value, got"}, (*end)) )
    }
    String* _String118;
    CHECK(30, string_new_copy(value, &(_String118)) )
    CHECK(30, List_add(self->values, _String118) )
  }
  if (!(NULL != self->values->first)) {
    CHECK(32, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){20, 19, "Enum with no values"}) )
  }
  glob->save_input = true;
  CHECK(34, NameMap_add(glob->enum_map, self->name, self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EnumData_m_has_value(EnumData* self, String* value, Bool* has_value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EnumData_m_has_value = "EnumData.m-has-value";
#define MR_FUNC_NAME _func_name_EnumData_m_has_value
Returncode EnumData_m_has_value(EnumData* self, String* value, Bool* has_value) {
  (*has_value) = true;
  Bool _Bool119;
  CHECK(38, String_equal(value, &(String){7, 6, "length"}, &(_Bool119)) )
  if (_Bool119) {
    return OK;
  }
  ListNode* node = self->values->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool120;
    CHECK(43, String_equal(value, node->item, &(_Bool120)) )
    if (_Bool120) {
      return OK;
    }
    node = node->next;
  }
  (*has_value) = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EnumData_write(EnumData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EnumData_write = "EnumData.write";
#define MR_FUNC_NAME _func_name_EnumData_write
Returncode EnumData_write(EnumData* self) {
  CHECK(49, write(&(String){11, 10, "\nenum {\n  "}) )
  ListNode* node = self->values->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(53, write_cname(self->name) )
    CHECK(54, write(&(String){2, 1, "_"}) )
    CHECK(55, write_cname(node->item) )
    if (node == self->values->first) {
      CHECK(57, write(&(String){5, 4, " = 0"}) )
    }
    node = node->next;
    CHECK(59, write(&(String){5, 4, ",\n  "}) )
  }
  CHECK(60, write_cname(self->name) )
  CHECK(61, write(&(String){9, 8, "_length\n"}) )
  CHECK(62, write(&(String){4, 3, "};\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func EnumData__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func EnumData__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)EnumData_write};
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
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
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
