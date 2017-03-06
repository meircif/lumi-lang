#include "mr.1.h"

/* MR2 compiler - written in MR1 */

Returncode print(String* text);

typedef void File;
Returncode file_open_read(String* name, File** file);
Returncode file_open_write(String* name, File** file);
Returncode file_close(File* self);
Returncode file_getc(File* self, Char* ch);
Returncode file_putc(File* self, Char ch);
Returncode file_write(File* self, String* line);

Returncode string_clear(String* self);
Returncode string_length(String* self, Int* length);
Returncode string_equal(String* self, String* other, Bool* equal);
Returncode string_get(String* self, Int index, Char* ch);
Returncode string_append(String* self, Char ch);
Returncode string_copy(String* self, String* source);
Returncode string_concat(String* self, String* ext);
Returncode string_find(String* self, String* pattern, Int* index);
Returncode string_replace(String* self, Char old_ch, Char new_ch);
Returncode string_has(String* self, Char ch, Bool* found);
Returncode int_to_string(Int self, String* string);

Returncode array_length(Array* arr, Int* length);

Returncode sys_exit(Int status);
Returncode sys_system(String* command, Int* status);
Returncode sys_getenv(String* name, Bool* exists, String* value);


typedef void Generic;


Returncode f_new_copy(String* text, String** out_text) {
  if (text == NULL) {
    RAISE
  }
  String* new_text = new_string(text->actual_length + 1); if (new_text == NULL) RAISE
  CHECK(string_copy(new_text, text))
  *out_text = new_text;
  return OK;
}
/* raising */
Returncode f_msg_raise(String* prefix, String* middle, String* suffix) {
  String* msg = &(String){256, 0, (char[256]){0}};
  CHECK(string_copy(msg, prefix))
  CHECK(string_concat(msg, middle))
  CHECK(string_concat(msg, suffix))
  CHECK(print(msg))
  RAISE
}
Returncode f_raise_on_null(Generic* ref, String* prefix, String* middle, String* suffix) {
  if (ref == NULL) {
    CHECK(f_msg_raise(prefix, middle, suffix))
  }
  return OK;
}
/* Function Map */
typedef struct Func_map Func_map; struct Func_map {
  String* key;
  Func f_value;
};
Returncode add_fm(Array* map, Int index, String* key, Func f_value) {
  Func_map* fm = &(Func_map){0};
  if (index < 0 || index >= map->length) RAISE fm = ((Func_map*)(map->values)) + index;
  CHECK(f_new_copy(key, &fm->key))
  fm->f_value = f_value;
  return OK;
}
Returncode f_fm_find(Array* map, String* key, Func* f_value, Bool* found) {
  Int n; for (n = 0; n < map->length; ++n) {
    Func_map* fm = &(Func_map){0};
    if (n < 0 || n >= map->length) RAISE fm = ((Func_map*)(map->values)) + n;
    Bool flag;
    CHECK(string_equal(key, fm->key, &flag)) if (flag) {
      *found = true;
      *f_value = fm->f_value;
      return OK;
    }
  }
  *found = false;
  return OK;
}
/* Name Map */
typedef struct Name_map Name_map; struct Name_map {
  Name_map* next;
  String* name;
  Generic* value;
};
typedef struct Type_attrs Type_attrs; struct Type_attrs {
  String* name;
  Name_map* members;
  Type_attrs* base_type;
  Bool is_dynamic;
};
typedef struct Var_attrs Var_attrs; struct Var_attrs {
  String* name;
  Type_attrs* type_attrs;
  Generic* subtype;
  String* access;
  Bool is_ref;
};
Returncode f_nm_init(String* name, Generic* value, Name_map** nm_ptr) {
  Name_map* nm = malloc(sizeof(Name_map)); if (nm == NULL) RAISE
  nm->next = nm_ptr[0];
  nm->name = name;
  nm->value = value;
  *nm_ptr = nm;
  return OK;
}
Returncode f_nm_find(Name_map* self, String* name, Generic** value) {
  Name_map* nm = self;
  while (true) {
    if (not(nm != NULL)) break;
    Bool equal;
    CHECK(string_equal(nm->name, name, &equal)) if (equal) {
      *value = nm->value;
      return OK;
    }
    nm = nm->next;
  }
  *value = NULL;
  return OK;
}
Returncode f_nm_print(Name_map* self) {
  Name_map* nm = self;
  while (true) {
    if (not(nm != NULL)) break;
    CHECK(print(nm->name))
    nm = nm->next;
  }
  return OK;
}
Returncode add_member(String* name, Type_attrs* type_attrs, Generic* subtype, Name_map** members) {
  Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
  CHECK(f_new_copy(name, &new_var->name))
  new_var->type_attrs = type_attrs;
  new_var->subtype = subtype;
  new_var->is_ref = false;
  CHECK(f_nm_init(new_var->name, new_var, members))
  return OK;
}
/* Syntax Tree */
typedef struct St St; struct St {
  St* next_brother;
  St* first_son;
  St* last_son;
  St* father;
  Func f_writer;
  Generic* value;
  Name_map* var_map;
  Int line_num;
};
Returncode f_st_del(St* self) {
  if (self == NULL) {
    return OK;
  }
  CHECK(f_st_del(self->first_son))
  CHECK(f_st_del(self->next_brother))
  free(self);
  return OK;
}
/* Global data */
typedef struct St_class St_class; struct St_class {
  Type_attrs* type_attrs;
  Int dynamic_count;
};
typedef struct Global_data Global_data; struct Global_data {
  /* data */
  File* infile;
  File* outfile;
  Array* key_word_map;
  Name_map* op_map;
  Name_map* type_map;
  Name_map* var_map;
  /* state */
  St* curr;
  Int spaces;
  St_class* st_class;
  Int var_count;
  Int line_num;
  /* vars */
  Int length;
  Bool flag;
  Char end;
};
Global_data* glob = &(Global_data){0};

