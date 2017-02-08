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

/* Function Map */
typedef struct Key_value Key_value; struct Key_value {
  String* key;
  Func value;
};
Returncode kv_add(Array* map, Int index, String* key, Func value) {
  Key_value* kv = &(Key_value){0};
  if (index < 0 || index >= map->length) RAISE kv = ((Key_value*)(map->values)) + index;
  Int length = 0;
  CHECK(string_length(key, &length))
  String* new_key = new_string(length); if (new_key == NULL) RAISE
  CHECK(string_copy(new_key, key))
  kv->key = new_key;
  kv->value = value;
  return OK;
}
Returncode kv_find(Array* map, String* key, Func* value, Bool* found) {
  Int length;
  CHECK(array_length(map, &length))
  Int n; for (n = 0; n < length; ++n) {
    Key_value* kv = &(Key_value){0};
    if (n < 0 || n >= map->length) RAISE kv = ((Key_value*)(map->values)) + n;
    Bool flag;
    CHECK(string_equal(key, kv->key, &flag)) if (flag) {
      *found = true;
      *value = kv->value;
      return OK;
    }
  }
  *found = false;
  return OK;
}
/* Syntax Tree */
typedef struct St St; struct St {
  St* next_brother;
  St* firSt_son;
  St* laSt_son;
  St* father;
  Func writer;
  Generic* value;
};
Returncode St_new(Func writer, Generic* value, St* father, St** res) {
  St* self = malloc(sizeof(St)); if (self == NULL) RAISE
  self->next_brother = NULL;
  self->firSt_son = NULL;
  self->laSt_son = NULL;
  self->father = father;
  self->writer = writer;
  self->value = value;
  *res = self;
  if (father != NULL) {
    if (father->firSt_son == NULL) {
      father->firSt_son = self;
    }
    else {
      father->laSt_son->next_brother = self;
    }
    father->laSt_son = self;
  }
  return OK;
}
Returncode St_del(St* self) {
  if (self == NULL) {
    return OK;
  }
  CHECK(St_del(self->firSt_son))
  CHECK(St_del(self->next_brother))
  free(self);
  return OK;
}
/* Global data */
typedef struct Global_data Global_data; struct Global_data {
  /* data */
  File* infile;
  File* outfile;
  Array* key_word_map;
  /* state */
  St* curr;
  Int spaces;
  /* vars */
  Int length;
  Bool flag;
  Char end;
};
Global_data* glob = &(Global_data){0};

