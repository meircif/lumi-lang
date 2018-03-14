static char* _lumi_file7_name = "args.2.lm";
#define LUMI_FILE_NAME _lumi_file7_name
/* TL3 compiler - arguments */

typedef struct Dec_arg Dec_arg;

typedef struct Arg_node Arg_node; struct Arg_node {
  Func* _dtl;
  Arg_node* next;
};
static char* _func_name_Arg_node_parse = "Arg-node.parse";
#define LUMI_FUNC_NAME _func_name_Arg_node_parse
Returncode Arg_node_parse(Arg_node* self, Bool is_out, Int access, Char* end) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_node_analyze = "Arg-node.analyze";
#define LUMI_FUNC_NAME _func_name_Arg_node_analyze
Returncode Arg_node_analyze(Arg_node* self, Arg_node* arg, Mtype* prev_mtype, Mtype* prev_sub_mtype) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_node_write_intro = "Arg-node.write-intro";
#define LUMI_FUNC_NAME _func_name_Arg_node_write_intro
Returncode Arg_node_write_intro(Arg_node* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_node_write_final = "Arg-node.write-final";
#define LUMI_FUNC_NAME _func_name_Arg_node_write_final
Returncode Arg_node_write_final(Arg_node* self, Bool is_out) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_node_get_dec = "Arg-node.get-dec";
#define LUMI_FUNC_NAME _func_name_Arg_node_get_dec
Returncode Arg_node_get_dec(Arg_node* self, Dec_arg** arg) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_node_get_call_value = "Arg-node.get-call-value";
#define LUMI_FUNC_NAME _func_name_Arg_node_get_call_value
Returncode Arg_node_get_call_value(Arg_node* self, Mexp** exp) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
Func Arg_node__dtl[] = {Arg_node_parse, Arg_node_analyze, Arg_node_write_intro, Arg_node_write_final, Arg_node_get_dec, Arg_node_get_call_value};

typedef struct Dec_arg Dec_arg; struct Dec_arg {
  Arg_node _base;
  Mvar* mvar;
};
static char* _func_name_Dec_arg_init = "Dec-arg.init";
#define LUMI_FUNC_NAME _func_name_Dec_arg_init
Returncode Dec_arg_init(Dec_arg* self, Int access, Mtype* mtype, String* name) {
  CHECK(25, init_new_var(mtype, &(self->mvar)));
  self->mvar->access = access;
  CHECK(27, f_new_copy(name, &(self->mvar->name)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_parse = "Dec-arg.parse";
#define LUMI_FUNC_NAME _func_name_Dec_arg_parse
Returncode Dec_arg_parse(Dec_arg* self, Bool is_out, Int access, Char* end) {
  CHECK(30, init_new_var(NULL, &(self->mvar)));
  self->mvar->is_ref = is_out;
  self->mvar->access = access;
  CHECK(33, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &((*end))))
  if ((*end) == '{') {
    CHECK(34, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &((*end))));
    CHECK(35, read_c(&((*end))));
  }
  CHECK(36, read_new(&(String){3, 2, ",)"}, &(self->mvar->name), &((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_analyze = "Dec-arg.analyze";
#define LUMI_FUNC_NAME _func_name_Dec_arg_analyze
Returncode Dec_arg_analyze(Dec_arg* self, Arg_node* arg, Mtype* prev_mtype, Mtype* prev_sub_mtype) {
  CHECK(39, Mvar_analyze(self->mvar));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_write_intro = "Dec-arg.write-intro";
#define LUMI_FUNC_NAME _func_name_Dec_arg_write_intro
Returncode Dec_arg_write_intro(Dec_arg* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_write_final = "Dec-arg.write-final";
#define LUMI_FUNC_NAME _func_name_Dec_arg_write_final
Returncode Dec_arg_write_final(Dec_arg* self, Bool is_out) {
  CHECK(45, write_cstyle(self->mvar->mtype->name));
  if (is_out) {
    CHECK(47, write(&(String){2, 1, "*"}));
  }
  if (self->mvar->access == ACCESS_USER || self->mvar->access == ACCESS_OWNER) {
    CHECK(49, write(&(String){2, 1, "*"}));
  }
  else {
    if (self->mvar->access == ACCESS_VAR && !self->mvar->mtype->is_primitive) {
      CHECK(51, write(&(String){2, 1, "*"}));
    }
  }
  CHECK(52, write(&(String){2, 1, " "}));
  CHECK(53, write_cstyle(self->mvar->name));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_get_dec = "Dec-arg.get-dec";
#define LUMI_FUNC_NAME _func_name_Dec_arg_get_dec
Returncode Dec_arg_get_dec(Dec_arg* self, Dec_arg** arg) {
  (*arg) = self;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Dec_arg_get_call_value = "Dec-arg.get-call-value";
#define LUMI_FUNC_NAME _func_name_Dec_arg_get_call_value
Returncode Dec_arg_get_call_value(Dec_arg* self, Mexp** exp) {
  RAISE(59)
}
#undef LUMI_FUNC_NAME
Func Dec_arg__dtl[] = {Dec_arg_parse, Dec_arg_analyze, Dec_arg_write_intro, Dec_arg_write_final, Dec_arg_get_dec, Dec_arg_get_call_value};

typedef struct Call_arg Call_arg; struct Call_arg {
  Arg_node _base;
  Int access;
  Mtype* generic_mtype;
  Mexp* value;
};
static char* _func_name_Call_arg_parse = "Call-arg.parse";
#define LUMI_FUNC_NAME _func_name_Call_arg_parse
Returncode Call_arg_parse(Call_arg* self, Bool is_out, Int access, Char* end) {
  self->access = access;
  self->generic_mtype = NULL;
  CHECK(69, parse_new_exp(&(String){3, 2, ",)"}, &(self->value), &((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Call_arg_analyze = "Call-arg.analyze";
#define LUMI_FUNC_NAME _func_name_Call_arg_analyze
Returncode Call_arg_analyze(Call_arg* self, Arg_node* arg, Mtype* prev_mtype, Mtype* prev_sub_mtype) {
  Dec_arg* dec_arg;
  CHECK(73, (*((Func**)(arg)))[4](arg, &(dec_arg)));
  if (self->access != dec_arg->mvar->access) {
    CHECK(75, f_syntax_error(&(String){25, 24, "invalid access for param"}, dec_arg->mvar->name));
  }
  Mtype* mtype = dec_arg->mvar->mtype;
  Mtype* sub_mtype = dec_arg->mvar->sub_mtype;
  if (mtype == prev_mtype->generic_mtype) {
    mtype = prev_sub_mtype;
    sub_mtype = NULL;
    self->generic_mtype = prev_mtype->generic_mtype;
  }
  else {
    if (sub_mtype == prev_mtype->generic_mtype) {
      sub_mtype = prev_sub_mtype;
    }
  }
  CHECK(84, Mexp_analyze(self->value, &(mtype), &(sub_mtype)));
  if (!self->value->is_used) {
    self->generic_mtype = mtype;
    self->value->is_used = true;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Call_arg_write_intro = "Call-arg.write-intro";
#define LUMI_FUNC_NAME _func_name_Call_arg_write_intro
Returncode Call_arg_write_intro(Call_arg* self) {
  CHECK(90, Mexp_write_intro(self->value));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Call_arg_write_final = "Call-arg.write-final";
#define LUMI_FUNC_NAME _func_name_Call_arg_write_final
Returncode Call_arg_write_final(Call_arg* self, Bool is_out) {
  if (is_out) {
    if (NULL != self->generic_mtype) {
      CHECK(95, write(&(String){2, 1, "("}));
      CHECK(96, write_cstyle(self->generic_mtype->name));
      CHECK(97, write(&(String){4, 3, "**)"}));
    }
    CHECK(98, write(&(String){3, 2, "&("}));
  }
  CHECK(99, Mexp_write_final(self->value));
  if (is_out) {
    CHECK(101, write(&(String){2, 1, ")"}));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Call_arg_get_dec = "Call-arg.get-dec";
#define LUMI_FUNC_NAME _func_name_Call_arg_get_dec
Returncode Call_arg_get_dec(Call_arg* self, Dec_arg** arg) {
  RAISE(104)
}
#undef LUMI_FUNC_NAME
static char* _func_name_Call_arg_get_call_value = "Call-arg.get-call-value";
#define LUMI_FUNC_NAME _func_name_Call_arg_get_call_value
Returncode Call_arg_get_call_value(Call_arg* self, Mexp** exp) {
  (*exp) = self->value;
  return OK;
}
#undef LUMI_FUNC_NAME
Func Call_arg__dtl[] = {Call_arg_parse, Call_arg_analyze, Call_arg_write_intro, Call_arg_write_final, Call_arg_get_dec, Call_arg_get_call_value};

typedef struct Arg_list Arg_list; struct Arg_list {
  Arg_node* first_param;
  Arg_node* first_out;
  Bool is_dec;
};
static char* _func_name_Arg_list_init = "Arg-list.init";
#define LUMI_FUNC_NAME _func_name_Arg_list_init
Returncode Arg_list_init(Arg_list* self, Bool is_dec) {
  self->first_param = NULL;
  self->first_out = NULL;
  self->is_dec = is_dec;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_parse_args = "Arg-list.parse-args";
#define LUMI_FUNC_NAME _func_name_Arg_list_parse_args
Returncode Arg_list_parse_args(Arg_list* self, Bool is_out) {
  Arg_node* prev = NULL;
  Char end;
  while (true) {
    String* access_text = &(String){128, 0, (char[128]){0}};
    CHECK(124, read(&(String){3, 2, " )"}, access_text, &(end)));
    if (access_text->length == 0 && end == '\n') {
      CHECK(126, read_cont_spaces());
      CHECK(127, read(&(String){2, 1, " "}, access_text, &(end)));
    }
    if (!(end == ' ')) break;
    Int access;
    CHECK(130, f_get_access(access_text, &(access)));
    Type arg_type;
    if (self->is_dec) {
      arg_type = (Type){sizeof(Dec_arg), Dec_arg__dtl};
    }
    else {
      arg_type = (Type){sizeof(Call_arg), Call_arg__dtl};
    }
    if (arg_type.size <= 0) RAISE(136)
    Arg_node* arg = malloc(arg_type.size);
    if (arg == NULL) RAISE(136)
    if (arg_type.dtl != NULL) { *((Func**)(arg)) = arg_type.dtl; }
    CHECK(137, (*((Func**)(arg)))[0](arg, is_out, access, &(end)));
    arg->next = NULL;
    if (NULL != prev) {
      prev->next = arg;
    }
    else {
      if (is_out) {
        self->first_out = arg;
      }
      else {
        self->first_param = arg;
      }
    }
    prev = arg;
    if (end == '\n') {
      CHECK(147, read_cont_spaces());
      CHECK(148, read_c(&(end)));
    }
    if (!(end == ',')) break;
    CHECK(150, read_c(&(end)));
    if (end == '\n') {
      CHECK(152, read_cont_spaces());
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_parse = "Arg-list.parse";
#define LUMI_FUNC_NAME _func_name_Arg_list_parse
Returncode Arg_list_parse(Arg_list* self, Bool is_dec, Char* end) {
  self->is_dec = is_dec;
  CHECK(156, Arg_list_parse_args(self, false));
  CHECK(157, read_c(&((*end))))
  if ((*end) == ':') {
    Char _Char0;
    CHECK(158, read_c(&(_Char0)))
    if (_Char0 != '(') {
      CHECK(159, f_syntax_error_c(&(String){17, 16, "expeted '(', got"}, (*end)));
    }
    CHECK(160, Arg_list_parse_args(self, true));
    CHECK(161, read_c(&((*end))));
  }
  else {
    self->first_out = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_analyze_args = "Arg-list.analyze-args";
#define LUMI_FUNC_NAME _func_name_Arg_list_analyze_args
Returncode Arg_list_analyze_args(Arg_list* self, Arg_node* first) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(169, (*((Func**)(node)))[1](node, NULL, NULL, NULL));
    node = node->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_analyze = "Arg-list.analyze";
#define LUMI_FUNC_NAME _func_name_Arg_list_analyze
Returncode Arg_list_analyze(Arg_list* self) {
  CHECK(173, Arg_list_analyze_args(self, self->first_param));
  CHECK(174, Arg_list_analyze_args(self, self->first_out));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_write_args_intro = "Arg-list.write-args-intro";
#define LUMI_FUNC_NAME _func_name_Arg_list_write_args_intro
Returncode Arg_list_write_args_intro(Arg_list* self, Arg_node* first) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(180, (*((Func**)(node)))[2](node));
    node = node->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_write_args_final = "Arg-list.write-args-final";
#define LUMI_FUNC_NAME _func_name_Arg_list_write_args_final
Returncode Arg_list_write_args_final(Arg_list* self, Bool is_out, Arg_node* first) {
  Arg_node* node = first;
  Bool has_more = !is_out && NULL != self->first_out;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(188, (*((Func**)(node)))[3](node, is_out));
    node = node->next;
    if (has_more || NULL != node) {
      CHECK(191, write(&(String){3, 2, ", "}));
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_write_intro = "Arg-list.write-intro";
#define LUMI_FUNC_NAME _func_name_Arg_list_write_intro
Returncode Arg_list_write_intro(Arg_list* self) {
  CHECK(194, Arg_list_write_args_intro(self, self->first_param));
  CHECK(195, Arg_list_write_args_intro(self, self->first_out));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_write_final = "Arg-list.write-final";
#define LUMI_FUNC_NAME _func_name_Arg_list_write_final
Returncode Arg_list_write_final(Arg_list* self) {
  CHECK(198, write(&(String){2, 1, "("}));
  CHECK(199, Arg_list_write_args_final(self, false, self->first_param));
  CHECK(200, Arg_list_write_args_final(self, true, self->first_out));
  CHECK(201, write(&(String){2, 1, ")"}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_add_arg = "Arg-list.add-arg";
#define LUMI_FUNC_NAME _func_name_Arg_list_add_arg
Returncode Arg_list_add_arg(Arg_list* self, Int access, Mtype* mtype, String* name, Arg_node** first) {
  Dec_arg* arg = malloc(sizeof(Dec_arg));
  if (arg == NULL) RAISE(204)
  *((Func**)(arg)) = Dec_arg__dtl;
  CHECK(205, Dec_arg_init(arg, access, mtype, name));
  arg->_base.next = (*first);
  (*first) = &(arg->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_add_param = "Arg-list.add-param";
#define LUMI_FUNC_NAME _func_name_Arg_list_add_param
Returncode Arg_list_add_param(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(210, Arg_list_add_arg(self, access, mtype, name, &(self->first_param)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_add_out = "Arg-list.add-out";
#define LUMI_FUNC_NAME _func_name_Arg_list_add_out
Returncode Arg_list_add_out(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(213, Arg_list_add_arg(self, access, mtype, name, &(self->first_out)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Arg_list_add_self_call = "Arg-list.add-self-call";
#define LUMI_FUNC_NAME _func_name_Arg_list_add_self_call
Returncode Arg_list_add_self_call(Arg_list* self, Mexp* value) {
  Call_arg* arg = malloc(sizeof(Call_arg));
  if (arg == NULL) RAISE(216)
  *((Func**)(arg)) = Call_arg__dtl;
  arg->access = ACCESS_VAR;
  arg->value = value;
  arg->_base.next = self->first_param;
  self->first_param = &(arg->_base);
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_parse_new_args = "parse-new-args";
#define LUMI_FUNC_NAME _func_name_parse_new_args
Returncode parse_new_args(Arg_list** new_args) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(223)
  CHECK(224, Arg_list_init(args, true));
  Char _Char1;
  CHECK(225, Arg_list_parse(args, true, &(_Char1)));
  (*new_args) = args;
  return OK;
}
#undef LUMI_FUNC_NAME

#undef LUMI_FILE_NAME
