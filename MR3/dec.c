static char* _mr_file8_name = "dec.2.mr";
#define MR_FILE_NAME _mr_file8_name
/* MR3 compiler - variable declerations */

typedef struct St_dec St_dec; struct St_dec {
  St _base;
  Mvar* mvar;
  Mexp* value;
};
static char* _func_name_St_dec_parse = "St-dec.parse";
#define MR_FUNC_NAME _func_name_St_dec_parse
Returncode St_dec_parse(St_dec* self) {
  CHECK(8, init_new_var(NULL, &(self->mvar)));
  self->value = NULL;
  Char _Char0;
  CHECK(10, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &(_Char0)))
  if (_Char0 == '{') {
    Bool _Bool1;
    CHECK(11, String_equal(self->mvar->typename, &(String){6, 5, "Array"}, &(_Bool1)))
    if (_Bool1) {
      CHECK(12, (*((Func**)(self)))[4](self));
      Char _Char2;
      CHECK(13, read_new(&(String){3, 2, "{}"}, &(self->mvar->sub_typename), &(_Char2)))
      if (_Char2 == '{') {
        CHECK(14, (*((Func**)(self)))[5](self));
        Char _Char3;
        CHECK(15, read_c(&(_Char3)));
      }
    }
    else {
      Bool _Bool4;
      CHECK(16, String_equal(self->mvar->typename, &(String){7, 6, "String"}, &(_Bool4)))
      if (_Bool4) {
        CHECK(17, (*((Func**)(self)))[5](self));
      }
      else {
        Bool _Bool5;
        CHECK(18, String_equal(self->mvar->typename, &(String){3, 2, "As"}, &(_Bool5)))
        if (_Bool5) {
          CHECK(19, (*((Func**)(self)))[6](self));
        }
        else {
          Char _Char6;
          CHECK(21, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &(_Char6)));
        }
      }
    }
    Char _Char7;
    CHECK(22, read_c(&(_Char7)));
  }
  Char _Char8;
  CHECK(23, read_new(&(String){2, 1, "("}, &(self->mvar->name), &(_Char8)))
  if (_Char8 == '(') {
    Char _Char9;
    CHECK(24, parse_new_exp(&(String){2, 1, ")"}, &(self->value), &(_Char9)));
    Char _Char10;
    CHECK(25, read_c(&(_Char10)));
  }
  CHECK(26, St_add_var(&(self->_base), self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze_first = "St-dec.analyze-first";
#define MR_FUNC_NAME _func_name_St_dec_analyze_first
Returncode St_dec_analyze_first(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze = "St-dec.analyze";
#define MR_FUNC_NAME _func_name_St_dec_analyze
Returncode St_dec_analyze(St_dec* self) {
  CHECK(32, Mvar_analyze(self->mvar));
  if (NULL != self->value) {
    CHECK(34, Mexp_analyze_types(self->value, self->mvar->mtype, self->mvar->sub_mtype));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write_to_dtl = "St-dec.write-to-dtl";
#define MR_FUNC_NAME _func_name_St_dec_write_to_dtl
Returncode St_dec_write_to_dtl(St_dec* self) {
  /* name->[_base.]_dtl =  */
  CHECK(38, write_new_indent_line());
  CHECK(39, write_cstyle(self->mvar->name));
  CHECK(40, write(&(String){3, 2, "->"}));
  Mtype* basetype = self->mvar->mtype->base_mtype;
  while (true) {
    if (!(NULL != basetype)) break;
    CHECK(44, write(&(String){7, 6, "_base."}));
    basetype = basetype->base_mtype;
  }
  CHECK(46, write(&(String){8, 7, "_dtl = "}));
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
    CHECK(52, write_spaces());
  }
  if (NULL != self->value) {
    CHECK(54, Mexp_write_intro(self->value));
  }
  CHECK(55, write_cstyle(self->mvar->typename));
  if (!self->mvar->mtype->is_primitive) {
    CHECK(57, write(&(String){2, 1, "*"}));
  }
  CHECK(58, write(&(String){2, 1, " "}));
  CHECK(59, write_cstyle(self->mvar->name));
  Bool _Bool11;
  CHECK(60, (*((Func**)(self)))[7](self, &(_Bool11)))
  if (_Bool11) {
    CHECK(61, write(&(String){4, 3, " = "}));
    if (self->mvar->mtype == glob->type_string) {
      CHECK(63, (*((Func**)(self)))[10](self));
    }
    else {
      if (self->mvar->mtype == glob->type_array) {
        if (!(NULL != self->mvar->sub_typename)) {
          CHECK(66, f_syntax_error(&(String){22, 21, "Array type missing in"}, self->mvar->name));
        }
        CHECK(67, (*((Func**)(self)))[11](self));
      }
      else {
        if (self->mvar->mtype->is_primitive) {
          CHECK(69, (*((Func**)(self)))[8](self));
        }
        else {
          Bool _Bool12;
          CHECK(70, (*((Func**)(self)))[12](self, &(_Bool12)))
          if (!_Bool12) {
            CHECK(71, (*((Func**)(self)))[9](self));
            if (NULL != self->mvar->mtype->dynamic_members) {
              CHECK(73, St_dec_write_to_dtl(self));
              CHECK(74, write_cstyle(self->mvar->mtype->name));
              CHECK(75, write(&(String){7, 6, "__dtl;"}));
            }
          }
        }
      }
    }
  }
  else {
    if (NULL != self->value) {
      CHECK(78, write(&(String){4, 3, " = "}));
      CHECK(79, Mexp_write_final(self->value));
    }
    CHECK(80, write(&(String){2, 1, ";"}));
  }
  if (NULL != glob->mclass) {
    CHECK(82, write(&(String){2, 1, "\n"}));
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
  CHECK(119, St_dec_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze_first = "St-var.analyze-first";
#define MR_FUNC_NAME _func_name_St_var_analyze_first
Returncode St_var_analyze_first(St_var* self) {
  CHECK(122, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze = "St-var.analyze";
#define MR_FUNC_NAME _func_name_St_var_analyze
Returncode St_var_analyze(St_var* self) {
  CHECK(125, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write = "St-var.write";
#define MR_FUNC_NAME _func_name_St_var_write
Returncode St_var_write(St_var* self) {
  CHECK(128, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_array = "St-var.parse-array";
#define MR_FUNC_NAME _func_name_St_var_parse_array
Returncode St_var_parse_array(St_var* self) {
  Char _Char13;
  CHECK(131, read_new(&(String){2, 1, ":"}, &(self->arr_length), &(_Char13)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_string = "St-var.parse-string";
#define MR_FUNC_NAME _func_name_St_var_parse_string
Returncode St_var_parse_string(St_var* self) {
  Char _Char14;
  CHECK(134, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char14)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_as = "St-var.parse-as";
#define MR_FUNC_NAME _func_name_St_var_parse_as
Returncode St_var_parse_as(St_var* self) {
  CHECK(137, f_syntax_error(&(String){22, 21, "illegal variable type"}, &(String){3, 2, "As"}));
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
  RAISE(143)
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_class = "St-var.write-class";
#define MR_FUNC_NAME _func_name_St_var_write_class
Returncode St_var_write_class(St_var* self) {
  /* Class* name = &(Class){0}; */
  CHECK(147, write(&(String){3, 2, "&("}));
  CHECK(148, write_cstyle(self->_base.mvar->typename));
  CHECK(149, write(&(String){6, 5, "){0};"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_string = "St-var.write-string";
#define MR_FUNC_NAME _func_name_St_var_write_string
Returncode St_var_write_string(St_var* self) {
  /* String* name = &(String){length, 0, (char[length]){0}}; */
  /* CHECK(line-num, String_copy(name, init)); */
  if (!(NULL != self->str_length)) {
    CHECK(155, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base.mvar->name));
  }
  CHECK(156, write(&(String){11, 10, "&(String){"}));
  CHECK(157, write(self->str_length));
  CHECK(158, write(&(String){12, 11, ", 0, (char["}));
  CHECK(159, write(self->str_length));
  CHECK(160, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->_base.value) {
    CHECK(162, write_new_indent_line());
    CHECK(163, write_tb_check());
    CHECK(164, write(&(String){13, 12, "String_copy("}));
    CHECK(165, write_cstyle(self->_base.mvar->name));
    CHECK(166, write(&(String){3, 2, ", "}));
    CHECK(167, Mexp_write_final(self->_base.value));
    CHECK(168, write(&(String){3, 2, "))"}));
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
    CHECK(175, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base.mvar->name));
  }
  CHECK(176, write(&(String){10, 9, "&(Array){"}));
  CHECK(177, write(self->arr_length));
  CHECK(178, write(&(String){4, 3, ", ("}));
  CHECK(179, write_cstyle(self->_base.mvar->sub_typename));
  CHECK(180, write(&(String){2, 1, "["}));
  CHECK(181, write(self->arr_length));
  CHECK(182, write(&(String){8, 7, "]){0}};"}));
  if (NULL != self->str_length) {
    CHECK(184, write_new_indent_line());
    CHECK(185, write(&(String){23, 22, "_set_var_string_array("}));
    CHECK(186, write(self->arr_length));
    CHECK(187, write(&(String){3, 2, ", "}));
    CHECK(188, write(self->str_length));
    CHECK(189, write(&(String){3, 2, ", "}));
    CHECK(190, write_cstyle(self->_base.mvar->name));
    CHECK(191, write(&(String){9, 8, ", (char["}));
    CHECK(192, write(self->str_length));
    CHECK(193, write(&(String){4, 3, " * "}));
    CHECK(194, write(self->arr_length));
    CHECK(195, write(&(String){8, 7, "]){0});"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write_as = "St-var.write-as";
#define MR_FUNC_NAME _func_name_St_var_write_as
Returncode St_var_write_as(St_var* self, Bool* is_as) {
  CHECK(198, St_dec_write_as(&(self->_base), &((*is_as))));
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
  CHECK(203, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_USER;
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze_first = "St-ref.analyze-first";
#define MR_FUNC_NAME _func_name_St_ref_analyze_first
Returncode St_ref_analyze_first(St_ref* self) {
  CHECK(207, St_dec_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze = "St-ref.analyze";
#define MR_FUNC_NAME _func_name_St_ref_analyze
Returncode St_ref_analyze(St_ref* self) {
  CHECK(210, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write = "St-ref.write";
#define MR_FUNC_NAME _func_name_St_ref_write
Returncode St_ref_write(St_ref* self) {
  CHECK(213, St_dec_write(&(self->_base)));
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
  CHECK(219, f_syntax_error(&(String){31, 30, "unexpected parameter to String"}, &(String){1, 0, ""}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_as = "St-ref.parse-as";
#define MR_FUNC_NAME _func_name_St_ref_parse_as
Returncode St_ref_parse_as(St_ref* self) {
  CHECK(222, f_syntax_error(&(String){23, 22, "illegal reference type"}, &(String){3, 2, "As"}));
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
  RAISE(228)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_class = "St-ref.write-class";
#define MR_FUNC_NAME _func_name_St_ref_write_class
Returncode St_ref_write_class(St_ref* self) {
  RAISE(231)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_string = "St-ref.write-string";
#define MR_FUNC_NAME _func_name_St_ref_write_string
Returncode St_ref_write_string(St_ref* self) {
  RAISE(234)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_array = "St-ref.write-array";
#define MR_FUNC_NAME _func_name_St_ref_write_array
Returncode St_ref_write_array(St_ref* self) {
  RAISE(237)
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write_as = "St-ref.write-as";
#define MR_FUNC_NAME _func_name_St_ref_write_as
Returncode St_ref_write_as(St_ref* self, Bool* is_as) {
  CHECK(240, St_dec_write_as(&(self->_base), &((*is_as))));
  return OK;
}
#undef MR_FUNC_NAME
Func St_ref__dtl[] = {St_ref_parse, St_ref_analyze_first, St_ref_analyze, St_ref_write, St_ref_parse_array, St_ref_parse_string, St_ref_parse_as, St_ref_m_is_allocation, St_ref_write_primitive, St_ref_write_class, St_ref_write_string, St_ref_write_array, St_ref_write_as};


typedef struct St_new St_new; struct St_new {
  St_var _base;
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
  CHECK(252, St_var_parse(&(self->_base)));
  self->_base._base.mvar->access = ACCESS_OWNER;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze_first = "St-new.analyze-first";
#define MR_FUNC_NAME _func_name_St_new_analyze_first
Returncode St_new_analyze_first(St_new* self) {
  CHECK(256, St_var_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze = "St-new.analyze";
#define MR_FUNC_NAME _func_name_St_new_analyze
Returncode St_new_analyze(St_new* self) {
  if (NULL != self->_base._base.value) {
    CHECK(260, f_syntax_error(&(String){21, 20, "cannot initialize in"}, &(String){4, 3, "new"}));
  }
  if (NULL != self->str_length) {
    CHECK(262, Mexp_analyze_type(self->str_length, glob->type_int));
  }
  if (NULL != self->arr_length) {
    CHECK(264, Mexp_analyze_type(self->arr_length, glob->type_int));
  }
  if (NULL != self->as_type) {
    self->_base._base.mvar->mtype = NULL;
    CHECK(267, Mexp_analyze_get_subtype(self->as_type, glob->type_type, &(self->_base._base.mvar->mtype)));
    if (!(NULL != self->_base._base.mvar->mtype)) {
      CHECK(269, f_syntax_error(&(String){20, 19, "no subtype for type"}, self->_base._base.mvar->name));
    }
    self->_base._base.mvar->typename = self->_base._base.mvar->mtype->name;
  }
  CHECK(271, St_var_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write = "St-new.write";
#define MR_FUNC_NAME _func_name_St_new_write
Returncode St_new_write(St_new* self) {
  CHECK(274, St_var_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_array = "St-new.parse-array";
#define MR_FUNC_NAME _func_name_St_new_parse_array
Returncode St_new_parse_array(St_new* self) {
  Char _Char15;
  CHECK(277, parse_new_exp(&(String){2, 1, ":"}, &(self->arr_length), &(_Char15)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_string = "St-new.parse-string";
#define MR_FUNC_NAME _func_name_St_new_parse_string
Returncode St_new_parse_string(St_new* self) {
  Char _Char16;
  CHECK(280, parse_new_exp(&(String){2, 1, "}"}, &(self->str_length), &(_Char16)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_as = "St-new.parse-as";
#define MR_FUNC_NAME _func_name_St_new_parse_as
Returncode St_new_parse_as(St_new* self) {
  Char _Char17;
  CHECK(283, parse_new_exp(&(String){2, 1, "}"}, &(self->as_type), &(_Char17)));
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
  CHECK(290, write_new_indent_line());
  CHECK(291, write(&(String){5, 4, "if ("}));
  CHECK(292, write_cstyle(self->_base._base.mvar->name));
  CHECK(293, write(&(String){11, 10, " == NULL) "}));
  CHECK(294, write_tb_raise());
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_primitive = "St-new.write-primitive";
#define MR_FUNC_NAME _func_name_St_new_write_primitive
Returncode St_new_write_primitive(St_new* self) {
  CHECK(297, f_syntax_error(&(String){33, 32, "new not supported for primitive "}, self->_base._base.mvar->name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_class = "St-new.write-class";
#define MR_FUNC_NAME _func_name_St_new_write_class
Returncode St_new_write_class(St_new* self) {
  /* Class* name = malloc(sizeof(Class)); */
  CHECK(301, write(&(String){15, 14, "malloc(sizeof("}));
  CHECK(302, write_cstyle(self->_base._base.mvar->typename));
  CHECK(303, write(&(String){4, 3, "));"}));
  CHECK(304, St_new_write_check(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_string = "St-new.write-string";
#define MR_FUNC_NAME _func_name_St_new_write_string
Returncode St_new_write_string(St_new* self) {
  /* String* name = _new_string(length); */
  if (!(NULL != self->str_length)) {
    CHECK(309, f_syntax_error(&(String){25, 24, "String length missing in"}, self->_base._base.mvar->name));
  }
  CHECK(310, Mexp_write_intro(self->str_length));
  CHECK(311, write(&(String){13, 12, "_new_string("}));
  CHECK(312, Mexp_write_final(self->str_length));
  CHECK(313, write(&(String){3, 2, ");"}));
  CHECK(314, St_new_write_check(self));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write_array = "St-new.write-array";
#define MR_FUNC_NAME _func_name_St_new_write_array
Returncode St_new_write_array(St_new* self) {
  /* Array* name = _new_array(length, sizeof(Class)); */
  /* Array* name = _new_array(length, sizeof(String) + (string-length)); */
  /* _set_new_string_array(length, string-length, name); */
  if (!(NULL != self->arr_length)) {
    CHECK(321, f_syntax_error(&(String){24, 23, "Array length missing in"}, self->_base._base.mvar->name));
  }
  CHECK(322, Mexp_write_intro(self->arr_length));
  if (NULL != self->str_length) {
    CHECK(324, Mexp_write_intro(self->str_length));
  }
  CHECK(325, write(&(String){12, 11, "_new_array("}));
  CHECK(326, Mexp_write_final(self->arr_length));
  CHECK(327, write(&(String){10, 9, ", sizeof("}));
  CHECK(328, write_cstyle(self->_base._base.mvar->sub_typename));
  if (NULL != self->str_length) {
    CHECK(330, write(&(String){6, 5, ") + ("}));
    CHECK(331, Mexp_write_final(self->str_length));
  }
  CHECK(332, write(&(String){4, 3, "));"}));
  CHECK(333, St_new_write_check(self));
  if (NULL != self->str_length) {
    CHECK(335, write_new_indent_line());
    CHECK(336, write(&(String){23, 22, "_set_new_string_array("}));
    CHECK(337, Mexp_write_final(self->arr_length));
    CHECK(338, write(&(String){3, 2, ", "}));
    CHECK(339, Mexp_write_final(self->str_length));
    CHECK(340, write(&(String){3, 2, ", "}));
    CHECK(341, write_cstyle(self->_base._base.mvar->name));
    CHECK(342, write(&(String){3, 2, ");"}));
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
  /* Type* name = malloc((as-type).size); */
  CHECK(349, Mexp_write_intro(self->as_type));
  CHECK(350, write(&(String){9, 8, "malloc(("}));
  CHECK(351, Mexp_write_final(self->as_type));
  CHECK(352, write(&(String){9, 8, ").size);"}));
  CHECK(353, St_new_write_check(self));
  if (NULL != self->_base._base.mvar->mtype->dynamic_members) {
    CHECK(355, St_dec_write_to_dtl(&(self->_base._base)));
    CHECK(356, write(&(String){2, 1, "("}));
    CHECK(357, Mexp_write_final(self->as_type));
    CHECK(358, write(&(String){7, 6, ").dtl;"}));
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
  Char _Char18;
  CHECK(366, read_new(&(String){1, 0, ""}, &(self->name), &(_Char18)));
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
  CHECK(373, m_find_var(self->name, &(self->mvar)))
  if (!(NULL != self->mvar)) {
    CHECK(374, f_syntax_error(&(String){16, 15, "unknow variable"}, self->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_write = "St-delete.write";
#define MR_FUNC_NAME _func_name_St_delete_write
Returncode St_delete_write(St_delete* self) {
  CHECK(377, write(&(String){6, 5, "free("}));
  CHECK(378, write_cstyle(self->name));
  CHECK(379, write(&(String){3, 2, ");"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_delete__dtl[] = {St_delete_parse, St_delete_analyze_first, St_delete_analyze, St_delete_write};

#undef MR_FILE_NAME
