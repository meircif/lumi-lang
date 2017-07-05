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
Returncode Operand_analyze(Operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
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
  CHECK(19, (*((Func**)(self)))[2](self));
  if (NULL != self->next) {
    CHECK(21, Operand_write_all_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Operand_write_all_final = "Operand.write-all-final";
#define MR_FUNC_NAME _func_name_Operand_write_all_final
Returncode Operand_write_all_final(Operand* self) {
  CHECK(24, (*((Func**)(self)))[3](self));
  if (NULL != self->next) {
    CHECK(26, Operand_write_all_final(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Operand__dtl[] = {Operand_parse, Operand_analyze, Operand_write_intro, Operand_write_final};


static char* _func_name_read_new_value = "read-new-value";
#define MR_FUNC_NAME _func_name_read_new_value
Returncode read_new_value(String* ends, String** out_text, Char* end) {
  String* all_ends = new_string(ends->length + 5);
  if (all_ends == NULL) RAISE(30)
  CHECK(31, String_copy(all_ends, &(String){5, 4, " .[("}));
  CHECK(32, String_concat(all_ends, ends));
  CHECK(33, read_new(all_ends, &((*out_text)), &((*end))));
  free(all_ends);
  return OK;
}
#undef MR_FUNC_NAME

Returncode parse_new_operands(String* text, String* ends, Operand** new_opr, Char* end);

static char* _func_name_f_is_bool_op = "f-is-bool-op";
#define MR_FUNC_NAME _func_name_f_is_bool_op
Returncode f_is_bool_op(String* operator, Bool* is) {
  if (!(NULL != operator)) {
    (*is) = false;
    return OK;
  }
  (*is) = true;
  Bool _Bool0;
  CHECK(43, String_equal(operator, &(String){2, 1, "<"}, &(_Bool0)))
  if (_Bool0) {
    return OK;
  }
  Bool _Bool1;
  CHECK(45, String_equal(operator, &(String){2, 1, ">"}, &(_Bool1)))
  if (_Bool1) {
    return OK;
  }
  Bool _Bool2;
  CHECK(47, String_equal(operator, &(String){3, 2, "<="}, &(_Bool2)))
  if (_Bool2) {
    return OK;
  }
  Bool _Bool3;
  CHECK(49, String_equal(operator, &(String){3, 2, ">="}, &(_Bool3)))
  if (_Bool3) {
    return OK;
  }
  Bool _Bool4;
  CHECK(51, String_equal(operator, &(String){2, 1, "="}, &(_Bool4)))
  if (_Bool4) {
    return OK;
  }
  Bool _Bool5;
  CHECK(53, String_equal(operator, &(String){3, 2, "!="}, &(_Bool5)))
  if (_Bool5) {
    return OK;
  }
  (*is) = false;
  return OK;
}
#undef MR_FUNC_NAME

typedef struct Mexp Mexp; struct Mexp {
  Operand* operand;
  String* operator;
  Mexp* next;
  Int base_count;
  Bool is_used;
};
static char* _func_name_Mexp_init = "Mexp.init";
#define MR_FUNC_NAME _func_name_Mexp_init
Returncode Mexp_init(Mexp* self) {
  self->operand = NULL;
  self->operator = NULL;
  self->next = NULL;
  self->is_used = true;
  self->base_count = 0;
  return OK;
}
#undef MR_FUNC_NAME
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end);
static char* _func_name_Mexp_parse_new_with_text = "Mexp.parse-new-with-text";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_text
Returncode Mexp_parse_new_with_text(Mexp* self, String* text, String* ends, Mexp** new_exp, Char* end) {
  Mexp* exp = malloc(sizeof(Mexp));
  if (exp == NULL) RAISE(74)
  CHECK(75, Mexp_init(exp));
  CHECK(76, Mexp_parse(exp, text, ends, &((*end))));
  (*new_exp) = exp;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new = "Mexp.parse-new";
#define MR_FUNC_NAME _func_name_Mexp_parse_new
Returncode Mexp_parse_new(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  String* text;
  CHECK(81, read_new_value(ends, &(text), &((*end))));
  CHECK(82, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new_with_kw = "Mexp.parse-new-with-kw";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_kw
Returncode Mexp_parse_new_with_kw(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  if (NULL != glob->key_word) {
    String* text;
    CHECK(87, f_new_copy(glob->key_word->text, &(text)));
    (*end) = glob->key_word->end;
    CHECK(89, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  }
  else {
    CHECK(91, Mexp_parse_new(self, ends, &((*new_exp)), &((*end))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse = "Mexp.parse";
#define MR_FUNC_NAME _func_name_Mexp_parse
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end) {
  String* _String6;
  CHECK(94, Op_map_find(glob->op_map, text, &(_String6)))
  if (((*end) == ' ' || (*end) == '\n') && NULL != _String6) {
    self->operator = text;
    if ((*end) == '\n') {
      CHECK(97, read_cont_spaces());
    }
    CHECK(98, read_new_value(ends, &(text), &((*end))));
    
    String* _String7;
    CHECK(100, Op_map_find(glob->op_map, text, &(_String7)))
    if ((*end) == ' ' && NULL != _String7) {
      self->operand = NULL;
      CHECK(102, Mexp_parse_new_with_text(self, text, ends, &(self->next), &((*end))));
      return OK;
    }
  }
  
  CHECK(105, parse_new_operands(text, ends, &(self->operand), &((*end))));
  Bool _Bool8;
  CHECK(106, String_has(ends, ' ', &(_Bool8)))
  if ((*end) == ' ' && !_Bool8) {
    CHECK(107, Mexp_parse_new(self, ends, &(self->next), &((*end))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_f_count_bases = "Mexp.f-count-bases";
#define MR_FUNC_NAME _func_name_Mexp_f_count_bases
Returncode Mexp_f_count_bases(Mexp* self, Mtype* target_mtype, Mtype** mtype, Int* base_count) {
  if (!(NULL != target_mtype)) {
    return OK;
  }
  if (!(NULL != (*mtype))) {
    CHECK(113, f_syntax_error(&(String){23, 22, "got no value, expected"}, target_mtype->name));
  }
  (*base_count) = 0;
  if (target_mtype == glob->type_bool && (*mtype)->is_primitive) {
    (*mtype) = glob->type_bool;
    return OK;
  }
  if (target_mtype == glob->type_char && (*mtype) == glob->type_int) {
    (*mtype) = glob->type_char;
    return OK;
  }
  if (target_mtype == glob->type_int && (*mtype) == glob->type_char) {
    (*mtype) = glob->type_int;
    return OK;
  }
  Mtype* orig_mtype = (*mtype);
  while (true) {
    if (!((*mtype) != target_mtype)) break;
    (*mtype) = (*mtype)->base_mtype;
    if (!(NULL != (*mtype))) {
      CHECK(129, f_syntax_error2(&(String){4, 3, "got"}, orig_mtype->name, &(String){9, 8, "expected"}, target_mtype->name));
    }
    (*base_count) = (*base_count) + 1;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze = "Mexp.analyze";
#define MR_FUNC_NAME _func_name_Mexp_analyze
Returncode Mexp_analyze(Mexp* self, Mtype** mtype, Mtype** sub_mtype) {
  if (NULL != self->operand) {
    Mtype* target_mtype = (*mtype);
    Mtype* target_sub_mtype = (*sub_mtype);
    CHECK(136, (*((Func**)(self->operand)))[1](self->operand, self, NULL, NULL, &((*mtype)), &((*sub_mtype))));
    if (NULL != self->operator && NULL != (*mtype)) {
      Bool _Bool9;
      CHECK(138, String_equal(self->operator, &(String){2, 1, "?"}, &(_Bool9)))
      if (_Bool9) {
        if ((*mtype)->is_primitive) {
          CHECK(140, f_syntax_error(&(String){20, 19, "? on primitive type"}, (*mtype)->name));
        }
        (*mtype) = glob->type_bool;
        (*sub_mtype) = NULL;
      }
    }
    Mtype* next_mtype = (*mtype);
    Mtype* next_sub_mtype = (*sub_mtype);
    if (NULL != self->next) {
      Bool _Bool10;
      CHECK(146, f_is_bool_op(self->next->operator, &(_Bool10)))
      if (_Bool10) {
        (*mtype) = glob->type_bool;
        (*sub_mtype) = NULL;
      }
    }
    CHECK(149, Mexp_f_count_bases(self, target_mtype, &((*mtype)), &(self->base_count)));
    Int _Int11;
    CHECK(150, Mexp_f_count_bases(self, target_sub_mtype, &((*sub_mtype)), &(_Int11)));
    (*mtype) = next_mtype;
    (*sub_mtype) = next_sub_mtype;
    Bool _Bool12;
    CHECK(153, f_is_bool_op(self->operator, &(_Bool12)))
    if (_Bool12) {
      (*mtype) = glob->type_bool;
      (*sub_mtype) = NULL;
    }
  }
  
  if (NULL != self->next) {
    CHECK(158, Mexp_analyze(self->next, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_get_subtype = "Mexp.analyze-get-subtype";
#define MR_FUNC_NAME _func_name_Mexp_analyze_get_subtype
Returncode Mexp_analyze_get_subtype(Mexp* self, Mtype* target_mtype, Mtype** sub_mtype) {
  Mtype* mtype = target_mtype;
  CHECK(162, Mexp_analyze(self, &(mtype), &((*sub_mtype))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_types = "Mexp.analyze-types";
#define MR_FUNC_NAME _func_name_Mexp_analyze_types
Returncode Mexp_analyze_types(Mexp* self, Mtype* target_mtype, Mtype* target_sub_mtype) {
  Mtype* sub_mtype = target_sub_mtype;
  CHECK(166, Mexp_analyze_get_subtype(self, target_mtype, &(sub_mtype)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_type = "Mexp.analyze-type";
#define MR_FUNC_NAME _func_name_Mexp_analyze_type
Returncode Mexp_analyze_type(Mexp* self, Mtype* target_mtype) {
  CHECK(169, Mexp_analyze_types(self, target_mtype, NULL));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_all_final = "Mexp.write-all-final";
#define MR_FUNC_NAME _func_name_Mexp_write_all_final
Returncode Mexp_write_all_final(Mexp* self, Bool is_binary) {
  if (NULL != self->operator) {
    String* op;
    CHECK(174, Op_map_find(glob->op_map, self->operator, &(op)))
    if (!(NULL != op)) {
      CHECK(175, f_syntax_error(&(String){16, 15, "unknow operator"}, self->operator));
    }
    if (is_binary) {
      CHECK(177, write(&(String){2, 1, " "}));
    }
    CHECK(178, write(op));
    if (is_binary) {
      CHECK(180, write(&(String){2, 1, " "}));
    }
  }
  if (NULL != self->operand) {
    if (self->base_count > 0) {
      CHECK(183, write(&(String){3, 2, "&("}));
    }
    CHECK(184, Operand_write_all_final(self->operand));
    if (self->base_count > 0) {
      CHECK(186, write(&(String){8, 7, "->_base"}));
      Int n; for (n = 1; n < self->base_count; ++n) {
        CHECK(188, write(&(String){7, 6, "._base"}));
      }
      CHECK(189, write(&(String){2, 1, ")"}));
    }
  }
  if (NULL != self->next) {
    CHECK(191, Mexp_write_all_final(self->next, true));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_intro = "Mexp.write-intro";
#define MR_FUNC_NAME _func_name_Mexp_write_intro
Returncode Mexp_write_intro(Mexp* self) {
  if (NULL != self->operand) {
    CHECK(195, Operand_write_all_intro(self->operand));
  }
  if (NULL != self->operator) {
    Bool _Bool13;
    CHECK(197, String_equal(self->operator, &(String){2, 1, "/"}, &(_Bool13)))
    if (_Bool13) {
      /* if (operand == 0) RAISE */
      CHECK(199, write(&(String){5, 4, "if ("}));
      CHECK(200, Operand_write_all_final(self->operand));
      CHECK(201, write(&(String){8, 7, " == 0) "}));
      CHECK(202, write_tb_raise());
      CHECK(203, write_new_indent_line());
    }
  }
  if (NULL != self->next) {
    CHECK(205, Mexp_write_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_final = "Mexp.write-final";
#define MR_FUNC_NAME _func_name_Mexp_write_final
Returncode Mexp_write_final(Mexp* self) {
  CHECK(208, Mexp_write_all_final(self, false));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp = "parse-new-exp";
#define MR_FUNC_NAME _func_name_parse_new_exp
Returncode parse_new_exp(String* ends, Mexp** exp, Char* end) {
  CHECK(211, Mexp_parse_new(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp_with_kw = "parse-new-exp-with-kw";
#define MR_FUNC_NAME _func_name_parse_new_exp_with_kw
Returncode parse_new_exp_with_kw(String* ends, Mexp** exp, Char* end) {
  CHECK(214, Mexp_parse_new_with_kw(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME


typedef struct St_exp St_exp; struct St_exp {
  St _base;
  Mexp* exp;
};
static char* _func_name_St_exp_parse = "St-exp.parse";
#define MR_FUNC_NAME _func_name_St_exp_parse
Returncode St_exp_parse(St_exp* self) {
  Char _Char14;
  CHECK(221, parse_new_exp_with_kw(&(String){1, 0, ""}, &(self->exp), &(_Char14)));
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
  Mtype* mtype = NULL;
  Mtype* sub_mtype = NULL;
  CHECK(230, Mexp_analyze(self->exp, &(mtype), &(sub_mtype)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_write = "St-exp.write";
#define MR_FUNC_NAME _func_name_St_exp_write
Returncode St_exp_write(St_exp* self) {
  CHECK(233, Mexp_write_intro(self->exp));
  CHECK(234, Mexp_write_final(self->exp));
  if (!self->exp->is_used) {
    CHECK(236, write(&(String){2, 1, ";"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_exp__dtl[] = {St_exp_parse, St_exp_analyze_first, St_exp_analyze, St_exp_write};

#undef MR_FILE_NAME
