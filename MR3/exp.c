static char* _mr_file4_name = "exp.2.mr";
#define MR_FILE_NAME _mr_file4_name
/* MR3 compiler - expression */

typedef struct Mexp Mexp;
typedef struct Var_operand Var_operand;

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
Returncode Operand_analyze(Operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
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
static char* _func_name_Operand_analyze_all = "Operand.analyze-all";
#define MR_FUNC_NAME _func_name_Operand_analyze_all
Returncode Operand_analyze_all(Operand* self, Mexp* exp) {
  CHECK(19, (*((Func**)(self)))[1](self, exp, NULL, NULL, NULL));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_all_intro = "Operand.write-all-intro";
#define MR_FUNC_NAME _func_name_Operand_write_all_intro
Returncode Operand_write_all_intro(Operand* self) {
  CHECK(22, (*((Func**)(self)))[2](self));
  if (NULL != self->next) {
    CHECK(24, Operand_write_all_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_all_final = "Operand.write-all-final";
#define MR_FUNC_NAME _func_name_Operand_write_all_final
Returncode Operand_write_all_final(Operand* self) {
  CHECK(27, (*((Func**)(self)))[3](self));
  if (NULL != self->next) {
    CHECK(29, Operand_write_all_final(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Operand__dtl[] = {Operand_parse, Operand_analyze, Operand_write_intro, Operand_write_final};


static char* _func_name_read_new_value = "read-new-value";
#define MR_FUNC_NAME _func_name_read_new_value
Returncode read_new_value(String* ends, String** out_text, Char* end) {
  String* all_ends = new_string(ends->length + 5);
  if (all_ends == NULL) RAISE(33)
  CHECK(34, String_copy(all_ends, &(String){5, 4, " .[("}));
  CHECK(35, String_concat(all_ends, ends));
  CHECK(36, read_new(all_ends, &((*out_text)), &((*end))));
  free(all_ends);
  return OK;
}
#undef MR_FUNC_NAME

Returncode parse_new_operands(String* text, String* ends, Operand** new_opr, Char* end);

typedef struct Mexp Mexp; struct Mexp {
  Operand* operand;
  String* operator;
  Mexp* next;
  Bool is_used;
};
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end);
static char* _func_name_Mexp_parse_new_with_text = "Mexp.parse-new-with-text";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_text
Returncode Mexp_parse_new_with_text(Mexp* self, String* text, String* ends, Mexp** new_exp, Char* end) {
  Mexp* exp = malloc(sizeof(Mexp));
  if (exp == NULL) RAISE(50)
  CHECK(51, Mexp_parse(exp, text, ends, &((*end))));
  (*new_exp) = exp;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new = "Mexp.parse-new";
#define MR_FUNC_NAME _func_name_Mexp_parse_new
Returncode Mexp_parse_new(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  String* text;
  CHECK(56, read_new_value(ends, &(text), &((*end))));
  CHECK(57, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new_with_kw = "Mexp.parse-new-with-kw";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_kw
Returncode Mexp_parse_new_with_kw(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  if (NULL != glob->key_word) {
    String* text;
    CHECK(62, f_new_copy(glob->key_word->text, &(text)));
    (*end) = glob->key_word->end;
    CHECK(64, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  }
  else {
    CHECK(66, Mexp_parse_new(self, ends, &((*new_exp)), &((*end))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse = "Mexp.parse";
#define MR_FUNC_NAME _func_name_Mexp_parse
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end) {
  self->is_used = true;
  String* _String0;
  CHECK(70, Op_map_find(glob->op_map, text, &(_String0)))
  if ((*end) == ' ' && NULL != _String0) {
    self->operator = text;
    CHECK(72, read_new_value(ends, &(text), &((*end))));
    
    String* _String1;
    CHECK(74, Op_map_find(glob->op_map, text, &(_String1)))
    if ((*end) == ' ' && NULL != _String1) {
      self->operand = NULL;
      CHECK(76, Mexp_parse_new_with_text(self, text, ends, &(self->next), &((*end))));
      return OK;
    }
    
  }
  else {
    self->operator = NULL;
  }
  
  CHECK(82, parse_new_operands(text, ends, &(self->operand), &((*end))));
  Bool _Bool2;
  CHECK(83, String_has(ends, ' ', &(_Bool2)))
  if ((*end) == ' ' && !_Bool2) {
    CHECK(84, Mexp_parse_new(self, ends, &(self->next), &((*end))));
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
  if (NULL != self->operand) {
    CHECK(90, (*((Func**)(self->operand)))[1](self->operand, self, NULL, NULL, NULL));
  }
  if (NULL != self->next) {
    CHECK(92, Mexp_analyze(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_all_final = "Mexp.write-all-final";
#define MR_FUNC_NAME _func_name_Mexp_write_all_final
Returncode Mexp_write_all_final(Mexp* self, Bool is_binary) {
  if (NULL != self->operator) {
    String* op;
    CHECK(97, Op_map_find(glob->op_map, self->operator, &(op)))
    if (!(NULL != op)) {
      CHECK(98, f_syntax_error(&(String){16, 15, "unknow operator"}, self->operator));
    }
    if (is_binary) {
      CHECK(100, write(&(String){2, 1, " "}));
    }
    CHECK(101, write(op));
    if (is_binary) {
      CHECK(103, write(&(String){2, 1, " "}));
    }
  }
  if (NULL != self->operand) {
    CHECK(105, Operand_write_all_final(self->operand));
  }
  if (NULL != self->next) {
    CHECK(107, Mexp_write_all_final(self->next, true));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_intro = "Mexp.write-intro";
#define MR_FUNC_NAME _func_name_Mexp_write_intro
Returncode Mexp_write_intro(Mexp* self) {
  if (NULL != self->operand) {
    CHECK(111, Operand_write_all_intro(self->operand));
  }
  if (NULL != self->next) {
    CHECK(113, Mexp_write_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_final = "Mexp.write-final";
#define MR_FUNC_NAME _func_name_Mexp_write_final
Returncode Mexp_write_final(Mexp* self) {
  CHECK(116, Mexp_write_all_final(self, false));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp = "parse-new-exp";
#define MR_FUNC_NAME _func_name_parse_new_exp
Returncode parse_new_exp(String* ends, Mexp** exp, Char* end) {
  CHECK(119, Mexp_parse_new(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp_with_kw = "parse-new-exp-with-kw";
#define MR_FUNC_NAME _func_name_parse_new_exp_with_kw
Returncode parse_new_exp_with_kw(String* ends, Mexp** exp, Char* end) {
  CHECK(122, Mexp_parse_new_with_kw(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME


Returncode m_find_var(String* name, Mvar** mvar);

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
static char* _func_name_Var_operand_analyze = "Var-operand.analyze";
#define MR_FUNC_NAME _func_name_Var_operand_analyze
Returncode Var_operand_analyze(Var_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  CHECK(136, m_find_var(self->name, &(self->mvar)))
  if (!(NULL != self->mvar)) {
    CHECK(137, f_syntax_error(&(String){16, 15, "unknow variable"}, self->name));
  }
  if (NULL != self->_base.next) {
    if (NULL != self->mvar->func_dec) {
      CHECK(140, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, self->mvar->mtype, &(self->_base), self));
    }
    else {
      CHECK(142, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, self->mvar->mtype, &(self->_base), NULL));
    }
  }
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
  if (self->mvar->is_ref) {
    CHECK(149, write(&(String){3, 2, "(*"}));
  }
  CHECK(150, write_cstyle(self->name));
  if (self->mvar->is_ref) {
    CHECK(152, write(&(String){2, 1, ")"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Var_operand__dtl[] = {Var_operand_parse, Var_operand_analyze, Var_operand_write_intro, Var_operand_write_final};


typedef struct Char_operand Char_operand; struct Char_operand {
  Operand _base;
  String* text;
};
static char* _func_name_Char_operand_parse = "Char-operand.parse";
#define MR_FUNC_NAME _func_name_Char_operand_parse
Returncode Char_operand_parse(Char_operand* self, String* text, String* ends, Char* end) {
  Char ch;
  if (text->length == 3) {
    if ((1) < 0 || (1) >= text->length) RAISE(161)
    ch = text->chars[1];
    if (ch == '\'' || ch == '\\') {
      CHECK(163, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
    }
  }
  else {
    if (text->length == 4) {
      if ((1) < 0 || (1) >= text->length) RAISE(165)
      if (text->chars[1] != '\\') {
        CHECK(166, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
      }
      if ((2) < 0 || (2) >= text->length) RAISE(167)
      ch = text->chars[2];
    }
    else {
      CHECK(169, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
    }
  }
  if ((text->length - 1) < 0 || (text->length - 1) >= text->length) RAISE(170)
  if (text->chars[text->length - 1] != '\'') {
    CHECK(171, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
  }
  self->text = text;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Char_operand_analyze = "Char-operand.analyze";
#define MR_FUNC_NAME _func_name_Char_operand_analyze
Returncode Char_operand_analyze(Char_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  if (NULL != self->_base.next) {
    CHECK(176, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, glob->type_char, &(self->_base), NULL));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Char_operand_write_intro = "Char-operand.write-intro";
#define MR_FUNC_NAME _func_name_Char_operand_write_intro
Returncode Char_operand_write_intro(Char_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Char_operand_write_final = "Char-operand.write-final";
#define MR_FUNC_NAME _func_name_Char_operand_write_final
Returncode Char_operand_write_final(Char_operand* self) {
  CHECK(182, write(self->text));
  return OK;
}
#undef MR_FUNC_NAME
Func Char_operand__dtl[] = {Char_operand_parse, Char_operand_analyze, Char_operand_write_intro, Char_operand_write_final};


typedef struct String_operand String_operand; struct String_operand {
  Operand _base;
  String* text;
};
static char* _func_name_String_operand_parse = "String-operand.parse";
#define MR_FUNC_NAME _func_name_String_operand_parse
Returncode String_operand_parse(String_operand* self, String* text, String* ends, Char* end) {
  if ((text->length - 1) < 0 || (text->length - 1) >= text->length) RAISE(188)
  if (text->chars[text->length - 1] != '\"') {
    CHECK(189, f_syntax_error(&(String){24, 23, "illegal string constant"}, text));
  }
  self->text = text;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_String_operand_analyze = "String-operand.analyze";
#define MR_FUNC_NAME _func_name_String_operand_analyze
Returncode String_operand_analyze(String_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  if (NULL != self->_base.next) {
    CHECK(194, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, glob->type_string, &(self->_base), NULL));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_String_operand_write_intro = "String-operand.write-intro";
#define MR_FUNC_NAME _func_name_String_operand_write_intro
Returncode String_operand_write_intro(String_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_String_operand_write_final = "String-operand.write-final";
#define MR_FUNC_NAME _func_name_String_operand_write_final
Returncode String_operand_write_final(String_operand* self) {
  Int real_length = 1;
  Int index; for (index = 1; index < self->text->length - 1; ++index) {
    if ((index) < 0 || (index) >= self->text->length) RAISE(202)
    if (self->text->chars[index] == '\\') {
      index = index + 1;
    }
    real_length = real_length + 1;
  }
  String* length_str = &(String){80, 0, (char[80]){0}};
  CHECK(206, write(&(String){11, 10, "&(String){"}));
  CHECK(207, Int_str(real_length, length_str));
  CHECK(208, write(length_str));
  CHECK(209, write(&(String){3, 2, ", "}));
  real_length = real_length - 1;
  CHECK(211, Int_str(real_length, length_str));
  CHECK(212, write(length_str));
  CHECK(213, write(&(String){3, 2, ", "}));
  CHECK(214, write(self->text));
  CHECK(215, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
Func String_operand__dtl[] = {String_operand_parse, String_operand_analyze, String_operand_write_intro, String_operand_write_final};


typedef struct Int_operand Int_operand; struct Int_operand {
  Operand _base;
  String* text;
  Int value;
};
static char* _func_name_Int_operand_parse = "Int-operand.parse";
#define MR_FUNC_NAME _func_name_Int_operand_parse
Returncode Int_operand_parse(Int_operand* self, String* text, String* ends, Char* end) {
  self->value = 0;
  Int n; for (n = 0; n < text->length; ++n) {
    if ((n) < 0 || (n) >= text->length) RAISE(225)
    Char ch = text->chars[n];
    if (ch < '0' || ch > '9') {
      CHECK(227, f_syntax_error(&(String){15, 14, "illegal number"}, text));
    }
    self->value = self->value * 10 + ch - '0';
  }
  self->text = text;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Int_operand_analyze = "Int-operand.analyze";
#define MR_FUNC_NAME _func_name_Int_operand_analyze
Returncode Int_operand_analyze(Int_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  if (NULL != self->_base.next) {
    CHECK(233, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, glob->type_int, &(self->_base), NULL));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Int_operand_write_intro = "Int-operand.write-intro";
#define MR_FUNC_NAME _func_name_Int_operand_write_intro
Returncode Int_operand_write_intro(Int_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Int_operand_write_final = "Int-operand.write-final";
#define MR_FUNC_NAME _func_name_Int_operand_write_final
Returncode Int_operand_write_final(Int_operand* self) {
  CHECK(239, write(self->text));
  return OK;
}
#undef MR_FUNC_NAME
Func Int_operand__dtl[] = {Int_operand_parse, Int_operand_analyze, Int_operand_write_intro, Int_operand_write_final};


typedef struct Empty_operand Empty_operand; struct Empty_operand {
  Operand _base;
};
static char* _func_name_Empty_operand_parse = "Empty-operand.parse";
#define MR_FUNC_NAME _func_name_Empty_operand_parse
Returncode Empty_operand_parse(Empty_operand* self, String* text, String* ends, Char* end) {
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Empty_operand_analyze = "Empty-operand.analyze";
#define MR_FUNC_NAME _func_name_Empty_operand_analyze
Returncode Empty_operand_analyze(Empty_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  if (NULL != self->_base.next) {
    CHECK(248, f_syntax_error(&(String){15, 14, "no members for"}, &(String){6, 5, "empty"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Empty_operand_write_intro = "Empty-operand.write-intro";
#define MR_FUNC_NAME _func_name_Empty_operand_write_intro
Returncode Empty_operand_write_intro(Empty_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Empty_operand_write_final = "Empty-operand.write-final";
#define MR_FUNC_NAME _func_name_Empty_operand_write_final
Returncode Empty_operand_write_final(Empty_operand* self) {
  CHECK(254, write(&(String){5, 4, "NULL"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Empty_operand__dtl[] = {Empty_operand_parse, Empty_operand_analyze, Empty_operand_write_intro, Empty_operand_write_final};


typedef struct Block_operand Block_operand; struct Block_operand {
  Operand _base;
  Mexp* exp;
};
static char* _func_name_Block_operand_parse = "Block-operand.parse";
#define MR_FUNC_NAME _func_name_Block_operand_parse
Returncode Block_operand_parse(Block_operand* self, String* text, String* ends, Char* end) {
  CHECK(261, parse_new_exp(&(String){2, 1, ")"}, &(self->exp), &((*end))));
  if ((*end) != ')') {
    CHECK(263, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, ")"}));
  }
  CHECK(264, read_c(&((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_analyze = "Block-operand.analyze";
#define MR_FUNC_NAME _func_name_Block_operand_analyze
Returncode Block_operand_analyze(Block_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  CHECK(267, Mexp_analyze(self->exp));
  if (NULL != self->_base.next) {
    /* todo ... */
    /* self.next.analyze(user exp, user exp-type, user self, user _) */
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_write_intro = "Block-operand.write-intro";
#define MR_FUNC_NAME _func_name_Block_operand_write_intro
Returncode Block_operand_write_intro(Block_operand* self) {
  CHECK(273, Mexp_write_intro(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Block_operand_write_final = "Block-operand.write-final";
#define MR_FUNC_NAME _func_name_Block_operand_write_final
Returncode Block_operand_write_final(Block_operand* self) {
  CHECK(276, write(&(String){2, 1, "("}));
  CHECK(277, Mexp_write_final(self->exp));
  CHECK(278, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Block_operand__dtl[] = {Block_operand_parse, Block_operand_analyze, Block_operand_write_intro, Block_operand_write_final};


typedef struct Member_operand Member_operand; struct Member_operand {
  Var_operand _base;
  Int base_count;
  Mtype* mtype;
};
static char* _func_name_Member_operand_parse = "Member-operand.parse";
#define MR_FUNC_NAME _func_name_Member_operand_parse
Returncode Member_operand_parse(Member_operand* self, String* text, String* ends, Char* end) {
  self->base_count = 0;
  CHECK(287, read_new_value(ends, &(self->_base.name), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Member_operand_analyze = "Member-operand.analyze";
#define MR_FUNC_NAME _func_name_Member_operand_analyze
Returncode Member_operand_analyze(Member_operand* self, Mexp* exp, Mtype* var_mtype, Operand* member, Member_operand* method) {
  Mtype* mtype = var_mtype;
  while (true) {
    CHECK(292, Var_map_find(mtype->members, self->_base.name, &(self->_base.mvar)))
    if (!(!(NULL != self->_base.mvar))) break;
    mtype = mtype->base_mtype;
    if (!(NULL != mtype)) {
      CHECK(295, f_syntax_error2(&(String){5, 4, "type"}, var_mtype->name, &(String){14, 13, "has no member"}, self->_base.name));
      self->base_count = self->base_count + 1;
    }
  }
  self->mtype = var_mtype;
  if (NULL != self->_base._base.next) {
    if (NULL != self->_base.mvar->func_dec) {
      CHECK(300, (*((Func**)(self->_base._base.next)))[1](self->_base._base.next, exp, self->_base.mvar->mtype, member, &(self->_base)));
    }
    else {
      CHECK(302, (*((Func**)(self->_base._base.next)))[1](self->_base._base.next, exp, self->_base.mvar->mtype, &(self->_base._base), NULL));
    }
  }
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
  if (NULL != self->_base.mvar->func_dec) {
    Mtype* mtype = self->mtype;
    Int n; for (n = 0; n < self->base_count; ++n) {
      mtype = mtype->base_mtype;
    }
    CHECK(312, write(mtype->name));
    CHECK(313, write(&(String){2, 1, "_"}));
  }
  else {
    CHECK(315, write(&(String){3, 2, "->"}));
    Int n; for (n = 0; n < self->base_count; ++n) {
      CHECK(317, write(&(String){7, 6, "_base."}));
    }
  }
  CHECK(318, Var_operand_write_final(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func Member_operand__dtl[] = {Member_operand_parse, Member_operand_analyze, Member_operand_write_intro, Member_operand_write_final};


typedef struct Slice_operand Slice_operand; struct Slice_operand {
  Operand _base;
  Mexp* index;
  Mexp* second_index;
  Bool is_string;
};
static char* _func_name_Slice_operand_parse = "Slice-operand.parse";
#define MR_FUNC_NAME _func_name_Slice_operand_parse
Returncode Slice_operand_parse(Slice_operand* self, String* text, String* ends, Char* end) {
  CHECK(327, parse_new_exp(&(String){3, 2, ":]"}, &(self->index), &((*end))));
  if ((*end) == ':') {
    CHECK(329, parse_new_exp(&(String){3, 2, ":]"}, &(self->second_index), &((*end))));
  }
  else {
    self->second_index = NULL;
  }
  if ((*end) != ']') {
    CHECK(333, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, "]"}));
  }
  CHECK(334, read_c(&((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Slice_operand_analyze = "Slice-operand.analyze";
#define MR_FUNC_NAME _func_name_Slice_operand_analyze
Returncode Slice_operand_analyze(Slice_operand* self, Mexp* exp, Mtype* mtype, Operand* member, Var_operand* method) {
  if (mtype != glob->type_array && mtype != glob->type_string) {
    CHECK(338, f_syntax_error(&(String){19, 18, "non-sliceable type"}, mtype->name));
  }
  self->is_string = mtype == glob->type_string;
  CHECK(340, Mexp_analyze(self->index));
  if (NULL != self->second_index) {
    CHECK(342, Mexp_analyze(self->second_index));
  }
  if (NULL != self->_base.next) {
    /* todo ... */
    /* self.next.analyze(user exp, user array-type, user self, user _) */
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Slice_operand_write_intro = "Slice-operand.write-intro";
#define MR_FUNC_NAME _func_name_Slice_operand_write_intro
Returncode Slice_operand_write_intro(Slice_operand* self) {
  CHECK(348, Mexp_write_intro(self->index));
  if (NULL != self->second_index) {
    CHECK(350, Mexp_write_intro(self->second_index));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Slice_operand_write_final = "Slice-operand.write-final";
#define MR_FUNC_NAME _func_name_Slice_operand_write_final
Returncode Slice_operand_write_final(Slice_operand* self) {
  if (NULL != self->second_index) {
    return OK;
  }
  if (self->is_string) {
    CHECK(356, write(&(String){8, 7, "->chars"}));
  }
  else {
    CHECK(358, write(&(String){9, 8, "->values"}));
  }
  CHECK(359, write(&(String){2, 1, "["}));
  CHECK(360, Mexp_write_final(self->index));
  CHECK(361, write(&(String){2, 1, "]"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Slice_operand__dtl[] = {Slice_operand_parse, Slice_operand_analyze, Slice_operand_write_intro, Slice_operand_write_final};


typedef struct St_exp St_exp; struct St_exp {
  St _base;
  Mexp* exp;
};
static char* _func_name_St_exp_parse = "St-exp.parse";
#define MR_FUNC_NAME _func_name_St_exp_parse
Returncode St_exp_parse(St_exp* self) {
  Char _Char3;
  CHECK(368, parse_new_exp_with_kw(&(String){1, 0, ""}, &(self->exp), &(_Char3)));
  self->exp->is_used = false;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_analyze_first = "St-exp.analyze-first";
#define MR_FUNC_NAME _func_name_St_exp_analyze_first
Returncode St_exp_analyze_first(St_exp* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_analyze = "St-exp.analyze";
#define MR_FUNC_NAME _func_name_St_exp_analyze
Returncode St_exp_analyze(St_exp* self) {
  CHECK(375, Mexp_analyze(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_write = "St-exp.write";
#define MR_FUNC_NAME _func_name_St_exp_write
Returncode St_exp_write(St_exp* self) {
  CHECK(378, Mexp_write_intro(self->exp));
  CHECK(379, Mexp_write_final(self->exp));
  if (!self->exp->is_used) {
    CHECK(381, write(&(String){2, 1, ";"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_exp__dtl[] = {St_exp_parse, St_exp_analyze_first, St_exp_analyze, St_exp_write};

#undef MR_FILE_NAME
