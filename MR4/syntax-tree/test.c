#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/test.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file20_name = "syntax-tree/test.3.mr";
#endif
#define MR_FILE_NAME _mr_file20_name

/* MR4 compiler - Syntax tree testing nodes */

/* Assert statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeAssert SyntaxTreeAssert;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeAssert {
  SyntaxTreeCode _base;
  Expression* tested;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse_new = "SyntaxTreeAssert.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_parse_new
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssert));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (SyntaxTreeAssert){SyntaxTreeAssert__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssert__dtl;
  CHECK(10, SyntaxTreeAssert_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse = "SyntaxTreeAssert.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_parse
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(14, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(15, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->tested), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_analyze(SyntaxTreeAssert* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_analyze = "SyntaxTreeAssert.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_analyze
Returncode SyntaxTreeAssert_analyze(SyntaxTreeAssert* self) {
  CHECK(18, SyntaxTreeNode_analyze_expression(&(self->_base._base), self->tested, &(glob->type_bool->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_write = "SyntaxTreeAssert.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_write
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self) {
  /* TEST_ASSERT(`line`, `tested`) */
  CHECK(22, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(23, (self->tested)->_base._dtl[5](self->tested) )
  CHECK(24, write(&(String){13, 12, "TEST_ASSERT("}) )
  CHECK(25, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(26, write(&(String){3, 2, ", "}) )
  CHECK(27, (self->tested)->_base._dtl[2](self->tested) )
  CHECK(28, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssert__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssert__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssert_analyze, (void*)SyntaxTreeAssert_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif

/* Assert-error statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeAssertError SyntaxTreeAssertError;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeAssertError {
  SyntaxTreeCode _base;
  Expression* tested;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse_new = "SyntaxTreeAssertError.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_parse_new
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssertError));
  if ((*new_node) == NULL) RAISE(36)
  *(*new_node) = (SyntaxTreeAssertError){SyntaxTreeAssertError__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssertError__dtl;
  CHECK(37, SyntaxTreeAssertError_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse = "SyntaxTreeAssertError.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_parse
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(41, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(42, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->tested), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_analyze(SyntaxTreeAssertError* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_analyze = "SyntaxTreeAssertError.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_analyze
Returncode SyntaxTreeAssertError_analyze(SyntaxTreeAssertError* self) {
  CHECK(45, (self->tested)->_base._dtl[1](self->tested) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_write = "SyntaxTreeAssertError.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_write
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self) {
  CHECK(48, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(49, write(&(String){6, 5, "do {\n"}) )
  self->_base.parent->_base.indentation_spaces += 2;
  CHECK(51, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(52, write(&(String){25, 24, "MR_trace_stream = NULL;\n"}) )
  CHECK(53, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(54, write(&(String){35, 34, "#define RETURN_ERROR(value) break\n"}) )
  CHECK(55, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(56, (self->tested)->_base._dtl[5](self->tested) )
  CHECK(57, write(&(String){22, 21, "\n#undef RETURN_ERROR\n"}) )
  CHECK(58, write(&(String){42, 41, "#define RETURN_ERROR(value) return value\n"}) )
  CHECK(59, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(60, write(&(String){27, 26, "MR_trace_stream = stdout;\n"}) )
  CHECK(61, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(62, write(&(String){11, 10, "TEST_FAIL("}) )
  CHECK(63, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(64, write(&(String){3, 2, ")\n"}) )
  self->_base.parent->_base.indentation_spaces -= 2;
  CHECK(66, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(67, write(&(String){18, 17, "} while (false);\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssertError__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssertError__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssertError_analyze, (void*)SyntaxTreeAssertError_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Test function in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTestFunction SyntaxTreeTestFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeTestFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTestFunction_parse_new = "SyntaxTreeTestFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeTestFunction_parse_new
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeTestFunction));
  if ((*new_node) == NULL) RAISE(73)
  *(*new_node) = (SyntaxTreeTestFunction){SyntaxTreeTestFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeTestFunction__dtl;
  CHECK(74, SyntaxTreeTestFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTestFunction_parse(SyntaxTreeTestFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTestFunction_parse = "SyntaxTreeTestFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeTestFunction_parse
Returncode SyntaxTreeTestFunction_parse(SyntaxTreeTestFunction* self, Char* end) {
  CHECK(77, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  if ((NULL != self->_base.arguments->parameters->first) || (NULL != self->_base.arguments->outputs->first)) {
    CHECK(79, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){36, 35, "test function cannot have arguments"}) )
  }
  CHECK(80, NameMap_add(glob->test_functions, self->_base.name, self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTestFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTestFunction__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Mock function in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMockFunction SyntaxTreeMockFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMockFunction {
  SyntaxTreeFunction _base;
  String* mocked_name;
  String* type_name;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse_new = "SyntaxTreeMockFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse_new
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMockFunction));
  if ((*new_node) == NULL) RAISE(89)
  *(*new_node) = (SyntaxTreeMockFunction){SyntaxTreeMockFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, NULL, NULL};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMockFunction__dtl;
  CHECK(90, SyntaxTreeMockFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse(SyntaxTreeMockFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse = "SyntaxTreeMockFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse
Returncode SyntaxTreeMockFunction_parse(SyntaxTreeMockFunction* self, Char* end) {
  CHECK(93, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  Int index = 0;
  CHECK(95, String_find(self->_base.name, &(String){2, 1, "."}, &(index)) )
  if (index < self->_base.name->length) {
    if ((0) < 0 || (index) < 0 || (0) + (index) > (self->_base.name)->length) RAISE(97)
    CHECK(97, string_new_copy((&(String){index, index, (self->_base.name)->values + (0)}), &(self->type_name)) )
    if ((index + 1) < 0 || (self->_base.name->length - index - 1) < 0 || (index + 1) + (self->_base.name->length - index - 1) > (self->_base.name)->length) RAISE(98)
    CHECK(98, string_new_copy((&(String){self->_base.name->length - index - 1, self->_base.name->length - index - 1, (self->_base.name)->values + (index + 1)}), &(self->mocked_name)) )
    free(self->_base.name);
  }
  else {
    self->mocked_name = self->_base.name;
  }
  CHECK(103, string_new_concat(&(String){6, 5, "Mock "}, self->mocked_name, &(self->_base.name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_check_name(SyntaxTreeMockFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_check_name = "SyntaxTreeMockFunction.check-name";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_check_name
Returncode SyntaxTreeMockFunction_check_name(SyntaxTreeMockFunction* self) {
  /* do not check */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_analyze(SyntaxTreeMockFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_analyze = "SyntaxTreeMockFunction.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_analyze
Returncode SyntaxTreeMockFunction_analyze(SyntaxTreeMockFunction* self) {
  SyntaxTreeFunction* mocked_func = NULL;
  if (NULL != self->type_name) {
    CHECK(111, SyntaxTreeNode_find_type(&(self->_base._base._base._base), self->type_name, &(self->_base.parent_type)) )
    Int _Int106;
    CHECK(112, TypeData_find_meth(self->_base.parent_type, self->mocked_name, &(mocked_func), &(_Int106)) )
    if (!(NULL != mocked_func)) {
      CHECK(114, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base._base), &(String){23, 22, "mocking unknown method"}, self->mocked_name, &(String){8, 7, "of type"}, self->type_name) )
    }
    TypeInstance* _TypeInstance107;
    CHECK(119, TypeData_m_new_type_instance(self->_base.parent_type, &(_TypeInstance107)) )
    CHECK(119, FunctionArguments_add_self_parameter(self->_base.arguments, _TypeInstance107) )
  }
  else {
    CHECK(122, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->mocked_name, &(mocked_func)) )
    if (!(NULL != mocked_func)) {
      CHECK(124, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){25, 24, "mocking unknown function"}, self->mocked_name) )
    }
  }
  Bool _Bool108;
  CHECK(126, FunctionArguments_check_same_as(self->_base.arguments, mocked_func->arguments, &(_Bool108)) )
  mocked_func->mocker_function = self;
  CHECK(128, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMockFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMockFunction__dtl[] = {(void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeMockFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMockFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
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
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
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
