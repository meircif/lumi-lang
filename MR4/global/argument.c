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
  Bool is_native;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_copy_new(Argument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_copy_new = "Argument.copy-new";
#define MR_FUNC_NAME _func_name_Argument_copy_new
Returncode Argument_copy_new(Argument* self, DeclarationArgument** new_argument) {
  RAISE(11)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_parse(Argument* self, String* access_str, Bool is_output, Bool is_native, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse = "Argument.parse";
#define MR_FUNC_NAME _func_name_Argument_parse
Returncode Argument_parse(Argument* self, String* access_str, Bool is_output, Bool is_native, SyntaxTreeCode* code_node, Char* end) {
  self->is_output = is_output;
  self->is_native = is_native;
  CHECK(21, SyntaxTreeNode_set_location(&(self->_base)) )
  CHECK(22, SyntaxTreeNode_get_access(&(self->_base), access_str, &(self->access)) )
  CHECK(23, (self)->_base._dtl[5](self, code_node, &((*end))) )
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
  RAISE(26)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_type_instance = "Argument.get-type-instance";
#define MR_FUNC_NAME _func_name_Argument_get_type_instance
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance) {
  RAISE(29)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_check_same_as(Argument* self, Argument* other, TypeInstance* instance_type, Int bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_check_same_as = "Argument.check-same-as";
#define MR_FUNC_NAME _func_name_Argument_check_same_as
Returncode Argument_check_same_as(Argument* self, Argument* other, TypeInstance* instance_type, Int bases) {
  if (self->access != other->access) {
    if ((other->access) < 0 || (other->access) >= (glob->access_names)->length) RAISE(34)
    if ((self->access) < 0 || (self->access) >= (glob->access_names)->length) RAISE(34)
    CHECK(34, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){16, 15, "expected access"}, (&(((String*)((glob->access_names)->values))[other->access])), &(String){6, 5, ", got"}, (&(((String*)((glob->access_names)->values))[self->access]))) )
  }
  TypeInstance* _TypeInstance0;
  CHECK(39, (other)->_base._dtl[6](other, &(_TypeInstance0)) )
  CHECK(39, (self)->_base._dtl[7](self, _TypeInstance0, instance_type, bases) )
  self->is_native = other->is_native;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_check_same_type_as(Argument* self, TypeInstance* type_instance, TypeInstance* instance_type, Int bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_check_same_type_as = "Argument.check-same-type-as";
#define MR_FUNC_NAME _func_name_Argument_check_same_type_as
Returncode Argument_check_same_type_as(Argument* self, TypeInstance* type_instance, TypeInstance* instance_type, Int bases) {
  TypeInstance* _TypeInstance1;
  CHECK(47, (self)->_base._dtl[6](self, &(_TypeInstance1)) )
  CHECK(47, TypeInstance_check_equal(_TypeInstance1, type_instance, &(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_variable = "Argument.get-variable";
#define MR_FUNC_NAME _func_name_Argument_get_variable
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable) {
  RAISE(50)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_output(Argument* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_output = "Argument.get-output";
#define MR_FUNC_NAME _func_name_Argument_get_output
Returncode Argument_get_output(Argument* self, Expression** output) {
  RAISE(53)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write_preactions(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write_preactions = "Argument.write-preactions";
#define MR_FUNC_NAME _func_name_Argument_write_preactions
Returncode Argument_write_preactions(Argument* self) {
  RAISE(56)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write_postactions(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write_postactions = "Argument.write-postactions";
#define MR_FUNC_NAME _func_name_Argument_write_postactions
Returncode Argument_write_postactions(Argument* self) {
  RAISE(59)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Argument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Argument__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)Argument_copy_new, (void*)Argument_parse_value, (void*)Argument_get_type_instance, (void*)Argument_check_same_type_as, (void*)Argument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions, (void*)Argument_write_postactions};
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
  RAISE(64)
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
Returncode FunctionArguments_copy_new(FunctionArguments* self, FunctionArguments** new_arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_copy_new = "FunctionArguments.copy-new";
#define MR_FUNC_NAME _func_name_FunctionArguments_copy_new
Returncode FunctionArguments_copy_new(FunctionArguments* self, FunctionArguments** new_arguments) {
  (*new_arguments) = malloc(sizeof(FunctionArguments));
  if ((*new_arguments) == NULL) RAISE(73)
  *(*new_arguments) = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  (*new_arguments)->_base._dtl = FunctionArguments__dtl;
  CHECK(74, FunctionArguments_init((*new_arguments)) )
  CHECK(75, FunctionArguments_copy_new_args(self, self->parameters, (*new_arguments)->parameters) )
  CHECK(76, FunctionArguments_copy_new_args(self, self->outputs, (*new_arguments)->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_copy_new_args(FunctionArguments* self, List* arguments, List* new_arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_copy_new_args = "FunctionArguments.copy-new-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_copy_new_args
Returncode FunctionArguments_copy_new_args(FunctionArguments* self, List* arguments, List* new_arguments) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    DeclarationArgument* _DeclarationArgument2;
    CHECK(83, (((Argument*)(node->item)))->_base._dtl[4](((Argument*)(node->item)), &(_DeclarationArgument2)) )
    CHECK(83, List_add(new_arguments, &(_DeclarationArgument2->_base)) )
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
  CHECK(87, SyntaxTreeNode_set_location(&(self->_base)) )
  self->parameters = malloc(sizeof(List));
  if (self->parameters == NULL) RAISE(88)
  *self->parameters = (List){NULL, NULL};
  self->outputs = malloc(sizeof(List));
  if (self->outputs == NULL) RAISE(89)
  *self->outputs = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, Bool is_native, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse = "FunctionArguments.parse";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, Bool is_native, SyntaxTreeCode* code_node, Char* end) {
  CHECK(96, FunctionArguments_init(self) )
  CHECK(97, FunctionArguments_parse_args(self, self->parameters, argument_factory, is_native, code_node, &((*end))) )
  if ((*end) == '-') {
    CHECK(104, SyntaxTreeNode_read_expect(&(self->_base), &(String){3, 2, ">("}) )
    CHECK(105, FunctionArguments_parse_args(self, self->outputs, argument_factory, is_native, code_node, &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_add_self_parameter(FunctionArguments* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_add_self_parameter = "FunctionArguments.add-self-parameter";
#define MR_FUNC_NAME _func_name_FunctionArguments_add_self_parameter
Returncode FunctionArguments_add_self_parameter(FunctionArguments* self, TypeData* type_data) {
  DeclarationArgument* self_args = malloc(sizeof(DeclarationArgument));
  if (self_args == NULL) RAISE(113)
  *self_args = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  self_args->_base._base._dtl = DeclarationArgument__dtl;
  if (type_data->is_primitive) {
    self_args->_base.access = ACCESS_COPY;
  }
  else {
    self_args->_base.access = ACCESS_VAR;
  }
  CHECK(118, SyntaxTreeNode_set_location(&(self_args->_base._base)) )
  self_args->variable = malloc(sizeof(SyntaxTreeVariable));
  if (self_args->variable == NULL) RAISE(119)
  *self_args->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  self_args->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(120, string_new_copy(&(String){5, 4, "self"}, &(self_args->variable->name)) )
  CHECK(121, TypeData_m_self_type_instance(type_data, &(self_args->variable->type_instance)) )
  CHECK(122, List_prepend(self->parameters, &(self_args->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, Bool is_native, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse_args = "FunctionArguments.parse-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse_args
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, Bool is_native, SyntaxTreeCode* code_node, Char* end) {
  Argument* argument = NULL;
  String* access_str = NULL;
  Bool is_output = arguments == self->outputs;
  Int _Int3;
  CHECK(133, read_until(&(String){3, 2, " )"}, false, &(access_str), &((*end)), &(_Int3)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(135, SyntaxTreeCode_read_line_break_spaces(code_node) )
    Int _Int4;
    CHECK(136, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int4)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(140, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(142, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){33, 32, "expected space after access, got"}, (*end)) )
      }
      CHECK(144, (argument_factory)->_dtl[0](argument_factory, &(argument)) )
      CHECK(145, List_add(arguments, argument) )
      CHECK(146, Argument_parse(argument, access_str, is_output, is_native, code_node, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(150, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(152, SyntaxTreeCode_read_line_break_spaces(code_node) )
      }
      else {
        if ((*end) != ' ') {
          CHECK(154, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){42, 41, "expected space or new-line after \",\", got"}, (*end)) )
        }
      }
      Int _Int5;
      CHECK(157, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int5)) )
    }
  }
  CHECK(158, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_link_types(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_link_types = "FunctionArguments.link-types";
#define MR_FUNC_NAME _func_name_FunctionArguments_link_types
Returncode FunctionArguments_link_types(FunctionArguments* self) {
  CHECK(161, SyntaxTreeNode_link_children_types(&(self->_base), self->parameters) )
  CHECK(162, SyntaxTreeNode_link_children_types(&(self->_base), self->outputs) )
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
  CHECK(165, SyntaxTreeNode_analyze_children(&(self->_base), self->parameters) )
  CHECK(166, SyntaxTreeNode_analyze_children(&(self->_base), self->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_get_result_type(FunctionArguments* self, Int* access, TypeInstance** result_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_get_result_type = "FunctionArguments.get-result-type";
#define MR_FUNC_NAME _func_name_FunctionArguments_get_result_type
Returncode FunctionArguments_get_result_type(FunctionArguments* self, Int* access, TypeInstance** result_type) {
  if (NULL != self->outputs->last) {
    CHECK(170, (((Argument*)(self->outputs->last->item)))->_base._dtl[6](((Argument*)(self->outputs->last->item)), &((*result_type))) )
    (*access) = ((Argument*)(self->outputs->last->item))->access;
  }
  else {
    (*result_type) = NULL;
    (*access) = ACCESS_VAR;
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
    CHECK(178, (((Argument*)(self->outputs->last->item)))->_base._dtl[9](((Argument*)(self->outputs->last->item)), &((*output))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_find_variable(FunctionArguments* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_find_variable = "FunctionArguments.find-variable";
#define MR_FUNC_NAME _func_name_FunctionArguments_find_variable
Returncode FunctionArguments_find_variable(FunctionArguments* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(182, FunctionArguments_find_variable_args(self, self->parameters, name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(184, FunctionArguments_find_variable_args(self, self->outputs, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_find_variable_args(FunctionArguments* self, List* arguments, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_find_variable_args = "FunctionArguments.find-variable-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_find_variable_args
Returncode FunctionArguments_find_variable_args(FunctionArguments* self, List* arguments, String* name, SyntaxTreeVariable** variable) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    SyntaxTreeVariable* _SyntaxTreeVariable6;
    CHECK(192, (((Argument*)(node->item)))->_base._dtl[8](((Argument*)(node->item)), &(_SyntaxTreeVariable6)) )
    Bool _Bool7;
    CHECK(192, SyntaxTreeVariable_find_variable(_SyntaxTreeVariable6, name, &((*variable)), &(_Bool7)) )
    if (!(!_Bool7)) break;
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_check_same_as(FunctionArguments* self, FunctionArguments* other, TypeInstance* instance_type, Int bases, Bool* output_ommited);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_check_same_as = "FunctionArguments.check-same-as";
#define MR_FUNC_NAME _func_name_FunctionArguments_check_same_as
Returncode FunctionArguments_check_same_as(FunctionArguments* self, FunctionArguments* other, TypeInstance* instance_type, Int bases, Bool* output_ommited) {
  ListNode* my_node = self->parameters->first;
  ListNode* other_node = other->parameters->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    CHECK(205, Argument_check_same_as(((Argument*)(my_node->item)), other_node->item, instance_type, bases) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(210, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){20, 19, "too many parameters"}) )
  }
  if (NULL != other_node) {
    CHECK(212, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){19, 18, "too few parameters"}) )
  }
  
  my_node = self->outputs->first;
  other_node = other->outputs->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    CHECK(218, Argument_check_same_as(((Argument*)(my_node->item)), other_node->item, instance_type, bases) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(223, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){17, 16, "too many outputs"}) )
  }
  if (NULL != other_node &&  NULL !=  other_node->next) {
    CHECK(225, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){16, 15, "too few outputs"}) )
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
  CHECK(229, FunctionArguments_write_args_preactions(self, self->parameters) )
  CHECK(230, FunctionArguments_write_args_preactions(self, self->outputs) )
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
    CHECK(236, (((Argument*)(node->item)))->_base._dtl[10](((Argument*)(node->item))) )
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write = "FunctionArguments.write";
#define MR_FUNC_NAME _func_name_FunctionArguments_write
Returncode FunctionArguments_write(FunctionArguments* self) {
  CHECK(240, FunctionArguments_write_if_decleration(self, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_call(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_call = "FunctionArguments.write-call";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_call
Returncode FunctionArguments_write_call(FunctionArguments* self) {
  CHECK(243, FunctionArguments_write_if_decleration(self, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_if_decleration(FunctionArguments* self, Bool is_decleration);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_if_decleration = "FunctionArguments.write-if-decleration";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_if_decleration
Returncode FunctionArguments_write_if_decleration(FunctionArguments* self, Bool is_decleration) {
  /* (`params...`, `outputs...`) */
  CHECK(247, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters->first) {
    CHECK(249, FunctionArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs->first) {
    if (NULL != self->parameters->first) {
      CHECK(252, write(&(String){3, 2, ", "}) )
    }
    CHECK(253, FunctionArguments_write_args(self, self->outputs) )
  }
  else {
    if (!(NULL != self->parameters->first) && is_decleration) {
      CHECK(255, write(&(String){5, 4, "void"}) )
    }
  }
  CHECK(256, write(&(String){2, 1, ")"}) )
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
    CHECK(261, (((Argument*)(node->item)))->_base._dtl[3](((Argument*)(node->item))) )
    node = node->next;
    if (!(NULL != node)) break;
    CHECK(264, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_pointer(FunctionArguments* self, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_pointer = "FunctionArguments.write-pointer";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_pointer
Returncode FunctionArguments_write_pointer(FunctionArguments* self, String* name) {
  CHECK(267, write(&(String){14, 13, "Returncode (*"}) )
  CHECK(268, write_cname(name) )
  CHECK(269, write(&(String){2, 1, ")"}) )
  CHECK(270, (self)->_base._dtl[3](self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_write_postactions(FunctionArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_write_postactions = "FunctionArguments.write-postactions";
#define MR_FUNC_NAME _func_name_FunctionArguments_write_postactions
Returncode FunctionArguments_write_postactions(FunctionArguments* self) {
  ListNode* node = self->parameters->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(276, (((Argument*)(node->item)))->_base._dtl[11](((Argument*)(node->item))) )
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func FunctionArguments__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func FunctionArguments__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)FunctionArguments_link_types, (void*)FunctionArguments_analyze, (void*)FunctionArguments_write, (void*)FunctionArguments_write_call};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
