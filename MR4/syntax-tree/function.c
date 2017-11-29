#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/function.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file17_name = "syntax-tree/function.3.mr";
#endif
#define MR_FILE_NAME _mr_file17_name

/* MR4 compiler - Syntax tree function */

/* Function node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeFunction SyntaxTreeFunction;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeFunction {
  SyntaxTreeBlock _base;
  List* aux_variables;
  TypeData* parent_type;
  String* name;
  FunctionArguments* arguments;
  SyntaxTreeMockFunction* mocker_function;
  SyntaxTreeFunction* dynamic_base_method;
  Int dynamic_base_count;
  Bool is_dynamic;
/* write function body */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_new = "SyntaxTreeFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_new
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeFunction));
  if ((*new_node) == NULL) RAISE(16)
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(17, SyntaxTreeFunction_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse = "SyntaxTreeFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end) {
  CHECK(20, SyntaxTreeFunction_init(self) )
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 2;
    if (self->parent_type->is_dynamic) {
      String* meth_type = NULL;
      Int _Int81;
      CHECK(26, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int81)) )
      Bool _Bool82;
      CHECK(27, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool82)) )
      if (_Bool82) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool83;
        CHECK(29, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool83)) )
        if (!_Bool83) {
          CHECK(30, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "expected \"dynamic\" or \"inst\" method type, got"}, meth_type) )
        }
      }
    }
  }
  CHECK(33, SyntaxTreeFunction_parse_header(self, &((*end))) )
  CHECK(34, SyntaxTreeFunction_parse_body(self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_init = "SyntaxTreeFunction.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_init
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self) {
  CHECK(37, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->aux_variables = malloc(sizeof(List));
  if (self->aux_variables == NULL) RAISE(38)
  *self->aux_variables = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_body = "SyntaxTreeFunction.parse-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_body
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end) {
  self->_base._base.indentation_spaces += 2;
  CHECK(42, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
  self->_base._base.indentation_spaces = 2;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_header = "SyntaxTreeFunction.parse-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_header
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Char* end) {
  CHECK(46, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(47, (self)->_base._base._base._dtl[6](self) )
  if ((*end) != '(') {
    CHECK(49, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  CHECK(51, SyntaxTreeFunction_parse_arguments(self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_arguments = "SyntaxTreeFunction.parse-arguments";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_arguments
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Char* end) {
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(54)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
  argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
  SyntaxTreeCode* dummy_node = &(SyntaxTreeCode){SyntaxTreeCode__dtl, NULL, 0, NULL};
  dummy_node->_base._dtl = SyntaxTreeCode__dtl;
  dummy_node->parent = &(self->_base);
  CHECK(58, FunctionArguments_parse(self->arguments, &(argument_factory->_base), dummy_node, &((*end))) )
  if (NULL != self->parent_type) {
    TypeInstance* _TypeInstance84;
    CHECK(60, TypeData_m_new_type_instance(self->parent_type, &(_TypeInstance84)) )
    CHECK(60, FunctionArguments_add_self_parameter(self->arguments, _TypeInstance84) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_check_name(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_check_name = "SyntaxTreeFunction.check-name";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_check_name
Returncode SyntaxTreeFunction_check_name(SyntaxTreeFunction* self) {
  Bool _Bool85;
  CHECK(64, f_is_legal_name(self->name, false, &(_Bool85)) )
  if (!_Bool85) {
    CHECK(65, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal function name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeFunction* meth = NULL;
    Int _Int86;
    CHECK(68, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int86)) )
    if (NULL != meth) {
      CHECK(70, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){23, 22, "redefinition of method"}, self->name) )
    }
    SyntaxTreeVariable* field = NULL;
    Int _Int87;
    CHECK(72, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int87)) )
    if (NULL != field) {
      CHECK(74, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "method name overrides field"}, self->name) )
    }
  }
  else {
    SyntaxTreeFunction* _SyntaxTreeFunction88;
    CHECK(77, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction88)) )
    if (NULL != _SyntaxTreeFunction88) {
      CHECK(78, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){25, 24, "redefinition of function"}, self->name) )
    }
    SyntaxTreeVariable* _SyntaxTreeVariable89;
    CHECK(79, (glob->root)->_base._base._base._dtl[4](glob->root, self->name, &(_SyntaxTreeVariable89)) )
    if (NULL != _SyntaxTreeVariable89) {
      CHECK(80, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){40, 39, "function name overrides global variable"}, self->name) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_get_function = "SyntaxTreeFunction.get-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_get_function
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function) {
  (*function) = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, TypeInstance* type_instance, SyntaxTreeVariable** new_variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_add_aux_variable = "SyntaxTreeFunction.add-aux-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_add_aux_variable
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, TypeInstance* type_instance, SyntaxTreeVariable** new_variable) {
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
    if (type_count == NULL) RAISE(98)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(100, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(101)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(102)
  CHECK(104, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(105, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(106, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(108, Int_str(index, index_str) )
  CHECK(109, String_concat(variable->name, index_str) )
  variable->_base.parent = &(self->_base);
  if (access == ACCESS_COPY) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = access;
  }
  CHECK(115, TypeInstance_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(117, List_add(self->_base._base.variables, variable) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_find_variable = "SyntaxTreeFunction.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_find_variable
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(121, SyntaxTreeBlock_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(123, FunctionArguments_find_variable(self->arguments, name, &((*variable))) )
  }
  if (!(NULL != (*variable))) {
    CHECK(125, (glob->root)->_base._base._base._dtl[4](glob->root, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_link_types = "SyntaxTreeFunction.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_link_types
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self) {
  CHECK(128, (self->arguments)->_base._dtl[0](self->arguments) )
  CHECK(129, SyntaxTreeBlock_link_types(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_analyze = "SyntaxTreeFunction.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_analyze
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self) {
  CHECK(132, (self->arguments)->_base._dtl[1](self->arguments) )
  CHECK(133, SyntaxTreeBlock_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_m_compare = "SyntaxTreeFunction.m-compare";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_m_compare
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other) {
  if (self->is_dynamic != other->is_dynamic) {
    CHECK(137, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal dynamic in function"}, self->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write function body */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write = "SyntaxTreeFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self) {
  /* #define MR_FILE_NAME "`file-name`" */
  /* #define MR_FUNC_NAME "`parent-type`.`function-name`" */
  /* Returncode `Type`_`name`(`args`) { */
  /*   `block...` */
  /* } */
  /* #undef MR_FILE_NAME */
  /* #undef MR_FUNC_NAME */
  CHECK(148, write_pre_func(self) )
  CHECK(149, SyntaxTreeFunction_write_header(self) )
  CHECK(150, SyntaxTreeFunction_write_block(self) )
  CHECK(151, write_post_func() )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_header = "SyntaxTreeFunction.write-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_header
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self) {
  CHECK(154, write(&(String){13, 12, "\nReturncode "}) )
  CHECK(155, SyntaxTreeFunction_write_cname(self) )
  CHECK(156, (self->arguments)->_base._dtl[2](self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_block = "SyntaxTreeFunction.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_block
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self) {
  /* `previous-text` { */
  /*   Returncode MR_err = OK; */
  /*   `block...` */
  /* MR_cleanup: */
  /*   return MR_err; */
  /* } */
  CHECK(165, SyntaxTreeBlock_write_block_start(&(self->_base)) )
  CHECK(166, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
  CHECK(167, write(&(String){25, 24, "Returncode MR_err = OK;\n"}) )
  CHECK(168, SyntaxTreeBranch_write(&(self->_base._base)) )
  CHECK(169, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base.code_nodes) )
  CHECK(170, write(&(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(171, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
  CHECK(172, write(&(String){16, 15, "return MR_err;\n"}) )
  CHECK(173, SyntaxTreeBlock_write_block_end(&(self->_base)) )
  
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_cname = "SyntaxTreeFunction.write-cname";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_cname
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self) {
  if (NULL != self->parent_type) {
    CHECK(178, write_cname(self->parent_type->name) )
    CHECK(179, write(&(String){2, 1, "_"}) )
  }
  CHECK(180, write_cname(self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_pointer = "SyntaxTreeFunction.write-pointer";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_pointer
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self) {
  CHECK(183, FunctionArguments_write_pointer(self->arguments, self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_declaration = "SyntaxTreeFunction.write-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_declaration
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self) {
  /* Returncode `Type`_`name`(`args`); */
  CHECK(187, SyntaxTreeFunction_write_header(self) )
  CHECK(188, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif

/* to be mocked in unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_pre_func(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_pre_func = "write-pre-func";
#define MR_FUNC_NAME _func_name_write_pre_func
Returncode write_pre_func(SyntaxTreeFunction* self) {
  CHECK(192, write(&(String){24, 23, "\n#define MR_FILE_NAME \""}) )
  CHECK(193, write(self->_base._base._base.input_file_name) )
  CHECK(194, write(&(String){25, 24, "\"\n#define MR_FUNC_NAME \""}) )
  if (NULL != self->parent_type) {
    CHECK(196, write(self->parent_type->name) )
    CHECK(197, write(&(String){2, 1, "."}) )
  }
  CHECK(198, write(self->name) )
  CHECK(199, write(&(String){2, 1, "\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

/* to be mocked in unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_post_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_post_func = "write-post-func";
#define MR_FUNC_NAME _func_name_write_post_func
Returncode write_post_func() {
  CHECK(203, write(&(String){21, 20, "#undef MR_FILE_NAME\n"}) )
  CHECK(204, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Count occurrences of a specific type */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeCount TypeCount;
#elif MR_STAGE == MR_TYPES(0)
struct TypeCount {
  TypeData* type_data;
  Int count;
};
#endif


/* Constructor declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeConstructor SyntaxTreeConstructor;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeConstructor {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse_new = "SyntaxTreeConstructor.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_parse_new
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeConstructor));
  if ((*new_node) == NULL) RAISE(217)
  *(*new_node) = (SyntaxTreeConstructor){SyntaxTreeConstructor__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeConstructor__dtl;
  CHECK(218, SyntaxTreeConstructor_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse = "SyntaxTreeConstructor.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_parse
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end) {
  CHECK(221, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.parent_type = parent_type;
  self->_base._base._base.indentation_spaces = 2;
  CHECK(224, string_new_copy(&(String){4, 3, "new"}, &(self->_base.name)) )
  CHECK(225, SyntaxTreeFunction_parse_arguments(&(self->_base), &((*end))) )
  CHECK(226, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_analyze = "SyntaxTreeConstructor.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_analyze
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self) {
  if (NULL != self->_base.arguments->outputs->first) {
    CHECK(230, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){25, 24, "constructor with outputs"}) )
  }
  CHECK(231, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeConstructor__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeConstructor__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeConstructor_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Main function node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMainFunction SyntaxTreeMainFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMainFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse_new = "SyntaxTreeMainFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse_new
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMainFunction));
  if ((*new_node) == NULL) RAISE(237)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(238, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse = "SyntaxTreeMainFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end) {
  CHECK(241, SyntaxTreeFunction_init(&(self->_base)) )
  CHECK(242, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(243)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(244, FunctionArguments_init(self->_base.arguments) )
  CHECK(245, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write = "SyntaxTreeMainFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_write
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self) {
  /* USER_MAIN_HEADER { */
  /*   `block...` */
  /* } */
  /* MAIN_FUNC */
  CHECK(252, write_pre_func(&(self->_base)) )
  CHECK(253, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(254, SyntaxTreeFunction_write_block(&(self->_base)) )
  CHECK(255, write_post_func() )
  CHECK(256, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Native function declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNativeFunction SyntaxTreeNativeFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeNativeFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNativeFunction_parse_new(SyntaxTreeNativeFunction* self, Char* end, SyntaxTreeNativeFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNativeFunction_parse_new = "SyntaxTreeNativeFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeNativeFunction_parse_new
Returncode SyntaxTreeNativeFunction_parse_new(SyntaxTreeNativeFunction* self, Char* end, SyntaxTreeNativeFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeNativeFunction));
  if ((*new_node) == NULL) RAISE(262)
  *(*new_node) = (SyntaxTreeNativeFunction){SyntaxTreeNativeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeNativeFunction__dtl;
  CHECK(263, SyntaxTreeNativeFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNativeFunction_parse(SyntaxTreeNativeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNativeFunction_parse = "SyntaxTreeNativeFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeNativeFunction_parse
Returncode SyntaxTreeNativeFunction_parse(SyntaxTreeNativeFunction* self, Char* end) {
  CHECK(266, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
  self->_base._base._base.indentation_spaces = 2;
  CHECK(268, SyntaxTreeFunction_parse_header(&(self->_base), &((*end))) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(269)
  *self->_base._base.code_nodes = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNativeFunction_write(SyntaxTreeNativeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNativeFunction_write = "SyntaxTreeNativeFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNativeFunction_write
Returncode SyntaxTreeNativeFunction_write(SyntaxTreeNativeFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNativeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNativeFunction__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNativeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Function declaration argument */
#if MR_STAGE == MR_TYPEDEFS
typedef struct DeclarationArgument DeclarationArgument;
#elif MR_STAGE == MR_TYPES(2)
struct DeclarationArgument {
  Argument _base;
  SyntaxTreeVariable* variable;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_copy_new = "DeclarationArgument.copy-new";
#define MR_FUNC_NAME _func_name_DeclarationArgument_copy_new
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument) {
  (*new_argument) = malloc(sizeof(DeclarationArgument));
  if ((*new_argument) == NULL) RAISE(280)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  (*new_argument)->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base.access = self->_base.access;
  (*new_argument)->variable = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_argument)->variable == NULL) RAISE(282)
  *(*new_argument)->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  (*new_argument)->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  (*new_argument)->variable->access = self->variable->access;
  CHECK(284, TypeInstance_copy_new(self->variable->type_instance, &((*new_argument)->variable->type_instance)) )
  CHECK(286, string_new_copy(self->variable->name, &((*new_argument)->variable->name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_parse_value = "DeclarationArgument.parse-value";
#define MR_FUNC_NAME _func_name_DeclarationArgument_parse_value
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Char* end) {
  self->variable = malloc(sizeof(SyntaxTreeVariable));
  if (self->variable == NULL) RAISE(289)
  *self->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  self->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  self->variable->access = self->_base.access;
  self->variable->is_output = self->_base.is_output;
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(292)
  *self->variable->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(293, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  if ((*end) != ' ') {
    CHECK(295, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(296, read_new(&(String){3, 2, ",)"}, &(self->variable->name), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_link_types(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_link_types = "DeclarationArgument.link-types";
#define MR_FUNC_NAME _func_name_DeclarationArgument_link_types
Returncode DeclarationArgument_link_types(DeclarationArgument* self) {
  CHECK(299, TypeInstance_link_types(self->variable->type_instance, &(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_analyze(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_analyze = "DeclarationArgument.analyze";
#define MR_FUNC_NAME _func_name_DeclarationArgument_analyze
Returncode DeclarationArgument_analyze(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data->is_primitive) {
    if (self->_base.access != ACCESS_COPY) {
      if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(304)
      CHECK(304, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
    }
  }
  else {
    if (self->_base.access == ACCESS_COPY) {
      CHECK(310, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){51, 50, "access should not be \"copy\" for non-primitive type"}, self->variable->type_instance->type_data->name) )
    }
  }
  CHECK(315, TypeInstance_analyze_lengths(self->variable->type_instance, &(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_get_type_instance = "DeclarationArgument.get-type-instance";
#define MR_FUNC_NAME _func_name_DeclarationArgument_get_type_instance
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance) {
  (*type_instance) = self->variable->type_instance;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_get_variable = "DeclarationArgument.get-variable";
#define MR_FUNC_NAME _func_name_DeclarationArgument_get_variable
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable) {
  (*variable) = self->variable;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_write(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_write = "DeclarationArgument.write";
#define MR_FUNC_NAME _func_name_DeclarationArgument_write
Returncode DeclarationArgument_write(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data == &(glob->type_func->_base)) {
    CHECK(325, write(&(String){14, 13, "Returncode (*"}) )
    if (self->_base.is_output) {
      CHECK(327, write(&(String){2, 1, "*"}) )
    }
    CHECK(328, write_cname(self->variable->name) )
    CHECK(329, write(&(String){2, 1, ")"}) )
    CHECK(330, (self->variable->type_instance->arguments)->_base._dtl[2](self->variable->type_instance->arguments) )
    return OK;
  }
  /* `type`[*][*] `name` */
  /* [, RefManager*[*] `name`_Refman] */
  /* [, `type`_Dynamic*[*] `name`_Dynamic] */
  CHECK(335, write_cname(self->variable->type_instance->type_data->name) )
  if (self->_base.access != ACCESS_COPY) {
    CHECK(337, write(&(String){2, 1, "*"}) )
  }
  if (self->_base.is_output) {
    CHECK(339, write(&(String){2, 1, "*"}) )
  }
  CHECK(340, write(&(String){2, 1, " "}) )
  CHECK(341, write_cname(self->variable->name) )
  
  if (!self->variable->type_instance->type_data->is_primitive) {
    CHECK(344, write(&(String){14, 13, ", RefManager*"}) )
    if (self->_base.is_output) {
      CHECK(346, write(&(String){2, 1, "*"}) )
    }
    CHECK(347, write(&(String){2, 1, " "}) )
    CHECK(348, write_cname(self->variable->name) )
    CHECK(349, write(&(String){8, 7, "_Refman"}) )
  }
  
  if (self->variable->type_instance->type_data->is_dynamic) {
    CHECK(352, write(&(String){3, 2, ", "}) )
    CHECK(353, write_cname(self->variable->type_instance->type_data->name) )
    CHECK(354, write(&(String){10, 9, "_Dynamic*"}) )
    if (self->_base.is_output) {
      CHECK(356, write(&(String){2, 1, "*"}) )
    }
    CHECK(357, write(&(String){2, 1, " "}) )
    CHECK(358, write_cname(self->variable->name) )
    CHECK(359, write(&(String){9, 8, "_Dynamic"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_link_types, (void*)DeclarationArgument_analyze, (void*)DeclarationArgument_write, (void*)DeclarationArgument_copy_new, (void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_get_type_instance, (void*)Argument_check_same_type_as, (void*)DeclarationArgument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct DeclarationArgumentFactory DeclarationArgumentFactory;
#elif MR_STAGE == MR_TYPES(1)
struct DeclarationArgumentFactory {
  ArgumentFactory _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgumentFactory_m_new_argument = "DeclarationArgumentFactory.m-new-argument";
#define MR_FUNC_NAME _func_name_DeclarationArgumentFactory_m_new_argument
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument) {
  DeclarationArgument* _DeclarationArgument90 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument90 == NULL) RAISE(364)
  *_DeclarationArgument90 = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  _DeclarationArgument90->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument90->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgumentFactory__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgumentFactory__dtl[] = {(void*)DeclarationArgumentFactory_m_new_argument};
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
