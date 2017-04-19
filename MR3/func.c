static char* _mr_file4_name = "func.2.mr";
#define MR_FILE_NAME _mr_file4_name
/* MR3 compiler - function */

typedef struct Mexp Mexp;
Returncode parse_new_exp(String* ends, Mexp** exp, Char* end);
Returncode analyze_exp(Mexp* exp);
Returncode write_exp_intro(Mexp* exp);
Returncode write_exp_final(Mexp* exp);


static char* _func_name_f_get_access = "f-get-access";
#define MR_FUNC_NAME _func_name_f_get_access
Returncode f_get_access(String* access_text, Int* access) {
  Bool _Bool0;
  CHECK(11, String_equal(access_text, &(String){5, 4, "copy"}, &(_Bool0)))
  if (_Bool0) {
    (*access) = ACCESS_COPY;
  }
  else {
    Bool _Bool1;
    CHECK(13, String_equal(access_text, &(String){5, 4, "user"}, &(_Bool1)))
    if (_Bool1) {
      (*access) = ACCESS_USER;
    }
    else {
      Bool _Bool2;
      CHECK(15, String_equal(access_text, &(String){6, 5, "owner"}, &(_Bool2)))
      if (_Bool2) {
        (*access) = ACCESS_OWNER;
      }
      else {
        Bool _Bool3;
        CHECK(17, String_equal(access_text, &(String){4, 3, "var"}, &(_Bool3)))
        if (_Bool3) {
          (*access) = ACCESS_VAR;
        }
        else {
          CHECK(20, f_syntax_error(&(String){15, 14, "unknown access"}, access_text));
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
Returncode Arg_node_parse(Arg_node* self, Int access, Char* end) {
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
Returncode Arg_node_write_final(Arg_node* self) {
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
  CHECK(43, init_new_var(mtype, &(self->mvar)));
  self->mvar->access = access;
  CHECK(45, f_new_copy(name, &(self->mvar->name)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_parse = "Dec-arg.parse";
#define MR_FUNC_NAME _func_name_Dec_arg_parse
Returncode Dec_arg_parse(Dec_arg* self, Int access, Char* end) {
  CHECK(48, init_new_var(NULL, &(self->mvar)));
  self->mvar->access = access;
  CHECK(50, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &((*end))))
  if ((*end) == '{') {
    CHECK(51, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &((*end))));
    CHECK(52, read_c(&((*end))));
  }
  CHECK(53, read_new(&(String){3, 2, ",)"}, &(self->mvar->name), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Dec_arg_analyze = "Dec-arg.analyze";
#define MR_FUNC_NAME _func_name_Dec_arg_analyze
Returncode Dec_arg_analyze(Dec_arg* self) {
  CHECK(56, Mvar_analyze(self->mvar));
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
Returncode Dec_arg_write_final(Dec_arg* self) {
  CHECK(62, write_cstyle(self->mvar->typename));
  CHECK(63, write(&(String){2, 1, " "}));
  CHECK(64, write_cstyle(self->mvar->name));
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
Returncode Call_arg_parse(Call_arg* self, Int access, Char* end) {
  self->access = access;
  CHECK(75, parse_new_exp(&(String){3, 2, ",)"}, &(self->value), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_analyze = "Call-arg.analyze";
#define MR_FUNC_NAME _func_name_Call_arg_analyze
Returncode Call_arg_analyze(Call_arg* self) {
  CHECK(78, analyze_exp(self->value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_write_intro = "Call-arg.write-intro";
#define MR_FUNC_NAME _func_name_Call_arg_write_intro
Returncode Call_arg_write_intro(Call_arg* self) {
  CHECK(81, write_exp_intro(self->value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_arg_write_final = "Call-arg.write-final";
#define MR_FUNC_NAME _func_name_Call_arg_write_final
Returncode Call_arg_write_final(Call_arg* self) {
  CHECK(84, write_exp_final(self->value));
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
Returncode Arg_list_parse_args(Arg_list* self, Arg_node** first) {
  (*first) = NULL;
  Arg_node* prev = NULL;
  Char end;
  while (true) {
    String* access_text = &(String){128, 0, (char[128]){0}};
    CHECK(105, read(&(String){3, 2, " )"}, access_text, &(end)));
    if (!(end == ' ')) break;
    Int access;
    CHECK(108, f_get_access(access_text, &(access)));
    Type arg_type;
    if (self->is_dec) {
      arg_type = (Type){sizeof(Dec_arg), Dec_arg__dtl};
    }
    else {
      arg_type = (Type){sizeof(Call_arg), Call_arg__dtl};
    }
    if (arg_type.size <= 0) RAISE(114)
    Arg_node* arg = malloc(arg_type.size);
    if (arg == NULL) RAISE(114)
    if (arg_type.dtl != NULL) { *((Func**)(arg)) = arg_type.dtl; }
    CHECK(115, (*((Func**)(arg)))[0](arg, access, &(end)));
    arg->next = NULL;
    if (NULL != prev) {
      prev->next = arg;
    }
    else {
      (*first) = arg;
    }
    prev = arg;
    if (!(end == ',')) break;
    CHECK(123, read_c(&(end)));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_parse = "Arg-list.parse";
#define MR_FUNC_NAME _func_name_Arg_list_parse
Returncode Arg_list_parse(Arg_list* self, Bool is_dec, Char* end) {
  self->is_dec = is_dec;
  CHECK(127, Arg_list_parse_args(self, &(self->first_param)));
  CHECK(128, read_c(&((*end))))
  if ((*end) == ':') {
    Char _Char4;
    CHECK(129, read_c(&(_Char4)))
    if (_Char4 != '(') {
      CHECK(130, f_syntax_error_c(&(String){17, 16, "expeted '(', got"}, (*end)));
    }
    CHECK(131, Arg_list_parse_args(self, &(self->first_out)));
    CHECK(132, read_c(&((*end))));
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
    CHECK(140, (*((Func**)(node)))[1](node));
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_analyze = "Arg-list.analyze";
#define MR_FUNC_NAME _func_name_Arg_list_analyze
Returncode Arg_list_analyze(Arg_list* self) {
  CHECK(144, Arg_list_analyze_args(self, self->first_param));
  CHECK(145, Arg_list_analyze_args(self, self->first_out));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_args_intro = "Arg-list.write-args-intro";
#define MR_FUNC_NAME _func_name_Arg_list_write_args_intro
Returncode Arg_list_write_args_intro(Arg_list* self, Arg_node* first) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(151, (*((Func**)(node)))[2](node));
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_args_final = "Arg-list.write-args-final";
#define MR_FUNC_NAME _func_name_Arg_list_write_args_final
Returncode Arg_list_write_args_final(Arg_list* self, Arg_node* first, Bool has_more) {
  Arg_node* node = first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(158, (*((Func**)(node)))[3](node));
    node = node->next;
    if (has_more || NULL != node) {
      CHECK(161, write(&(String){3, 2, ", "}));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_intro = "Arg-list.write-intro";
#define MR_FUNC_NAME _func_name_Arg_list_write_intro
Returncode Arg_list_write_intro(Arg_list* self) {
  CHECK(164, Arg_list_write_args_intro(self, self->first_param));
  CHECK(165, Arg_list_write_args_intro(self, self->first_out));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_write_final = "Arg-list.write-final";
#define MR_FUNC_NAME _func_name_Arg_list_write_final
Returncode Arg_list_write_final(Arg_list* self) {
  CHECK(168, write(&(String){2, 1, "("}));
  CHECK(169, Arg_list_write_args_final(self, self->first_param, NULL != self->first_out));
  CHECK(170, Arg_list_write_args_final(self, self->first_out, false));
  CHECK(171, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_arg = "Arg-list.add-arg";
#define MR_FUNC_NAME _func_name_Arg_list_add_arg
Returncode Arg_list_add_arg(Arg_list* self, Int access, Mtype* mtype, String* name, Arg_node** first) {
  Dec_arg* arg = malloc(sizeof(Dec_arg));
  if (arg == NULL) RAISE(174)
  *((Func**)(arg)) = Dec_arg__dtl;
  CHECK(175, Dec_arg_init(arg, access, mtype, name));
  arg->_base.next = (*first);
  (*first) = &(arg->_base);
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_param = "Arg-list.add-param";
#define MR_FUNC_NAME _func_name_Arg_list_add_param
Returncode Arg_list_add_param(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(180, Arg_list_add_arg(self, access, mtype, name, &(self->first_param)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Arg_list_add_out = "Arg-list.add-out";
#define MR_FUNC_NAME _func_name_Arg_list_add_out
Returncode Arg_list_add_out(Arg_list* self, Int access, Mtype* mtype, String* name) {
  CHECK(183, Arg_list_add_arg(self, access, mtype, name, &(self->first_out)));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_args = "parse-new-args";
#define MR_FUNC_NAME _func_name_parse_new_args
Returncode parse_new_args(Arg_list** new_args) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(186)
  Char _Char5;
  CHECK(187, Arg_list_parse(args, true, &(_Char5)));
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
  CHECK(198, f_new_copy(name, &(self->name)));
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(199)
  self->args = args;
  CHECK(201, Arg_list_init(self->args));
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
    CHECK(208, read(&(String){2, 1, " "}, meth_type, &(_Char6)));
    Bool _Bool7;
    CHECK(209, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool7)))
    self->is_dynamic = _Bool7;
  }
  else {
    self->is_dynamic = false;
  }
  self->dynamic_index = 0;
  Char _Char8;
  CHECK(213, read_new(&(String){2, 1, "("}, &(self->name), &(_Char8)));
  CHECK(214, parse_new_args(&(self->args)));
  if (NULL != glob->mclass) {
    CHECK(216, Arg_list_add_param(self->args, ACCESS_USER, glob->mclass, &(String){5, 4, "self"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_analyze = "Mfunc.analyze";
#define MR_FUNC_NAME _func_name_Mfunc_analyze
Returncode Mfunc_analyze(Mfunc* self) {
  CHECK(219, Arg_list_analyze(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_write = "Mfunc.write";
#define MR_FUNC_NAME _func_name_Mfunc_write
Returncode Mfunc_write(Mfunc* self) {
  CHECK(222, write(&(String){12, 11, "Returncode "}));
  CHECK(223, write_cstyle(self->name));
  CHECK(224, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mfunc_m_new_var = "Mfunc.m-new-var";
#define MR_FUNC_NAME _func_name_Mfunc_m_new_var
Returncode Mfunc_m_new_var(Mfunc* self, Mvar** mvar) {
  CHECK(227, init_new_var(glob->type_func, &((*mvar))));
  CHECK(228, f_new_copy(self->name, &((*mvar)->name)));
  (*mvar)->func_dec = self;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_mfunc = "parse-new-mfunc";
#define MR_FUNC_NAME _func_name_parse_new_mfunc
Returncode parse_new_mfunc(Mfunc** new_mfunc) {
  Mfunc* mfunc = malloc(sizeof(Mfunc));
  if (mfunc == NULL) RAISE(232)
  CHECK(233, Mfunc_parse(mfunc));
  (*new_mfunc) = mfunc;
  return OK;
}
#undef MR_FUNC_NAME

#undef MR_FILE_NAME
