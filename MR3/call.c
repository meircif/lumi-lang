static char* _mr_file10_name = "call.2.mr";
#define MR_FILE_NAME _mr_file10_name
/* MR3 compiler - call operand */

typedef struct Call_operand Call_operand; struct Call_operand {
  Operand _base;
  Arg_list* args;
  Operand* func_opr;
  Operand* dynamic_opr;
  Int dynamic_index;
  Int dynamic_base_count;
  Bool is_used;
  Mtype* res_mtype;
  Mexp* res_exp;
  String* res_name;
};
static char* _func_name_Call_operand_parse = "Call-operand.parse";
#define MR_FUNC_NAME _func_name_Call_operand_parse
Returncode Call_operand_parse(Call_operand* self, String* text, String* ends, Char* end) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(15)
  self->args = args;
  CHECK(17, Arg_list_init(self->args, false));
  CHECK(18, Arg_list_parse(args, false, &((*end))));
  self->func_opr = NULL;
  self->dynamic_opr = NULL;
  self->dynamic_index = 0;
  self->dynamic_base_count = 0;
  self->res_mtype = NULL;
  self->res_name = NULL;
  self->res_exp = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_analyze_args = "Call-operand.analyze-args";
#define MR_FUNC_NAME _func_name_Call_operand_analyze_args
Returncode Call_operand_analyze_args(Call_operand* self, Mfunc* mfunc, Bool is_method, Mtype** mtype, Mtype** sub_mtype) {
  Arg_node* dec_param = mfunc->args->first_param;
  Arg_node* call_param = self->args->first_param;
  Bool not_self = !is_method;
  while (true) {
    if (!(NULL != dec_param)) break;
    if (!(NULL != call_param)) {
      CHECK(34, f_syntax_error(&(String){23, 22, "too few parameters for"}, mfunc->name));
    }
    if (not_self) {
      CHECK(36, (*((Func**)(call_param)))[1](call_param, dec_param, (*mtype), (*sub_mtype)));
    }
    else {
      not_self = true;
    }
    dec_param = dec_param->next;
    call_param = call_param->next;
  }
  if (NULL != call_param) {
    CHECK(42, f_syntax_error(&(String){24, 23, "too many parameters for"}, mfunc->name));
  }
  
  Arg_node* dec_out = mfunc->args->first_out;
  Arg_node* call_out = self->args->first_out;
  if (!(NULL != dec_out)) {
    if (self->is_used) {
      CHECK(48, f_syntax_error(&(String){20, 19, "no return value for"}, mfunc->name));
    }
    if (call_out) {
      CHECK(50, f_syntax_error(&(String){21, 20, "too many outputs for"}, mfunc->name));
    }
    (*mtype) = NULL;
    (*sub_mtype) = NULL;
    return OK;
  }
  
  if (NULL != call_out) {
    CHECK(56, (*((Func**)(call_out)))[1](call_out, dec_out, (*mtype), (*sub_mtype)));
    while (true) {
      if (!(NULL != call_out->next)) break;
      call_out = call_out->next;
      dec_out = dec_out->next;
      if (!(NULL != dec_out)) {
        CHECK(62, f_syntax_error(&(String){21, 20, "too many outputs for"}, mfunc->name));
      }
      CHECK(63, (*((Func**)(call_out)))[1](call_out, dec_out, (*mtype), (*sub_mtype)));
    }
  }
  
  Bool fill_out = NULL != dec_out->next || !(NULL != call_out);
  if (NULL != dec_out->next) {
    dec_out = dec_out->next;
    if (NULL != dec_out->next || !(NULL != call_out)) {
      CHECK(69, f_syntax_error(&(String){20, 19, "too few outputs for"}, mfunc->name));
    }
  }
  Dec_arg* dec_res;
  CHECK(71, (*((Func**)(dec_out)))[4](dec_out, &(dec_res)));
  Mtype* generic_mtype = NULL;
  if (dec_res->mvar->mtype == (*mtype)->generic_mtype) {
    generic_mtype = (*mtype)->generic_mtype;
    (*mtype) = (*sub_mtype);
    (*sub_mtype) = NULL;
  }
  else {
    if (dec_res->mvar->sub_mtype == (*mtype)->generic_mtype) {
      (*mtype) = dec_res->mvar->mtype;
      /* sub-mtype is the same */
    }
    else {
      (*mtype) = dec_res->mvar->mtype;
      (*sub_mtype) = dec_res->mvar->sub_mtype;
    }
  }
  self->res_mtype = (*mtype);
  if (fill_out) {
    String* res_count = &(String){64, 0, (char[64]){0}};
    CHECK(86, Int_str(glob->res_count, res_count));
    glob->res_count = glob->res_count + 1;
    String* res_name = new_string(self->res_mtype->name->length + res_count->length + 2);
    if (res_name == NULL) RAISE(88)
    self->res_name = res_name;
    CHECK(90, String_append(self->res_name, '-'));
    CHECK(91, String_concat(self->res_name, self->res_mtype->name));
    CHECK(92, String_concat(self->res_name, res_count));
    Var_operand* var_opr = malloc(sizeof(Var_operand));
    if (var_opr == NULL) RAISE(93)
    *((Func**)(var_opr)) = Var_operand__dtl;
    CHECK(94, f_new_copy(self->res_name, &(var_opr->name)));
    CHECK(95, init_new_var((*mtype), &(var_opr->mvar)));
    CHECK(96, f_new_copy(self->res_name, &(var_opr->mvar->name)));
    if (NULL != (*sub_mtype)) {
      CHECK(98, f_new_copy((*sub_mtype)->name, &(var_opr->mvar->sub_typename)));
    }
    var_opr->mvar->sub_mtype = (*sub_mtype);
    var_opr->mvar->func_dec = dec_res->mvar->func_dec;
    var_opr->mvar->access = dec_res->mvar->access;
    var_opr->_base.next = NULL;
    Mexp* exp = malloc(sizeof(Mexp));
    if (exp == NULL) RAISE(103)
    CHECK(104, Mexp_init(exp));
    exp->operand = &(var_opr->_base);
    Call_arg* arg = malloc(sizeof(Call_arg));
    if (arg == NULL) RAISE(106)
    *((Func**)(arg)) = Call_arg__dtl;
    arg->access = dec_res->mvar->access;
    arg->generic_mtype = generic_mtype;
    arg->value = exp;
    arg->_base.next = NULL;
    if (NULL != call_out) {
      call_out->next = &(arg->_base);
    }
    else {
      self->args->first_out = &(arg->_base);
    }
  }
  else {
    CHECK(116, (*((Func**)(call_out)))[5](call_out, &(self->res_exp)));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_analyze_func_pointer = "Call-operand.analyze-func-pointer";
#define MR_FUNC_NAME _func_name_Call_operand_analyze_func_pointer
Returncode Call_operand_analyze_func_pointer(Call_operand* self, Mtype** mtype, Mtype** sub_mtype) {
  Arg_node* arg = self->args->first_param;
  Bool first = true;
  while (true) {
    if (!(NULL != arg)) break;
    Mexp* exp;
    CHECK(124, (*((Func**)(arg)))[5](arg, &(exp)));
    Mtype* param_mtype = NULL;
    Mtype* param_sub_mtype = NULL;
    CHECK(127, Mexp_analyze(exp, &(param_mtype), &(param_sub_mtype)));
  }
  arg = self->args->first_out;
  (*mtype) = NULL;
  (*sub_mtype) = NULL;
  while (true) {
    if (!(NULL != arg)) break;
    Mexp* exp;
    CHECK(134, (*((Func**)(arg)))[5](arg, &(exp)));
    (*mtype) = NULL;
    (*sub_mtype) = NULL;
    CHECK(137, Mexp_analyze(exp, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_analyze = "Call-operand.analyze";
#define MR_FUNC_NAME _func_name_Call_operand_analyze
Returncode Call_operand_analyze(Call_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  self->is_used = exp->is_used || NULL != self->_base.next || NULL != exp->next || NULL != exp->operator;
  if (!self->is_used) {
    exp->is_used = true;
  }
  
  member->next = NULL;
  Operand* method_opr;
  method_opr = &(method->_base);
  Bool is_method = NULL != method && method_opr != member;
  if (is_method) {
    method->_base.next = NULL;
    self->func_opr = &(method->_base);
    if (method->mvar->func_dec->is_dynamic && method->allow_dynamic) {
      self->dynamic_opr = exp->operand;
      self->dynamic_index = method->mvar->func_dec->dynamic_index;
      self->dynamic_base_count = method->base_count;
      method->base_count = 0;
    }
    Mexp* new_exp = malloc(sizeof(Mexp));
    if (new_exp == NULL) RAISE(156)
    CHECK(157, Mexp_init(new_exp));
    new_exp->operand = exp->operand;
    new_exp->base_count = method->base_count;
    CHECK(160, Arg_list_add_self_call(self->args, new_exp));
  }
  else {
    self->func_opr = exp->operand;
  }
  exp->operand = &(self->_base);
  
  if (NULL != method && NULL != method->mvar->func_dec) {
    CHECK(166, Call_operand_analyze_args(self, method->mvar->func_dec, is_method, &((*mtype)), &((*sub_mtype))));
  }
  else {
    CHECK(168, Call_operand_analyze_func_pointer(self, &((*mtype)), &((*sub_mtype))));
  }
  
  if (NULL != self->_base.next) {
    CHECK(171, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_call = "Call-operand.write-call";
#define MR_FUNC_NAME _func_name_Call_operand_write_call
Returncode Call_operand_write_call(Call_operand* self) {
  CHECK(174, write_tb_check());
  if (NULL != self->dynamic_opr) {
    /* (opr)->[_base.]_dtl[index] */
    CHECK(177, write(&(String){2, 1, "("}));
    CHECK(178, Operand_write_all_final(self->dynamic_opr));
    CHECK(179, write(&(String){4, 3, ")->"}));
    Int n; for (n = 0; n < self->dynamic_base_count; ++n) {
      CHECK(181, write(&(String){7, 6, "_base."}));
    }
    CHECK(182, write(&(String){6, 5, "_dtl["}));
    CHECK(183, write_int(self->dynamic_index));
    CHECK(184, write(&(String){2, 1, "]"}));
  }
  else {
    CHECK(186, Operand_write_all_final(self->func_opr));
  }
  CHECK(187, Arg_list_write_final(self->args));
  CHECK(188, write(&(String){3, 2, " )"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_intro = "Call-operand.write-intro";
#define MR_FUNC_NAME _func_name_Call_operand_write_intro
Returncode Call_operand_write_intro(Call_operand* self) {
  CHECK(191, Operand_write_all_intro(self->func_opr));
  CHECK(192, Arg_list_write_intro(self->args));
  if (NULL != self->res_exp) {
    CHECK(194, Mexp_write_intro(self->res_exp));
  }
  else {
    if (NULL != self->res_name) {
      CHECK(196, write_cstyle(self->res_mtype->name));
      if (!self->res_mtype->is_primitive) {
        CHECK(198, write(&(String){2, 1, "*"}));
      }
      CHECK(199, write(&(String){2, 1, " "}));
      CHECK(200, write_cstyle(self->res_name));
      CHECK(201, write(&(String){3, 2, ";\n"}));
      CHECK(202, write_spaces());
    }
  }
  if (self->is_used) {
    CHECK(204, Call_operand_write_call(self));
    CHECK(205, write_new_indent_line());
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_final = "Call-operand.write-final";
#define MR_FUNC_NAME _func_name_Call_operand_write_final
Returncode Call_operand_write_final(Call_operand* self) {
  if (self->is_used) {
    if (NULL != self->res_exp) {
      CHECK(210, Mexp_write_final(self->res_exp));
    }
    else {
      if (self->res_name) {
        CHECK(212, write_cstyle(self->res_name));
      }
    }
  }
  else {
    CHECK(214, Call_operand_write_call(self));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Call_operand__dtl[] = {Call_operand_parse, Call_operand_analyze, Call_operand_write_intro, Call_operand_write_final};

#undef MR_FILE_NAME
