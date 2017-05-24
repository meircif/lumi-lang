static char* _mr_file8_name = "dec.2.mr";
#define MR_FILE_NAME _mr_file8_name
/* MR3 compiler - variable declerations */

typedef struct St_dec St_dec; struct St_dec {
  St _base;
  Mvar* mvar;
  Mexp* value;
  Bool is_in;
};
static char* _func_name_St_dec_parse = "St-dec.parse";
#define MR_FUNC_NAME _func_name_St_dec_parse
Returncode St_dec_parse(St_dec* self) {
  CHECK(9, init_new_var(NULL, &(self->mvar)));
  self->value = NULL;
  Char _Char0;
  CHECK(11, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &(_Char0)))
  if (_Char0 == '{') {
    Bool _Bool1;
    CHECK(12, String_equal(self->mvar->typename, &(String){6, 5, "Array"}, &(_Bool1)))
    if (_Bool1) {
      CHECK(13, (*((Func**)(self)))[4](self));
      Char _Char2;
      CHECK(14, read_new(&(String){3, 2, "{}"}, &(self->mvar->sub_typename), &(_Char2)))
      if (_Char2 == '{') {
        CHECK(15, (*((Func**)(self)))[5](self));
        Char _Char3;
        CHECK(16, read_c(&(_Char3)));
      }
    }
    else {
      Bool _Bool4;
      CHECK(17, String_equal(self->mvar->typename, &(String){7, 6, "String"}, &(_Bool4)))
      if (_Bool4) {
        CHECK(18, (*((Func**)(self)))[5](self));
      }
      else {
        Bool _Bool5;
        CHECK(19, String_equal(self->mvar->typename, &(String){3, 2, "As"}, &(_Bool5)))
        if (_Bool5) {
          CHECK(20, (*((Func**)(self)))[6](self));
        }
        else {
          Char _Char6;
          CHECK(22, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &(_Char6)));
        }
      }
    }
    Char _Char7;
    CHECK(23, read_c(&(_Char7)));
  }
  Char end;
  CHECK(25, read_new(&(String){3, 2, " ("}, &(self->mvar->name), &(end)))
  if (end == '(') {
    Char _Char8;
    CHECK(26, parse_new_exp(&(String){2, 1, ")"}, &(self->value), &(_Char8)));
    Char _Char9;
    CHECK(27, read_c(&(_Char9)));
  }
  self->is_in = end == ' ';
  if (self->is_in) {
    Bool _Bool10;
    CHECK(30, String_equal(self->mvar->name, &(String){3, 2, "in"}, &(_Bool10)))
    if (!_Bool10) {
      CHECK(31, f_syntax_error(&(String){19, 18, "expected 'in', got"}, self->mvar->name));
    }
    Char _Char11;
    CHECK(32, parse_new_exp(&(String){1, 0, ""}, &(self->value), &(_Char11)));
  }
  else {
    CHECK(34, St_add_var(&(self->_base), self->mvar));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze_first = "St-dec.analyze-first";
#define MR_FUNC_NAME _func_name_St_dec_analyze_first
Returncode St_dec_analyze_first(St_dec* self) {
  CHECK(37, Mvar_analyze(self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze = "St-dec.analyze";
#define MR_FUNC_NAME _func_name_St_dec_analyze
Returncode St_dec_analyze(St_dec* self) {
  if (NULL != self->value) {
    CHECK(41, Mexp_analyze_types(self->value, self->mvar->mtype, self->mvar->sub_mtype));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_m_is_global = "St-dec.m-is-global";
#define MR_FUNC_NAME _func_name_St_dec_m_is_global
Returncode St_dec_m_is_global(St_dec* self, Bool* is_global) {
  (*is_global) = !(NULL != self->_base.father->father->father);
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_name = "St-dec.write-name";
#define MR_FUNC_NAME _func_name_St_dec_write_name
Returncode St_dec_write_name(St_dec* self) {
  if (self->is_in) {
    CHECK(48, Mexp_write_final(self->value));
  }
  else {
    CHECK(50, write_cstyle(self->mvar->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_dec = "St-dec.write-dec";
#define MR_FUNC_NAME _func_name_St_dec_write_dec
Returncode St_dec_write_dec(St_dec* self) {
  if (self->is_in) {
    CHECK(54, Mexp_write_final(self->value));
  }
  else {
    CHECK(56, write_cstyle(self->mvar->mtype->name));
    if (!self->mvar->mtype->is_primitive) {
      CHECK(58, write(&(String){2, 1, "*"}));
    }
    CHECK(59, write(&(String){2, 1, " "}));
    CHECK(60, write_cstyle(self->mvar->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_to_dtl = "St-dec.write-to-dtl";
#define MR_FUNC_NAME _func_name_St_dec_write_to_dtl
Returncode St_dec_write_to_dtl(St_dec* self) {
  /* name->[_base.]_dtl =  */
  CHECK(64, write_new_indent_line());
  CHECK(65, St_dec_write_name(self));
  CHECK(66, write(&(String){3, 2, "->"}));
  Mtype* basetype = self->mvar->mtype->base_mtype;
  while (true) {
    if (!(NULL != basetype)) break;
    CHECK(70, write(&(String){7, 6, "_base."}));
    basetype = basetype->base_mtype;
  }
  CHECK(72, write(&(String){8, 7, "_dtl = "}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_struct_init = "St-dec.write-struct-init";
#define MR_FUNC_NAME _func_name_St_dec_write_struct_init
Returncode St_dec_write_struct_init(St_dec* self) {
  /* (Type){init-values...}; */
  CHECK(76, write(&(String){2, 1, "("}));
  CHECK(77, write_cstyle(self->mvar->mtype->name));
  CHECK(78, write(&(String){3, 2, "){"}));
  Bool is_dynmaic = NULL != self->mvar->mtype->dynamic_members;
  if (is_dynmaic) {
    CHECK(81, write_cstyle(self->mvar->mtype->name));
    CHECK(82, write(&(String){6, 5, "__dtl"}));
  }
  CHECK(83, write_type_init(self->mvar->mtype, self->mvar->sub_mtype, !is_dynmaic));
  CHECK(84, write(&(String){3, 2, "};"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write = "St-dec.write";
#define MR_FUNC_NAME _func_name_St_dec_write
Returncode St_dec_write(St_dec* self) {
  if (NULL != glob->mclass) {
    if (glob->methods) {
      return OK;
    }
    CHECK(90, write_spaces());
  }
  else {
    Bool _Bool12;
    CHECK(91, St_dec_m_is_global(self, &(_Bool12)))
    if (_Bool12) {
      CHECK(92, write(&(String){33, 32, "#if MR_STAGE == MR_DECLARATIONS\n"}));
      CHECK(93, write_spaces());
      CHECK(94, write(&(String){8, 7, "extern "}));
      CHECK(95, St_dec_write_dec(self));
      CHECK(96, write(&(String){3, 2, ";\n"}));
      CHECK(97, write_spaces());
      CHECK(98, write(&(String){32, 31, "#elif MR_STAGE == MR_FUNCTIONS\n"}));
      CHECK(99, write_spaces());
    }
  }
  if (NULL != self->value) {
    CHECK(101, Mexp_write_intro(self->value));
  }
  CHECK(102, St_dec_write_dec(self));
  Bool _Bool13;
  CHECK(103, (*((Func**)(self)))[7](self, &(_Bool13)))
  if (_Bool13) {
    CHECK(104, write(&(String){4, 3, " = "}));
    if (self->mvar->mtype == glob->type_string) {
      CHECK(106, (*((Func**)(self)))[10](self));
    }
    else {
      if (self->mvar->mtype == glob->type_array) {
        if (!(NULL != self->mvar->sub_typename)) {
          CHECK(109, f_syntax_error(&(String){22, 21, "Array type missing in"}, self->mvar->name));
        }
        CHECK(110, (*((Func**)(self)))[11](self));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          CHECK(112, (*((Func**)(self)))[8](self));
        }
        else {
          Bool _Bool14;
          CHECK(113, (*((Func**)(self)))[12](self, &(_Bool14)))
          if (!_Bool14) {
            CHECK(114, (*((Func**)(self)))[9](self));
            if (NULL != self->mvar->mtype->dynamic_members) {
              CHECK(116, St_dec_write_to_dtl(self));
              CHECK(117, write_cstyle(self->mvar->mtype->name));
              CHECK(118, write(&(String){7, 6, "__dtl;"}));
            }
          }
        }
      }
    }
  }
  else {
    if (!(NULL != glob->mclass)) {
      CHECK(121, write(&(String){4, 3, " = "}));
      if (NULL != self->value) {
        CHECK(123, Mexp_write_final(self->value));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          if (self->mvar->mtype == glob->type_type) {
            CHECK(126, write(&(String){8, 7, "(Type){"}));
            CHECK(127, write_type_type_params(self->mvar->sub_mtype));
            CHECK(128, write(&(String){2, 1, "}"}));
          }
          else {
            CHECK(130, write_type_init(self->mvar->mtype, self->mvar->sub_mtype, true));
          }
        }
        else {
          CHECK(132, write(&(String){5, 4, "NULL"}));
        }
      }
    }
    CHECK(133, write(&(String){2, 1, ";"}));
  }
  if (NULL != glob->mclass) {
    CHECK(135, write(&(String){2, 1, "\n"}));
  }
  else {
    Bool _Bool15;
    CHECK(136, St_dec_m_is_global(self, &(_Bool15)))
    if (_Bool15) {
      CHECK(137, write_new_indent_line());
      CHECK(138, write(&(String){7, 6, "#endif"}));
    }
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
static char* _func_name_St_dec_parse_as = "St-dec.parse-as";
#define MR_FUNC_NAME _func_name_St_dec_parse_as
Returncode St_dec_parse_as(St_dec* self) {
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
static char* _func_name_St_dec_write_as = "St-dec.write-as";
#define MR_FUNC_NAME _func_name_St_dec_write_as
Returncode St_dec_write_as(St_dec* self, Bool* is_as) {
  (*is_as) = false;
  return OK;
}
#undef MR_FUNC_NAME
Func St_dec__dtl[] = {St_dec_parse, St_dec_analyze_first, St_dec_analyze, St_dec_write, St_dec_parse_array, St_dec_parse_string, St_dec_parse_as, St_dec_m_is_allocation, St_dec_write_primitive, St_dec_write_class, St_dec_write_string, St_dec_write_array, St_dec_write_as};


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
  CHECK(175, St_dec_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze_first = "St-var.analyze-first";
#define MR_FUNC_NAME _func_name_St_var_analyze_first
Returncode St_var_analyze_first(St_var* self) {
  CHECK(178, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze = "St-var.analyze";
#define MR_FUNC_NAME _func_name_St_var_analyze
Returncode St_var_analyze(St_var* self) {
  CHECK(181, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write = "St-var.write";
#define MR_FUNC_NAME _func_name_St_var_write
Returncode St_var_write(St_var* self) {
  CHECK(184, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_array = "St-var.parse-array";
#define MR_FUNC_NAME _func_name_St_var_parse_array
Returncode St_var_parse_array(St_var* self) {
  Char _Char16;
  CHECK(187, read_new(&(String){2, 1, ":"}, &(self->arr_length), &(_Char16)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_string = "St-var.parse-string";
#define MR_FUNC_NAME _func_name_St_var_parse_string
Returncode St_var_parse_string(St_var* self) {
  Char _Char17;
  CHECK(190, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char17)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_as = "St-var.parse-as";
#define MR_FUNC_NAME _func_name_St_var_parse_as
Returncode St_var_parse_as(St_var* self) {
  CHECK(193, f_syntax_error(&(String){22, 21, "illegal variable type"}, &(String){3, 2, "As"}));
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
  RAISE(199)
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_class = "St-var.write-class";
#define MR_FUNC_NAME _func_name_St_var_write_class
Returncode St_var_write_class(St_var* self) {
  CHECK(202, write(&(String){2, 1, "&"}));
  CHECK(203, St_dec_write_struct_init(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_string = "St-var.write-string";
#define MR_FUNC_NAME _func_name_St_var_write_string
Returncode St_var_write_string(St_var* self) {
  /* String* name = &(String){length, 0, (char[length]){0}}; */
  /* CHECK(line-num, String_copy(name, init)); */
  if (!(NULL != self->str_length)) {
    CHECK(209, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(210, write(&(String){11, 10, "&(String){"}));
  CHECK(211, write(self->str_length));
  CHECK(212, write(&(String){12, 11, ", 0, (char["}));
  CHECK(213, write(self->str_length));
  CHECK(214, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->_base.value) {
    CHECK(216, write_new_indent_line());
    CHECK(217, write_tb_check());
    CHECK(218, write(&(String){13, 12, "String_copy("}));
    CHECK(219, write_cstyle(self->_base.mvar->name));
    CHECK(220, write(&(String){3, 2, ", "}));
    CHECK(221, Mexp_write_final(self->_base.value));
    CHECK(222, write(&(String){3, 2, "))"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_array = "St-var.write-array";
#define MR_FUNC_NAME _func_name_St_var_write_array
Returncode St_var_write_array(St_var* self) {
  /* Array* name = &(Array){length, (Class[length]){0}}; */
  /* Array* name = &(Array){length, (String[length]){0}}; */
  /* _set_var_string_array(length, string-length, name, (char[string-length * length]){0}); */
  if (!(NULL != self->arr_length)) {
    CHECK(229, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(230, write(&(String){10, 9, "&(Array){"}));
  CHECK(231, write(self->arr_length));
  CHECK(232, write(&(String){4, 3, ", ("}));
  CHECK(233, write_cstyle(self->_base.mvar->sub_typename));
  CHECK(234, write(&(String){2, 1, "["}));
  CHECK(235, write(self->arr_length));
  CHECK(236, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->str_length) {
    CHECK(238, write_new_indent_line());
    CHECK(239, write(&(String){23, 22, "_set_var_string_array("}));
    CHECK(240, write(self->arr_length));
    CHECK(241, write(&(String){3, 2, ", "}));
    CHECK(242, write(self->str_length));
    CHECK(243, write(&(String){3, 2, ", "}));
    CHECK(244, write_cstyle(self->_base.mvar->name));
    CHECK(245, write(&(String){9, 8, ", (char["}));
    CHECK(246, write(self->str_length));
    CHECK(247, write(&(String){4, 3, " * "}));
    CHECK(248, write(self->arr_length));
    CHECK(249, write(&(String){8, 7, "]){0});"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_as = "St-var.write-as";
#define MR_FUNC_NAME _func_name_St_var_write_as
Returncode St_var_write_as(St_var* self, Bool* is_as) {
  CHECK(252, St_dec_write_as(&(self->_base), &((*is_as))));
  return OK;
}
#undef MR_FUNC_NAME
Func St_var__dtl[] = {St_var_parse, St_var_analyze_first, St_var_analyze, St_var_write, St_var_parse_array, St_var_parse_string, St_var_parse_as, St_var_m_is_allocation, St_var_write_primitive, St_var_write_class, St_var_write_string, St_var_write_array, St_var_write_as};


typedef struct St_ref St_ref; struct St_ref {
  St_dec _base;
};
static char* _func_name_St_ref_parse = "St-ref.parse";
#define MR_FUNC_NAME _func_name_St_ref_parse
Returncode St_ref_parse(St_ref* self) {
  CHECK(257, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_USER;
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze_first = "St-ref.analyze-first";
#define MR_FUNC_NAME _func_name_St_ref_analyze_first
Returncode St_ref_analyze_first(St_ref* self) {
  CHECK(261, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze = "St-ref.analyze";
#define MR_FUNC_NAME _func_name_St_ref_analyze
Returncode St_ref_analyze(St_ref* self) {
  CHECK(264, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write = "St-ref.write";
#define MR_FUNC_NAME _func_name_St_ref_write
Returncode St_ref_write(St_ref* self) {
  CHECK(267, St_dec_write(&(self->_base)));
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
  CHECK(273, f_syntax_error(&(String){31, 30, "unexpected parameter to String"}, &(String){1, 0, ""}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_as = "St-ref.parse-as";
#define MR_FUNC_NAME _func_name_St_ref_parse_as
Returncode St_ref_parse_as(St_ref* self) {
  CHECK(276, f_syntax_error(&(String){23, 22, "illegal reference type"}, &(String){3, 2, "As"}));
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
  RAISE(282)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_class = "St-ref.write-class";
#define MR_FUNC_NAME _func_name_St_ref_write_class
Returncode St_ref_write_class(St_ref* self) {
  RAISE(285)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_string = "St-ref.write-string";
#define MR_FUNC_NAME _func_name_St_ref_write_string
Returncode St_ref_write_string(St_ref* self) {
  RAISE(288)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_array = "St-ref.write-array";
#define MR_FUNC_NAME _func_name_St_ref_write_array
Returncode St_ref_write_array(St_ref* self) {
  RAISE(291)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_as = "St-ref.write-as";
#define MR_FUNC_NAME _func_name_St_ref_write_as
Returncode St_ref_write_as(St_ref* self, Bool* is_as) {
  CHECK(294, St_dec_write_as(&(self->_base), &((*is_as))));
  return OK;
}
#undef MR_FUNC_NAME
Func St_ref__dtl[] = {St_ref_parse, St_ref_analyze_first, St_ref_analyze, St_ref_write, St_ref_parse_array, St_ref_parse_string, St_ref_parse_as, St_ref_m_is_allocation, St_ref_write_primitive, St_ref_write_class, St_ref_write_string, St_ref_write_array, St_ref_write_as};


typedef struct St_new St_new; struct St_new {
  St_dec _base;
  Mexp* arr_length;
  Mexp* str_length;
  Mexp* as_type;
};
static char* _func_name_St_new_parse = "St-new.parse";
#define MR_FUNC_NAME _func_name_St_new_parse
Returncode St_new_parse(St_new* self) {
  self->arr_length = NULL;
  self->str_length = NULL;
  self->as_type = NULL;
  CHECK(306, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_OWNER;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze_first = "St-new.analyze-first";
#define MR_FUNC_NAME _func_name_St_new_analyze_first
Returncode St_new_analyze_first(St_new* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze = "St-new.analyze";
#define MR_FUNC_NAME _func_name_St_new_analyze
Returncode St_new_analyze(St_new* self) {
  if (NULL != self->_base.value && !self->_base.is_in) {
    CHECK(314, f_syntax_error(&(String){21, 20, "cannot initialize in"}, &(String){4, 3, "new"}));
  }
  if (NULL != self->str_length) {
    CHECK(316, Mexp_analyze_type(self->str_length, glob->type_int));
  }
  if (NULL != self->arr_length) {
    CHECK(318, Mexp_analyze_type(self->arr_length, glob->type_int));
  }
  if (NULL != self->as_type) {
    self->_base.mvar->mtype = NULL;
    CHECK(321, Mexp_analyze_get_subtype(self->as_type, glob->type_type, &(self->_base.mvar->mtype)));
    if (!(NULL != self->_base.mvar->mtype)) {
      CHECK(323, f_syntax_error(&(String){20, 19, "no subtype for type"}, self->_base.mvar->name));
    }
    self->_base.mvar->typename = self->_base.mvar->mtype->name;
  }
  CHECK(325, Mvar_analyze(self->_base.mvar));
  CHECK(326, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write = "St-new.write";
#define MR_FUNC_NAME _func_name_St_new_write
Returncode St_new_write(St_new* self) {
  CHECK(329, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_array = "St-new.parse-array";
#define MR_FUNC_NAME _func_name_St_new_parse_array
Returncode St_new_parse_array(St_new* self) {
  Char _Char18;
  CHECK(332, parse_new_exp(&(String){2, 1, ":"}, &(self->arr_length), &(_Char18)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_string = "St-new.parse-string";
#define MR_FUNC_NAME _func_name_St_new_parse_string
Returncode St_new_parse_string(St_new* self) {
  Char _Char19;
  CHECK(335, parse_new_exp(&(String){2, 1, "}"}, &(self->str_length), &(_Char19)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_as = "St-new.parse-as";
#define MR_FUNC_NAME _func_name_St_new_parse_as
Returncode St_new_parse_as(St_new* self) {
  Char _Char20;
  CHECK(338, parse_new_exp(&(String){2, 1, "}"}, &(self->as_type), &(_Char20)));
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
  CHECK(345, write_new_indent_line());
  CHECK(346, write(&(String){5, 4, "if ("}));
  CHECK(347, St_dec_write_name(&(self->_base)));
  CHECK(348, write(&(String){11, 10, " == NULL) "}));
  CHECK(349, write_tb_raise());
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_primitive = "St-new.write-primitive";
#define MR_FUNC_NAME _func_name_St_new_write_primitive
Returncode St_new_write_primitive(St_new* self) {
  CHECK(352, f_syntax_error(&(String){33, 32, "new not supported for primitive "}, self->_base.mvar->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_class = "St-new.write-class";
#define MR_FUNC_NAME _func_name_St_new_write_class
Returncode St_new_write_class(St_new* self) {
  /* Class* name = malloc(sizeof(Class)); */
  /* if (name == NULL) RAISE(line-num) */
  /* *name = (Class){init-values...}; */
  CHECK(358, write(&(String){15, 14, "malloc(sizeof("}));
  CHECK(359, write_cstyle(self->_base.mvar->mtype->name));
  CHECK(360, write(&(String){4, 3, "));"}));
  CHECK(361, St_new_write_check(self));
  CHECK(362, write_new_indent_line());
  CHECK(363, write(&(String){2, 1, "*"}));
  CHECK(364, St_dec_write_name(&(self->_base)));
  CHECK(365, write(&(String){4, 3, " = "}));
  CHECK(366, St_dec_write_struct_init(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_string = "St-new.write-string";
#define MR_FUNC_NAME _func_name_St_new_write_string
Returncode St_new_write_string(St_new* self) {
  /* String* name = _new_string(length); */
  /* if (name == NULL) RAISE(line-num) */
  if (!(NULL != self->str_length)) {
    CHECK(372, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(373, Mexp_write_intro(self->str_length));
  CHECK(374, write(&(String){13, 12, "_new_string("}));
  CHECK(375, Mexp_write_final(self->str_length));
  CHECK(376, write(&(String){3, 2, ");"}));
  CHECK(377, St_new_write_check(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_array = "St-new.write-array";
#define MR_FUNC_NAME _func_name_St_new_write_array
Returncode St_new_write_array(St_new* self) {
  /* Array* name = _new_array(length, sizeof(Class)); */
  /* Array* name = _new_array(length, sizeof(String) + (string-length)); */
  /* if (name == NULL) RAISE(line-num) */
  /* _set_new_string_array(length, string-length, name); */
  if (!(NULL != self->arr_length)) {
    CHECK(385, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(386, Mexp_write_intro(self->arr_length));
  if (NULL != self->str_length) {
    CHECK(388, Mexp_write_intro(self->str_length));
  }
  CHECK(389, write(&(String){12, 11, "_new_array("}));
  CHECK(390, Mexp_write_final(self->arr_length));
  CHECK(391, write(&(String){10, 9, ", sizeof("}));
  CHECK(392, write_cstyle(self->_base.mvar->sub_typename));
  if (NULL != self->str_length) {
    CHECK(394, write(&(String){6, 5, ") + ("}));
    CHECK(395, Mexp_write_final(self->str_length));
  }
  CHECK(396, write(&(String){4, 3, "));"}));
  CHECK(397, St_new_write_check(self));
  if (NULL != self->str_length) {
    CHECK(399, write_new_indent_line());
    CHECK(400, write(&(String){23, 22, "_set_new_string_array("}));
    CHECK(401, Mexp_write_final(self->arr_length));
    CHECK(402, write(&(String){3, 2, ", "}));
    CHECK(403, Mexp_write_final(self->str_length));
    CHECK(404, write(&(String){3, 2, ", "}));
    CHECK(405, St_dec_write_name(&(self->_base)));
    CHECK(406, write(&(String){3, 2, ");"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_as = "St-new.write-as";
#define MR_FUNC_NAME _func_name_St_new_write_as
Returncode St_new_write_as(St_new* self, Bool* is_as) {
  (*is_as) = NULL != self->as_type;
  if (!(*is_as)) {
    return OK;
  }
  /* Type* name = calloc(1, (as-type).size); */
  /* name->[_base.]_dtl = (as-type).dtl; */
  CHECK(414, Mexp_write_intro(self->as_type));
  CHECK(415, write(&(String){12, 11, "calloc(1, ("}));
  CHECK(416, Mexp_write_final(self->as_type));
  CHECK(417, write(&(String){9, 8, ").size);"}));
  CHECK(418, St_new_write_check(self));
  if (NULL != self->_base.mvar->mtype->dynamic_members) {
    CHECK(420, St_dec_write_to_dtl(&(self->_base)));
    CHECK(421, write(&(String){2, 1, "("}));
    CHECK(422, Mexp_write_final(self->as_type));
    CHECK(423, write(&(String){7, 6, ").dtl;"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_new__dtl[] = {St_new_parse, St_new_analyze_first, St_new_analyze, St_new_write, St_new_parse_array, St_new_parse_string, St_new_parse_as, St_new_m_is_allocation, St_new_write_primitive, St_new_write_class, St_new_write_string, St_new_write_array, St_new_write_as};


typedef struct St_delete St_delete; struct St_delete {
  St _base;
  String* name;
  Mvar* mvar;
};
static char* _func_name_St_delete_parse = "St-delete.parse";
#define MR_FUNC_NAME _func_name_St_delete_parse
Returncode St_delete_parse(St_delete* self) {
  Char _Char21;
  CHECK(431, read_new(&(String){1, 0, ""}, &(self->name), &(_Char21)));
  self->mvar = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_analyze_first = "St-delete.analyze-first";
#define MR_FUNC_NAME _func_name_St_delete_analyze_first
Returncode St_delete_analyze_first(St_delete* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_analyze = "St-delete.analyze";
#define MR_FUNC_NAME _func_name_St_delete_analyze
Returncode St_delete_analyze(St_delete* self) {
  CHECK(438, St_m_find_var(&(self->_base), self->name, &(self->mvar)))
  if (!(NULL != self->mvar)) {
    CHECK(439, f_syntax_error(&(String){16, 15, "unknow variable"}, self->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_write = "St-delete.write";
#define MR_FUNC_NAME _func_name_St_delete_write
Returncode St_delete_write(St_delete* self) {
  CHECK(442, write(&(String){6, 5, "free("}));
  CHECK(443, write_cstyle(self->name));
  CHECK(444, write(&(String){3, 2, ");"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_delete__dtl[] = {St_delete_parse, St_delete_analyze_first, St_delete_analyze, St_delete_write};

#undef MR_FILE_NAME
