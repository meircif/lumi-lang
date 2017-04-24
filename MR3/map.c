static char* _mr_file2_name = "map.2.mr";
#define MR_FILE_NAME _mr_file2_name
/* MR3 compiler - attribute mappings */

/* Name Map */
typedef struct Name_map_node Name_map_node; struct Name_map_node {
  Name_map_node* next;
  String* name;
  Object* value;
};
static char* _func_name_Name_map_node_init = "Name-map-node.init";
#define MR_FUNC_NAME _func_name_Name_map_node_init
Returncode Name_map_node_init(Name_map_node* self, Name_map_node* next, String* name, Object* value) {
  self->next = next;
  self->name = name;
  self->value = value;
  return OK;
}
#undef MR_FUNC_NAME

typedef struct Name_map Name_map; struct Name_map {
  Name_map_node* first;
};
static char* _func_name_Name_map_init = "Name-map.init";
#define MR_FUNC_NAME _func_name_Name_map_init
Returncode Name_map_init(Name_map* self) {
  self->first = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Name_map_add = "Name-map.add";
#define MR_FUNC_NAME _func_name_Name_map_add
Returncode Name_map_add(Name_map* self, String* name, Object* value) {
  Name_map_node* node = malloc(sizeof(Name_map_node));
  if (node == NULL) RAISE(21)
  CHECK(22, Name_map_node_init(node, self->first, name, value));
  self->first = node;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Name_map_find = "Name-map.find";
#define MR_FUNC_NAME _func_name_Name_map_find
Returncode Name_map_find(Name_map* self, String* name, Object** value) {
  Name_map_node* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool0;
    CHECK(29, String_equal(node->name, name, &(_Bool0)))
    if (_Bool0) {
      (*value) = node->value;
      return OK;
    }
    node = node->next;
  }
  (*value) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Name_map_print = "Name-map.print";
#define MR_FUNC_NAME _func_name_Name_map_print
Returncode Name_map_print(Name_map* self) {
  Name_map_node* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    CHECK(39, Sys_print(sys, node->name));
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Mvar Mvar;

typedef struct Var_map Var_map; struct Var_map {
  Name_map _base;
};
static char* _func_name_Var_map_m_copy_from = "Var-map.m-copy-from";
#define MR_FUNC_NAME _func_name_Var_map_m_copy_from
Returncode Var_map_m_copy_from(Var_map* self, Var_map* other) {
  self->_base.first = other->_base.first;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_add = "Var-map.add";
#define MR_FUNC_NAME _func_name_Var_map_add
Returncode Var_map_add(Var_map* self, String* name, Mvar* mvar) {
  Object* value = mvar;
  CHECK(51, Name_map_add(&(self->_base), name, value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_find = "Var-map.find";
#define MR_FUNC_NAME _func_name_Var_map_find
Returncode Var_map_find(Var_map* self, String* name, Mvar** mvar) {
  Object* _Object1;
  CHECK(54, Name_map_find(&(self->_base), name, &(_Object1)))
  (*mvar) = _Object1;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_f_copy_new_var_map = "f-copy-new-var-map";
#define MR_FUNC_NAME _func_name_f_copy_new_var_map
Returncode f_copy_new_var_map(Var_map* other, Var_map** new_var_map) {
  Var_map* var_map = malloc(sizeof(Var_map));
  if (var_map == NULL) RAISE(57)
  if (NULL != other) {
    CHECK(59, Var_map_m_copy_from(var_map, other));
  }
  else {
    CHECK(61, Name_map_init(&(var_map->_base)));
  }
  (*new_var_map) = var_map;
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Mtype Mtype; struct Mtype {
  String* name;
  Var_map* members;
  String* base_typename;
  Mtype* base_mtype;
  Bool is_dynamic;
  Bool is_primitive;
};
static char* _func_name_Mtype_init = "Mtype.init";
#define MR_FUNC_NAME _func_name_Mtype_init
Returncode Mtype_init(Mtype* self, String* name) {
  self->name = name;
  CHECK(75, f_copy_new_var_map(NULL, &(self->members)));
  self->base_typename = NULL;
  self->base_mtype = NULL;
  self->is_dynamic = false;
  self->is_primitive = false;
  return OK;
}
#undef MR_FUNC_NAME


Int ACCESS_COPY = 0;
Int ACCESS_USER = 1;
Int ACCESS_OWNER = 2;
Int ACCESS_VAR = 3;

typedef struct Mfunc Mfunc;

Returncode f_find_type(String* typename, Mtype** mtype);

typedef struct Mvar Mvar; struct Mvar {
  String* name;
  String* typename;
  Mtype* mtype;
  String* sub_typename;
  Mtype* sub_mtype;
  Mfunc* func_dec;
  Int access;
  Bool is_ref;
};
static char* _func_name_Mvar_init = "Mvar.init";
#define MR_FUNC_NAME _func_name_Mvar_init
Returncode Mvar_init(Mvar* self, Mtype* mtype) {
  self->name = NULL;
  if (NULL != mtype) {
    CHECK(104, f_new_copy(mtype->name, &(self->typename)));
  }
  else {
    self->typename = NULL;
  }
  self->mtype = mtype;
  self->sub_typename = NULL;
  self->sub_mtype = NULL;
  self->func_dec = NULL;
  self->access = ACCESS_VAR;
  self->is_ref = false;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mvar_analyze = "Mvar.analyze";
#define MR_FUNC_NAME _func_name_Mvar_analyze
Returncode Mvar_analyze(Mvar* self) {
  if (!(NULL != self->mtype)) {
    CHECK(116, f_find_type(self->typename, &(self->mtype)));
  }
  if (NULL != self->sub_typename && !(NULL != self->sub_mtype)) {
    CHECK(118, f_find_type(self->sub_typename, &(self->sub_mtype)));
  }
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_init_new_var = "init-new-var";
#define MR_FUNC_NAME _func_name_init_new_var
Returncode init_new_var(Mtype* mtype, Mvar** new_mvar) {
  Mvar* mvar = malloc(sizeof(Mvar));
  if (mvar == NULL) RAISE(121)
  CHECK(122, Mvar_init(mvar, mtype));
  (*new_mvar) = mvar;
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_f_copy_var = "f-copy-var";
#define MR_FUNC_NAME _func_name_f_copy_var
Returncode f_copy_var(Mvar* mvar, String* name, Mvar** new_mvar) {
  CHECK(126, init_new_var(mvar->mtype, &((*new_mvar))));
  CHECK(127, f_new_copy(name, &((*new_mvar)->name)));
  CHECK(128, f_new_copy(mvar->sub_typename, &((*new_mvar)->sub_typename)));
  (*new_mvar)->sub_mtype = mvar->sub_mtype;
  (*new_mvar)->func_dec = mvar->func_dec;
  (*new_mvar)->access = mvar->access;
  (*new_mvar)->is_ref = false;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_add_var = "add-var";
#define MR_FUNC_NAME _func_name_add_var
Returncode add_var(Var_map* map, Mvar* mvar) {
  CHECK(135, Var_map_add(map, mvar->name, mvar));
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Op_map Op_map; struct Op_map {
  Name_map _base;
};
static char* _func_name_Op_map_add = "Op-map.add";
#define MR_FUNC_NAME _func_name_Op_map_add
Returncode Op_map_add(Op_map* self, String* name, String* ctext) {
  String* new_name;
  CHECK(141, f_new_copy(name, &(new_name)));
  String* new_text;
  CHECK(143, f_new_copy(ctext, &(new_text)));
  Object* value = new_text;
  CHECK(145, Name_map_add(&(self->_base), new_name, value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Op_map_add_copy = "Op-map.add-copy";
#define MR_FUNC_NAME _func_name_Op_map_add_copy
Returncode Op_map_add_copy(Op_map* self, String* name) {
  CHECK(148, Op_map_add(self, name, name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Op_map_find = "Op-map.find";
#define MR_FUNC_NAME _func_name_Op_map_find
Returncode Op_map_find(Op_map* self, String* name, String** ctext) {
  Object* _Object2;
  CHECK(151, Name_map_find(&(self->_base), name, &(_Object2)))
  (*ctext) = _Object2;
  return OK;
}
#undef MR_FUNC_NAME

typedef struct Type_map Type_map; struct Type_map {
  Name_map _base;
};
static char* _func_name_Type_map_add = "Type-map.add";
#define MR_FUNC_NAME _func_name_Type_map_add
Returncode Type_map_add(Type_map* self, String* name, Mtype** out_mtype) {
  Mtype* mtype = malloc(sizeof(Mtype));
  if (mtype == NULL) RAISE(155)
  String* new_name;
  CHECK(157, f_new_copy(name, &(new_name)));
  CHECK(158, Mtype_init(mtype, new_name));
  Object* value = mtype;
  CHECK(160, Name_map_add(&(self->_base), new_name, value));
  (*out_mtype) = mtype;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Type_map_find = "Type-map.find";
#define MR_FUNC_NAME _func_name_Type_map_find
Returncode Type_map_find(Type_map* self, String* name, Mtype** mtype) {
  Object* _Object3;
  CHECK(164, Name_map_find(&(self->_base), name, &(_Object3)))
  (*mtype) = _Object3;
  return OK;
}
#undef MR_FUNC_NAME


/* Node Map */
typedef struct St St;

typedef struct Node_map_item Node_map_item; struct Node_map_item {
  String* key;
  Type node_type;
};

#undef MR_FILE_NAME