/* read helpers */
Returncode readc(Char* ch) {
  CHECK(file_getc(glob->infile, ch))
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
Returncode new_copy(String* text, String** out_text) {
  CHECK(string_length(text, &glob->length))
  String* new_text = new_string(glob->length + 1); if (new_text == NULL) RAISE
  CHECK(string_copy(new_text, text))
  *out_text = new_text;
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
  Char prev = ' ';
  CHECK(string_length(text, &glob->length))
  Int index; for (index = 0; index < glob->length; ++index) {
    Char ch;
    CHECK(string_get(text, index, &ch))
    CHECK(write_csyle_char(ch, prev))
    prev = ch;
  }
  return OK;
}
/* other helpers */
Returncode add_node(Func writer, Generic* value) {
  St* node;
  CHECK(St_new(writer, value, glob->curr, &node))
  return OK;
}
Returncode string_split(String* text, Char sep, Int* index, Int* length) {
  CHECK(string_length(text, &glob->length))
  CHECK(string_has(text, sep, &glob->flag)) if (glob->flag) {
    String* sep_str = &(String){2, 0, (char[2]){0}};
    CHECK(string_append(sep_str, sep))
    Int sep_index;
    CHECK(string_find(text, sep_str, &sep_index))
    *index = sep_index;
    *length = glob->length - sep_index - 1;
  }
  else {
    *index = glob->length;
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
Returncode write_sons() {
  St* son = glob->curr->firSt_son;
  while (true) {
    if (not(son != NULL)) break;
    glob->curr = son;
    CHECK(write_spaces())
    CHECK(son->writer(son->value))
    son = son->next_brother;
  }
  return OK;
}
Returncode start_block() {
  glob->spaces = glob->spaces + 2;
  glob->curr = glob->curr->laSt_son;
  return OK;
}
Returncode end_block() {
  glob->curr = glob->curr->father;
  glob->spaces = glob->spaces - 2;
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
/* title */
Returncode write_title(String* title) {
  CHECK(write(&(String){12, 11, "/* #title <"}))
  CHECK(write(title))
  CHECK(write(&(String){6, 5, "> */\n"}))
  glob->spaces = glob->spaces + 2;
  CHECK(write_sons())
  glob->spaces = glob->spaces - 2;
  return OK;
}

Returncode add_title(String* text) {
  CHECK(string_length(text, &glob->length))
  String* title = new_string(glob->length + 1); if (title == NULL) RAISE
  CHECK(string_copy(title, text))
  CHECK(add_node(write_title, title))
  /* read rest of line */
  String* ignore_line = &(String){256, 0, (char[256]){0}};
  CHECK(read(&(String){1, 0, ""}, ignore_line, &glob->end))
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
/* function helpers */
typedef struct St_arg St_arg; struct St_arg {
  St_arg* next;
  String* name;
  String* typename;
  String* type_param;
  String* access;
};
typedef struct St_func St_func; struct St_func {
  String* name;
  St_arg* params;
  St_arg* outputs;
};
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
    CHECK(write_cstyle(arg->name))
    arg = arg->next;
    if (arg != NULL or next != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  return OK;
}
Returncode write_func_header(St_func* st_func) {
  CHECK(write(&(String){12, 11, "Returncode "}))
  CHECK(write_cstyle(st_func->name))
  CHECK(write(&(String){2, 1, "("}))
  CHECK(write_args(st_func->params, false, st_func->outputs))
  CHECK(write_args(st_func->outputs, true, NULL))
  CHECK(write(&(String){2, 1, ")"}))
  return OK;
}
Returncode parse_func_header(String* name, St_func** st_func, Char* end) {
  St_func* new_func = malloc(sizeof(St_func)); if (new_func == NULL) RAISE
  if (name == NULL) {
    CHECK(read_new(&(String){2, 1, "("}, &new_func->name, &glob->end))
  }
  else {
    CHECK(new_copy(name, &new_func->name))
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
    if (name == NULL) {
      CHECK(read_new(&(String){3, 2, " {"}, &param->typename, &glob->end)) if (glob->end == '{') {
        CHECK(read_new(&(String){2, 1, "}"}, &param->type_param, &glob->end))
        CHECK(readc(&glob->end))
      }
    }
    CHECK(read_new(&(String){3, 2, ",)"}, &param->name, &glob->end))
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
    if (name == NULL) {
      CHECK(read_new(&(String){2, 1, " "}, &param->typename, &glob->end))
    }
    else {
      param->typename = NULL;
    }
    CHECK(read_new(&(String){3, 2, ", "}, &param->name, &glob->end))
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
Returncode parse_func() {
  St_func* st_func;
  CHECK(parse_func_header(NULL, &st_func, &glob->end))
  CHECK(add_node(write_func, st_func))
  CHECK(start_block())
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
  St_func* st_func;
  CHECK(parse_func_header(NULL, &st_func, &glob->end))
  CHECK(add_node(write_main, st_func))
  CHECK(start_block())
  return OK;
}
/* declerations */
typedef struct St_dec St_dec; struct St_dec {
  String* name;
  String* typename;
  String* array_length;
  String* string_length;
  String* init;
  String* slice_start;
  String* slice_length;
};
Returncode parse_dec(St_dec** new_st_dec) {
  St_dec* st_dec = malloc(sizeof(St_dec)); if (st_dec == NULL) RAISE
  st_dec->array_length = NULL;
  st_dec->string_length = NULL;
  st_dec->init = NULL;
  st_dec->slice_start = NULL;
  st_dec->slice_length = NULL;
  
  CHECK(read_new(&(String){3, 2, " {"}, &st_dec->typename, &glob->end))
  if (glob->end == '{') {
    Bool is_array;
    CHECK(string_equal(st_dec->typename, &(String){6, 5, "Array"}, &is_array)) if (is_array) {
      CHECK(read_new(&(String){3, 2, "}:"}, &st_dec->array_length, &glob->end)) if (glob->end == ':') {
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
    CHECK(read_new(&(String){3, 2, ")["}, &st_dec->init, &glob->end)) if (glob->end == '[') {
      CHECK(read_new(&(String){2, 1, ":"}, &st_dec->slice_start, &glob->end))
      CHECK(read_new(&(String){2, 1, "]"}, &st_dec->slice_length, &glob->end))
      CHECK(readc(&glob->end))
    }
    CHECK(readc(&glob->end))
  }
  *new_st_dec = st_dec;
  return OK;
}
/* var */
Returncode write_var_primitive(St_dec* st_dec) {
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){2, 1, " "}))
  CHECK(write_cstyle(st_dec->name))
  if (st_dec->init != NULL) {
    CHECK(write(&(String){4, 3, " = "}))
    CHECK(write_cstyle(st_dec->init))
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
  CHECK(write_ref_prefix(st_dec->typename, st_dec->name))
  CHECK(write(&(String){5, 4, "0};\n"}))
  return OK;
}
Returncode write_var_string(St_dec* st_dec) {
  CHECK(write_ref_prefix(&(String){7, 6, "String"}, st_dec->name))
  CHECK(write(st_dec->string_length))
  CHECK(write(&(String){12, 11, ", 0, (char["}))
  CHECK(write(st_dec->string_length))
  CHECK(write(&(String){9, 8, "]){0}};\n"}))
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
    CHECK(write(&(String){8, 7, " char _"}))
    CHECK(write_cstyle(st_dec->name))
    CHECK(write(&(String){8, 7, "_chars["}))
    CHECK(write(st_dec->string_length))
    CHECK(write(&(String){3, 2, "]["}))
    CHECK(write(st_dec->array_length))
    CHECK(write(&(String){23, 22, "]; {int n; for(n=0; n<"}))
    CHECK(write(st_dec->array_length))
    CHECK(write(&(String){19, 18, "; ++n) ((String*)("}))
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
Returncode parse_var() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  
  if (st_dec->array_length != NULL) {
    CHECK(add_node(write_var_array, st_dec))
    return OK;
  }
  if (st_dec->string_length != NULL) {
    CHECK(add_node(write_var_string, st_dec))
    return OK;
  }
  CHECK(is_primitive(st_dec->typename, &glob->flag)) if (glob->flag) {
    CHECK(add_node(write_var_primitive, st_dec))
    return OK;
  }
  CHECK(add_node(write_var_class, st_dec))
  return OK;
}
/* ref */
Returncode write_ref(St_dec* st_dec) {
  if (st_dec->slice_start != NULL) {
    CHECK(write(&(String){6, 5, "if (("}))
    CHECK(write_cstyle(st_dec->slice_start))
    CHECK(write(&(String){6, 5, ") + ("}))
    CHECK(write_cstyle(st_dec->slice_length))
    CHECK(write(&(String){5, 4, ") > "}))
    CHECK(write_cstyle(st_dec->init))
    CHECK(write(&(String){3, 2, "->"}))
    if (st_dec->array_length == NULL) {
      CHECK(write(&(String){8, 7, "actual_"}))
    }
    CHECK(write(&(String){15, 14, "length) RAISE "}))
  }
  CHECK(write_cstyle(st_dec->typename))
  CHECK(write(&(String){3, 2, "* "}))
  CHECK(write_cstyle(st_dec->name))
  
  if (st_dec->init != NULL) {
    CHECK(write(&(String){4, 3, " = "}))
    if (st_dec->slice_start == NULL) {
      CHECK(write_cstyle(st_dec->init))
    }
    else if (st_dec->array_length != NULL) {
      CHECK(write(&(String){10, 9, "&(Array){"}))
      CHECK(write_cstyle(st_dec->slice_length))
      CHECK(write(&(String){11, 10, ", (Byte*)("}))
      CHECK(write_cstyle(st_dec->init))
      CHECK(write(&(String){14, 13, "->values) + ("}))
      CHECK(write_cstyle(st_dec->slice_start))
      CHECK(write(&(String){12, 11, ") * sizeof("}))
      CHECK(write_cstyle(st_dec->array_length))
      CHECK(write(&(String){3, 2, ")}"}))
    }
    else {
      CHECK(write(&(String){11, 10, "&(String){"}))
      CHECK(write_cstyle(st_dec->slice_length))
      CHECK(write(&(String){3, 2, ", "}))
      CHECK(write_cstyle(st_dec->slice_length))
      CHECK(write(&(String){3, 2, ", "}))
      CHECK(write_cstyle(st_dec->init))
      CHECK(write(&(String){11, 10, "->chars + "}))
      CHECK(write_cstyle(st_dec->slice_start))
      CHECK(write(&(String){2, 1, "}"}))
    }
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_ref() {
  St_dec* st_dec;
  CHECK(parse_dec(&st_dec))
  CHECK(add_node(write_ref, st_dec))
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
  CHECK(write(&(String){8, 7, "); if ("}))
  CHECK(write_cstyle(st_dec->name))
  CHECK(write(&(String){16, 15, " == NULL) RAISE"}))
  
  if (st_dec->array_length != NULL and st_dec->string_length != NULL) {
    CHECK(write(&(String){22, 21, " {int n; for(n=0; n<("}))
    CHECK(write_cstyle(st_dec->array_length))
    CHECK(write(&(String){20, 19, "); ++n) ((String*)("}))
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
/* expression */
typedef struct St_exp St_exp; struct St_exp {
  String* prefix;
  St_func* call;
  String* suffix;
};
Returncode real_string_length(String* text, Int* length) {
  Int index = 1;
  Int real_length = 1;
  Int text_length;
  CHECK(string_length(text, &text_length))
  text_length = text_length - 1;
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
Returncode write_func_call(St_func* st_func) {
  CHECK(write(&(String){7, 6, "CHECK("}))
  CHECK(write_cstyle(st_func->name))
  CHECK(write(&(String){2, 1, "("}))
  St_arg* arg = st_func->params;
  while (true) {
    if (not(arg != NULL)) break;
    CHECK(string_get(arg->name, 0, &glob->end)) if (glob->end == '"') {
      CHECK(real_string_length(arg->name, &glob->length))
      String* length_str = &(String){80, 0, (char[80]){0}};
      CHECK(write(&(String){11, 10, "&(String){"}))
      CHECK(int_to_string(glob->length, length_str))
      CHECK(write(length_str))
      CHECK(write(&(String){3, 2, ", "}))
      glob->length = glob->length - 1;
      CHECK(int_to_string(glob->length, length_str))
      CHECK(write(length_str))
      CHECK(write(&(String){3, 2, ", "}))
      CHECK(write(arg->name))
      CHECK(write(&(String){2, 1, "}"}))
    }
    else {
      CHECK(write_cstyle(arg->name))
    }
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
    CHECK(write_cstyle(arg->name))
    arg = arg->next;
    if (arg != NULL) {
      CHECK(write(&(String){3, 2, ", "}))
    }
  }
  CHECK(write(&(String){3, 2, "))"}))
  return OK;
}
Returncode write_exp_call(St_exp* st_exp) {
  if (st_exp->call != NULL) {
    CHECK(write_func_call(st_exp->call))
    CHECK(write(&(String){2, 1, " "}))
  }
  return OK;
}
Returncode write_exp(St_exp* st_exp) {
  if (st_exp->call != NULL) {
    St_arg* last = st_exp->call->outputs;
    if (last == NULL) {
      RAISE
    }
    while (true) {
      if (not(last->next != NULL)) break;
      last = last->next;
    }
    CHECK(write_cstyle(last->name))
    
  }
  else {
    CHECK(write_cstyle(st_exp->prefix))
  }
  if (st_exp->suffix != NULL) {
    CHECK(write(&(String){2, 1, " "}))
    CHECK(write_cstyle(st_exp->suffix))
  }
  return OK;
}
Returncode parse_exp(St_exp** new_st_exp) {
  St_exp* st_exp = malloc(sizeof(St_exp)); if (st_exp == NULL) RAISE
  st_exp->call = NULL;
  st_exp->suffix = NULL;
  Char end;
  CHECK(read_new(&(String){3, 2, " ("}, &st_exp->prefix, &end)) if (end == '(') {
    CHECK(parse_func_header(st_exp->prefix, &st_exp->call, &end))
  }
  if (end == ' ') {
    CHECK(read_new(&(String){1, 0, ""}, &st_exp->suffix, &end))
  }
  *new_st_exp = st_exp;
  return OK;
}
/* if */
Returncode write_if(St_exp* st_exp) {
  CHECK(write_exp_call(st_exp))
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){2, 1, ")"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_if() {
  St_exp* st_exp;
  CHECK(parse_exp(&st_exp))
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
  CHECK(write_exp_call(st_exp))
  CHECK(write(&(String){10, 9, "else if ("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){2, 1, ")"}))
  CHECK(write_block())
  return OK;
}
Returncode parse_else_if() {
  St_exp* st_exp;
  CHECK(parse_exp(&st_exp))
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
  CHECK(write_exp_call(st_exp))
  CHECK(write(&(String){9, 8, "if (not("}))
  CHECK(write_exp(st_exp))
  CHECK(write(&(String){11, 10, ")) break;\n"}))
  return OK;
}
Returncode parse_while() {
  St_exp* st_exp;
  CHECK(parse_exp(&st_exp))
  CHECK(add_node(write_while, st_exp))
  return OK;
}
/* for */
typedef struct St_for St_for; struct St_for {
  String* counter;
  St_exp* limit;
};
Returncode write_for(St_for* st_for) {
  CHECK(write_exp_call(st_for->limit))
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
  CHECK(parse_exp(&st_for->limit))
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
  CHECK(write(&(String){7, 6, "RAISE\n"}))
  return OK;
}
Returncode parse_raise() {
  CHECK(add_node(write_raise, NULL))
  return OK;
}
/* class */
Returncode write_class(String* name) {
  CHECK(write(&(String){16, 15, "typedef struct "}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){2, 1, " "}))
  CHECK(write_cstyle(name))
  CHECK(write(&(String){10, 9, "; struct "}))
  CHECK(write_cstyle(name))
  CHECK(write_block_suffix(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_class() {
  String* name;
  CHECK(read_new(&(String){1, 0, ""}, &name, &glob->end))
  CHECK(add_node(write_class, name))
  CHECK(start_block())
  return OK;
}
/* ... array */
typedef struct St_array St_array; struct St_array {
  String* typename;
  String* array;
  String* variable;
  String* index;
  Bool is_set;
};
Returncode write_array(St_array* st_array) {
  CHECK(write(&(String){5, 4, "if ("}))
  CHECK(write_cstyle(st_array->index))
  CHECK(write(&(String){9, 8, " < 0 || "}))
  CHECK(write_cstyle(st_array->index))
  CHECK(write(&(String){5, 4, " >= "}))
  CHECK(write_cstyle(st_array->array))
  CHECK(write(&(String){17, 16, "->length) RAISE "}))
  if (not st_array->is_set) {
    CHECK(write_cstyle(st_array->variable))
    CHECK(write(&(String){4, 3, " = "}))
  }
  CHECK(write(&(String){3, 2, "(("}))
  CHECK(write_cstyle(st_array->typename))
  CHECK(write(&(String){4, 3, "*)("}))
  CHECK(write_cstyle(st_array->array))
  CHECK(write(&(String){11, 10, "->values))"}))
  CHECK(is_primitive(st_array->typename, &glob->flag)) if (glob->flag or st_array->is_set) {
    CHECK(write(&(String){2, 1, "["}))
    CHECK(write_cstyle(st_array->index))
    CHECK(write(&(String){2, 1, "]"}))
  }
  else {
    CHECK(write(&(String){4, 3, " + "}))
    CHECK(write_cstyle(st_array->index))
  }
  if (st_array->is_set) {
    CHECK(write(&(String){4, 3, " = "}))
    CHECK(write_cstyle(st_array->variable))
  }
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_array() {
  St_array* st_array = malloc(sizeof(St_array)); if (st_array == NULL) RAISE
  CHECK(read_new(&(String){2, 1, " "}, &st_array->typename, &glob->end))
  String* target;
  CHECK(read_new(&(String){3, 2, " ["}, &target, &glob->end)) st_array->is_set = glob->end == '[';
  if (st_array->is_set) {
    st_array->array = target;
    CHECK(read_new(&(String){2, 1, "]"}, &st_array->index, &glob->end))
    /* ignore ":= " */
    CHECK(read_ignore(3))
    CHECK(read_new(&(String){1, 0, ""}, &st_array->variable, &glob->end))
  }
  else {
    st_array->variable = target;
    /* ignore ":= " */
    CHECK(read_ignore(3))
    CHECK(read_new(&(String){2, 1, "["}, &st_array->array, &glob->end))
    CHECK(read_new(&(String){2, 1, "]"}, &st_array->index, &glob->end))
    CHECK(readc(&glob->end))
  }
  CHECK(add_node(write_array, st_array))
  return OK;
}
/* call */
Returncode write_call(St_func* st_func) {
  CHECK(write_func_call(st_func))
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_call(String* name) {
  St_func* st_func;
  CHECK(parse_func_header(name, &st_func, &glob->end))
  CHECK(add_node(write_call, st_func))
  return OK;
}
/* assign */
typedef struct St_assign St_assign; struct St_assign {
  String* name;
  St_exp* value;
};
Returncode write_assign(St_assign* st_assign) {
  CHECK(write_exp_call(st_assign->value))
  CHECK(write_cstyle(st_assign->name))
  CHECK(write(&(String){4, 3, " = "}))
  CHECK(write_exp(st_assign->value))
  CHECK(write(&(String){3, 2, ";\n"}))
  return OK;
}
Returncode parse_assign_exp(String* name, Func writer) {
  St_assign* st_assign = malloc(sizeof(St_assign)); if (st_assign == NULL) RAISE
  st_assign->name = name;
  /* ignore ":= " */
  CHECK(read_ignore(3))
  CHECK(parse_exp(&st_assign->value))
  CHECK(add_node(writer, st_assign))
  CHECK(start_block())
  return OK;
}
Returncode parse_assign(String* name) {
  String* new_name;
  CHECK(new_copy(name, &new_name))
  CHECK(parse_assign_exp(new_name, write_assign))
  return OK;
}

/* out */
Returncode write_out(St_assign* st_assign) {
  CHECK(write(&(String){2, 1, "*"}))
  CHECK(write_assign(st_assign))
  return OK;
}
Returncode parse_out() {
  String* name;
  CHECK(read_new(&(String){2, 1, " "}, &name, &glob->end))
  CHECK(parse_assign_exp(name, write_out))
  return OK;
}
/* lines */
Returncode parse_line(Bool* more_lines) {
  String* key_word = &(String){80, 0, (char[80]){0}};
  Int spaces;
  CHECK(read_indent(&(String){3, 2, " ("}, true, key_word, &glob->end, &spaces))
  if (glob->end == EOF) {
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
  Func parser;
  CHECK(kv_find(glob->key_word_map, key_word, &parser, &glob->flag)) if (glob->flag) {
    CHECK(parser())
  }
  else if (glob->end == '(') {
    CHECK(parse_call(key_word))
  }
  else {
    CHECK(parse_assign(key_word))
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
  Array* key_word_map = new_array(20, sizeof(Key_value)); if (key_word_map == NULL) RAISE
  CHECK(kv_add(key_word_map, 0, &(String){2, 1, "#"}, parse_comment))
  CHECK(kv_add(key_word_map, 1, &(String){5, 4, "func"}, parse_func))
  CHECK(kv_add(key_word_map, 2, &(String){7, 6, "native"}, parse_native))
  CHECK(kv_add(key_word_map, 3, &(String){5, 4, "main"}, parse_main))
  CHECK(kv_add(key_word_map, 4, &(String){4, 3, "var"}, parse_var))
  CHECK(kv_add(key_word_map, 5, &(String){6, 5, "owner"}, parse_ref))
  CHECK(kv_add(key_word_map, 6, &(String){5, 4, "user"}, parse_ref))
  CHECK(kv_add(key_word_map, 7, &(String){4, 3, "new"}, parse_new))
  CHECK(kv_add(key_word_map, 8, &(String){7, 6, "delete"}, parse_delete))
  CHECK(kv_add(key_word_map, 9, &(String){3, 2, "if"}, parse_if))
  CHECK(kv_add(key_word_map, 10, &(String){5, 4, "else"}, parse_else))
  CHECK(kv_add(key_word_map, 11, &(String){8, 7, "else-if"}, parse_else_if))
  CHECK(kv_add(key_word_map, 12, &(String){3, 2, "do"}, parse_do))
  CHECK(kv_add(key_word_map, 13, &(String){6, 5, "while"}, parse_while))
  CHECK(kv_add(key_word_map, 14, &(String){4, 3, "for"}, parse_for))
  CHECK(kv_add(key_word_map, 15, &(String){7, 6, "return"}, parse_return))
  CHECK(kv_add(key_word_map, 16, &(String){6, 5, "raise"}, parse_raise))
  CHECK(kv_add(key_word_map, 17, &(String){4, 3, "out"}, parse_out))
  CHECK(kv_add(key_word_map, 18, &(String){6, 5, "class"}, parse_class))
  CHECK(kv_add(key_word_map, 19, &(String){3, 2, "[]"}, parse_array))
  glob->key_word_map = key_word_map;
  return OK;
}

Returncode init_glob_state(St* root) {
  glob->curr = root;
  glob->spaces = 0;
  return OK;
}
/* main */
Returncode func(Array* argv) {
  CHECK(print(&(String){18, 17, "MR compiler start"}))
  
  CHECK(array_length(argv, &glob->length))
  if (glob->length != 3) {
    CHECK(print(&(String){52, 51, "usage: mr2-compiler [input MR file] [output C file]"}))
    return OK;
  }
  /* open files */
  String* infile_name;
  if (1 < 0 || 1 >= argv->length) RAISE infile_name = ((String*)(argv->values)) + 1;
  String* outfile_name;
  if (2 < 0 || 2 >= argv->length) RAISE outfile_name = ((String*)(argv->values)) + 2;
  CHECK(file_open_read(infile_name, &glob->infile))
  CHECK(file_open_write(outfile_name, &glob->outfile))
  
  /* init global data */
  St* root;
  CHECK(St_new(write_sons, NULL, NULL, &root))
  CHECK(create_key_word_map())
  
  /* parse */
  CHECK(print(&(String){11, 10, "parsing..."}))
  CHECK(init_glob_state(root))
  CHECK(parse_lines())
  
  /* write */
  CHECK(print(&(String){11, 10, "writing..."}))
  CHECK(init_glob_state(root))
  CHECK(write(&(String){20, 19, "#include \"mr.1.h\"\n\n"}))
  CHECK(root->writer())
  
  /* close files */
  CHECK(file_close(glob->infile))
  CHECK(file_close(glob->outfile))
  
  CHECK(print(&(String){16, 15, "MR compiler end"}))
  return OK;
}

MAIN_FUNC
