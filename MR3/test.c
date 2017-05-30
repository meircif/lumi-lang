static char* _mr_file14_name = "test.2.mr";
#define MR_FILE_NAME _mr_file14_name
/* MR3 compiler - testing */

typedef struct St_assert St_assert; struct St_assert {
  St _base;
  Mexp* condition;
};
static char* _func_name_St_assert_parse = "St-assert.parse";
#define MR_FUNC_NAME _func_name_St_assert_parse
Returncode St_assert_parse(St_assert* self) {
  Char _Char0;
  CHECK(7, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char0)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_assert_analyze_first = "St-assert.analyze-first";
#define MR_FUNC_NAME _func_name_St_assert_analyze_first
Returncode St_assert_analyze_first(St_assert* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_assert_analyze = "St-assert.analyze";
#define MR_FUNC_NAME _func_name_St_assert_analyze
Returncode St_assert_analyze(St_assert* self) {
  CHECK(13, Mexp_analyze_type(self->condition, glob->type_bool));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_assert_write = "St-assert.write";
#define MR_FUNC_NAME _func_name_St_assert_write
Returncode St_assert_write(St_assert* self) {
  CHECK(16, Mexp_write_intro(self->condition));
  CHECK(17, write(&(String){13, 12, "TEST_ASSERT("}));
  CHECK(18, write_line_num());
  CHECK(19, write(&(String){3, 2, ", "}));
  CHECK(20, Mexp_write_final(self->condition));
  CHECK(21, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_assert__dtl[] = {St_assert_parse, St_assert_analyze_first, St_assert_analyze, St_assert_write};


typedef struct St_test St_test; struct St_test {
  St_func _base;
};
static char* _func_name_St_test_parse = "St-test.parse";
#define MR_FUNC_NAME _func_name_St_test_parse
Returncode St_test_parse(St_test* self) {
  CHECK(26, St_func_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_test_analyze_first = "St-test.analyze-first";
#define MR_FUNC_NAME _func_name_St_test_analyze_first
Returncode St_test_analyze_first(St_test* self) {
  CHECK(29, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_test_analyze = "St-test.analyze";
#define MR_FUNC_NAME _func_name_St_test_analyze
Returncode St_test_analyze(St_test* self) {
  CHECK(32, St_func_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_test_write = "St-test.write";
#define MR_FUNC_NAME _func_name_St_test_write
Returncode St_test_write(St_test* self) {
  CHECK(35, St_func_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_test_m_register = "St-test.m-register";
#define MR_FUNC_NAME _func_name_St_test_m_register
Returncode St_test_m_register(St_test* self) {
  CHECK(38, String_list_add(glob->test_funcs, self->_base.mfunc->name));
  return OK;
}
#undef MR_FUNC_NAME
Func St_test__dtl[] = {St_test_parse, St_test_analyze_first, St_test_analyze, St_test_write, St_test_m_register};


typedef struct St_mock St_mock; struct St_mock {
  St_func _base;
};
static char* _func_name_St_mock_parse = "St-mock.parse";
#define MR_FUNC_NAME _func_name_St_mock_parse
Returncode St_mock_parse(St_mock* self) {
  CHECK(43, St_func_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_mock_analyze_first = "St-mock.analyze-first";
#define MR_FUNC_NAME _func_name_St_mock_analyze_first
Returncode St_mock_analyze_first(St_mock* self) {
  CHECK(46, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_mock_analyze = "St-mock.analyze";
#define MR_FUNC_NAME _func_name_St_mock_analyze
Returncode St_mock_analyze(St_mock* self) {
  Mvar* mvar;
  Int index;
  CHECK(51, String_find(self->_base.mfunc->name, &(String){2, 1, "."}, &(index)));
  if (index < self->_base.mfunc->name->length) {
    if ((0) < 0 || (index) < 0 || (0) + (index) > self->_base.mfunc->name->length) RAISE(53)
    String* type_name = &(String){index, index, self->_base.mfunc->name->chars + (0)};
    String* meth_name = new_string(self->_base.mfunc->name->length - index);
    if (meth_name == NULL) RAISE(54)
    if ((index + 1) < 0 || (self->_base.mfunc->name->length - index - 1) < 0 || (index + 1) + (self->_base.mfunc->name->length - index - 1) > self->_base.mfunc->name->length) RAISE(55)
    CHECK(55, String_copy(meth_name, &(String){self->_base.mfunc->name->length - index - 1, self->_base.mfunc->name->length - index - 1, self->_base.mfunc->name->chars + (index + 1)}));
    CHECK(56, f_find_type(type_name, &(self->_base.mfunc->mclass)))
    if (!(NULL != self->_base.mfunc->mclass)) {
      CHECK(57, f_syntax_error(&(String){31, 30, "mocking method of unknown type"}, type_name));
    }
    CHECK(58, Var_map_find(self->_base.mfunc->mclass->members, meth_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(59, f_syntax_error2(&(String){5, 4, "type"}, type_name, &(String){14, 13, "has no member"}, meth_name));
    }
    free(self->_base.mfunc->name);
    self->_base.mfunc->name = meth_name;
    CHECK(62, Arg_list_add_param(self->_base.mfunc->args, ACCESS_VAR, self->_base.mfunc->mclass, &(String){5, 4, "self"}));
  }
  else {
    CHECK(63, St_m_find_var(&(self->_base._base._base), self->_base.mfunc->name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(64, f_syntax_error(&(String){25, 24, "mocking unknown function"}, self->_base.mfunc->name));
    }
  }
  if (!(NULL != mvar->func_dec)) {
    CHECK(66, f_syntax_error(&(String){25, 24, "cannot mock non-function"}, self->_base.mfunc->name));
  }
  mvar->func_dec->is_mocked = true;
  CHECK(68, St_func_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_mock_write = "St-mock.write";
#define MR_FUNC_NAME _func_name_St_mock_write
Returncode St_mock_write(St_mock* self) {
  CHECK(71, St_func_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_mock_m_register = "St-mock.m-register";
#define MR_FUNC_NAME _func_name_St_mock_m_register
Returncode St_mock_m_register(St_mock* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func St_mock__dtl[] = {St_mock_parse, St_mock_analyze_first, St_mock_analyze, St_mock_write, St_mock_m_register};

#undef MR_FILE_NAME
