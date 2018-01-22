#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file20_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file20_name

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
/* Expect `expected-text` to be read exactly from the input file *//* Print a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` *//* Same as `m-syntax-error` but but with another `{text} "{item}" pair *//* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair *//* Same as `m-syntax-error` but with a character item */};
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
  {int n; for (n = (1); n < (5); ++n) {
    if ((n) < 0 || (n) >= (glob->access_names)->length) RAISE(17)
    Bool _Bool96;
    CHECK(17, String_equal((&(((String*)((glob->access_names)->values))[n])), access_str, &(_Bool96)) )
    if (_Bool96) {
      (*access) = n;
      return OK;
    }
  }}
  CHECK(20, SyntaxTreeNode_print_syntax_error(self, &(String){15, 14, "illegal access"}, access_str) )
  RAISE(21)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_get_parent_type(SyntaxTreeNode* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_get_parent_type = "SyntaxTreeNode.get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_get_parent_type
Returncode SyntaxTreeNode_get_parent_type(SyntaxTreeNode* self, TypeData** parent_type) {
  (*parent_type) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_find_type = "SyntaxTreeNode.find-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_find_type
Returncode SyntaxTreeNode_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data) {
  CHECK(27, NameMap_find(glob->type_map, name, (void**)&((*type_data))) )
  if (NULL != (*type_data)) {
    return OK;
  }
  TypeData* parent_type = NULL;
  CHECK(30, (self)->_dtl[0](self, &(parent_type)) )
  if (NULL != parent_type &&  NULL !=  parent_type->parameters) {
    ListNode* node = parent_type->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      Bool _Bool97;
      CHECK(34, String_equal(((String*)(node->item)), name, &(_Bool97)) )
      if (_Bool97) {
        (*type_data) = &(glob->type_generic->_base);
        return OK;
      }
      node = node->next;
    }
  }
  CHECK(38, SyntaxTreeNode_print_syntax_error(self, &(String){13, 12, "unknown type"}, name) )
  RAISE(39)
}
#undef MR_FUNC_NAME
#endif/* Expect `expected-text` to be read exactly from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_expect = "SyntaxTreeNode.read-expect";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_read_expect
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text) {
  String* actual_text = _new_string(expected_text->length + 1);
  if (actual_text == NULL) RAISE(43)
  {int n; for (n = (0); n < (expected_text->length); ++n) {
    Char _Char98;
    CHECK(45, read_c(&(_Char98)) )
    CHECK(45, String_append(actual_text, _Char98) )
  }}
  Bool _Bool99;
  CHECK(46, String_equal(actual_text, expected_text, &(_Bool99)) )
  if (!_Bool99) {
    CHECK(47, SyntaxTreeNode_m_syntax_error2(self, &(String){9, 8, "expected"}, expected_text, &(String){4, 3, "got"}, actual_text) )
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
  CHECK(53, (expression)->_base._dtl[2](expression) )
  if (!(NULL != expression->result_type)) {
    CHECK(55, SyntaxTreeNode_m_syntax_error(self, &(String){30, 29, "got void expression, expected"}, expected_type->name) )
  }
  if (expression->result_type->type_data != expected_type) {
    CHECK(58, SyntaxTreeNode_m_syntax_error2(self, &(String){4, 3, "got"}, expression->result_type->type_data->name, &(String){21, 20, "expression, expected"}, expected_type->name) )
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
  CHECK(65, write_int(self->line_number) )
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
  CHECK(68, write(&(String){7, 6, "RAISE("}) )
  CHECK(69, SyntaxTreeNode_write_line_num(self) )
  CHECK(70, write(&(String){3, 2, ")\n"}) )
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
  CHECK(73, write(&(String){7, 6, "CHECK("}) )
  CHECK(74, SyntaxTreeNode_write_line_num(self) )
  CHECK(75, write(&(String){3, 2, ", "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Print a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error = "SyntaxTreeNode.print-syntax-error";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error
Returncode SyntaxTreeNode_print_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(80, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(81, print_msg_with_item(text, item) )
  CHECK(82, print(&(String){2, 1, "\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error = "SyntaxTreeNode.m-syntax-error";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(85, SyntaxTreeNode_print_syntax_error(self, text, item) )
  RAISE(86)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error2 = "SyntaxTreeNode.m-syntax-error2";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error2
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2) {
  CHECK(91, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(92, print_msg_with_item(text1, item1) )
  CHECK(93, print(&(String){2, 1, " "}) )
  CHECK(94, print_msg_with_item(text2, item2) )
  CHECK(95, print(&(String){2, 1, "\n"}) )
  RAISE(96)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error3 = "SyntaxTreeNode.m-syntax-error3";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error3
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3) {
  CHECK(106, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(107, print_msg_with_item(text1, item1) )
  CHECK(108, print(&(String){2, 1, " "}) )
  CHECK(109, print_msg_with_item(text2, item2) )
  CHECK(110, print(&(String){2, 1, " "}) )
  CHECK(111, print_msg_with_item(text3, item3) )
  CHECK(112, print(&(String){2, 1, "\n"}) )
  RAISE(113)
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
    CHECK(119, String_copy(char_str, &(String){4, 3, "EOF"}) )
  }
  else {
    if (item == '\n') {
      CHECK(121, String_copy(char_str, &(String){9, 8, "new-line"}) )
    }
    else {
      CHECK(123, String_append(char_str, item) )
    }
  }
  CHECK(124, SyntaxTreeNode_print_syntax_error(self, text, char_str) )
  RAISE(125)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_msg = "SyntaxTreeNode.m-syntax-error-msg";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_msg
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text) {
  CHECK(128, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(129, print(text) )
  CHECK(130, print(&(String){2, 1, "\n"}) )
  RAISE(131)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error_header = "SyntaxTreeNode.print-syntax-error-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error_header
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self) {
  CHECK(134, print(&(String){15, 14, "Code error in "}) )
  CHECK(135, print(self->input_file_name) )
  CHECK(136, print(&(String){2, 1, "["}) )
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(138, Int_str(self->line_number, line_num_str) )
  CHECK(139, print(line_num_str) )
  CHECK(140, print(&(String){3, 2, "] "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_link_types(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_link_types = "SyntaxTreeNode.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_link_types
Returncode SyntaxTreeNode_link_types(SyntaxTreeNode* self) {
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
  RAISE(149)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_link_children_types(SyntaxTreeNode* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_link_children_types = "SyntaxTreeNode.link-children-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_link_children_types
Returncode SyntaxTreeNode_link_children_types(SyntaxTreeNode* self, List* child_list) {
  NodeLinkTypesAction* action_link_types = &(NodeLinkTypesAction){NodeLinkTypesAction__dtl};
  action_link_types->_base._dtl = NodeLinkTypesAction__dtl;
  CHECK(153, SyntaxTreeNode_do_on_children(self, child_list, &(action_link_types->_base)) )
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
  CHECK(157, SyntaxTreeNode_do_on_children(self, child_list, &(action_analyze->_base)) )
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
  CHECK(161, SyntaxTreeNode_do_on_children(self, child_list, &(action_write->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_do_on_children = "SyntaxTreeNode.do-on-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_do_on_children
Returncode SyntaxTreeNode_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(168, (action)->_dtl[0](action, child->item) )
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
Func SyntaxTreeNode__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write};
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
  RAISE(174)
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
  CHECK(178, (node)->_dtl[1](node) )
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
  CHECK(182, (node)->_dtl[2](node) )
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
  CHECK(186, (node)->_dtl[3](node) )
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
#include "syntax-tree/root.c"
#include "statement/error.c"
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
