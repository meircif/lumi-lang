#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "statement/function.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file26_name = "statement/function.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file26_name

/* TL4 compiler - Syntax tree function */

/* Function node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeFunction SyntaxTreeFunction;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeFunction {
  SyntaxTreeBlock _base;
  List* aux_variables;
  TypeData* parent_type;
  String* name;
  ModuleMembers* my_module;
  FunctionArguments* arguments;
  SyntaxTreeMockFunction* mocker_function;
  SyntaxTreeFunction* dynamic_base_method;
  Int dynamic_base_count;
  Bool is_dynamic;
  Bool has_user_assign;
/* write function body */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_new = "SyntaxTreeFunction.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_parse_new
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeFunction));
  if ((*new_node) == NULL) RAISE(18)
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false};
  (*new_node)->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(19, SyntaxTreeFunction_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse = "SyntaxTreeFunction.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_parse
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end) {
  CHECK(22, SyntaxTreeFunction_init(self) )
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 2;
    if (self->parent_type->is_dynamic) {
      String* meth_type = NULL;
      Int _Int157;
      CHECK(28, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int157)) )
      Bool _Bool158;
      CHECK(29, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool158)) )
      if (_Bool158) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool159;
        CHECK(31, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool159)) )
        if (!_Bool159) {
          CHECK(32, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "expected \"dynamic\" or \"inst\" method type, got"}, meth_type) )
        }
      }
    }
  }
  else {
    self->my_module = glob->current_module;
  }
  CHECK(37, SyntaxTreeFunction_parse_header(self, false, &((*end))) )
  CHECK(38, SyntaxTreeFunction_parse_body(self, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_init = "SyntaxTreeFunction.init";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_init
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self) {
  CHECK(41, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->aux_variables = malloc(sizeof(List));
  if (self->aux_variables == NULL) RAISE(42)
  *self->aux_variables = (List){NULL, NULL};
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_body = "SyntaxTreeFunction.parse-body";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_parse_body
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end) {
  self->_base._base.indentation_spaces += 2;
  CHECK(46, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
  self->_base._base.indentation_spaces = 2;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Bool is_native, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_header = "SyntaxTreeFunction.parse-header";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_parse_header
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Bool is_native, Char* end) {
  CHECK(50, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(51, (self)->_base._base._base._dtl[10](self) )
  if ((*end) != '(') {
    CHECK(53, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  CHECK(55, SyntaxTreeFunction_parse_arguments(self, is_native, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Bool is_native, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_arguments = "SyntaxTreeFunction.parse-arguments";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_parse_arguments
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Bool is_native, Char* end) {
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(58)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
  argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
  SyntaxTreeCode* dummy_node = &(SyntaxTreeCode){SyntaxTreeCode__dtl, NULL, 0, NULL};
  dummy_node->_base._dtl = SyntaxTreeCode__dtl;
  CHECK(61, SyntaxTreeNode_set_location(&(dummy_node->_base)) )
  dummy_node->parent = &(self->_base);
  CHECK(63, FunctionArguments_parse(self->arguments, &(argument_factory->_base), is_native, dummy_node, self->_base._base.indentation_spaces, &((*end))) )
  if (NULL != self->parent_type) {
    CHECK(70, FunctionArguments_add_self_parameter(self->arguments, self->parent_type) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_f_register_name(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_f_register_name = "SyntaxTreeFunction.f-register-name";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_f_register_name
Returncode SyntaxTreeFunction_f_register_name(SyntaxTreeFunction* self) {
  Bool _Bool160;
  CHECK(73, f_is_legal_name(self->name, NAME_DEFAULT, &(_Bool160)) )
  if (!_Bool160) {
    CHECK(74, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal function name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeFunction* meth = NULL;
    Int _Int161;
    CHECK(77, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int161)) )
    if (NULL != meth) {
      CHECK(79, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){23, 22, "redefinition of method"}, self->name) )
    }
    SyntaxTreeVariable* field = NULL;
    Int _Int162;
    CHECK(81, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int162)) )
    if (NULL != field) {
      CHECK(83, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "method name overrides field"}, self->name) )
    }
  }
  else {
    ModuleMembers* _ModuleMembers163;
    CHECK(86, NameMap_find(glob->module_map, self->name, (void**)&(_ModuleMembers163)) )
    if (NULL != _ModuleMembers163) {
      CHECK(87, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "function name overrides module"}, self->name) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction164;
    CHECK(89, Global_find_function(glob, self->name, &(_SyntaxTreeFunction164)) )
    if (NULL != _SyntaxTreeFunction164) {
      CHECK(90, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){25, 24, "redefinition of function"}, self->name) )
    }
    SyntaxTreeVariable* _SyntaxTreeVariable165;
    CHECK(91, Global_find_variable(glob, self->name, &(_SyntaxTreeVariable165)) )
    if (NULL != _SyntaxTreeVariable165) {
      CHECK(92, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){40, 39, "function name overrides global variable"}, self->name) )
    }
    if (NULL != self->my_module) {
      CHECK(95, NameMap_add(self->my_module->function_map, self->name, self) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_get_function = "SyntaxTreeFunction.get-function";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_get_function
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function) {
  (*function) = self;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_get_parent_type = "SyntaxTreeFunction.get-parent-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_get_parent_type
Returncode SyntaxTreeFunction_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type) {
  (*parent_type) = self->parent_type;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, Bool is_create, TypeInstance* type_instance, SyntaxTreeVariable** new_variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_add_aux_variable = "SyntaxTreeFunction.add-aux-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_add_aux_variable
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, Bool is_create, TypeInstance* type_instance, SyntaxTreeVariable** new_variable) {
  Int index = 0;
  ListNode* node = self->aux_variables->first;
  while (true) {
    if (!(NULL != node)) break;
    if (!(((TypeCount*)(node->item))->type_data != type_instance->type_data)) break;
    node = node->next;
  }
  if (NULL != node) {
    ((TypeCount*)(node->item))->count += 1;
    index = ((TypeCount*)(node->item))->count;
  }
  else {
    TypeCount* type_count = malloc(sizeof(TypeCount));
    if (type_count == NULL) RAISE(116)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(118, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(119)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(120)
  CHECK(122, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(123, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(124, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(126, Int_str(index, index_str) )
  CHECK(127, String_concat(variable->name, index_str) )
  variable->_base.parent = &(self->_base);
  variable->access = access;
  variable->is_create = is_create;
  CHECK(131, TypeInstance_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(133, List_add(self->_base._base.variables, variable) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_find_variable = "SyntaxTreeFunction.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_find_variable
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  CHECK(137, SyntaxTreeBlock_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (NULL != (*variable)) {
    return OK;
  }
  if (!(NULL != module_name)) {
    CHECK(140, FunctionArguments_find_variable(self->arguments, name, &((*variable))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_link_types = "SyntaxTreeFunction.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_link_types
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self) {
  if (NULL != self->my_module) {
    glob->current_module = self->my_module;
  }
  CHECK(145, (self->arguments)->_base._dtl[1](self->arguments) )
  CHECK(146, SyntaxTreeBlock_link_types(&(self->_base)) )
  if (NULL != self->my_module) {
    glob->current_module = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_analyze = "SyntaxTreeFunction.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_analyze
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self) {
  if (NULL != self->my_module) {
    glob->current_module = self->my_module;
  }
  CHECK(153, (self->arguments)->_base._dtl[2](self->arguments) )
  CHECK(154, SyntaxTreeBlock_analyze(&(self->_base)) )
  if (NULL != self->my_module) {
    glob->current_module = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_m_compare = "SyntaxTreeFunction.m-compare";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_m_compare
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other) {
  if (self->is_dynamic != other->is_dynamic) {
    CHECK(160, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal dynamic in function"}, self->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* write function body */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write = "SyntaxTreeFunction.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self) {
  /* #define LUMI_FILE_NAME "`file-name`" */
  /* #define LUMI_FUNC_NAME "`parent-type`.`function-name`" */
  /* Returncode `Type`_`name`(`args`) { */
  /*   `block...` */
  /* } */
  /* #undef LUMI_FILE_NAME */
  /* #undef LUMI_FUNC_NAME */
  CHECK(171, write_pre_func(self) )
  CHECK(172, SyntaxTreeFunction_write_header(self) )
  CHECK(173, SyntaxTreeFunction_write_block(self) )
  CHECK(174, write_post_func() )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_header = "SyntaxTreeFunction.write-header";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_header
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self) {
  CHECK(177, write(&(String){13, 12, "\nReturncode "}) )
  CHECK(178, SyntaxTreeFunction_write_cname(self) )
  CHECK(179, (self->arguments)->_base._dtl[4](self->arguments) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_block = "SyntaxTreeFunction.write-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_block
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self) {
  /* `previous-text` { */
  /*   Returncode LUMI_err = OK; */
  /*   `block...` */
  /* LUMI_cleanup: */
  /*   return LUMI_err; */
  /* } */
  CHECK(188, SyntaxTreeBlock_write_block_start(&(self->_base)) )
  CHECK(189, write(&(String){29, 28, "  Returncode LUMI_err = OK;\n"}) )
  CHECK(190, SyntaxTreeBranch_write(&(self->_base._base)) )
  CHECK(191, SyntaxTreeFunction_write_setup(self) )
  CHECK(192, (self)->_base._base._base._dtl[9](self) )
  CHECK(193, write(&(String){15, 14, "LUMI_cleanup:\n"}) )
  CHECK(194, SyntaxTreeFunction_write_cleanup(self) )
  CHECK(195, write(&(String){20, 19, "  return LUMI_err;\n"}) )
  CHECK(196, SyntaxTreeBlock_write_block_end(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_setup(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_setup = "SyntaxTreeFunction.write-setup";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_setup
Returncode SyntaxTreeFunction_write_setup(SyntaxTreeFunction* self) {
  if (self->has_user_assign) {
    CHECK(200, write(&(String){40, 39, "  Ref_Manager* aux_Ref_Manager = NULL;\n"}) )
  }
  ListNode* node = self->arguments->parameters->first;
  while (true) {
    if (!(NULL != node)) break;
    if (((Argument*)(node->item))->access == ACCESS_USER) {
      CHECK(205, write(&(String){16, 15, "  LUMI_inc_ref("}) )
      SyntaxTreeVariable* _SyntaxTreeVariable166;
      CHECK(206, (((Argument*)(node->item)))->_base._dtl[9](((Argument*)(node->item)), &(_SyntaxTreeVariable166)) )
      CHECK(206, write_cname(_SyntaxTreeVariable166->name) )
      CHECK(207, write(&(String){11, 10, "_Refman);\n"}) )
    }
    node = node->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_cleanup(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_cleanup = "SyntaxTreeFunction.write-cleanup";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_cleanup
Returncode SyntaxTreeFunction_write_cleanup(SyntaxTreeFunction* self) {
  CHECK(211, SyntaxTreeBranch_write_cleanup(&(self->_base._base), NULL) )
  ListNode* param_node = self->arguments->parameters->last;
  while (true) {
    if (!(NULL != param_node)) break;
    if (((Argument*)(param_node->item))->access == ACCESS_USER || ((Argument*)(param_node->item))->access == ACCESS_OWNER) {
      SyntaxTreeVariable* _SyntaxTreeVariable167;
      CHECK(217, (((Argument*)(param_node->item)))->_base._dtl[9](((Argument*)(param_node->item)), &(_SyntaxTreeVariable167)) )
      CHECK(217, SyntaxTreeBranch_write_variable_cleanup(&(self->_base._base), _SyntaxTreeVariable167, NULL) )
    }
    param_node = param_node->prev;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_cname = "SyntaxTreeFunction.write-cname";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_cname
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self) {
  if (NULL != self->parent_type) {
    CHECK(223, TypeData_write_cname(self->parent_type) )
    CHECK(224, write(&(String){2, 1, "_"}) )
  }
  else {
    if (NULL != self->my_module) {
      CHECK(226, ModuleMembers_write_prefix(self->my_module) )
    }
  }
  CHECK(227, write_cname(self->name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_pointer = "SyntaxTreeFunction.write-pointer";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_pointer
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self) {
  CHECK(230, FunctionArguments_write_pointer(self->arguments, self->name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_declaration = "SyntaxTreeFunction.write-declaration";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFunction_write_declaration
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self) {
  /* Returncode `Type`_`name`(`args`); */
  CHECK(234, SyntaxTreeFunction_write_header(self) )
  CHECK(235, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Count occurrences of a specific type */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct TypeCount TypeCount;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct TypeCount {
  TypeData* type_data;
  Int count;
};
#endif


/* Constructor declaration in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeConstructor SyntaxTreeConstructor;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct SyntaxTreeConstructor {
  SyntaxTreeFunction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse_new = "SyntaxTreeConstructor.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstructor_parse_new
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeConstructor));
  if ((*new_node) == NULL) RAISE(248)
  *(*new_node) = (SyntaxTreeConstructor){SyntaxTreeConstructor__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeConstructor__dtl;
  CHECK(249, SyntaxTreeConstructor_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse = "SyntaxTreeConstructor.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstructor_parse
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end) {
  CHECK(252, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.parent_type = parent_type;
  self->_base._base._base.indentation_spaces = 2;
  CHECK(255, string_new_copy(&(String){4, 3, "new"}, &(self->_base.name)) )
  CHECK(256, SyntaxTreeFunction_parse_arguments(&(self->_base), false, &((*end))) )
  CHECK(257, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_analyze = "SyntaxTreeConstructor.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstructor_analyze
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self) {
  if (NULL != self->_base.arguments->outputs->first) {
    CHECK(261, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){25, 24, "constructor with outputs"}) )
  }
  CHECK(262, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeConstructor__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeConstructor__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeConstructor_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Function declaration argument */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct DeclarationArgument DeclarationArgument;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct DeclarationArgument {
  Argument _base;
  SyntaxTreeVariable* variable;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_copy_new = "DeclarationArgument.copy-new";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_copy_new
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument) {
  (*new_argument) = malloc(sizeof(DeclarationArgument));
  if ((*new_argument) == NULL) RAISE(270)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  (*new_argument)->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base._base.input_file_name = self->_base._base.input_file_name;
  (*new_argument)->_base._base.line_number = self->_base._base.line_number;
  (*new_argument)->_base.access = self->_base.access;
  (*new_argument)->_base.is_output = self->_base.is_output;
  (*new_argument)->_base.is_native = self->_base.is_native;
  (*new_argument)->variable = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_argument)->variable == NULL) RAISE(276)
  *(*new_argument)->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  (*new_argument)->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  (*new_argument)->variable->access = self->variable->access;
  (*new_argument)->variable->parent_type = self->variable->parent_type;
  CHECK(279, TypeInstance_copy_new(self->variable->type_instance, &((*new_argument)->variable->type_instance)) )
  CHECK(281, string_new_copy(self->variable->name, &((*new_argument)->variable->name)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_parse_value = "DeclarationArgument.parse-value";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_parse_value
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end) {
  self->variable = malloc(sizeof(SyntaxTreeVariable));
  if (self->variable == NULL) RAISE(286)
  *self->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  self->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  self->variable->access = self->_base.access;
  self->variable->is_output = self->_base.is_output;
  if (NULL != code_node) {
    CHECK(290, (code_node)->_base._dtl[0](code_node, &(self->variable->parent_type)) )
  }
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(291)
  *self->variable->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(292, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, indentation_spaces, &((*end))) )
  if ((*end) != ' ') {
    CHECK(295, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(296, read_new(&(String){3, 2, ",)"}, &(self->variable->name), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_get_parent_type(DeclarationArgument* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_get_parent_type = "DeclarationArgument.get-parent-type";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_get_parent_type
Returncode DeclarationArgument_get_parent_type(DeclarationArgument* self, TypeData** parent_type) {
  (*parent_type) = self->variable->parent_type;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_link_types(DeclarationArgument* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_link_types = "DeclarationArgument.link-types";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_link_types
Returncode DeclarationArgument_link_types(DeclarationArgument* self) {
  CHECK(302, TypeInstance_link_types(self->variable->type_instance, &(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_analyze(DeclarationArgument* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_analyze = "DeclarationArgument.analyze";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_analyze
Returncode DeclarationArgument_analyze(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data->is_primitive) {
    if (self->_base.is_output && self->_base.access != ACCESS_VAR) {
      if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(307)
      CHECK(307, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){7, 6, "output"}, self->variable->name, &(String){48, 47, "access should be \"var\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
    }
    else {
      if (!self->_base.is_output && self->_base.access != ACCESS_COPY) {
        if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(313)
        CHECK(313, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){10, 9, "parameter"}, self->variable->name, &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
      }
    }
  }
  else {
    if (self->_base.access == ACCESS_COPY) {
      CHECK(319, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){51, 50, "access should not be \"copy\" for non-primitive type"}, self->variable->type_instance->type_data->name) )
    }
  }
  CHECK(324, TypeInstance_analyze_lengths(self->variable->type_instance, &(self->_base._base), false) )
  if (self->_base.is_native) {
    if (self->_base.access == ACCESS_OWNER) {
      CHECK(327, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "owner argument to native function"}) )
    }
    if (self->_base.is_output && self->_base.access == ACCESS_USER) {
      CHECK(329, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "user output to native function"}) )
    }
    
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_get_type_instance = "DeclarationArgument.get-type-instance";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_get_type_instance
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance) {
  (*type_instance) = self->variable->type_instance;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_get_variable = "DeclarationArgument.get-variable";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_get_variable
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable) {
  (*variable) = self->variable;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgument_write(DeclarationArgument* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgument_write = "DeclarationArgument.write";
#define LUMI_FUNC_NAME _func_name_DeclarationArgument_write
Returncode DeclarationArgument_write(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data == glob->type_func) {
    CHECK(340, write(&(String){14, 13, "Returncode (*"}) )
    if (self->_base.is_output) {
      CHECK(342, write(&(String){2, 1, "*"}) )
    }
    CHECK(343, write_cname(self->variable->name) )
    CHECK(344, write(&(String){2, 1, ")"}) )
    CHECK(345, (self->variable->type_instance->arguments)->_base._dtl[4](self->variable->type_instance->arguments) )
    return OK;
  }
  /* `type`[*][*] `name` */
  /* [, Ref_Manager*[*] `name`_Refman] */
  /* [, `type`_Dynamic*[*] `name`_Dynamic] */
  CHECK(350, TypeData_write_cname(self->variable->type_instance->type_data) )
  if (!self->variable->type_instance->type_data->is_primitive) {
    CHECK(352, write(&(String){2, 1, "*"}) )
  }
  if (self->_base.is_output) {
    CHECK(354, write(&(String){2, 1, "*"}) )
  }
  CHECK(355, write(&(String){2, 1, " "}) )
  CHECK(356, write_cname(self->variable->name) )
  
  if (!self->variable->type_instance->type_data->is_primitive &&  ! self->_base.is_native) {
    CHECK(360, write(&(String){15, 14, ", Ref_Manager*"}) )
    if (self->_base.is_output) {
      CHECK(362, write(&(String){2, 1, "*"}) )
    }
    CHECK(363, write(&(String){2, 1, " "}) )
    CHECK(364, write_cname(self->variable->name) )
    CHECK(365, write(&(String){8, 7, "_Refman"}) )
  }
  
  if (self->variable->type_instance->type_data->is_dynamic &&  ! self->_base.is_native) {
    CHECK(368, write(&(String){3, 2, ", "}) )
    CHECK(369, TypeData_write_cname(self->variable->type_instance->type_data) )
    CHECK(370, write(&(String){10, 9, "_Dynamic*"}) )
    if (self->_base.is_output) {
      CHECK(372, write(&(String){2, 1, "*"}) )
    }
    CHECK(373, write(&(String){2, 1, " "}) )
    CHECK(374, write_cname(self->variable->name) )
    CHECK(375, write(&(String){9, 8, "_Dynamic"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_get_parent_type, (void*)DeclarationArgument_link_types, (void*)DeclarationArgument_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)DeclarationArgument_write, (void*)DeclarationArgument_copy_new, (void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_get_type_instance, (void*)Argument_check_same_type_as, (void*)DeclarationArgument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions, (void*)Argument_write_postactions};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct DeclarationArgumentFactory DeclarationArgumentFactory;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct DeclarationArgumentFactory {
  ArgumentFactory _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_DeclarationArgumentFactory_m_new_argument = "DeclarationArgumentFactory.m-new-argument";
#define LUMI_FUNC_NAME _func_name_DeclarationArgumentFactory_m_new_argument
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument) {
  DeclarationArgument* _DeclarationArgument168 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument168 == NULL) RAISE(380)
  *_DeclarationArgument168 = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  _DeclarationArgument168->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument168->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func DeclarationArgumentFactory__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func DeclarationArgumentFactory__dtl[] = {(void*)DeclarationArgumentFactory_m_new_argument};
#endif


/* to be mocked in unit-tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_pre_func(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_pre_func = "write-pre-func";
#define LUMI_FUNC_NAME _func_name_write_pre_func
Returncode write_pre_func(SyntaxTreeFunction* self) {
  CHECK(385, write(&(String){26, 25, "\n#define LUMI_FILE_NAME \""}) )
  CHECK(386, write(self->_base._base._base.input_file_name) )
  CHECK(387, write(&(String){27, 26, "\"\n#define LUMI_FUNC_NAME \""}) )
  if (NULL != self->parent_type) {
    CHECK(389, write(self->parent_type->name) )
    CHECK(390, write(&(String){2, 1, "."}) )
  }
  CHECK(391, write(self->name) )
  CHECK(392, write(&(String){2, 1, "\""}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

/* to be mocked in unit-tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_post_func();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_post_func = "write-post-func";
#define LUMI_FUNC_NAME _func_name_write_post_func
Returncode write_post_func() {
  CHECK(396, write(&(String){23, 22, "#undef LUMI_FILE_NAME\n"}) )
  CHECK(397, write(&(String){23, 22, "#undef LUMI_FUNC_NAME\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
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
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
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
