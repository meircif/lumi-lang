#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/test.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file26_name = "statement/test.3.mr";
#endif
#define MR_FILE_NAME _mr_file26_name

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
  CHECK(23, (self->tested)->_base._dtl[8](self->tested) )
  CHECK(24, write(&(String){13, 12, "TEST_ASSERT("}) )
  CHECK(25, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(26, write(&(String){3, 2, ", "}) )
  CHECK(27, (self->tested)->_base._dtl[3](self->tested) )
  CHECK(28, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssert__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssert__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssert_analyze, (void*)SyntaxTreeAssert_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif

/* Assert-error statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeAssertError SyntaxTreeAssertError;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeAssertError {
  SyntaxTreeCode _base;
  Expression* tested;
  String* expected_error;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse_new = "SyntaxTreeAssertError.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_parse_new
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssertError));
  if ((*new_node) == NULL) RAISE(37)
  *(*new_node) = (SyntaxTreeAssertError){SyntaxTreeAssertError__dtl, NULL, 0, NULL, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssertError__dtl;
  CHECK(38, SyntaxTreeAssertError_parse((*new_node), parent, &((*end))) )
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
  CHECK(42, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(43, parse_new_expression(&(String){2, 1, ","}, &(self->_base), &(self->tested), &((*end))) )
  if ((*end) == ',') {
    CHECK(45, read_c(&((*end))) )
    if ((*end) == '\n') {
      CHECK(47, SyntaxTreeCode_read_line_break_spaces(&(self->_base)) )
    }
    else {
      if ((*end) != ' ') {
        CHECK(49, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){30, 29, "expected space after \",\", got"}, (*end)) )
      }
    }
    CHECK(50, read_new(&(String){1, 0, ""}, &(self->expected_error), &((*end))) )
    CHECK(51, SyntaxTreeNode_check_string(&(self->_base._base), self->expected_error) )
  }
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
  CHECK(54, (self->tested)->_base._dtl[2](self->tested) )
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
  if (NULL != self->expected_error) {
    CHECK(58, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(59, write(&(String){32, 31, "{char* MR_expected_error_prev;\n"}) )
    CHECK(60, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(61, write(&(String){48, 47, "int MR_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(62, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(63, write(&(String){45, 44, "MR_expected_error_prev = MR_expected_error;\n"}) )
    CHECK(64, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(65, write(&(String){44, 43, "MR_expected_error_trace_ignore_count_prev ="}) )
    CHECK(66, write(&(String){40, 39, " MR_expected_error_trace_ignore_count;\n"}) )
    CHECK(67, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(68, write(&(String){21, 20, "MR_expected_error = "}) )
    CHECK(69, write(self->expected_error) )
    CHECK(70, write(&(String){3, 2, ";\n"}) )
    CHECK(71, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(72, write(&(String){39, 38, "MR_expected_error_trace_ignore_count ="}) )
    CHECK(73, write(&(String){29, 28, " MR_trace_ignore_count + 1;\n"}) )
  }
  CHECK(74, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(75, write(&(String){6, 5, "do {\n"}) )
  self->_base.parent->_base.indentation_spaces += 2;
  CHECK(77, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(78, write(&(String){26, 25, "++MR_trace_ignore_count;\n"}) )
  CHECK(79, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(80, write(&(String){35, 34, "#define RETURN_ERROR(value) break\n"}) )
  CHECK(81, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(82, (self->tested)->_base._dtl[8](self->tested) )
  CHECK(83, write(&(String){22, 21, "\n#undef RETURN_ERROR\n"}) )
  CHECK(84, write(&(String){61, 60, "#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup\n"}) )
  CHECK(85, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(86, write(&(String){26, 25, "--MR_trace_ignore_count;\n"}) )
  if (NULL != self->expected_error) {
    CHECK(88, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(89, write(&(String){39, 38, "MR_expected_error_trace_ignore_count ="}) )
    CHECK(90, write(&(String){45, 44, " MR_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(91, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(92, write(&(String){45, 44, "MR_expected_error = MR_expected_error_prev;\n"}) )
  }
  CHECK(93, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(94, write(&(String){11, 10, "TEST_FAIL("}) )
  CHECK(95, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(96, write(&(String){27, 26, ", 16, \"error not raised\")\n"}) )
  self->_base.parent->_base.indentation_spaces -= 2;
  CHECK(98, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(99, write(&(String){18, 17, "} while (false);\n"}) )
  CHECK(100, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(101, write(&(String){26, 25, "--MR_trace_ignore_count;\n"}) )
  if (NULL != self->expected_error) {
    CHECK(103, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(104, write(&(String){39, 38, "MR_expected_error_trace_ignore_count ="}) )
    CHECK(105, write(&(String){45, 44, " MR_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(106, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(107, write(&(String){34, 33, "if (MR_expected_error == NULL) {\n"}) )
    CHECK(108, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(109, write(&(String){47, 46, "  MR_expected_error = MR_expected_error_prev;\n"}) )
    CHECK(110, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(111, write(&(String){18, 17, "  TEST_FAIL_NULL("}) )
    CHECK(112, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
    CHECK(113, write(&(String){3, 2, ")\n"}) )
    CHECK(114, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(115, write(&(String){3, 2, "}\n"}) )
    CHECK(116, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(117, write(&(String){46, 45, "MR_expected_error = MR_expected_error_prev;}\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssertError__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssertError__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssertError_analyze, (void*)SyntaxTreeAssertError_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if ((*new_node) == NULL) RAISE(123)
  *(*new_node) = (SyntaxTreeTestFunction){SyntaxTreeTestFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeTestFunction__dtl;
  CHECK(124, SyntaxTreeTestFunction_parse((*new_node), &((*end))) )
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
  CHECK(127, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  if ((NULL != self->_base.arguments->parameters->first) || (NULL != self->_base.arguments->outputs->first)) {
    CHECK(129, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){36, 35, "test function cannot have arguments"}) )
  }
  CHECK(130, NameMap_add(glob->test_functions, self->_base.name, self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTestFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTestFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Mock function in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMockFunction SyntaxTreeMockFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMockFunction {
  SyntaxTreeFunction _base;
  String* mocked_name;
  String* type_name;
  SyntaxTreeFunction* mocked_function;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse_new = "SyntaxTreeMockFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse_new
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMockFunction));
  if ((*new_node) == NULL) RAISE(140)
  *(*new_node) = (SyntaxTreeMockFunction){SyntaxTreeMockFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, NULL, NULL, NULL};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMockFunction__dtl;
  CHECK(141, SyntaxTreeMockFunction_parse((*new_node), &((*end))) )
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
  CHECK(144, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  self->_base.mocker_function = self;
  Int index = 0;
  CHECK(147, String_find(self->_base.name, &(String){2, 1, "."}, &(index)) )
  if (index < self->_base.name->length) {
    if ((0) < 0 || (index) < 0 || (0) + (index) > (self->_base.name)->length) RAISE(149)
    CHECK(149, string_new_copy((&(String){index, index, (self->_base.name)->values + (0)}), &(self->type_name)) )
    if ((index + 1) < 0 || (self->_base.name->length - index - 1) < 0 || (index + 1) + (self->_base.name->length - index - 1) > (self->_base.name)->length) RAISE(150)
    CHECK(150, string_new_copy((&(String){self->_base.name->length - index - 1, self->_base.name->length - index - 1, (self->_base.name)->values + (index + 1)}), &(self->mocked_name)) )
    free(self->_base.name);
  }
  else {
    self->mocked_name = self->_base.name;
  }
  Bool _Bool138;
  CHECK(155, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool138)) )
  if (NULL != self->type_name && _Bool138) {
    CHECK(156, string_new_copy(&(String){8, 7, "MockDel"}, &(self->_base.name)) )
  }
  else {
    CHECK(158, string_new_concat(self->mocked_name, &(String){6, 5, " Mock"}, &(self->_base.name)) )
  }
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
  if (NULL != self->type_name) {
    CHECK(165, SyntaxTreeNode_find_type(&(self->_base._base._base._base), self->type_name, &(self->_base.parent_type)) )
    Bool _Bool139;
    CHECK(166, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool139)) )
    if (_Bool139) {
      if (self->_base.parent_type->is_delete_mocked) {
        CHECK(168, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "already mocking delete of type"}, self->type_name) )
      }
      self->_base.parent_type->is_delete_mocked = true;
      CHECK(171, FunctionArguments_add_self_parameter(self->_base.arguments, &(glob->type_ref->_base)) )
    }
    else {
      Int _Int140;
      CHECK(173, TypeData_find_meth(self->_base.parent_type, self->mocked_name, &(self->mocked_function), &(_Int140)) )
      if (!(NULL != self->mocked_function)) {
        CHECK(176, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base._base), &(String){23, 22, "mocking unknown method"}, self->mocked_name, &(String){8, 7, "of type"}, self->type_name) )
      }
      CHECK(181, FunctionArguments_add_self_parameter(self->_base.arguments, self->_base.parent_type) )
    }
  }
  else {
    Bool _Bool141;
    CHECK(182, String_equal(self->mocked_name, &(String){4, 3, "new"}, &(_Bool141)) )
    if (_Bool141) {
      if (glob->is_new_mocked) {
        CHECK(184, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){27, 26, "already mocking global new"}) )
      }
      if (NULL != self->_base.arguments->parameters->first ||  ! (NULL != self->_base.arguments->outputs->first) ||  NULL !=  self->_base.arguments->outputs->first->next) {
        CHECK(188, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){45, 44, "mock new should have only single Bool output"}) )
      }
      TypeInstance* _TypeInstance142;
      CHECK(190, (((Argument*)(self->_base.arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->_base.arguments->outputs->first->item)), &(_TypeInstance142)) )
      if (_TypeInstance142->type_data != &(glob->type_bool->_base)) {
        CHECK(192, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){45, 44, "mock new should have only single Bool output"}) )
      }
      glob->is_new_mocked = true;
    }
    else {
      Bool _Bool143;
      CHECK(195, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool143)) )
      if (_Bool143) {
        if (glob->is_delete_mocked) {
          CHECK(197, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){30, 29, "already mocking global delete"}) )
        }
        glob->is_delete_mocked = true;
        if (NULL != self->_base.arguments->parameters->first ||  NULL !=  self->_base.arguments->outputs->first) {
          CHECK(200, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){37, 36, "mock delete should have no arguments"}) )
        }
        CHECK(201, FunctionArguments_add_self_parameter(self->_base.arguments, &(glob->type_ref->_base)) )
      }
      else {
        CHECK(203, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->mocked_name, &(self->mocked_function)) )
        if (!(NULL != self->mocked_function)) {
          CHECK(205, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){25, 24, "mocking unknown function"}, self->mocked_name) )
        }
      }
    }
  }
  if (NULL != self->mocked_function) {
    if (NULL != self->mocked_function->mocker_function) {
      CHECK(209, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){25, 24, "already mocking function"}, self->mocked_name) )
    }
    Bool _Bool144;
    CHECK(211, FunctionArguments_check_same_as(self->_base.arguments, self->mocked_function->arguments, NULL, 0, &(_Bool144)) )
    self->mocked_function->mocker_function = self;
  }
  CHECK(214, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_write(SyntaxTreeMockFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write = "SyntaxTreeMockFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_write
Returncode SyntaxTreeMockFunction_write(SyntaxTreeMockFunction* self) {
  if (NULL != self->mocked_function) {
    /* Bool `name`_active = true; */
    CHECK(219, write(&(String){7, 6, "\nBool "}) )
    CHECK(220, SyntaxTreeFunction_write_cname(&(self->_base)) )
    CHECK(221, write(&(String){16, 15, "_active = true;"}) )
  }
  CHECK(222, SyntaxTreeFunction_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_write_block_body(SyntaxTreeMockFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write_block_body = "SyntaxTreeMockFunction.write-block-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_write_block_body
Returncode SyntaxTreeMockFunction_write_block_body(SyntaxTreeMockFunction* self) {
  if (NULL != self->mocked_function) {
    /* if (!`name`_active) return `name`(`arguments`); */
    CHECK(227, write(&(String){8, 7, "  if (!"}) )
    CHECK(228, SyntaxTreeFunction_write_cname(&(self->_base)) )
    CHECK(229, write(&(String){17, 16, "_active) return "}) )
    CHECK(230, SyntaxTreeFunction_write_cname(self->mocked_function) )
    CHECK(231, write(&(String){2, 1, "("}) )
    Bool first = true;
    CHECK(233, SyntaxTreeMockFunction_write_arg_list(self, self->_base.arguments->parameters, &(first)) )
    CHECK(234, SyntaxTreeMockFunction_write_arg_list(self, self->_base.arguments->outputs, &(first)) )
    CHECK(235, write(&(String){4, 3, ");\n"}) )
  }
  CHECK(236, SyntaxTreeBlock_write_block_body(&(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_write_arg_list(SyntaxTreeMockFunction* self, List* list, Bool* first);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write_arg_list = "SyntaxTreeMockFunction.write-arg-list";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_write_arg_list
Returncode SyntaxTreeMockFunction_write_arg_list(SyntaxTreeMockFunction* self, List* list, Bool* first) {
  ListNode* node = list->first;
  while (true) {
    if (!(NULL != node)) break;
    if (!(*first)) {
      CHECK(244, write(&(String){3, 2, ", "}) )
    }
    SyntaxTreeVariable* variable = NULL;
    CHECK(246, (((Argument*)(node->item)))->_base._dtl[8](((Argument*)(node->item)), &(variable)) )
    CHECK(247, write_cname(variable->name) )
    if (!variable->type_instance->type_data->is_primitive) {
      CHECK(249, write(&(String){3, 2, ", "}) )
      CHECK(250, write_cname(variable->name) )
      CHECK(251, write(&(String){8, 7, "_Refman"}) )
    }
    if (variable->type_instance->type_data->is_dynamic) {
      CHECK(253, write(&(String){3, 2, ", "}) )
      CHECK(254, write_cname(variable->name) )
      CHECK(255, write(&(String){9, 8, "_Dynamic"}) )
    }
    (*first) = false;
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMockFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMockFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeMockFunction_analyze, (void*)SyntaxTreeMockFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMockFunction_write_block_body, (void*)SyntaxTreeMockFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
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
