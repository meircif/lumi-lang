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
  if (exp == NULL) RAISE(55)
  CHECK(56, Mexp_init(exp));
  CHECK(57, Mexp_parse(exp, text, ends, &((*end))));
  (*new_exp) = exp;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new = "Mexp.parse-new";
#define MR_FUNC_NAME _func_name_Mexp_parse_new
Returncode Mexp_parse_new(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  String* text;
  CHECK(62, read_new_value(ends, &(text), &((*end))));
  CHECK(63, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse_new_with_kw = "Mexp.parse-new-with-kw";
#define MR_FUNC_NAME _func_name_Mexp_parse_new_with_kw
Returncode Mexp_parse_new_with_kw(Mexp* self, String* ends, Mexp** new_exp, Char* end) {
  if (NULL != glob->key_word) {
    String* text;
    CHECK(68, f_new_copy(glob->key_word->text, &(text)));
    (*end) = glob->key_word->end;
    CHECK(70, Mexp_parse_new_with_text(self, text, ends, &((*new_exp)), &((*end))));
  }
  else {
    CHECK(72, Mexp_parse_new(self, ends, &((*new_exp)), &((*end))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_parse = "Mexp.parse";
#define MR_FUNC_NAME _func_name_Mexp_parse
Returncode Mexp_parse(Mexp* self, String* text, String* ends, Char* end) {
  String* _String0;
  CHECK(75, Op_map_find(glob->op_map, text, &(_String0)))
  if ((*end) == ' ' && NULL != _String0) {
    self->operator = text;
    CHECK(77, read_new_value(ends, &(text), &((*end))));
    
    String* _String1;
    CHECK(79, Op_map_find(glob->op_map, text, &(_String1)))
    if ((*end) == ' ' && NULL != _String1) {
      self->operand = NULL;
      CHECK(81, Mexp_parse_new_with_text(self, text, ends, &(self->next), &((*end))));
      return OK;
    }
  }
  
  CHECK(84, parse_new_operands(text, ends, &(self->operand), &((*end))));
  Bool _Bool2;
  CHECK(85, String_has(ends, ' ', &(_Bool2)))
  if ((*end) == ' ' && !_Bool2) {
    CHECK(86, Mexp_parse_new(self, ends, &(self->next), &((*end))));
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
    CHECK(92, f_syntax_error(&(String){23, 22, "got no value, expected"}, target_mtype->name));
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
      CHECK(108, f_syntax_error2(&(String){4, 3, "got"}, orig_mtype->name, &(String){9, 8, "expected"}, target_mtype->name));
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
    CHECK(115, (*((Func**)(self->operand)))[1](self->operand, self, NULL, NULL, &((*mtype)), &((*sub_mtype))));
    if (NULL != self->operator && NULL != (*mtype)) {
      Bool _Bool3;
      CHECK(117, String_equal(self->operator, &(String){2, 1, "?"}, &(_Bool3)))
      if (_Bool3) {
        if ((*mtype)->is_primitive) {
          CHECK(119, f_syntax_error(&(String){20, 19, "? on primitive type"}, (*mtype)->name));
        }
        (*mtype) = glob->type_bool;
        (*sub_mtype) = NULL;
      }
    }
    CHECK(122, Mexp_f_count_bases(self, target_mtype, &((*mtype)), &(self->base_count)));
    Int _Int4;
    CHECK(123, Mexp_f_count_bases(self, target_sub_mtype, &((*sub_mtype)), &(_Int4)));
  }
  
  if (NULL != self->next) {
    CHECK(126, Mexp_analyze(self->next, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_get_subtype = "Mexp.analyze-get-subtype";
#define MR_FUNC_NAME _func_name_Mexp_analyze_get_subtype
Returncode Mexp_analyze_get_subtype(Mexp* self, Mtype* target_mtype, Mtype** sub_mtype) {
  Mtype* mtype = target_mtype;
  CHECK(130, Mexp_analyze(self, &(mtype), &((*sub_mtype))));
  if (!(NULL != mtype)) {
    CHECK(132, f_syntax_error(&(String){23, 22, "got no value, expected"}, target_mtype->name));
  }
  if (mtype != target_mtype) {
    CHECK(134, f_syntax_error2(&(String){4, 3, "got"}, mtype->name, &(String){9, 8, "expected"}, target_mtype->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_types = "Mexp.analyze-types";
#define MR_FUNC_NAME _func_name_Mexp_analyze_types
Returncode Mexp_analyze_types(Mexp* self, Mtype* target_mtype, Mtype* target_sub_mtype) {
  Mtype* sub_mtype = target_sub_mtype;
  CHECK(138, Mexp_analyze_get_subtype(self, target_mtype, &(sub_mtype)));
  if (NULL != target_sub_mtype) {
    if (!(NULL != sub_mtype)) {
      CHECK(141, f_syntax_error(&(String){26, 25, "got no sub-type, expected"}, target_sub_mtype->name));
    }
    if (sub_mtype != target_sub_mtype) {
      CHECK(143, f_syntax_error2(&(String){13, 12, "got sub-type"}, sub_mtype->name, &(String){9, 8, "expected"}, target_sub_mtype->name));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_analyze_type = "Mexp.analyze-type";
#define MR_FUNC_NAME _func_name_Mexp_analyze_type
Returncode Mexp_analyze_type(Mexp* self, Mtype* target_mtype) {
  CHECK(146, Mexp_analyze_types(self, target_mtype, NULL));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_all_final = "Mexp.write-all-final";
#define MR_FUNC_NAME _func_name_Mexp_write_all_final
Returncode Mexp_write_all_final(Mexp* self, Bool is_binary) {
  if (NULL != self->operator) {
    String* op;
    CHECK(151, Op_map_find(glob->op_map, self->operator, &(op)))
    if (!(NULL != op)) {
      CHECK(152, f_syntax_error(&(String){16, 15, "unknow operator"}, self->operator));
    }
    if (is_binary) {
      CHECK(154, write(&(String){2, 1, " "}));
    }
    CHECK(155, write(op));
    if (is_binary) {
      CHECK(157, write(&(String){2, 1, " "}));
    }
  }
  if (NULL != self->operand) {
    if (self->base_count > 0) {
      CHECK(160, write(&(String){3, 2, "&("}));
    }
    CHECK(161, Operand_write_all_final(self->operand));
    if (self->base_count > 0) {
      CHECK(163, write(&(String){8, 7, "->_base"}));
      Int n; for (n = 1; n < self->base_count; ++n) {
        CHECK(165, write(&(String){7, 6, "._base"}));
      }
      CHECK(166, write(&(String){2, 1, ")"}));
    }
  }
  if (NULL != self->next) {
    CHECK(168, Mexp_write_all_final(self->next, true));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_intro = "Mexp.write-intro";
#define MR_FUNC_NAME _func_name_Mexp_write_intro
Returncode Mexp_write_intro(Mexp* self) {
  if (NULL != self->operand) {
    CHECK(172, Operand_write_all_intro(self->operand));
  }
  if (NULL != self->next) {
    CHECK(174, Mexp_write_intro(self->next));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mexp_write_final = "Mexp.write-final";
#define MR_FUNC_NAME _func_name_Mexp_write_final
Returncode Mexp_write_final(Mexp* self) {
  CHECK(177, Mexp_write_all_final(self, false));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp = "parse-new-exp";
#define MR_FUNC_NAME _func_name_parse_new_exp
Returncode parse_new_exp(String* ends, Mexp** exp, Char* end) {
  CHECK(180, Mexp_parse_new(NULL, ends, &((*exp)), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_parse_new_exp_with_kw = "parse-new-exp-with-kw";
#define MR_FUNC_NAME _func_name_parse_new_exp_with_kw
Returncode parse_new_exp_with_kw(String* ends, Mexp** exp, Char* end) {
  CHECK(183, Mexp_parse_new_with_kw(NULL, ends, &((*exp)), &((*end))));
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
  Char _Char5;
  CHECK(190, parse_new_exp_with_kw(&(String){1, 0, ""}, &(self->exp), &(_Char5)));
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
  CHECK(199, Mexp_analyze(self->exp, &(mtype), &(sub_mtype)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_write = "St-exp.write";
#define MR_FUNC_NAME _func_name_St_exp_write
Returncode St_exp_write(St_exp* self) {
  CHECK(202, Mexp_write_intro(self->exp));
  CHECK(203, Mexp_write_final(self->exp));
  if (!self->exp->is_used) {
    CHECK(205, write(&(String){2, 1, ";"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_exp__dtl[] = {St_exp_parse, St_exp_analyze_first, St_exp_analyze, St_exp_write};

#undef MR_FILE_NAME
