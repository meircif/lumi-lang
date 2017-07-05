static char* _mr_file9_name = "member.2.mr";
#define MR_FILE_NAME _mr_file9_name
/* MR3 compiler - member operands */

typedef struct Cast_operand Cast_operand; struct Cast_operand {
  Operand _base;
  Mtype* mtype;
  Operand* operand;
};
static char* _func_name_Cast_operand_parse = "Cast-operand.parse";
#define MR_FUNC_NAME _func_name_Cast_operand_parse
Returncode Cast_operand_parse(Cast_operand* self, String* text, String* ends, Char* end) {
  RAISE(8)
}
#undef MR_FUNC_NAME
static char* _func_name_Cast_operand_analyze = "Cast-operand.analyze";
#define MR_FUNC_NAME _func_name_Cast_operand_analyze
Returncode Cast_operand_analyze(Cast_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  self->mtype = (*mtype);
  self->operand = exp->operand;
  exp->operand = &(self->_base);
  if (NULL != self->_base.next) {
    CHECK(15, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Cast_operand_write_intro = "Cast-operand.write-intro";
#define MR_FUNC_NAME _func_name_Cast_operand_write_intro
Returncode Cast_operand_write_intro(Cast_operand* self) {
  CHECK(18, Operand_write_all_intro(self->operand));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Cast_operand_write_final = "Cast-operand.write-final";
#define MR_FUNC_NAME _func_name_Cast_operand_write_final
Returncode Cast_operand_write_final(Cast_operand* self) {
  /* ((Type*)(operand...)) */
  CHECK(22, write(&(String){3, 2, "(("}));
  CHECK(23, write_cstyle(self->mtype->name));
  CHECK(24, write(&(String){4, 3, "*)("}));
  CHECK(25, Operand_write_all_final(self->operand));
  CHECK(26, write(&(String){3, 2, "))"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Cast_operand__dtl[] = {Cast_operand_parse, Cast_operand_analyze, Cast_operand_write_intro, Cast_operand_write_final};


typedef struct Var_operand Var_operand; struct Var_operand {
  Operand _base;
  String* name;
  Mvar* mvar;
  Int base_count;
  Bool allow_dynamic;
};
static char* _func_name_Var_operand_parse = "Var-operand.parse";
#define MR_FUNC_NAME _func_name_Var_operand_parse
Returncode Var_operand_parse(Var_operand* self, String* text, String* ends, Char* end) {
  self->name = text;
  self->mvar = NULL;
  self->base_count = 0;
  self->allow_dynamic = true;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_operand_analyze = "Var-operand.analyze";
#define MR_FUNC_NAME _func_name_Var_operand_analyze
Returncode Var_operand_analyze(Var_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  CHECK(42, f_find_var(self->name, &(self->mvar)))
  if (!(NULL != self->mvar)) {
    CHECK(43, f_syntax_error(&(String){16, 15, "unknow variable"}, self->name));
  }
  (*mtype) = self->mvar->mtype;
  (*sub_mtype) = self->mvar->sub_mtype;
  if (NULL != self->_base.next) {
    CHECK(47, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), self, &((*mtype)), &((*sub_mtype))));
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
    CHECK(54, write(&(String){3, 2, "(*"}));
  }
  CHECK(55, write_cstyle(self->name));
  if (self->mvar->is_ref) {
    CHECK(57, write(&(String){2, 1, ")"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Var_operand__dtl[] = {Var_operand_parse, Var_operand_analyze, Var_operand_write_intro, Var_operand_write_final};


typedef struct Member_operand Member_operand; struct Member_operand {
  Var_operand _base;
  Mtype* prev_mtype;
};
static char* _func_name_Member_operand_parse = "Member-operand.parse";
#define MR_FUNC_NAME _func_name_Member_operand_parse
Returncode Member_operand_parse(Member_operand* self, String* text, String* ends, Char* end) {
  self->_base.base_count = 0;
  self->_base.allow_dynamic = true;
  CHECK(66, read_new_value(ends, &(self->_base.name), &((*end))));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Member_operand_analyze = "Member-operand.analyze";
#define MR_FUNC_NAME _func_name_Member_operand_analyze
Returncode Member_operand_analyze(Member_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  if (!(NULL != (*mtype))) {
    CHECK(70, f_syntax_error(&(String){20, 19, "member with no type"}, self->_base.name));
  }
  self->prev_mtype = (*mtype);
  while (true) {
    CHECK(73, Var_map_find((*mtype)->members, self->_base.name, &(self->_base.mvar)))
    if (!(!(NULL != self->_base.mvar))) break;
    (*mtype) = (*mtype)->base_mtype;
    if (!(NULL != (*mtype))) {
      CHECK(76, f_syntax_error2(&(String){5, 4, "type"}, self->prev_mtype->name, &(String){14, 13, "has no member"}, self->_base.name));
    }
    self->_base.base_count = self->_base.base_count + 1;
  }
  self->prev_mtype = (*mtype);
  Mtype* prev_sub_mtype = (*sub_mtype);
  Mtype* basetype = (*mtype)->base_mtype;
  if (NULL != (*mtype)->generic_mtype && (*mtype)->generic_mtype == self->_base.mvar->mtype) {
    (*mtype) = (*sub_mtype);
    (*sub_mtype) = NULL;
    if ((NULL != exp->operator || NULL != self->_base._base.next) && (*mtype) != self->_base.mvar->mtype) {
      Cast_operand* cast = malloc(sizeof(Cast_operand));
      if (cast == NULL) RAISE(85)
      *((Func**)(cast)) = Cast_operand__dtl;
      cast->_base.next = self->_base._base.next;
      self->_base._base.next = NULL;
      CHECK(88, (*((Func**)(cast)))[1](cast, exp, NULL, NULL, &((*mtype)), &((*sub_mtype))));
    }
    else {
      if ((*mtype) != self->_base.mvar->mtype && !(NULL != self->_base._base.next)) {
        exp->is_used = false;
      }
    }
  }
  else {
    if (NULL != (*mtype)->generic_mtype && (*mtype)->generic_mtype == self->_base.mvar->sub_mtype) {
      (*mtype) = self->_base.mvar->mtype;
      /* sub-mtype is the same */
    }
    else {
      (*mtype) = self->_base.mvar->mtype;
      (*sub_mtype) = self->_base.mvar->sub_mtype;
    }
  }
  if (NULL != self->_base._base.next) {
    if (NULL != self->_base.mvar->func_dec && NULL != member) {
      if (self->_base.mvar->func_dec->is_dynamic && self->_base.allow_dynamic) {
        while (true) {
          if (!(NULL != basetype)) break;
          self->_base.base_count = self->_base.base_count + 1;
          basetype = basetype->base_mtype;
        }
      }
      (*mtype) = self->prev_mtype;
      (*sub_mtype) = prev_sub_mtype;
      CHECK(106, (*((Func**)(self->_base._base.next)))[1](self->_base._base.next, exp, member, &(self->_base), &((*mtype)), &((*sub_mtype))));
    }
    else {
      CHECK(108, (*((Func**)(self->_base._base.next)))[1](self->_base._base.next, exp, &(self->_base._base), &(self->_base), &((*mtype)), &((*sub_mtype))));
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
    CHECK(115, write_cstyle(self->prev_mtype->name));
    CHECK(116, write(&(String){2, 1, "_"}));
  }
  else {
    CHECK(118, write(&(String){3, 2, "->"}));
    Int n; for (n = 0; n < self->_base.base_count; ++n) {
      CHECK(120, write(&(String){7, 6, "_base."}));
    }
  }
  CHECK(121, Var_operand_write_final(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func Member_operand__dtl[] = {Member_operand_parse, Member_operand_analyze, Member_operand_write_intro, Member_operand_write_final};


typedef struct Base_meth_operand Base_meth_operand; struct Base_meth_operand {
  Operand _base;
  Member_operand* member;
  Bool first;
};
static char* _func_name_Base_meth_operand_parse = "Base-meth-operand.parse";
#define MR_FUNC_NAME _func_name_Base_meth_operand_parse
Returncode Base_meth_operand_parse(Base_meth_operand* self, String* text, String* ends, Char* end) {
  free(text);
  Member_operand* member = malloc(sizeof(Member_operand));
  if (member == NULL) RAISE(130)
  *((Func**)(member)) = Member_operand__dtl;
  self->member = member;
  CHECK(132, (*((Func**)(self->member)))[0](self->member, NULL, ends, &((*end))));
  self->member->_base._base.next = NULL;
  self->member->_base.allow_dynamic = false;
  if ((*end) != '(') {
    CHECK(136, f_syntax_error(&(String){13, 12, "not a method"}, self->member->_base.mvar->name));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Base_meth_operand_analyze = "Base-meth-operand.analyze";
#define MR_FUNC_NAME _func_name_Base_meth_operand_analyze
Returncode Base_meth_operand_analyze(Base_meth_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  (*sub_mtype) = NULL;
  self->first = !(NULL != member);
  if (self->first) {
    Mvar* mvar;
    CHECK(143, f_find_var(&(String){5, 4, "self"}, &(mvar)))
    if (!(NULL != mvar)) {
      CHECK(144, f_syntax_error(&(String){25, 24, "not a method, cannot use"}, &(String){5, 4, "base"}));
    }
    (*mtype) = mvar->mtype;
  }
  if (!(NULL != (*mtype)->base_mtype)) {
    CHECK(147, f_syntax_error(&(String){20, 19, "no subtype for type"}, (*mtype)->name));
  }
  (*mtype) = (*mtype)->base_mtype;
  CHECK(149, (*((Func**)(self->member)))[1](self->member, exp, &(self->_base), NULL, &((*mtype)), &((*sub_mtype))));
  self->member->_base.base_count = self->member->_base.base_count + 1;
  CHECK(151, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, &(self->_base), &(self->member->_base), &((*mtype)), &((*sub_mtype))));
  self->member = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Base_meth_operand_write_intro = "Base-meth-operand.write-intro";
#define MR_FUNC_NAME _func_name_Base_meth_operand_write_intro
Returncode Base_meth_operand_write_intro(Base_meth_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Base_meth_operand_write_final = "Base-meth-operand.write-final";
#define MR_FUNC_NAME _func_name_Base_meth_operand_write_final
Returncode Base_meth_operand_write_final(Base_meth_operand* self) {
  if (self->first) {
    CHECK(159, write(&(String){5, 4, "self"}));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func Base_meth_operand__dtl[] = {Base_meth_operand_parse, Base_meth_operand_analyze, Base_meth_operand_write_intro, Base_meth_operand_write_final};


typedef struct Type_operand Type_operand; struct Type_operand {
  Operand _base;
  String* name;
  Mtype* mtype;
};
static char* _func_name_Type_operand_parse = "Type-operand.parse";
#define MR_FUNC_NAME _func_name_Type_operand_parse
Returncode Type_operand_parse(Type_operand* self, String* text, String* ends, Char* end) {
  self->name = text;
  self->mtype = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Type_operand_analyze = "Type-operand.analyze";
#define MR_FUNC_NAME _func_name_Type_operand_analyze
Returncode Type_operand_analyze(Type_operand* self, Mexp* exp, Operand* member, Var_operand* method, Mtype** mtype, Mtype** sub_mtype) {
  CHECK(171, f_find_type(self->name, &((*mtype))));
  if (NULL != self->_base.next) {
    (*sub_mtype) = NULL;
    exp->operand = self->_base.next;
    CHECK(175, (*((Func**)(self->_base.next)))[1](self->_base.next, exp, member, method, &((*mtype)), &((*sub_mtype))));
    free(self);
  }
  else {
    self->mtype = (*mtype);
    (*mtype) = glob->type_type;
    (*sub_mtype) = self->mtype;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Type_operand_write_intro = "Type-operand.write-intro";
#define MR_FUNC_NAME _func_name_Type_operand_write_intro
Returncode Type_operand_write_intro(Type_operand* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Type_operand_write_final = "Type-operand.write-final";
#define MR_FUNC_NAME _func_name_Type_operand_write_final
Returncode Type_operand_write_final(Type_operand* self) {
  /* (Type){sizeof(name), name__dtl} */
  CHECK(187, write(&(String){8, 7, "(Type){"}));
  CHECK(188, write_type_type_params(self->mtype));
  CHECK(189, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
Func Type_operand__dtl[] = {Type_operand_parse, Type_operand_analyze, Type_operand_write_intro, Type_operand_write_final};

#undef MR_FILE_NAME
