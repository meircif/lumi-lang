#ifndef MR_MAINFILE
#define MR_MAINFILE "global/argument.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file1_name = "global/argument.3.mr";
#endif
#define MR_FILE_NAME _mr_file1_name

/* MR4 compiler - Function arguments */


/* Basic function argument */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Argument Argument;
#elif MR_STAGE == MR_TYPES(1)
struct Argument {
  SyntaxTreeNode _base;
  Int access;
  Bool is_output;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_m_copy_new(Argument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_m_copy_new = "Argument.m-copy-new";
#define MR_FUNC_NAME _func_name_Argument_m_copy_new
Returncode Argument_m_copy_new(Argument* self, DeclarationArgument** new_argument) {
  RAISE(10)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_parse(Argument* self, String* access_str, Bool is_output, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse = "Argument.parse";
#define MR_FUNC_NAME _func_name_Argument_parse
Returncode Argument_parse(Argument* self, String* access_str, Bool is_output, SyntaxTreeCode* code_node, Char* end) {
  self->is_output = is_output;
  CHECK(18, SyntaxTreeNode_set_location(&(self->_base)) )
  CHECK(19, SyntaxTreeNode_get_access(&(self->_base), access_str, &(self->access)) )
  CHECK(20, (self)->_base._dtl[4](self, code_node, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_parse_value(Argument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse_value = "Argument.parse-value";
#define MR_FUNC_NAME _func_name_Argument_parse_value
Returncode Argument_parse_value(Argument* self, SyntaxTreeCode* code_node, Char* end) {
  RAISE(23)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_type_instance = "Argument.get-type-instance";
#define MR_FUNC_NAME _func_name_Argument_get_type_instance
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance) {
  RAISE(26)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_m_check_calling(Argument* self, TypeInstance* type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_m_check_calling = "Argument.m-check-calling";
#define MR_FUNC_NAME _func_name_Argument_m_check_calling
Returncode Argument_m_check_calling(Argument* self, TypeInstance* type_instance) {
  RAISE(29)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_variable = "Argument.get-variable";
#define MR_FUNC_NAME _func_name_Argument_get_variable
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable) {
  RAISE(32)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_output(Argument* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_output = "Argument.get-output";
#define MR_FUNC_NAME _func_name_Argument_get_output
Returncode Argument_get_output(Argument* self, Expression** output) {
  RAISE(35)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write_preactions(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write_preactions = "Argument.write-preactions";
#define MR_FUNC_NAME _func_name_Argument_write_preactions
Returncode Argument_write_preactions(Argument* self) {
  RAISE(38)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Argument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Argument__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)Argument_m_copy_new, (void*)Argument_parse_value, (void*)Argument_get_type_instance, (void*)Argument_m_check_calling, (void*)Argument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct ArgumentFactory ArgumentFactory;
#elif MR_STAGE == MR_TYPES(0)
struct ArgumentFactory {
  Func* _dtl;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode ArgumentFactory_m_new_argument(ArgumentFactory* self, Argument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_ArgumentFactory_m_new_argument = "ArgumentFactory.m-new-argument";
#define MR_FUNC_NAME _func_name_ArgumentFactory_m_new_argument
Returncode ArgumentFactory_m_new_argument(ArgumentFactory* self, Argument** new_argument) {
  RAISE(43)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func ArgumentFactory__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func ArgumentFactory__dtl[] = {(void*)ArgumentFactory_m_new_argument};
#endif


/* All function parameters and outputs */
#if MR_STAGE == MR_TYPEDEFS
typedef struct FunctionArguments FunctionArguments;
#elif MR_STAGE == MR_TYPES(1)
struct FunctionArguments {
  SyntaxTreeNode _base;
  List* parameters;
  List* outputs;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_copy_new(FunctionArguments* self, FunctionArguments** new_arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_copy_new = "FunctionArguments.m-copy-new";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_copy_new
Returncode FunctionArguments_m_copy_new(FunctionArguments* self, FunctionArguments** new_arguments) {
  (*new_arguments) = malloc(sizeof(FunctionArguments));
  if ((*new_arguments) == NULL) RAISE(52)
  *(*new_arguments) = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  (*new_arguments)->_base._dtl = FunctionArguments__dtl;
  CHECK(53, FunctionArguments_init((*new_arguments)) )
  CHECK(54, FunctionArguments_m_copy_new_args(self, self->parameters, (*new_arguments)->parameters) )
  CHECK(55, FunctionArguments_m_copy_new_args(self, self->outputs, (*new_arguments)->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_copy_new_args(FunctionArguments* self, List* arguments, List* new_arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_copy_new_args = "FunctionArguments.m-copy-new-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_copy_new_args
Returncode FunctionArguments_m_copy_new_args(FunctionArguments* self, List* arguments, List* new_arguments) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    DeclarationArgument* _DeclarationArgument0;
    CHECK(62, (((Argument*)(node->item)))->_base._dtl[3](((Argument*)(node->item)), &(_DeclarationArgument0)) )
    CHECK(62, List_add(new_arguments, &(_DeclarationArgument0->_base)) )
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_init(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_init = "FunctionArguments.init";
#define MR_FUNC_NAME _func_name_FunctionArguments_init
Returncode FunctionArguments_init(FunctionArguments* self) {
  CHECK(66, SyntaxTreeNode_set_location(&(self->_base)) )
  self->parameters = malloc(sizeof(List));
  if (self->parameters == NULL) RAISE(67)
  *self->parameters = (List){NULL, NULL};
  self->outputs = malloc(sizeof(List));
  if (self->outputs == NULL) RAISE(68)
  *self->outputs = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, SyntaxTreeCode* code_node, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse = "FunctionArguments.parse";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, SyntaxTreeCode* code_node, TypeData* parent_type, Char* end) {
  CHECK(75, FunctionArguments_init(self) )
  if (NULL != parent_type) {
    DeclarationArgument* self_args = malloc(sizeof(DeclarationArgument));
    if (self_args == NULL) RAISE(77)
    *self_args = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
    self_args->_base._base._dtl = DeclarationArgument__dtl;
    self_args->_base.access = ACCESS_VAR;
    self_args->variable = malloc(sizeof(SyntaxTreeVariable));
    if (self_args->variable == NULL) RAISE(79)
    *self_args->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
    self_args->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
    CHECK(80, string_new_copy(&(String){5, 4, "self"}, &(self_args->variable->name)) )
    CHECK(81, TypeData_m_new_type_instance(parent_type, &(self_args->variable->type_instance)) )
    CHECK(82, List_add(self->parameters, &(self_args->_base)) )
  }
  CHECK(83, FunctionArguments_parse_args(self, self->parameters, argument_factory, code_node, &((*end))) )
  if ((*end) == '-') {
    CHECK(86, SyntaxTreeNode_read_expect(&(self->_base), &(String){3, 2, ">("}) )
    CHECK(87, FunctionArguments_parse_args(self, self->outputs, argument_factory, code_node, &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse_args = "FunctionArguments.parse-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse_args
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, SyntaxTreeCode* code_node, Char* end) {
  Argument* argument = NULL;
  String* access_str = NULL;
  Bool is_output = arguments == self->outputs;
  Int _Int1;
  CHECK(98, read_until(&(String){3, 2, " )"}, false, &(access_str), &((*end)), &(_Int1)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(100, SyntaxTreeCode_read_line_break_spaces(code_node) )
    Int _Int2;
    CHECK(101, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int2)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(105, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(107, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){33, 32, "expected space after access, got"}, (*end)) )
      }
      CHECK(109, (argument_factory)->_dtl[0](argument_factory, &(argument)) )
      CHECK(110, List_add(arguments, argument) )
      CHECK(111, Argument_parse(argument, access_str, is_output, code_node, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(114, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(116, SyntaxTreeCode_read_line_break_spaces(code_node) )
      }
      else {
        if ((*end) != ' ') {
          CHECK(118, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){42, 41, "expected space or new-line after \",\", got"}, (*end)) )
        }
      }
      Int _Int3;
      CHECK(121, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int3)) )
    }
  }
  CHECK(122, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_link_types(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_link_types = "FunctionArguments.m-link-types";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_link_types
Returncode FunctionArguments_m_link_types(FunctionArguments* self) {
  CHECK(125, SyntaxTreeNode_m_link_children_types(&(self->_base), self->parameters) )
  CHECK(126, SyntaxTreeNode_m_link_children_types(&(self->_base), self->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_analyze(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_analyze = "FunctionArguments.analyze";
#define MR_FUNC_NAME _func_name_FunctionArguments_analyze
Returncode FunctionArguments_analyze(FunctionArguments* self) {
  CHECK(129, SyntaxTreeNode_analyze_children(&(self->_base), self->parameters) )
  CHECK(130, SyntaxTreeNode_analyze_children(&(self->_base), self->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_get_result_type(FunctionArguments* self, TypeInstance** result_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_get_result_type = "FunctionArguments.get-result-type";
#define MR_FUNC_NAME _func_name_FunctionArguments_get_result_type
Returncode FunctionArguments_get_result_type(FunctionArguments* self, TypeInstance** result_type) {
  if (NULL != self->outputs->last) {
    CHECK(134, (((Argument*)(self->outputs->last->item)))->_base._dtl[5](((Argument*)(self->outputs->last->item)), &((*result_type))) )
  }
  else {
    (*result_type) = NULL;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_get_output(FunctionArguments* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_get_output = "FunctionArguments.get-output";
#define MR_FUNC_NAME _func_name_FunctionArguments_get_output
Returncode FunctionArguments_get_output(FunctionArguments* self, Expression** output) {
  if (NULL != self->outputs->last) {
    CHECK(140, (((Argument*)(self->outputs->last->item)))->_base._dtl[8](((Argument*)(self->outputs->last->item)), &((*output))) )
  }
  else {
    (*output) = NULL;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_find_variable(FunctionArguments* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_find_variable = "FunctionArguments.m-find-variable";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_find_variable
Returncode FunctionArguments_m_find_variable(FunctionArguments* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(146, FunctionArguments_m_find_variable_args(self, self->parameters, name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(148, FunctionArguments_m_find_variable_args(self, self->outputs, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_find_variable_args(FunctionArguments* self, List* arguments, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_find_variable_args = "FunctionArguments.m-find-variable-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_find_variable_args
Returncode FunctionArguments_m_find_variable_args(FunctionArguments* self, List* arguments, String* name, SyntaxTreeVariable** variable) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    SyntaxTreeVariable* _SyntaxTreeVariable4;
    CHECK(156, (((Argument*)(node->item)))->_base._dtl[7](((Argument*)(node->item)), &(_SyntaxTreeVariable4)) )
    Bool _Bool5;
    CHECK(156, SyntaxTreeVariable_m_find_variable(_SyntaxTreeVariable4, name, &((*variable)), &(_Bool5)) )
    if (!(!_Bool5)) break;
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_m_check_calling(FunctionArguments* self, FunctionArguments* other, Bool* output_ommited);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_m_check_calling = "FunctionArguments.m-check-calling";
#define MR_FUNC_NAME _func_name_FunctionArguments_m_check_calling
Returncode FunctionArguments_m_check_calling(FunctionArguments* self, FunctionArguments* other, Bool* output_ommited) {
  ListNode* my_node = self->parameters->first;
  ListNode* other_node = other->parameters->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    TypeInstance* _TypeInstance6;
    CHECK(166, (((Argument*)(other_node->item)))->_base._dtl[5](((Argument*)(other_node->item)), &(_TypeInstance6)) )
    CHECK(166, (((Argument*)(my_node->item)))->_base._dtl[6](((Argument*)(my_node->item)), _TypeInstance6) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(170, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){20, 19, "too many parameters"}) )
  }
  if (NULL != other_node) {
    CHECK(172, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){19, 18, "too few parameters"}) )
  }
  
  my_node = self->outputs->first;
  other_node = other->outputs->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    TypeInstance* _TypeInstance7;
    CHECK(178, (((Argument*)(other_node->item)))->_base._dtl[5](((Argument*)(other_node->item)), &(_TypeInstance7)) )
    CHECK(178, (((Argument*)(my_node->item)))->_base._dtl[6](((Argument*)(my_node->item)), _TypeInstance7) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(182, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){17, 16, "too many outputs"}) )
  }
  if (NULL != other_node &&  NULL !=  other_node->next) {
    CHECK(184, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){16, 15, "too few outputs"}) )
  }
  (*output_ommited) =  NULL !=  other_node;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_preactions(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_preactions = "FunctionArguments.write-preactions";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_preactions
Returncode FunctionArguments_write_preactions(FunctionArguments* self) {
  CHECK(188, FunctionArguments_write_args_preactions(self, self->parameters) )
  CHECK(189, FunctionArguments_write_args_preactions(self, self->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_args_preactions(FunctionArguments* self, List* arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_args_preactions = "FunctionArguments.write-args-preactions";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_args_preactions
Returncode FunctionArguments_write_args_preactions(FunctionArguments* self, List* arguments) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(195, (((Argument*)(node->item)))->_base._dtl[9](((Argument*)(node->item))) )
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write(FunctionArguments* self, Bool is_decleration);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write = "FunctionArguments.write";
#define MR_FUNC_NAME _func_name_FunctionArguments_write
Returncode FunctionArguments_write(FunctionArguments* self, Bool is_decleration) {
  /* (`params...`, `outputs...`) */
  CHECK(200, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters->first) {
    CHECK(202, FunctionArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs->first) {
    if (NULL != self->parameters->first) {
      CHECK(205, write(&(String){3, 2, ", "}) )
    }
    CHECK(206, FunctionArguments_write_args(self, self->outputs) )
  }
  else {
    if (!(NULL != self->parameters->first) && is_decleration) {
      CHECK(208, write(&(String){5, 4, "void"}) )
    }
  }
  CHECK(209, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_args(FunctionArguments* self, List* arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_args = "FunctionArguments.write-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_args
Returncode FunctionArguments_write_args(FunctionArguments* self, List* arguments) {
  ListNode* node = arguments->first;
  while (true) {
    CHECK(214, (((Argument*)(node->item)))->_base._dtl[2](((Argument*)(node->item))) )
    node = node->next;
    if (!(NULL != node)) break;
    CHECK(217, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func FunctionArguments__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func FunctionArguments__dtl[] = {(void*)FunctionArguments_m_link_types, (void*)FunctionArguments_analyze, (void*)FunctionArguments_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
