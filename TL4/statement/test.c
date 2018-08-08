#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "statement/test.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file28_name = "statement/test.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file28_name

/* TL4 compiler - Syntax tree testing nodes */

/* Assert statement in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeAssert SyntaxTreeAssert;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeAssert {
  SyntaxTreeCode _base;
  Expression* tested;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse_new = "SyntaxTreeAssert.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssert_parse_new
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssert));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (SyntaxTreeAssert){SyntaxTreeAssert__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssert__dtl;
  CHECK(10, SyntaxTreeAssert_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse = "SyntaxTreeAssert.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssert_parse
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(14, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(15, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->tested), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssert_analyze(SyntaxTreeAssert* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_analyze = "SyntaxTreeAssert.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssert_analyze
Returncode SyntaxTreeAssert_analyze(SyntaxTreeAssert* self) {
  CHECK(18, SyntaxTreeNode_analyze_expression(&(self->_base._base), self->tested, glob->type_bool) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_write = "SyntaxTreeAssert.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssert_write
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self) {
  /* TEST_ASSERT(`line`, `tested`) */
  CHECK(22, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(23, (self->tested)->_base._dtl[9](self->tested) )
  CHECK(24, write(&(String){13, 12, "TEST_ASSERT("}) )
  CHECK(25, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(26, write(&(String){3, 2, ", "}) )
  CHECK(27, (self->tested)->_base._dtl[4](self->tested) )
  CHECK(28, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeAssert__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeAssert__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssert_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeAssert_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif

/* Assert-error statement in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeAssertError SyntaxTreeAssertError;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeAssertError {
  SyntaxTreeCode _base;
  Expression* tested;
  String* expected_error;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse_new = "SyntaxTreeAssertError.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssertError_parse_new
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssertError));
  if ((*new_node) == NULL) RAISE(37)
  *(*new_node) = (SyntaxTreeAssertError){SyntaxTreeAssertError__dtl, NULL, 0, NULL, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssertError__dtl;
  CHECK(38, SyntaxTreeAssertError_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse = "SyntaxTreeAssertError.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssertError_parse
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(42, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(43, parse_new_expression(&(String){2, 1, ","}, &(self->_base), &(self->tested), &((*end))) )
  if ((*end) == ',') {
    CHECK(45, read_c(&((*end))) )
    if ((*end) == '\n') {
      CHECK(47, SyntaxTreeCode_read_parent_line_break_spaces(&(self->_base)) )
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
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssertError_analyze(SyntaxTreeAssertError* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_analyze = "SyntaxTreeAssertError.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssertError_analyze
Returncode SyntaxTreeAssertError_analyze(SyntaxTreeAssertError* self) {
  CHECK(54, (self->tested)->_base._dtl[2](self->tested) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_write = "SyntaxTreeAssertError.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeAssertError_write
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self) {
  if (NULL != self->expected_error) {
    CHECK(58, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(59, write(&(String){34, 33, "{char* LUMI_expected_error_prev;\n"}) )
    CHECK(60, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(61, write(&(String){50, 49, "int LUMI_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(62, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(63, write(&(String){49, 48, "LUMI_expected_error_prev = LUMI_expected_error;\n"}) )
    CHECK(64, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(65, write(&(String){46, 45, "LUMI_expected_error_trace_ignore_count_prev ="}) )
    CHECK(66, write(&(String){42, 41, " LUMI_expected_error_trace_ignore_count;\n"}) )
    CHECK(67, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(68, write(&(String){23, 22, "LUMI_expected_error = "}) )
    CHECK(69, write(self->expected_error) )
    CHECK(70, write(&(String){3, 2, ";\n"}) )
    CHECK(71, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(72, write(&(String){41, 40, "LUMI_expected_error_trace_ignore_count ="}) )
    CHECK(73, write(&(String){31, 30, " LUMI_trace_ignore_count + 1;\n"}) )
  }
  CHECK(74, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(75, write(&(String){6, 5, "do {\n"}) )
  self->_base.parent->_base.indentation_spaces += 2;
  CHECK(77, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(78, write(&(String){28, 27, "++LUMI_trace_ignore_count;\n"}) )
  CHECK(79, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(80, write(&(String){28, 27, "#define RETURN_ERROR break\n"}) )
  CHECK(81, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(82, (self->tested)->_base._dtl[9](self->tested) )
  CHECK(83, write(&(String){22, 21, "\n#undef RETURN_ERROR\n"}) )
  CHECK(84, write(&(String){40, 39, "#define RETURN_ERROR goto LUMI_cleanup\n"}) )
  CHECK(85, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(86, write(&(String){28, 27, "--LUMI_trace_ignore_count;\n"}) )
  if (NULL != self->expected_error) {
    CHECK(88, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(89, write(&(String){41, 40, "LUMI_expected_error_trace_ignore_count ="}) )
    CHECK(90, write(&(String){47, 46, " LUMI_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(91, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(92, write(&(String){49, 48, "LUMI_expected_error = LUMI_expected_error_prev;\n"}) )
  }
  CHECK(93, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(94, write(&(String){11, 10, "TEST_FAIL("}) )
  CHECK(95, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(96, write(&(String){27, 26, ", 16, \"error not raised\")\n"}) )
  self->_base.parent->_base.indentation_spaces -= 2;
  CHECK(98, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(99, write(&(String){18, 17, "} while (false);\n"}) )
  CHECK(100, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(101, write(&(String){28, 27, "--LUMI_trace_ignore_count;\n"}) )
  if (NULL != self->expected_error) {
    CHECK(103, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(104, write(&(String){41, 40, "LUMI_expected_error_trace_ignore_count ="}) )
    CHECK(105, write(&(String){47, 46, " LUMI_expected_error_trace_ignore_count_prev;\n"}) )
    CHECK(106, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(107, write(&(String){36, 35, "if (LUMI_expected_error == NULL) {\n"}) )
    CHECK(108, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(109, write(&(String){51, 50, "  LUMI_expected_error = LUMI_expected_error_prev;\n"}) )
    CHECK(110, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(111, write(&(String){18, 17, "  TEST_FAIL_NULL("}) )
    CHECK(112, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
    CHECK(113, write(&(String){3, 2, ")\n"}) )
    CHECK(114, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(115, write(&(String){3, 2, "}\n"}) )
    CHECK(116, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(117, write(&(String){50, 49, "LUMI_expected_error = LUMI_expected_error_prev;}\n"}) )
  }
  CHECK(118, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(119, write(&(String){16, 15, "LUMI_err = OK;\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeAssertError__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeAssertError__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeAssertError_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeAssertError_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Test function in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeTestFunction SyntaxTreeTestFunction;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct SyntaxTreeTestFunction {
  SyntaxTreeFunction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeTestFunction_parse_new = "SyntaxTreeTestFunction.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeTestFunction_parse_new
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeTestFunction));
  if ((*new_node) == NULL) RAISE(125)
  *(*new_node) = (SyntaxTreeTestFunction){SyntaxTreeTestFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeTestFunction__dtl;
  CHECK(126, SyntaxTreeTestFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeTestFunction_parse(SyntaxTreeTestFunction* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeTestFunction_parse = "SyntaxTreeTestFunction.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeTestFunction_parse
Returncode SyntaxTreeTestFunction_parse(SyntaxTreeTestFunction* self, Char* end) {
  CHECK(129, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  if ((NULL != self->_base.arguments->parameters->first) || (NULL != self->_base.arguments->outputs->first)) {
    CHECK(131, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){36, 35, "test function cannot have arguments"}) )
  }
  CHECK(132, NameMap_add(glob->test_functions, self->_base.name, self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeTestFunction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeTestFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Mock function in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeMockFunction SyntaxTreeMockFunction;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct SyntaxTreeMockFunction {
  SyntaxTreeFunction _base;
  String* mocked_name;
  String* type_name;
  String* module_name;
  SyntaxTreeFunction* mocked_function;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse_new = "SyntaxTreeMockFunction.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse_new
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMockFunction));
  if ((*new_node) == NULL) RAISE(143)
  *(*new_node) = (SyntaxTreeMockFunction){SyntaxTreeMockFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMockFunction__dtl;
  CHECK(144, SyntaxTreeMockFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse(SyntaxTreeMockFunction* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse = "SyntaxTreeMockFunction.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse
Returncode SyntaxTreeMockFunction_parse(SyntaxTreeMockFunction* self, Char* end) {
  CHECK(147, SyntaxTreeFunction_parse(&(self->_base), NULL, &((*end))) )
  self->_base.mocker_function = self;
  Int index = 0;
  CHECK(150, String_find(self->_base.name, &(String){2, 1, "."}, &(index)) )
  if (index < self->_base.name->length) {
    if ((0) < 0 || (index) < 0 || (0) + (index) > (self->_base.name)->length) RAISE(152)
    String* first = (&(String){index, index, (self->_base.name)->values + (0)});
    if ((index + 1) < 0 || (self->_base.name->length - index - 1) < 0 || (index + 1) + (self->_base.name->length - index - 1) > (self->_base.name)->length) RAISE(153)
    String* last = (&(String){self->_base.name->length - index - 1, self->_base.name->length - index - 1, (self->_base.name)->values + (index + 1)});
    CHECK(154, String_find(last, &(String){2, 1, "."}, &(index)) )
    if (index < last->length) {
      CHECK(156, string_new_copy(first, &(self->module_name)) )
      if ((0) < 0 || (index) < 0 || (0) + (index) > (last)->length) RAISE(157)
      first = (&(String){index, index, (last)->values + (0)});
      if ((index + 1) < 0 || (last->length - index - 1) < 0 || (index + 1) + (last->length - index - 1) > (last)->length) RAISE(158)
      last = (&(String){last->length - index - 1, last->length - index - 1, (last)->values + (index + 1)});
      CHECK(159, string_new_copy(first, &(self->type_name)) )
    }
    else {
      if ((0) < 0 || (0) >= (first)->length) RAISE(161)
      Char ch = ((first)->values[0]);
      if (ch >= 'a' && ch <= 'z') {
        CHECK(163, string_new_copy(first, &(self->module_name)) )
      }
      else {
        CHECK(165, string_new_copy(first, &(self->type_name)) )
      }
    }
    CHECK(166, string_new_copy(last, &(self->mocked_name)) )
    free(self->_base.name);
  }
  else {
    self->mocked_name = self->_base.name;
  }
  Bool _Bool176;
  CHECK(170, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool176)) )
  if (NULL != self->type_name && _Bool176) {
    CHECK(171, string_new_copy(&(String){8, 7, "MockDel"}, &(self->_base.name)) )
  }
  else {
    CHECK(173, string_new_concat(self->mocked_name, &(String){6, 5, " Mock"}, &(self->_base.name)) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_f_register_name(SyntaxTreeMockFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_f_register_name = "SyntaxTreeMockFunction.f-register-name";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_f_register_name
Returncode SyntaxTreeMockFunction_f_register_name(SyntaxTreeMockFunction* self) {
  /* do not register */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_link_types(SyntaxTreeMockFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_link_types = "SyntaxTreeMockFunction.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_link_types
Returncode SyntaxTreeMockFunction_link_types(SyntaxTreeMockFunction* self) {
  glob->current_module = self->_base.my_module;
  if (NULL != self->type_name) {
    CHECK(181, SyntaxTreeNode_find_type(&(self->_base._base._base._base), self->type_name, self->module_name, &(self->_base.parent_type)) )
    Bool _Bool177;
    CHECK(183, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool177)) )
    if (_Bool177) {
      if (self->_base.parent_type->is_delete_mocked) {
        CHECK(185, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "already mocking delete of type"}, self->type_name) )
      }
      self->_base.parent_type->is_delete_mocked = true;
      CHECK(188, FunctionArguments_add_self_parameter(self->_base.arguments, glob->type_ref) )
    }
    else {
      Int _Int178;
      CHECK(190, TypeData_find_meth(self->_base.parent_type, self->mocked_name, &(self->mocked_function), &(_Int178)) )
      if (!(NULL != self->mocked_function)) {
        CHECK(193, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base._base), &(String){23, 22, "mocking unknown method"}, self->mocked_name, &(String){8, 7, "of type"}, self->type_name) )
      }
      CHECK(198, FunctionArguments_add_self_parameter(self->_base.arguments, self->_base.parent_type) )
    }
  }
  else {
    Bool _Bool179;
    CHECK(199, String_equal(self->mocked_name, &(String){4, 3, "new"}, &(_Bool179)) )
    if (_Bool179) {
      if (glob->is_new_mocked) {
        CHECK(201, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){27, 26, "already mocking global new"}) )
      }
      glob->is_new_mocked = true;
    }
    else {
      Bool _Bool180;
      CHECK(203, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool180)) )
      if (_Bool180) {
        if (glob->is_delete_mocked) {
          CHECK(205, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){30, 29, "already mocking global delete"}) )
        }
        if (NULL != self->_base.arguments->parameters->first ||  NULL !=  self->_base.arguments->outputs->first) {
          CHECK(207, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){37, 36, "mock delete should have no arguments"}) )
        }
        glob->is_delete_mocked = true;
        CHECK(209, FunctionArguments_add_self_parameter(self->_base.arguments, glob->type_ref) )
      }
      else {
        CHECK(211, SyntaxTreeNode_find_function(&(self->_base._base._base._base), self->mocked_name, self->module_name, &(self->mocked_function)) )
        if (!(NULL != self->mocked_function)) {
          CHECK(214, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){25, 24, "mocking unknown function"}, self->mocked_name) )
        }
      }
    }
  }
  if (NULL != self->mocked_function) {
    if (NULL != self->mocked_function->mocker_function) {
      CHECK(218, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){25, 24, "already mocking function"}, self->mocked_name) )
    }
    self->mocked_function->mocker_function = self;
  }
  CHECK(221, SyntaxTreeFunction_link_types(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_analyze(SyntaxTreeMockFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_analyze = "SyntaxTreeMockFunction.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_analyze
Returncode SyntaxTreeMockFunction_analyze(SyntaxTreeMockFunction* self) {
  glob->current_module = self->_base.my_module;
  Bool _Bool181;
  CHECK(225, String_equal(self->mocked_name, &(String){4, 3, "new"}, &(_Bool181)) )
  if (!(NULL != self->type_name) && _Bool181) {
    if (NULL != self->_base.arguments->parameters->first ||  ! (NULL != self->_base.arguments->outputs->first) ||  NULL !=  self->_base.arguments->outputs->first->next) {
      CHECK(229, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){45, 44, "mock new should have only single Bool output"}) )
    }
    TypeInstance* _TypeInstance182;
    CHECK(231, (((Argument*)(self->_base.arguments->outputs->first->item)))->_base._dtl[7](((Argument*)(self->_base.arguments->outputs->first->item)), &(_TypeInstance182)) )
    if (_TypeInstance182->type_data != glob->type_bool) {
      CHECK(233, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){45, 44, "mock new should have only single Bool output"}) )
    }
    self->_base.my_module = NULL;
  }
  else {
    Bool _Bool183;
    CHECK(236, String_equal(self->mocked_name, &(String){7, 6, "delete"}, &(_Bool183)) )
    if (_Bool183) {
      self->_base.my_module = NULL;
    }
  }
  if (NULL != self->mocked_function) {
    Bool _Bool184;
    CHECK(239, FunctionArguments_check_same_as(self->_base.arguments, self->mocked_function->arguments, NULL, 0, &(_Bool184)) )
    self->_base.my_module = self->mocked_function->my_module;
  }
  CHECK(242, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_write_declaration(SyntaxTreeMockFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write_declaration = "SyntaxTreeMockFunction.write-declaration";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_write_declaration
Returncode SyntaxTreeMockFunction_write_declaration(SyntaxTreeMockFunction* self) {
  CHECK(245, SyntaxTreeFunction_write_declaration(&(self->_base)) )
  if (NULL != self->mocked_function) {
    /* Bool `name`_active = true; */
    CHECK(248, write(&(String){7, 6, "\nBool "}) )
    CHECK(249, SyntaxTreeFunction_write_cname(&(self->_base)) )
    CHECK(250, write(&(String){16, 15, "_active = true;"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_write_block_body(SyntaxTreeMockFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write_block_body = "SyntaxTreeMockFunction.write-block-body";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_write_block_body
Returncode SyntaxTreeMockFunction_write_block_body(SyntaxTreeMockFunction* self) {
  if (NULL != self->mocked_function) {
    /* if (!`name`_active) return `name`(`arguments`); */
    CHECK(255, write(&(String){8, 7, "  if (!"}) )
    CHECK(256, SyntaxTreeFunction_write_cname(&(self->_base)) )
    CHECK(257, write(&(String){17, 16, "_active) return "}) )
    CHECK(258, SyntaxTreeFunction_write_cname(self->mocked_function) )
    CHECK(259, write(&(String){2, 1, "("}) )
    Bool first = true;
    CHECK(261, SyntaxTreeMockFunction_write_arg_list(self, self->_base.arguments->parameters, &(first)) )
    CHECK(262, SyntaxTreeMockFunction_write_arg_list(self, self->_base.arguments->outputs, &(first)) )
    CHECK(263, write(&(String){4, 3, ");\n"}) )
  }
  CHECK(264, SyntaxTreeBlock_write_block_body(&(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMockFunction_write_arg_list(SyntaxTreeMockFunction* self, List* list, Bool* first);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_write_arg_list = "SyntaxTreeMockFunction.write-arg-list";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMockFunction_write_arg_list
Returncode SyntaxTreeMockFunction_write_arg_list(SyntaxTreeMockFunction* self, List* list, Bool* first) {
  ListNode* node = list->first;
  while (true) {
    if (!(NULL != node)) break;
    if (!(*first)) {
      CHECK(272, write(&(String){3, 2, ", "}) )
    }
    SyntaxTreeVariable* variable = NULL;
    CHECK(274, (((Argument*)(node->item)))->_base._dtl[9](((Argument*)(node->item)), &(variable)) )
    CHECK(275, write_cname(variable->name) )
    if (!variable->type_instance->type_data->is_primitive) {
      CHECK(277, write(&(String){3, 2, ", "}) )
      CHECK(278, write_cname(variable->name) )
      CHECK(279, write(&(String){8, 7, "_Refman"}) )
    }
    if (variable->type_instance->type_data->is_dynamic) {
      CHECK(281, write(&(String){3, 2, ", "}) )
      CHECK(282, write_cname(variable->name) )
      CHECK(283, write(&(String){9, 8, "_Dynamic"}) )
    }
    (*first) = false;
    node = node->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeMockFunction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeMockFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeMockFunction_link_types, (void*)SyntaxTreeMockFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMockFunction_write_block_body, (void*)SyntaxTreeMockFunction_f_register_name, (void*)SyntaxTreeMockFunction_write_declaration};
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
#include "statement/function.c"
#include "statement/native.c"
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
