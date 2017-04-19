static char* _mr_file5_name = "exp.2.mr";
#define MR_FILE_NAME _mr_file5_name
/* MR3 compiler - expression */

static char* _func_name_read_new_value = "read-new-value";
#define MR_FUNC_NAME _func_name_read_new_value
Returncode read_new_value(String* ends, String** out_text, Char* end) {
  String* all_ends = new_string(ends->length + 5);
  if (all_ends == NULL) RAISE(4)
  CHECK(5, String_copy(all_ends, &(String){5, 4, " .[("}));
  CHECK(6, String_concat(all_ends, ends));
  CHECK(7, read_new(all_ends, &((*out_text)), &((*end))));
  free(all_ends);
  return OK;
}
#undef MR_FUNC_NAME


Returncode m_find_var(String* name, Mvar** mvar);

typedef struct Operand Operand; struct Operand {
  Func* _dtl;
  Operand* next;
};
static char* _func_name_Operand_parse = "Operand.parse";
#define MR_FUNC_NAME _func_name_Operand_parse
Returncode Operand_parse(Operand* self, String* text, String* ends, Char* end) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_analyze = "Operand.analyze";
#define MR_FUNC_NAME _func_name_Operand_analyze
Returncode Operand_analyze(Operand* self, Mvar* mvar) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_intro = "Operand.write-intro";
#define MR_FUNC_NAME _func_name_Operand_write_intro
Returncode Operand_write_intro(Operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_final = "Operand.write-final";
#define MR_FUNC_NAME _func_name_Operand_write_final
Returncode Operand_write_final(Operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_all_intro = "Operand.write-all-intro";
#define MR_FUNC_NAME _func_name_Operand_write_all_intro
Returncode Operand_write_all_intro(Operand* self) {
  CHECK(26, (*((Func**)(self)))[2](self));
  if (NULL != self->next) {
    CHECK(28, Operand_write_all_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_all_final = "Operand.write-all-final";
#define MR_FUNC_NAME _func_name_Operand_write_all_final
Returncode Operand_write_all_final(Operand* self) {
  CHECK(31, (*((Func**)(self)))[3](self));
  if (NULL != self->next) {
    CHECK(33, Operand_write_all_final(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Operand__dtl[] = {Operand_parse, Operand_analyze, Operand_write_intro, Operand_write_final};

typedef struct Var_operand Var_operand; struct Var_operand {
  Operand _base;
  String* name;
  Mvar* mvar;
};
static char* _func_name_Var_operand_parse = "Var-operand.parse";
#define MR_FUNC_NAME _func_name_Var_operand_parse
Returncode Var_operand_parse(Var_operand* self, String* text, String* ends, Char* end) {
  self->name = text;
  self->mvar = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_operand_analyze_next = "Var-operand.analyze-next";
#define MR_FUNC_NAME _func_name_Var_operand_analyze_next
Returncode Var_operand_analyze_next(Var_operand* self) {
  CHECK(44, Mvar_analyze(self->mvar));
  if (NULL != self->_base.next) {
    CHECK(46, (*((Func**)(self->_base.next)))[1](self->_base.next, self->mvar));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_operand_analyze = "Var-operand.analyze";
#define MR_FUNC_NAME _func_name_Var_operand_analyze
Returncode Var_operand_analyze(Var_operand* self, Mvar* mvar) {
  if (self->name->length < 1) {
    CHECK(50, f_syntax_error(&(String){26, 25, "variable with zero length"}, self->name));
  }
  Char first;
  CHECK(52, String_get(self->name, 0, &(first)));
  
  if (first == '\'' || first == '"') {
    Char _Char0;
    CHECK(55, String_get(self->name, self->name->length - 1, &(_Char0)))
    if (_Char0 != first) {
      CHECK(56, f_syntax_error(&(String){17, 16, "illegal constant"}, self->name));
    }
    if (first == '"') {
      self->mvar = glob->mvar_char;
    }
    else {
      self->mvar = glob->mvar_string;
    }
  }
  else {
    if (first >= '0' && first <= '9') {
      Int n; for (n = 0; n < self->name->length; ++n) {
        Char ch;
        CHECK(64, String_get(self->name, n, &(ch)));
        if (ch < '0' || ch > '9') {
          CHECK(66, f_syntax_error(&(String){15, 14, "illegal number"}, self->name));
        }
      }
      self->mvar = glob->mvar_int;
    }
    else {
      if (self->name->length == 1 && first == '_') {
        if (NULL != self->_base.next) {
          CHECK(70, f_syntax_error(&(String){15, 14, "no members for"}, self->name));
        }
        return OK;
      }
      else {
        CHECK(73, m_find_var(self->name, &(self->mvar)))
        if (!(NULL != self->mvar)) {
          CHECK(74, f_syntax_error(&(String){16, 15, "unknow variable"}, self->name));
        }
      }
    }
  }
  
  CHECK(76, Var_operand_analyze_next(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_operand_write_intro = "Var-operand.write-intro";
#define MR_FUNC_NAME _func_name_Var_operand_write_intro
Returncode Var_operand_write_intro(Var_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_operand_write_final = "Var-operand.write-final";
#define MR_FUNC_NAME _func_name_Var_operand_write_final
Returncode Var_operand_write_final(Var_operand* self) {
  CHECK(82, write_cstyle(self->name));
  return OK;
}
#undef MR_FUNC_NAME
Func Var_operand__dtl[] = {Var_operand_parse, Var_operand_analyze, Var_operand_write_intro, Var_operand_write_final};

typedef struct Block_operand Block_operand; struct Block_operand {
  Operand _base;
  Mexp* exp;
};
static char* _func_name_Block_operand_parse = "Block-operand.parse";
#define MR_FUNC_NAME _func_name_Block_operand_parse
Returncode Block_operand_parse(Block_operand* self, String* text, String* ends, Char* end) {
  CHECK(88, parse_new_exp(&(String){2, 1, ")"}, &(self->exp), &((*end))));
  if ((*end) != ')') {
    CHECK(90, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, ")"}));
  }
  CHECK(91, read_c(&((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_analyze = "Block-operand.analyze";
#define MR_FUNC_NAME _func_name_Block_operand_analyze
Returncode Block_operand_analyze(Block_operand* self, Mvar* mvar) {
  CHECK(94, analyze_exp(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_write_intro = "Block-operand.write-intro";
#define MR_FUNC_NAME _func_name_Block_operand_write_intro
Returncode Block_operand_write_intro(Block_operand* self) {
  CHECK(97, write_exp_intro(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_write_final = "Block-operand.write-final";
#define MR_FUNC_NAME _func_name_Block_operand_write_final
Returncode Block_operand_write_final(Block_operand* self) {
  CHECK(100, write(&(String){2, 1, "("}));
  CHECK(101, write_exp_final(self->exp));
  CHECK(102, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Block_operand__dtl[] = {Block_operand_parse, Block_operand_analyze, Block_operand_write_intro, Block_operand_write_final};

typedef struct Member_operand Member_operand; struct Member_operand {
  Var_operand _base;
};
static char* _func_name_Member_operand_parse = "Member-operand.parse";
#define MR_FUNC_NAME _func_name_Member_operand_parse
Returncode Member_operand_parse(Member_operand* self, String* text, String* ends, Char* end) {
  CHECK(106, read_new_value(ends, &(self->_base.name), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Member_operand_analyze = "Member-operand.analyze";
#define MR_FUNC_NAME _func_name_Member_operand_analyze
Returncode Member_operand_analyze(Member_operand* self, Mvar* mvar) {
  CHECK(109, Var_map_find(mvar->mtype->members, self->_base.name, &(self->_base.mvar)))
  if (!(NULL != self->_base.mvar)) {
    CHECK(110, f_syntax_error2(&(String){5, 4, "type"}, mvar->typename, &(String){14, 13, "has no member"}, self->_base.name));
  }
  CHECK(111, Var_operand_analyze_next(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Member_operand_write_intro = "Member-operand.write-intro";
#define MR_FUNC_NAME _func_name_Member_operand_write_intro
Returncode Member_operand_write_intro(Member_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Member_operand_write_final = "Member-operand.write-final";
#define MR_FUNC_NAME _func_name_Member_operand_write_final
Returncode Member_operand_write_final(Member_operand* self) {
  CHECK(117, write(&(String){3, 2, "->"}));
  CHECK(118, Var_operand_write_final(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func Member_operand__dtl[] = {Member_operand_parse, Member_operand_analyze, Member_operand_write_intro, Member_operand_write_final};

typedef struct Array_operand Array_operand; struct Array_operand {
  Operand _base;
  Mexp* index;
  Mexp* second_index;
};
static char* _func_name_Array_operand_parse = "Array-operand.parse";
#define MR_FUNC_NAME _func_name_Array_operand_parse
Returncode Array_operand_parse(Array_operand* self, String* text, String* ends, Char* end) {
  CHECK(125, parse_new_exp(&(String){3, 2, ":]"}, &(self->index), &((*end))));
  if ((*end) == ':') {
    CHECK(127, parse_new_exp(&(String){3, 2, ":]"}, &(self->second_index), &((*end))));
  }
  else {
    self->second_index = NULL;
  }
  if ((*end) != ']') {
    CHECK(131, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, "]"}));
  }
  CHECK(132, read_c(&((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Array_operand_analyze = "Array-operand.analyze";
#define MR_FUNC_NAME _func_name_Array_operand_analyze
Returncode Array_operand_analyze(Array_operand* self, Mvar* mvar) {
  if (mvar->mtype != glob->type_array) {
    CHECK(136, f_syntax_error(&(String){13, 12, "not an array"}, mvar->name));
  }
  CHECK(137, analyze_exp(self->index));
  if (NULL != self->second_index) {
    CHECK(139, analyze_exp(self->second_index));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Array_operand_write_intro = "Array-operand.write-intro";
#define MR_FUNC_NAME _func_name_Array_operand_write_intro
Returncode Array_operand_write_intro(Array_operand* self) {
  CHECK(142, write_exp_intro(self->index));
  if (NULL != self->second_index) {
    CHECK(144, write_exp_intro(self->second_index));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Array_operand_write_final = "Array-operand.write-final";
#define MR_FUNC_NAME _func_name_Array_operand_write_final
Returncode Array_operand_write_final(Array_operand* self) {
  CHECK(147, write(&(String){2, 1, "["}));
  CHECK(148, write_exp_final(self->index));
  if (NULL != self->second_index) {
    CHECK(150, write(&(String){2, 1, ":"}));
    CHECK(151, write_exp_final(self->second_index));
  }
  CHECK(152, write(&(String){2, 1, "]"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Array_operand__dtl[] = {Array_operand_parse, Array_operand_analyze, Array_operand_write_intro, Array_operand_write_final};

typedef struct Call_operand Call_operand; struct Call_operand {
  Operand _base;
  Arg_list* args;
};
static char* _func_name_Call_operand_parse = "Call-operand.parse";
#define MR_FUNC_NAME _func_name_Call_operand_parse
Returncode Call_operand_parse(Call_operand* self, String* text, String* ends, Char* end) {
  Arg_list* args = malloc(sizeof(Arg_list));
  if (args == NULL) RAISE(158)
  self->args = args;
  CHECK(160, Arg_list_parse(args, false, &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_analyze = "Call-operand.analyze";
#define MR_FUNC_NAME _func_name_Call_operand_analyze
Returncode Call_operand_analyze(Call_operand* self, Mvar* mvar) {
  if (mvar->mtype != glob->type_func) {
    CHECK(164, f_syntax_error(&(String){15, 14, "not a function"}, mvar->name));
  }
  CHECK(165, Arg_list_analyze(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_intro = "Call-operand.write-intro";
#define MR_FUNC_NAME _func_name_Call_operand_write_intro
Returncode Call_operand_write_intro(Call_operand* self) {
  CHECK(168, Arg_list_write_intro(self->args));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Call_operand_write_final = "Call-operand.write-final";
#define MR_FUNC_NAME _func_name_Call_operand_write_final
Returncode Call_operand_write_final(Call_operand* self) {
  CHECK(171, Arg_list_write_final(self->args));
  return OK;
}
#undef MR_FUNC_NAME
Func Call_operand__dtl[] = {Call_operand_parse, Call_operand_analyze, Call_operand_write_intro, Call_operand_write_final};

static char* _func_name_parse_new_operand = "parse-new-operand";
#define MR_FUNC_NAME _func_name_parse_new_operand
Returncode parse_new_operand(Type opr_type, String* text, String* ends, Operand** new_opr, Char* end) {
  if (opr_type.size <= 0) RAISE(174)
  Operand* opr = malloc(opr_type.size);
  if (opr == NULL) RAISE(174)
  if (opr_type.dtl != NULL) { *((Func**)(opr)) = opr_type.dtl; }
  (*new_opr) = opr;
  CHECK(176, (*((Func**)(opr)))[0](opr, text, ends, &((*end))));
  Type next_type;
  if ((*end) == '.') {
    next_type = (Type){sizeof(Member_operand), Member_operand__dtl};
  }
  else {
    if ((*end) == '[') {
      next_type = (Type){sizeof(Array_operand), Array_operand__dtl};
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
  CHECK(187, parse_new_operand(next_type, NULL, ends, &(opr->next), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Mexp Mexp; struct Mexp {
  Operand* operand;
  String* operator;
  Mexp* next;
};
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end);
static char* _func_name_Mexp_parse_new_with_text = "Mexp.parse-new-with-text";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_text
Returncode Mexp_parse_new_with_text(Mexp* self, String* text, String* ends, Mexp** new_exp, Char* end) {
  Mexp* exp = malloc(sizeof(Mexp));
  if (exp == NULL) RAISE(198)
  CHECK(199, Mexp_parse(exp, text, ends, &((*end))));
  (*new_exp) = exp;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new = "Mexp.parse-new";
#define MR_FUNC_NAME _func_name_Mexp_parse_new
Returncode Mexp_parse_new(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  String* text;
  CHECK(204, read_new_value(ends, &(text), &((*end))));
  CHECK(205, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new_with_kw = "Mexp.parse-new-with-kw";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_kw
Returncode Mexp_parse_new_with_kw(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  if (NULL != glob->key_word) {
    String* text;
    CHECK(210, f_new_copy(glob->key_word->text, &(text)));
    (*end) = glob->key_word->end;
    CHECK(212, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  }
  else {
    CHECK(214, Mexp_parse_new(self, ends, &((*new_exp)), &((*end))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse = "Mexp.parse";
#define MR_FUNC_NAME _func_name_Mexp_parse
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end) {
  String* _String1;
  CHECK(217, Op_map_find(glob->op_map, text, &(_String1)))
  if ((*end) == ' ' && NULL != _String1) {
    self->operator = text;
    CHECK(219, read_new_value(ends, &(text), &((*end))));
  }
  else {
    self->operator = NULL;
  }
  
  Type opr_type;
  if (text->length == 0) {
    if ((*end) == '(') {
      opr_type = (Type){sizeof(Block_operand), Block_operand__dtl};
    }
    else {
      CHECK(228, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)));
    }
  }
  else {
    opr_type = (Type){sizeof(Var_operand), Var_operand__dtl};
  }
  CHECK(231, parse_new_operand(opr_type, text, ends, &(self->operand), &((*end))));
  Bool _Bool2;
  CHECK(232, String_has(ends, ' ', &(_Bool2)))
  if ((*end) == ' ' && !_Bool2) {
    CHECK(233, Mexp_parse_new(self, ends, &(self->next), &((*end))));
  }
  else {
    self->next = NULL;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze = "Mexp.analyze";
#define MR_FUNC_NAME _func_name_Mexp_analyze
Returncode Mexp_analyze(Mexp* self) {
  CHECK(238, (*((Func**)(self->operand)))[1](self->operand, NULL));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_all_final = "Mexp.write-all-final";
#define MR_FUNC_NAME _func_name_Mexp_write_all_final
Returncode Mexp_write_all_final(Mexp* self, Bool is_binary) {
  if (NULL != self->operator) {
    String* op;
    CHECK(243, Op_map_find(glob->op_map, self->operator, &(op)))
    if (!(NULL != op)) {
      CHECK(244, f_syntax_error(&(String){16, 15, "unknow operator"}, self->operator));
    }
    if (is_binary) {
      CHECK(246, write(&(String){2, 1, " "}));
    }
    CHECK(247, write(op));
    if (is_binary) {
      CHECK(249, write(&(String){2, 1, " "}));
    }
  }
  CHECK(250, Operand_write_all_final(self->operand));
  if (NULL != self->next) {
    CHECK(252, write(&(String){2, 1, " "}));
    CHECK(253, Mexp_write_all_final(self->next, true));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_intro = "Mexp.write-intro";
#define MR_FUNC_NAME _func_name_Mexp_write_intro
Returncode Mexp_write_intro(Mexp* self) {
  CHECK(256, Operand_write_all_intro(self->operand));
  if (NULL != self->next) {
    CHECK(258, Mexp_write_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_final = "Mexp.write-final";
#define MR_FUNC_NAME _func_name_Mexp_write_final
Returncode Mexp_write_final(Mexp* self) {
  CHECK(261, Mexp_write_all_final(self, false));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp = "parse-new-exp";
#define MR_FUNC_NAME _func_name_parse_new_exp
Returncode parse_new_exp(String* ends, Mexp** exp, Char* end) {
  CHECK(264, Mexp_parse_new(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp_with_kw = "parse-new-exp-with-kw";
#define MR_FUNC_NAME _func_name_parse_new_exp_with_kw
Returncode parse_new_exp_with_kw(String* ends, Mexp** exp, Char* end) {
  CHECK(267, Mexp_parse_new_with_kw(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_analyze_exp = "analyze-exp";
#define MR_FUNC_NAME _func_name_analyze_exp
Returncode analyze_exp(Mexp* exp) {
  CHECK(270, Mexp_analyze(exp));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_exp_intro = "write-exp-intro";
#define MR_FUNC_NAME _func_name_write_exp_intro
Returncode write_exp_intro(Mexp* exp) {
  CHECK(273, Mexp_write_intro(exp));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_exp_final = "write-exp-final";
#define MR_FUNC_NAME _func_name_write_exp_final
Returncode write_exp_final(Mexp* exp) {
  CHECK(276, Mexp_write_final(exp));
  return OK;
}
#undef MR_FUNC_NAME

#undef MR_FILE_NAME
