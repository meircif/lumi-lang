#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/function.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file14_name = "syntax-tree/function.3.mr";
#endif
#define MR_FILE_NAME _mr_file14_name

/* MR4 compiler - Syntax tree function */

/* Function node in the syntax tree  */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeFunction SyntaxTreeFunction;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeFunction {
  SyntaxTreeBlock _base;
  SyntaxTreeType* parent_type;
  String* name;
  FunctionArguments* arguemnts;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, SyntaxTreeType* parent_type, SyntaxTreeFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_new = "SyntaxTreeFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_new
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, SyntaxTreeType* parent_type, SyntaxTreeFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeFunction));
  if ((*new_node) == NULL) RAISE(11)
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(12, SyntaxTreeFunction_parse((*new_node), parent_type) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, SyntaxTreeType* parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse = "SyntaxTreeFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, SyntaxTreeType* parent_type) {
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 4;
  }
  else {
    self->_base._base.indentation_spaces = 2;
  }
  Char end = '\0';
  CHECK(21, read_new(&(String){2, 1, "("}, &(self->name), &(end)) )
  if (end != '(') {
    CHECK(23, f_syntax_error_c(&(String){19, 18, "expected \"(\", got "}, end) )
  }
  self->arguemnts = malloc(sizeof(FunctionArguments));
  if (self->arguemnts == NULL) RAISE(24)
  *self->arguemnts = (FunctionArguments){NULL, NULL};
  ArgumentFactory* argument_factory = &(ArgumentFactory){ArgumentFactory__dtl};
  argument_factory->_dtl = ArgumentFactory__dtl;
  CHECK(26, FunctionArguments_parse(self->arguemnts, argument_factory, &(end)) )
  if (end != '\n') {
    CHECK(28, f_syntax_error_c(&(String){24, 23, "expected line-end, got "}, end) )
  }
  CHECK(29, SyntaxTreeBlock_parse_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write = "SyntaxTreeFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self) {
  CHECK(32, write(&(String){10, 9, "Function("}) )
  CHECK(33, write(self->name) )
  CHECK(34, write(&(String){2, 1, ")"}) )
  CHECK(35, FunctionArguments_write(self->arguemnts) )
  CHECK(36, SyntaxTreeBlock_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child};
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
Returncode Argument_parse(Argument* self, String* access_str, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse = "Argument.parse";
#define MR_FUNC_NAME _func_name_Argument_parse
Returncode Argument_parse(Argument* self, String* access_str, Char* end) {
  CHECK(44, get_access(access_str, &(self->access)) )
  CHECK(45, (self)->_dtl[0](self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_parse_value(Argument* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_parse_value = "Argument.parse-value";
#define MR_FUNC_NAME _func_name_Argument_parse_value
Returncode Argument_parse_value(Argument* self, Char* end) {
  RAISE(48)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write = "Argument.write";
#define MR_FUNC_NAME _func_name_Argument_write
Returncode Argument_write(Argument* self) {
  CHECK(51, write(&(String){8, 7, "Access("}) )
  CHECK(52, write_int(self->access) )
  CHECK(53, write(&(String){3, 2, ") "}) )
  CHECK(54, (self)->_dtl[1](self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Argument_write_value(Argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Argument_write_value = "Argument.write-value";
#define MR_FUNC_NAME _func_name_Argument_write_value
Returncode Argument_write_value(Argument* self) {
  RAISE(57)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Argument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Argument__dtl[] = {(void*)Argument_parse_value, (void*)Argument_write_value};
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
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_parse_value = "DeclarationArgument.parse-value";
#define MR_FUNC_NAME _func_name_DeclarationArgument_parse_value
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, Char* end) {
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(66)
  *self->type_instance = (TypeInstance){NULL, NULL};
  CHECK(67, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &((*end))) )
  if ((*end) != ' ') {
    CHECK(69, f_syntax_error_c(&(String){21, 20, "expected space, got "}, (*end)) )
  }
  CHECK(70, read_new(&(String){3, 2, ",)"}, &(self->name), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_write_value(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_write_value = "DeclarationArgument.write-value";
#define MR_FUNC_NAME _func_name_DeclarationArgument_write_value
Returncode DeclarationArgument_write_value(DeclarationArgument* self) {
  CHECK(73, TypeInstance_write(self->type_instance) )
  CHECK(74, write(&(String){2, 1, " "}) )
  CHECK(75, write(self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_write_value};
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
  DeclarationArgument* _DeclarationArgument27 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument27 == NULL) RAISE(80)
  *_DeclarationArgument27 = (DeclarationArgument){DeclarationArgument__dtl, 0, NULL, NULL};
  _DeclarationArgument27->_base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument27->_base);
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
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse = "FunctionArguments.parse";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse
Returncode FunctionArguments_parse(FunctionArguments* self, ArgumentFactory* argument_factory, Char* end) {
  self->parameters = malloc(sizeof(List));
  if (self->parameters == NULL) RAISE(89)
  *self->parameters = (List){NULL, NULL};
  self->outputs = malloc(sizeof(List));
  if (self->outputs == NULL) RAISE(90)
  *self->outputs = (List){NULL, NULL};
  CHECK(91, FunctionArguments_parse_args(self, self->parameters, argument_factory, &((*end))) )
  if ((*end) == '-') {
    CHECK(93, read_expect(&(String){3, 2, ">("}) )
    CHECK(94, FunctionArguments_parse_args(self, self->outputs, argument_factory, &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_FunctionArguments_parse_args = "FunctionArguments.parse-args";
#define MR_FUNC_NAME _func_name_FunctionArguments_parse_args
Returncode FunctionArguments_parse_args(FunctionArguments* self, List* arguments, ArgumentFactory* argument_factory, Char* end) {
  Argument* argument = NULL;
  String* access_str = NULL;
  Int _Int28;
  CHECK(101, read_until(&(String){3, 2, " )"}, false, &(access_str), &((*end)), &(_Int28)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(103, read_line_break_spaces() )
    Int _Int29;
    CHECK(104, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int29)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(108, f_syntax_error_c(&(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(110, f_syntax_error_c(&(String){20, 19, "expected space, got"}, (*end)) )
      }
      CHECK(111, (argument_factory)->_dtl[0](argument_factory, &(argument)) )
      CHECK(112, List_add(arguments, argument) )
      CHECK(113, Argument_parse(argument, access_str, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(115, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(117, read_line_break_spaces() )
      }
      else {
        if ((*end) != ' ') {
          CHECK(119, f_syntax_error_c(&(String){32, 31, "expected space or new-line, got"}, (*end)) )
        }
      }
      Int _Int30;
      CHECK(120, read_until(&(String){2, 1, " "}, false, &(access_str), &((*end)), &(_Int30)) )
    }
  }
  CHECK(121, read_c(&((*end))) )
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
  CHECK(124, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters->first) {
    CHECK(126, FunctionArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs->first) {
    CHECK(128, write(&(String){5, 4, ")->("}) )
    CHECK(129, FunctionArguments_write_args(self, self->outputs) )
  }
  CHECK(130, write(&(String){2, 1, ")"}) )
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
    CHECK(135, Argument_write(((Argument*)(node->item))) )
    node = node->next;
    if (!(NULL != node)) break;
    CHECK(138, write(&(String){3, 2, ", "}) )
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
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/loop.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
