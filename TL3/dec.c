static char* _lumi_file12_name = "dec.2.lm";
#define LUMI_FILE_NAME _lumi_file12_name
/* TL3 compiler - variable declerations */

typedef struct St_dec St_dec; struct St_dec {
  St _base;
  Mvar* mvar;
  Mexp* value;
  Bool is_in;
  String* temp_name;
  Int base_count;
};
static char* _func_name_St_dec_parse = "St-dec.parse";
#define LUMI_FUNC_NAME _func_name_St_dec_parse
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
        Bool _Bool5;
        CHECK(21, String_equal(self->mvar->typename, &(String){3, 2, "As"}, &(_Bool5)))
        if (_Bool5) {
          CHECK(22, (*((Func**)(self)))[6](self));
        }
        else {
          Char _Char6;
          CHECK(24, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &(_Char6)));
        }
      }
    }
    Char _Char7;
    CHECK(25, read_c(&(_Char7)));
  }
  Char end;
  CHECK(27, read_new(&(String){3, 2, " ("}, &(self->mvar->name), &(end)))
  if (end == '(') {
    Char _Char8;
    CHECK(28, parse_new_exp(&(String){2, 1, ")"}, &(self->value), &(_Char8)));
    Char _Char9;
    CHECK(29, read_c(&(_Char9)));
  }
  self->is_in = end == ' ';
  self->temp_name = NULL;
  self->base_count = 0;
  if (self->is_in) {
    Bool _Bool10;
    CHECK(34, String_equal(self->mvar->name, &(String){3, 2, "in"}, &(_Bool10)))
    if (!_Bool10) {
      CHECK(35, f_syntax_error(&(String){19, 18, "expected 'in', got"}, self->mvar->name));
    }
    Char _Char11;
    CHECK(36, parse_new_exp(&(String){1, 0, ""}, &(self->value), &(_Char11)));
  }
  else {
    CHECK(38, St_add_var(&(self->_base), self->mvar));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_analyze_first = "St-dec.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_dec_analyze_first
Returncode St_dec_analyze_first(St_dec* self) {
  CHECK(41, Mvar_analyze(self->mvar));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_analyze = "St-dec.analyze";
#define LUMI_FUNC_NAME _func_name_St_dec_analyze
Returncode St_dec_analyze(St_dec* self) {
  if (NULL != self->value) {
    if (self->is_in) {
      Mtype* mtype = NULL;
      Mtype* sub_mtype = self->mvar->sub_mtype;
      CHECK(48, Mexp_analyze(self->value, &(mtype), &(sub_mtype)));
      Mtype* new_mtype = self->mvar->mtype;
      if (!(NULL != mtype)) {
        CHECK(51, f_syntax_error(&(String){27, 26, "illegal varibale to assign"}, &(String){4, 3, "new"}));
      }
      while (true) {
        if (!(new_mtype != mtype)) break;
        new_mtype = new_mtype->base_mtype;
        if (!(NULL != new_mtype)) {
          CHECK(56, f_syntax_error2(&(String){14, 13, "cannot assign"}, self->mvar->mtype->name, &(String){3, 2, "in"}, mtype->name));
        }
        self->base_count = self->base_count + 1;
      }
      if (self->base_count > 0) {
        CHECK(59, f_new_temp_name(self->mvar->mtype, &(self->temp_name)));
      }
    }
    else {
      CHECK(61, Mexp_analyze_types(self->value, self->mvar->mtype, self->mvar->sub_mtype));
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_m_is_global = "St-dec.m-is-global";
#define LUMI_FUNC_NAME _func_name_St_dec_m_is_global
Returncode St_dec_m_is_global(St_dec* self, Bool* is_global) {
  (*is_global) = !(NULL != self->_base.father->father->father);
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_name = "St-dec.write-name";
#define LUMI_FUNC_NAME _func_name_St_dec_write_name
Returncode St_dec_write_name(St_dec* self) {
  if (NULL != self->temp_name) {
    CHECK(68, write_cstyle(self->temp_name));
  }
  else {
    if (self->is_in) {
      CHECK(70, Mexp_write_final(self->value));
    }
    else {
      CHECK(72, write_cstyle(self->mvar->name));
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_dec = "St-dec.write-dec";
#define LUMI_FUNC_NAME _func_name_St_dec_write_dec
Returncode St_dec_write_dec(St_dec* self) {
  if (!self->is_in || NULL != self->temp_name) {
    CHECK(76, write_cstyle(self->mvar->mtype->name));
    if (!self->mvar->mtype->is_primitive) {
      CHECK(78, write(&(String){2, 1, "*"}));
    }
    CHECK(79, write(&(String){2, 1, " "}));
  }
  CHECK(80, St_dec_write_name(self));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_to_dtl = "St-dec.write-to-dtl";
#define LUMI_FUNC_NAME _func_name_St_dec_write_to_dtl
Returncode St_dec_write_to_dtl(St_dec* self) {
  /* name->[_base.]_dtl =  */
  CHECK(84, write_new_indent_line());
  CHECK(85, St_dec_write_name(self));
  CHECK(86, write(&(String){3, 2, "->"}));
  Mtype* basetype = self->mvar->mtype->base_mtype;
  while (true) {
    if (!(NULL != basetype)) break;
    CHECK(90, write(&(String){7, 6, "_base."}));
    basetype = basetype->base_mtype;
  }
  CHECK(92, write(&(String){8, 7, "_dtl = "}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_struct_init = "St-dec.write-struct-init";
#define LUMI_FUNC_NAME _func_name_St_dec_write_struct_init
Returncode St_dec_write_struct_init(St_dec* self) {
  /* (Type){init-values...}; */
  CHECK(96, write(&(String){2, 1, "("}));
  CHECK(97, write_cstyle(self->mvar->mtype->name));
  CHECK(98, write(&(String){3, 2, "){"}));
  Bool is_dynmaic = NULL != self->mvar->mtype->dynamic_members;
  if (is_dynmaic) {
    CHECK(101, write_cstyle(self->mvar->mtype->name));
    CHECK(102, write(&(String){6, 5, "__dtl"}));
  }
  CHECK(103, write_type_init(self->mvar->mtype, self->mvar->sub_mtype, !is_dynmaic));
  CHECK(104, write(&(String){3, 2, "};"}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write = "St-dec.write";
#define LUMI_FUNC_NAME _func_name_St_dec_write
Returncode St_dec_write(St_dec* self) {
  if (NULL != glob->mclass) {
    if (glob->methods) {
      return OK;
    }
    CHECK(110, write_spaces());
  }
  else {
    Bool _Bool12;
    CHECK(111, St_dec_m_is_global(self, &(_Bool12)))
    if (_Bool12) {
      CHECK(112, write(&(String){37, 36, "#if LUMI_STAGE == LUMI_DECLARATIONS\n"}));
      CHECK(113, write_spaces());
      CHECK(114, write(&(String){8, 7, "extern "}));
      CHECK(115, St_dec_write_dec(self));
      CHECK(116, write(&(String){3, 2, ";\n"}));
      CHECK(117, write_spaces());
      CHECK(118, write(&(String){36, 35, "#elif LUMI_STAGE == LUMI_FUNCTIONS\n"}));
      CHECK(119, write_spaces());
    }
  }
  if (NULL != self->value) {
    CHECK(121, Mexp_write_intro(self->value));
  }
  CHECK(122, St_dec_write_dec(self));
  Bool _Bool13;
  CHECK(123, (*((Func**)(self)))[7](self, &(_Bool13)))
  if (_Bool13) {
    CHECK(124, write(&(String){4, 3, " = "}));
    if (self->mvar->mtype == glob->type_string) {
      CHECK(126, (*((Func**)(self)))[10](self));
    }
    else {
      if (self->mvar->mtype == glob->type_array) {
        if (!(NULL != self->mvar->sub_typename)) {
          CHECK(129, f_syntax_error(&(String){22, 21, "Array type missing in"}, self->mvar->name));
        }
        CHECK(130, (*((Func**)(self)))[11](self));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          CHECK(132, (*((Func**)(self)))[8](self));
        }
        else {
          Bool _Bool14;
          CHECK(133, (*((Func**)(self)))[12](self, &(_Bool14)))
          if (!_Bool14) {
            CHECK(134, (*((Func**)(self)))[9](self));
            if (NULL != self->mvar->mtype->dynamic_members) {
              CHECK(136, St_dec_write_to_dtl(self));
              CHECK(137, write_cstyle(self->mvar->mtype->name));
              CHECK(138, write(&(String){7, 6, "__dtl;"}));
            }
          }
        }
      }
    }
    if (NULL != self->temp_name) {
      CHECK(140, write_new_indent_line());
      CHECK(141, Mexp_write_final(self->value));
      CHECK(142, write(&(String){6, 5, " = &("}));
      CHECK(143, St_dec_write_name(self));
      CHECK(144, write(&(String){8, 7, "->_base"}));
      Int i; for (i = 0; i < self->base_count - 1; ++i) {
        CHECK(146, write(&(String){7, 6, "._base"}));
      }
      CHECK(147, write(&(String){3, 2, ");"}));
    }
  }
  else {
    if (!(NULL != glob->mclass)) {
      CHECK(150, write(&(String){4, 3, " = "}));
      if (NULL != self->value) {
        CHECK(152, Mexp_write_final(self->value));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          if (self->mvar->mtype == glob->type_type) {
            CHECK(155, write(&(String){8, 7, "(Type){"}));
            CHECK(156, write_type_type_params(self->mvar->sub_mtype));
            CHECK(157, write(&(String){2, 1, "}"}));
          }
          else {
            CHECK(159, write_type_init(self->mvar->mtype, self->mvar->sub_mtype, true));
          }
        }
        else {
          CHECK(161, write(&(String){5, 4, "NULL"}));
        }
      }
    }
    CHECK(162, write(&(String){2, 1, ";"}));
  }
  if (NULL != glob->mclass) {
    CHECK(164, write(&(String){2, 1, "\n"}));
  }
  else {
    Bool _Bool15;
    CHECK(165, St_dec_m_is_global(self, &(_Bool15)))
    if (_Bool15) {
      CHECK(166, write_new_indent_line());
      CHECK(167, write(&(String){7, 6, "#endif"}));
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_parse_array = "St-dec.parse-array";
#define LUMI_FUNC_NAME _func_name_St_dec_parse_array
Returncode St_dec_parse_array(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_parse_string = "St-dec.parse-string";
#define LUMI_FUNC_NAME _func_name_St_dec_parse_string
Returncode St_dec_parse_string(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_parse_as = "St-dec.parse-as";
#define LUMI_FUNC_NAME _func_name_St_dec_parse_as
Returncode St_dec_parse_as(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_m_is_allocation = "St-dec.m-is-allocation";
#define LUMI_FUNC_NAME _func_name_St_dec_m_is_allocation
Returncode St_dec_m_is_allocation(St_dec* self, Bool* is_aloc) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_primitive = "St-dec.write-primitive";
#define LUMI_FUNC_NAME _func_name_St_dec_write_primitive
Returncode St_dec_write_primitive(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_class = "St-dec.write-class";
#define LUMI_FUNC_NAME _func_name_St_dec_write_class
Returncode St_dec_write_class(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_string = "St-dec.write-string";
#define LUMI_FUNC_NAME _func_name_St_dec_write_string
Returncode St_dec_write_string(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_array = "St-dec.write-array";
#define LUMI_FUNC_NAME _func_name_St_dec_write_array
Returncode St_dec_write_array(St_dec* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dec_write_as = "St-dec.write-as";
#define LUMI_FUNC_NAME _func_name_St_dec_write_as
Returncode St_dec_write_as(St_dec* self, Bool* is_as) {
  (*is_as) = false;
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_dec__dtl[] = {St_dec_parse, St_dec_analyze_first, St_dec_analyze, St_dec_write, St_dec_parse_array, St_dec_parse_string, St_dec_parse_as, St_dec_m_is_allocation, St_dec_write_primitive, St_dec_write_class, St_dec_write_string, St_dec_write_array, St_dec_write_as};


typedef struct St_var St_var; struct St_var {
  St_dec _base;
  String* arr_length;
  String* str_length;
};
static char* _func_name_St_var_parse = "St-var.parse";
#define LUMI_FUNC_NAME _func_name_St_var_parse
Returncode St_var_parse(St_var* self) {
  self->arr_length = NULL;
  self->str_length = NULL;
  CHECK(204, St_dec_parse(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_analyze_first = "St-var.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_var_analyze_first
Returncode St_var_analyze_first(St_var* self) {
  CHECK(207, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_analyze = "St-var.analyze";
#define LUMI_FUNC_NAME _func_name_St_var_analyze
Returncode St_var_analyze(St_var* self) {
  CHECK(210, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write = "St-var.write";
#define LUMI_FUNC_NAME _func_name_St_var_write
Returncode St_var_write(St_var* self) {
  CHECK(213, St_dec_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_parse_array = "St-var.parse-array";
#define LUMI_FUNC_NAME _func_name_St_var_parse_array
Returncode St_var_parse_array(St_var* self) {
  Char _Char16;
  CHECK(216, read_new(&(String){2, 1, ":"}, &(self->arr_length), &(_Char16)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_parse_string = "St-var.parse-string";
#define LUMI_FUNC_NAME _func_name_St_var_parse_string
Returncode St_var_parse_string(St_var* self) {
  Char _Char17;
  CHECK(219, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char17)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_parse_as = "St-var.parse-as";
#define LUMI_FUNC_NAME _func_name_St_var_parse_as
Returncode St_var_parse_as(St_var* self) {
  CHECK(222, f_syntax_error(&(String){22, 21, "illegal variable type"}, &(String){3, 2, "As"}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_m_is_allocation = "St-var.m-is-allocation";
#define LUMI_FUNC_NAME _func_name_St_var_m_is_allocation
Returncode St_var_m_is_allocation(St_var* self, Bool* is_aloc) {
  (*is_aloc) = !self->_base.mvar->mtype->is_primitive;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write_primitive = "St-var.write-primitive";
#define LUMI_FUNC_NAME _func_name_St_var_write_primitive
Returncode St_var_write_primitive(St_var* self) {
  RAISE(228)
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write_class = "St-var.write-class";
#define LUMI_FUNC_NAME _func_name_St_var_write_class
Returncode St_var_write_class(St_var* self) {
  CHECK(231, write(&(String){2, 1, "&"}));
  CHECK(232, St_dec_write_struct_init(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write_string = "St-var.write-string";
#define LUMI_FUNC_NAME _func_name_St_var_write_string
Returncode St_var_write_string(St_var* self) {
  /* String* name = &(String){length, 0, (char[length]){0}}; */
  /* CHECK(line-num, String_copy(name, init)); */
  if (!(NULL != self->str_length)) {
    CHECK(238, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(239, write(&(String){11, 10, "&(String){"}));
  CHECK(240, write(self->str_length));
  CHECK(241, write(&(String){12, 11, ", 0, (char["}));
  CHECK(242, write(self->str_length));
  CHECK(243, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->_base.value) {
    CHECK(245, write_new_indent_line());
    CHECK(246, write_tb_check());
    CHECK(247, write(&(String){13, 12, "String_copy("}));
    CHECK(248, write_cstyle(self->_base.mvar->name));
    CHECK(249, write(&(String){3, 2, ", "}));
    CHECK(250, Mexp_write_final(self->_base.value));
    CHECK(251, write(&(String){3, 2, "))"}));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write_array = "St-var.write-array";
#define LUMI_FUNC_NAME _func_name_St_var_write_array
Returncode St_var_write_array(St_var* self) {
  /* Array* name = &(Array){length, (Class[length]){0}}; */
  /* Array* name = &(Array){length, (String[length]){0}}; */
  /* _set_var_string_array(length, string-length, name, (char[string-length * length]){0}); */
  if (!(NULL != self->arr_length)) {
    CHECK(258, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(259, write(&(String){10, 9, "&(Array){"}));
  CHECK(260, write(self->arr_length));
  CHECK(261, write(&(String){4, 3, ", ("}));
  CHECK(262, write_cstyle(self->_base.mvar->sub_typename));
  CHECK(263, write(&(String){2, 1, "["}));
  CHECK(264, write(self->arr_length));
  CHECK(265, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->str_length) {
    CHECK(267, write_new_indent_line());
    CHECK(268, write(&(String){23, 22, "_set_var_string_array("}));
    CHECK(269, write(self->arr_length));
    CHECK(270, write(&(String){3, 2, ", "}));
    CHECK(271, write(self->str_length));
    CHECK(272, write(&(String){3, 2, ", "}));
    CHECK(273, write_cstyle(self->_base.mvar->name));
    CHECK(274, write(&(String){9, 8, ", (char["}));
    CHECK(275, write(self->str_length));
    CHECK(276, write(&(String){4, 3, " * "}));
    CHECK(277, write(self->arr_length));
    CHECK(278, write(&(String){8, 7, "]){0});"}));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_var_write_as = "St-var.write-as";
#define LUMI_FUNC_NAME _func_name_St_var_write_as
Returncode St_var_write_as(St_var* self, Bool* is_as) {
  CHECK(281, St_dec_write_as(&(self->_base), &((*is_as))));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_var__dtl[] = {St_var_parse, St_var_analyze_first, St_var_analyze, St_var_write, St_var_parse_array, St_var_parse_string, St_var_parse_as, St_var_m_is_allocation, St_var_write_primitive, St_var_write_class, St_var_write_string, St_var_write_array, St_var_write_as};


typedef struct St_ref St_ref; struct St_ref {
  St_dec _base;
};
static char* _func_name_St_ref_parse = "St-ref.parse";
#define LUMI_FUNC_NAME _func_name_St_ref_parse
Returncode St_ref_parse(St_ref* self) {
  CHECK(286, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_USER;
  
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_analyze_first = "St-ref.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_ref_analyze_first
Returncode St_ref_analyze_first(St_ref* self) {
  CHECK(290, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_analyze = "St-ref.analyze";
#define LUMI_FUNC_NAME _func_name_St_ref_analyze
Returncode St_ref_analyze(St_ref* self) {
  CHECK(293, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write = "St-ref.write";
#define LUMI_FUNC_NAME _func_name_St_ref_write
Returncode St_ref_write(St_ref* self) {
  CHECK(296, St_dec_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_parse_array = "St-ref.parse-array";
#define LUMI_FUNC_NAME _func_name_St_ref_parse_array
Returncode St_ref_parse_array(St_ref* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_parse_string = "St-ref.parse-string";
#define LUMI_FUNC_NAME _func_name_St_ref_parse_string
Returncode St_ref_parse_string(St_ref* self) {
  CHECK(302, f_syntax_error(&(String){31, 30, "unexpected parameter to String"}, &(String){1, 0, ""}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_parse_as = "St-ref.parse-as";
#define LUMI_FUNC_NAME _func_name_St_ref_parse_as
Returncode St_ref_parse_as(St_ref* self) {
  CHECK(305, f_syntax_error(&(String){23, 22, "illegal reference type"}, &(String){3, 2, "As"}));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_m_is_allocation = "St-ref.m-is-allocation";
#define LUMI_FUNC_NAME _func_name_St_ref_m_is_allocation
Returncode St_ref_m_is_allocation(St_ref* self, Bool* is_aloc) {
  (*is_aloc) = false;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write_primitive = "St-ref.write-primitive";
#define LUMI_FUNC_NAME _func_name_St_ref_write_primitive
Returncode St_ref_write_primitive(St_ref* self) {
  RAISE(311)
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write_class = "St-ref.write-class";
#define LUMI_FUNC_NAME _func_name_St_ref_write_class
Returncode St_ref_write_class(St_ref* self) {
  RAISE(314)
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write_string = "St-ref.write-string";
#define LUMI_FUNC_NAME _func_name_St_ref_write_string
Returncode St_ref_write_string(St_ref* self) {
  RAISE(317)
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write_array = "St-ref.write-array";
#define LUMI_FUNC_NAME _func_name_St_ref_write_array
Returncode St_ref_write_array(St_ref* self) {
  RAISE(320)
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_ref_write_as = "St-ref.write-as";
#define LUMI_FUNC_NAME _func_name_St_ref_write_as
Returncode St_ref_write_as(St_ref* self, Bool* is_as) {
  CHECK(323, St_dec_write_as(&(self->_base), &((*is_as))));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_ref__dtl[] = {St_ref_parse, St_ref_analyze_first, St_ref_analyze, St_ref_write, St_ref_parse_array, St_ref_parse_string, St_ref_parse_as, St_ref_m_is_allocation, St_ref_write_primitive, St_ref_write_class, St_ref_write_string, St_ref_write_array, St_ref_write_as};


typedef struct St_new St_new; struct St_new {
  St_dec _base;
  Mexp* arr_length;
  Mexp* str_length;
  Mexp* as_type;
};
static char* _func_name_St_new_parse = "St-new.parse";
#define LUMI_FUNC_NAME _func_name_St_new_parse
Returncode St_new_parse(St_new* self) {
  self->arr_length = NULL;
  self->str_length = NULL;
  self->as_type = NULL;
  CHECK(335, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_OWNER;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_analyze_first = "St-new.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_new_analyze_first
Returncode St_new_analyze_first(St_new* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_analyze = "St-new.analyze";
#define LUMI_FUNC_NAME _func_name_St_new_analyze
Returncode St_new_analyze(St_new* self) {
  if (NULL != self->_base.value && !self->_base.is_in) {
    CHECK(343, f_syntax_error(&(String){21, 20, "cannot initialize in"}, &(String){4, 3, "new"}));
  }
  if (NULL != self->str_length) {
    CHECK(345, Mexp_analyze_type(self->str_length, glob->type_int));
  }
  if (NULL != self->arr_length) {
    CHECK(347, Mexp_analyze_type(self->arr_length, glob->type_int));
  }
  if (NULL != self->as_type) {
    self->_base.mvar->mtype = NULL;
    CHECK(350, Mexp_analyze_get_subtype(self->as_type, glob->type_type, &(self->_base.mvar->mtype)));
    if (!(NULL != self->_base.mvar->mtype)) {
      CHECK(352, f_syntax_error(&(String){20, 19, "no subtype for type"}, self->_base.mvar->name));
    }
    self->_base.mvar->typename = self->_base.mvar->mtype->name;
  }
  CHECK(354, Mvar_analyze(self->_base.mvar));
  CHECK(355, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write = "St-new.write";
#define LUMI_FUNC_NAME _func_name_St_new_write
Returncode St_new_write(St_new* self) {
  CHECK(358, St_dec_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_parse_array = "St-new.parse-array";
#define LUMI_FUNC_NAME _func_name_St_new_parse_array
Returncode St_new_parse_array(St_new* self) {
  Char _Char18;
  CHECK(361, parse_new_exp(&(String){2, 1, ":"}, &(self->arr_length), &(_Char18)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_parse_string = "St-new.parse-string";
#define LUMI_FUNC_NAME _func_name_St_new_parse_string
Returncode St_new_parse_string(St_new* self) {
  Char _Char19;
  CHECK(364, parse_new_exp(&(String){2, 1, "}"}, &(self->str_length), &(_Char19)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_parse_as = "St-new.parse-as";
#define LUMI_FUNC_NAME _func_name_St_new_parse_as
Returncode St_new_parse_as(St_new* self) {
  Char _Char20;
  CHECK(367, parse_new_exp(&(String){2, 1, "}"}, &(self->as_type), &(_Char20)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_m_is_allocation = "St-new.m-is-allocation";
#define LUMI_FUNC_NAME _func_name_St_new_m_is_allocation
Returncode St_new_m_is_allocation(St_new* self, Bool* is_aloc) {
  (*is_aloc) = true;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_check = "St-new.write-check";
#define LUMI_FUNC_NAME _func_name_St_new_write_check
Returncode St_new_write_check(St_new* self) {
  /* if (name == NULL) RAISE(line-num) */
  CHECK(374, write_new_indent_line());
  CHECK(375, write(&(String){5, 4, "if ("}));
  CHECK(376, St_dec_write_name(&(self->_base)));
  CHECK(377, write(&(String){11, 10, " == NULL) "}));
  CHECK(378, write_tb_raise());
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_primitive = "St-new.write-primitive";
#define LUMI_FUNC_NAME _func_name_St_new_write_primitive
Returncode St_new_write_primitive(St_new* self) {
  CHECK(381, f_syntax_error(&(String){33, 32, "new not supported for primitive "}, self->_base.mvar->name));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_class = "St-new.write-class";
#define LUMI_FUNC_NAME _func_name_St_new_write_class
Returncode St_new_write_class(St_new* self) {
  /* Class* name = malloc(sizeof(Class)); */
  /* if (name == NULL) RAISE(line-num) */
  /* *name = (Class){init-values...}; */
  CHECK(387, write(&(String){15, 14, "malloc(sizeof("}));
  CHECK(388, write_cstyle(self->_base.mvar->mtype->name));
  CHECK(389, write(&(String){4, 3, "));"}));
  CHECK(390, St_new_write_check(self));
  CHECK(391, write_new_indent_line());
  CHECK(392, write(&(String){2, 1, "*"}));
  CHECK(393, St_dec_write_name(&(self->_base)));
  CHECK(394, write(&(String){4, 3, " = "}));
  CHECK(395, St_dec_write_struct_init(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_string = "St-new.write-string";
#define LUMI_FUNC_NAME _func_name_St_new_write_string
Returncode St_new_write_string(St_new* self) {
  /* String* name = _new_string(length); */
  /* if (name == NULL) RAISE(line-num) */
  if (!(NULL != self->str_length)) {
    CHECK(401, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(402, Mexp_write_intro(self->str_length));
  CHECK(403, write(&(String){13, 12, "_new_string("}));
  CHECK(404, Mexp_write_final(self->str_length));
  CHECK(405, write(&(String){3, 2, ");"}));
  CHECK(406, St_new_write_check(self));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_array = "St-new.write-array";
#define LUMI_FUNC_NAME _func_name_St_new_write_array
Returncode St_new_write_array(St_new* self) {
  /* Array* name = _new_array(length, sizeof(Class)); */
  /* Array* name = _new_array(length, sizeof(String) + (string-length)); */
  /* if (name == NULL) RAISE(line-num) */
  /* _set_new_string_array(length, string-length, name); */
  if (!(NULL != self->arr_length)) {
    CHECK(414, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(415, Mexp_write_intro(self->arr_length));
  if (NULL != self->str_length) {
    CHECK(417, Mexp_write_intro(self->str_length));
  }
  CHECK(418, write(&(String){12, 11, "_new_array("}));
  CHECK(419, Mexp_write_final(self->arr_length));
  CHECK(420, write(&(String){10, 9, ", sizeof("}));
  CHECK(421, write_cstyle(self->_base.mvar->sub_typename));
  if (NULL != self->str_length) {
    CHECK(423, write(&(String){6, 5, ") + ("}));
    CHECK(424, Mexp_write_final(self->str_length));
  }
  CHECK(425, write(&(String){4, 3, "));"}));
  CHECK(426, St_new_write_check(self));
  if (NULL != self->str_length) {
    CHECK(428, write_new_indent_line());
    CHECK(429, write(&(String){23, 22, "_set_new_string_array("}));
    CHECK(430, Mexp_write_final(self->arr_length));
    CHECK(431, write(&(String){3, 2, ", "}));
    CHECK(432, Mexp_write_final(self->str_length));
    CHECK(433, write(&(String){3, 2, ", "}));
    CHECK(434, St_dec_write_name(&(self->_base)));
    CHECK(435, write(&(String){3, 2, ");"}));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_new_write_as = "St-new.write-as";
#define LUMI_FUNC_NAME _func_name_St_new_write_as
Returncode St_new_write_as(St_new* self, Bool* is_as) {
  (*is_as) = NULL != self->as_type;
  if (!(*is_as)) {
    return OK;
  }
  /* Type* name = calloc(1, (as-type).size); */
  /* name->[_base.]_dtl = (as-type).dtl; */
  CHECK(443, Mexp_write_intro(self->as_type));
  CHECK(444, write(&(String){12, 11, "calloc(1, ("}));
  CHECK(445, Mexp_write_final(self->as_type));
  CHECK(446, write(&(String){9, 8, ").size);"}));
  CHECK(447, St_new_write_check(self));
  if (NULL != self->_base.mvar->mtype->dynamic_members) {
    CHECK(449, St_dec_write_to_dtl(&(self->_base)));
    CHECK(450, write(&(String){2, 1, "("}));
    CHECK(451, Mexp_write_final(self->as_type));
    CHECK(452, write(&(String){7, 6, ").dtl;"}));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_new__dtl[] = {St_new_parse, St_new_analyze_first, St_new_analyze, St_new_write, St_new_parse_array, St_new_parse_string, St_new_parse_as, St_new_m_is_allocation, St_new_write_primitive, St_new_write_class, St_new_write_string, St_new_write_array, St_new_write_as};


typedef struct St_delete St_delete; struct St_delete {
  St _base;
  Mexp* mexp;
};
static char* _func_name_St_delete_parse = "St-delete.parse";
#define LUMI_FUNC_NAME _func_name_St_delete_parse
Returncode St_delete_parse(St_delete* self) {
  Char _Char21;
  CHECK(459, parse_new_exp(&(String){1, 0, ""}, &(self->mexp), &(_Char21)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_delete_analyze_first = "St-delete.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_delete_analyze_first
Returncode St_delete_analyze_first(St_delete* self) {
  /* nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_delete_analyze = "St-delete.analyze";
#define LUMI_FUNC_NAME _func_name_St_delete_analyze
Returncode St_delete_analyze(St_delete* self) {
  Mtype* mtype = NULL;
  Mtype* sub_mtype = NULL;
  CHECK(467, Mexp_analyze(self->mexp, &(mtype), &(sub_mtype)));
  if (!(NULL != mtype)) {
    CHECK(469, f_syntax_error(&(String){29, 28, "illegal expression given for"}, &(String){7, 6, "delete"}));
  }
  if (mtype->is_primitive) {
    CHECK(471, f_syntax_error(&(String){19, 18, "cannot delete type"}, mtype->name));
  }
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_delete_write = "St-delete.write";
#define LUMI_FUNC_NAME _func_name_St_delete_write
Returncode St_delete_write(St_delete* self) {
  CHECK(474, Mexp_write_intro(self->mexp));
  CHECK(475, write(&(String){6, 5, "free("}));
  CHECK(476, Mexp_write_final(self->mexp));
  CHECK(477, write(&(String){3, 2, ");"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_delete__dtl[] = {St_delete_parse, St_delete_analyze_first, St_delete_analyze, St_delete_write};

#undef LUMI_FILE_NAME
