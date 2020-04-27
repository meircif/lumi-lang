#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file21_name = "syntax-tree/node.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file21_name

/*  TL4 compiler - Syntax tree basic node types


 */

/* Basic node type for all syntax tree nodes */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeNode SyntaxTreeNode;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct SyntaxTreeNode {
  Func* _dtl;
  String* input_file_name;
  Int line_number;
/* Expect `expected-text` to be read exactly from the input file *//* Print a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` *//* Same as `m-syntax-error` but but with another `{text} "{item}" pair *//* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair *//* Same as `m-syntax-error` but with a character item *//* Check `text` is a string constant */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_set_location = "SyntaxTreeNode.set-location";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_set_location
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self) {
  self->input_file_name = glob->input_file_name;
  self->line_number = glob->line_number;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_read_line_break_spaces(SyntaxTreeNode* self, Int indentation_spaces);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_line_break_spaces = "SyntaxTreeNode.read-line-break-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_read_line_break_spaces
Returncode SyntaxTreeNode_read_line_break_spaces(SyntaxTreeNode* self, Int indentation_spaces) {
  Int expected_spaces = indentation_spaces + 8;
  {int n; for (n = (0); n < (expected_spaces); ++n) {
    Char _Char110;
    CHECK(18, read_c(&(_Char110)) )
    if (_Char110 != ' ') {
      CHECK(19, SyntaxTreeNode_m_syntax_error_indentation(self, n, expected_spaces) )
    }
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_get_access = "SyntaxTreeNode.get-access";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_get_access
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access) {
  {int n; for (n = (1); n < (5); ++n) {
    if ((n) < 0 || (n) >= (glob->access_names)->length) RAISE(23)
    Bool _Bool111;
    CHECK(23, String_equal((&(((String*)((glob->access_names)->values))[n])), access_str, &(_Bool111)) )
    if (_Bool111) {
      (*access) = n;
      return OK;
    }
  }}
  CHECK(26, SyntaxTreeNode_print_syntax_error(self, &(String){15, 14, "illegal access"}, access_str) )
  RAISE(27)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_get_parent_type(SyntaxTreeNode* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_get_parent_type = "SyntaxTreeNode.get-parent-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_get_parent_type
Returncode SyntaxTreeNode_get_parent_type(SyntaxTreeNode* self, TypeData** parent_type) {
  (*parent_type) = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_find_module(SyntaxTreeNode* self, String* name, ModuleMembers** module_members);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_find_module = "SyntaxTreeNode.find-module";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_find_module
Returncode SyntaxTreeNode_find_module(SyntaxTreeNode* self, String* name, ModuleMembers** module_members) {
  CHECK(33, NameMap_find(glob->module_map, name, (void**)&((*module_members))) )
  if (!(NULL != (*module_members))) {
    CHECK(34, SyntaxTreeNode_m_syntax_error(self, &(String){15, 14, "unknown module"}, name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_find_type(SyntaxTreeNode* self, String* name, String* module_name, TypeData** type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_find_type = "SyntaxTreeNode.find-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_find_type
Returncode SyntaxTreeNode_find_type(SyntaxTreeNode* self, String* name, String* module_name, TypeData** type_data) {
  if (NULL != module_name) {
    ModuleMembers* _ModuleMembers112;
    CHECK(39, SyntaxTreeNode_find_module(self, module_name, &(_ModuleMembers112)) )
    CHECK(39, NameMap_find(_ModuleMembers112->type_map, name, (void**)&((*type_data))) )
    if (NULL != (*type_data)) {
      return OK;
    }
    CHECK(42, SyntaxTreeNode_m_syntax_error2(self, &(String){13, 12, "unknown type"}, name, &(String){10, 9, "in module"}, module_name) )
  }
  CHECK(44, Global_find_type(glob, name, &((*type_data))) )
  if (NULL != (*type_data)) {
    return OK;
  }
  TypeData* parent_type = NULL;
  CHECK(47, (self)->_dtl[0](self, &(parent_type)) )
  if (NULL != parent_type &&  NULL !=  parent_type->parameters) {
    ListNode* node = parent_type->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      Bool _Bool113;
      CHECK(51, String_equal(((String*)(node->item)), name, &(_Bool113)) )
      if (_Bool113) {
        (*type_data) = glob->type_generic;
        return OK;
      }
      node = node->next;
    }
  }
  CHECK(55, SyntaxTreeNode_print_syntax_error(self, &(String){13, 12, "unknown type"}, name) )
  RAISE(56)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_find_variable(SyntaxTreeNode* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_find_variable = "SyntaxTreeNode.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_find_variable
Returncode SyntaxTreeNode_find_variable(SyntaxTreeNode* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  if (NULL != module_name) {
    ModuleMembers* _ModuleMembers114;
    CHECK(61, SyntaxTreeNode_find_module(self, module_name, &(_ModuleMembers114)) )
    CHECK(61, NameMap_find(_ModuleMembers114->variable_map, name, (void**)&((*variable))) )
  }
  else {
    CHECK(64, Global_find_variable(glob, name, &((*variable))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_find_function(SyntaxTreeNode* self, String* name, String* module_name, SyntaxTreeFunction** function);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_find_function = "SyntaxTreeNode.find-function";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_find_function
Returncode SyntaxTreeNode_find_function(SyntaxTreeNode* self, String* name, String* module_name, SyntaxTreeFunction** function) {
  if (NULL != module_name) {
    ModuleMembers* _ModuleMembers115;
    CHECK(69, SyntaxTreeNode_find_module(self, module_name, &(_ModuleMembers115)) )
    CHECK(69, NameMap_find(_ModuleMembers115->function_map, name, (void**)&((*function))) )
  }
  else {
    CHECK(72, Global_find_function(glob, name, &((*function))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Expect `expected-text` to be read exactly from the input file */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_expect = "SyntaxTreeNode.read-expect";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_read_expect
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text) {
  String* actual_text = _new_string(expected_text->length + 1);
  if (actual_text == NULL) RAISE(76)
  {int n; for (n = (0); n < (expected_text->length); ++n) {
    Char _Char116;
    CHECK(78, read_c(&(_Char116)) )
    CHECK(78, String_append(actual_text, _Char116) )
  }}
  Bool _Bool117;
  CHECK(79, String_equal(actual_text, expected_text, &(_Bool117)) )
  if (!_Bool117) {
    CHECK(80, SyntaxTreeNode_m_syntax_error2(self, &(String){9, 8, "expected"}, expected_text, &(String){4, 3, "got"}, actual_text) )
  }
  free(actual_text);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_analyze_expression(SyntaxTreeNode* self, Expression* expression, TypeData* expected_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze_expression = "SyntaxTreeNode.analyze-expression";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_analyze_expression
Returncode SyntaxTreeNode_analyze_expression(SyntaxTreeNode* self, Expression* expression, TypeData* expected_type) {
  CHECK(86, (expression)->_base._dtl[2](expression) )
  if (!(NULL != expression->result_type)) {
    CHECK(88, SyntaxTreeNode_m_syntax_error(self, &(String){30, 29, "got void expression, expected"}, expected_type->name) )
  }
  if (expression->result_type->type_data != expected_type) {
    CHECK(91, SyntaxTreeNode_m_syntax_error2(self, &(String){4, 3, "got"}, expression->result_type->type_data->name, &(String){21, 20, "expression, expected"}, expected_type->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_line_num = "SyntaxTreeNode.write-line-num";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_write_line_num
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self) {
  CHECK(98, write_int(self->line_number) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self, String* error_message);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_raise = "SyntaxTreeNode.write-raise";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_write_raise
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self, String* error_message) {
  CHECK(101, write(&(String){7, 6, "RAISE("}) )
  CHECK(102, SyntaxTreeNode_write_line_num(self) )
  CHECK(103, write(&(String){3, 2, ", "}) )
  CHECK(104, write(error_message) )
  CHECK(105, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Print a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error = "SyntaxTreeNode.print-syntax-error";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error
Returncode SyntaxTreeNode_print_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(110, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(111, print_msg_with_item(text, item) )
  CHECK(112, print(&(String){2, 1, "\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error = "SyntaxTreeNode.m-syntax-error";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(115, SyntaxTreeNode_print_syntax_error(self, text, item) )
  RAISE(116)
}
#undef LUMI_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another `{text} "{item}" pair */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error2 = "SyntaxTreeNode.m-syntax-error2";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error2
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2) {
  CHECK(121, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(122, print_msg_with_item(text1, item1) )
  CHECK(123, print(&(String){2, 1, " "}) )
  CHECK(124, print_msg_with_item(text2, item2) )
  CHECK(125, print(&(String){2, 1, "\n"}) )
  RAISE(126)
}
#undef LUMI_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error3 = "SyntaxTreeNode.m-syntax-error3";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error3
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3) {
  CHECK(136, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(137, print_msg_with_item(text1, item1) )
  CHECK(138, print(&(String){2, 1, " "}) )
  CHECK(139, print_msg_with_item(text2, item2) )
  CHECK(140, print(&(String){2, 1, " "}) )
  CHECK(141, print_msg_with_item(text3, item3) )
  CHECK(142, print(&(String){2, 1, "\n"}) )
  RAISE(143)
}
#undef LUMI_FUNC_NAME
#endif/* Same as `m-syntax-error` but with a character item */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_c = "SyntaxTreeNode.m-syntax-error-c";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_c
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item) {
  String* char_str = &(String){16, 0, (char[16]){0}};
  if (item == 127) {
    CHECK(149, String_copy(char_str, &(String){4, 3, "EOF"}) )
  }
  else {
    if (item == '\n') {
      CHECK(151, String_copy(char_str, &(String){9, 8, "new-line"}) )
    }
    else {
      CHECK(153, String_append(char_str, item) )
    }
  }
  CHECK(154, SyntaxTreeNode_print_syntax_error(self, text, char_str) )
  RAISE(155)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_msg = "SyntaxTreeNode.m-syntax-error-msg";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_msg
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text) {
  CHECK(158, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(159, print(text) )
  CHECK(160, print(&(String){2, 1, "\n"}) )
  RAISE(161)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_indentation(SyntaxTreeNode* self, Int actual, Int expected);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_indentation = "SyntaxTreeNode.m-syntax-error-indentation";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_indentation
Returncode SyntaxTreeNode_m_syntax_error_indentation(SyntaxTreeNode* self, Int actual, Int expected) {
  String* expected_str = &(String){16, 0, (char[16]){0}};
  String* actual_str = &(String){16, 0, (char[16]){0}};
  CHECK(166, Int_str(expected, expected_str) )
  CHECK(167, Int_str(actual, actual_str) )
  CHECK(168, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(169, print(&(String){17, 16, "indentation too "}) )
  if (actual < expected) {
    CHECK(171, print(&(String){6, 5, "short"}) )
  }
  else {
    CHECK(173, print(&(String){5, 4, "long"}) )
  }
  CHECK(174, print(&(String){12, 11, ", expected "}) )
  CHECK(175, print(expected_str) )
  CHECK(176, print(&(String){6, 5, " got "}) )
  CHECK(177, print(actual_str) )
  CHECK(178, print(&(String){2, 1, "\n"}) )
  RAISE(179)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error_header = "SyntaxTreeNode.print-syntax-error-header";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error_header
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self) {
  CHECK(182, print(&(String){15, 14, "Code error in "}) )
  CHECK(183, print(self->input_file_name) )
  CHECK(184, print(&(String){2, 1, "["}) )
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(186, Int_str(self->line_number, line_num_str) )
  CHECK(187, print(line_num_str) )
  CHECK(188, print(&(String){3, 2, "] "}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Check `text` is a string constant */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_check_string(SyntaxTreeNode* self, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_check_string = "SyntaxTreeNode.check-string";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_check_string
Returncode SyntaxTreeNode_check_string(SyntaxTreeNode* self, String* text) {
  if (text->length < 2) {
    CHECK(193, SyntaxTreeNode_m_syntax_error(self, &(String){26, 25, "too short string constant"}, text) )
  }
  if ((0) < 0 || (0) >= (text)->length) RAISE(194)
  if ((text->length - 1) < 0 || (text->length - 1) >= (text)->length) RAISE(194)
  if (((text)->values[0]) != '\"' || ((text)->values[text->length - 1]) != '\"') {
    CHECK(195, SyntaxTreeNode_m_syntax_error(self, &(String){30, 29, "no '\"' around string constant"}, text) )
  }
  Char prev = '\0';
  {int n; for (n = (1); n < (text->length - 1); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(198)
    Char curr = ((text)->values[n]);
    if (curr == '"' && prev != '\\') {
      CHECK(200, SyntaxTreeNode_m_syntax_error(self, &(String){27, 26, "'\"' inside string constant"}, text) )
    }
    prev = curr;
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_link_types(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_link_types = "SyntaxTreeNode.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_link_types
Returncode SyntaxTreeNode_link_types(SyntaxTreeNode* self) {
  /* do nothing as default */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze = "SyntaxTreeNode.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_analyze
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self) {
  /* do nothing as default */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_order_constants(SyntaxTreeNode* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_order_constants = "SyntaxTreeNode.m-order-constants";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_order_constants
Returncode SyntaxTreeNode_m_order_constants(SyntaxTreeNode* self, List* ordered_list) {
  /* do nothing as default */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write = "SyntaxTreeNode.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_write
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self) {
  RAISE(213)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_link_children_types(SyntaxTreeNode* self, List* child_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_link_children_types = "SyntaxTreeNode.link-children-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_link_children_types
Returncode SyntaxTreeNode_link_children_types(SyntaxTreeNode* self, List* child_list) {
  NodeLinkTypesAction* action_link_types = &(NodeLinkTypesAction){NodeLinkTypesAction__dtl};
  action_link_types->_base._dtl = NodeLinkTypesAction__dtl;
  CHECK(217, SyntaxTreeNode_do_on_children(self, child_list, &(action_link_types->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_analyze_children(SyntaxTreeNode* self, List* child_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze_children = "SyntaxTreeNode.analyze-children";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_analyze_children
Returncode SyntaxTreeNode_analyze_children(SyntaxTreeNode* self, List* child_list) {
  NodeAnalyzeAction* action_analyze = &(NodeAnalyzeAction){NodeAnalyzeAction__dtl};
  action_analyze->_base._dtl = NodeAnalyzeAction__dtl;
  CHECK(221, SyntaxTreeNode_do_on_children(self, child_list, &(action_analyze->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_m_order_children_constants(SyntaxTreeNode* self, List* child_list, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_order_children_constants = "SyntaxTreeNode.m-order-children-constants";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_m_order_children_constants
Returncode SyntaxTreeNode_m_order_children_constants(SyntaxTreeNode* self, List* child_list, List* ordered_list) {
  NodeOrderConstantsAction* action_order_constants = &(NodeOrderConstantsAction){NodeOrderConstantsAction__dtl, NULL};
  action_order_constants->_base._dtl = NodeOrderConstantsAction__dtl;
  action_order_constants->ordered_list = ordered_list;
  CHECK(228, SyntaxTreeNode_do_on_children(self, child_list, &(action_order_constants->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_write_children(SyntaxTreeNode* self, List* child_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_children = "SyntaxTreeNode.write-children";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_write_children
Returncode SyntaxTreeNode_write_children(SyntaxTreeNode* self, List* child_list) {
  NodeWriteAction* action_write = &(NodeWriteAction){NodeWriteAction__dtl};
  action_write->_base._dtl = NodeWriteAction__dtl;
  CHECK(232, SyntaxTreeNode_do_on_children(self, child_list, &(action_write->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNode_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNode_do_on_children = "SyntaxTreeNode.do-on-children";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNode_do_on_children
Returncode SyntaxTreeNode_do_on_children(SyntaxTreeNode* self, List* child_list, NodeAction* action) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    glob->input_file_name = ((SyntaxTreeNode*)(child->item))->input_file_name;
    glob->line_number = ((SyntaxTreeNode*)(child->item))->line_number;
    CHECK(241, (action)->_dtl[0](action, child->item) )
    child = child->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeNode__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeNode__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NodeAction NodeAction;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct NodeAction {
  Func* _dtl;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NodeAction_m_action(NodeAction* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NodeAction_m_action = "NodeAction.m-action";
#define LUMI_FUNC_NAME _func_name_NodeAction_m_action
Returncode NodeAction_m_action(NodeAction* self, SyntaxTreeNode* node) {
  RAISE(247)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func NodeAction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func NodeAction__dtl[] = {(void*)NodeAction_m_action};
#endif

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NodeLinkTypesAction NodeLinkTypesAction;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct NodeLinkTypesAction {
  NodeAction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NodeLinkTypesAction_m_action(NodeLinkTypesAction* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NodeLinkTypesAction_m_action = "NodeLinkTypesAction.m-action";
#define LUMI_FUNC_NAME _func_name_NodeLinkTypesAction_m_action
Returncode NodeLinkTypesAction_m_action(NodeLinkTypesAction* self, SyntaxTreeNode* node) {
  CHECK(251, (node)->_dtl[1](node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func NodeLinkTypesAction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func NodeLinkTypesAction__dtl[] = {(void*)NodeLinkTypesAction_m_action};
#endif

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NodeAnalyzeAction NodeAnalyzeAction;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct NodeAnalyzeAction {
  NodeAction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NodeAnalyzeAction_m_action(NodeAnalyzeAction* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NodeAnalyzeAction_m_action = "NodeAnalyzeAction.m-action";
#define LUMI_FUNC_NAME _func_name_NodeAnalyzeAction_m_action
Returncode NodeAnalyzeAction_m_action(NodeAnalyzeAction* self, SyntaxTreeNode* node) {
  CHECK(255, (node)->_dtl[2](node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func NodeAnalyzeAction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func NodeAnalyzeAction__dtl[] = {(void*)NodeAnalyzeAction_m_action};
#endif

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NodeWriteAction NodeWriteAction;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct NodeWriteAction {
  NodeAction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NodeWriteAction_m_action(NodeWriteAction* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NodeWriteAction_m_action = "NodeWriteAction.m-action";
#define LUMI_FUNC_NAME _func_name_NodeWriteAction_m_action
Returncode NodeWriteAction_m_action(NodeWriteAction* self, SyntaxTreeNode* node) {
  CHECK(259, (node)->_dtl[4](node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func NodeWriteAction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func NodeWriteAction__dtl[] = {(void*)NodeWriteAction_m_action};
#endif

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NodeOrderConstantsAction NodeOrderConstantsAction;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct NodeOrderConstantsAction {
  NodeAction _base;
  List* ordered_list;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NodeOrderConstantsAction_m_action(NodeOrderConstantsAction* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NodeOrderConstantsAction_m_action = "NodeOrderConstantsAction.m-action";
#define LUMI_FUNC_NAME _func_name_NodeOrderConstantsAction_m_action
Returncode NodeOrderConstantsAction_m_action(NodeOrderConstantsAction* self, SyntaxTreeNode* node) {
  CHECK(265, (node)->_dtl[3](node, self->ordered_list) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func NodeOrderConstantsAction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func NodeOrderConstantsAction__dtl[] = {(void*)NodeOrderConstantsAction_m_action};
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/code.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
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
