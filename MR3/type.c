static char* _mr_file9_name = "type.2.mr";
#define MR_FILE_NAME _mr_file9_name
/* MR3 compiler - types */

typedef struct St_class St_class; struct St_class {
  St_node _base;
  Mtype* mtype;
};
static char* _func_name_St_class_parse = "St-class.parse";
#define MR_FUNC_NAME _func_name_St_class_parse
Returncode St_class_parse(St_class* self) {
  String* name = &(String){128, 0, (char[128]){0}};
  Char _Char0;
  CHECK(8, read(&(String){2, 1, "("}, name, &(_Char0)));
  CHECK(9, Type_map_add(glob->type_map, name, &(self->mtype)));
  String* base_typename = &(String){128, 0, (char[128]){0}};
  Char _Char1;
  CHECK(11, read(&(String){2, 1, ")"}, base_typename, &(_Char1)));
  Bool _Bool2;
  CHECK(12, String_equal(base_typename, &(String){7, 6, "Object"}, &(_Bool2)))
  if (!_Bool2) {
    CHECK(13, f_new_copy(base_typename, &(self->mtype->base_typename)));
  }
  Char _Char3;
  CHECK(14, read_c(&(_Char3)));
  glob->mclass = self->mtype;
  CHECK(16, St_node_parse(&(self->_base)));
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_analyze_first = "St-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_class_analyze_first
Returncode St_class_analyze_first(St_class* self) {
  if (NULL != self->mtype->base_typename) {
    CHECK(21, f_find_type(self->mtype->base_typename, &(self->mtype->base_mtype)));
  }
  CHECK(22, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_analyze = "St-class.analyze";
#define MR_FUNC_NAME _func_name_St_class_analyze
Returncode St_class_analyze(St_class* self) {
  CHECK(25, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_write = "St-class.write";
#define MR_FUNC_NAME _func_name_St_class_write
Returncode St_class_write(St_class* self) {
  CHECK(28, write(&(String){16, 15, "typedef struct "}));
  CHECK(29, write_cstyle(self->mtype->name));
  CHECK(30, write(&(String){2, 1, " "}));
  CHECK(31, write_cstyle(self->mtype->name));
  CHECK(32, write(&(String){3, 2, ";\n"}));
  CHECK(33, write_spaces());
  CHECK(34, write(&(String){8, 7, "struct "}));
  CHECK(35, write_cstyle(self->mtype->name));
  glob->mclass = self->mtype;
  glob->methods = false;
  CHECK(38, St_node_write(&(self->_base)));
  CHECK(39, write(&(String){2, 1, ";"}));
  glob->methods = true;
  CHECK(41, St_node_write_block(&(self->_base)));
  glob->methods = false;
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
Func St_class__dtl[] = {St_class_parse, St_class_analyze_first, St_class_analyze, St_class_write};


typedef struct St_static_class St_static_class; struct St_static_class {
  St_class _base;
};
static char* _func_name_St_static_class_parse = "St-static-class.parse";
#define MR_FUNC_NAME _func_name_St_static_class_parse
Returncode St_static_class_parse(St_static_class* self) {
  CHECK(48, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_analyze_first = "St-static-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_static_class_analyze_first
Returncode St_static_class_analyze_first(St_static_class* self) {
  CHECK(50, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_analyze = "St-static-class.analyze";
#define MR_FUNC_NAME _func_name_St_static_class_analyze
Returncode St_static_class_analyze(St_static_class* self) {
  CHECK(52, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_write = "St-static-class.write";
#define MR_FUNC_NAME _func_name_St_static_class_write
Returncode St_static_class_write(St_static_class* self) {
  CHECK(54, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_static_class__dtl[] = {St_static_class_parse, St_static_class_analyze_first, St_static_class_analyze, St_static_class_write};


typedef struct St_dynamic_class St_dynamic_class; struct St_dynamic_class {
  St_class _base;
};
static char* _func_name_St_dynamic_class_parse = "St-dynamic-class.parse";
#define MR_FUNC_NAME _func_name_St_dynamic_class_parse
Returncode St_dynamic_class_parse(St_dynamic_class* self) {
  CHECK(59, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze_first = "St-dynamic-class.analyze-first";
#define MR_FUNC_NAME _func_name_St_dynamic_class_analyze_first
Returncode St_dynamic_class_analyze_first(St_dynamic_class* self) {
  CHECK(61, St_class_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze = "St-dynamic-class.analyze";
#define MR_FUNC_NAME _func_name_St_dynamic_class_analyze
Returncode St_dynamic_class_analyze(St_dynamic_class* self) {
  CHECK(63, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_write = "St-dynamic-class.write";
#define MR_FUNC_NAME _func_name_St_dynamic_class_write
Returncode St_dynamic_class_write(St_dynamic_class* self) {
  CHECK(65, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_dynamic_class__dtl[] = {St_dynamic_class_parse, St_dynamic_class_analyze_first, St_dynamic_class_analyze, St_dynamic_class_write};

#undef MR_FILE_NAME
