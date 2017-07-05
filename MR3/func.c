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
  if (NULL != self->mclass) {
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
  glob->mclass = NULL;
  CHECK(81, St_node_parse(&(self->_base)));
  glob->mclass = self->mfunc->mclass;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze_first = "St-func.analyze-first";
#define MR_FUNC_NAME _func_name_St_func_analyze_first
Returncode St_func_analyze_first(St_func* self) {
  CHECK(85, Mfunc_analyze(self->mfunc));
  glob->mclass = NULL;
  CHECK(87, St_node_analyze_first(&(self->_base)));
  glob->mclass = self->mfunc->mclass;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze = "St-func.analyze";
#define MR_FUNC_NAME _func_name_St_func_analyze
Returncode St_func_analyze(St_func* self) {
  St_return* st_return = malloc(sizeof(St_return));
  if (st_return == NULL) RAISE(91)
  *((Func**)(st_return)) = St_return__dtl;
  CHECK(92, St_init(&(st_return->_base), &(self->_base._base)));
  glob->mclass = NULL;
  CHECK(94, St_node_analyze(&(self->_base)));
  glob->mclass = self->mfunc->mclass;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_write = "St-func.write";
#define MR_FUNC_NAME _func_name_St_func_write
Returncode St_func_write(St_func* self) {
  if (NULL != glob->mclass) {
    if (!glob->methods) {
      return OK;
    }
    CHECK(101, write_new_indent_line());
  }
  CHECK(102, write(&(String){33, 32, "#if MR_STAGE == MR_DECLARATIONS\n"}));
  CHECK(103, write_spaces());
  CHECK(104, Mfunc_write(self->mfunc));
  CHECK(105, write(&(String){3, 2, ";\n"}));
  CHECK(106, write_spaces());
  if (self->mfunc->is_mocked) {
    CHECK(108, write(&(String){7, 6, "#endif"}));
    return OK;
  }
  CHECK(110, write(&(String){32, 31, "#elif MR_STAGE == MR_FUNCTIONS\n"}));
  CHECK(111, write_spaces());
  CHECK(112, write(&(String){25, 24, "static char* _func_name_"}));
  CHECK(113, Mfunc_write_name(self->mfunc));
  CHECK(114, write(&(String){5, 4, " = \""}));
  if (NULL != self->mfunc->mclass) {
    CHECK(116, write(self->mfunc->mclass->name));
    CHECK(117, write(&(String){2, 1, "."}));
  }
  CHECK(118, write(self->mfunc->name));
  CHECK(119, write(&(String){4, 3, "\";\n"}));
  CHECK(120, write_spaces());
  CHECK(121, write(&(String){33, 32, "#define MR_FUNC_NAME _func_name_"}));
  CHECK(122, Mfunc_write_name(self->mfunc));
  CHECK(123, write_new_indent_line());
  CHECK(124, Mfunc_write(self->mfunc));
  glob->mclass = NULL;
  CHECK(126, St_node_write(&(self->_base)));
  glob->mclass = self->mfunc->mclass;
  CHECK(128, write_new_indent_line());
  CHECK(129, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}));
  CHECK(130, write_spaces());
  CHECK(131, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_m_register = "St-func.m-register";
#define MR_FUNC_NAME _func_name_St_func_m_register
Returncode St_func_m_register(St_func* self) {
  Mvar* _Mvar3;
  CHECK(134, Mfunc_m_new_var(self->mfunc, &(_Mvar3)))
  CHECK(134, St_add_var(&(self->_base._base), _Mvar3));
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
  CHECK(139, St_func_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze_first = "St-main.analyze-first";
#define MR_FUNC_NAME _func_name_St_main_analyze_first
Returncode St_main_analyze_first(St_main* self) {
  CHECK(142, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze = "St-main.analyze";
#define MR_FUNC_NAME _func_name_St_main_analyze
Returncode St_main_analyze(St_main* self) {
  CHECK(145, St_func_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_write = "St-main.write";
#define MR_FUNC_NAME _func_name_St_main_write
Returncode St_main_write(St_main* self) {
  Bool _Bool4;
  CHECK(148, String_list_has(glob->test_funcs, &(_Bool4)))
  if (_Bool4) {
    CHECK(149, write(&(String){30, 29, "#if MR_STAGE == MR_FUNCTIONS\n"}));
    CHECK(150, write(&(String){29, 28, "Returncode func(Array* _) {\n"}));
    CHECK(151, write(&(String){24, 23, "  Bool success = true;\n"}));
    String_list_node* test_func = glob->test_funcs->first;
    while (true) {
      CHECK(154, write(&(String){12, 11, "  RUN_TEST("}));
      CHECK(155, write_cstyle(test_func->value));
      CHECK(156, write(&(String){4, 3, ");\n"}));
      test_func = test_func->next;
      if (!(NULL != test_func)) break;
    }
    CHECK(159, write(&(String){30, 29, "  return success? OK : FAIL;\n"}));
    CHECK(160, write(&(String){3, 2, "}\n"}));
    CHECK(161, write(&(String){17, 16, "\nMAIN_TEST_FUNC\n"}));
    CHECK(162, write(&(String){7, 6, "#endif"}));
  }
  else {
    CHECK(164, St_func_write(&(self->_base)));
    CHECK(165, write(&(String){32, 31, "\n\n#if MR_STAGE == MR_FUNCTIONS\n"}));
    CHECK(166, write(&(String){11, 10, "MAIN_FUNC\n"}));
    CHECK(167, write(&(String){7, 6, "#endif"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_m_register = "St-main.m-register";
#define MR_FUNC_NAME _func_name_St_main_m_register
Returncode St_main_m_register(St_main* self) {
  CHECK(170, St_func_m_register(&(self->_base)));
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
  Char _Char5;
  CHECK(182, read_new(&(String){3, 2, ".("}, &(self->func_name), &(_Char5)))
  if (_Char5 == '.') {
    self->item_name = self->func_name;
    Char _Char6;
    CHECK(184, read_new(&(String){2, 1, "("}, &(self->func_name), &(_Char6)));
  }
  String* format = &(String){256, 0, (char[256]){0}};
  Char _Char7;
  CHECK(186, read(&(String){2, 1, ")"}, format, &(_Char7)));
  if ((format->length - 1) < 0 || (format->length - 1) >= format->length) RAISE(187)
  if ((0) < 0 || (0) >= format->length) RAISE(187)
  if (format->length < 2 || format->chars[0] != '"' || format->chars[format->length - 1] != '"') {
    CHECK(188, f_syntax_error(&(String){22, 21, "illegal format string"}, format));
  }
  if ((1) < 0 || (format->length - 2) < 0 || (1) + (format->length - 2) > format->length) RAISE(189)
  CHECK(189, f_new_copy(&(String){format->length - 2, format->length - 2, format->chars + (1)}, &(self->format)));
  Char _Char8;
  CHECK(190, read_c(&(_Char8)));
  CHECK(191, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze_first = "St-format.analyze-first";
#define MR_FUNC_NAME _func_name_St_format_analyze_first
Returncode St_format_analyze_first(St_format* self) {
  CHECK(194, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze = "St-format.analyze";
#define MR_FUNC_NAME _func_name_St_format_analyze
Returncode St_format_analyze(St_format* self) {
  Mvar* mvar;
  if (NULL != self->item_name) {
    CHECK(199, f_find_var(self->item_name, &(self->item_mvar)))
    if (!(NULL != self->item_mvar)) {
      CHECK(200, f_syntax_error(&(String){16, 15, "unknow variable"}, self->item_name));
    }
    CHECK(201, Var_map_find(self->item_mvar->mtype->members, self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(202, f_syntax_error2(&(String){5, 4, "type"}, self->item_mvar->typename, &(String){14, 13, "has no method"}, self->func_name));
    }
  }
  else {
    CHECK(204, f_find_var(self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(205, f_syntax_error(&(String){16, 15, "unknow function"}, self->func_name));
    }
  }
  if (!(NULL != mvar->func_dec)) {
    CHECK(207, f_syntax_error(&(String){22, 21, "non function variable"}, self->func_name));
  }
  if (!(NULL != mvar->func_dec->args->first_param)) {
    CHECK(209, f_syntax_error(&(String){26, 25, "no parameter for function"}, self->func_name));
  }
  if (NULL != mvar->func_dec->args->first_out) {
    CHECK(211, f_syntax_error(&(String){27, 26, "outputs exists in function"}, self->func_name));
  }
  Dec_arg* param_dec;
  if (NULL != self->item_name) {
    if (!(NULL != mvar->func_dec->args->first_param->next)) {
      CHECK(215, f_syntax_error(&(String){24, 23, "no parameter for method"}, self->func_name));
    }
    CHECK(216, (*((Func**)(mvar->func_dec->args->first_param->next)))[4](mvar->func_dec->args->first_param->next, &(param_dec)));
  }
  else {
    CHECK(218, (*((Func**)(mvar->func_dec->args->first_param)))[4](mvar->func_dec->args->first_param, &(param_dec)));
  }
  if (NULL != param_dec->_base.next) {
    CHECK(220, f_syntax_error(&(String){32, 31, "too many parameter for function"}, self->func_name));
  }
  if (param_dec->mvar->mtype != glob->type_string) {
    CHECK(222, f_syntax_error2(&(String){40, 39, "expected a string parameter in function"}, self->func_name, &(String){12, 11, " instead of"}, param_dec->mvar->typename));
  }
  if (param_dec->mvar->access != ACCESS_USER) {
    CHECK(224, f_syntax_error(&(String){48, 47, "expected parameter with user access in function"}, self->func_name));
  }
  CHECK(225, St_node_analyze(&(self->_base)));
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
      CHECK(234, write_new_indent_line());
    }
    if ((index) < 0 || (len) < 0 || (index) + (len) > self->format->length) RAISE(235)
    String* format = &(String){len, len, self->format->chars + (index)};
    Int _Int9;
    CHECK(236, String_find(format, &(String){3, 2, "{}"}, &(_Int9)))
    Int next = _Int9;
    if (next > 0) {
      CHECK(238, write_tb_check());
      if (NULL != self->item_mvar) {
        CHECK(240, write_cstyle(self->item_mvar->mtype->name));
        CHECK(241, write(&(String){2, 1, "_"}));
      }
      CHECK(242, write_cstyle(self->func_name));
      CHECK(243, write(&(String){2, 1, "("}));
      if (NULL != self->item_mvar) {
        if (self->item_mvar->is_ref) {
          CHECK(246, write(&(String){2, 1, "*"}));
        }
        CHECK(247, write_cstyle(self->item_mvar->name));
        CHECK(248, write(&(String){3, 2, ", "}));
      }
      CHECK(249, write(&(String){11, 10, "&(String){"}));
      CHECK(250, write_int(next + 1));
      CHECK(251, write(&(String){3, 2, ", "}));
      CHECK(252, write_int(next));
      CHECK(253, write(&(String){4, 3, ", \""}));
      if ((0) < 0 || (next) < 0 || (0) + (next) > format->length) RAISE(254)
      CHECK(254, write(&(String){next, next, format->chars + (0)}));
      CHECK(255, write(&(String){6, 5, "\"}) )"}));
    }
    else {
      if (!(NULL != node)) {
        CHECK(258, f_syntax_error(&(String){24, 23, "too few lines to format"}, self->func_name));
      }
      glob->line_num = node->line_num;
      CHECK(260, (*((Func**)(node)))[3](node));
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
