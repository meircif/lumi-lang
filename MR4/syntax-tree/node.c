#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file18_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file18_name

/*  MR4 compiler - Syntax tree basic node types


 */

/* Basic node type for all syntax tree nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNode SyntaxTreeNode;
#elif MR_STAGE == MR_TYPES(0)
struct SyntaxTreeNode {
  Func* _dtl;
  String* input_file_name;
  Int line_number;
/* Expect `expected-text` to be read exaclty from the input file *//* Raise a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` *//* Same as `m-syntax-error` but but with another `{text} "{item}" pair *//* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair *//* Same as `m-syntax-error` but with a character item */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_set_location = "SyntaxTreeNode.set-location";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_set_location
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self) {
  self->input_file_name = glob->input_file_name;
  self->line_number = glob->line_number;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_get_access = "SyntaxTreeNode.get-access";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_get_access
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access) {
  {int n; for (n = (0); n < (4); ++n) {
    if ((n) < 0 || (n) >= (glob->access_names)->length) RAISE(17)
    Bool _Bool85;
    CHECK(17, String_equal((&(((String*)((glob->access_names)->values))[n])), access_str, &(_Bool85)) )
    if (_Bool85) {
      (*access) = n;
      return OK;
    }
  }}
  CHECK(20, SyntaxTreeNode_m_syntax_error(self, &(String){15, 14, "illegal access"}, access_str) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_find_type = "SyntaxTreeNode.m-find-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_find_type
Returncode SyntaxTreeNode_m_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data) {
  CHECK(23, NameMap_find(glob->type_map, name, (void**)&((*type_data))) )
  if (!(NULL != (*type_data))) {
    CHECK(24, SyntaxTreeNode_m_syntax_error(self, &(String){13, 12, "unknown type"}, name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Expect `expected-text` to be read exaclty from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_expect = "SyntaxTreeNode.read-expect";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_read_expect
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text) {
  String* actual_text = _new_string(expected_text->length + 1);
  if (actual_text == NULL) RAISE(28)
  {int n; for (n = (0); n < (expected_text->length); ++n) {
    Char _Char86;
    CHECK(30, read_c(&(_Char86)) )
    CHECK(30, String_append(actual_text, _Char86) )
  }}
  Bool _Bool87;
  CHECK(31, String_equal(actual_text, expected_text, &(_Bool87)) )
  if (!_Bool87) {
    CHECK(32, SyntaxTreeNode_m_syntax_error2(self, &(String){9, 8, "expected"}, expected_text, &(String){4, 3, "got"}, actual_text) )
  }
  free(actual_text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_analyze_expression(SyntaxTreeNode* self, Expression* expression, TypeData* expected_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze_expression = "SyntaxTreeNode.analyze-expression";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_analyze_expression
Returncode SyntaxTreeNode_analyze_expression(SyntaxTreeNode* self, Expression* expression, TypeData* expected_type) {
  CHECK(38, (expression)->_base._dtl[1](expression) )
  if (!(NULL != expression->result_type)) {
    CHECK(40, SyntaxTreeNode_m_syntax_error(self, &(String){30, 29, "got void expression, expected"}, expected_type->name) )
  }
  if (expression->result_type->type_data != expected_type) {
    CHECK(43, SyntaxTreeNode_m_syntax_error2(self, &(String){4, 3, "got"}, expression->result_type->type_data->name, &(String){21, 20, "expression, expected"}, expected_type->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_line_num = "SyntaxTreeNode.write-line-num";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_line_num
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self) {
  CHECK(50, write_int(self->line_number) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_raise = "SyntaxTreeNode.write-raise";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_raise
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self) {
  CHECK(53, write(&(String){7, 6, "RAISE("}) )
  CHECK(54, SyntaxTreeNode_write_line_num(self) )
  CHECK(55, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_call(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_call = "SyntaxTreeNode.write-call";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_call
Returncode SyntaxTreeNode_write_call(SyntaxTreeNode* self) {
  CHECK(58, write(&(String){7, 6, "CHECK("}) )
  CHECK(59, SyntaxTreeNode_write_line_num(self) )
  CHECK(60, write(&(String){3, 2, ", "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Raise a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error = "SyntaxTreeNode.m-syntax-error";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(65, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(66, print_msg_with_item(text, item) )
  CHECK(67, print(&(String){2, 1, "\n"}) )
  RAISE(68)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error2 = "SyntaxTreeNode.m-syntax-error2";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error2
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2) {
  CHECK(73, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(74, print_msg_with_item(text1, item1) )
  CHECK(75, print(&(String){2, 1, " "}) )
  CHECK(76, print_msg_with_item(text2, item2) )
  CHECK(77, print(&(String){2, 1, "\n"}) )
  RAISE(78)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error3 = "SyntaxTreeNode.m-syntax-error3";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error3
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3) {
  CHECK(88, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(89, print_msg_with_item(text1, item1) )
  CHECK(90, print(&(String){2, 1, " "}) )
  CHECK(91, print_msg_with_item(text2, item2) )
  CHECK(92, print(&(String){2, 1, " "}) )
  CHECK(93, print_msg_with_item(text3, item3) )
  CHECK(94, print(&(String){2, 1, "\n"}) )
  RAISE(95)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but with a character item */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_c = "SyntaxTreeNode.m-syntax-error-c";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_c
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item) {
  String* char_str = &(String){16, 0, (char[16]){0}};
  if (item == EOF) {
    CHECK(101, String_copy(char_str, &(String){4, 3, "EOF"}) )
  }
  else {
    if (item == '\n') {
      CHECK(103, String_copy(char_str, &(String){9, 8, "new-line"}) )
    }
    else {
      CHECK(105, String_append(char_str, item) )
    }
  }
  CHECK(106, SyntaxTreeNode_m_syntax_error(self, text, char_str) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_msg = "SyntaxTreeNode.m-syntax-error-msg";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_msg
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text) {
  CHECK(109, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(110, print(text) )
  CHECK(111, print(&(String){2, 1, "\n"}) )
  RAISE(112)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error_header = "SyntaxTreeNode.print-syntax-error-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error_header
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self) {
  CHECK(115, print(&(String){15, 14, "Code error in "}) )
  CHECK(116, print(self->input_file_name) )
  CHECK(117, print(&(String){2, 1, "["}) )
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(119, Int_str(self->line_number, line_num_str) )
  CHECK(120, print(line_num_str) )
  CHECK(121, print(&(String){3, 2, "] "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_link_types(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_link_types = "SyntaxTreeNode.m-link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_link_types
Returncode SyntaxTreeNode_m_link_types(SyntaxTreeNode* self) {
  /* do nothing as default */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze = "SyntaxTreeNode.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_analyze
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self) {
  /* do nothing as default */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write = "SyntaxTreeNode.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self) {
  RAISE(130)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_link_children_types(SyntaxTreeNode* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_link_children_types = "SyntaxTreeNode.m-link-children-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_link_children_types
Returncode SyntaxTreeNode_m_link_children_types(SyntaxTreeNode* self, List* child_list) {
  NodeLinkTypesAction* action_link_types = &(NodeLinkTypesAction){NodeLinkTypesAction__dtl};
  action_link_types->_base._dtl = NodeLinkTypesAction__dtl;
  CHECK(134, SyntaxTreeNode_m_do_on_children(self, child_list, &(action_link_types->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_analyze_children(SyntaxTreeNode* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze_children = "SyntaxTreeNode.analyze-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_analyze_children
Returncode SyntaxTreeNode_analyze_children(SyntaxTreeNode* self, List* child_list) {
  NodeAnalyzeAction* action_analyze = &(NodeAnalyzeAction){NodeAnalyzeAction__dtl};
  action_analyze->_base._dtl = NodeAnalyzeAction__dtl;
  CHECK(138, SyntaxTreeNode_m_do_on_children(self, child_list, &(action_analyze->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_children(SyntaxTreeNode* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_children = "SyntaxTreeNode.write-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_children
Returncode SyntaxTreeNode_write_children(SyntaxTreeNode* self, List* child_list) {
  NodeWriteAction* action_write = &(NodeWriteAction){NodeWriteAction__dtl};
  action_write->_base._dtl = NodeWriteAction__dtl;
  CHECK(142, SyntaxTreeNode_m_do_on_children(self, child_list, &(action_write->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_do_on_children = "SyntaxTreeNode.m-do-on-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_do_on_children
Returncode SyntaxTreeNode_m_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(149, (action)->_dtl[0](action, child->item) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNode__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct NodeAction NodeAction;
#elif MR_STAGE == MR_TYPES(0)
struct NodeAction {
  Func* _dtl;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NodeAction_m_action(NodeAction* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NodeAction_m_action = "NodeAction.m-action";
#define MR_FUNC_NAME _func_name_NodeAction_m_action
Returncode NodeAction_m_action(NodeAction* self, SyntaxTreeNode* node) {
  RAISE(155)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NodeAction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NodeAction__dtl[] = {(void*)NodeAction_m_action};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct NodeLinkTypesAction NodeLinkTypesAction;
#elif MR_STAGE == MR_TYPES(1)
struct NodeLinkTypesAction {
  NodeAction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NodeLinkTypesAction_m_action(NodeLinkTypesAction* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NodeLinkTypesAction_m_action = "NodeLinkTypesAction.m-action";
#define MR_FUNC_NAME _func_name_NodeLinkTypesAction_m_action
Returncode NodeLinkTypesAction_m_action(NodeLinkTypesAction* self, SyntaxTreeNode* node) {
  CHECK(159, (node)->_dtl[0](node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NodeLinkTypesAction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NodeLinkTypesAction__dtl[] = {(void*)NodeLinkTypesAction_m_action};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct NodeAnalyzeAction NodeAnalyzeAction;
#elif MR_STAGE == MR_TYPES(1)
struct NodeAnalyzeAction {
  NodeAction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NodeAnalyzeAction_m_action(NodeAnalyzeAction* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NodeAnalyzeAction_m_action = "NodeAnalyzeAction.m-action";
#define MR_FUNC_NAME _func_name_NodeAnalyzeAction_m_action
Returncode NodeAnalyzeAction_m_action(NodeAnalyzeAction* self, SyntaxTreeNode* node) {
  CHECK(163, (node)->_dtl[1](node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NodeAnalyzeAction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NodeAnalyzeAction__dtl[] = {(void*)NodeAnalyzeAction_m_action};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct NodeWriteAction NodeWriteAction;
#elif MR_STAGE == MR_TYPES(1)
struct NodeWriteAction {
  NodeAction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NodeWriteAction_m_action(NodeWriteAction* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NodeWriteAction_m_action = "NodeWriteAction.m-action";
#define MR_FUNC_NAME _func_name_NodeWriteAction_m_action
Returncode NodeWriteAction_m_action(NodeWriteAction* self, SyntaxTreeNode* node) {
  CHECK(167, (node)->_dtl[2](node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func NodeWriteAction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func NodeWriteAction__dtl[] = {(void*)NodeWriteAction_m_action};
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
