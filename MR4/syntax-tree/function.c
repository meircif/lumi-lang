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
  List* aux_variables_owner;
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
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
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
      Int _Int77;
      CHECK(26, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int77)) )
      Bool _Bool78;
      CHECK(27, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool78)) )
      if (_Bool78) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool79;
        CHECK(29, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool79)) )
        if (!_Bool79) {
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
  self->aux_variables_owner = malloc(sizeof(List));
  if (self->aux_variables_owner == NULL) RAISE(38)
  *self->aux_variables_owner = (List){NULL, NULL};
  self->_base.aux_variables = self->aux_variables_owner;
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
  CHECK(43, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
  Bool _Bool80;
  CHECK(44, SyntaxTreeBlock_m_has_end_point(&(self->_base), &(_Bool80)) )
  if (!_Bool80) {
    SyntaxTreeReturn* _SyntaxTreeReturn81;
    CHECK(45, SyntaxTreeReturn_parse_new(NULL, &(self->_base), &((*end)), &(_SyntaxTreeReturn81)) )
    CHECK(45, List_add(self->_base.code_nodes, &(_SyntaxTreeReturn81->_base)) )
  }
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
  CHECK(50, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(51, (self)->_base._base._base._dtl[6](self) )
  if ((*end) != '(') {
    CHECK(53, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  CHECK(55, SyntaxTreeFunction_parse_arguments(self, &((*end))) )
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
  if (self->arguments == NULL) RAISE(58)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
  argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
  SyntaxTreeCode* dummy_node = &(SyntaxTreeCode){SyntaxTreeCode__dtl, NULL, 0, NULL};
  dummy_node->_base._dtl = SyntaxTreeCode__dtl;
  dummy_node->parent = &(self->_base);
  CHECK(62, FunctionArguments_parse(self->arguments, &(argument_factory->_base), dummy_node, &((*end))) )
  if (NULL != self->parent_type) {
    TypeInstance* _TypeInstance82;
    CHECK(64, TypeData_m_new_type_instance(self->parent_type, &(_TypeInstance82)) )
    CHECK(64, FunctionArguments_add_self_parameter(self->arguments, _TypeInstance82) )
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
  Bool _Bool83;
  CHECK(68, f_is_legal_name(self->name, false, &(_Bool83)) )
  if (!_Bool83) {
    CHECK(69, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal function name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeFunction* meth = NULL;
    Int _Int84;
    CHECK(72, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int84)) )
    if (NULL != meth) {
      CHECK(74, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){23, 22, "redefinition of method"}, self->name) )
    }
    SyntaxTreeVariable* field = NULL;
    Int _Int85;
    CHECK(76, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int85)) )
    if (NULL != field) {
      CHECK(78, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "method name overrides field"}, self->name) )
    }
  }
  else {
    SyntaxTreeFunction* _SyntaxTreeFunction86;
    CHECK(81, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction86)) )
    if (NULL != _SyntaxTreeFunction86) {
      CHECK(82, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){25, 24, "redefinition of function"}, self->name) )
    }
    SyntaxTreeVariable* _SyntaxTreeVariable87;
    CHECK(83, (glob->root)->_base._base._base._dtl[4](glob->root, self->name, &(_SyntaxTreeVariable87)) )
    if (NULL != _SyntaxTreeVariable87) {
      CHECK(84, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){40, 39, "function name overrides global variable"}, self->name) )
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
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_find_variable = "SyntaxTreeFunction.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_find_variable
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(92, SyntaxTreeBlock_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(94, FunctionArguments_find_variable(self->arguments, name, &((*variable))) )
  }
  if (!(NULL != (*variable))) {
    CHECK(96, (glob->root)->_base._base._base._dtl[4](glob->root, name, &((*variable))) )
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
  CHECK(99, (self->arguments)->_base._dtl[0](self->arguments) )
  CHECK(100, SyntaxTreeBlock_link_types(&(self->_base)) )
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
  CHECK(103, (self->arguments)->_base._dtl[1](self->arguments) )
  CHECK(104, SyntaxTreeBlock_analyze(&(self->_base)) )
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
    CHECK(108, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal dynamic in function"}, self->name) )
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
  CHECK(119, write_pre_func(self) )
  CHECK(120, SyntaxTreeFunction_write_header(self) )
  CHECK(121, SyntaxTreeBlock_write_block(&(self->_base)) )
  CHECK(122, write_post_func() )
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
  CHECK(125, write(&(String){13, 12, "\nReturncode "}) )
  CHECK(126, SyntaxTreeFunction_write_cname(self) )
  CHECK(127, (self->arguments)->_base._dtl[2](self->arguments) )
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
    CHECK(131, write_cname(self->parent_type->name) )
    CHECK(132, write(&(String){2, 1, "_"}) )
  }
  CHECK(133, write_cname(self->name) )
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
  CHECK(136, FunctionArguments_write_pointer(self->arguments, self->name) )
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
  CHECK(140, SyntaxTreeFunction_write_header(self) )
  CHECK(141, write(&(String){3, 2, ";\n"}) )
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
  CHECK(145, write(&(String){24, 23, "\n#define MR_FILE_NAME \""}) )
  CHECK(146, write(self->_base._base._base.input_file_name) )
  CHECK(147, write(&(String){25, 24, "\"\n#define MR_FUNC_NAME \""}) )
  if (NULL != self->parent_type) {
    CHECK(149, write(self->parent_type->name) )
    CHECK(150, write(&(String){2, 1, "."}) )
  }
  CHECK(151, write(self->name) )
  CHECK(152, write(&(String){2, 1, "\""}) )
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
  CHECK(156, write(&(String){21, 20, "#undef MR_FILE_NAME\n"}) )
  CHECK(157, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
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
  if ((*new_node) == NULL) RAISE(164)
  *(*new_node) = (SyntaxTreeConstructor){SyntaxTreeConstructor__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeConstructor__dtl;
  CHECK(165, SyntaxTreeConstructor_parse((*new_node), parent_type, &((*end))) )
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
  CHECK(168, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.parent_type = parent_type;
  self->_base._base._base.indentation_spaces = 2;
  CHECK(171, string_new_copy(&(String){4, 3, "new"}, &(self->_base.name)) )
  CHECK(172, SyntaxTreeFunction_parse_arguments(&(self->_base), &((*end))) )
  CHECK(173, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
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
    CHECK(177, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){25, 24, "constructor with outputs"}) )
  }
  CHECK(178, SyntaxTreeFunction_analyze(&(self->_base)) )
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
  if ((*new_node) == NULL) RAISE(184)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(185, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
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
  CHECK(188, SyntaxTreeFunction_init(&(self->_base)) )
  CHECK(189, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(190)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(191, FunctionArguments_init(self->_base.arguments) )
  CHECK(192, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
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
  CHECK(199, write_pre_func(&(self->_base)) )
  CHECK(200, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(201, SyntaxTreeBlock_write_block(&(self->_base._base)) )
  CHECK(202, write_post_func() )
  CHECK(203, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
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
  if ((*new_node) == NULL) RAISE(209)
  *(*new_node) = (SyntaxTreeNativeFunction){SyntaxTreeNativeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeNativeFunction__dtl;
  CHECK(210, SyntaxTreeNativeFunction_parse((*new_node), &((*end))) )
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
  CHECK(213, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
  self->_base._base._base.indentation_spaces = 2;
  CHECK(215, SyntaxTreeFunction_parse_header(&(self->_base), &((*end))) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(216)
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
  if ((*new_argument) == NULL) RAISE(227)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  (*new_argument)->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base.access = self->_base.access;
  (*new_argument)->variable = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_argument)->variable == NULL) RAISE(229)
  *(*new_argument)->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  (*new_argument)->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  (*new_argument)->variable->access = self->variable->access;
  CHECK(231, TypeInstance_copy_new(self->variable->type_instance, &((*new_argument)->variable->type_instance)) )
  CHECK(233, string_new_copy(self->variable->name, &((*new_argument)->variable->name)) )
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
  if (self->variable == NULL) RAISE(236)
  *self->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  self->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  self->variable->access = self->_base.access;
  self->variable->is_output = self->_base.is_output;
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(239)
  *self->variable->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
  CHECK(240, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  if ((*end) != ' ') {
    CHECK(242, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(243, read_new(&(String){3, 2, ",)"}, &(self->variable->name), &((*end))) )
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
  CHECK(246, TypeInstance_link_types(self->variable->type_instance, &(self->_base._base)) )
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
      if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(251)
      CHECK(251, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
    }
  }
  else {
    if (self->_base.access == ACCESS_COPY) {
      CHECK(257, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){51, 50, "access should not be \"copy\" for non-primitive type"}, self->variable->type_instance->type_data->name) )
    }
  }
  CHECK(262, TypeInstance_analyze_lengths(self->variable->type_instance, &(self->_base._base)) )
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
    CHECK(272, write(&(String){14, 13, "Returncode (*"}) )
    if (self->_base.is_output) {
      CHECK(274, write(&(String){2, 1, "*"}) )
    }
    CHECK(275, write_cname(self->variable->name) )
    CHECK(276, write(&(String){2, 1, ")"}) )
    CHECK(277, (self->variable->type_instance->arguments)->_base._dtl[2](self->variable->type_instance->arguments) )
    return OK;
  }
  /* `type`[*][*] `name`[, `type`_Dynamic*[*] `name`_Dynamic] */
  CHECK(280, write_cname(self->variable->type_instance->type_data->name) )
  if (self->_base.access != ACCESS_COPY) {
    CHECK(282, write(&(String){2, 1, "*"}) )
  }
  if (self->_base.is_output) {
    CHECK(284, write(&(String){2, 1, "*"}) )
  }
  CHECK(285, write(&(String){2, 1, " "}) )
  CHECK(286, write_cname(self->variable->name) )
  if (self->variable->type_instance->type_data->is_dynamic) {
    CHECK(288, write(&(String){3, 2, ", "}) )
    CHECK(289, write_cname(self->variable->type_instance->type_data->name) )
    CHECK(290, write(&(String){10, 9, "_Dynamic*"}) )
    if (self->_base.is_output) {
      CHECK(292, write(&(String){2, 1, "*"}) )
    }
    CHECK(293, write(&(String){2, 1, " "}) )
    CHECK(294, write_cname(self->variable->name) )
    CHECK(295, write(&(String){9, 8, "_Dynamic"}) )
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
  DeclarationArgument* _DeclarationArgument88 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument88 == NULL) RAISE(300)
  *_DeclarationArgument88 = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  _DeclarationArgument88->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument88->_base);
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
