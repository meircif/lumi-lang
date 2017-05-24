static char* _mr_file8_name = "func.2.mr";
#define MR_FILE_NAME _mr_file8_name
/* MR3 compiler - function */

typedef struct Mfunc Mfunc; struct Mfunc {
  String* name;
  Arg_list* args;
  Mtype* mclass;
  Bool is_dynamic;
  Int dynamic_index;
};
static char* _func_name_Mfunc_init = "Mfunc.init";
#define MR_FUNC_NAME _func_name_Mfunc_init
Returncode Mfunc_init(Mfunc* self, String* name) {
  CHECK(11, f_new_copy(name, &(self->name)));
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(12)
  self->args = args;
  CHECK(14, Arg_list_init(self->args, true));
  self->mclass = NULL;
  self->is_dynamic = false;
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
    CHECK(23, read(&(String){2, 1, " "}, meth_type, &(_Char0)));
    Bool _Bool1;
    CHECK(24, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool1)))
    self->is_dynamic = _Bool1;
  }
  else {
    self->is_dynamic = false;
  }
  self->dynamic_index = 0;
  Char _Char2;
  CHECK(28, read_new(&(String){2, 1, "("}, &(self->name), &(_Char2)));
  CHECK(29, parse_new_args(&(self->args)));
  if (NULL != self->mclass) {
    CHECK(31, Arg_list_add_param(self->args, ACCESS_VAR, self->mclass, &(String){5, 4, "self"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_analyze = "Mfunc.analyze";
#define MR_FUNC_NAME _func_name_Mfunc_analyze
Returncode Mfunc_analyze(Mfunc* self) {
  CHECK(34, Arg_list_analyze(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write_name = "Mfunc.write-name";
#define MR_FUNC_NAME _func_name_Mfunc_write_name
Returncode Mfunc_write_name(Mfunc* self) {
  if (self->mclass) {
    CHECK(38, write_cstyle(self->mclass->name));
    CHECK(39, write(&(String){2, 1, "_"}));
  }
  CHECK(40, write_cstyle(self->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write = "Mfunc.write";
#define MR_FUNC_NAME _func_name_Mfunc_write
Returncode Mfunc_write(Mfunc* self) {
  CHECK(43, write(&(String){12, 11, "Returncode "}));
  CHECK(44, Mfunc_write_name(self));
  CHECK(45, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_m_new_var = "Mfunc.m-new-var";
#define MR_FUNC_NAME _func_name_Mfunc_m_new_var
Returncode Mfunc_m_new_var(Mfunc* self, Mvar** mvar) {
  CHECK(48, init_new_var(glob->type_func, &((*mvar))));
  CHECK(49, f_new_copy(self->name, &((*mvar)->name)));
  (*mvar)->func_dec = self;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_mfunc = "parse-new-mfunc";
#define MR_FUNC_NAME _func_name_parse_new_mfunc
Returncode parse_new_mfunc(Mfunc** new_mfunc) {
  Mfunc* mfunc = malloc(sizeof(Mfunc));
  if (mfunc == NULL) RAISE(53)
  CHECK(54, Mfunc_parse(mfunc));
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
    CHECK(66, (*((Func**)(arg)))[4](arg, &(dec_arg)));
    if (!(NULL != dec_arg)) break;
    CHECK(68, add_var(self->_base._base.sons_var_map, dec_arg->mvar));
    arg = arg->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_parse = "St-func.parse";
#define MR_FUNC_NAME _func_name_St_func_parse
Returncode St_func_parse(St_func* self) {
  CHECK(72, parse_new_mfunc(&(self->mfunc)));
  Mvar* _Mvar3;
  CHECK(73, Mfunc_m_new_var(self->mfunc, &(_Mvar3)))
  CHECK(73, St_add_var(&(self->_base._base), _Mvar3));
  CHECK(74, f_copy_new_var_map(NULL, &(self->_base._base.sons_var_map)));
  CHECK(75, St_func_add_args_vars(self, self->mfunc->args->first_param));
  CHECK(76, St_func_add_args_vars(self, self->mfunc->args->first_out));
  CHECK(77, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze_first = "St-func.analyze-first";
#define MR_FUNC_NAME _func_name_St_func_analyze_first
Returncode St_func_analyze_first(St_func* self) {
  CHECK(80, Mfunc_analyze(self->mfunc));
  CHECK(81, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze = "St-func.analyze";
#define MR_FUNC_NAME _func_name_St_func_analyze
Returncode St_func_analyze(St_func* self) {
  St_return* st_return = malloc(sizeof(St_return));
  if (st_return == NULL) RAISE(84)
  *((Func**)(st_return)) = St_return__dtl;
  CHECK(85, St_init(&(st_return->_base), &(self->_base._base)));
  CHECK(86, St_node_analyze(&(self->_base)));
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
    CHECK(92, write_new_indent_line());
  }
  CHECK(93, write(&(String){33, 32, "#if MR_STAGE == MR_DECLARATIONS\n"}));
  CHECK(94, write_spaces());
  CHECK(95, Mfunc_write(self->mfunc));
  CHECK(96, write(&(String){3, 2, ";\n"}));
  CHECK(97, write_spaces());
  CHECK(98, write(&(String){32, 31, "#elif MR_STAGE == MR_FUNCTIONS\n"}));
  CHECK(99, write_spaces());
  CHECK(100, write(&(String){25, 24, "static char* _func_name_"}));
  CHECK(101, Mfunc_write_name(self->mfunc));
  CHECK(102, write(&(String){5, 4, " = \""}));
  if (NULL != glob->mclass) {
    CHECK(104, write(glob->mclass->name));
    CHECK(105, write(&(String){2, 1, "."}));
  }
  CHECK(106, write(self->mfunc->name));
  CHECK(107, write(&(String){4, 3, "\";\n"}));
  CHECK(108, write_spaces());
  CHECK(109, write(&(String){33, 32, "#define MR_FUNC_NAME _func_name_"}));
  CHECK(110, Mfunc_write_name(self->mfunc));
  CHECK(111, write_new_indent_line());
  CHECK(112, Mfunc_write(self->mfunc));
  Mtype* mclass = glob->mclass;
  glob->mclass = NULL;
  CHECK(115, St_node_write(&(self->_base)));
  glob->mclass = mclass;
  CHECK(117, write_new_indent_line());
  CHECK(118, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}));
  CHECK(119, write_spaces());
  CHECK(120, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_func__dtl[] = {St_func_parse, St_func_analyze_first, St_func_analyze, St_func_write};


typedef struct St_main St_main; struct St_main {
  St_func _base;
};
static char* _func_name_St_main_parse = "St-main.parse";
#define MR_FUNC_NAME _func_name_St_main_parse
Returncode St_main_parse(St_main* self) {
  CHECK(125, St_func_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze_first = "St-main.analyze-first";
#define MR_FUNC_NAME _func_name_St_main_analyze_first
Returncode St_main_analyze_first(St_main* self) {
  CHECK(128, St_func_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze = "St-main.analyze";
#define MR_FUNC_NAME _func_name_St_main_analyze
Returncode St_main_analyze(St_main* self) {
  CHECK(131, St_func_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_write = "St-main.write";
#define MR_FUNC_NAME _func_name_St_main_write
Returncode St_main_write(St_main* self) {
  CHECK(134, St_func_write(&(self->_base)));
  CHECK(135, write(&(String){32, 31, "\n\n#if MR_STAGE == MR_FUNCTIONS\n"}));
  CHECK(136, write(&(String){11, 10, "MAIN_FUNC\n"}));
  CHECK(137, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_main__dtl[] = {St_main_parse, St_main_analyze_first, St_main_analyze, St_main_write};


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
  CHECK(149, read_new(&(String){3, 2, ".("}, &(self->func_name), &(_Char4)))
  if (_Char4 == '.') {
    self->item_name = self->func_name;
    Char _Char5;
    CHECK(151, read_new(&(String){2, 1, "("}, &(self->func_name), &(_Char5)));
  }
  String* format = &(String){256, 0, (char[256]){0}};
  Char _Char6;
  CHECK(153, read(&(String){2, 1, ")"}, format, &(_Char6)));
  if ((format->length - 1) < 0 || (format->length - 1) >= format->length) RAISE(154)
  if ((0) < 0 || (0) >= format->length) RAISE(154)
  if (format->length < 2 || format->chars[0] != '"' || format->chars[format->length - 1] != '"') {
    CHECK(155, f_syntax_error(&(String){22, 21, "illegal format string"}, format));
  }
  if ((1) < 0 || (format->length - 2) < 0 || (1) + (format->length - 2) > format->length) RAISE(156)
  CHECK(156, f_new_copy(&(String){format->length - 2, format->length - 2, format->chars + (1)}, &(self->format)));
  Char _Char7;
  CHECK(157, read_c(&(_Char7)));
  CHECK(158, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze_first = "St-format.analyze-first";
#define MR_FUNC_NAME _func_name_St_format_analyze_first
Returncode St_format_analyze_first(St_format* self) {
  CHECK(161, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_format_analyze = "St-format.analyze";
#define MR_FUNC_NAME _func_name_St_format_analyze
Returncode St_format_analyze(St_format* self) {
  Mvar* mvar;
  if (NULL != self->item_name) {
    CHECK(166, f_find_var(self->item_name, &(self->item_mvar)))
    if (!(NULL != self->item_mvar)) {
      CHECK(167, f_syntax_error(&(String){16, 15, "unknow variable"}, self->item_name));
    }
    CHECK(168, Var_map_find(self->item_mvar->mtype->members, self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(169, f_syntax_error2(&(String){5, 4, "type"}, self->item_mvar->typename, &(String){14, 13, "has no method"}, self->func_name));
    }
  }
  else {
    CHECK(171, f_find_var(self->func_name, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(172, f_syntax_error(&(String){16, 15, "unknow function"}, self->func_name));
    }
  }
  if (!(NULL != mvar->func_dec)) {
    CHECK(174, f_syntax_error(&(String){22, 21, "non function variable"}, self->func_name));
  }
  if (!(NULL != mvar->func_dec->args->first_param)) {
    CHECK(176, f_syntax_error(&(String){26, 25, "no parameter for function"}, self->func_name));
  }
  if (NULL != mvar->func_dec->args->first_out) {
    CHECK(178, f_syntax_error(&(String){27, 26, "outputs exists in function"}, self->func_name));
  }
  Dec_arg* param_dec;
  if (NULL != self->item_name) {
    if (!(NULL != mvar->func_dec->args->first_param->next)) {
      CHECK(182, f_syntax_error(&(String){24, 23, "no parameter for method"}, self->func_name));
    }
    CHECK(183, (*((Func**)(mvar->func_dec->args->first_param->next)))[4](mvar->func_dec->args->first_param->next, &(param_dec)));
  }
  else {
    CHECK(185, (*((Func**)(mvar->func_dec->args->first_param)))[4](mvar->func_dec->args->first_param, &(param_dec)));
  }
  if (NULL != param_dec->_base.next) {
    CHECK(187, f_syntax_error(&(String){32, 31, "too many parameter for function"}, self->func_name));
  }
  if (param_dec->mvar->mtype != glob->type_string) {
    CHECK(189, f_syntax_error2(&(String){40, 39, "expected a string parameter in function"}, self->func_name, &(String){12, 11, " instead of"}, param_dec->mvar->typename));
  }
  if (param_dec->mvar->access != ACCESS_USER) {
    CHECK(191, f_syntax_error(&(String){48, 47, "expected parameter with user access in function"}, self->func_name));
  }
  CHECK(192, St_node_analyze(&(self->_base)));
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
      CHECK(201, write_new_indent_line());
    }
    if ((index) < 0 || (len) < 0 || (index) + (len) > self->format->length) RAISE(202)
    String* format = &(String){len, len, self->format->chars + (index)};
    Int _Int8;
    CHECK(203, String_find(format, &(String){3, 2, "{}"}, &(_Int8)))
    Int next = _Int8;
    if (next > 0) {
      CHECK(205, write_tb_check());
      if (NULL != self->item_mvar) {
        CHECK(207, write_cstyle(self->item_mvar->mtype->name));
        CHECK(208, write(&(String){2, 1, "_"}));
      }
      CHECK(209, write_cstyle(self->func_name));
      CHECK(210, write(&(String){2, 1, "("}));
      if (NULL != self->item_mvar) {
        if (self->item_mvar->is_ref) {
          CHECK(213, write(&(String){2, 1, "*"}));
        }
        CHECK(214, write_cstyle(self->item_mvar->name));
        CHECK(215, write(&(String){3, 2, ", "}));
      }
      CHECK(216, write(&(String){11, 10, "&(String){"}));
      CHECK(217, write_int(next + 1));
      CHECK(218, write(&(String){3, 2, ", "}));
      CHECK(219, write_int(next));
      CHECK(220, write(&(String){4, 3, ", \""}));
      if ((0) < 0 || (next) < 0 || (0) + (next) > format->length) RAISE(221)
      CHECK(221, write(&(String){next, next, format->chars + (0)}));
      CHECK(222, write(&(String){6, 5, "\"}) )"}));
    }
    else {
      if (!(NULL != node)) {
        CHECK(225, f_syntax_error(&(String){24, 23, "too few lines to format"}, self->func_name));
      }
      glob->line_num = node->line_num;
      CHECK(227, (*((Func**)(node)))[3](node));
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
