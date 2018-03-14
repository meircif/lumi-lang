static char* _mr_file11_name = "operand.2.lm";
#define LUMI_FILE_NAME _mr_file11_name
/* TL3 compiler - operands */

typedef struct Char_operand Char_operand; struct Char_operand {
  Operand _base;
  String* text;
};
static char* _func_name_Char_operand_parse = "Char-operand.parse";
#define LUMI_FUNC_NAME _func_name_Char_operand_parse
Returncode Char_operand_parse(Char_operand* self, String* text, String* ends, Char* end) {
  Char ch;
  if (text->length == 3) {
    if ((1) < 0 || (1) >= text->length) RAISE(9)
    ch = text->chars[1];
    if (ch == '\'' || ch == '\\') {
      CHECK(11, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
    }
  }
  else {
    if (text->length == 4) {
      if ((1) < 0 || (1) >= text->length) RAISE(13)
      if (text->chars[1] != '\\') {
        CHECK(14, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
      }
      if ((2) < 0 || (2) >= text->length) RAISE(15)
      ch = text->chars[2];
    }
    else {
      CHECK(17, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
    }
  }
  if ((text->length - 1) < 0 || (text->length - 1) >= text->length) RAISE(18)
  if (text->chars[text->length - 1] != '\'') {
    CHECK(19, f_syntax_error(&(String){27, 26, "illegal character constant"}, text));
  }
  self->text = text;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Char_operand_analyze = "Char-operand.analyze";
#define LUMI_FUNC_NAME _func_name_Char_operand_analyze
Returncode Char_operand_analyze(Char_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  (*mtype) = glob->type_char;
  (*sub_mtype) = NULL;
  if (NULL != self->_base.next) {
    CHECK(26, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Char_operand_write_intro = "Char-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_Char_operand_write_intro
Returncode Char_operand_write_intro(Char_operand* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Char_operand_write_final = "Char-operand.write-final";
#define LUMI_FUNC_NAME _func_name_Char_operand_write_final
Returncode Char_operand_write_final(Char_operand* self) {
  CHECK(32, write(self->text));
  return OK;
}
#undef LUMI_FUNC_NAME
Func Char_operand__dtl[] = {Char_operand_parse, Char_operand_analyze, Char_operand_write_intro, Char_operand_write_final};


typedef struct String_operand String_operand; struct String_operand {
  Operand _base;
  String* text;
};
static char* _func_name_String_operand_parse = "String-operand.parse";
#define LUMI_FUNC_NAME _func_name_String_operand_parse
Returncode String_operand_parse(String_operand* self, String* text, String* ends, Char* end) {
  if ((text->length - 1) < 0 || (text->length - 1) >= text->length) RAISE(39)
  if (text->chars[text->length - 1] != '\"') {
    CHECK(40, f_syntax_error(&(String){24, 23, "illegal string constant"}, text));
  }
  self->text = text;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_String_operand_analyze = "String-operand.analyze";
#define LUMI_FUNC_NAME _func_name_String_operand_analyze
Returncode String_operand_analyze(String_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  (*mtype) = glob->type_string;
  (*sub_mtype) = NULL;
  if (NULL != self->_base.next) {
    CHECK(47, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_String_operand_write_intro = "String-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_String_operand_write_intro
Returncode String_operand_write_intro(String_operand* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_String_operand_write_final = "String-operand.write-final";
#define LUMI_FUNC_NAME _func_name_String_operand_write_final
Returncode String_operand_write_final(String_operand* self) {
  Int real_length = 1;
  Int index; for (index = 1; index < self->text->length - 1; ++index) {
    if ((index) < 0 || (index) >= self->text->length) RAISE(55)
    if (self->text->chars[index] == '\\') {
      index = index + 1;
    }
    real_length = real_length + 1;
  }
  CHECK(58, write(&(String){11, 10, "&(String){"}));
  CHECK(59, write_int(real_length));
  CHECK(60, write(&(String){3, 2, ", "}));
  CHECK(61, write_int(real_length - 1));
  CHECK(62, write(&(String){3, 2, ", "}));
  CHECK(63, write(self->text));
  CHECK(64, write(&(String){2, 1, "}"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func String_operand__dtl[] = {String_operand_parse, String_operand_analyze, String_operand_write_intro, String_operand_write_final};


typedef struct Int_operand Int_operand; struct Int_operand {
  Operand _base;
  String* text;
  Int value;
};
static char* _func_name_Int_operand_parse = "Int-operand.parse";
#define LUMI_FUNC_NAME _func_name_Int_operand_parse
Returncode Int_operand_parse(Int_operand* self, String* text, String* ends, Char* end) {
  self->value = 0;
  Int n; for (n = 0; n < text->length; ++n) {
    if ((n) < 0 || (n) >= text->length) RAISE(74)
    Char ch = text->chars[n];
    if (ch < '0' || ch > '9') {
      CHECK(76, f_syntax_error(&(String){15, 14, "illegal number"}, text));
    }
    self->value = self->value * 10 + ch - '0';
  }
  self->text = text;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Int_operand_analyze = "Int-operand.analyze";
#define LUMI_FUNC_NAME _func_name_Int_operand_analyze
Returncode Int_operand_analyze(Int_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  (*mtype) = glob->type_int;
  (*sub_mtype) = NULL;
  if (NULL != self->_base.next) {
    CHECK(84, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Int_operand_write_intro = "Int-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_Int_operand_write_intro
Returncode Int_operand_write_intro(Int_operand* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Int_operand_write_final = "Int-operand.write-final";
#define LUMI_FUNC_NAME _func_name_Int_operand_write_final
Returncode Int_operand_write_final(Int_operand* self) {
  CHECK(90, write(self->text));
  return OK;
}
#undef LUMI_FUNC_NAME
Func Int_operand__dtl[] = {Int_operand_parse, Int_operand_analyze, Int_operand_write_intro, Int_operand_write_final};


typedef struct Empty_operand Empty_operand; struct Empty_operand {
  Operand _base;
};
static char* _func_name_Empty_operand_parse = "Empty-operand.parse";
#define LUMI_FUNC_NAME _func_name_Empty_operand_parse
Returncode Empty_operand_parse(Empty_operand* self, String* text, String* ends, Char* end) {
  free(text);
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Empty_operand_analyze = "Empty-operand.analyze";
#define LUMI_FUNC_NAME _func_name_Empty_operand_analyze
Returncode Empty_operand_analyze(Empty_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  if (!(NULL != (*mtype)) || NULL != self->_base.next || (*mtype)->is_primitive) {
    CHECK(99, f_syntax_error_c(&(String){21, 20, "illegal use of value"}, '_'));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Empty_operand_write_intro = "Empty-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_Empty_operand_write_intro
Returncode Empty_operand_write_intro(Empty_operand* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Empty_operand_write_final = "Empty-operand.write-final";
#define LUMI_FUNC_NAME _func_name_Empty_operand_write_final
Returncode Empty_operand_write_final(Empty_operand* self) {
  CHECK(105, write(&(String){5, 4, "NULL"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func Empty_operand__dtl[] = {Empty_operand_parse, Empty_operand_analyze, Empty_operand_write_intro, Empty_operand_write_final};


typedef struct Block_operand Block_operand; struct Block_operand {
  Operand _base;
  Mexp* exp;
};
static char* _func_name_Block_operand_parse = "Block-operand.parse";
#define LUMI_FUNC_NAME _func_name_Block_operand_parse
Returncode Block_operand_parse(Block_operand* self, String* text, String* ends, Char* end) {
  free(text);
  CHECK(113, parse_new_exp(&(String){2, 1, ")"}, &(self->exp), &((*end))));
  if ((*end) != ')') {
    CHECK(115, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, ")"}));
  }
  CHECK(116, read_c(&((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Block_operand_analyze = "Block-operand.analyze";
#define LUMI_FUNC_NAME _func_name_Block_operand_analyze
Returncode Block_operand_analyze(Block_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  CHECK(119, Mexp_analyze(self->exp, &((*mtype)), &((*sub_mtype))));
  if (NULL != self->_base.next) {
    CHECK(121, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Block_operand_write_intro = "Block-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_Block_operand_write_intro
Returncode Block_operand_write_intro(Block_operand* self) {
  CHECK(124, Mexp_write_intro(self->exp));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Block_operand_write_final = "Block-operand.write-final";
#define LUMI_FUNC_NAME _func_name_Block_operand_write_final
Returncode Block_operand_write_final(Block_operand* self) {
  CHECK(127, write(&(String){2, 1, "("}));
  CHECK(128, Mexp_write_final(self->exp));
  CHECK(129, write(&(String){2, 1, ")"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func Block_operand__dtl[] = {Block_operand_parse, Block_operand_analyze, Block_operand_write_intro, Block_operand_write_final};

typedef struct Slice_operand Slice_operand; struct Slice_operand {
  Operand _base;
  Mexp* index;
  Mexp* second_index;
  Operand* seq;
  Mtype* seq_type;
  Mtype* item_type;
};
static char* _func_name_Slice_operand_parse = "Slice-operand.parse";
#define LUMI_FUNC_NAME _func_name_Slice_operand_parse
Returncode Slice_operand_parse(Slice_operand* self, String* text, String* ends, Char* end) {
  CHECK(139, parse_new_exp(&(String){3, 2, ":]"}, &(self->index), &((*end))));
  if ((*end) == ':') {
    CHECK(141, parse_new_exp(&(String){3, 2, ":]"}, &(self->second_index), &((*end))));
  }
  else {
    self->second_index = NULL;
  }
  if ((*end) != ']') {
    CHECK(145, f_syntax_error(&(String){8, 7, "missing"}, &(String){2, 1, "]"}));
  }
  CHECK(146, read_c(&((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Slice_operand_analyze = "Slice-operand.analyze";
#define LUMI_FUNC_NAME _func_name_Slice_operand_analyze
Returncode Slice_operand_analyze(Slice_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  self->seq_type = (*mtype);
  self->item_type = (*sub_mtype);
  if (self->seq_type != glob->type_array && self->seq_type != glob->type_string) {
    CHECK(152, f_syntax_error(&(String){19, 18, "non-sliceable type"}, self->seq_type->name));
  }
  if (!(NULL != self->second_index)) {
    (*sub_mtype) = NULL;
    if (self->seq_type == glob->type_string) {
      (*mtype) = glob->type_char;
    }
    else {
      if (NULL != self->item_type) {
        (*mtype) = self->item_type;
      }
      else {
        CHECK(160, f_syntax_error(&(String){27, 26, "missing sub-type for array"}, &(String){1, 0, ""}));
      }
    }
  }
  
  self->seq = exp->operand;
  exp->operand = &(self->_base);
  member->next = NULL;
  
  CHECK(166, Mexp_analyze_type(self->index, glob->type_int));
  if (NULL != self->second_index) {
    CHECK(168, Mexp_analyze_type(self->second_index, glob->type_int));
  }
  
  if (NULL != self->_base.next) {
    CHECK(171, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Slice_operand_write_intro = "Slice-operand.write-intro";
#define LUMI_FUNC_NAME _func_name_Slice_operand_write_intro
Returncode Slice_operand_write_intro(Slice_operand* self) {
  CHECK(174, Mexp_write_intro(self->index));
  if (NULL != self->second_index) {
    CHECK(176, Mexp_write_intro(self->second_index));
  }
  CHECK(177, Operand_write_all_intro(self->seq));
  /* if ((index) < 0 || (index) >= (seq)->length) RAISE(line-num) */
  /* if ((index) < 0 || (second) < 0 || (index) + (second) > (seq)->length) RAISE(line-num) */
  CHECK(180, write(&(String){6, 5, "if (("}));
  CHECK(181, Mexp_write_final(self->index));
  CHECK(182, write(&(String){11, 10, ") < 0 || ("}));
  if (NULL != self->second_index) {
    CHECK(184, Mexp_write_final(self->second_index));
    CHECK(185, write(&(String){11, 10, ") < 0 || ("}));
  }
  CHECK(186, Mexp_write_final(self->index));
  CHECK(187, write(&(String){3, 2, ") "}));
  if (NULL != self->second_index) {
    CHECK(189, write(&(String){4, 3, "+ ("}));
    CHECK(190, Mexp_write_final(self->second_index));
    CHECK(191, write(&(String){4, 3, ") >"}));
  }
  else {
    CHECK(193, write(&(String){3, 2, ">="}));
  }
  CHECK(194, write(&(String){3, 2, " ("}));
  CHECK(195, Operand_write_all_final(self->seq));
  CHECK(196, write(&(String){12, 11, ")->length) "}));
  CHECK(197, write_tb_raise());
  CHECK(198, write_new_indent_line());
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_Slice_operand_write_final = "Slice-operand.write-final";
#define LUMI_FUNC_NAME _func_name_Slice_operand_write_final
Returncode Slice_operand_write_final(Slice_operand* self) {
  /* ((Prmitive*)((seq)->values))[index] */
  /* &(((Complex*)((seq)->values))[index]) */
  /* &(Array){second, ((Type**)((seq)->values)) + (index)} */
  /* &(String){second, second, (seq)->values + (index)} */
  CHECK(205, write(&(String){2, 1, "("}));
  if (NULL != self->second_index) {
    CHECK(207, write(&(String){3, 2, "&("}));
    CHECK(208, write_cstyle(self->seq_type->name));
    CHECK(209, write(&(String){3, 2, "){"}));
    CHECK(210, Mexp_write_final(self->second_index));
    CHECK(211, write(&(String){3, 2, ", "}));
    if (self->seq_type == glob->type_string) {
      CHECK(213, Mexp_write_final(self->second_index));
      CHECK(214, write(&(String){3, 2, ", "}));
    }
  }
  if (NULL != self->item_type) {
    if (!self->item_type->is_primitive && !(NULL != self->second_index)) {
      CHECK(217, write(&(String){3, 2, "&("}));
    }
    CHECK(218, write(&(String){3, 2, "(("}));
    CHECK(219, write_cstyle(self->item_type->name));
    CHECK(220, write(&(String){4, 3, "*)("}));
  }
  CHECK(221, write(&(String){2, 1, "("}));
  CHECK(222, Operand_write_all_final(self->seq));
  CHECK(223, write(&(String){10, 9, ")->values"}));
  if (NULL != self->item_type) {
    CHECK(225, write(&(String){3, 2, "))"}));
  }
  if (NULL != self->second_index) {
    CHECK(227, write(&(String){5, 4, " + ("}));
    CHECK(228, Mexp_write_final(self->index));
    CHECK(229, write(&(String){3, 2, ")}"}));
  }
  else {
    CHECK(231, write(&(String){2, 1, "["}));
    CHECK(232, Mexp_write_final(self->index));
    CHECK(233, write(&(String){2, 1, "]"}));
    if (NULL != self->item_type && !self->item_type->is_primitive) {
      CHECK(235, write(&(String){2, 1, ")"}));
    }
  }
  CHECK(236, write(&(String){2, 1, ")"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func Slice_operand__dtl[] = {Slice_operand_parse, Slice_operand_analyze, Slice_operand_write_intro, Slice_operand_write_final};


static char* _func_name_parse_new_operand = "parse-new-operand";
#define LUMI_FUNC_NAME _func_name_parse_new_operand
Returncode parse_new_operand(Type opr_type, String* text, String* ends, Operand** new_opr, Char* end) {
  if (opr_type.size <= 0) RAISE(240)
  Operand* opr = malloc(opr_type.size);
  if (opr == NULL) RAISE(240)
  if (opr_type.dtl != NULL) { *((Func**)(opr)) = opr_type.dtl; }
  (*new_opr) = opr;
  CHECK(242, (*((Func**)(opr)))[0](opr, text, ends, &((*end))));
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
  CHECK(253, parse_new_operand(next_type, NULL, ends, &(opr->next), &((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_parse_new_operands = "parse-new-operands";
#define LUMI_FUNC_NAME _func_name_parse_new_operands
Returncode parse_new_operands(String* text, String* ends, Operand** new_opr, Char* end) {
  Type opr_type = {sizeof(Operand), Operand__dtl};
  if (text->length == 0) {
    if ((*end) == '(') {
      opr_type = (Type){sizeof(Block_operand), Block_operand__dtl};
    }
    else {
      CHECK(261, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)));
    }
  }
  else {
    if ((0) < 0 || (0) >= text->length) RAISE(263)
    Char first = text->chars[0];
    Char second = '\0';
    if (text->length > 1) {
      if ((1) < 0 || (1) >= text->length) RAISE(266)
      second = text->chars[1];
    }
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
          if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
            opr_type = (Type){sizeof(Type_operand), Type_operand__dtl};
          }
          else {
            if (text->length == 1 && first == '_') {
              opr_type = (Type){sizeof(Empty_operand), Empty_operand__dtl};
            }
            else {
              Bool _Bool0;
              CHECK(277, String_equal(text, &(String){5, 4, "base"}, &(_Bool0)))
              if (_Bool0) {
                opr_type = (Type){sizeof(Base_meth_operand), Base_meth_operand__dtl};
              }
              else {
                opr_type = (Type){sizeof(Var_operand), Var_operand__dtl};
              }
            }
          }
        }
      }
    }
  }
  CHECK(281, parse_new_operand(opr_type, text, ends, &((*new_opr)), &((*end))));
  return OK;
}
#undef LUMI_FUNC_NAME

#undef LUMI_FILE_NAME
