static char* _mr_file13_name = "type.2.lm";
#define LUMI_FILE_NAME _mr_file13_name
/* TL3 compiler - types */

static char* _func_name_analyze_type = "analyze-type";
#define LUMI_FUNC_NAME _func_name_analyze_type
Returncode analyze_type(Mtype* self, Bool is_dynamic) {
  if (NULL != self->base_typename && !(NULL != self->base_mtype)) {
    CHECK(5, f_find_type(self->base_typename, &(self->base_mtype)));
  }
  if (is_dynamic && !(NULL != self->dynamic_members)) {
    CHECK(7, f_copy_new_var_map(NULL, &(self->dynamic_members)));
    Int dynamic_count = 0;
    Var_map_iter* iter = &(Var_map_iter){0};
    String* name;
    Mvar* mvar;
    if (NULL != self->base_mtype) {
      CHECK(13, analyze_type(self->base_mtype, is_dynamic));
      CHECK(14, Var_map_iter_init(iter, self->base_mtype->dynamic_members));
      while (true) {
        Bool _Bool0;
        CHECK(16, Var_map_iter_m_has_data(iter, &(_Bool0)))
        if (!(_Bool0)) break;
        CHECK(17, Var_map_iter_get_name(iter, &(name)));
        CHECK(18, Var_map_find(self->members, name, &(mvar)));
        if (NULL != mvar) {
          if (!(NULL != mvar->func_dec)) {
            CHECK(21, f_syntax_error2(&(String){25, 24, "non-function override of"}, name, &(String){8, 7, "in type"}, self->name));
          }
          CHECK(22, Var_map_add(self->dynamic_members, name, mvar));
          mvar->func_dec->dynamic_index = dynamic_count;
        }
        else {
          Mvar* _Mvar1;
          CHECK(25, Var_map_iter_get_var(iter, &(_Mvar1)))
          CHECK(25, Var_map_add(self->dynamic_members, name, _Mvar1));
        }
        dynamic_count = dynamic_count + 1;
        CHECK(27, Var_map_iter_m_next(iter));
      }
    }
    CHECK(28, Var_map_iter_init(iter, self->members));
    while (true) {
      Bool _Bool2;
      CHECK(30, Var_map_iter_m_has_data(iter, &(_Bool2)))
      if (!(_Bool2)) break;
      CHECK(31, Var_map_iter_get_name(iter, &(name)));
      CHECK(32, Var_map_iter_get_var(iter, &(mvar)));
      Mvar* _Mvar3;
      CHECK(33, Var_map_find(self->dynamic_members, name, &(_Mvar3)))
      if (NULL != mvar->func_dec && mvar->func_dec->is_dynamic && !(NULL != _Mvar3)) {
        CHECK(34, Var_map_add(self->dynamic_members, name, mvar));
        mvar->func_dec->dynamic_index = dynamic_count;
        dynamic_count = dynamic_count + 1;
      }
      CHECK(37, Var_map_iter_m_next(iter));
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME


typedef struct St_class St_class; struct St_class {
  St_node _base;
  Mtype* mtype;
  Int depth;
};
static char* _func_name_St_class_parse = "St-class.parse";
#define LUMI_FUNC_NAME _func_name_St_class_parse
Returncode St_class_parse(St_class* self) {
  String* name = &(String){128, 0, (char[128]){0}};
  Char end;
  CHECK(47, read(&(String){3, 2, "({"}, name, &(end)));
  CHECK(48, Type_map_add(glob->type_map, name, &(self->mtype)));
  if (end == '{') {
    Mtype* generic_mtype = malloc(sizeof(Mtype));
    if (generic_mtype == NULL) RAISE(50)
    String* _String4;
    CHECK(51, f_new_copy(&(String){5, 4, "void"}, &(_String4)))
    CHECK(51, Mtype_init(generic_mtype, _String4));
    Char _Char5;
    CHECK(52, read_new(&(String){2, 1, "}"}, &(generic_mtype->base_typename), &(_Char5)));
    self->mtype->generic_mtype = generic_mtype;
    CHECK(54, read_c(&(end)));
  }
  if (end == '(') {
    Char _Char6;
    CHECK(56, read_new(&(String){2, 1, ")"}, &(self->mtype->base_typename), &(_Char6)));
    Char _Char7;
    CHECK(57, read_c(&(_Char7)));
  }
  self->depth = 0;
  glob->generic_mtype = self->mtype->generic_mtype;
  glob->mclass = self->mtype;
  CHECK(61, St_node_parse(&(self->_base)));
  glob->mclass = NULL;
  glob->generic_mtype = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_class_analyze_first = "St-class.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_class_analyze_first
Returncode St_class_analyze_first(St_class* self) {
  CHECK(66, analyze_type(self->mtype, false));
  glob->generic_mtype = self->mtype->generic_mtype;
  glob->mclass = self->mtype;
  CHECK(69, St_node_analyze_first(&(self->_base)));
  glob->mclass = NULL;
  glob->generic_mtype = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_class_analyze = "St-class.analyze";
#define LUMI_FUNC_NAME _func_name_St_class_analyze
Returncode St_class_analyze(St_class* self) {
  Mtype* basetype = self->mtype->base_mtype;
  while (true) {
    if (!(NULL != basetype)) break;
    self->depth = self->depth + 1;
    basetype = basetype->base_mtype;
  }
  if (self->depth > glob->max_type_depth) {
    glob->max_type_depth = self->depth;
  }
  glob->generic_mtype = self->mtype->generic_mtype;
  glob->mclass = self->mtype;
  CHECK(83, St_node_analyze(&(self->_base)));
  glob->mclass = NULL;
  glob->generic_mtype = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
Returncode St_class_write_vars(St_class* self);
Returncode St_class_write_meths(St_class* self);
static char* _func_name_St_class_write = "St-class.write";
#define LUMI_FUNC_NAME _func_name_St_class_write
Returncode St_class_write(St_class* self) {
  /* #ifdef LUMI_TYPEDEFS */
  /* typedef struct name name; */
  /* #elif defined LUMI_TYPES */
  /* struct name { */
  /*   members... */
  /* }; */
  /* #endif */
  /* methods... */
  CHECK(99, write(&(String){33, 32, "#if LUMI_STAGE == LUMI_TYPEDEFS\n"}));
  CHECK(100, write_spaces());
  CHECK(101, write(&(String){16, 15, "typedef struct "}));
  CHECK(102, write_cstyle(self->mtype->name));
  CHECK(103, write(&(String){2, 1, " "}));
  CHECK(104, write_cstyle(self->mtype->name));
  CHECK(105, write(&(String){3, 2, ";\n"}));
  CHECK(106, write_spaces());
  CHECK(107, write(&(String){32, 31, "#elif LUMI_STAGE == LUMI_TYPES("}));
  CHECK(108, write_int(self->depth));
  CHECK(109, write(&(String){3, 2, ")\n"}));
  CHECK(110, write_spaces());
  CHECK(111, write(&(String){8, 7, "struct "}));
  CHECK(112, write_cstyle(self->mtype->name));
  CHECK(113, write(&(String){4, 3, " {\n"}));
  CHECK(114, (*((Func**)(self)))[4](self));
  CHECK(115, write(&(String){3, 2, ";\n"}));
  CHECK(116, write_spaces());
  CHECK(117, write(&(String){7, 6, "#endif"}));
  CHECK(118, (*((Func**)(self)))[5](self));
  glob->methods = false;
  glob->mclass = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_class_write_vars = "St-class.write-vars";
#define LUMI_FUNC_NAME _func_name_St_class_write_vars
Returncode St_class_write_vars(St_class* self) {
  if (NULL != self->mtype->base_typename) {
    CHECK(124, write_spaces());
    CHECK(125, write(&(String){3, 2, "  "}));
    CHECK(126, write_cstyle(self->mtype->base_typename));
    CHECK(127, write(&(String){9, 8, " _base;\n"}));
  }
  glob->mclass = self->mtype;
  glob->methods = false;
  CHECK(130, St_node_write_indent_block(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_class_write_meths = "St-class.write-meths";
#define LUMI_FUNC_NAME _func_name_St_class_write_meths
Returncode St_class_write_meths(St_class* self) {
  glob->methods = true;
  CHECK(134, St_node_write_block(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_class__dtl[] = {St_class_parse, St_class_analyze_first, St_class_analyze, St_class_write, St_class_write_vars, St_class_write_meths};


typedef struct St_static_class St_static_class; struct St_static_class {
  St_class _base;
};
static char* _func_name_St_static_class_parse = "St-static-class.parse";
#define LUMI_FUNC_NAME _func_name_St_static_class_parse
Returncode St_static_class_parse(St_static_class* self) {
  CHECK(139, St_class_parse(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_static_class_analyze_first = "St-static-class.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_static_class_analyze_first
Returncode St_static_class_analyze_first(St_static_class* self) {
  CHECK(141, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_static_class_analyze = "St-static-class.analyze";
#define LUMI_FUNC_NAME _func_name_St_static_class_analyze
Returncode St_static_class_analyze(St_static_class* self) {
  CHECK(143, St_class_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_static_class_write = "St-static-class.write";
#define LUMI_FUNC_NAME _func_name_St_static_class_write
Returncode St_static_class_write(St_static_class* self) {
  CHECK(145, St_class_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_static_class_write_vars = "St-static-class.write-vars";
#define LUMI_FUNC_NAME _func_name_St_static_class_write_vars
Returncode St_static_class_write_vars(St_static_class* self) {
  CHECK(147, St_class_write_vars(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_static_class_write_meths = "St-static-class.write-meths";
#define LUMI_FUNC_NAME _func_name_St_static_class_write_meths
Returncode St_static_class_write_meths(St_static_class* self) {
  CHECK(149, St_class_write_meths(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_static_class__dtl[] = {St_static_class_parse, St_static_class_analyze_first, St_static_class_analyze, St_static_class_write, St_static_class_write_vars, St_static_class_write_meths};


typedef struct St_dynamic_class St_dynamic_class; struct St_dynamic_class {
  St_class _base;
};
static char* _func_name_St_dynamic_class_parse = "St-dynamic-class.parse";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_parse
Returncode St_dynamic_class_parse(St_dynamic_class* self) {
  CHECK(154, St_class_parse(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze_first = "St-dynamic-class.analyze-first";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_analyze_first
Returncode St_dynamic_class_analyze_first(St_dynamic_class* self) {
  CHECK(157, analyze_type(self->_base.mtype, true));
  CHECK(158, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze = "St-dynamic-class.analyze";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_analyze
Returncode St_dynamic_class_analyze(St_dynamic_class* self) {
  CHECK(161, St_class_analyze(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dynamic_class_write = "St-dynamic-class.write";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_write
Returncode St_dynamic_class_write(St_dynamic_class* self) {
  CHECK(164, St_class_write(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dynamic_class_write_vars = "St-dynamic-class.write-vars";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_write_vars
Returncode St_dynamic_class_write_vars(St_dynamic_class* self) {
  if (!(NULL != self->_base.mtype->base_typename)) {
    CHECK(168, write_spaces());
    CHECK(169, write(&(String){15, 14, "  Func* _dtl;\n"}));
  }
  CHECK(170, St_class_write_vars(&(self->_base)));
  return OK;
}
#undef LUMI_FUNC_NAME
static char* _func_name_St_dynamic_class_write_meths = "St-dynamic-class.write-meths";
#define LUMI_FUNC_NAME _func_name_St_dynamic_class_write_meths
Returncode St_dynamic_class_write_meths(St_dynamic_class* self) {
  CHECK(173, St_class_write_meths(&(self->_base)));
  /* #if LUMI_STAGE == LUMI_DECLARATIONS */
  /* extern Func {name}__dtl[]; */
  /* #endif */
  /* #if LUMI_STAGE == LUMI_FUNCTIONS */
  /* Func {name}__dtl[] = {funcs...}; */
  /* #endif */
  CHECK(180, write_new_indent_line());
  CHECK(181, write(&(String){37, 36, "#if LUMI_STAGE == LUMI_DECLARATIONS\n"}));
  CHECK(182, write(&(String){13, 12, "extern Func "}));
  CHECK(183, write_cstyle(self->_base.mtype->name));
  CHECK(184, write(&(String){10, 9, "__dtl[];\n"}));
  CHECK(185, write_spaces());
  CHECK(186, write(&(String){8, 7, "#endif\n"}));
  CHECK(187, write_spaces());
  CHECK(188, write(&(String){34, 33, "#if LUMI_STAGE == LUMI_FUNCTIONS\n"}));
  CHECK(189, write_spaces());
  CHECK(190, write(&(String){6, 5, "Func "}));
  CHECK(191, write_cstyle(self->_base.mtype->name));
  CHECK(192, write(&(String){12, 11, "__dtl[] = {"}));
  Var_map_iter* iter = &(Var_map_iter){0};
  CHECK(194, Var_map_iter_init(iter, self->_base.mtype->dynamic_members));
  while (true) {
    Bool _Bool8;
    CHECK(196, Var_map_iter_m_has_data(iter, &(_Bool8)))
    if (!(_Bool8)) break;
    Mvar* mvar;
    CHECK(198, Var_map_iter_get_var(iter, &(mvar)));
    if (!(NULL != mvar->func_dec)) {
      CHECK(200, f_syntax_error(self->_base.mtype->name, mvar->name));
    }
    if (!(NULL != mvar->func_dec->mclass)) {
      CHECK(202, f_syntax_error(self->_base.mtype->name, mvar->name));
    }
    CHECK(203, write(&(String){8, 7, "(void*)"}));
    CHECK(204, write_cstyle(mvar->func_dec->mclass->name));
    CHECK(205, write(&(String){2, 1, "_"}));
    CHECK(206, write_cstyle(mvar->func_dec->name));
    CHECK(207, Var_map_iter_m_next(iter));
    Bool _Bool9;
    CHECK(208, Var_map_iter_m_has_data(iter, &(_Bool9)))
    if (_Bool9) {
      CHECK(209, write(&(String){3, 2, ", "}));
    }
  }
  CHECK(210, write(&(String){4, 3, "};\n"}));
  CHECK(211, write_spaces());
  CHECK(212, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef LUMI_FUNC_NAME
Func St_dynamic_class__dtl[] = {St_dynamic_class_parse, St_dynamic_class_analyze_first, St_dynamic_class_analyze, St_dynamic_class_write, St_dynamic_class_write_vars, St_dynamic_class_write_meths};

#undef LUMI_FILE_NAME
