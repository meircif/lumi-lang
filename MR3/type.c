static char* _mr_file9_name = "type.2.mr";
#define MR_FILE_NAME _mr_file9_name
/* MR3 compiler - types */

static char* _func_name_analyze_type = "analyze-type";
#define MR_FUNC_NAME _func_name_analyze_type
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
#undef MR_FUNC_NAME


typedef struct St_class St_class; struct St_class {
  St_node _base;
  Mtype* mtype;
  Int depth;
};
static char* _func_name_St_class_parse = "St-class.parse";
#define MR_FUNC_NAME _func_name_St_class_parse
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
  glob->mclass = self->mtype;
  CHECK(60, St_node_parse(&(self->_base)));
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_analyze_first = "St-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_class_analyze_first
Returncode St_class_analyze_first(St_class* self) {
  CHECK(64, analyze_type(self->mtype, false));
  glob->mclass = self->mtype;
  CHECK(66, St_node_analyze_first(&(self->_base)));
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_analyze = "St-class.analyze";
#define MR_FUNC_NAME _func_name_St_class_analyze
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
  glob->mclass = self->mtype;
  CHECK(78, St_node_analyze(&(self->_base)));
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
Returncode St_class_write_vars(St_class* self);
Returncode St_class_write_meths(St_class* self);
static char* _func_name_St_class_write = "St-class.write";
#define MR_FUNC_NAME _func_name_St_class_write
Returncode St_class_write(St_class* self) {
  /* #ifdef MR_TYPEDEFS */
  /* typedef struct name name; */
  /* #elif defined MR_TYPES */
  /* struct name { */
  /*   members... */
  /* }; */
  /* #endif */
  /* methods... */
  CHECK(93, write(&(String){29, 28, "#if MR_STAGE == MR_TYPEDEFS\n"}));
  CHECK(94, write_spaces());
  CHECK(95, write(&(String){16, 15, "typedef struct "}));
  CHECK(96, write_cstyle(self->mtype->name));
  CHECK(97, write(&(String){2, 1, " "}));
  CHECK(98, write_cstyle(self->mtype->name));
  CHECK(99, write(&(String){3, 2, ";\n"}));
  CHECK(100, write_spaces());
  CHECK(101, write(&(String){28, 27, "#elif MR_STAGE == MR_TYPES("}));
  CHECK(102, write_int(self->depth));
  CHECK(103, write(&(String){3, 2, ")\n"}));
  CHECK(104, write_spaces());
  CHECK(105, write(&(String){8, 7, "struct "}));
  CHECK(106, write_cstyle(self->mtype->name));
  CHECK(107, write(&(String){4, 3, " {\n"}));
  CHECK(108, (*((Func**)(self)))[4](self));
  CHECK(109, write(&(String){3, 2, ";\n"}));
  CHECK(110, write_spaces());
  CHECK(111, write(&(String){7, 6, "#endif"}));
  CHECK(112, (*((Func**)(self)))[5](self));
  glob->methods = false;
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_write_vars = "St-class.write-vars";
#define MR_FUNC_NAME _func_name_St_class_write_vars
Returncode St_class_write_vars(St_class* self) {
  if (NULL != self->mtype->base_typename) {
    CHECK(118, write_spaces());
    CHECK(119, write(&(String){3, 2, "  "}));
    CHECK(120, write_cstyle(self->mtype->base_typename));
    CHECK(121, write(&(String){9, 8, " _base;\n"}));
  }
  glob->mclass = self->mtype;
  glob->methods = false;
  CHECK(124, St_node_write_indent_block(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_write_meths = "St-class.write-meths";
#define MR_FUNC_NAME _func_name_St_class_write_meths
Returncode St_class_write_meths(St_class* self) {
  glob->methods = true;
  CHECK(128, St_node_write_block(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_class__dtl[] = {St_class_parse, St_class_analyze_first, St_class_analyze, St_class_write, St_class_write_vars, St_class_write_meths};


typedef struct St_static_class St_static_class; struct St_static_class {
  St_class _base;
};
static char* _func_name_St_static_class_parse = "St-static-class.parse";
#define MR_FUNC_NAME _func_name_St_static_class_parse
Returncode St_static_class_parse(St_static_class* self) {
  CHECK(133, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_analyze_first = "St-static-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_static_class_analyze_first
Returncode St_static_class_analyze_first(St_static_class* self) {
  CHECK(135, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_analyze = "St-static-class.analyze";
#define MR_FUNC_NAME _func_name_St_static_class_analyze
Returncode St_static_class_analyze(St_static_class* self) {
  CHECK(137, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_write = "St-static-class.write";
#define MR_FUNC_NAME _func_name_St_static_class_write
Returncode St_static_class_write(St_static_class* self) {
  CHECK(139, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_write_vars = "St-static-class.write-vars";
#define MR_FUNC_NAME _func_name_St_static_class_write_vars
Returncode St_static_class_write_vars(St_static_class* self) {
  CHECK(141, St_class_write_vars(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_write_meths = "St-static-class.write-meths";
#define MR_FUNC_NAME _func_name_St_static_class_write_meths
Returncode St_static_class_write_meths(St_static_class* self) {
  CHECK(143, St_class_write_meths(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_static_class__dtl[] = {St_static_class_parse, St_static_class_analyze_first, St_static_class_analyze, St_static_class_write, St_static_class_write_vars, St_static_class_write_meths};


typedef struct St_dynamic_class St_dynamic_class; struct St_dynamic_class {
  St_class _base;
};
static char* _func_name_St_dynamic_class_parse = "St-dynamic-class.parse";
#define MR_FUNC_NAME _func_name_St_dynamic_class_parse
Returncode St_dynamic_class_parse(St_dynamic_class* self) {
  CHECK(148, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze_first = "St-dynamic-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_dynamic_class_analyze_first
Returncode St_dynamic_class_analyze_first(St_dynamic_class* self) {
  CHECK(151, analyze_type(self->_base.mtype, true));
  CHECK(152, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze = "St-dynamic-class.analyze";
#define MR_FUNC_NAME _func_name_St_dynamic_class_analyze
Returncode St_dynamic_class_analyze(St_dynamic_class* self) {
  CHECK(155, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_write = "St-dynamic-class.write";
#define MR_FUNC_NAME _func_name_St_dynamic_class_write
Returncode St_dynamic_class_write(St_dynamic_class* self) {
  CHECK(158, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_write_vars = "St-dynamic-class.write-vars";
#define MR_FUNC_NAME _func_name_St_dynamic_class_write_vars
Returncode St_dynamic_class_write_vars(St_dynamic_class* self) {
  if (!(NULL != self->_base.mtype->base_typename)) {
    CHECK(162, write_spaces());
    CHECK(163, write(&(String){15, 14, "  Func* _dtl;\n"}));
  }
  CHECK(164, St_class_write_vars(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_write_meths = "St-dynamic-class.write-meths";
#define MR_FUNC_NAME _func_name_St_dynamic_class_write_meths
Returncode St_dynamic_class_write_meths(St_dynamic_class* self) {
  CHECK(167, St_class_write_meths(&(self->_base)));
  CHECK(168, write_new_indent_line());
  CHECK(169, write(&(String){33, 32, "#if MR_STAGE == MR_DECLARATIONS\n"}));
  CHECK(170, write_spaces());
  CHECK(171, write(&(String){6, 5, "Func "}));
  CHECK(172, write_cstyle(self->_base.mtype->name));
  CHECK(173, write(&(String){12, 11, "__dtl[] = {"}));
  Var_map_iter* iter = &(Var_map_iter){0};
  CHECK(175, Var_map_iter_init(iter, self->_base.mtype->dynamic_members));
  while (true) {
    Bool _Bool8;
    CHECK(177, Var_map_iter_m_has_data(iter, &(_Bool8)))
    if (!(_Bool8)) break;
    Mvar* mvar;
    CHECK(179, Var_map_iter_get_var(iter, &(mvar)));
    if (!(NULL != mvar->func_dec)) {
      CHECK(181, f_syntax_error(self->_base.mtype->name, mvar->name));
    }
    if (!(NULL != mvar->func_dec->mclass)) {
      CHECK(183, f_syntax_error(self->_base.mtype->name, mvar->name));
    }
    CHECK(184, write_cstyle(mvar->func_dec->mclass->name));
    CHECK(185, write(&(String){2, 1, "_"}));
    CHECK(186, write_cstyle(mvar->func_dec->name));
    CHECK(187, Var_map_iter_m_next(iter));
    Bool _Bool9;
    CHECK(188, Var_map_iter_m_has_data(iter, &(_Bool9)))
    if (_Bool9) {
      CHECK(189, write(&(String){3, 2, ", "}));
    }
  }
  CHECK(190, write(&(String){4, 3, "};\n"}));
  CHECK(191, write_spaces());
  CHECK(192, write(&(String){7, 6, "#endif"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_dynamic_class__dtl[] = {St_dynamic_class_parse, St_dynamic_class_analyze_first, St_dynamic_class_analyze, St_dynamic_class_write, St_dynamic_class_write_vars, St_dynamic_class_write_meths};

#undef MR_FILE_NAME
