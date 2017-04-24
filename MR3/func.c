static char* _mr_file6_name = "func.2.mr";
#define MR_FILE_NAME _mr_file6_name
/* MR3 compiler - function */

static char* _func_name_f_get_access = "f-get-access";
#define MR_FUNC_NAME _func_name_f_get_access
Returncode f_get_access(String* access_text, Int* access) {
  Bool _Bool0;
  CHECK(4, String_equal(access_text, &(String){5, 4, "copy"}, &(_Bool0)))
  if (_Bool0) {
    (*access) = ACCESS_COPY;
  }
  else {
    Bool _Bool1;
    CHECK(6, String_equal(access_text, &(String){5, 4, "user"}, &(_Bool1)))
    if (_Bool1) {
      (*access) = ACCESS_USER;
    }
    else {
      Bool _Bool2;
      CHECK(8, String_equal(access_text, &(String){6, 5, "owner"}, &(_Bool2)))
      if (_Bool2) {
        (*access) = ACCESS_OWNER;
      }
      else {
        Bool _Bool3;
        CHECK(10, String_equal(access_text, &(String){4, 3, "var"}, &(_Bool3)))
        if (_Bool3) {
          (*access) = ACCESS_VAR;
        }
        else {
          CHECK(13, f_syntax_error(&(String){15, 14, "unknown access"}, access_text));
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Dec_arg Dec_arg;

typedef struct Arg_node Arg_node; struct Arg_node {
  Func* _dtl;
  Arg_node* next;
};
static char* _func_name_Arg_node_parse = "Arg-node.parse";
#define MR_FUNC_NAME _func_name_Arg_node_parse
Returncode Arg_node_parse(Arg_node* self, Bool is_out, Int access, Char* end) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_node_analyze = "Arg-node.analyze";
#define MR_FUNC_NAME _func_name_Arg_node_analyze
Returncode Arg_node_analyze(Arg_node* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_node_write_intro = "Arg-node.write-intro";
#define MR_FUNC_NAME _func_name_Arg_node_write_intro
Returncode Arg_node_write_intro(Arg_node* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_node_write_final = "Arg-node.write-final";
#define MR_FUNC_NAME _func_name_Arg_node_write_final
Returncode Arg_node_write_final(Arg_node* self, Bool is_out) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_node_get_dec = "Arg-node.get-dec";
#define MR_FUNC_NAME _func_name_Arg_node_get_dec
Returncode Arg_node_get_dec(Arg_node* self, Dec_arg** arg) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func Arg_node__dtl[] = {Arg_node_parse, Arg_node_analyze, Arg_node_write_intro, Arg_node_write_final, Arg_node_get_dec};

typedef struct Dec_arg Dec_arg; struct Dec_arg {
  Arg_node _base;
  Mvar* mvar;
};
static char* _func_name_Dec_arg_init = "Dec-arg.init";
#define MR_FUNC_NAME _func_name_Dec_arg_init
Returncode Dec_arg_init(Dec_arg* self, Int access, Mtype* mtype, String* name) {
  CHECK(36, init_new_var(mtype, &(self->mvar)));
  self->mvar->access = access;
  CHECK(38, f_new_copy(name, &(self->mvar->name)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_parse = "Dec-arg.parse";
#define MR_FUNC_NAME _func_name_Dec_arg_parse
Returncode Dec_arg_parse(Dec_arg* self, Bool is_out, Int access, Char* end) {
  CHECK(41, init_new_var(NULL, &(self->mvar)));
  self->mvar->is_ref = is_out;
  self->mvar->access = access;
  CHECK(44, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &((*end))))
  if ((*end) == '{') {
    CHECK(45, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &((*end))));
    CHECK(46, read_c(&((*end))));
  }
  CHECK(47, read_new(&(String){3, 2, ",)"}, &(self->mvar->name), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_analyze = "Dec-arg.analyze";
#define MR_FUNC_NAME _func_name_Dec_arg_analyze
Returncode Dec_arg_analyze(Dec_arg* self) {
  CHECK(50, Mvar_analyze(self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_write_intro = "Dec-arg.write-intro";
#define MR_FUNC_NAME _func_name_Dec_arg_write_intro
Returncode Dec_arg_write_intro(Dec_arg* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_write_final = "Dec-arg.write-final";
#define MR_FUNC_NAME _func_name_Dec_arg_write_final
Returncode Dec_arg_write_final(Dec_arg* self, Bool is_out) {
  CHECK(56, write_cstyle(self->mvar->typename));
  if (is_out) {
    CHECK(58, write(&(String){2, 1, "*"}));
  }
  if (self->mvar->access == ACCESS_USER || self->mvar->access == ACCESS_OWNER) {
    CHECK(60, write(&(String){2, 1, "*"}));
  }
  CHECK(61, write(&(String){2, 1, " "}));
  CHECK(62, write_cstyle(self->mvar->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_get_dec = "Dec-arg.get-dec";
#define MR_FUNC_NAME _func_name_Dec_arg_get_dec
Returncode Dec_arg_get_dec(Dec_arg* self, Dec_arg** arg) {
  (*arg) = self;
  return OK;
}
#undef MR_FUNC_NAME
Func Dec_arg__dtl[] = {Dec_arg_parse, Dec_arg_analyze, Dec_arg_write_intro, Dec_arg_write_final, Dec_arg_get_dec};

typedef struct Call_arg Call_arg; struct Call_arg {
  Arg_node _base;
  Int access;
  Mexp* value;
};
static char* _func_name_Call_arg_parse = "Call-arg.parse";
#define MR_FUNC_NAME _func_name_Call_arg_parse
Returncode Call_arg_parse(Call_arg* self, Bool is_out, Int access, Char* end) {
  self->access = access;
  CHECK(73, parse_new_exp(&(String){3, 2, ",)"}, &(self->value), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_analyze = "Call-arg.analyze";
#define MR_FUNC_NAME _func_name_Call_arg_analyze
Returncode Call_arg_analyze(Call_arg* self) {
  CHECK(76, Mexp_analyze(self->value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_write_intro = "Call-arg.write-intro";
#define MR_FUNC_NAME _func_name_Call_arg_write_intro
Returncode Call_arg_write_intro(Call_arg* self) {
  CHECK(79, Mexp_write_intro(self->value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_write_final = "Call-arg.write-final";
#define MR_FUNC_NAME _func_name_Call_arg_write_final
Returncode Call_arg_write_final(Call_arg* self, Bool is_out) {
  if (is_out) {
    CHECK(83, write(&(String){3, 2, "&("}));
  }
  CHECK(84, Mexp_write_final(self->value));
  if (is_out) {
    CHECK(86, write(&(String){2, 1, ")"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_get_dec = "Call-arg.get-dec";
#define MR_FUNC_NAME _func_name_Call_arg_get_dec
Returncode Call_arg_get_dec(Call_arg* self, Dec_arg** arg) {
  (*arg) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
Func Call_arg__dtl[] = {Call_arg_parse, Call_arg_analyze, Call_arg_write_intro, Call_arg_write_final, Call_arg_get_dec};

typedef struct Arg_list Arg_list; struct Arg_list {
  Arg_node* first_param;
  Arg_node* first_out;
  Bool is_dec;
};
static char* _func_name_Arg_list_init = "Arg-list.init";
#define MR_FUNC_NAME _func_name_Arg_list_init
Returncode Arg_list_init(Arg_list* self) {
  self->first_param = NULL;
  self->first_out = NULL;
  self->is_dec = true;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_parse_args = "Arg-list.parse-args";
#define MR_FUNC_NAME _func_name_Arg_list_parse_args
Returncode Arg_list_parse_args(Arg_list* self, Bool is_out) {
  Arg_node* prev = NULL;
  Char end;
  while (true) {
    String* access_text = &(String){128, 0, (char[128]){0}};
    CHECK(106, read(&(String){3, 2, " )"}, access_text, &(end)));
    if (!(end == ' ')) break;
    Int access;
    CHECK(109, f_get_access(access_text, &(access)));
    Type arg_type;
    if (self->is_dec) {
      arg_type = (Type){sizeof(Dec_arg), Dec_arg__dtl};
    }
    else {
      arg_type = (Type){sizeof(Call_arg), Call_arg__dtl};
    }
    if (arg_type.size <= 0) RAISE(115)
    Arg_node* arg = malloc(arg_type.size);
    if (arg == NULL) RAISE(115)
    if (arg_type.dtl != NULL) { *((Func**)(arg)) = arg_type.dtl; }
    CHECK(116, (*((Func**)(arg)))[0](arg, is_out, access, &(end)));
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
    if (!(end == ',')) break;
    CHECK(126, read_c(&(end)));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_parse = "Arg-list.parse";
#define MR_FUNC_NAME _func_name_Arg_list_parse
Returncode Arg_list_parse(Arg_list* self, Bool is_dec, Char* end) {
  self->is_dec = is_dec;
  CHECK(130, Arg_list_parse_args(self, false));
  CHECK(131, read_c(&((*end))))
  if ((*end) == ':') {
    Char _Char4;
    CHECK(132, read_c(&(_Char4)))
    if (_Char4 != '(') {
      CHECK(133, f_syntax_error_c(&(String){17, 16, "expeted '(', got"}, (*end)));
    }
    CHECK(134, Arg_list_parse_args(self, true));
    CHECK(135, read_c(&((*end))));
  }
  else {
    self->first_out = NULL;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_analyze_args = "Arg-list.analyze-args";
#define MR_FUNC_NAME _func_name_Arg_list_analyze_args
Returncode Arg_list_analyze_args(Arg_list* self, Arg_node* first) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(143, (*((Func**)(node)))[1](node));
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_analyze = "Arg-list.analyze";
#define MR_FUNC_NAME _func_name_Arg_list_analyze
Returncode Arg_list_analyze(Arg_list* self) {
  CHECK(147, Arg_list_analyze_args(self, self->first_param));
  CHECK(148, Arg_list_analyze_args(self, self->first_out));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_args_intro = "Arg-list.write-args-intro";
#define MR_FUNC_NAME _func_name_Arg_list_write_args_intro
Returncode Arg_list_write_args_intro(Arg_list* self, Arg_node* first) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(154, (*((Func**)(node)))[2](node));
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_args_final = "Arg-list.write-args-final";
#define MR_FUNC_NAME _func_name_Arg_list_write_args_final
Returncode Arg_list_write_args_final(Arg_list* self, Bool is_out, Arg_node* first) {
  Arg_node* node = first;
  Bool has_more = !is_out && NULL != self->first_out;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(162, (*((Func**)(node)))[3](node, is_out));
    node = node->next;
    if (has_more || NULL != node) {
      CHECK(165, write(&(String){3, 2, ", "}));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_intro = "Arg-list.write-intro";
#define MR_FUNC_NAME _func_name_Arg_list_write_intro
Returncode Arg_list_write_intro(Arg_list* self) {
  CHECK(168, Arg_list_write_args_intro(self, self->first_param));
  CHECK(169, Arg_list_write_args_intro(self, self->first_out));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_final = "Arg-list.write-final";
#define MR_FUNC_NAME _func_name_Arg_list_write_final
Returncode Arg_list_write_final(Arg_list* self) {
  CHECK(172, write(&(String){2, 1, "("}));
  CHECK(173, Arg_list_write_args_final(self, false, self->first_param));
  CHECK(174, Arg_list_write_args_final(self, true, self->first_out));
  CHECK(175, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_arg = "Arg-list.add-arg";
#define MR_FUNC_NAME _func_name_Arg_list_add_arg
Returncode Arg_list_add_arg(Arg_list* self, Int access, Mtype* mtype, String* name, Arg_node** first) {
  Dec_arg* arg = malloc(sizeof(Dec_arg));
  if (arg == NULL) RAISE(178)
  *((Func**)(arg)) = Dec_arg__dtl;
  CHECK(179, Dec_arg_init(arg, access, mtype, name));
  arg->_base.next = (*first);
  (*first) = &(arg->_base);
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_param = "Arg-list.add-param";
#define MR_FUNC_NAME _func_name_Arg_list_add_param
Returncode Arg_list_add_param(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(184, Arg_list_add_arg(self, access, mtype, name, &(self->first_param)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_out = "Arg-list.add-out";
#define MR_FUNC_NAME _func_name_Arg_list_add_out
Returncode Arg_list_add_out(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(187, Arg_list_add_arg(self, access, mtype, name, &(self->first_out)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_self_call = "Arg-list.add-self-call";
#define MR_FUNC_NAME _func_name_Arg_list_add_self_call
Returncode Arg_list_add_self_call(Arg_list* self, Mexp* value) {
  Call_arg* arg = malloc(sizeof(Call_arg));
  if (arg == NULL) RAISE(190)
  *((Func**)(arg)) = Call_arg__dtl;
  arg->access = ACCESS_USER;
  arg->value = value;
  arg->_base.next = self->first_param;
  self->first_param = &(arg->_base);
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_args = "parse-new-args";
#define MR_FUNC_NAME _func_name_parse_new_args
Returncode parse_new_args(Arg_list** new_args) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(197)
  Char _Char5;
  CHECK(198, Arg_list_parse(args, true, &(_Char5)));
  (*new_args) = args;
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Mfunc Mfunc; struct Mfunc {
  String* name;
  Arg_list* args;
  Bool is_dynamic;
  Int dynamic_index;
};
static char* _func_name_Mfunc_init = "Mfunc.init";
#define MR_FUNC_NAME _func_name_Mfunc_init
Returncode Mfunc_init(Mfunc* self, String* name) {
  CHECK(209, f_new_copy(name, &(self->name)));
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(210)
  self->args = args;
  CHECK(212, Arg_list_init(self->args));
  self->is_dynamic = false;
  self->dynamic_index = 0;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_parse = "Mfunc.parse";
#define MR_FUNC_NAME _func_name_Mfunc_parse
Returncode Mfunc_parse(Mfunc* self) {
  if (NULL != glob->mclass) {
    String* meth_type = &(String){64, 0, (char[64]){0}};
    Char _Char6;
    CHECK(219, read(&(String){2, 1, " "}, meth_type, &(_Char6)));
    Bool _Bool7;
    CHECK(220, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool7)))
    self->is_dynamic = _Bool7;
  }
  else {
    self->is_dynamic = false;
  }
  self->dynamic_index = 0;
  Char _Char8;
  CHECK(224, read_new(&(String){2, 1, "("}, &(self->name), &(_Char8)));
  CHECK(225, parse_new_args(&(self->args)));
  if (NULL != glob->mclass) {
    CHECK(227, Arg_list_add_param(self->args, ACCESS_USER, glob->mclass, &(String){5, 4, "self"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_analyze = "Mfunc.analyze";
#define MR_FUNC_NAME _func_name_Mfunc_analyze
Returncode Mfunc_analyze(Mfunc* self) {
  CHECK(230, Arg_list_analyze(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write = "Mfunc.write";
#define MR_FUNC_NAME _func_name_Mfunc_write
Returncode Mfunc_write(Mfunc* self) {
  CHECK(233, write(&(String){12, 11, "Returncode "}));
  CHECK(234, write_cstyle(self->name));
  CHECK(235, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_m_new_var = "Mfunc.m-new-var";
#define MR_FUNC_NAME _func_name_Mfunc_m_new_var
Returncode Mfunc_m_new_var(Mfunc* self, Mvar** mvar) {
  CHECK(238, init_new_var(glob->type_func, &((*mvar))));
  CHECK(239, f_new_copy(self->name, &((*mvar)->name)));
  (*mvar)->func_dec = self;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_mfunc = "parse-new-mfunc";
#define MR_FUNC_NAME _func_name_parse_new_mfunc
Returncode parse_new_mfunc(Mfunc** new_mfunc) {
  Mfunc* mfunc = malloc(sizeof(Mfunc));
  if (mfunc == NULL) RAISE(243)
  CHECK(244, Mfunc_parse(mfunc));
  (*new_mfunc) = mfunc;
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Call_operand Call_operand; struct Call_operand {
  Operand _base;
  Arg_list* args;
};
static char* _func_name_Call_operand_parse = "Call-operand.parse";
#define MR_FUNC_NAME _func_name_Call_operand_parse
Returncode Call_operand_parse(Call_operand* self, String* text, String* ends, Char* end) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(252)
  self->args = args;
  CHECK(254, Arg_list_parse(args, false, &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_analyze = "Call-operand.analyze";
#define MR_FUNC_NAME _func_name_Call_operand_analyze
Returncode Call_operand_analyze(Call_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Member_operand* method) {
  if (mtype != glob->type_func) {
    CHECK(258, f_syntax_error(&(String){15, 14, "not a function"}, mtype->name));
  }
  CHECK(259, Arg_list_analyze(self->args));
  
  if (NULL != method) {
    member->next = NULL;
    Mexp* new_exp = malloc(sizeof(Mexp));
    if (new_exp == NULL) RAISE(263)
    new_exp->operand = exp->operand;
    new_exp->operator = NULL;
    new_exp->next = NULL;
    exp->operand = &(method->_base._base);
    CHECK(268, Arg_list_add_self_call(self->args, new_exp));
  }
  
  if (NULL != self->_base.next) {
    /* todo ... */
    /* self.next.analyze(user exp, user return-type, user self, user _) */
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_intro = "Call-operand.write-intro";
#define MR_FUNC_NAME _func_name_Call_operand_write_intro
Returncode Call_operand_write_intro(Call_operand* self) {
  CHECK(275, Arg_list_write_intro(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_final = "Call-operand.write-final";
#define MR_FUNC_NAME _func_name_Call_operand_write_final
Returncode Call_operand_write_final(Call_operand* self) {
  CHECK(278, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
Func Call_operand__dtl[] = {Call_operand_parse, Call_operand_analyze, Call_operand_write_intro, Call_operand_write_final};


static char* _func_name_parse_new_operand = "parse-new-operand";
#define MR_FUNC_NAME _func_name_parse_new_operand
Returncode parse_new_operand(Type opr_type, String* text, String* ends, Operand** new_opr, Char* end) {
  if (opr_type.size <= 0) RAISE(282)
  Operand* opr = malloc(opr_type.size);
  if (opr == NULL) RAISE(282)
  if (opr_type.dtl != NULL) { *((Func**)(opr)) = opr_type.dtl; }
  (*new_opr) = opr;
  CHECK(284, (*((Func**)(opr)))[0](opr, text, ends, &((*end))));
  Type next_type;
  if ((*end) == '.') {
    next_type = (Type){sizeof(Member_operand), Member_operand__dtl};
  }
  else {
    if ((*end) == '[') {
      next_type = (Type){sizeof(Slice_operand), Slice_operand__dtl};
    }
    else {
      if ((*end) == '(') {
        next_type = (Type){sizeof(Call_operand), Call_operand__dtl};
      }
      else {
        opr->next = NULL;
        return OK;
      }
    }
  }
  CHECK(295, parse_new_operand(next_type, NULL, ends, &(opr->next), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_operands = "parse-new-operands";
#define MR_FUNC_NAME _func_name_parse_new_operands
Returncode parse_new_operands(String* text, String* ends, Operand** new_opr, Char* end) {
  Type opr_type;
  if (text->length == 0) {
    if ((*end) == '(') {
      opr_type = (Type){sizeof(Block_operand), Block_operand__dtl};
    }
    else {
      CHECK(303, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)));
    }
  }
  else {
    if ((0) < 0 || (0) >= text->length) RAISE(305)
    Char first = text->chars[0];
    if (first == '\'') {
      opr_type = (Type){sizeof(Char_operand), Char_operand__dtl};
    }
    else {
      if (first == '"') {
        opr_type = (Type){sizeof(String_operand), String_operand__dtl};
      }
      else {
        if (first >= '0' && first <= '9') {
          opr_type = (Type){sizeof(Int_operand), Int_operand__dtl};
        }
        else {
          if (text->length == 1 && first == '_') {
            opr_type = (Type){sizeof(Empty_operand), Empty_operand__dtl};
          }
          else {
            opr_type = (Type){sizeof(Var_operand), Var_operand__dtl};
          }
        }
      }
    }
  }
  CHECK(316, parse_new_operand(opr_type, text, ends, &((*new_opr)), &((*end))));
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
    CHECK(327, (*((Func**)(arg)))[4](arg, &(dec_arg)));
    if (!(NULL != dec_arg)) break;
    CHECK(329, add_var(self->_base._base.sons_var_map, dec_arg->mvar));
    arg = arg->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_parse = "St-func.parse";
#define MR_FUNC_NAME _func_name_St_func_parse
Returncode St_func_parse(St_func* self) {
  CHECK(333, parse_new_mfunc(&(self->mfunc)));
  Mvar* _Mvar9;
  CHECK(334, Mfunc_m_new_var(self->mfunc, &(_Mvar9)))
  CHECK(334, St_add_var(&(self->_base._base), _Mvar9));
  CHECK(335, f_copy_new_var_map(NULL, &(self->_base._base.sons_var_map)));
  CHECK(336, St_func_add_args_vars(self, self->mfunc->args->first_param));
  CHECK(337, St_func_add_args_vars(self, self->mfunc->args->first_out));
  CHECK(338, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze_first = "St-func.analyze-first";
#define MR_FUNC_NAME _func_name_St_func_analyze_first
Returncode St_func_analyze_first(St_func* self) {
  CHECK(341, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze = "St-func.analyze";
#define MR_FUNC_NAME _func_name_St_func_analyze
Returncode St_func_analyze(St_func* self) {
  CHECK(344, Mfunc_analyze(self->mfunc));
  CHECK(345, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_write = "St-func.write";
#define MR_FUNC_NAME _func_name_St_func_write
Returncode St_func_write(St_func* self) {
  CHECK(348, Mfunc_write(self->mfunc));
  CHECK(349, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_func__dtl[] = {St_func_parse, St_func_analyze_first, St_func_analyze, St_func_write};


typedef struct St_main St_main; struct St_main {
  St_node _base;
};
static char* _func_name_St_main_parse = "St-main.parse";
#define MR_FUNC_NAME _func_name_St_main_parse
Returncode St_main_parse(St_main* self) {
  CHECK(354, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze_first = "St-main.analyze-first";
#define MR_FUNC_NAME _func_name_St_main_analyze_first
Returncode St_main_analyze_first(St_main* self) {
  CHECK(356, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze = "St-main.analyze";
#define MR_FUNC_NAME _func_name_St_main_analyze
Returncode St_main_analyze(St_main* self) {
  CHECK(358, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_write = "St-main.write";
#define MR_FUNC_NAME _func_name_St_main_write
Returncode St_main_write(St_main* self) {
  CHECK(360, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_main__dtl[] = {St_main_parse, St_main_analyze_first, St_main_analyze, St_main_write};

#undef MR_FILE_NAME
