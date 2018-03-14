static char* _mr_file14_name = "test.2.lm";
#define LUMI_FILE_NAME _mr_file14_name
/* TL3 compiler - testing */

typedef struct St_assert St_assert; struct St_assert {
  St _base;
  Mexp* condition;
};
static char* _func_name_St_assert_parse = "St-assert.parse";
#define LUMI_FUNC_NAME _func_name_St_assert_parse
Returncode St_assert_parse(St_assert* self) {
  Char _Char0;
  CHECK(7, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char0)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_analyze_first = "St-assert.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_assert_analyze_first
Returncode St_assert_analyze_first(St_assert* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_analyze = "St-assert.analyze";
#define LUMI_FUNC_NAME _func_name_St_assert_analyze
Returncode St_assert_analyze(St_assert* self) {
  CHECK(13, Mexp_analyze_type(self->condition, glob->type_bool));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_write = "St-assert.write";
#define LUMI_FUNC_NAME _func_name_St_assert_write
Returncode St_assert_write(St_assert* self) {
  CHECK(16, Mexp_write_intro(self->condition));
  CHECK(17, write(&(String){13, 12, "TEST_ASSERT("}));
  CHECK(18, write_line_num());
  CHECK(19, write(&(String){3, 2, ", "}));
  CHECK(20, Mexp_write_final(self->condition));
  CHECK(21, write(&(String){2, 1, ")"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_assert__dtl[] = {St_assert_parse, St_assert_analyze_first, St_assert_analyze, St_assert_write};


typedef struct St_assert_error St_assert_error; struct St_assert_error {
  St _base;
  Mexp* exp;
};
static char* _func_name_St_assert_error_parse = "St-assert-error.parse";
#define LUMI_FUNC_NAME _func_name_St_assert_error_parse
Returncode St_assert_error_parse(St_assert_error* self) {
  Char _Char1;
  CHECK(28, parse_new_exp(&(String){1, 0, ""}, &(self->exp), &(_Char1)));
  self->exp->is_used = false;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_error_analyze_first = "St-assert-error.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_assert_error_analyze_first
Returncode St_assert_error_analyze_first(St_assert_error* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_error_analyze = "St-assert-error.analyze";
#define LUMI_FUNC_NAME _func_name_St_assert_error_analyze
Returncode St_assert_error_analyze(St_assert_error* self) {
  CHECK(35, Mexp_analyze_type(self->exp, NULL));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_assert_error_write = "St-assert-error.write";
#define LUMI_FUNC_NAME _func_name_St_assert_error_write
Returncode St_assert_error_write(St_assert_error* self) {
  CHECK(38, write(&(String){23, 22, "_trace_stream = NULL;\n"}));
  CHECK(39, write_spaces());
  CHECK(40, write(&(String){6, 5, "do {\n"}));
  glob->spaces = glob->spaces + 2;
  CHECK(42, write(&(String){21, 20, "#undef RETURN_ERROR\n"}));
  CHECK(43, write(&(String){35, 34, "#define RETURN_ERROR(value) break\n"}));
  CHECK(44, write_spaces());
  CHECK(45, Mexp_write_intro(self->exp));
  CHECK(46, Mexp_write_final(self->exp));
  CHECK(47, write(&(String){3, 2, ";\n"}));
  CHECK(48, write(&(String){21, 20, "#undef RETURN_ERROR\n"}));
  CHECK(49, write(&(String){42, 41, "#define RETURN_ERROR(value) return value\n"}));
  CHECK(50, write_spaces());
  CHECK(51, write(&(String){25, 24, "_trace_stream = stdout;\n"}));
  CHECK(52, write_spaces());
  CHECK(53, write(&(String){11, 10, "TEST_FAIL("}));
  CHECK(54, write_line_num());
  CHECK(55, write(&(String){3, 2, ")\n"}));
  glob->spaces = glob->spaces - 2;
  CHECK(57, write_spaces());
  CHECK(58, write(&(String){18, 17, "} while (false);\n"}));
  CHECK(59, write_spaces());
  CHECK(60, write(&(String){24, 23, "_trace_stream = stdout;"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_assert_error__dtl[] = {St_assert_error_parse, St_assert_error_analyze_first, St_assert_error_analyze, St_assert_error_write};


typedef struct St_test St_test; struct St_test {
  St_func _base;
};
static char* _func_name_St_test_parse = "St-test.parse";
#define LUMI_FUNC_NAME _func_name_St_test_parse
Returncode St_test_parse(St_test* self) {
  CHECK(65, St_func_parse(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_test_analyze_first = "St-test.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_test_analyze_first
Returncode St_test_analyze_first(St_test* self) {
  CHECK(68, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_test_analyze = "St-test.analyze";
#define LUMI_FUNC_NAME _func_name_St_test_analyze
Returncode St_test_analyze(St_test* self) {
  CHECK(71, St_func_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_test_write = "St-test.write";
#define LUMI_FUNC_NAME _func_name_St_test_write
Returncode St_test_write(St_test* self) {
  CHECK(74, St_func_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_test_m_register = "St-test.m-register";
#define LUMI_FUNC_NAME _func_name_St_test_m_register
Returncode St_test_m_register(St_test* self) {
  CHECK(77, String_list_add(glob->test_funcs, self->_base.mfunc->name));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_test__dtl[] = {St_test_parse, St_test_analyze_first, St_test_analyze, St_test_write, St_test_m_register};


typedef struct St_mock St_mock; struct St_mock {
  St_func _base;
};
static char* _func_name_St_mock_parse = "St-mock.parse";
#define LUMI_FUNC_NAME _func_name_St_mock_parse
Returncode St_mock_parse(St_mock* self) {
  CHECK(82, St_func_parse(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_mock_analyze_first = "St-mock.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_mock_analyze_first
Returncode St_mock_analyze_first(St_mock* self) {
  CHECK(85, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_mock_analyze = "St-mock.analyze";
#define LUMI_FUNC_NAME _func_name_St_mock_analyze
Returncode St_mock_analyze(St_mock* self) {
  Mvar* mvar;
  Int index;
  CHECK(90, String_find(self->_base.mfunc->name, &(String){2, 1, "."}, &(index)));
  if (index < self->_base.mfunc->name->length) {
    if ((0) < 0 || (index) < 0 || (0) + (index) > self->_base.mfunc->name->length) RAISE(92)
    String* type_name = &(String){index, index, self->_base.mfunc->name->chars + (0)};
    String* meth_name = new_string(self->_base.mfunc->name->length - index);
    if (meth_name == NULL) RAISE(93)
    if ((index + 1) < 0 || (self->_base.mfunc->name->length - index - 1) < 0 || (index + 1) + (self->_base.mfunc->name->length - index - 1) > self->_base.mfunc->name->length) RAISE(94)
    CHECK(94, String_copy(meth_name, &(String){self->_base.mfunc->name->length - index - 1, self->_base.mfunc->name->length - index - 1, self->_base.mfunc->name->chars + (index + 1)}));
    CHECK(95, f_find_type(type_name, &(self->_base.mfunc->mclass)))
    if (!(NULL != self->_base.mfunc->mclass)) {
      CHECK(96, f_syntax_error(&(String){31, 30, "mocking method of unknown type"}, type_name));
    }
    CHECK(97, Var_map_find(self->_base.mfunc->mclass->members, meth_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(98, f_syntax_error2(&(String){5, 4, "type"}, type_name, &(String){14, 13, "has no member"}, meth_name));
    }
    free(self->_base.mfunc->name);
    self->_base.mfunc->name = meth_name;
    CHECK(101, Arg_list_add_param(self->_base.mfunc->args, ACCESS_VAR, self->_base.mfunc->mclass, &(String){5, 4, "self"}));
  }
  else {
    CHECK(102, St_m_find_var(&(self->_base._base._base), self->_base.mfunc->name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(103, f_syntax_error(&(String){25, 24, "mocking unknown function"}, self->_base.mfunc->name));
    }
  }
  if (!(NULL != mvar->func_dec)) {
    CHECK(105, f_syntax_error(&(String){25, 24, "cannot mock non-function"}, self->_base.mfunc->name));
  }
  mvar->func_dec->is_mocked = true;
  CHECK(107, St_func_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_mock_write = "St-mock.write";
#define LUMI_FUNC_NAME _func_name_St_mock_write
Returncode St_mock_write(St_mock* self) {
  CHECK(110, St_func_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_mock_m_register = "St-mock.m-register";
#define LUMI_FUNC_NAME _func_name_St_mock_m_register
Returncode St_mock_m_register(St_mock* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_mock__dtl[] = {St_mock_parse, St_mock_analyze_first, St_mock_analyze, St_mock_write, St_mock_m_register};


typedef struct St_debug St_debug; struct St_debug {
  St _base;
};
static char* _func_name_St_debug_m_swich_debug = "St-debug.m-swich-debug";
#define LUMI_FUNC_NAME _func_name_St_debug_m_swich_debug
Returncode St_debug_m_swich_debug(St_debug* self) {
  glob->debug = !glob->debug;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_debug_parse = "St-debug.parse";
#define LUMI_FUNC_NAME _func_name_St_debug_parse
Returncode St_debug_parse(St_debug* self) {
  CHECK(121, St_debug_m_swich_debug(self));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_debug_analyze_first = "St-debug.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_debug_analyze_first
Returncode St_debug_analyze_first(St_debug* self) {
  CHECK(124, St_debug_m_swich_debug(self));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_debug_analyze = "St-debug.analyze";
#define LUMI_FUNC_NAME _func_name_St_debug_analyze
Returncode St_debug_analyze(St_debug* self) {
  CHECK(127, St_debug_m_swich_debug(self));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_debug_write = "St-debug.write";
#define LUMI_FUNC_NAME _func_name_St_debug_write
Returncode St_debug_write(St_debug* self) {
  CHECK(130, St_debug_m_swich_debug(self));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_debug__dtl[] = {St_debug_parse, St_debug_analyze_first, St_debug_analyze, St_debug_write};

#undef LUMI_FILE_NAME
