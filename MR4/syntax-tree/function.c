#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/function.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file14_name = "syntax-tree/function.3.mr";
#endif
#define MR_FILE_NAME _mr_file14_name

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
  if ((*new_node) == NULL) RAISE(13)
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, false};
  (*new_node)->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(14, SyntaxTreeFunction_parse((*new_node), parent_type, &((*end))) )
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
  CHECK(17, SyntaxTreeFunction_init(self) )
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 4;
    if (self->parent_type->is_dynamic) {
      String* meth_type = NULL;
      Int _Int26;
      CHECK(23, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int26)) )
      Bool _Bool27;
      CHECK(24, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool27)) )
      if (_Bool27) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool28;
        CHECK(26, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool28)) )
        if (!_Bool28) {
          CHECK(27, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "expected \"dynamic\" or \"inst\" method type, got"}, meth_type) )
        }
      }
    }
  }
  CHECK(30, SyntaxTreeFunction_parse_header(self, &((*end))) )
  CHECK(31, SyntaxTreeFunction_parse_body(self, &((*end))) )
  self->_base._base.indentation_spaces = 2;
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
  CHECK(35, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->aux_variables_owner = malloc(sizeof(List));
  if (self->aux_variables_owner == NULL) RAISE(36)
  *self->aux_variables_owner = (List){NULL, NULL};
  self->_base.aux_variables = self->aux_variables_owner;
  self->_base._base.indentation_spaces = 2;
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
  CHECK(41, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
  Bool _Bool29;
  CHECK(42, SyntaxTreeBlock_m_has_end_point(&(self->_base), &(_Bool29)) )
  if (!_Bool29) {
    SyntaxTreeReturn* _SyntaxTreeReturn30;
    CHECK(43, SyntaxTreeReturn_parse_new(NULL, &(self->_base), &((*end)), &(_SyntaxTreeReturn30)) )
    CHECK(43, List_add(self->_base._base.code_nodes, &(_SyntaxTreeReturn30->_base)) )
  }
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
  CHECK(47, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  if ((*end) != '(') {
    CHECK(49, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(51)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  ArgumentFactory* argument_factory = &(ArgumentFactory){ArgumentFactory__dtl};
  argument_factory->_dtl = ArgumentFactory__dtl;
  CHECK(53, FunctionArguments_parse(self->arguments, argument_factory, NULL, self->parent_type, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_m_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_m_get_parent_type = "SyntaxTreeFunction.m-get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_m_get_parent_type
Returncode SyntaxTreeFunction_m_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type) {
  (*parent_type) = self->parent_type;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_m_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_m_find_variable = "SyntaxTreeFunction.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_m_find_variable
Returncode SyntaxTreeFunction_m_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(61, SyntaxTreeBlock_m_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(63, FunctionArguments_m_find_variable(self->arguments, name, &((*variable))) )
  }
  if (!(NULL != (*variable))) {
    CHECK(65, (glob->root)->_base._base._base._dtl[3](glob->root, name, &((*variable))) )
  }
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
  CHECK(68, FunctionArguments_analyze(self->arguments) )
  CHECK(69, SyntaxTreeBranch_analyze(&(self->_base._base)) )
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
    CHECK(73, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal dynamic in function"}, self->name) )
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
  /* Returncode `Type`_`name`(`args`) { */
  /*   `block...` */
  /* } */
  CHECK(80, SyntaxTreeFunction_write_header(self) )
  CHECK(81, SyntaxTreeBlock_write_block(&(self->_base)) )
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
  CHECK(84, write(&(String){12, 11, "Returncode "}) )
  if (NULL != self->parent_type) {
    CHECK(86, write_cname(self->parent_type->name) )
    CHECK(87, write(&(String){2, 1, "_"}) )
  }
  CHECK(88, write_cname(self->name) )
  CHECK(89, FunctionArguments_write(self->arguments, true) )
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
  CHECK(92, write(&(String){14, 13, "Returncode (*"}) )
  CHECK(93, write_cname(self->name) )
  CHECK(94, write(&(String){2, 1, ")"}) )
  CHECK(95, FunctionArguments_write(self->arguments, true) )
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
  CHECK(99, write(&(String){2, 1, "\n"}) )
  CHECK(100, SyntaxTreeFunction_write_header(self) )
  CHECK(101, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_find_variable, (void*)SyntaxTreeFunction_m_get_parent_type};
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
  if ((*new_node) == NULL) RAISE(107)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(108, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
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
  CHECK(111, SyntaxTreeFunction_init(&(self->_base)) )
  CHECK(112, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(113)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(114, FunctionArguments_init(self->_base.arguments) )
  CHECK(115, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
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
  CHECK(122, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(123, SyntaxTreeBlock_write_block(&(self->_base._base)) )
  CHECK(124, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_find_variable, (void*)SyntaxTreeFunction_m_get_parent_type};
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
  if ((*new_node) == NULL) RAISE(130)
  *(*new_node) = (SyntaxTreeNativeFunction){SyntaxTreeNativeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeNativeFunction__dtl;
  CHECK(131, SyntaxTreeNativeFunction_parse((*new_node), &((*end))) )
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
  CHECK(134, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
  self->_base._base._base.indentation_spaces = 2;
  CHECK(136, SyntaxTreeFunction_parse_header(&(self->_base), &((*end))) )
  self->_base._base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base._base.code_nodes == NULL) RAISE(137)
  *self->_base._base._base.code_nodes = (List){NULL, NULL};
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
Func SyntaxTreeNativeFunction__dtl[] = {(void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNativeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_find_variable, (void*)SyntaxTreeFunction_m_get_parent_type};
#endif


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
  RAISE(149)
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
  CHECK(157, SyntaxTreeNode_set_location(&(self->_base)) )
  CHECK(158, SyntaxTreeNode_get_access(&(self->_base), access_str, &(self->access)) )
  CHECK(159, (self)->_base._dtl[3](self, code_node, &((*end))) )
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
  RAISE(162)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_type_instance = "Argument.get-type-instance";
#define MR_FUNC_NAME _func_name_Argument_get_type_instance
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance) {
  RAISE(165)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_variable = "Argument.get-variable";
#define MR_FUNC_NAME _func_name_Argument_get_variable
Returncode Argument_get_variable(Argument* self, SyntaxTreeVariable** variable) {
  RAISE(168)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_output(Argument* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_output = "Argument.get-output";
#define MR_FUNC_NAME _func_name_Argument_get_output
Returncode Argument_get_output(Argument* self, Expression** output) {
  RAISE(171)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write_preactions(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write_preactions = "Argument.write-preactions";
#define MR_FUNC_NAME _func_name_Argument_write_preactions
Returncode Argument_write_preactions(Argument* self) {
  RAISE(174)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Argument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Argument__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)Argument_m_copy_new, (void*)Argument_parse_value, (void*)Argument_get_type_instance, (void*)Argument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions};
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
Returncode DeclarationArgument_m_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_m_copy_new = "DeclarationArgument.m-copy-new";
#define MR_FUNC_NAME _func_name_DeclarationArgument_m_copy_new
Returncode DeclarationArgument_m_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument) {
  (*new_argument) = malloc(sizeof(DeclarationArgument));
  if ((*new_argument) == NULL) RAISE(182)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  (*new_argument)->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base.access = self->_base.access;
  (*new_argument)->variable = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_argument)->variable == NULL) RAISE(184)
  *(*new_argument)->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL};
  (*new_argument)->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  (*new_argument)->variable->access = self->variable->access;
  CHECK(186, TypeInstance_m_copy_new(self->variable->type_instance, &((*new_argument)->variable->type_instance)) )
  CHECK(188, string_new_copy(self->variable->name, &((*new_argument)->variable->name)) )
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
  if (self->variable == NULL) RAISE(191)
  *self->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL};
  self->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  self->variable->access = self->_base.access;
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(193)
  *self->variable->type_instance = (TypeInstance){NULL, NULL, NULL, NULL};
  CHECK(194, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &(self->_base._base), &((*end))) )
  if ((*end) != ' ') {
    CHECK(196, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(197, read_new(&(String){3, 2, ",)"}, &(self->variable->name), &((*end))) )
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
  CHECK(200, TypeInstance_analyze(self->variable->type_instance, &(self->_base._base)) )
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
  /* `type`** `name` */
  CHECK(210, write_cname(self->variable->type_instance->type_data->name) )
  if (self->_base.access != ACCESS_COPY) {
    CHECK(212, write(&(String){2, 1, "*"}) )
  }
  if (self->_base.is_output) {
    CHECK(214, write(&(String){2, 1, "*"}) )
  }
  CHECK(215, write(&(String){2, 1, " "}) )
  CHECK(216, write_cname(self->variable->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_analyze, (void*)DeclarationArgument_write, (void*)DeclarationArgument_m_copy_new, (void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_get_type_instance, (void*)DeclarationArgument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions};
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
  DeclarationArgument* _DeclarationArgument31 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument31 == NULL) RAISE(221)
  *_DeclarationArgument31 = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
  _DeclarationArgument31->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument31->_base);
  return OK;
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
  CHECK(230, FunctionArguments_m_copy_new_args(self, self->parameters, (*new_arguments)->parameters) )
  CHECK(231, FunctionArguments_m_copy_new_args(self, self->outputs, (*new_arguments)->outputs) )
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
    DeclarationArgument* _DeclarationArgument32;
    CHECK(238, (((Argument*)(node->item)))->_base._dtl[2](((Argument*)(node->item)), &(_DeclarationArgument32)) )
    CHECK(238, List_add(new_arguments, &(_DeclarationArgument32->_base)) )
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
  CHECK(242, SyntaxTreeNode_set_location(&(self->_base)) )
  self->parameters = malloc(sizeof(List));
  if (self->parameters == NULL) RAISE(243)
  *self->parameters = (List){NULL, NULL};
  self->outputs = malloc(sizeof(List));
  if (self->outputs == NULL) RAISE(244)
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
  CHECK(251, FunctionArguments_init(self) )
  if (NULL != parent_type) {
    DeclarationArgument* self_args = malloc(sizeof(DeclarationArgument));
    if (self_args == NULL) RAISE(253)
    *self_args = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, NULL};
    self_args->_base._base._dtl = DeclarationArgument__dtl;
    self_args->_base.access = ACCESS_VAR;
    self_args->variable = malloc(sizeof(SyntaxTreeVariable));
    if (self_args->variable == NULL) RAISE(255)
    *self_args->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL};
    self_args->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
    CHECK(256, string_new_copy(&(String){5, 4, "self"}, &(self_args->variable->name)) )
    CHECK(257, TypeData_m_new_type_instance(parent_type, &(self_args->variable->type_instance)) )
    CHECK(258, List_add(self->parameters, &(self_args->_base)) )
  }
  CHECK(259, FunctionArguments_parse_args(self, self->parameters, argument_factory, code_node, &((*end))) )
  if ((*end) == '-') {
    CHECK(262, SyntaxTreeNode_read_expect(&(self->_base), &(String){3, 2, ">("}) )
    CHECK(263, FunctionArguments_parse_args(self, self->outputs, argument_factory, code_node, &((*end))) )
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
  Int _Int33;
  CHECK(274, read_until(&(String){3, 2, " )"}, false, &(access_str), &((*end)), &(_Int33)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(276, SyntaxTreeNode_read_line_break_spaces(&(self->_base)) )
    Int _Int34;
    CHECK(277, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int34)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(281, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(283, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){33, 32, "expected space after access, got"}, (*end)) )
      }
      CHECK(285, (argument_factory)->_dtl[0](argument_factory, &(argument)) )
      CHECK(286, List_add(arguments, argument) )
      CHECK(287, Argument_parse(argument, access_str, is_output, code_node, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(290, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(292, SyntaxTreeNode_read_line_break_spaces(&(self->_base)) )
      }
      else {
        if ((*end) != ' ') {
          CHECK(294, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){42, 41, "expected space or new-line after \",\", got"}, (*end)) )
        }
      }
      Int _Int35;
      CHECK(297, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int35)) )
    }
  }
  CHECK(298, read_c(&((*end))) )
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
  CHECK(301, FunctionArguments_analyze_args(self, self->parameters) )
  CHECK(302, FunctionArguments_analyze_args(self, self->outputs) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_analyze_args(FunctionArguments* self, List* arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_analyze_args = "FunctionArguments.analyze-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_analyze_args
Returncode FunctionArguments_analyze_args(FunctionArguments* self, List* arguments) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(308, (((Argument*)(node->item)))->_base._dtl[0](((Argument*)(node->item))) )
    node = node->next;
  }
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
    CHECK(313, (((Argument*)(self->outputs->last->item)))->_base._dtl[4](((Argument*)(self->outputs->last->item)), &((*result_type))) )
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
    CHECK(319, (((Argument*)(self->outputs->last->item)))->_base._dtl[6](((Argument*)(self->outputs->last->item)), &((*output))) )
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
  CHECK(325, FunctionArguments_m_find_variable_args(self, self->parameters, name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(327, FunctionArguments_m_find_variable_args(self, self->outputs, name, &((*variable))) )
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
    SyntaxTreeVariable* _SyntaxTreeVariable36;
    CHECK(335, (((Argument*)(node->item)))->_base._dtl[5](((Argument*)(node->item)), &(_SyntaxTreeVariable36)) )
    Bool _Bool37;
    CHECK(335, SyntaxTreeVariable_m_find_variable(_SyntaxTreeVariable36, name, &((*variable)), &(_Bool37)) )
    if (!(!_Bool37)) break;
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
    TypeInstance* _TypeInstance38;
    CHECK(345, (((Argument*)(my_node->item)))->_base._dtl[4](((Argument*)(my_node->item)), &(_TypeInstance38)) )
    TypeInstance* _TypeInstance39;
    CHECK(345, (((Argument*)(other_node->item)))->_base._dtl[4](((Argument*)(other_node->item)), &(_TypeInstance39)) )
    CHECK(345, TypeInstance_m_check_assign_to(_TypeInstance38, _TypeInstance39, &(self->_base)) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(350, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){20, 19, "too many parameters"}) )
  }
  if (NULL != other_node) {
    CHECK(352, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){19, 18, "too few parameters"}) )
  }
  
  my_node = self->outputs->first;
  other_node = other->outputs->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    TypeInstance* _TypeInstance40;
    CHECK(358, (((Argument*)(other_node->item)))->_base._dtl[4](((Argument*)(other_node->item)), &(_TypeInstance40)) )
    TypeInstance* _TypeInstance41;
    CHECK(358, (((Argument*)(my_node->item)))->_base._dtl[4](((Argument*)(my_node->item)), &(_TypeInstance41)) )
    CHECK(358, TypeInstance_m_check_assign_to(_TypeInstance40, _TypeInstance41, &(self->_base)) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(363, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){17, 16, "too many outputs"}) )
  }
  if (NULL != other_node &&  NULL !=  other_node->next) {
    CHECK(365, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){16, 15, "too few outputs"}) )
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
  CHECK(369, FunctionArguments_write_args_preactions(self, self->parameters) )
  CHECK(370, FunctionArguments_write_args_preactions(self, self->outputs) )
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
    CHECK(376, (((Argument*)(node->item)))->_base._dtl[7](((Argument*)(node->item))) )
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
  CHECK(381, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters->first) {
    CHECK(383, FunctionArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs->first) {
    if (NULL != self->parameters->first) {
      CHECK(386, write(&(String){3, 2, ", "}) )
    }
    CHECK(387, FunctionArguments_write_args(self, self->outputs) )
  }
  else {
    if (!(NULL != self->parameters->first) && is_decleration) {
      CHECK(389, write(&(String){5, 4, "void"}) )
    }
  }
  CHECK(390, write(&(String){2, 1, ")"}) )
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
    CHECK(395, (((Argument*)(node->item)))->_base._dtl[1](((Argument*)(node->item))) )
    node = node->next;
    if (!(NULL != node)) break;
    CHECK(398, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func FunctionArguments__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func FunctionArguments__dtl[] = {(void*)FunctionArguments_analyze, (void*)FunctionArguments_write};
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