Returncode f_st_new(Func f_writer, Generic* value, St* father, St** res) {
  St* self = malloc(sizeof(St)); if (self == NULL) RAISE
  self->next_brother = NULL;
  self->first_son = NULL;
  self->last_son = NULL;
  self->father = father;
  self->f_writer = f_writer;
  self->value = value;
  self->line_num = glob->line_num;
  *res = self;
  if (father != NULL) {
    if (father->first_son == NULL) {
      father->first_son = self;
    }
    else {
      father->last_son->next_brother = self;
    }
    father->last_son = self;
    self->var_map = father->var_map;
  }
  else {
    self->var_map = glob->var_map;
  }
  return OK;
}
Returncode f_find_type(String* name, Type_attrs** type_attr) {
  Generic* value;
  CHECK(f_nm_find(glob->type_map, name, &value))
  CHECK(f_raise_on_null(value, &(String){17, 16, "Undefined type \""}, name, &(String){2, 1, "\""}))
  *type_attr = value;
  return OK;
}
Returncode add_type(String* name, String* base_name, Name_map* members) {
  Type_attrs* new_type = malloc(sizeof(Type_attrs)); if (new_type == NULL) RAISE
  CHECK(f_new_copy(name, &new_type->name))
  new_type->members = members;
  new_type->base_type = NULL;
  new_type->is_dynamic = false;
  if (base_name != NULL) {
    CHECK(f_find_type(base_name, &new_type->base_type))
  }
  Name_map* nm = malloc(sizeof(Name_map)); if (nm == NULL) RAISE
  CHECK(f_nm_init(new_type->name, new_type, &glob->type_map))
  return OK;
}
Returncode f_find_var(Name_map* nm, String* name, Var_attrs** var_attr) {
  Generic* value;
  CHECK(f_nm_find(nm, name, &value))
  CHECK(f_raise_on_null(value, &(String){21, 20, "Undefined variable \""}, name, &(String){2, 1, "\""}))
  *var_attr = value;
  return OK;
}
/* read helpers */
Returncode read_c(Char* out_ch) {
  Char ch;
  CHECK(file_getc(glob->infile, &ch))
  if (ch == '\n') {
    glob->line_num = glob->line_num + 1;
  }
  *out_ch = ch;
  return OK;
}
Returncode read_ignore(Int chars) {
  Int n; for (n = 0; n < chars; ++n) {
    CHECK(read_c(&glob->end))
  }
  return OK;
}
Returncode read_indent(String* ends, Bool indent, String* text, Char* end, Int* out_spaces) {
  CHECK(string_clear(text))
  Char ch = EOF;
  Char q = '\0';
  Int spaces = 0;
  while (true) {
    /* ignore indent */
    CHECK(read_c(&ch))
    if (indent) {
      while (true) {
        if (not(ch == ' ')) break;
        spaces = spaces + 1;
        CHECK(read_c(&ch))
      }
      indent = false;
    }
    if (not(ch != EOF)) break;
    if (q != '\0') {
      if (ch == '\\') {
        CHECK(string_append(text, ch))
        CHECK(read_c(&ch))
      }
      else if (ch == q) {
        q = '\0';
      }
    }
    else {
      if (not(ch != '\n')) break;
      CHECK(string_has(ends, ch, &glob->flag)) if (not(glob->flag == false)) break;
      if (ch == '\'' or ch == '"') {
        q = ch;
      }
    }
    CHECK(string_append(text, ch))
  }
  *end = ch;
  *out_spaces = spaces;
  return OK;
}
Returncode read(String* ends, String* text, Char* end) {
  Int spaces = 0;
  CHECK(read_indent(ends, false, text, end, &spaces))
  return OK;
}
Returncode read_new(String* ends, String** out_text, Char* end) {
  String* text = &(String){256, 0, (char[256]){0}};
  CHECK(read(ends, text, end))
  CHECK(f_new_copy(text, out_text))
  return OK;
}
/* write helpers */
Returncode write_c(Char ch) {
  CHECK(file_putc(glob->outfile, ch))
  return OK;
}
Returncode write(String* text) {
  CHECK(file_write(glob->outfile, text))
  return OK;
}
Returncode write_cstyle(String* text) {
  if (text == NULL) {
    RAISE
  }
  Int index; for (index = 0; index < text->actual_length; ++index) {
    Char ch;
    CHECK(string_get(text, index, &ch))
    if (ch == '-') {
      CHECK(write_c('_'))
    }
    else {
      CHECK(write_c(ch))
    }
  }
  return OK;
}
Returncode write_line_num() {
  String* line_num_str = &(String){64, 0, (char[64]){0}};
  CHECK(int_to_string(glob->curr->line_num, line_num_str))
  CHECK(write(line_num_str))
  return OK;
}
Returncode write_tb_raise() {
  CHECK(write(&(String){7, 6, "RAISE("}))
  CHECK(write_line_num())
  CHECK(write(&(String){2, 1, ")"}))
  return OK;
}
Returncode write_tb_check() {
  CHECK(write(&(String){7, 6, "CHECK("}))
  CHECK(write_line_num())
  CHECK(write(&(String){3, 2, ", "}))
  return OK;
}
/* other helpers */
Returncode add_node(Func f_writer, Generic* value) {
  St* node;
  CHECK(f_st_new(f_writer, value, glob->curr, &node))
  return OK;
}
Returncode string_split(String* text, Char sep, Int* index, Int* length) {
  CHECK(string_has(text, sep, &glob->flag)) if (glob->flag) {
    String* sep_str = &(String){2, 0, (char[2]){0}};
    CHECK(string_append(sep_str, sep))
    Int sep_index;
    CHECK(string_find(text, sep_str, &sep_index))
    *index = sep_index;
    *length = text->actual_length - sep_index - 1;
  }
  else {
    *index = text->actual_length;
    *length = 0;
  }
  return OK;
}
Returncode f_is_primitive(String* typename, Bool* res) {
  Bool flag;
  CHECK(string_equal(typename, &(String){4, 3, "Int"}, &flag)) if (flag) {
    *res = true;
    return OK;
  }
  CHECK(string_equal(typename, &(String){5, 4, "Char"}, &flag)) if (flag) {
    *res = true;
    return OK;
  }
  CHECK(string_equal(typename, &(String){5, 4, "Func"}, &flag)) if (flag) {
    *res = true;
    return OK;
  }
  CHECK(string_equal(typename, &(String){5, 4, "Bool"}, &flag))
  *res = flag;
  return OK;
}
/* block helpers */
Returncode write_spaces() {
  Int n; for (n = 0; n < glob->spaces; ++n) {
    CHECK(write(&(String){2, 1, " "}))
  }
  return OK;
}
Returncode write_new_indent_line() {
  CHECK(write(&(String){2, 1, "\n"}))
  CHECK(write_spaces())
  return OK;
}
Returncode write_sons() {
  St* son = glob->curr->first_son;
  while (true) {
    if (not(son != NULL)) break;
    glob->curr = son;
    CHECK(write_spaces())
    CHECK(son->f_writer(son->value))
    son = glob->curr->next_brother;
    glob->curr = glob->curr->father;
  }
  return OK;
}
Returncode f_start_block() {
  glob->spaces = glob->spaces + 2;
  glob->curr = glob->curr->last_son;
  return OK;
}
Returncode f_end_block() {
  glob->curr = glob->curr->father;
  glob->spaces = glob->spaces - 2;
  if (glob->spaces == 0) {
    glob->st_class = NULL;
  }
  return OK;
}
Returncode write_block_close() {
  glob->spaces = glob->spaces - 2;
  CHECK(write_spaces())
  CHECK(write(&(String){2, 1, "}"}))
  return OK;
}
Returncode write_block() {
  CHECK(write(&(String){4, 3, " {\n"}))
  glob->spaces = glob->spaces + 2;
  CHECK(write_sons())
  CHECK(write_block_close())
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
/* empty */
Returncode write_empty_line(Generic* null) {
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode add_empty_line() {
  CHECK(add_node(write_empty_line, NULL))
  return OK;
}
/* comment */
Returncode write_comment(String* comment_text) {
  CHECK(write(&(String){4, 3, "/* "}))
  CHECK(write(comment_text))
  CHECK(write(&(String){5, 4, " */\n"}))
  return OK;
}
Returncode parse_comment() {
  String* comment;
  CHECK(read_new(&(String){1, 0, ""}, &comment, &glob->end))
  CHECK(add_node(write_comment, comment))
  return OK;
}
/* member path */
typedef struct Member_path Member_path; struct Member_path {
  Member_path* next;
  String* name;
};
Returncode read_mpath(String* ends, Member_path** mem_path, Char* end) {
  Member_path* new_mem_path = malloc(sizeof(Member_path)); if (new_mem_path == NULL) RAISE
  Member_path* mpath = new_mem_path;
  while (true) {
    mpath->next = NULL;
    CHECK(read_new(ends, &mpath->name, &glob->end)) if (not(glob->end == '.')) break;
    Member_path* new_mpath = malloc(sizeof(Member_path)); if (new_mpath == NULL) RAISE
    mpath->next = new_mpath;
    mpath = new_mpath;
  }
  *mem_path = new_mem_path;
  *end = glob->end;
  return OK;
}
Returncode f_mpath_attrs(Member_path* mem_path, Var_attrs** ret_var_attrs) {
  *ret_var_attrs = NULL;
  Member_path* mpath = mem_path;
  Var_attrs* var_attrs;
  CHECK(f_find_var(glob->curr->var_map, mpath->name, &var_attrs))
  while (true) {
    mpath = mpath->next;
    if (not(mpath != NULL)) break;
    Type_attrs* type_attrs = var_attrs->type_attrs;
    while (true) {
      Generic* value;
      CHECK(f_nm_find(type_attrs->members, mpath->name, &value)) var_attrs = value;
      if (not(var_attrs == NULL)) break;
      type_attrs = type_attrs->base_type;
      CHECK(f_raise_on_null(type_attrs, &(String){21, 20, "Undefined variable \""}, mpath->name, &(String){2, 1, "\""}))
    }
  }
  *ret_var_attrs = var_attrs;
  return OK;
}
Returncode write_mpath(Member_path* mem_path, Bool write_last) {
  Member_path* mpath = mem_path;
  Generic* value;
  CHECK(f_nm_find(glob->curr->var_map, mpath->name, &value))
  Var_attrs* var_attrs = value;
  Bool is_ref = var_attrs != NULL and var_attrs->is_ref;
  if (is_ref) {
    CHECK(write(&(String){3, 2, "(*"}))
  }
  CHECK(write_cstyle(mpath->name))
  if (is_ref) {
    CHECK(write(&(String){2, 1, ")"}))
  }
  while (true) {
    if (not(mpath->next != NULL and (write_last or mpath->next->next != NULL))) break;
    CHECK(f_raise_on_null(var_attrs, &(String){19, 18, "unknown variable \""}, mpath->name, &(String){2, 1, "\""}))
    mpath = mpath->next;
    CHECK(write(&(String){3, 2, "->"}))
    Type_attrs* type_attrs = var_attrs->type_attrs;
    while (true) {
      CHECK(f_nm_find(type_attrs->members, mpath->name, &value)) var_attrs = value;
      if (not(var_attrs == NULL)) break;
      type_attrs = type_attrs->base_type;
      CHECK(f_raise_on_null(type_attrs, &(String){19, 18, "unknown variable \""}, mpath->name, &(String){2, 1, "\""}))
      CHECK(write(&(String){7, 6, "_base."}))
    }
    CHECK(write_cstyle(mpath->name))
  }
  return OK;
}
/* expression and function */
typedef struct St_arg St_arg; struct St_arg {
  St_arg* next;
  Generic* value;
  String* typename;
  String* type_param;
  String* access;
};
typedef struct St_func St_func; struct St_func {
  Member_path* path;
  St_arg* params;
  St_arg* outputs;
  St_arg* last;
  Bool is_dynamic;
  Int dynamic_index;
};
typedef struct St_exp St_exp; struct St_exp {
  St_exp* next;
  String* operator;
  Member_path* item;
  St_func* call;
  St_exp* subexp;
  St_exp* slice_length;
};
Returncode f_real_string_length(String* text, Int* length) {
  Int index = 1;
  Int real_length = 1;
  Int text_length = text->actual_length - 1;
  while (true) {
    if (not(index < text_length)) break;
    CHECK(string_get(text, index, &glob->end)) if (glob->end == '\\') {
      index = index + 1;
    }
    real_length = real_length + 1;
    index = index + 1;
  }
  *length = real_length;
  return OK;
}
Returncode write_exp(St_exp* st_exp);

Returncode write_exp_array(St_exp* st_exp) {
  Var_attrs* var_attrs;
  CHECK(f_mpath_attrs(st_exp->item, &var_attrs))
  String* typename = var_attrs->type_attrs->name;
  Bool is_array;
  CHECK(string_equal(typename, &(String){6, 5, "Array"}, &is_array)) if (is_array) {
    CHECK(f_raise_on_null(var_attrs->subtype, &(String){22, 21, "No subtype in array \""}, var_attrs->name, &(String){2, 1, "\""}))
    Type_attrs* subtype = var_attrs->subtype;
    typename = subtype->name;
  }
  if (st_exp->slice_length == NULL) {
    if (is_array) {
      CHECK(write(&(String){3, 2, "(("}))
      CHECK(write_cstyle(typename))
      CHECK(write(&(String){4, 3, "*)("}))
      CHECK(write_mpath(st_exp->item, true))
      CHECK(write(&(String){11, 10, "->values))"}))
      CHECK(f_is_primitive(typename, &glob->flag)) if (glob->flag) {
        CHECK(write(&(String){2, 1, "["}))
        CHECK(write_exp(st_exp->subexp))
        CHECK(write(&(String){2, 1, "]"}))
      }
      else {
        CHECK(write(&(String){4, 3, " + "}))
        CHECK(write_exp(st_exp->subexp))
      }
    }
    else {
      CHECK(write_mpath(st_exp->item, true))
      CHECK(write(&(String){9, 8, "->chars["}))
      CHECK(write_exp(st_exp->subexp))
      CHECK(write(&(String){2, 1, "]"}))
    }
  }
  else if (is_array) {
    CHECK(write(&(String){10, 9, "&(Array){"}))
    CHECK(write_exp(st_exp->slice_length))
    CHECK(write(&(String){5, 4, ", (("}))
    CHECK(write_cstyle(typename))
    CHECK(write(&(String){4, 3, "*)("}))
    CHECK(write_mpath(st_exp->item, true))
    CHECK(write(&(String){15, 14, "->values)) + ("}))
    CHECK(write_exp(st_exp->subexp))
    CHECK(write(&(String){3, 2, ")}"}))
  }
  else {
    CHECK(write(&(String){11, 10, "&(String){"}))
    CHECK(write_exp(st_exp->slice_length))
    CHECK(write(&(String){3, 2, ", "}))
    CHECK(write_exp(st_exp->slice_length))
    CHECK(write(&(String){3, 2, ", "}))
    CHECK(write_mpath(st_exp->item, true))
    CHECK(write(&(String){12, 11, "->chars + ("}))
    CHECK(write_exp(st_exp->subexp))
    CHECK(write(&(String){3, 2, ")}"}))
  }
  return OK;
}
Returncode write_exp_item(Member_path* mpath) {
  Char first;
  CHECK(string_get(mpath->name, 0, &first)) if (first == '"') {
    CHECK(f_real_string_length(mpath->name, &glob->length))
    String* length_str = &(String){80, 0, (char[80]){0}};
    CHECK(write(&(String){11, 10, "&(String){"}))
    CHECK(int_to_string(glob->length, length_str))
    CHECK(write(length_str))
    CHECK(write(&(String){3, 2, ", "}))
    glob->length = glob->length - 1;
    CHECK(int_to_string(glob->length, length_str))
    CHECK(write(length_str))
    CHECK(write(&(String){3, 2, ", "}))
    CHECK(write(mpath->name))
    CHECK(write(&(String){2, 1, "}"}))
  }
  else if (first == '\'' or first == '-' or first >= '0' and first <= '9') {
    CHECK(write(mpath->name))
  }
  else if (first == '_') {
    CHECK(write(&(String){5, 4, "NULL"}))
  }
  else {
    CHECK(write_mpath(mpath, true))
  }
  return OK;
}
Returncode write_exp(St_exp* st_exp) {
  if (st_exp == NULL) {
    RAISE
  }
  Bool binary = true;
  if (st_exp->call != NULL) {
    CHECK(f_raise_on_null(st_exp->call->last, &(String){16, 15, "No output for \""}, st_exp->call->path->name, &(String){2, 1, "\""}))
    CHECK(write_mpath(st_exp->call->last->value, true))
  }
  else if (st_exp->item == NULL) {
    binary = st_exp->subexp != NULL;
    if (binary) {
      CHECK(write(&(String){2, 1, "("}))
      CHECK(write_exp(st_exp->subexp))
      CHECK(write(&(String){2, 1, ")"}))
    }
  }
  else if (st_exp->subexp != NULL) {
    CHECK(write_exp_array(st_exp))
  }
  else {
    CHECK(write_exp_item(st_exp->item))
  }
  if (st_exp->operator != NULL) {
    if (binary) {
      CHECK(write(&(String){2, 1, " "}))
    }
    CHECK(write(st_exp->operator))
  }
  if (st_exp->next != NULL) {
    if (binary) {
      CHECK(write(&(String){2, 1, " "}))
    }
    CHECK(write_exp(st_exp->next))
  }
  return OK;
}
Returncode write_func_call(St_func* st_func);

Returncode write_exp_intro(St_exp* st_exp) {
  if (st_exp == NULL) {
    return OK;
  }
  CHECK(write_exp_intro(st_exp->next))
  CHECK(write_exp_intro(st_exp->subexp))
  if (st_exp->call != NULL) {
    CHECK(write_func_call(st_exp->call))
    CHECK(write_new_indent_line())
  }
  else if (st_exp->subexp != NULL and st_exp->item != NULL) {
    CHECK(write(&(String){6, 5, "if (("}))
    CHECK(write_exp(st_exp->subexp))
    CHECK(write(&(String){11, 10, ") < 0 || ("}))
    if (st_exp->slice_length != NULL) {
      CHECK(write_exp(st_exp->slice_length))
      CHECK(write(&(String){11, 10, ") < 0 || ("}))
    }
    CHECK(write_exp(st_exp->subexp))
    if (st_exp->slice_length == NULL) {
      CHECK(write(&(String){6, 5, ") >= "}))
    }
    else {
      CHECK(write(&(String){6, 5, ") + ("}))
      CHECK(write_exp(st_exp->slice_length))
      CHECK(write(&(String){5, 4, ") > "}))
    }
    CHECK(write_mpath(st_exp->item, true))
    CHECK(write(&(String){11, 10, "->length) "}))
    CHECK(write_tb_raise())
    CHECK(write_new_indent_line())
  }
  return OK;
}
Returncode f_get_mpath_attrs(St_exp* st_exp, Var_attrs** var_attrs) {
  *var_attrs = NULL;
  if (st_exp->item == NULL or st_exp->call != NULL or st_exp->subexp != NULL) {
    return OK;
  }
  if (st_exp->operator != NULL or st_exp->next != NULL) {
    return OK;
  }
  Char first;
  CHECK(string_get(st_exp->item->name, 0, &first))
  if (first == '"' or first == '\'' or first == '_' or (first >= '0' and first <= '9')) {
    return OK;
  }
  CHECK(f_mpath_attrs(st_exp->item, var_attrs))
  return OK;
}
Returncode write_type_var(St_exp* st_exp) {
  String* typename = st_exp->item->name;
  CHECK(write(&(String){9, 8, "{sizeof("}))
  CHECK(write_cstyle(typename))
  CHECK(write(&(String){4, 3, "), "}))
  Type_attrs* type_attrs;
  CHECK(f_find_type(typename, &type_attrs))
  if (type_attrs->is_dynamic) {
    CHECK(write_cstyle(typename))
    CHECK(write(&(String){6, 5, "__dtl"}))
  }
  else {
    CHECK(write(&(String){5, 4, "NULL"}))
  }
  CHECK(write(&(String){2, 1, "}"}))
  return OK;
}
Returncode write_exp_typed(St_exp* st_exp, Type_attrs* wanted_type) {
  CHECK(string_equal(wanted_type->name, &(String){5, 4, "Type"}, &glob->flag)) if (glob->flag and st_exp->item != NULL and st_exp->item->next == NULL) {
    Char first;
    CHECK(string_get(st_exp->item->name, 0, &first))
    if (first >= 'A' and first <= 'Z') {
      CHECK(write(&(String){7, 6, "(Type)"}))
      CHECK(write_type_var(st_exp))
      return OK;
    }
  }
  Var_attrs* var_attrs;
  CHECK(f_get_mpath_attrs(st_exp, &var_attrs))
  
  if (var_attrs != NULL) {
    CHECK(f_mpath_attrs(st_exp->item, &var_attrs))
    Type_attrs* type_attrs = var_attrs->type_attrs;
    Bool first_base = true;
    while (true) {
      if (not(type_attrs != wanted_type)) break;
      type_attrs = type_attrs->base_type;
      if (type_attrs == NULL) {
        String* msg = &(String){256, 0, (char[256]){0}};
        CHECK(string_copy(msg, &(String){12, 11, "Parameter \""}))
        CHECK(string_concat(msg, st_exp->item->name))
        CHECK(string_concat(msg, &(String){15, 14, "\" is of type \""}))
        CHECK(string_concat(msg, var_attrs->type_attrs->name))
        CHECK(string_concat(msg, &(String){15, 14, "\" instead of \""}))
        CHECK(string_concat(msg, wanted_type->name))
        CHECK(string_concat(msg, &(String){2, 1, "\""}))
        CHECK(print(msg))
        RAISE
      }
      if (first_base) {
        CHECK(write(&(String){3, 2, "&("}))
        CHECK(write_mpath(st_exp->item, true))
        CHECK(write(&(String){3, 2, "->"}))
        first_base = false;
      }
      else {
        CHECK(write(&(String){2, 1, "."}))
      }
      CHECK(write(&(String){6, 5, "_base"}))
    }
    if (first_base) {
      CHECK(write_mpath(st_exp->item, true))
    }
    else {
      CHECK(write(&(String){2, 1, ")"}))
    }
    return OK;
  }
  CHECK(write_exp(st_exp))
  return OK;
}
Returncode parse_func_header(Member_path* path, St_func** st_func, Char* end);

Returncode parse_exp(String* exp_ends, St_exp** new_st_exp, Char* out_end) {
  St_exp* st_exp = malloc(sizeof(St_exp)); if (st_exp == NULL) RAISE
  st_exp->next = NULL;
  st_exp->operator = NULL;
  st_exp->call = NULL;
  st_exp->subexp = NULL;
  String* ends = &(String){16, 0, (char[16]){0}};
  CHECK(string_copy(ends, &(String){5, 4, " .(["}))
  CHECK(string_concat(ends, exp_ends))
  Char end;
  CHECK(read_mpath(ends, &st_exp->item, &end)) if (end == '(') {
    if (st_exp->item->name->actual_length > 0) {
      CHECK(parse_func_header(st_exp->item, &st_exp->call, &end))
    }
    else {
      CHECK(parse_exp(&(String){2, 1, ")"}, &st_exp->subexp, &end))
      CHECK(read_c(&end))
      free(st_exp->item);
    }
    st_exp->item = NULL;
  }
  else if (end == '[') {
    CHECK(parse_exp(&(String){3, 2, ":]"}, &st_exp->subexp, &end))
    if (end == ':') {
      CHECK(parse_exp(&(String){2, 1, "]"}, &st_exp->slice_length, &end))
    }
    CHECK(read_c(&end))
    if (end == '.') {
      CHECK(f_new_copy(&(String){3, 2, "->"}, &st_exp->operator))
      CHECK(parse_exp(exp_ends, &st_exp->next, &end))
    }
  }
  else if (end == ' ' and st_exp->item->next == NULL) {
    Generic* value;
    CHECK(f_nm_find(glob->op_map, st_exp->item->name, &value))
    if (value != NULL) {
      st_exp->operator = value;
      free(st_exp->item);
      st_exp->item = NULL;
      CHECK(parse_exp(exp_ends, &st_exp->next, &end))
    }
  }
  if (end == ' ') {
    String* operator = &(String){16, 0, (char[16]){0}};
    CHECK(read(&(String){2, 1, " "}, operator, &end))
    Generic* value;
    CHECK(f_nm_find(glob->op_map, operator, &value))
    CHECK(f_raise_on_null(value, &(String){18, 17, "Unknow operator \""}, operator, &(String){2, 1, "\""}))
    st_exp->operator = value;
    CHECK(parse_exp(exp_ends, &st_exp->next, &end))
  }
  *new_st_exp = st_exp;
  *out_end = end;
  return OK;
}
/* function */
Returncode write_func_last(St_func* st_func, Var_attrs* var_attrs) {
  CHECK(f_raise_on_null(var_attrs->subtype, &(String){2, 1, "\""}, var_attrs->name, &(String){20, 19, "\" is not a function"}))
  St_func* func_def = var_attrs->subtype;
  St_arg* dec_out = func_def->outputs;
  if (dec_out == NULL) {
    CHECK(write_tb_check())
    return OK;
  }
  St_arg* call_out = st_func->outputs;
  St_arg* call_prev_out = NULL;
  while (true) {
    if (not(dec_out->next != NULL and call_out != NULL)) break;
    call_prev_out = call_out;
    dec_out = dec_out->next;
    call_out = call_out->next;
  }
  if (dec_out->next != NULL) {
    CHECK(f_raise_on_null(NULL, &(String){21, 20, "too few outputs in \""}, var_attrs->name, &(String){2, 1, "\""}))
  }
  if (call_out != NULL and call_out->next != NULL) {
    CHECK(f_raise_on_null(NULL, &(String){22, 21, "too many outputs in \""}, var_attrs->name, &(String){2, 1, "\""}))
  }
  if (call_out == NULL) {
    String* counter = &(String){32, 0, (char[32]){0}};
    CHECK(int_to_string(glob->var_count, counter))
    glob->var_count = glob->var_count + 1;
    String* last = new_string(2 + dec_out->typename->actual_length + counter->actual_length); if (last == NULL) RAISE
    CHECK(string_copy(last, &(String){2, 1, "_"}))
    CHECK(string_concat(last, dec_out->typename))
    CHECK(string_concat(last, counter))
    CHECK(write_cstyle(dec_out->typename))
    CHECK(string_equal(dec_out->access, &(String){5, 4, "copy"}, &glob->flag)) if (glob->flag == false) {
      CHECK(write(&(String){2, 1, "*"}))
    }
    CHECK(write(&(String){2, 1, " "}))
    CHECK(write_cstyle(last))
    CHECK(write(&(String){2, 1, ";"}))
    CHECK(write_new_indent_line())
    Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
    mpath->name = last;
    mpath->next = NULL;
    St_arg* arg = malloc(sizeof(St_arg)); if (arg == NULL) RAISE
    arg->value = mpath;
    arg->next = NULL;
    arg->type_param = NULL;
    CHECK(f_new_copy(dec_out->typename, &arg->typename))
    CHECK(f_new_copy(dec_out->access, &arg->access))
    if (call_prev_out == NULL) {
      st_func->outputs = arg;
    }
    else {
      call_prev_out->next = arg;
    }
    st_func->last = arg;
  }
  else {
    st_func->last = call_out;
  }
  CHECK(write_tb_check())
  return OK;
}
Returncode write_call_func_name(St_func* st_func, St_func** ret_func_def) {
  Var_attrs* var_attrs;
  if (st_func->path->next == NULL) {
    CHECK(f_find_var(glob->curr->var_map, st_func->path->name, &var_attrs))
    CHECK(write_func_last(st_func, var_attrs))
    CHECK(write_mpath(st_func->path, true))
    *ret_func_def = var_attrs->subtype;
    return OK;
  }
  Char first;
  Generic* value;
  Type_attrs* type_attrs;
  CHECK(string_get(st_func->path->name, 0, &first))
  if (first >= 'A' and first <= 'Z') {
    if (st_func->path->next->next != NULL) {
      CHECK(f_msg_raise(&(String){20, 19, "Illegal meth call \""}, st_func->path->next->next->name, &(String){2, 1, "\""}))
    }
    CHECK(f_find_type(st_func->path->name, &type_attrs))
    String* meth = st_func->path->next->name;
    CHECK(f_nm_find(type_attrs->members, meth, &value)) var_attrs = value;
    CHECK(f_raise_on_null(var_attrs, &(String){17, 16, "unknown method \""}, meth, &(String){2, 1, "\""}))
    *ret_func_def = var_attrs->subtype;
    CHECK(write_func_last(st_func, var_attrs))
    CHECK(write_cstyle(type_attrs->name))
    CHECK(write(&(String){2, 1, "_"}))
    CHECK(write_cstyle(meth))
    return OK;
  }
  St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
  param->typename = NULL;
  param->type_param = NULL;
  CHECK(f_new_copy(&(String){5, 4, "user"}, &param->access))
  Member_path* mpath = st_func->path;
  Member_path* param_mpath = malloc(sizeof(Member_path)); if (param_mpath == NULL) RAISE
  param_mpath->next = NULL;
  St_exp* param_exp = malloc(sizeof(St_exp)); if (param_exp == NULL) RAISE
  param_exp->next = NULL;
  param_exp->operator = NULL;
  param_exp->call = NULL;
  param_exp->subexp = NULL;
  param_exp->slice_length = NULL;
  param_exp->item = param_mpath;
  param->value = param_exp;
  param->next = st_func->params;
  st_func->params = param;
  
  Bool ignore_dynamic;
  CHECK(string_equal(mpath->name, &(String){5, 4, "base"}, &ignore_dynamic)) if (ignore_dynamic) {
    CHECK(f_find_var(glob->curr->var_map, &(String){5, 4, "self"}, &var_attrs))
    type_attrs = var_attrs->type_attrs->base_type;
    CHECK(f_raise_on_null(type_attrs, &(String){14, 13, "no base class"}, &(String){1, 0, ""}, &(String){1, 0, ""}))
    CHECK(f_new_copy(&(String){5, 4, "self"}, &param_mpath->name))
  }
  else {
    CHECK(f_new_copy(mpath->name, &param_mpath->name))
    CHECK(f_find_var(glob->curr->var_map, mpath->name, &var_attrs))
    type_attrs = var_attrs->type_attrs;
  }
  while (true) {
    mpath = mpath->next;
    while (true) {
      CHECK(f_nm_find(type_attrs->members, mpath->name, &value)) var_attrs = value;
      if (not(var_attrs == NULL)) break;
      type_attrs = type_attrs->base_type;
      CHECK(f_raise_on_null(type_attrs, &(String){19, 18, "unknown variable \""}, mpath->name, &(String){2, 1, "\""}))
    }
    if (not(mpath->next != NULL)) break;
    type_attrs = var_attrs->type_attrs;
    Member_path* new_mpath = malloc(sizeof(Member_path)); if (new_mpath == NULL) RAISE
    param_mpath->next = new_mpath;
    new_mpath->next = NULL;
    CHECK(f_new_copy(mpath->name, &new_mpath->name))
    param_mpath = new_mpath;
  }
  St_func* func_def = var_attrs->subtype;
  *ret_func_def = func_def;
  CHECK(write_func_last(st_func, var_attrs))
  if (func_def->is_dynamic and not ignore_dynamic) {
    CHECK(write(&(String){13, 12, "(*((Func**)("}))
    CHECK(write_mpath(st_func->path, false))
    CHECK(write(&(String){5, 4, ")))["}))
    String* dynamic_index = &(String){32, 0, (char[32]){0}};
    CHECK(int_to_string(func_def->dynamic_index, dynamic_index))
    CHECK(write(dynamic_index))
    CHECK(write(&(String){2, 1, "]"}))
  }
  else {
    CHECK(write_cstyle(type_attrs->name))
    CHECK(write(&(String){2, 1, "_"}))
    CHECK(write_cstyle(mpath->name))
  }
  return OK;
}
Returncode write_func_call(St_func* st_func) {
  St_arg* arg = st_func->params;
  St_func* func_def;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(write_exp_intro(arg->value))
    arg = arg->next;
  }
  CHECK(write_call_func_name(st_func, &func_def))
  CHECK(write(&(String){2, 1, "("}))
  arg = st_func->params;
  St_arg* arg_def = func_def->params;
  while (true) {
    if (not(arg != NULL or arg_def != NULL)) break;
    CHECK(f_raise_on_null(arg, &(String){32, 31, "too few parameters in call to \""}, func_def->path->name, &(String){2, 1, "\""}))
    CHECK(f_raise_on_null(arg_def, &(String){33, 32, "too much parameters in call to \""}, func_def->path->name, &(String){2, 1, "\""}))
    Type_attrs* dec_type_attrs;
    CHECK(f_find_type(arg_def->typename, &dec_type_attrs))
    CHECK(write_exp_typed(arg->value, dec_type_attrs))
    arg = arg->next;
    arg_def = arg_def->next;
    if (arg != NULL or st_func->outputs != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  arg = st_func->outputs;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(string_equal(arg->access, &(String){4, 3, "var"}, &glob->flag)) if (glob->flag == false) {
      CHECK(write(&(String){2, 1, "&"}))
    }
    CHECK(write_mpath(arg->value, true))
    arg = arg->next;
    if (arg != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  CHECK(write(&(String){3, 2, "))"}))
  return OK;
}
Returncode write_args(St_arg* first, Bool is_out, St_arg* next) {
  St_arg* arg = first;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(write_cstyle(arg->typename))
    CHECK(string_equal(arg->access, &(String){5, 4, "copy"}, &glob->flag)) if (glob->flag == false) {
      CHECK(write(&(String){2, 1, "*"}))
    }
    CHECK(string_equal(arg->access, &(String){4, 3, "var"}, &glob->flag)) if (glob->flag == false and is_out) {
      CHECK(write(&(String){2, 1, "*"}))
    }
    CHECK(write(&(String){2, 1, " "}))
    CHECK(write_cstyle(arg->value))
    arg = arg->next;
    if (arg != NULL or next != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  return OK;
}
Returncode write_class(St_class* st_class);

Returncode write_func_name(St_func* st_func) {
  if (glob->curr->father->f_writer == write_class) {
    CHECK(write_cstyle(glob->st_class->type_attrs->name))
    CHECK(write(&(String){2, 1, "_"}))
  }
  CHECK(write_cstyle(st_func->path->name))
  return OK;
}
Returncode write_func_header(St_func* st_func) {
  CHECK(write(&(String){12, 11, "Returncode "}))
  CHECK(write_func_name(st_func))
  CHECK(write(&(String){2, 1, "("}))
  CHECK(write_args(st_func->params, false, st_func->outputs))
  CHECK(write_args(st_func->outputs, true, NULL))
  CHECK(write(&(String){2, 1, ")"}))
  return OK;
}
Returncode parse_param_dec(St_arg* param) {
  CHECK(read_new(&(String){3, 2, " {"}, &param->typename, &glob->end)) if (glob->end == '{') {
    CHECK(read_new(&(String){2, 1, "}"}, &param->type_param, &glob->end))
    CHECK(read_c(&glob->end))
  }
  String* name;
  CHECK(read_new(&(String){3, 2, ",)"}, &name, &glob->end))
  param->value = name;
  return OK;
}
Returncode parse_func_header(Member_path* path, St_func** st_func, Char* end) {
  St_func* new_func = malloc(sizeof(St_func)); if (new_func == NULL) RAISE
  if (path == NULL) {
    Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
    mpath->next = NULL;
    CHECK(read_new(&(String){2, 1, "("}, &mpath->name, &glob->end))
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(f_new_copy(mpath->name, &new_var->name))
    new_func->path = mpath;
    CHECK(f_find_type(&(String){5, 4, "Func"}, &new_var->type_attrs))
    new_var->subtype = new_func;
    new_var->is_ref = false;
    if (glob->curr->f_writer == write_class) {
      CHECK(f_nm_init(new_var->name, new_var, &glob->st_class->type_attrs->members))
    }
    else {
      CHECK(f_nm_init(new_var->name, new_var, &glob->curr->var_map))
    }
  }
  else {
    new_func->path = path;
  }
  new_func->last = NULL;
  new_func->params = NULL;
  new_func->outputs = NULL;
  new_func->is_dynamic = false;
  new_func->dynamic_index = 0;
  St_arg* last = NULL;
  while (true) {
    String* access = &(String){256, 0, (char[256]){0}};
    CHECK(read(&(String){3, 2, " )"}, access, &glob->end)) if (not(glob->end == ' ')) break;
    St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
    param->next = NULL;
    param->typename = NULL;
    param->type_param = NULL;
    CHECK(f_new_copy(access, &param->access))
    if (path == NULL) {
      CHECK(parse_param_dec(param))
    }
    else {
      St_exp* value ;
      CHECK(parse_exp(&(String){3, 2, ",)"}, &value, &glob->end))
      param->value = value;
    }
    if (last == NULL) {
      new_func->params = param;
    }
    else {
      last->next = param;
    }
    last = param;
    if (not(glob->end == ',')) break;
    CHECK(read_c(&glob->end))
  }
  CHECK(read_c(&glob->end))
  last = NULL;
  if (glob->end == ':') {
    while (true) {
      CHECK(read_c(&glob->end))
      St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
      param->next = NULL;
      param->typename = NULL;
      param->type_param = NULL;
      CHECK(read_new(&(String){2, 1, " "}, &param->access, &glob->end))
      if (path == NULL) {
        CHECK(parse_param_dec(param))
      }
      else {
        Member_path* mpath;
        CHECK(read_mpath(&(String){3, 2, ",)"}, &mpath, &glob->end))
        param->value = mpath;
      }
      if (last == NULL) {
        new_func->outputs = param;
      }
      else {
        last->next = param;
      }
      last = param;
      if (not(glob->end == ',')) break;
    }
    CHECK(read_c(&glob->end))
  }
  *st_func = new_func;
  *end = glob->end;
  return OK;
}
/* return */
Returncode write_return(Generic* null) {
  CHECK(write(&(String){12, 11, "return OK;\n"}))
  return OK;
}
Returncode parse_return() {
  CHECK(add_node(write_return, NULL))
  return OK;
}
/* raise */
Returncode write_raise(Generic* null) {
  CHECK(write_tb_raise())
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode parse_raise() {
  CHECK(add_node(write_raise, NULL))
  return OK;
}
/* func */
Returncode write_func(St_func* st_func) {
  CHECK(write(&(String){25, 24, "static char* _func_name_"}))
  CHECK(write_func_name(st_func))
  CHECK(write(&(String){5, 4, " = \""}))
  if (glob->curr->father->f_writer == write_class) {
    CHECK(write(glob->st_class->type_attrs->name))
    CHECK(write(&(String){2, 1, "."}))
  }
  CHECK(write(st_func->path->name))
  CHECK(write(&(String){3, 2, "\";"}))
  CHECK(write_new_indent_line())
  CHECK(write(&(String){33, 32, "#define MR_FUNC_NAME _func_name_"}))
  CHECK(write_func_name(st_func))
  CHECK(write_new_indent_line())
  CHECK(write_func_header(st_func))
  CHECK(write(&(String){4, 3, " {\n"}))
  glob->spaces = glob->spaces + 2;
  CHECK(write_sons())
  if (glob->curr->last_son->f_writer != write_return and glob->curr->last_son->f_writer != write_raise) {
    CHECK(write_spaces())
    CHECK(write_return(NULL))
  }
  CHECK(write_block_close())
  CHECK(write_new_indent_line())
  CHECK(write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}))
  return OK;
}
Returncode add_arg_vars(St_arg* first, Bool is_ref) {
  St_arg* arg = first;
  while (true) {
    if (not(arg != NULL)) break;
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(f_new_copy(arg->value, &new_var->name))
    CHECK(f_find_type(arg->typename, &new_var->type_attrs))
    new_var->subtype = NULL;
    if (arg->type_param != NULL) {
      Type_attrs* subtype;
      CHECK(f_find_type(arg->type_param, &subtype))
      new_var->subtype = subtype;
    }
    CHECK(string_equal(arg->access, &(String){4, 3, "var"}, &glob->flag)) new_var->is_ref = glob->flag == false and is_ref;
    CHECK(f_nm_init(new_var->name, new_var, &glob->curr->var_map))
    arg = arg->next;
  }
  return OK;
}
Returncode parse_func_body(Func f_writer) {
  Bool is_dynamic = false;
  if (glob->curr->f_writer == write_class) {
    String* subtype = &(String){16, 0, (char[16]){0}};
    CHECK(read(&(String){2, 1, " "}, subtype, &glob->end))
    CHECK(string_equal(subtype, &(String){8, 7, "dynamic"}, &is_dynamic))
  }
  St_func* st_func;
  CHECK(parse_func_header(NULL, &st_func, &glob->end))
  if (is_dynamic) {
    st_func->is_dynamic = true;
    st_func->dynamic_index = glob->st_class->dynamic_count;
    glob->st_class->dynamic_count = glob->st_class->dynamic_count + 1;
  }
  CHECK(add_node(f_writer, st_func))
  CHECK(f_start_block())
  /* add "self" */
  if (glob->curr->father->f_writer == write_class) {
    St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
    param->type_param = NULL;
    CHECK(f_new_copy(&(String){5, 4, "user"}, &param->access))
    CHECK(f_new_copy(glob->st_class->type_attrs->name, &param->typename))
    String* param_name;
    CHECK(f_new_copy(&(String){5, 4, "self"}, &param_name))
    param->value = param_name;
    param->next = st_func->params;
    st_func->params = param;
    
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(f_new_copy(&(String){5, 4, "self"}, &new_var->name))
    new_var->type_attrs = glob->st_class->type_attrs;
    new_var->subtype = NULL;
    new_var->is_ref = false;
    CHECK(f_nm_init(new_var->name, new_var, &glob->curr->var_map))
  }
  CHECK(add_arg_vars(st_func->params, false))
  CHECK(add_arg_vars(st_func->outputs, true))
  return OK;
}
Returncode parse_func() {
  CHECK(parse_func_body(write_func))
  return OK;
}
/* native */
Returncode write_native_type(String* name) {
  CHECK(write(&(String){14, 13, "typedef void "}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode write_native_func(St_func* st_func) {
  CHECK(write_func_header(st_func))
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_native() {
  String* kind = &(String){80, 0, (char[80]){0}};
  CHECK(read(&(String){2, 1, " "}, kind, &glob->end))
  CHECK(string_equal(kind, &(String){5, 4, "func"}, &glob->flag)) if (glob->flag) {
    St_func* st_func;
    CHECK(parse_func_header(NULL, &st_func, &glob->end))
    CHECK(add_node(write_native_func, st_func))
  }
  else {
    String* name;
    CHECK(read_new(&(String){1, 0, ""}, &name, &glob->end))
    CHECK(add_type(name, NULL, NULL))
    CHECK(add_node(write_native_type, name))
  }
  return OK;
}
/* main */
Returncode write_main(St_func* st_func) {
  CHECK(write_func(st_func))
  CHECK(write(&(String){12, 11, "\nMAIN_FUNC\n"}))
  return OK;
}
Returncode parse_main() {
  CHECK(parse_func_body(write_main))
  return OK;
}
/* declerations */
typedef struct St_dec St_dec; struct St_dec {
  String* name;
  String* typename;
  String* arr_length;
  String* str_length;
  String* type_base;
  String* type_var;
  St_exp* init;
};
Returncode parse_dec(St_dec** new_st_dec) {
  St_dec* st_dec = malloc(sizeof(St_dec)); if (st_dec == NULL) RAISE
  st_dec->arr_length = NULL;
  st_dec->str_length = NULL;
  st_dec->type_base = NULL;
  st_dec->type_var = NULL;
  st_dec->init = NULL;
  
  CHECK(read_new(&(String){3, 2, " {"}, &st_dec->typename, &glob->end))
  Bool is_array = false;
  Bool is_array_var = false;
  if (glob->end == '{') {
    CHECK(string_equal(st_dec->typename, &(String){6, 5, "Array"}, &is_array)) if (is_array) {
      CHECK(read_new(&(String){3, 2, "}:"}, &st_dec->arr_length, &glob->end)) if (glob->end == ':') {
        is_array_var = true;
        CHECK(read_new(&(String){3, 2, "}{"}, &st_dec->typename, &glob->end))
      }
    }
    CHECK(string_equal(st_dec->typename, &(String){7, 6, "String"}, &glob->flag)) if (glob->flag) {
      CHECK(read_new(&(String){2, 1, "}"}, &st_dec->str_length, &glob->end))
      if (is_array) {
        CHECK(read_c(&glob->end))
      }
    }
    CHECK(string_equal(st_dec->typename, &(String){5, 4, "Type"}, &glob->flag)) if (glob->flag) {
      CHECK(read_new(&(String){2, 1, "}"}, &st_dec->type_base, &glob->end))
    }
    CHECK(string_equal(st_dec->typename, &(String){3, 2, "As"}, &glob->flag)) if (glob->flag) {
      CHECK(read_new(&(String){2, 1, "}"}, &st_dec->type_var, &glob->end))
      Var_attrs* var_attrs;
      CHECK(f_find_var(glob->curr->var_map, st_dec->type_var, &var_attrs))
      CHECK(f_raise_on_null(var_attrs->subtype, &(String){24, 23, "Illegal type variable \""}, st_dec->type_var, &(String){2, 1, "\""}))
      free(st_dec->typename);
      Type_attrs* subtype = var_attrs->subtype;
      CHECK(f_new_copy(subtype->name, &st_dec->typename))
    }
    CHECK(read_c(&glob->end))
  }
  CHECK(read_new(&(String){2, 1, "("}, &st_dec->name, &glob->end)) if (glob->end == '(') {
    CHECK(parse_exp(&(String){2, 1, ")"}, &st_dec->init, &glob->end))
    
    CHECK(read_c(&glob->end))
  }
  Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
  CHECK(f_new_copy(st_dec->name, &new_var->name))
  Type_attrs* type_attr;
  CHECK(f_find_type(st_dec->typename, &type_attr))
  new_var->subtype = NULL;
  if (is_array_var) {
    new_var->subtype = type_attr;
    CHECK(f_find_type(&(String){6, 5, "Array"}, &type_attr))
  }
  else if (is_array) {
    Type_attrs* subtype;
    CHECK(f_find_type(st_dec->arr_length, &subtype))
    new_var->subtype = subtype;
  }
  else if (st_dec->type_base != NULL) {
    Type_attrs* subtype;
    CHECK(f_find_type(st_dec->type_base, &subtype))
    new_var->subtype = subtype;
  }
  new_var->type_attrs = type_attr;
  new_var->is_ref = false;
  
  if (glob->curr->f_writer == write_class) {
    CHECK(f_nm_init(new_var->name, new_var, &glob->st_class->type_attrs->members))
  }
  else {
    CHECK(f_nm_init(new_var->name, new_var, &glob->curr->var_map))
  }
  *new_st_dec = st_dec;
  return OK;
}
/* var */
Returncode write_dtl_assign(String* name) {
  CHECK(write(&(String){12, 11, "*((Func**)("}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){6, 5, ")) = "}))
  return OK;
}
Returncode write_dtl(St_dec* st_dec) {
  Type_attrs* type_attrs;
  CHECK(f_find_type(st_dec->typename, &type_attrs))
  if (type_attrs->is_dynamic) {
    CHECK(write_new_indent_line())
    CHECK(write_dtl_assign(st_dec->name))
    CHECK(write_cstyle(st_dec->typename))
    CHECK(write(&(String){7, 6, "__dtl;"}))
  }
  return OK;
}
Returncode write_var_primitive(St_dec* st_dec) {
  CHECK(write_exp_intro(st_dec->init))
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){2, 1, " "}))
  CHECK(write_cstyle(st_dec->name))
  if (st_dec->init != NULL) {
    CHECK(write(&(String){4, 3, " = "}))
    CHECK(write_exp(st_dec->init))
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode write_ref_prefix(String* typename, String* name) {
  CHECK(write_cstyle(typename))
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){6, 5, " = &("}))
  CHECK(write_cstyle(typename))
  CHECK(write(&(String){3, 2, "){"}))
  return OK;
}
Returncode write_var_class(St_dec* st_dec) {
  CHECK(write_exp_intro(st_dec->init))
  CHECK(write_ref_prefix(st_dec->typename, st_dec->name))
  if (st_dec->init == NULL) {
    CHECK(write(&(String){2, 1, "0"}))
  }
  else {
    CHECK(write_exp(st_dec->init))
  }
  CHECK(write(&(String){3, 2, "};"}))
  CHECK(write_dtl(st_dec))
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode write_var_string(St_dec* st_dec) {
  CHECK(write_exp_intro(st_dec->init))
  CHECK(write_ref_prefix(&(String){7, 6, "String"}, st_dec->name))
  CHECK(write(st_dec->str_length))
  CHECK(write(&(String){12, 11, ", 0, (char["}))
  CHECK(write(st_dec->str_length))
  CHECK(write(&(String){8, 7, "]){0}};"}))
  if (st_dec->init != NULL) {
    CHECK(write_new_indent_line())
    CHECK(write_tb_check())
    CHECK(write(&(String){13, 12, "String_copy("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){3, 2, ", "}))
    CHECK(write_exp(st_dec->init))
    CHECK(write(&(String){4, 3, "));"}))
  }
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode write_var_array(St_dec* st_dec) {
  CHECK(write_ref_prefix(&(String){6, 5, "Array"}, st_dec->name))
  CHECK(write(st_dec->arr_length))
  CHECK(write(&(String){4, 3, ", ("}))
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){2, 1, "["}))
  CHECK(write(st_dec->arr_length))
  CHECK(write(&(String){8, 7, "]){0}};"}))
  
  if (st_dec->str_length != NULL) {
    CHECK(write_new_indent_line())
    CHECK(write(&(String){7, 6, "char _"}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){8, 7, "_chars["}))
    CHECK(write(st_dec->str_length))
    CHECK(write(&(String){3, 2, "]["}))
    CHECK(write(st_dec->arr_length))
    CHECK(write(&(String){3, 2, "];"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){20, 19, "{int n; for(n=0; n<"}))
    CHECK(write(st_dec->arr_length))
    CHECK(write(&(String){7, 6, "; ++n)"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){13, 12, " ((String*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){26, 25, "->values))[n] = (String){"}))
    CHECK(write(st_dec->str_length))
    CHECK(write(&(String){7, 6, ", 0, _"}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){13, 12, "_chars[n]};}"}))
  }
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode write_var_typevar(St_dec* st_dec) {
  CHECK(write(&(String){6, 5, "Type "}))
  CHECK(write_cstyle(st_dec->name))
  if (st_dec->init != NULL) {
    CHECK(f_raise_on_null(st_dec->init->item, &(String){27, 26, "Illegal init for type var\""}, st_dec->name, &(String){2, 1, "\""}))
    CHECK(write(&(String){4, 3, " = "}))
    CHECK(write_type_var(st_dec->init))
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode write_new_as_dtl(St_dec* st_dec) {
  CHECK(write_new_indent_line())
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_cstyle(st_dec->type_var))
  CHECK(write(&(String){17, 16, ".dtl != NULL) { "}))
  CHECK(write_dtl_assign(st_dec->name))
  CHECK(write_cstyle(st_dec->type_var))
  CHECK(write(&(String){8, 7, ".dtl; }"}))
  return OK;
}
Returncode write_var_as(St_dec* st_dec) {
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){5, 4, " = ("}))
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){9, 8, "*)(Byte["}))
  CHECK(write_cstyle(st_dec->type_var))
  CHECK(write(&(String){12, 11, ".size]){0};"}))
  CHECK(write_new_as_dtl(st_dec))
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode add_dec_node(Func f_writer, Generic* value) {
  St* node;
  CHECK(f_st_new(f_writer, value, glob->curr, &node))
  return OK;
}
Returncode parse_var() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  
  if (st_dec->arr_length != NULL) {
    CHECK(add_dec_node(write_var_array, st_dec))
    return OK;
  }
  if (st_dec->str_length != NULL) {
    CHECK(add_dec_node(write_var_string, st_dec))
    return OK;
  }
  if (st_dec->type_base != NULL) {
    CHECK(add_dec_node(write_var_typevar, st_dec))
    return OK;
  }
  if (st_dec->type_var != NULL) {
    CHECK(add_dec_node(write_var_as, st_dec))
    return OK;
  }
  CHECK(f_is_primitive(st_dec->typename, &glob->flag)) if (glob->flag) {
    CHECK(add_dec_node(write_var_primitive, st_dec))
    return OK;
  }
  CHECK(add_dec_node(write_var_class, st_dec))
  return OK;
}
/* ref */
Returncode write_ref(St_dec* st_dec) {
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(st_dec->name))
  if (st_dec->init != NULL) {
    CHECK(write(&(String){4, 3, " = "}))
    CHECK(write_exp(st_dec->init))
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_ref() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  CHECK(add_dec_node(write_ref, st_dec))
  return OK;
}
/* new */
Returncode write_new(St_dec* st_dec) {
  if (st_dec->type_var != NULL) {
    CHECK(write(&(String){5, 4, "if ("}))
    CHECK(write_cstyle(st_dec->type_var))
    CHECK(write(&(String){13, 12, ".size <= 0) "}))
    CHECK(write_tb_raise())
    CHECK(write_new_indent_line())
  }
  if (st_dec->arr_length != NULL) {
    CHECK(write(&(String){6, 5, "Array"}))
  }
  else {
    CHECK(write_cstyle(st_dec->typename))
  }
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){4, 3, " = "}))
  
  if (st_dec->arr_length != NULL) {
    CHECK(write(&(String){11, 10, "new_array("}))
    CHECK(write_cstyle(st_dec->arr_length))
    CHECK(write(&(String){10, 9, ", sizeof("}))
    CHECK(write_cstyle(st_dec->typename))
    CHECK(write(&(String){2, 1, ")"}))
    if (st_dec->str_length != NULL) {
      CHECK(write(&(String){5, 4, " + ("}))
      CHECK(write_cstyle(st_dec->str_length))
      CHECK(write_c(')'))
    }
  }
  else if (st_dec->str_length != NULL) {
    CHECK(write(&(String){12, 11, "new_string("}))
    CHECK(write_cstyle(st_dec->str_length))
  }
  else if (st_dec->type_var != NULL) {
    CHECK(write(&(String){8, 7, "malloc("}))
    CHECK(write_cstyle(st_dec->type_var))
    CHECK(write(&(String){6, 5, ".size"}))
  }
  else {
    CHECK(write(&(String){15, 14, "malloc(sizeof("}))
    CHECK(write_cstyle(st_dec->typename))
    CHECK(write_c(')'))
    
  }
  CHECK(write(&(String){3, 2, ");"}))
  CHECK(write_new_indent_line())
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){11, 10, " == NULL) "}))
  CHECK(write_tb_raise())
  
  if (st_dec->arr_length != NULL and st_dec->str_length != NULL) {
    CHECK(write_new_indent_line())
    CHECK(write(&(String){21, 20, "{int n; for(n=0; n<("}))
    CHECK(write_cstyle(st_dec->arr_length))
    CHECK(write(&(String){8, 7, "); ++n)"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){13, 12, " ((String*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){26, 25, "->values))[n] = (String){"}))
    CHECK(write_cstyle(st_dec->str_length))
    CHECK(write(&(String){14, 13, ", 0, (Byte*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){14, 13, "->values) + ("}))
    CHECK(write_cstyle(st_dec->arr_length))
    CHECK(write(&(String){23, 22, ") * sizeof(String) + ("}))
    CHECK(write_cstyle(st_dec->str_length))
    CHECK(write(&(String){9, 8, ") * n};}"}))
  }
  if (st_dec->type_var != NULL) {
    CHECK(write_new_as_dtl(st_dec))
  }
  else if (st_dec->arr_length == NULL and st_dec->str_length == NULL) {
    CHECK(write_dtl(st_dec))
  }
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode parse_new() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  CHECK(add_node(write_new, st_dec))
  return OK;
}
/* delete */
Returncode write_delete(String* name) {
  CHECK(write(&(String){6, 5, "free("}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){4, 3, ");\n"}))
  return OK;
}
Returncode parse_delete() {
  String* name;
  CHECK(read_new(&(String){1, 0, ""}, &name, &glob->end))
  CHECK(add_node(write_delete, name))
  return OK;
}
/* if */
Returncode write_if(St_exp* st_exp) {
  CHECK(write_exp_intro(st_exp))
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){2, 1, ")"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_if() {
  St_exp* st_exp;
  CHECK(parse_exp(&(String){1, 0, ""}, &st_exp, &glob->end))
  CHECK(add_node(write_if, st_exp))
  CHECK(f_start_block())
  return OK;
}
/* else */
Returncode write_else(Generic* null) {
  CHECK(write(&(String){5, 4, "else"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_else() {
  CHECK(add_node(write_else, NULL))
  CHECK(f_start_block())
  return OK;
}
/* else-if */
Returncode write_else_if(St_exp* st_exp) {
  CHECK(write(&(String){7, 6, "else {"}))
  glob->spaces = glob->spaces + 2;
  CHECK(write_new_indent_line())
  CHECK(write_exp_intro(st_exp))
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){2, 1, ")"}))
  CHECK(write_block())
  St* next = glob->curr->next_brother;
  if (next != NULL and (next->f_writer == write_else or next->f_writer == write_else_if)) {
    glob->curr = next;
    CHECK(write_spaces())
    CHECK(next->f_writer(next->value))
  }
  CHECK(write_block_close())
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode parse_else_if() {
  St_exp* st_exp;
  CHECK(parse_exp(&(String){1, 0, ""}, &st_exp, &glob->end))
  CHECK(add_node(write_else_if, st_exp))
  CHECK(f_start_block())
  return OK;
}
/* do */
Returncode write_do(Generic* null) {
  CHECK(write(&(String){13, 12, "while (true)"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_do() {
  CHECK(add_node(write_do, NULL))
  CHECK(f_start_block())
  return OK;
}
/* while */
Returncode write_while(St_exp* st_exp) {
  CHECK(write_exp_intro(st_exp))
  CHECK(write(&(String){7, 6, "if (!("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){11, 10, ")) break;\n"}))
  return OK;
}
Returncode parse_while() {
  St_exp* st_exp;
  CHECK(parse_exp(&(String){1, 0, ""}, &st_exp, &glob->end))
  CHECK(add_node(write_while, st_exp))
  return OK;
}
/* for */
typedef struct St_for St_for; struct St_for {
  String* counter;
  St_exp* start;
  St_exp* limit;
};
Returncode write_for(St_for* st_for) {
  CHECK(write_exp_intro(st_for->start))
  CHECK(write_exp_intro(st_for->limit))
  CHECK(write(&(String){5, 4, "Int "}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){8, 7, "; for ("}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){4, 3, " = "}))
  if (st_for->start == NULL) {
    CHECK(write(&(String){2, 1, "0"}))
  }
  else {
    CHECK(write_exp(st_for->start))
  }
  CHECK(write(&(String){3, 2, "; "}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){4, 3, " < "}))
  CHECK(write_exp(st_for->limit))
  CHECK(write(&(String){5, 4, "; ++"}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){2, 1, ")"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_for() {
  St_for* st_for = malloc(sizeof(St_for)); if (st_for == NULL) RAISE
  CHECK(read_new(&(String){2, 1, " "}, &st_for->counter, &glob->end))
  /* ignore "in " */
  CHECK(read_ignore(3))
  st_for->start = NULL;
  CHECK(parse_exp(&(String){2, 1, ":"}, &st_for->limit, &glob->end)) if (glob->end == ':') {
    st_for->start = st_for->limit;
    CHECK(parse_exp(&(String){1, 0, ""}, &st_for->limit, &glob->end))
  }
  CHECK(add_node(write_for, st_for))
  CHECK(f_start_block())
  return OK;
}
/* class */
Returncode write_class_members(St* self_node, Bool is_func) {
  St* son = self_node->first_son;
  while (true) {
    if (not(son != NULL)) break;
    glob->curr = son;
    if (is_func == (son->f_writer == write_func) and son->f_writer != write_empty_line) {
      CHECK(write_spaces())
      CHECK(son->f_writer(son->value))
    }
    son = son->next_brother;
    glob->curr = glob->curr->father;
  }
  return OK;
}
Returncode write_class(St_class* st_class) {
  String* class_name = st_class->type_attrs->name;
  CHECK(write(&(String){16, 15, "typedef struct "}))
  CHECK(write_cstyle(class_name))
  CHECK(write(&(String){2, 1, " "}))
  CHECK(write_cstyle(class_name))
  CHECK(write(&(String){10, 9, "; struct "}))
  CHECK(write_cstyle(class_name))
  CHECK(write(&(String){4, 3, " {\n"}))
  /* write members */
  glob->spaces = glob->spaces + 2;
  glob->st_class = st_class;
  if (st_class->type_attrs->base_type != NULL) {
    CHECK(write_spaces())
    CHECK(write_cstyle(st_class->type_attrs->base_type->name))
    CHECK(write(&(String){9, 8, " _base;\n"}))
  }
  else if (st_class->type_attrs->is_dynamic) {
    CHECK(write_spaces())
    CHECK(write(&(String){13, 12, "Func* _dtl;\n"}))
  }
  St* self_node = glob->curr;
  CHECK(write_class_members(self_node, false))
  CHECK(write_block_close())
  CHECK(write(&(String){3, 2, ";\n"}))
  CHECK(write_class_members(self_node, true))
  glob->st_class = NULL;
  if (st_class->type_attrs->is_dynamic) {
    CHECK(write_spaces())
    CHECK(write(&(String){6, 5, "Func "}))
    CHECK(write_cstyle(class_name))
    CHECK(write(&(String){12, 11, "__dtl[] = {"}))
    St* son = self_node->first_son;
    Bool not_first = false;
    while (true) {
      if (not(son != NULL)) break;
      if (son->f_writer == write_func) {
        St_func* st_func = son->value;
        if (st_func->is_dynamic) {
          if (not_first) {
            CHECK(write(&(String){3, 2, ", "}))
          }
          CHECK(write_cstyle(class_name))
          CHECK(write(&(String){2, 1, "_"}))
          CHECK(write_cstyle(st_func->path->name))
          not_first = true;
        }
      }
      son = son->next_brother;
    }
    CHECK(write(&(String){4, 3, "};\n"}))
  }
  return OK;
}
Returncode parse_class(Bool is_dynamic) {
  String* name = &(String){256, 0, (char[256]){0}};
  String* base_name = &(String){256, 0, (char[256]){0}};
  CHECK(read(&(String){2, 1, "("}, name, &glob->end))
  CHECK(read(&(String){2, 1, ")"}, base_name, &glob->end))
  CHECK(read_c(&glob->end))
  CHECK(string_equal(base_name, &(String){7, 6, "Object"}, &glob->flag)) if (glob->flag) {
    CHECK(add_type(name, NULL, NULL))
  }
  else {
    CHECK(add_type(name, base_name, NULL))
  }
  St_class* st_class = malloc(sizeof(St_class)); if (st_class == NULL) RAISE
  st_class->type_attrs = glob->type_map->value;
  st_class->type_attrs->is_dynamic = is_dynamic;
  glob->st_class = st_class;
  CHECK(add_node(write_class, st_class))
  CHECK(f_start_block())
  return OK;
}
Returncode parse_dynamic_class() {
  CHECK(parse_class(true))
  return OK;
}
Returncode parse_static_class() {
  CHECK(parse_class(false))
  return OK;
}
/* call */
Returncode write_call(St_func* st_func) {
  CHECK(write_func_call(st_func))
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_call(Member_path* mpath) {
  St_func* st_func;
  CHECK(parse_func_header(mpath, &st_func, &glob->end))
  CHECK(add_node(write_call, st_func))
  return OK;
}
/* assign */
typedef struct St_assign St_assign; struct St_assign {
  St_exp* target;
  St_exp* value;
};
Returncode write_assign(St_assign* st_assign) {
  CHECK(write_exp_intro(st_assign->value))
  CHECK(write_exp_intro(st_assign->target))
  CHECK(write_exp(st_assign->target))
  CHECK(write(&(String){4, 3, " = "}))
  Var_attrs* var_attrs;
  CHECK(f_get_mpath_attrs(st_assign->target, &var_attrs))
  if (var_attrs == NULL) {
    CHECK(write_exp(st_assign->value))
  }
  else {
    CHECK(write_exp_typed(st_assign->value, var_attrs->type_attrs))
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_assign(Member_path* mpath, Char end) {
  St_assign* st_assign = malloc(sizeof(St_assign)); if (st_assign == NULL) RAISE
  St_exp* target = malloc(sizeof(St_exp)); if (target == NULL) RAISE
  target->next = NULL;
  target->operator = NULL;
  target->item = mpath;
  target->call = NULL;
  target->subexp = NULL;
  if (end == '[') {
    CHECK(parse_exp(&(String){2, 1, "]"}, &target->subexp, &glob->end))
    CHECK(read_ignore(1))
  }
  st_assign->target = target;
  /* ignore ":= " */
  CHECK(read_ignore(3))
  CHECK(parse_exp(&(String){1, 0, ""}, &st_assign->value, &glob->end))
  CHECK(add_node(write_assign, st_assign))
  return OK;
}
/* member path */
Returncode parse_member_path(String* name) {
  Member_path* mem_path = malloc(sizeof(Member_path)); if (mem_path == NULL) RAISE
  Member_path* mpath = mem_path;
  CHECK(f_new_copy(name, &mpath->name))
  while (true) {
    Member_path* new_mpath = malloc(sizeof(Member_path)); if (new_mpath == NULL) RAISE
    mpath->next = new_mpath;
    mpath = new_mpath;
    mpath->next = NULL;
    CHECK(read_new(&(String){5, 4, " .(["}, &mpath->name, &glob->end)) if (not(glob->end == '.')) break;
  }
  if (glob->end == '(') {
    CHECK(parse_call(mem_path))
  }
  else {
    CHECK(parse_assign(mem_path, glob->end))
  }
  return OK;
}
/* lines */
Returncode parse_line(Bool* more_lines) {
  String* key_word = &(String){80, 0, (char[80]){0}};
  Int spaces;
  Char end;
  CHECK(read_indent(&(String){5, 4, " .(["}, true, key_word, &end, &spaces))
  if (end == EOF) {
    *more_lines = false;
    return OK;
  }
  *more_lines = true;
  while (true) {
    if (not(spaces < glob->spaces)) break;
    CHECK(f_end_block())
  }
  CHECK(string_equal(key_word, &(String){1, 0, ""}, &glob->flag)) if (glob->flag) {
    CHECK(add_empty_line())
    return OK;
  }
  if (end == '(') {
    Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
    CHECK(f_new_copy(key_word, &mpath->name))
    mpath->next = NULL;
    CHECK(parse_call(mpath))
  }
  else if (end == '.') {
    CHECK(parse_member_path(key_word))
  }
  else {
    Bool parsed = false;
    if (end != '[') {
      Func f_parser;
      CHECK(f_fm_find(glob->key_word_map, key_word, &f_parser, &parsed)) if (parsed) {
        CHECK(f_parser())
      }
    }
    if (not parsed) {
      Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
      CHECK(f_new_copy(key_word, &mpath->name))
      mpath->next = NULL;
      CHECK(parse_assign(mpath, end))
    }
  }
  return OK;
}
Returncode parse_lines() {
  Bool flag;
  while (true) {
    CHECK(parse_line(&flag)) if (not(flag)) break;
  }
  return OK;
}
/* global init */
Returncode f_create_key_word_map() {
  Array* key_word_map = new_array(19, sizeof(Func_map)); if (key_word_map == NULL) RAISE
  CHECK(add_fm(key_word_map, 0, &(String){2, 1, "#"}, parse_comment))
  CHECK(add_fm(key_word_map, 1, &(String){5, 4, "func"}, parse_func))
  CHECK(add_fm(key_word_map, 2, &(String){7, 6, "native"}, parse_native))
  CHECK(add_fm(key_word_map, 3, &(String){5, 4, "main"}, parse_main))
  CHECK(add_fm(key_word_map, 4, &(String){4, 3, "var"}, parse_var))
  CHECK(add_fm(key_word_map, 5, &(String){6, 5, "owner"}, parse_ref))
  CHECK(add_fm(key_word_map, 6, &(String){5, 4, "user"}, parse_ref))
  CHECK(add_fm(key_word_map, 7, &(String){4, 3, "new"}, parse_new))
  CHECK(add_fm(key_word_map, 8, &(String){7, 6, "delete"}, parse_delete))
  CHECK(add_fm(key_word_map, 9, &(String){3, 2, "if"}, parse_if))
  CHECK(add_fm(key_word_map, 10, &(String){5, 4, "else"}, parse_else))
  CHECK(add_fm(key_word_map, 11, &(String){8, 7, "else-if"}, parse_else_if))
  CHECK(add_fm(key_word_map, 12, &(String){3, 2, "do"}, parse_do))
  CHECK(add_fm(key_word_map, 13, &(String){6, 5, "while"}, parse_while))
  CHECK(add_fm(key_word_map, 14, &(String){4, 3, "for"}, parse_for))
  CHECK(add_fm(key_word_map, 15, &(String){7, 6, "return"}, parse_return))
  CHECK(add_fm(key_word_map, 16, &(String){6, 5, "raise"}, parse_raise))
  CHECK(add_fm(key_word_map, 17, &(String){7, 6, "static"}, parse_static_class))
  CHECK(add_fm(key_word_map, 18, &(String){6, 5, "class"}, parse_dynamic_class))
  glob->key_word_map = key_word_map;
  return OK;
}
Returncode f_new_substing(String* text, String* ends, String** substing, Int* end, Char* endch) {
  Int start = end[0];
  Int index = start;
  Char ch;
  while (true) {
    ch = EOF;
    if (not(index < text->actual_length)) break;
    Bool has_end;
    CHECK(string_get(text, index, &ch))
    CHECK(string_has(ends, ch, &has_end)) if (not(has_end == false)) break;
    index = index + 1;
  }
  if ((start) + (index - start) > text->actual_length) RAISE String* sub = &(String){index - start, index - start, text->chars + start};
  CHECK(f_new_copy(sub, substing))
  *end = index + 1;
  *endch = ch;
  return OK;
}
Returncode add_args(String* header, St_arg** args, Int* index, Char* endch) {
  Char end;
  St_arg* prev = NULL;
  *args = NULL;
  while (true) {
    St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
    param->next = NULL;
    param->type_param = NULL;
    CHECK(f_new_substing(header, &(String){2, 1, " "}, &param->access, index, &end))
    CHECK(f_new_substing(header, &(String){3, 2, " {"}, &param->typename, index, &end))
    if (end == '{') {
      CHECK(f_new_substing(header, &(String){2, 1, " "}, &param->type_param, index, &end))
    }
    String* value;
    CHECK(f_new_substing(header, &(String){3, 2, ",)"}, &value, index, &end))
    param->value = value;
    if (prev == NULL) {
      *args = param;
    }
    else {
      prev->next = param;
    }
    prev = param;
    if (not(end == ',')) break;
  }
  *endch = end;
  return OK;
}
Returncode add_meth(String* header, Type_attrs* func_type, Name_map** members) {
  St_func* st_func = malloc(sizeof(St_func)); if (st_func == NULL) RAISE
  Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
  mpath->next = NULL;
  Int index = 0;
  Char end;
  CHECK(f_new_substing(header, &(String){3, 2, "()"}, &mpath->name, &index, &end))
  st_func->path = mpath;
  st_func->last = NULL;
  if (end == '(') {
    CHECK(add_args(header, &st_func->params, &index, &end))
  }
  if (end == ')') {
    CHECK(add_args(header, &st_func->outputs, &index, &end))
  }
  CHECK(add_member(mpath->name, func_type, st_func, members))
  return OK;
}
Returncode f_add_op(String* op_name, String* op_c_name) {
  String* name;
  CHECK(f_new_copy(op_name, &name))
  String* c_name;
  CHECK(f_new_copy(op_c_name, &c_name))
  CHECK(f_nm_init(name, c_name, &glob->op_map))
  return OK;
}
Returncode f_add_op_copy(String* name) {
  CHECK(f_add_op(name, name))
  return OK;
}
Returncode f_create_name_maps() {
  glob->op_map = NULL;
  glob->type_map = NULL;
  glob->var_map = NULL;
  /* Operands */
  CHECK(f_add_op_copy(&(String){2, 1, "+"}))
  CHECK(f_add_op_copy(&(String){2, 1, "-"}))
  CHECK(f_add_op_copy(&(String){2, 1, "*"}))
  CHECK(f_add_op_copy(&(String){2, 1, "/"}))
  CHECK(f_add_op(&(String){2, 1, "="}, &(String){3, 2, "=="}))
  CHECK(f_add_op_copy(&(String){3, 2, "!="}))
  CHECK(f_add_op_copy(&(String){2, 1, ">"}))
  CHECK(f_add_op_copy(&(String){2, 1, "<"}))
  CHECK(f_add_op_copy(&(String){3, 2, ">="}))
  CHECK(f_add_op_copy(&(String){3, 2, "<="}))
  CHECK(f_add_op(&(String){2, 1, "?"}, &(String){9, 8, "NULL != "}))
  CHECK(f_add_op(&(String){4, 3, "not"}, &(String){2, 1, "!"}))
  CHECK(f_add_op(&(String){3, 2, "or"}, &(String){3, 2, "||"}))
  CHECK(f_add_op(&(String){4, 3, "and"}, &(String){3, 2, "&&"}))
  /* Func */
  CHECK(add_type(&(String){5, 4, "Func"}, NULL, NULL))
  Type_attrs* func_type = glob->type_map->value;
  /* Int */
  Name_map* members_int = NULL;
  CHECK(add_meth(&(String){33, 32, "str(user Int self)var String str"}, func_type, &members_int))
  CHECK(add_type(&(String){4, 3, "Int"}, NULL, members_int))
  Type_attrs* type_int = glob->type_map->value;
  /* Char */
  CHECK(add_type(&(String){5, 4, "Char"}, NULL, NULL))
  /* Bool */
  CHECK(add_type(&(String){5, 4, "Bool"}, NULL, NULL))
  /* Type */
  CHECK(add_type(&(String){5, 4, "Type"}, NULL, NULL))
  CHECK(add_type(&(String){3, 2, "As"}, NULL, NULL))
  /* String */
  Name_map* members_string = NULL;
  CHECK(add_member(&(String){7, 6, "length"}, type_int, NULL, &members_string))
  CHECK(add_member(&(String){11, 10, "max-length"}, type_int, NULL, &members_string))
  CHECK(add_meth(&(String){23, 22, "clear(user String self"}, func_type, &members_string))
  CHECK(add_meth(&(String){59, 58, "equal(user String self,user String pattern)copy Bool equal"}, func_type, &members_string))
  CHECK(add_meth(&(String){49, 48, "get(user String self,copy Int index)copy Char ch"}, func_type, &members_string))
  CHECK(add_meth(&(String){37, 36, "append(user String self,copy Char ch"}, func_type, &members_string))
  CHECK(add_meth(&(String){40, 39, "copy(user String self,user String other"}, func_type, &members_string))
  CHECK(add_meth(&(String){42, 41, "concat(user String self,user String other"}, func_type, &members_string))
  CHECK(add_meth(&(String){57, 56, "find(user String self,user String pattern)copy Int index"}, func_type, &members_string))
  CHECK(add_meth(&(String){57, 56, "replace(user String self,copy Char oldch,copy Char newch"}, func_type, &members_string))
  CHECK(add_meth(&(String){48, 47, "has(user String self,copy Char ch)copy Bool has"}, func_type, &members_string))
  CHECK(add_type(&(String){7, 6, "String"}, NULL, members_string))
  /* Array */
  Name_map* members_array = NULL;
  CHECK(add_member(&(String){7, 6, "length"}, type_int, NULL, &members_array))
  CHECK(add_type(&(String){6, 5, "Array"}, NULL, members_array))
  /* File */
  Name_map* members_file = NULL;
  CHECK(add_meth(&(String){21, 20, "close(user File self"}, func_type, &members_file))
  CHECK(add_meth(&(String){33, 32, "getc(user File self)copy Char ch"}, func_type, &members_file))
  CHECK(add_meth(&(String){33, 32, "putc(user File self,copy Char ch"}, func_type, &members_file))
  CHECK(add_meth(&(String){38, 37, "write(user File self,user String text"}, func_type, &members_file))
  CHECK(add_type(&(String){5, 4, "File"}, NULL, members_file))
  CHECK(add_meth(&(String){48, 47, "file-open-read(user String name)owner File file"}, func_type, &glob->var_map))
  CHECK(add_meth(&(String){49, 48, "file-open-write(user String name)owner File file"}, func_type, &glob->var_map))
  /* Sys */
  Name_map* members_sys = NULL;
  CHECK(add_meth(&(String){37, 36, "print(user Sys self,user String text"}, func_type, &members_sys))
  CHECK(add_meth(&(String){35, 34, "exit(user Sys self,copy Int status"}, func_type, &members_sys))
  CHECK(add_meth(&(String){57, 56, "system(user Sys self,user String command)copy Int status"}, func_type, &members_sys))
  CHECK(add_meth(&(String){72, 71, "getenv(user Sys self,user String name)var String value,copy Bool exists"}, func_type, &members_sys))
  CHECK(add_type(&(String){4, 3, "Sys"}, NULL, members_sys))
  return OK;
}
Returncode f_init_glob_state(St* root) {
  glob->curr = root;
  glob->spaces = 0;
  glob->st_class = NULL;
  glob->var_count = 0;
  return OK;
}
/* compile */
Returncode f_compile_file(Array* argv, Int index) {
  /* get file names */
  String* infile_name;
  if (index < 0 || index >= argv->length) RAISE infile_name = ((String*)(argv->values)) + index;
  CHECK(string_has(infile_name, '"', &glob->flag)) if (glob->flag) {
    CHECK(f_msg_raise(&(String){34, 33, "Illegal \" character in argument '"}, infile_name, &(String){2, 1, "'"}))
  }
  if (infile_name->actual_length < 6) {
    CHECK(f_msg_raise(&(String){21, 20, "too short argument \""}, infile_name, &(String){2, 1, "\""}))
  }
  String* outfile_name = new_string(infile_name->actual_length); if (outfile_name == NULL) RAISE
  if ((0) + (infile_name->actual_length - 4) > infile_name->actual_length) RAISE String* prefix = &(String){infile_name->actual_length - 4, infile_name->actual_length - 4, infile_name->chars + 0};
  CHECK(string_copy(outfile_name, prefix))
  CHECK(string_append(outfile_name, 'c'))
  
  /* init root node */
  CHECK(f_st_new(write_sons, NULL, NULL, &glob->curr))
  St* root = glob->curr;
  
  /* parse */
  CHECK(print(infile_name))
  CHECK(file_open_read(infile_name, &glob->infile))
  CHECK(print(&(String){11, 10, "parsing..."}))
  CHECK(f_init_glob_state(root))
  glob->line_num = 0;
  CHECK(parse_lines())
  CHECK(file_close(glob->infile))
  
  /* write */
  CHECK(file_open_write(outfile_name, &glob->outfile))
  CHECK(print(&(String){11, 10, "writing..."}))
  CHECK(f_init_glob_state(root))
  if (index == argv->length - 1) {
    CHECK(write(&(String){19, 18, "#include \"mr.2.h\"\n"}))
    Int index = 1;
    while (true) {
      if (not(index < argv->length - 1)) break;
      String* infile_name;
      if (index < 0 || index >= argv->length) RAISE infile_name = ((String*)(argv->values)) + index;
      if ((0) + (infile_name->actual_length - 4) > infile_name->actual_length) RAISE String* prefix = &(String){infile_name->actual_length - 4, infile_name->actual_length - 4, infile_name->chars + 0};
      CHECK(write(&(String){11, 10, "#include \""}))
      CHECK(write(prefix))
      CHECK(write(&(String){4, 3, "c\"\n"}))
      index = index + 1;
    }
    CHECK(write(&(String){2, 1, "\n"}))
  }
  String* index_str = &(String){64, 0, (char[64]){0}};
  CHECK(int_to_string(index, index_str))
  CHECK(write(&(String){22, 21, "static char* _mr_file"}))
  CHECK(write(index_str))
  CHECK(write(&(String){10, 9, "_name = \""}))
  CHECK(write(infile_name))
  CHECK(write(&(String){33, 32, "\";\n#define MR_FILE_NAME _mr_file"}))
  CHECK(write(index_str))
  CHECK(write(&(String){7, 6, "_name\n"}))
  CHECK(root->f_writer())
  CHECK(write(&(String){22, 21, "\n#undef MR_FILE_NAME\n"}))
  CHECK(file_close(glob->outfile))
  
  /* finalize */
  glob->var_map = root->var_map;
  free(outfile_name);
  return OK;
}
/* main */
Returncode func(Array* argv) {
  CHECK(print(&(String){18, 17, "MR compiler start"}))
  
  if (argv->length < 2) {
    CHECK(print(&(String){40, 39, "usage: mr2-compiler [input MR files]..."}))
    return OK;
  }
  /* init global data */
  CHECK(f_create_key_word_map())
  CHECK(f_create_name_maps())
  
  Int index = 1;
  while (true) {
    if (not(index < argv->length)) break;
    CHECK(f_compile_file(argv, index))
    index = index + 1;
  }
  CHECK(print(&(String){16, 15, "MR compiler end"}))
  return OK;
}

MAIN_FUNC
