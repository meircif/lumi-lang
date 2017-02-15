#include "mr.1.h"

/* MR2 compiler - written in MR1 */

Returncode print(String* text);

typedef void File;
Returncode file_open_read(String* name, File** file);
Returncode file_open_write(String* name, File** file);
Returncode file_close(File* this);
Returncode file_getc(File* this, Char* ch);
Returncode file_putc(File* this, Char ch);
Returncode file_write(File* this, String* line);

Returncode string_clear(String* this);
Returncode string_length(String* this, Int* length);
Returncode string_equal(String* this, String* other, Bool* equal);
Returncode string_get(String* this, Int index, Char* ch);
Returncode string_append(String* this, Char ch);
Returncode string_copy(String* this, String* source);
Returncode string_concat(String* this, String* ext);
Returncode string_find(String* this, String* pattern, Int* index);
Returncode string_replace(String* this, Char old_ch, Char new_ch);
Returncode string_has(String* this, Char ch, Bool* found);
Returncode int_to_string(Int value, String* str);

Returncode array_length(Array* arr, Int* length);

Returncode sys_exit(Int status);
Returncode sys_system(String* command, Int* status);
Returncode sys_getenv(String* name, Bool* exists, String* value);


typedef void Generic;


Returncode new_copy(String* text, String** out_text) {
  if (text == NULL) {
    RAISE
  }
  String* new_text = new_string(text->actual_length + 1); if (new_text == NULL) RAISE
  CHECK(string_copy(new_text, text))
  *out_text = new_text;
  return OK;
}

