static char* _mr_file7_name = "dec.2.mr";
#define MR_FILE_NAME _mr_file7_name
/* MR3 compiler - variable declerations */

typedef struct St_dec St_dec; struct St_dec {
  St _base;
  Mvar* mvar;
  Mexp* value;
};
Returncode St_dec_parse_array(St_dec* self);
Returncode St_dec_parse_string(St_dec* self);
static char* _func_name_St_dec_parse = "St-dec.parse";
#define MR_FUNC_NAME _func_name_St_dec_parse
Returncode St_dec_parse(St_dec* self) {
  CHECK(11, init_new_var(NULL, &(self->mvar)));
  self->value = NULL;
  Char _Char0;
  CHECK(13, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &(_Char0)))
  if (_Char0 == '{') {
    Bool _Bool1;
    CHECK(14, String_equal(self->mvar->typename, &(String){6, 5, "Array"}, &(_Bool1)))
    if (_Bool1) {
      CHECK(15, (*((Func**)(self)))[4](self));
      Char _Char2;
      CHECK(16, read_new(&(String){3, 2, "{}"}, &(self->mvar->sub_typename), &(_Char2)))
      if (_Char2 == '{') {
        CHECK(17, (*((Func**)(self)))[5](self));
        Char _Char3;
        CHECK(18, read_c(&(_Char3)));
      }
    }
    else {
      Bool _Bool4;
      CHECK(19, String_equal(self->mvar->typename, &(String){7, 6, "String"}, &(_Bool4)))
      if (_Bool4) {
        CHECK(20, (*((Func**)(self)))[5](self));
      }
      else {
        Char _Char5;
        CHECK(22, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &(_Char5)));
      }
    }
    Char _Char6;
    CHECK(23, read_c(&(_Char6)));
  }
  Char _Char7;
  CHECK(24, read_new(&(String){2, 1, "("}, &(self->mvar->name), &(_Char7)))
  if (_Char7 == '(') {
    Char _Char8;
    CHECK(25, parse_new_exp(&(String){2, 1, ")"}, &(self->value), &(_Char8)));
    Char _Char9;
    CHECK(26, read_c(&(_Char9)));
  }
  CHECK(27, St_add_var(&(self->_base), self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze_first = "St-dec.analyze-first";
#define MR_FUNC_NAME _func_name_St_dec_analyze_first
Returncode St_dec_analyze_first(St_dec* self) {
  CHECK(30, Mvar_analyze(self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze = "St-dec.analyze";
#define MR_FUNC_NAME _func_name_St_dec_analyze
Returncode St_dec_analyze(St_dec* self) {
  if (NULL != self->value) {
    CHECK(34, Mexp_analyze(self->value));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write = "St-dec.write";
#define MR_FUNC_NAME _func_name_St_dec_write
Returncode St_dec_write(St_dec* self) {
  if (NULL != glob->mclass && glob->methods) {
    return OK;
  }
  if (NULL != self->value) {
    CHECK(40, Mexp_write_intro(self->value));
  }
  CHECK(41, write_cstyle(self->mvar->typename));
  if (!self->mvar->mtype->is_primitive) {
    CHECK(43, write(&(String){2, 1, "*"}));
  }
  CHECK(44, write(&(String){2, 1, " "}));
  CHECK(45, write_cstyle(self->mvar->name));
  Bool _Bool10;
  CHECK(46, (*((Func**)(self)))[6](self, &(_Bool10)))
  if (_Bool10) {
    CHECK(47, write(&(String){4, 3, " = "}));
    if (self->mvar->mtype == glob->type_string) {
      CHECK(49, (*((Func**)(self)))[9](self));
    }
    else {
      if (self->mvar->mtype == glob->type_array) {
        if (!(NULL != self->mvar->sub_typename)) {
          CHECK(52, f_syntax_error(&(String){22, 21, "Array type missing in"}, self->mvar->name));
        }
        CHECK(53, (*((Func**)(self)))[10](self));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          CHECK(55, (*((Func**)(self)))[7](self));
        }
        else {
          CHECK(57, (*((Func**)(self)))[8](self));
        }
      }
    }
  }
  else {
    if (NULL != self->value) {
      CHECK(59, write(&(String){4, 3, " = "}));
      CHECK(60, Mexp_write_final(self->value));
    }
  }
  CHECK(61, write(&(String){2, 1, ";"}));
  if (NULL != glob->mclass) {
    CHECK(63, write(&(String){2, 1, "\n"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_parse_array = "St-dec.parse-array";
#define MR_FUNC_NAME _func_name_St_dec_parse_array
Returncode St_dec_parse_array(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_parse_string = "St-dec.parse-string";
#define MR_FUNC_NAME _func_name_St_dec_parse_string
Returncode St_dec_parse_string(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_m_is_allocation = "St-dec.m-is-allocation";
#define MR_FUNC_NAME _func_name_St_dec_m_is_allocation
Returncode St_dec_m_is_allocation(St_dec* self, Bool* is_aloc) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_primitive = "St-dec.write-primitive";
#define MR_FUNC_NAME _func_name_St_dec_write_primitive
Returncode St_dec_write_primitive(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_class = "St-dec.write-class";
#define MR_FUNC_NAME _func_name_St_dec_write_class
Returncode St_dec_write_class(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_string = "St-dec.write-string";
#define MR_FUNC_NAME _func_name_St_dec_write_string
Returncode St_dec_write_string(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_array = "St-dec.write-array";
#define MR_FUNC_NAME _func_name_St_dec_write_array
Returncode St_dec_write_array(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func St_dec__dtl[] = {St_dec_parse, St_dec_analyze_first, St_dec_analyze, St_dec_write, St_dec_parse_array, St_dec_parse_string, St_dec_m_is_allocation, St_dec_write_primitive, St_dec_write_class, St_dec_write_string, St_dec_write_array};


typedef struct St_var St_var; struct St_var {
  St_dec _base;
  String* arr_length;
  String* str_length;
};
static char* _func_name_St_var_parse = "St-var.parse";
#define MR_FUNC_NAME _func_name_St_var_parse
Returncode St_var_parse(St_var* self) {
  self->arr_length = NULL;
  self->str_length = NULL;
  CHECK(94, St_dec_parse(&(self->_base)));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze_first = "St-var.analyze-first";
#define MR_FUNC_NAME _func_name_St_var_analyze_first
Returncode St_var_analyze_first(St_var* self) {
  CHECK(97, St_dec_analyze_first(&(self->_base)));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze = "St-var.analyze";
#define MR_FUNC_NAME _func_name_St_var_analyze
Returncode St_var_analyze(St_var* self) {
  CHECK(100, St_dec_analyze(&(self->_base)));
  /* f-syntax-error(user "cannot initialize variable of type", user self.mvar.typename) */
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write = "St-var.write";
#define MR_FUNC_NAME _func_name_St_var_write
Returncode St_var_write(St_var* self) {
  CHECK(104, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_array = "St-var.parse-array";
#define MR_FUNC_NAME _func_name_St_var_parse_array
Returncode St_var_parse_array(St_var* self) {
  Char _Char11;
  CHECK(107, read_new(&(String){2, 1, ":"}, &(self->arr_length), &(_Char11)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_string = "St-var.parse-string";
#define MR_FUNC_NAME _func_name_St_var_parse_string
Returncode St_var_parse_string(St_var* self) {
  Char _Char12;
  CHECK(110, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char12)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_m_is_allocation = "St-var.m-is-allocation";
#define MR_FUNC_NAME _func_name_St_var_m_is_allocation
Returncode St_var_m_is_allocation(St_var* self, Bool* is_aloc) {
  (*is_aloc) = !self->_base.mvar->mtype->is_primitive;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_primitive = "St-var.write-primitive";
#define MR_FUNC_NAME _func_name_St_var_write_primitive
Returncode St_var_write_primitive(St_var* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_class = "St-var.write-class";
#define MR_FUNC_NAME _func_name_St_var_write_class
Returncode St_var_write_class(St_var* self) {
  /* Class* name = &(Class){0}; */
  CHECK(120, write(&(String){3, 2, "&("}));
  CHECK(121, write_cstyle(self->_base.mvar->typename));
  CHECK(122, write(&(String){6, 5, "){0};"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_string = "St-var.write-string";
#define MR_FUNC_NAME _func_name_St_var_write_string
Returncode St_var_write_string(St_var* self) {
  /* String* name = &(String){length, 0, (char[length]){0}}; */
  /* CHECK(line-num, String_copy(name, init)); */
  if (!(NULL != self->str_length)) {
    CHECK(128, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(129, write(&(String){11, 10, "&(String){"}));
  CHECK(130, write(self->str_length));
  CHECK(131, write(&(String){12, 11, ", 0, (char["}));
  CHECK(132, write(self->str_length));
  CHECK(133, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->_base.value) {
    CHECK(135, write_new_indent_line());
    CHECK(136, write_tb_check());
    CHECK(137, write(&(String){13, 12, "String_copy("}));
    CHECK(138, write_cstyle(self->_base.mvar->name));
    CHECK(139, write(&(String){3, 2, ", "}));
    CHECK(140, Mexp_write_final(self->_base.value));
    CHECK(141, write(&(String){3, 2, "))"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_array = "St-var.write-array";
#define MR_FUNC_NAME _func_name_St_var_write_array
Returncode St_var_write_array(St_var* self) {
  /* Array* name = &(Array){length, (Class[length]){0}}; */
  /* Array* name = &(Array){length, (String[length]){0}}; */
  /* char _name_chars[string-length][length]; */
  /* _set_var_string_array(length, string-length, name, _name_chars); */
  if (!(NULL != self->arr_length)) {
    CHECK(149, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(150, write(&(String){10, 9, "&(Array){"}));
  CHECK(151, write(self->arr_length));
  CHECK(152, write(&(String){4, 3, ", ("}));
  CHECK(153, write_cstyle(self->_base.mvar->sub_typename));
  CHECK(154, write(&(String){2, 1, "["}));
  CHECK(155, write(self->arr_length));
  CHECK(156, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->str_length) {
    CHECK(158, write_new_indent_line());
    CHECK(159, write(&(String){7, 6, "char _"}));
    CHECK(160, write_cstyle(self->_base.mvar->name));
    CHECK(161, write(&(String){8, 7, "_chars["}));
    CHECK(162, write(self->str_length));
    CHECK(163, write(&(String){3, 2, "]["}));
    CHECK(164, write(self->arr_length));
    CHECK(165, write(&(String){4, 3, "];\n"}));
    CHECK(166, write_spaces());
    CHECK(167, write(&(String){23, 22, "_set_var_string_array("}));
    CHECK(168, write(self->arr_length));
    CHECK(169, write(&(String){3, 2, ", "}));
    CHECK(170, write(self->str_length));
    CHECK(171, write(&(String){3, 2, ", "}));
    CHECK(172, write_cstyle(self->_base.mvar->name));
    CHECK(173, write(&(String){4, 3, ", _"}));
    CHECK(174, write_cstyle(self->_base.mvar->name));
    CHECK(175, write(&(String){9, 8, "_chars);"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_var__dtl[] = {St_var_parse, St_var_analyze_first, St_var_analyze, St_var_write, St_var_parse_array, St_var_parse_string, St_var_m_is_allocation, St_var_write_primitive, St_var_write_class, St_var_write_string, St_var_write_array};


typedef struct St_ref St_ref; struct St_ref {
  St_dec _base;
};
static char* _func_name_St_ref_parse = "St-ref.parse";
#define MR_FUNC_NAME _func_name_St_ref_parse
Returncode St_ref_parse(St_ref* self) {
  CHECK(180, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_USER;
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze_first = "St-ref.analyze-first";
#define MR_FUNC_NAME _func_name_St_ref_analyze_first
Returncode St_ref_analyze_first(St_ref* self) {
  CHECK(184, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze = "St-ref.analyze";
#define MR_FUNC_NAME _func_name_St_ref_analyze
Returncode St_ref_analyze(St_ref* self) {
  CHECK(187, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write = "St-ref.write";
#define MR_FUNC_NAME _func_name_St_ref_write
Returncode St_ref_write(St_ref* self) {
  CHECK(190, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_array = "St-ref.parse-array";
#define MR_FUNC_NAME _func_name_St_ref_parse_array
Returncode St_ref_parse_array(St_ref* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_string = "St-ref.parse-string";
#define MR_FUNC_NAME _func_name_St_ref_parse_string
Returncode St_ref_parse_string(St_ref* self) {
  CHECK(196, f_syntax_error(&(String){31, 30, "unexpected parameter to String"}, &(String){1, 0, ""}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_m_is_allocation = "St-ref.m-is-allocation";
#define MR_FUNC_NAME _func_name_St_ref_m_is_allocation
Returncode St_ref_m_is_allocation(St_ref* self, Bool* is_aloc) {
  (*is_aloc) = false;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_primitive = "St-ref.write-primitive";
#define MR_FUNC_NAME _func_name_St_ref_write_primitive
Returncode St_ref_write_primitive(St_ref* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_class = "St-ref.write-class";
#define MR_FUNC_NAME _func_name_St_ref_write_class
Returncode St_ref_write_class(St_ref* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_string = "St-ref.write-string";
#define MR_FUNC_NAME _func_name_St_ref_write_string
Returncode St_ref_write_string(St_ref* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_array = "St-ref.write-array";
#define MR_FUNC_NAME _func_name_St_ref_write_array
Returncode St_ref_write_array(St_ref* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func St_ref__dtl[] = {St_ref_parse, St_ref_analyze_first, St_ref_analyze, St_ref_write, St_ref_parse_array, St_ref_parse_string, St_ref_m_is_allocation, St_ref_write_primitive, St_ref_write_class, St_ref_write_string, St_ref_write_array};


typedef struct St_new St_new; struct St_new {
  St_var _base;
  Mexp* arr_length;
  Mexp* str_length;
};
static char* _func_name_St_new_parse = "St-new.parse";
#define MR_FUNC_NAME _func_name_St_new_parse
Returncode St_new_parse(St_new* self) {
  CHECK(219, St_var_parse(&(self->_base)));
  self->_base._base.mvar->access = ACCESS_OWNER;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze_first = "St-new.analyze-first";
#define MR_FUNC_NAME _func_name_St_new_analyze_first
Returncode St_new_analyze_first(St_new* self) {
  CHECK(223, St_var_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze = "St-new.analyze";
#define MR_FUNC_NAME _func_name_St_new_analyze
Returncode St_new_analyze(St_new* self) {
  if (NULL != self->_base._base.value) {
    CHECK(227, f_syntax_error(&(String){21, 20, "cannot initialize in"}, &(String){4, 3, "new"}));
  }
  if (NULL != self->str_length) {
    CHECK(229, Mexp_analyze(self->str_length));
  }
  if (NULL != self->arr_length) {
    CHECK(231, Mexp_analyze(self->arr_length));
  }
  CHECK(232, St_var_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write = "St-new.write";
#define MR_FUNC_NAME _func_name_St_new_write
Returncode St_new_write(St_new* self) {
  CHECK(235, St_var_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_array = "St-new.parse-array";
#define MR_FUNC_NAME _func_name_St_new_parse_array
Returncode St_new_parse_array(St_new* self) {
  Char _Char13;
  CHECK(238, parse_new_exp(&(String){2, 1, ":"}, &(self->arr_length), &(_Char13)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_string = "St-new.parse-string";
#define MR_FUNC_NAME _func_name_St_new_parse_string
Returncode St_new_parse_string(St_new* self) {
  Char _Char14;
  CHECK(241, parse_new_exp(&(String){2, 1, "}"}, &(self->str_length), &(_Char14)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_m_is_allocation = "St-new.m-is-allocation";
#define MR_FUNC_NAME _func_name_St_new_m_is_allocation
Returncode St_new_m_is_allocation(St_new* self, Bool* is_aloc) {
  (*is_aloc) = true;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_check = "St-new.write-check";
#define MR_FUNC_NAME _func_name_St_new_write_check
Returncode St_new_write_check(St_new* self) {
  /* if (name == NULL) RAISE(line-num) */
  CHECK(248, write_new_indent_line());
  CHECK(249, write(&(String){5, 4, "if ("}));
  CHECK(250, write_cstyle(self->_base._base.mvar->name));
  CHECK(251, write(&(String){11, 10, " == NULL) "}));
  CHECK(252, write_tb_raise());
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_primitive = "St-new.write-primitive";
#define MR_FUNC_NAME _func_name_St_new_write_primitive
Returncode St_new_write_primitive(St_new* self) {
  CHECK(255, f_syntax_error(&(String){33, 32, "new not supported for primitive "}, self->_base._base.mvar->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_class = "St-new.write-class";
#define MR_FUNC_NAME _func_name_St_new_write_class
Returncode St_new_write_class(St_new* self) {
  /* Class* name = malloc(sizeof(Class)); */
  CHECK(259, write(&(String){15, 14, "malloc(sizeof("}));
  CHECK(260, write_cstyle(self->_base._base.mvar->typename));
  CHECK(261, write(&(String){4, 3, "));"}));
  CHECK(262, St_new_write_check(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_string = "St-new.write-string";
#define MR_FUNC_NAME _func_name_St_new_write_string
Returncode St_new_write_string(St_new* self) {
  /* String* name = new_string(length); */
  if (!(NULL != self->str_length)) {
    CHECK(267, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base._base.mvar->name));
  }
  CHECK(268, Mexp_write_intro(self->str_length));
  CHECK(269, write(&(String){13, 12, "_new_string("}));
  CHECK(270, Mexp_write_final(self->str_length));
  CHECK(271, write(&(String){3, 2, ");"}));
  CHECK(272, St_new_write_check(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_array = "St-new.write-array";
#define MR_FUNC_NAME _func_name_St_new_write_array
Returncode St_new_write_array(St_new* self) {
  /* Array* name = new_array(length, sizeof(Class)); */
  /* Array* name = new_array(length, sizeof(String) + (string-length)); */
  /* _set_new_string_array(length, string-length, name); */
  if (!(NULL != self->arr_length)) {
    CHECK(279, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base._base.mvar->name));
  }
  CHECK(280, Mexp_write_intro(self->arr_length));
  if (NULL != self->str_length) {
    CHECK(282, Mexp_write_intro(self->str_length));
  }
  CHECK(283, write(&(String){12, 11, "_new_array("}));
  CHECK(284, Mexp_write_final(self->arr_length));
  CHECK(285, write(&(String){10, 9, ", sizeof("}));
  CHECK(286, write_cstyle(self->_base._base.mvar->sub_typename));
  if (NULL != self->str_length) {
    CHECK(288, write(&(String){6, 5, ") + ("}));
    CHECK(289, Mexp_write_final(self->str_length));
  }
  CHECK(290, write(&(String){4, 3, "));"}));
  CHECK(291, St_new_write_check(self));
  if (NULL != self->str_length) {
    CHECK(293, write_new_indent_line());
    CHECK(294, write(&(String){23, 22, "_set_new_string_array("}));
    CHECK(295, Mexp_write_final(self->arr_length));
    CHECK(296, write(&(String){3, 2, ", "}));
    CHECK(297, Mexp_write_final(self->str_length));
    CHECK(298, write(&(String){3, 2, ", "}));
    CHECK(299, write_cstyle(self->_base._base.mvar->name));
    CHECK(300, write(&(String){3, 2, ");"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_new__dtl[] = {St_new_parse, St_new_analyze_first, St_new_analyze, St_new_write, St_new_parse_array, St_new_parse_string, St_new_m_is_allocation, St_new_write_primitive, St_new_write_class, St_new_write_string, St_new_write_array};


typedef struct St_delete St_delete; struct St_delete {
  St_comment _base;
};
static char* _func_name_St_delete_parse = "St-delete.parse";
#define MR_FUNC_NAME _func_name_St_delete_parse
Returncode St_delete_parse(St_delete* self) {
  CHECK(305, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_analyze_first = "St-delete.analyze-first";
#define MR_FUNC_NAME _func_name_St_delete_analyze_first
Returncode St_delete_analyze_first(St_delete* self) {
  CHECK(307, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_analyze = "St-delete.analyze";
#define MR_FUNC_NAME _func_name_St_delete_analyze
Returncode St_delete_analyze(St_delete* self) {
  CHECK(309, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_write = "St-delete.write";
#define MR_FUNC_NAME _func_name_St_delete_write
Returncode St_delete_write(St_delete* self) {
  CHECK(311, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_delete__dtl[] = {St_delete_parse, St_delete_analyze_first, St_delete_analyze, St_delete_write};

#undef MR_FILE_NAME
