static char* _mr_file8_name = "func.2.mr";
#define MR_FILE_NAME _mr_file8_name
/* MR3 compiler - function */

typedef struct Mfunc Mfunc; struct Mfunc {
  String* name;
  Arg_list* args;
  Mtype* mclass;
  Bool is_dynamic;
  Bool is_mocked;
  Int dynamic_index;
};
static char* _func_name_Mfunc_init = "Mfunc.init";
#define MR_FUNC_NAME _func_name_Mfunc_init
Returncode Mfunc_init(Mfunc* self, String* name) {
  CHECK(12, f_new_copy(name, &(self->name)));
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(13)
  self->args = args;
  CHECK(15, Arg_list_init(self->args, true));
  self->mclass = NULL;
  self->is_dynamic = false;
  self->is_mocked = false;
  self->dynamic_index = 0;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_parse = "Mfunc.parse";
#define MR_FUNC_NAME _func_name_Mfunc_parse
Returncode Mfunc_parse(Mfunc* self) {
  self->mclass = glob->mclass;
  if (NULL != self->mclass) {
    String* meth_type = &(String){64, 0, (char[64]){0}};
    Char _Char0;
    CHECK(25, read(&(String){2, 1, " "}, meth_type, &(_Char0)));
    Bool _Bool1;
    CHECK(26, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool1)))
    self->is_dynamic = _Bool1;
  }
  else {
    self->is_dynamic = false;
  }
  self->dynamic_index = 0;
  self->is_mocked = false;
  Char _Char2;
  CHECK(31, read_new(&(String){2, 1, "("}, &(self->name), &(_Char2)));
  CHECK(32, parse_new_args(&(self->args)));
  if (NULL != self->mclass) {
    CHECK(34, Arg_list_add_param(self->args, ACCESS_VAR, self->mclass, &(String){5, 4, "self"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_analyze = "Mfunc.analyze";
#define MR_FUNC_NAME _func_name_Mfunc_analyze
Returncode Mfunc_analyze(Mfunc* self) {
  CHECK(37, Arg_list_analyze(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write_name = "Mfunc.write-name";
#define MR_FUNC_NAME _func_name_Mfunc_write_name
Returncode Mfunc_write_name(Mfunc* self) {
  if (self->mclass) {
    CHECK(41, write_cstyle(self->mclass->name));
    CHECK(42, write(&(String){2, 1, "_"}));
  }
  CHECK(43, write_cstyle(self->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write = "Mfunc.write";
#define MR_FUNC_NAME _func_name_Mfunc_write
Returncode Mfunc_write(Mfunc* self) {
  CHECK(46, write(&(String){12, 11, "Returncode "}));
  CHECK(47, Mfunc_write_name(self));
  CHECK(48, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_m_new_var = "Mfunc.m-new-var";
#define MR_FUNC_NAME _func_name_Mfunc_m_new_var
Returncode Mfunc_m_new_var(Mfunc* self, Mvar** mvar) {
  CHECK(51, init_new_var(glob->type_func, &((*mvar))));
  CHECK(52, f_new_copy(self->name, &((*mvar)->name)));
  (*mvar)->func_dec = self;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_mfunc = "parse-new-mfunc";
#define MR_FUNC_NAME _func_name_parse_new_mfunc
Returncode parse_new_mfunc(Mfunc** new_mfunc) {
  Mfunc* mfunc = malloc(sizeof(Mfunc));
  if (mfunc == NULL) RAISE(56)
  CHECK(57, Mfunc_parse(mfunc));
  (*new_mfunc) = mfunc;
  return OK;
}
#undef MR_FUNC_NAME


typedef struct St_func St_func; struct St_func {
  St_node _base;
  Mfunc* mfunc;
};
static char* _func_name_St_func_add_args_vars = "St-func.add-args-vars";
#define MR_FUNC_NAME _func_name_St_func_add_args_vars
Returncode St_func_add_args_vars(St_func* self, Arg_node* fisrt_arg) {
  Arg_node* arg = fisrt_arg;
  while (true) {
    if (!(NULL != arg)) break;
    Dec_arg* dec_arg;
    CHECK(69, (*((Func**)(arg)))[4](arg, &(dec_arg)));
    if (!(NULL != dec_arg)) break;
    CHECK(71, add_var(self->_base._base.sons_var_map, dec_arg->mvar));
    arg = arg->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_parse = "St-func.parse";
#define MR_FUNC_NAME _func_name_St_func_parse
Returncode St_func_parse(St_func* self) {
  CHECK(75, parse_new_mfunc(&(self->mfunc)));
  CHECK(76, (*((Func**)(self)))[4](self));
  CHECK(77, f_copy_new_var_map(NULL, &(self->_base._base.sons_var_map)));
  CHECK(78, St_func_add_args_vars(self, self->mfunc->args->first_param));
  CHECK(79, St_func_add_args_vars(self, self->mfunc->args->first_out));
  CHECK(80, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze_first = "St-func.analyze-first";
#define MR_FUNC_NAME _func_name_St_func_analyze_first
Returncode St_func_analyze_first(St_func* self) {
  CHECK(83, Mfunc_analyze(self->mfunc));
  CHECK(84, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze = "St-func.analyze";
#define MR_FUNC_NAME _func_name_St_func_analyze
Returncode St_func_analyze(St_func* self) {
  St_return* st_return = malloc(sizeof(St_return));
  if (st_return == NULL) RAISE(87)
  *((Func**)(st_return)) = St_return__dtl;
  CHECK(88, St_init(&(st_return->_base), &(self->_base._base)));
  CHECK(89, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_write = "St-func.write";
#define MR_FUNC_NAME _func_name_St_func_write
Returncode St_func_write(St_func* self) {
  if (self->mfunc->is_mocked) {
    return OK;
  }
  if (NULL != glob->mclass) {
    if (!glob->methods) {
      return OK;
    }
    CHECK(97, write_new_indent_line());
  }
  CHECK(98, write(&(String){33, 32, "#if MR_STAGE == MR_DECLARATIONS\n"}));
  CHECK(99, write_spaces());
  CHECK(100, Mfunc_write(self->mfunc));
  CHECK(101, write(&(String){3, 2, ";\n"}));
  CHECK(102, write_spaces());
  CHECK(103, write(&(String){32, 31, "#elif MR_STAGE == MR_FUNCTIONS\n"}));
  CHECK(104, write_spaces());
  CHECK(105, write(&(String){25, 24, "static char* _func_name_"}));
  CHECK(106, Mfunc_write_name(self->mfunc));
  CHECK(107, write(&(String){5, 4, " = \""}));
  if (NULL != glob->mclass) {
    CHECK(109, write(glob->mclass->name));
    CHECK(110, write(&(String){2, 1, "."}));
  }
  CHECK(111, write(self->mfunc->name));
  CHECK(112, write(&(String){4, 3, "\";\n"}));
  CHECK(113, write_spaces());
  CHECK(114, write(&(String){33, 32, "#define MR_FUNC_NAME _func_name_"}));
  CHECK(115, Mfunc_write_name(self->mfunc));
  CHECK(116, write_new_indent_line());
  CHECK(117, Mfunc_write(self->mfunc));
  Mtype* mclass = glob->mclass;
  glob->mclass = NULL;
  CHECK(120, St_node_write(&(self->_base)));
  glob->mclass = mclass;
  CHECK(122, write_new_indent_line());
  CHECK(123, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}));
  CHECK(124, write_spaces());
  CHECK(125, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_m_register = "St-func.m-register";
#define MR_FUNC_NAME _func_name_St_func_m_register
Returncode St_func_m_register(St_func* self) {
  Mvar* _Mvar3;
  CHECK(128, Mfunc_m_new_var(self->mfunc, &(_Mvar3)))
  CHECK(128, St_add_var(&(self->_base._base), _Mvar3));
  return OK;
}
#undef MR_FUNC_NAME
Func St_func__dtl[] = {St_func_parse, St_func_analyze_first, St_func_analyze, St_func_write, St_func_m_register};


typedef struct St_main St_main; struct St_main {
  St_func _base;
};
static char* _func_name_St_main_parse = "St-main.parse";
#define MR_FUNC_NAME _func_name_St_main_parse
Returncode St_main_parse(St_main* self) {
  CHECK(133, St_func_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze_first = "St-main.analyze-first";
#define MR_FUNC_NAME _func_name_St_main_analyze_first
Returncode St_main_analyze_first(St_main* self) {
  CHECK(136, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze = "St-main.analyze";
#define MR_FUNC_NAME _func_name_St_main_analyze
Returncode St_main_analyze(St_main* self) {
  CHECK(139, St_func_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_write = "St-main.write";
#define MR_FUNC_NAME _func_name_St_main_write
Returncode St_main_write(St_main* self) {
  if (NULL != glob->test_funcs) {
    CHECK(143, write(&(String){30, 29, "#if MR_STAGE == MR_FUNCTIONS\n"}));
    CHECK(144, write(&(String){29, 28, "Returncode func(Array* _) {\n"}));
    CHECK(145, write(&(String){24, 23, "  Bool success = true;\n"}));
    String_list* test_func = glob->test_funcs;
    while (true) {
      CHECK(148, write(&(String){12, 11, "  RUN_TEST("}));
      CHECK(149, write_cstyle(test_func->value));
      CHECK(150, write(&(String){4, 3, ");\n"}));
      test_func = test_func->next;
      if (!(NULL != test_func)) break;
    }
    CHECK(153, write(&(String){30, 29, "  return success? OK : FAIL;\n"}));
    CHECK(154, write(&(String){3, 2, "}\n"}));
    CHECK(155, write(&(String){17, 16, "\nMAIN_TEST_FUNC\n"}));
    CHECK(156, write(&(String){7, 6, "#endif"}));
  }
  else {
    CHECK(158, St_func_write(&(self->_base)));
    CHECK(159, write(&(String){32, 31, "\n\n#if MR_STAGE == MR_FUNCTIONS\n"}));
    CHECK(160, write(&(String){11, 10, "MAIN_FUNC\n"}));
    CHECK(161, write(&(String){7, 6, "#endif"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_m_register = "St-main.m-register";
#define MR_FUNC_NAME _func_name_St_main_m_register
Returncode St_main_m_register(St_main* self) {
  CHECK(164, St_func_m_register(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_main__dtl[] = {St_main_parse, St_main_analyze_first, St_main_analyze, St_main_write, St_main_m_register};


typedef struct St_format St_format; struct St_format {
  St_node _base;
  String* item_name;
  Mvar* item_mvar;
  String* func_name;
  String* format;
};
static char* _func_name_St_format_parse = "St-format.parse";
#define MR_FUNC_NAME _func_name_St_format_parse
Returncode St_format_parse(St_format* self) {
  self->item_name = NULL;
  self->item_mvar = NULL;
  Char _Char4;
  CHECK(176, read_new(&(String){3, 2, ".("}, &(self->func_name), &(_Char4)))
  if (_Char4 == '.') {
    self->item_name = self->func_name;
    Char _Char5;
    CHECK(178, read_new(&(String){2, 1, "("}, &(self->func_name), &(_Char5)));
  }
  String* format = &(String){256, 0, (char[256]){0}};
  Char _Char6;
  CHECK(180, read(&(String){2, 1, ")"}, format, &(_Char6)));
  if ((format->length - 1) < 0 || (format->length - 1) >= format->length) RAISE(181)
  if ((0) < 0 || (0) >= format->length) RAISE(181)
  if (format->length < 2 || format->chars[0] != '"' || format->chars[format->length - 1] != '"') {
    CHECK(182, f_syntax_error(&(String){22, 21, "illegal format string"}, format));
  }
  if ((1) < 0 || (format->length - 2) < 0 || (1) + (format->length - 2) > format->length) RAISE(183)
  CHECK(183, f_new_copy(&(String){format->length - 2, format->length - 2, format->chars + (1)}, &(self->format)));
  Char _Char7;
  CHECK(184, read_c(&(_Char7)));
  CHECK(185, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze_first = "St-format.analyze-first";
#define MR_FUNC_NAME _func_name_St_format_analyze_first
Returncode St_format_analyze_first(St_format* self) {
  CHECK(188, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze = "St-format.analyze";
#define MR_FUNC_NAME _func_name_St_format_analyze
Returncode St_format_analyze(St_format* self) {
  Mvar* mvar;
  if (NULL != self->item_name) {
    CHECK(193, f_find_var(self->item_name, &(self->item_mvar)))
    if (!(NULL != self->item_mvar)) {
      CHECK(194, f_syntax_error(&(String){16, 15, "unknow variable"}, self->item_name));
    }
    CHECK(195, Var_map_find(self->item_mvar->mtype->members, self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(196, f_syntax_error2(&(String){5, 4, "type"}, self->item_mvar->typename, &(String){14, 13, "has no method"}, self->func_name));
    }
  }
  else {
    CHECK(198, f_find_var(self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(199, f_syntax_error(&(String){16, 15, "unknow function"}, self->func_name));
    }
  }
  if (!(NULL != mvar->func_dec)) {
    CHECK(201, f_syntax_error(&(String){22, 21, "non function variable"}, self->func_name));
  }
  if (!(NULL != mvar->func_dec->args->first_param)) {
    CHECK(203, f_syntax_error(&(String){26, 25, "no parameter for function"}, self->func_name));
  }
  if (NULL != mvar->func_dec->args->first_out) {
    CHECK(205, f_syntax_error(&(String){27, 26, "outputs exists in function"}, self->func_name));
  }
  Dec_arg* param_dec;
  if (NULL != self->item_name) {
    if (!(NULL != mvar->func_dec->args->first_param->next)) {
      CHECK(209, f_syntax_error(&(String){24, 23, "no parameter for method"}, self->func_name));
    }
    CHECK(210, (*((Func**)(mvar->func_dec->args->first_param->next)))[4](mvar->func_dec->args->first_param->next, &(param_dec)));
  }
  else {
    CHECK(212, (*((Func**)(mvar->func_dec->args->first_param)))[4](mvar->func_dec->args->first_param, &(param_dec)));
  }
  if (NULL != param_dec->_base.next) {
    CHECK(214, f_syntax_error(&(String){32, 31, "too many parameter for function"}, self->func_name));
  }
  if (param_dec->mvar->mtype != glob->type_string) {
    CHECK(216, f_syntax_error2(&(String){40, 39, "expected a string parameter in function"}, self->func_name, &(String){12, 11, " instead of"}, param_dec->mvar->typename));
  }
  if (param_dec->mvar->access != ACCESS_USER) {
    CHECK(218, f_syntax_error(&(String){48, 47, "expected parameter with user access in function"}, self->func_name));
  }
  CHECK(219, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_write = "St-format.write";
#define MR_FUNC_NAME _func_name_St_format_write
Returncode St_format_write(St_format* self) {
  Int index = 0;
  Int len = self->format->length;
  St* node = self->_base._base.first_son;
  while (true) {
    if (!(len > 0)) break;
    if (index > 0) {
      CHECK(228, write_new_indent_line());
    }
    if ((index) < 0 || (len) < 0 || (index) + (len) > self->format->length) RAISE(229)
    String* format = &(String){len, len, self->format->chars + (index)};
    Int _Int8;
    CHECK(230, String_find(format, &(String){3, 2, "{}"}, &(_Int8)))
    Int next = _Int8;
    if (next > 0) {
      CHECK(232, write_tb_check());
      if (NULL != self->item_mvar) {
        CHECK(234, write_cstyle(self->item_mvar->mtype->name));
        CHECK(235, write(&(String){2, 1, "_"}));
      }
      CHECK(236, write_cstyle(self->func_name));
      CHECK(237, write(&(String){2, 1, "("}));
      if (NULL != self->item_mvar) {
        if (self->item_mvar->is_ref) {
          CHECK(240, write(&(String){2, 1, "*"}));
        }
        CHECK(241, write_cstyle(self->item_mvar->name));
        CHECK(242, write(&(String){3, 2, ", "}));
      }
      CHECK(243, write(&(String){11, 10, "&(String){"}));
      CHECK(244, write_int(next + 1));
      CHECK(245, write(&(String){3, 2, ", "}));
      CHECK(246, write_int(next));
      CHECK(247, write(&(String){4, 3, ", \""}));
      if ((0) < 0 || (next) < 0 || (0) + (next) > format->length) RAISE(248)
      CHECK(248, write(&(String){next, next, format->chars + (0)}));
      CHECK(249, write(&(String){6, 5, "\"}) )"}));
    }
    else {
      if (!(NULL != node)) {
        CHECK(252, f_syntax_error(&(String){24, 23, "too few lines to format"}, self->func_name));
      }
      glob->line_num = node->line_num;
      CHECK(254, (*((Func**)(node)))[3](node));
      glob->line_num = self->_base._base.line_num;
      node = node->next_brother;
      next = 2;
    }
    index = index + next;
    len = len - next;
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_format__dtl[] = {St_format_parse, St_format_analyze_first, St_format_analyze, St_format_write};

#undef MR_FILE_NAME