/* Function Map */
typedef struct Func_map Func_map; struct Func_map {
  String* key;
  Func value;
};
Returncode fm_add(Array* map, Int index, String* key, Func value) {
  Func_map* fm = &(Func_map){0};
  if (index < 0 || index >= map->length) RAISE fm = ((Func_map*)(map->values)) + index;
  CHECK(new_copy(key, &fm->key))
  fm->value = value;
  return OK;
}
Returncode fm_find(Array* map, String* key, Func* value, Bool* found) {
  Int n; for (n = 0; n < map->length; ++n) {
    Func_map* fm = &(Func_map){0};
    if (n < 0 || n >= map->length) RAISE fm = ((Func_map*)(map->values)) + n;
    Bool flag;
    CHECK(string_equal(key, fm->key, &flag)) if (flag) {
      *found = true;
      *value = fm->value;
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
};
typedef struct Var_attrs Var_attrs; struct Var_attrs {
  String* name;
  Type_attrs* type_attrs;
  Type_attrs* subtype;
  String* access;
  Bool is_ref;
};
Returncode nm_init(String* name, Generic* value, Name_map** nm_ptr) {
  Name_map* nm = malloc(sizeof(Name_map)); if (nm == NULL) RAISE
  nm->next = nm_ptr[0];
  nm->name = name;
  nm->value = value;
  *nm_ptr = nm;
  return OK;
}
Returncode nm_find(Name_map* self, String* name, Generic** value) {
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
Returncode add_member(String* name, Type_attrs* type_attrs, Type_attrs* subtype, Name_map** members) {
  Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
  CHECK(new_copy(name, &new_var->name))
  new_var->type_attrs = type_attrs;
  new_var->subtype = subtype;
  new_var->is_ref = false;
  CHECK(nm_init(new_var->name, new_var, members))
  return OK;
}
/* Syntax Tree */
typedef struct St St; struct St {
  St* next_brother;
  St* first_son;
  St* last_son;
  St* father;
  Func writer;
  Generic* value;
  Name_map* var_map;
  Bool in_class;
  /* place */
  String* file_name;
  String* func_name;
  Int line_num;
};
Returncode st_del(St* self) {
  if (self == NULL) {
    return OK;
  }
  CHECK(st_del(self->first_son))
  CHECK(st_del(self->next_brother))
  free(self);
  return OK;
}
/* Global data */
typedef struct Global_data Global_data; struct Global_data {
  /* data */
  File* infile;
  File* outfile;
  Array* key_word_map;
  Name_map* type_map;
  Name_map* var_map;
  /* place */
  String* file_name;
  String* func_name;
  Int line_num;
  /* state */
  St* curr;
  Int spaces;
  Type_attrs* class_attrs;
  /* vars */
  Int length;
  Bool flag;
  Char end;
};
Global_data* glob = &(Global_data){0};

Returncode st_new(Func writer, Generic* value, St* father, Bool in_class, St** res) {
  St* self = malloc(sizeof(St)); if (self == NULL) RAISE
  self->next_brother = NULL;
  self->first_son = NULL;
  self->last_son = NULL;
  self->father = father;
  self->writer = writer;
  self->value = value;
  self->in_class = in_class;
  self->file_name = glob->file_name;
  self->func_name = glob->func_name;
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
    self->var_map = NULL;
  }
  return OK;
}
Returncode add_type(String* name, Name_map* members) {
  Type_attrs* new_type = malloc(sizeof(Type_attrs)); if (new_type == NULL) RAISE
  CHECK(new_copy(name, &new_type->name))
  new_type->members = members;
  Name_map* nm = malloc(sizeof(Name_map)); if (nm == NULL) RAISE
  CHECK(nm_init(new_type->name, new_type, &glob->type_map))
  return OK;
}
Returncode find_type(String* name, Type_attrs** type_attr) {
  Generic* value;
  CHECK(nm_find(glob->type_map, name, &value))
  if (value == NULL) {
    String* msg = &(String){256, 0, (char[256]){0}};
    CHECK(string_copy(msg, &(String){16, 15, "Undefined type "}))
    CHECK(string_concat(msg, name))
    CHECK(print(msg))
    RAISE
  }
  *type_attr = value;
  return OK;
}
Returncode find_var(Name_map* nm, String* name, Var_attrs** var_attr) {
  Generic* value;
  CHECK(nm_find(nm, name, &value))
  if (value == NULL) {
    String* msg = &(String){256, 0, (char[256]){0}};
    CHECK(string_copy(msg, &(String){20, 19, "Undefined variable "}))
    CHECK(string_concat(msg, name))
    CHECK(print(msg))
    RAISE
  }
  *var_attr = value;
  return OK;
}
/* read helpers */
Returncode readc(Char* out_ch) {
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
    CHECK(readc(&glob->end))
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
    CHECK(readc(&ch))
    if (indent) {
      while (true) {
        if (not(ch == ' ')) break;
        spaces = spaces + 1;
        CHECK(readc(&ch))
      }
      indent = false;
    }
    if (not(ch != EOF)) break;
    if (q != '\0') {
      if (ch == '\\') {
        CHECK(string_append(text, ch))
        CHECK(readc(&ch))
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
  CHECK(new_copy(text, out_text))
  return OK;
}
/* write helpers */
Returncode writec(Char ch) {
  CHECK(file_putc(glob->outfile, ch))
  return OK;
}
Returncode write(String* text) {
  CHECK(file_write(glob->outfile, text))
  return OK;
}
Returncode write_csyle_char(Char ch, Char prev) {
  if (ch == '-' and prev != ' ') {
    CHECK(writec('_'))
  }
  else if (ch == '.') {
    CHECK(write(&(String){3, 2, "->"}))
  }
  else if (ch == '=' and prev == ' ') {
    CHECK(write(&(String){3, 2, "=="}))
  }
  else if (ch != ':') {
    CHECK(writec(ch))
  }
  return OK;
}
Returncode write_cstyle(String* text) {
  if (text == NULL) {
    RAISE
  }
  Char prev = ' ';
  Int index; for (index = 0; index < text->actual_length; ++index) {
    Char ch;
    CHECK(string_get(text, index, &ch))
    CHECK(write_csyle_char(ch, prev))
    prev = ch;
  }
  return OK;
}
Returncode write_traceback_args() {
  CHECK(write(&(String){2, 1, "\""}))
  CHECK(write(glob->curr->file_name))
  CHECK(write(&(String){4, 3, "\", "}))
  String* line_num_str = &(String){64, 0, (char[64]){0}};
  CHECK(int_to_string(glob->curr->line_num, line_num_str))
  CHECK(write(line_num_str))
  CHECK(write(&(String){4, 3, ", \""}))
  if (glob->curr->func_name != NULL) {
    CHECK(write(glob->curr->func_name))
  }
  CHECK(write(&(String){2, 1, "\""}))
  return OK;
}
Returncode write_tb_raise() {
  CHECK(write(&(String){7, 6, "RAISE("}))
  CHECK(write_traceback_args())
  CHECK(write(&(String){2, 1, ")"}))
  return OK;
}
Returncode write_tb_check() {
  CHECK(write(&(String){7, 6, "CHECK("}))
  CHECK(write_traceback_args())
  CHECK(write(&(String){3, 2, ", "}))
  return OK;
}
/* other helpers */
Returncode add_node(Func writer, Generic* value) {
  St* node;
  CHECK(st_new(writer, value, glob->curr, false, &node))
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
Returncode is_primitive(String* typename, Bool* res) {
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
    CHECK(son->writer(son->value))
    son = glob->curr->next_brother;
    glob->curr = glob->curr->father;
  }
  return OK;
}
Returncode start_block() {
  glob->spaces = glob->spaces + 2;
  glob->curr = glob->curr->last_son;
  return OK;
}
Returncode end_block() {
  glob->curr = glob->curr->father;
  glob->spaces = glob->spaces - 2;
  if (glob->spaces == 0) {
    glob->class_attrs = NULL;
  }
  return OK;
}
Returncode write_block_suffix(String* suffix) {
  CHECK(write(&(String){4, 3, " {\n"}))
  glob->spaces = glob->spaces + 2;
  CHECK(write_sons())
  glob->spaces = glob->spaces - 2;
  CHECK(write_spaces())
  CHECK(write(&(String){2, 1, "}"}))
  CHECK(write(suffix))
  return OK;
}
Returncode write_block() {
  CHECK(write_block_suffix(&(String){2, 1, "\n"}))
  return OK;
}
/* empty */
Returncode write_empty(Generic* null) {
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode add_empty() {
  CHECK(add_node(write_empty, NULL))
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
Returncode write_mpath(Member_path* mem_path, Bool write_last) {
  Member_path* mpath = mem_path;
  Generic* value;
  CHECK(nm_find(glob->curr->var_map, mpath->name, &value))
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
    mpath = mpath->next;
    if (not(mpath != NULL and (write_last or mpath->next != NULL))) break;
    CHECK(write(&(String){3, 2, "->"}))
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
};
typedef struct St_exp St_exp; struct St_exp {
  St_exp* next;
  String* operator;
  Member_path* item;
  St_func* call;
  St_exp* subexp;
  St_exp* slice_length;
};
Returncode real_string_length(String* text, Int* length) {
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
  CHECK(find_var(glob->curr->var_map, st_exp->item->name, &var_attrs))
  Member_path* mpath = st_exp->item;
  while (true) {
    if (not(mpath->next != NULL)) break;
    mpath = mpath->next;
    CHECK(find_var(var_attrs->type_attrs->members, mpath->name, &var_attrs))
  }
  String* typename = var_attrs->type_attrs->name;
  Bool is_array;
  CHECK(string_equal(typename, &(String){6, 5, "Array"}, &is_array)) if (is_array) {
    if (var_attrs->subtype == NULL) {
      CHECK(print(mpath->name))
      RAISE
    }
    typename = var_attrs->subtype->name;
  }
  if (st_exp->slice_length == NULL) {
    if (is_array) {
      CHECK(write(&(String){3, 2, "(("}))
      CHECK(write_cstyle(typename))
      CHECK(write(&(String){4, 3, "*)("}))
      CHECK(write_mpath(st_exp->item, true))
      CHECK(write(&(String){11, 10, "->values))"}))
      CHECK(is_primitive(typename, &glob->flag)) if (glob->flag) {
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
    CHECK(real_string_length(mpath->name, &glob->length))
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
  else {
    CHECK(write_mpath(mpath, true))
  }
  return OK;
}
Returncode write_exp(St_exp* st_exp) {
  if (st_exp == NULL) {
    RAISE
  }
  if (st_exp->call != NULL) {
    St_arg* last = st_exp->call->outputs;
    if (last == NULL) {
      RAISE
    }
    while (true) {
      if (not(last->next != NULL)) break;
      last = last->next;
    }
    CHECK(write_mpath(last->value, true))
  }
  else if (st_exp->item == NULL) {
    if (st_exp->subexp != NULL) {
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
    CHECK(write(&(String){2, 1, " "}))
    CHECK(write_cstyle(st_exp->operator))
  }
  if (st_exp->next != NULL) {
    CHECK(write(&(String){2, 1, " "}))
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
      CHECK(readc(&end))
      free(st_exp->item);
    }
    st_exp->item = NULL;
  }
  else if (end == '[') {
    CHECK(parse_exp(&(String){3, 2, ":]"}, &st_exp->subexp, &end))
    if (end == ':') {
      CHECK(parse_exp(&(String){2, 1, "]"}, &st_exp->slice_length, &end))
    }
    CHECK(readc(&end))
    if (end == '.') {
      CHECK(new_copy(&(String){3, 2, "->"}, &st_exp->operator))
      CHECK(parse_exp(exp_ends, &st_exp->next, &end))
    }
  }
  if (end == ' ') {
    CHECK(read_new(&(String){2, 1, " "}, &st_exp->operator, &end))
    CHECK(parse_exp(exp_ends, &st_exp->next, &end))
  }
  *new_st_exp = st_exp;
  *out_end = end;
  return OK;
}
/* function */
Returncode write_func_call(St_func* st_func) {
  St_arg* arg = st_func->params;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(write_exp_intro(arg->value))
    arg = arg->next;
  }
  CHECK(write_tb_check())
  if (st_func->path->next != NULL) {
    Var_attrs* var_attrs;
    CHECK(find_var(glob->curr->var_map, st_func->path->name, &var_attrs))
    Member_path* mpath = st_func->path->next;
    while (true) {
      if (not(mpath->next != NULL)) break;
      CHECK(find_var(var_attrs->type_attrs->members, mpath->name, &var_attrs))
      mpath = mpath->next;
    }
    CHECK(write_cstyle(var_attrs->type_attrs->name))
    CHECK(write(&(String){2, 1, "_"}))
    CHECK(write_cstyle(mpath->name))
    CHECK(write(&(String){2, 1, "("}))
    CHECK(write_mpath(st_func->path, false))
    if (st_func->params != NULL or st_func->outputs != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  else {
    CHECK(write_mpath(st_func->path, true))
    CHECK(write(&(String){2, 1, "("}))
  }
  arg = st_func->params;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(write_exp(arg->value))
    arg = arg->next;
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
Returncode write_func_header(St_func* st_func) {
  CHECK(write(&(String){12, 11, "Returncode "}))
  if (glob->class_attrs != NULL) {
    CHECK(write_cstyle(glob->class_attrs->name))
    CHECK(write(&(String){2, 1, "_"}))
  }
  CHECK(write_cstyle(st_func->path->name))
  CHECK(write(&(String){2, 1, "("}))
  if (glob->class_attrs != NULL) {
    CHECK(write_cstyle(glob->class_attrs->name))
    CHECK(write(&(String){7, 6, "* self"}))
    if (st_func->params != NULL or st_func->outputs != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  CHECK(write_args(st_func->params, false, st_func->outputs))
  CHECK(write_args(st_func->outputs, true, NULL))
  CHECK(write(&(String){2, 1, ")"}))
  return OK;
}
Returncode parse_func_header(Member_path* path, St_func** st_func, Char* end) {
  St_func* new_func = malloc(sizeof(St_func)); if (new_func == NULL) RAISE
  if (path == NULL) {
    Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
    mpath->next = NULL;
    CHECK(read_new(&(String){2, 1, "("}, &mpath->name, &glob->end))
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(new_copy(mpath->name, &new_var->name))
    new_func->path = mpath;
    CHECK(find_type(&(String){5, 4, "Func"}, &new_var->type_attrs))
    new_var->subtype = NULL;
    new_var->is_ref = false;
    CHECK(nm_init(new_var->name, new_var, &glob->curr->var_map))
  }
  else {
    new_func->path = path;
  }
  new_func->params = NULL;
  new_func->outputs = NULL;
  St_arg* last = NULL;
  while (true) {
    String* access = &(String){256, 0, (char[256]){0}};
    CHECK(read(&(String){3, 2, " )"}, access, &glob->end)) if (not(glob->end == ' ')) break;
    St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
    param->next = NULL;
    param->typename = NULL;
    param->type_param = NULL;
    CHECK(new_copy(access, &param->access))
    if (path == NULL) {
      CHECK(read_new(&(String){3, 2, " {"}, &param->typename, &glob->end)) if (glob->end == '{') {
        CHECK(read_new(&(String){2, 1, "}"}, &param->type_param, &glob->end))
        CHECK(readc(&glob->end))
      }
    }
    if (path == NULL) {
      String* name;
      CHECK(read_new(&(String){3, 2, ",)"}, &name, &glob->end))
      param->value = name;
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
    CHECK(readc(&glob->end))
  }
  CHECK(readc(&glob->end))
  last = NULL;
  while (true) {
    if (not(glob->end != '\n')) break;
    CHECK(readc(&glob->end))
    St_arg* param = malloc(sizeof(St_arg)); if (param == NULL) RAISE
    param->next = NULL;
    CHECK(read_new(&(String){2, 1, " "}, &param->access, &glob->end))
    if (path == NULL) {
      CHECK(read_new(&(String){2, 1, " "}, &param->typename, &glob->end))
    }
    else {
      param->typename = NULL;
    }
    if (path == NULL) {
      String* name;
      CHECK(read_new(&(String){3, 2, ", "}, &name, &glob->end))
      param->value = name;
    }
    else {
      Member_path* mpath;
      CHECK(read_mpath(&(String){4, 3, "., "}, &mpath, &glob->end))
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
  *st_func = new_func;
  *end = glob->end;
  return OK;
}
/* func */
Returncode write_func(St_func* st_func) {
  CHECK(write_func_header(st_func))
  CHECK(write_block())
  return OK;
}
Returncode add_arg_vars(St_arg* first, Bool is_ref) {
  St_arg* arg = first;
  while (true) {
    if (not(arg != NULL)) break;
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(new_copy(arg->value, &new_var->name))
    CHECK(find_type(arg->typename, &new_var->type_attrs))
    new_var->subtype = NULL;
    if (arg->type_param != NULL) {
      CHECK(find_type(arg->type_param, &new_var->subtype))
    }
    CHECK(string_equal(arg->access, &(String){4, 3, "var"}, &glob->flag)) new_var->is_ref = glob->flag == false and is_ref;
    CHECK(nm_init(new_var->name, new_var, &glob->curr->var_map))
    arg = arg->next;
  }
  return OK;
}
Returncode parse_func_body(Func writer) {
  St_func* st_func;
  CHECK(parse_func_header(NULL, &st_func, &glob->end))
  glob->func_name = st_func->path->name;
  CHECK(add_node(writer, st_func))
  CHECK(start_block())
  /* add vars to var-map */
  if (glob->class_attrs != NULL) {
    Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
    CHECK(new_copy(&(String){5, 4, "self"}, &new_var->name))
    new_var->type_attrs = glob->class_attrs;
    new_var->subtype = NULL;
    new_var->is_ref = false;
    CHECK(nm_init(new_var->name, new_var, &glob->curr->var_map))
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
    CHECK(add_type(name, NULL))
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
  String* array_length;
  String* string_length;
  St_exp* init;
};
Returncode parse_dec(St_dec** new_st_dec) {
  St_dec* st_dec = malloc(sizeof(St_dec)); if (st_dec == NULL) RAISE
  st_dec->array_length = NULL;
  st_dec->string_length = NULL;
  st_dec->init = NULL;
  
  CHECK(read_new(&(String){3, 2, " {"}, &st_dec->typename, &glob->end))
  Bool is_array = false;
  Bool is_array_var = false;
  if (glob->end == '{') {
    CHECK(string_equal(st_dec->typename, &(String){6, 5, "Array"}, &is_array)) if (is_array) {
      CHECK(read_new(&(String){3, 2, "}:"}, &st_dec->array_length, &glob->end)) if (glob->end == ':') {
        is_array_var = true;
        CHECK(read_new(&(String){3, 2, "}{"}, &st_dec->typename, &glob->end))
      }
    }
    CHECK(string_equal(st_dec->typename, &(String){7, 6, "String"}, &glob->flag)) if (glob->flag) {
      CHECK(read_new(&(String){2, 1, "}"}, &st_dec->string_length, &glob->end))
      CHECK(readc(&glob->end))
    }
    if (is_array) {
      CHECK(readc(&glob->end))
    }
  }
  CHECK(read_new(&(String){2, 1, "("}, &st_dec->name, &glob->end)) if (glob->end == '(') {
    CHECK(parse_exp(&(String){2, 1, ")"}, &st_dec->init, &glob->end))
    
    CHECK(readc(&glob->end))
  }
  Var_attrs* new_var = malloc(sizeof(Var_attrs)); if (new_var == NULL) RAISE
  CHECK(new_copy(st_dec->name, &new_var->name))
  Type_attrs* type_attr;
  CHECK(find_type(st_dec->typename, &type_attr))
  new_var->subtype = NULL;
  if (is_array_var) {
    new_var->subtype = type_attr;
    CHECK(find_type(&(String){6, 5, "Array"}, &type_attr))
  }
  else if (is_array) {
    CHECK(find_type(st_dec->array_length, &new_var->subtype))
  }
  new_var->type_attrs = type_attr;
  new_var->is_ref = false;
  
  if (glob->class_attrs != NULL) {
    CHECK(nm_init(new_var->name, new_var, &glob->class_attrs->members))
  }
  else {
    CHECK(nm_init(new_var->name, new_var, &glob->curr->var_map))
  }
  *new_st_dec = st_dec;
  return OK;
}
/* var */
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
  CHECK(write(&(String){4, 3, "};\n"}))
  return OK;
}
Returncode write_var_string(St_dec* st_dec) {
  CHECK(write_exp_intro(st_dec->init))
  CHECK(write_ref_prefix(&(String){7, 6, "String"}, st_dec->name))
  CHECK(write(st_dec->string_length))
  CHECK(write(&(String){12, 11, ", 0, (char["}))
  CHECK(write(st_dec->string_length))
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
  CHECK(write(st_dec->array_length))
  CHECK(write(&(String){4, 3, ", ("}))
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){2, 1, "["}))
  CHECK(write(st_dec->array_length))
  CHECK(write(&(String){8, 7, "]){0}};"}))
  
  if (st_dec->string_length != NULL) {
    CHECK(write_new_indent_line())
    CHECK(write(&(String){7, 6, "char _"}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){8, 7, "_chars["}))
    CHECK(write(st_dec->string_length))
    CHECK(write(&(String){3, 2, "]["}))
    CHECK(write(st_dec->array_length))
    CHECK(write(&(String){3, 2, "];"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){20, 19, "{int n; for(n=0; n<"}))
    CHECK(write(st_dec->array_length))
    CHECK(write(&(String){7, 6, "; ++n)"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){13, 12, " ((String*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){26, 25, "->values))[n] = (String){"}))
    CHECK(write(st_dec->string_length))
    CHECK(write(&(String){7, 6, ", 0, _"}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){13, 12, "_chars[n]};}"}))
  }
  CHECK(write(&(String){2, 1, "\n"}))
  return OK;
}
Returncode add_dec_node(Func writer, Generic* value) {
  St* node;
  CHECK(st_new(writer, value, glob->curr, glob->class_attrs != NULL, &node))
  return OK;
}
Returncode parse_var() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  
  if (st_dec->array_length != NULL) {
    CHECK(add_dec_node(write_var_array, st_dec))
    return OK;
  }
  if (st_dec->string_length != NULL) {
    CHECK(add_dec_node(write_var_string, st_dec))
    return OK;
  }
  CHECK(is_primitive(st_dec->typename, &glob->flag)) if (glob->flag) {
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
  if (st_dec->array_length != NULL) {
    CHECK(write(&(String){6, 5, "Array"}))
  }
  else {
    CHECK(write_cstyle(st_dec->typename))
  }
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){4, 3, " = "}))
  
  if (st_dec->array_length != NULL) {
    CHECK(write(&(String){11, 10, "new_array("}))
    CHECK(write_cstyle(st_dec->array_length))
    CHECK(write(&(String){10, 9, ", sizeof("}))
    CHECK(write_cstyle(st_dec->typename))
    CHECK(write(&(String){2, 1, ")"}))
    if (st_dec->string_length != NULL) {
      CHECK(write(&(String){5, 4, " + ("}))
      CHECK(write_cstyle(st_dec->string_length))
      CHECK(writec(')'))
    }
  }
  else if (st_dec->string_length != NULL) {
    CHECK(write(&(String){12, 11, "new_string("}))
    CHECK(write_cstyle(st_dec->string_length))
  }
  else {
    CHECK(write(&(String){15, 14, "malloc(sizeof("}))
    CHECK(write_cstyle(st_dec->typename))
    CHECK(writec(')'))
    
  }
  CHECK(write(&(String){3, 2, ");"}))
  CHECK(write_new_indent_line())
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){11, 10, " == NULL) "}))
  CHECK(write_tb_raise())
  
  if (st_dec->array_length != NULL and st_dec->string_length != NULL) {
    CHECK(write_new_indent_line())
    CHECK(write(&(String){21, 20, "{int n; for(n=0; n<("}))
    CHECK(write_cstyle(st_dec->array_length))
    CHECK(write(&(String){8, 7, "); ++n)"}))
    CHECK(write_new_indent_line())
    CHECK(write(&(String){13, 12, " ((String*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){26, 25, "->values))[n] = (String){"}))
    CHECK(write_cstyle(st_dec->string_length))
    CHECK(write(&(String){14, 13, ", 0, (Byte*)("}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){14, 13, "->values) + ("}))
    CHECK(write_cstyle(st_dec->array_length))
    CHECK(write(&(String){23, 22, ") * sizeof(String) + ("}))
    CHECK(write_cstyle(st_dec->string_length))
    CHECK(write(&(String){9, 8, ") * n};}"}))
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
  CHECK(start_block())
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
  CHECK(start_block())
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
  if (next != NULL and (next->writer == write_else or next->writer == write_else_if)) {
    glob->curr = next;
    CHECK(write_spaces())
    CHECK(next->writer(next->value))
  }
  glob->spaces = glob->spaces - 2;
  CHECK(write_spaces())
  CHECK(write(&(String){3, 2, "}\n"}))
  return OK;
}
Returncode parse_else_if() {
  St_exp* st_exp;
  CHECK(parse_exp(&(String){1, 0, ""}, &st_exp, &glob->end))
  CHECK(add_node(write_else_if, st_exp))
  CHECK(start_block())
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
  CHECK(start_block())
  return OK;
}
/* while */
Returncode write_while(St_exp* st_exp) {
  CHECK(write_exp_intro(st_exp))
  CHECK(write(&(String){9, 8, "if (not("}))
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
  St_exp* limit;
};
Returncode write_for(St_for* st_for) {
  CHECK(write_exp_intro(st_for->limit))
  CHECK(write(&(String){5, 4, "Int "}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){8, 7, "; for ("}))
  CHECK(write_cstyle(st_for->counter))
  CHECK(write(&(String){7, 6, " = 0; "}))
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
  CHECK(parse_exp(&(String){1, 0, ""}, &st_for->limit, &glob->end))
  CHECK(add_node(write_for, st_for))
  CHECK(start_block())
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
/* class */
Returncode write_class_members(St* self_node, Bool in_class) {
  St* son = self_node->first_son;
  while (true) {
    if (not(son != NULL)) break;
    glob->curr = son;
    if (son->in_class == in_class) {
      CHECK(write_spaces())
      CHECK(son->writer(son->value))
    }
    son = son->next_brother;
    glob->curr = glob->curr->father;
  }
  return OK;
}
Returncode write_class(Type_attrs* class_attrs) {
  CHECK(write(&(String){16, 15, "typedef struct "}))
  CHECK(write_cstyle(class_attrs->name))
  CHECK(write(&(String){2, 1, " "}))
  CHECK(write_cstyle(class_attrs->name))
  CHECK(write(&(String){10, 9, "; struct "}))
  CHECK(write_cstyle(class_attrs->name))
  CHECK(write(&(String){4, 3, " {\n"}))
  /* write members */
  glob->spaces = glob->spaces + 2;
  glob->class_attrs = class_attrs;
  St* self_node = glob->curr;
  CHECK(write_class_members(self_node, true))
  glob->spaces = glob->spaces - 2;
  CHECK(write_spaces())
  CHECK(write(&(String){4, 3, "};\n"}))
  CHECK(write_class_members(self_node, false))
  glob->class_attrs = NULL;
  return OK;
}
Returncode parse_class() {
  String* name = &(String){256, 0, (char[256]){0}};
  CHECK(read(&(String){1, 0, ""}, name, &glob->end))
  CHECK(add_type(name, NULL))
  Type_attrs* class_attrs = glob->type_map->value;
  CHECK(add_node(write_class, class_attrs))
  glob->class_attrs = class_attrs;
  CHECK(start_block())
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
  CHECK(write_exp(st_assign->value))
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
  CHECK(new_copy(name, &mpath->name))
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
    CHECK(end_block())
  }
  CHECK(string_equal(key_word, &(String){1, 0, ""}, &glob->flag)) if (glob->flag) {
    CHECK(add_node(write_empty, NULL))
    return OK;
  }
  if (end == '(') {
    Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
    CHECK(new_copy(key_word, &mpath->name))
    mpath->next = NULL;
    CHECK(parse_call(mpath))
  }
  else if (end == '.') {
    CHECK(parse_member_path(key_word))
  }
  else {
    Bool parsed = false;
    if (end != '[') {
      Func parser;
      CHECK(fm_find(glob->key_word_map, key_word, &parser, &parsed)) if (parsed) {
        CHECK(parser())
      }
    }
    if (not parsed) {
      Member_path* mpath = malloc(sizeof(Member_path)); if (mpath == NULL) RAISE
      CHECK(new_copy(key_word, &mpath->name))
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
Returncode create_key_word_map() {
  Array* key_word_map = new_array(18, sizeof(Func_map)); if (key_word_map == NULL) RAISE
  CHECK(fm_add(key_word_map, 0, &(String){2, 1, "#"}, parse_comment))
  CHECK(fm_add(key_word_map, 1, &(String){5, 4, "func"}, parse_func))
  CHECK(fm_add(key_word_map, 2, &(String){7, 6, "native"}, parse_native))
  CHECK(fm_add(key_word_map, 3, &(String){5, 4, "main"}, parse_main))
  CHECK(fm_add(key_word_map, 4, &(String){4, 3, "var"}, parse_var))
  CHECK(fm_add(key_word_map, 5, &(String){6, 5, "owner"}, parse_ref))
  CHECK(fm_add(key_word_map, 6, &(String){5, 4, "user"}, parse_ref))
  CHECK(fm_add(key_word_map, 7, &(String){4, 3, "new"}, parse_new))
  CHECK(fm_add(key_word_map, 8, &(String){7, 6, "delete"}, parse_delete))
  CHECK(fm_add(key_word_map, 9, &(String){3, 2, "if"}, parse_if))
  CHECK(fm_add(key_word_map, 10, &(String){5, 4, "else"}, parse_else))
  CHECK(fm_add(key_word_map, 11, &(String){8, 7, "else-if"}, parse_else_if))
  CHECK(fm_add(key_word_map, 12, &(String){3, 2, "do"}, parse_do))
  CHECK(fm_add(key_word_map, 13, &(String){6, 5, "while"}, parse_while))
  CHECK(fm_add(key_word_map, 14, &(String){4, 3, "for"}, parse_for))
  CHECK(fm_add(key_word_map, 15, &(String){7, 6, "return"}, parse_return))
  CHECK(fm_add(key_word_map, 16, &(String){6, 5, "raise"}, parse_raise))
  CHECK(fm_add(key_word_map, 17, &(String){6, 5, "class"}, parse_class))
  glob->key_word_map = key_word_map;
  return OK;
}
Returncode create_name_maps() {
  glob->type_map = NULL;
  glob->var_map = NULL;
  /* Func */
  CHECK(add_type(&(String){5, 4, "Func"}, NULL))
  Type_attrs* func_type = glob->type_map->value;
  /* Int */
  Name_map* int_members = NULL;
  CHECK(add_member(&(String){4, 3, "str"}, func_type, NULL, &int_members))
  CHECK(add_type(&(String){4, 3, "Int"}, int_members))
  Type_attrs* int_type = glob->type_map->value;
  /* Char */
  CHECK(add_type(&(String){5, 4, "Char"}, NULL))
  /* Bool */
  CHECK(add_type(&(String){5, 4, "Bool"}, NULL))
  /* String */
  Name_map* string_members = NULL;
  CHECK(add_member(&(String){7, 6, "length"}, int_type, NULL, &string_members))
  CHECK(add_member(&(String){11, 10, "max-length"}, int_type, NULL, &string_members))
  CHECK(add_member(&(String){6, 5, "clear"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){6, 5, "equal"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){4, 3, "get"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){7, 6, "append"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){5, 4, "copy"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){7, 6, "concat"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){5, 4, "find"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){8, 7, "replace"}, func_type, NULL, &string_members))
  CHECK(add_member(&(String){4, 3, "has"}, func_type, NULL, &string_members))
  CHECK(add_type(&(String){7, 6, "String"}, string_members))
  /* Array */
  Name_map* array_members = NULL;
  CHECK(add_member(&(String){7, 6, "length"}, int_type, NULL, &array_members))
  CHECK(add_type(&(String){6, 5, "Array"}, array_members))
  /* File */
  Name_map* file_members = NULL;
  CHECK(add_member(&(String){6, 5, "close"}, func_type, NULL, &file_members))
  CHECK(add_member(&(String){5, 4, "getc"}, func_type, NULL, &file_members))
  CHECK(add_member(&(String){5, 4, "putc"}, func_type, NULL, &file_members))
  CHECK(add_member(&(String){6, 5, "write"}, func_type, NULL, &file_members))
  CHECK(add_type(&(String){5, 4, "File"}, file_members))
  /* Sys */
  Name_map* sys_members = NULL;
  CHECK(add_member(&(String){6, 5, "print"}, func_type, NULL, &sys_members))
  CHECK(add_member(&(String){5, 4, "exit"}, func_type, NULL, &sys_members))
  CHECK(add_member(&(String){7, 6, "system"}, func_type, NULL, &sys_members))
  CHECK(add_member(&(String){7, 6, "getenv"}, func_type, NULL, &sys_members))
  CHECK(add_type(&(String){4, 3, "Sys"}, sys_members))
  return OK;
}
Returncode init_glob_state(St* root) {
  glob->curr = root;
  glob->spaces = 0;
  glob->class_attrs = NULL;
  return OK;
}
/* main */
Returncode func(Array* argv) {
  CHECK(print(&(String){18, 17, "MR compiler start"}))
  
  if (argv->length != 3) {
    CHECK(print(&(String){52, 51, "usage: mr2-compiler [input MR file] [output C file]"}))
    return OK;
  }
  /* open files */
  String* infile_name;
  if (1 < 0 || 1 >= argv->length) RAISE infile_name = ((String*)(argv->values)) + 1;
  String* outfile_name;
  if (2 < 0 || 2 >= argv->length) RAISE outfile_name = ((String*)(argv->values)) + 2;
  
  /* init global data */
  St* root;
  CHECK(st_new(write_sons, NULL, NULL, false, &root))
  CHECK(create_key_word_map())
  CHECK(create_name_maps())
  
  /* parse */
  CHECK(file_open_read(infile_name, &glob->infile))
  glob->file_name = infile_name;
  glob->func_name = NULL;
  glob->line_num = 0;
  CHECK(print(&(String){11, 10, "parsing..."}))
  CHECK(init_glob_state(root))
  CHECK(parse_lines())
  CHECK(file_close(glob->infile))
  
  /* write */
  CHECK(file_open_write(outfile_name, &glob->outfile))
  CHECK(print(&(String){11, 10, "writing..."}))
  CHECK(init_glob_state(root))
  CHECK(write(&(String){20, 19, "#include \"mr.2.h\"\n\n"}))
  CHECK(root->writer())
  CHECK(file_close(glob->outfile))
  
  CHECK(print(&(String){16, 15, "MR compiler end"}))
  return OK;
}

MAIN_FUNC
