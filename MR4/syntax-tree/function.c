#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/function.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file15_name = "syntax-tree/function.3.mr";
#endif
#define MR_FILE_NAME _mr_file15_name

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
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false};
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
  self->aux_variables_owner = malloc(sizeof(List));
  if (self->aux_variables_owner == NULL) RAISE(17)
  *self->aux_variables_owner = (List){NULL, NULL};
  self->_base.aux_variables = self->aux_variables_owner;
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 4;
    if (self->parent_type->is_dynamic) {
      String* meth_type = NULL;
      Int _Int28;
      CHECK(24, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int28)) )
      Bool _Bool29;
      CHECK(25, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool29)) )
      if (_Bool29) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool30;
        CHECK(27, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool30)) )
        if (!_Bool30) {
          CHECK(28, f_syntax_error(&(String){46, 45, "expected \"dynamic\" or \"inst\" method type, got"}, meth_type) )
        }
      }
    }
  }
  else {
    self->_base._base.indentation_spaces = 2;
  }
  CHECK(33, SyntaxTreeFunction_parse_header(self, &((*end))) )
  CHECK(34, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
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
  CHECK(38, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  if ((*end) != '(') {
    CHECK(40, f_syntax_error_c(&(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(41)
  *self->arguments = (FunctionArguments){NULL, NULL};
  ArgumentFactory* argument_factory = &(ArgumentFactory){ArgumentFactory__dtl};
  argument_factory->_dtl = ArgumentFactory__dtl;
  CHECK(43, FunctionArguments_parse(self->arguments, argument_factory, NULL, self->parent_type, &((*end))) )
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
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_analyze = "SyntaxTreeFunction.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_analyze
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self) {
  CHECK(50, FunctionArguments_analyze(self->arguments) )
  CHECK(51, SyntaxTreeBranch_analyze(&(self->_base._base)) )
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
    CHECK(55, f_syntax_error(&(String){28, 27, "illegal dynamic in function"}, self->name) )
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
  CHECK(62, SyntaxTreeFunction_write_header(self) )
  CHECK(63, SyntaxTreeBlock_write_block(&(self->_base)) )
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
  CHECK(66, write(&(String){12, 11, "Returncode "}) )
  if (NULL != self->parent_type) {
    CHECK(68, write_cname(self->parent_type->name) )
    CHECK(69, write(&(String){2, 1, "_"}) )
  }
  CHECK(70, write_cname(self->name) )
  CHECK(71, FunctionArguments_write(self->arguments, true) )
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
  CHECK(74, write(&(String){14, 13, "Returncode (*"}) )
  CHECK(75, write_cname(self->name) )
  CHECK(76, write(&(String){2, 1, ")"}) )
  CHECK(77, FunctionArguments_write(self->arguments, true) )
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
  CHECK(81, write(&(String){2, 1, "\n"}) )
  CHECK(82, SyntaxTreeFunction_write_header(self) )
  CHECK(83, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_get_parent_type};
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
  if ((*new_node) == NULL) RAISE(89)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(90, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
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
  self->_base._base._base.indentation_spaces = 2;
  String* _String31;
  CHECK(94, string_new_copy(&(String){5, 4, "main"}, &(_String31)) )
  self->_base.name = _String31;
  CHECK(95, SyntaxTreeBlock_parse_block(&(self->_base._base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_analyze(SyntaxTreeMainFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_analyze = "SyntaxTreeMainFunction.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_analyze
Returncode SyntaxTreeMainFunction_analyze(SyntaxTreeMainFunction* self) {
  /* TODO... */
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
  CHECK(105, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(106, SyntaxTreeBlock_write_block(&(self->_base._base)) )
  CHECK(107, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeMainFunction_analyze, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_get_parent_type};
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
  if ((*new_node) == NULL) RAISE(113)
  *(*new_node) = (SyntaxTreeNativeFunction){SyntaxTreeNativeFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeNativeFunction__dtl;
  CHECK(114, SyntaxTreeNativeFunction_parse((*new_node), &((*end))) )
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
  self->_base._base._base.indentation_spaces = 2;
  CHECK(118, SyntaxTreeFunction_parse_header(&(self->_base), &((*end))) )
  self->_base._base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base._base.code_nodes == NULL) RAISE(119)
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
Func SyntaxTreeNativeFunction__dtl[] = {(void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNativeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_m_get_parent_type};
#endif


/* Basic function argument */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Argument Argument;
#elif MR_STAGE == MR_TYPES(0)
struct Argument {
  Func* _dtl;
  Int access;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_m_copy_new(Argument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_m_copy_new = "Argument.m-copy-new";
#define MR_FUNC_NAME _func_name_Argument_m_copy_new
Returncode Argument_m_copy_new(Argument* self, DeclarationArgument** new_argument) {
  RAISE(130)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_parse(Argument* self, String* access_str, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse = "Argument.parse";
#define MR_FUNC_NAME _func_name_Argument_parse
Returncode Argument_parse(Argument* self, String* access_str, SyntaxTreeCode* code_node, Char* end) {
  CHECK(134, get_access(access_str, &(self->access)) )
  CHECK(135, (self)->_dtl[1](self, code_node, &((*end))) )
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
  RAISE(138)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_analyze(Argument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_analyze = "Argument.analyze";
#define MR_FUNC_NAME _func_name_Argument_analyze
Returncode Argument_analyze(Argument* self, Bool is_output) {
  RAISE(141)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_type_instance = "Argument.get-type-instance";
#define MR_FUNC_NAME _func_name_Argument_get_type_instance
Returncode Argument_get_type_instance(Argument* self, TypeInstance** type_instance) {
  RAISE(144)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_get_output(Argument* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_get_output = "Argument.get-output";
#define MR_FUNC_NAME _func_name_Argument_get_output
Returncode Argument_get_output(Argument* self, Expression** output) {
  RAISE(147)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write(Argument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write = "Argument.write";
#define MR_FUNC_NAME _func_name_Argument_write
Returncode Argument_write(Argument* self, Bool is_output) {
  RAISE(150)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Argument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Argument__dtl[] = {(void*)Argument_m_copy_new, (void*)Argument_parse_value, (void*)Argument_analyze, (void*)Argument_get_type_instance, (void*)Argument_get_output, (void*)Argument_write};
#endif


/* Function declaration argument */
#if MR_STAGE == MR_TYPEDEFS
typedef struct DeclarationArgument DeclarationArgument;
#elif MR_STAGE == MR_TYPES(1)
struct DeclarationArgument {
  Argument _base;
  TypeInstance* type_instance;
  String* name;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_m_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_m_copy_new = "DeclarationArgument.m-copy-new";
#define MR_FUNC_NAME _func_name_DeclarationArgument_m_copy_new
Returncode DeclarationArgument_m_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument) {
  (*new_argument) = malloc(sizeof(DeclarationArgument));
  if ((*new_argument) == NULL) RAISE(159)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, 0, NULL, NULL};
  (*new_argument)->_base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base.access = self->_base.access;
  TypeInstance* _TypeInstance32;
  CHECK(161, TypeInstance_m_copy_new(self->type_instance, &(_TypeInstance32)) )
  CHECK(162, string_new_copy(self->name, &((*new_argument)->name)) )
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
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(165)
  *self->type_instance = (TypeInstance){NULL, NULL, NULL, NULL};
  CHECK(166, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &((*end))) )
  if ((*end) != ' ') {
    CHECK(168, f_syntax_error_c(&(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(169, read_new(&(String){3, 2, ",)"}, &(self->name), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_analyze(DeclarationArgument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_analyze = "DeclarationArgument.analyze";
#define MR_FUNC_NAME _func_name_DeclarationArgument_analyze
Returncode DeclarationArgument_analyze(DeclarationArgument* self, Bool is_output) {
  CHECK(172, TypeInstance_analyze(self->type_instance) )
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
  (*type_instance) = self->type_instance;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_write(DeclarationArgument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_write = "DeclarationArgument.write";
#define MR_FUNC_NAME _func_name_DeclarationArgument_write
Returncode DeclarationArgument_write(DeclarationArgument* self, Bool is_output) {
  /* `type`** `name` */
  CHECK(179, write_cname(self->type_instance->type_data->name) )
  if (self->_base.access != ACCESS_COPY) {
    CHECK(181, write(&(String){2, 1, "*"}) )
  }
  if (is_output) {
    CHECK(183, write(&(String){2, 1, "*"}) )
  }
  CHECK(184, write(&(String){2, 1, " "}) )
  CHECK(185, write_cname(self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_m_copy_new, (void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_analyze, (void*)DeclarationArgument_get_type_instance, (void*)Argument_get_output, (void*)DeclarationArgument_write};
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
  DeclarationArgument* _DeclarationArgument33 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument33 == NULL) RAISE(190)
  *_DeclarationArgument33 = (DeclarationArgument){DeclarationArgument__dtl, 0, NULL, NULL};
  _DeclarationArgument33->_base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument33->_base);
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
#elif MR_STAGE == MR_TYPES(0)
struct FunctionArguments {
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
  CHECK(199, FunctionArguments_m_copy_new_args(self, self->parameters, (*new_arguments)->parameters) )
  CHECK(200, FunctionArguments_m_copy_new_args(self, self->outputs, (*new_arguments)->outputs) )
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
    DeclarationArgument* _DeclarationArgument34;
    CHECK(207, (((Argument*)(node->item)))->_dtl[0](((Argument*)(node->item)), &(_DeclarationArgument34)) )
    CHECK(207, List_add(new_arguments, &(_DeclarationArgument34->_base)) )
    node = node->next;
  }
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
  self->parameters = malloc(sizeof(List));
  if (self->parameters == NULL) RAISE(215)
  *self->parameters = (List){NULL, NULL};
  self->outputs = malloc(sizeof(List));
  if (self->outputs == NULL) RAISE(216)
  *self->outputs = (List){NULL, NULL};
  if (NULL != parent_type) {
    DeclarationArgument* self_args = malloc(sizeof(DeclarationArgument));
    if (self_args == NULL) RAISE(218)
    *self_args = (DeclarationArgument){DeclarationArgument__dtl, 0, NULL, NULL};
    self_args->_base._dtl = DeclarationArgument__dtl;
    self_args->_base.access = ACCESS_VAR;
    CHECK(220, string_new_copy(&(String){5, 4, "self"}, &(self_args->name)) )
    CHECK(221, TypeData_m_new_type_instance(parent_type, &(self_args->type_instance)) )
    CHECK(222, List_add(self->parameters, &(self_args->_base)) )
  }
  CHECK(223, FunctionArguments_parse_args(self, self->parameters, argument_factory, code_node, &((*end))) )
  if ((*end) == '-') {
    CHECK(226, read_expect(&(String){3, 2, ">("}) )
    CHECK(227, FunctionArguments_parse_args(self, self->outputs, argument_factory, code_node, &((*end))) )
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
  Int _Int35;
  CHECK(237, read_until(&(String){3, 2, " )"}, false, &(access_str), &((*end)), &(_Int35)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(239, read_line_break_spaces() )
    Int _Int36;
    CHECK(240, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int36)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(244, f_syntax_error_c(&(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(246, f_syntax_error_c(&(String){33, 32, "expected space after access, got"}, (*end)) )
      }
      CHECK(247, (argument_factory)->_dtl[0](argument_factory, &(argument)) )
      CHECK(248, List_add(arguments, argument) )
      CHECK(249, Argument_parse(argument, access_str, code_node, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(251, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(253, read_line_break_spaces() )
      }
      else {
        if ((*end) != ' ') {
          CHECK(255, f_syntax_error_c(&(String){42, 41, "expected space or new-line after \",\", got"}, (*end)) )
        }
      }
      Int _Int37;
      CHECK(258, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int37)) )
    }
  }
  CHECK(259, read_c(&((*end))) )
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
  CHECK(262, FunctionArguments_analyze_args(self, self->parameters, false) )
  CHECK(263, FunctionArguments_analyze_args(self, self->outputs, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_analyze_args(FunctionArguments* self, List* arguments, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_analyze_args = "FunctionArguments.analyze-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_analyze_args
Returncode FunctionArguments_analyze_args(FunctionArguments* self, List* arguments, Bool is_output) {
  ListNode* node = arguments->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(269, (((Argument*)(node->item)))->_dtl[2](((Argument*)(node->item)), is_output) )
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
    CHECK(274, (((Argument*)(self->outputs->last->item)))->_dtl[3](((Argument*)(self->outputs->last->item)), &((*result_type))) )
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
    CHECK(280, (((Argument*)(self->outputs->last->item)))->_dtl[4](((Argument*)(self->outputs->last->item)), &((*output))) )
  }
  else {
    (*output) = NULL;
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
    CHECK(290, (((Argument*)(my_node->item)))->_dtl[3](((Argument*)(my_node->item)), &(_TypeInstance38)) )
    TypeInstance* _TypeInstance39;
    CHECK(290, (((Argument*)(other_node->item)))->_dtl[3](((Argument*)(other_node->item)), &(_TypeInstance39)) )
    CHECK(290, TypeInstance_m_check_assign_to(_TypeInstance38, _TypeInstance39) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(295, f_syntax_error_msg(&(String){20, 19, "too many parameters"}) )
  }
  if (NULL != other_node) {
    CHECK(297, f_syntax_error_msg(&(String){19, 18, "too few parameters"}) )
  }
  
  my_node = self->outputs->first;
  other_node = other->outputs->first;
  while (true) {
    if (!(NULL != my_node &&  NULL !=  other_node)) break;
    TypeInstance* _TypeInstance40;
    CHECK(303, (((Argument*)(other_node->item)))->_dtl[3](((Argument*)(other_node->item)), &(_TypeInstance40)) )
    TypeInstance* _TypeInstance41;
    CHECK(303, (((Argument*)(my_node->item)))->_dtl[3](((Argument*)(my_node->item)), &(_TypeInstance41)) )
    CHECK(303, TypeInstance_m_check_assign_to(_TypeInstance40, _TypeInstance41) )
    my_node = my_node->next;
    other_node = other_node->next;
  }
  if (NULL != my_node) {
    CHECK(308, f_syntax_error_msg(&(String){17, 16, "too many outputs"}) )
  }
  if (NULL != other_node &&  NULL !=  other_node->next) {
    CHECK(310, f_syntax_error_msg(&(String){16, 15, "too few outputs"}) )
  }
  (*output_ommited) =  NULL !=  other_node;
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
  CHECK(315, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters->first) {
    CHECK(317, FunctionArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs->first) {
    if (NULL != self->parameters->first) {
      CHECK(320, write(&(String){3, 2, ", "}) )
    }
    CHECK(321, FunctionArguments_write_args(self, self->outputs) )
  }
  else {
    if (!(NULL != self->parameters->first) && is_decleration) {
      CHECK(323, write(&(String){5, 4, "void"}) )
    }
  }
  CHECK(324, write(&(String){2, 1, ")"}) )
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
  Bool is_output = arguments == self->outputs;
  while (true) {
    CHECK(330, (((Argument*)(node->item)))->_dtl[5](((Argument*)(node->item)), is_output) )
    node = node->next;
    if (!(NULL != node)) break;
    CHECK(333, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
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
