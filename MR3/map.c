static char* _mr_file2_name = "map.2.mr";
#define MR_FILE_NAME _mr_file2_name
/* MR3 compiler - attribute mappings */

/* String List */
typedef struct String_list String_list; struct String_list {
  String_list* next;
  String* value;
};


/* Name Map */
typedef struct Name_map_node Name_map_node; struct Name_map_node {
  Name_map_node* next;
  String* name;
  Object* value;
};
static char* _func_name_Name_map_node_init = "Name-map-node.init";
#define MR_FUNC_NAME _func_name_Name_map_node_init
Returncode Name_map_node_init(Name_map_node* self, String* name, Object* value) {
  self->next = NULL;
  self->name = name;
  self->value = value;
  return OK;
}
#undef MR_FUNC_NAME

typedef struct Name_map Name_map; struct Name_map {
  Name_map_node* first;
  Name_map_node* last;
};
static char* _func_name_Name_map_init = "Name-map.init";
#define MR_FUNC_NAME _func_name_Name_map_init
Returncode Name_map_init(Name_map* self) {
  self->first = NULL;
  self->last = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Name_map_add = "Name-map.add";
#define MR_FUNC_NAME _func_name_Name_map_add
Returncode Name_map_add(Name_map* self, String* name, Object* value) {
  Name_map_node* node = malloc(sizeof(Name_map_node));
  if (node == NULL) RAISE(29)
  CHECK(30, Name_map_node_init(node, name, value));
  if (NULL != self->last) {
    self->last->next = node;
  }
  else {
    self->first = node;
  }
  self->last = node;
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
    CHECK(41, String_equal(node->name, name, &(_Bool0)))
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
    CHECK(51, Sys_print(sys, node->name));
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
  CHECK(63, Name_map_add(&(self->_base), name, value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_find = "Var-map.find";
#define MR_FUNC_NAME _func_name_Var_map_find
Returncode Var_map_find(Var_map* self, String* name, Mvar** mvar) {
  Object* _Object1;
  CHECK(66, Name_map_find(&(self->_base), name, &(_Object1)))
  (*mvar) = _Object1;
  return OK;
}
#undef MR_FUNC_NAME

typedef struct Var_map_iter Var_map_iter; struct Var_map_iter {
  Name_map_node* node;
};
static char* _func_name_Var_map_iter_init = "Var-map-iter.init";
#define MR_FUNC_NAME _func_name_Var_map_iter_init
Returncode Var_map_iter_init(Var_map_iter* self, Var_map* map) {
  self->node = map->_base.first;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_iter_get_name = "Var-map-iter.get-name";
#define MR_FUNC_NAME _func_name_Var_map_iter_get_name
Returncode Var_map_iter_get_name(Var_map_iter* self, String** name) {
  (*name) = self->node->name;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_iter_get_var = "Var-map-iter.get-var";
#define MR_FUNC_NAME _func_name_Var_map_iter_get_var
Returncode Var_map_iter_get_var(Var_map_iter* self, Mvar** mvar) {
  Mvar* value = self->node->value;
  (*mvar) = value;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_iter_m_has_data = "Var-map-iter.m-has-data";
#define MR_FUNC_NAME _func_name_Var_map_iter_m_has_data
Returncode Var_map_iter_m_has_data(Var_map_iter* self, Bool* has_data) {
  (*has_data) = NULL != self->node;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Var_map_iter_m_next = "Var-map-iter.m-next";
#define MR_FUNC_NAME _func_name_Var_map_iter_m_next
Returncode Var_map_iter_m_next(Var_map_iter* self) {
  self->node = self->node->next;
  return OK;
}
#undef MR_FUNC_NAME


static char* _func_name_f_copy_new_var_map = "f-copy-new-var-map";
#define MR_FUNC_NAME _func_name_f_copy_new_var_map
Returncode f_copy_new_var_map(Var_map* other, Var_map** new_var_map) {
  Var_map* var_map = malloc(sizeof(Var_map));
  if (var_map == NULL) RAISE(89)
  if (NULL != other) {
    CHECK(91, Var_map_m_copy_from(var_map, other));
  }
  else {
    CHECK(93, Name_map_init(&(var_map->_base)));
  }
  (*new_var_map) = var_map;
  return OK;
}
#undef MR_FUNC_NAME


typedef struct Mtype Mtype; struct Mtype {
  String* name;
  Var_map* members;
  Var_map* dynamic_members;
  String* base_typename;
  Mtype* base_mtype;
  Mtype* generic_mtype;
  String* default_value;
  Bool is_primitive;
};
static char* _func_name_Mtype_init = "Mtype.init";
#define MR_FUNC_NAME _func_name_Mtype_init
Returncode Mtype_init(Mtype* self, String* name) {
  self->name = name;
  CHECK(109, f_copy_new_var_map(NULL, &(self->members)));
  self->dynamic_members = NULL;
  self->base_typename = NULL;
  self->base_mtype = NULL;
  self->generic_mtype = NULL;
  self->default_value = NULL;
  self->is_primitive = false;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mtype_set_primitive = "Mtype.set-primitive";
#define MR_FUNC_NAME _func_name_Mtype_set_primitive
Returncode Mtype_set_primitive(Mtype* self, String* default_value) {
  self->is_primitive = true;
  CHECK(119, f_new_copy(default_value, &(self->default_value)));
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
  self->typename = NULL;
  self->mtype = mtype;
  self->sub_typename = NULL;
  self->sub_mtype = NULL;
  self->func_dec = NULL;
  self->access = ACCESS_VAR;
  self->is_ref = false;
  if (NULL != mtype) {
    CHECK(151, f_new_copy(mtype->name, &(self->typename)));
    if (NULL != mtype->generic_mtype) {
      CHECK(153, f_new_copy(mtype->generic_mtype->name, &(self->sub_typename)));
      self->sub_mtype = mtype->generic_mtype;
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Mvar_analyze = "Mvar.analyze";
#define MR_FUNC_NAME _func_name_Mvar_analyze
Returncode Mvar_analyze(Mvar* self) {
  if (!(NULL != self->mtype)) {
    CHECK(158, f_find_type(self->typename, &(self->mtype)));
  }
  if (NULL != self->sub_typename && !(NULL != self->sub_mtype)) {
    CHECK(160, f_find_type(self->sub_typename, &(self->sub_mtype)));
  }
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_init_new_var = "init-new-var";
#define MR_FUNC_NAME _func_name_init_new_var
Returncode init_new_var(Mtype* mtype, Mvar** new_mvar) {
  Mvar* mvar = malloc(sizeof(Mvar));
  if (mvar == NULL) RAISE(163)
  CHECK(164, Mvar_init(mvar, mtype));
  (*new_mvar) = mvar;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_add_var = "add-var";
#define MR_FUNC_NAME _func_name_add_var
Returncode add_var(Var_map* map, Mvar* mvar) {
  CHECK(168, Var_map_add(map, mvar->name, mvar));
  return OK;
}
#undef MR_FUNC_NAME


/* Operator Map */
typedef struct Op_map Op_map; struct Op_map {
  Name_map _base;
};
static char* _func_name_Op_map_add = "Op-map.add";
#define MR_FUNC_NAME _func_name_Op_map_add
Returncode Op_map_add(Op_map* self, String* name, String* ctext) {
  String* new_name;
  CHECK(175, f_new_copy(name, &(new_name)));
  String* new_text;
  CHECK(177, f_new_copy(ctext, &(new_text)));
  Object* value = new_text;
  CHECK(179, Name_map_add(&(self->_base), new_name, value));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Op_map_add_copy = "Op-map.add-copy";
#define MR_FUNC_NAME _func_name_Op_map_add_copy
Returncode Op_map_add_copy(Op_map* self, String* name) {
  CHECK(182, Op_map_add(self, name, name));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Op_map_find = "Op-map.find";
#define MR_FUNC_NAME _func_name_Op_map_find
Returncode Op_map_find(Op_map* self, String* name, String** ctext) {
  Object* _Object2;
  CHECK(185, Name_map_find(&(self->_base), name, &(_Object2)))
  (*ctext) = _Object2;
  return OK;
}
#undef MR_FUNC_NAME


/* Type Map */
typedef struct Type_map Type_map; struct Type_map {
  Name_map _base;
};
static char* _func_name_Type_map_add = "Type-map.add";
#define MR_FUNC_NAME _func_name_Type_map_add
Returncode Type_map_add(Type_map* self, String* name, Mtype** out_mtype) {
  Mtype* mtype = malloc(sizeof(Mtype));
  if (mtype == NULL) RAISE(191)
  String* new_name;
  CHECK(193, f_new_copy(name, &(new_name)));
  CHECK(194, Mtype_init(mtype, new_name));
  Object* value = mtype;
  CHECK(196, Name_map_add(&(self->_base), new_name, value));
  (*out_mtype) = mtype;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Type_map_find = "Type-map.find";
#define MR_FUNC_NAME _func_name_Type_map_find
Returncode Type_map_find(Type_map* self, String* name, Mtype** mtype) {
  Object* _Object3;
  CHECK(200, Name_map_find(&(self->_base), name, &(_Object3)))
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
