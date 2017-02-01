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
  St* first_son;
  St* last_son;
  St* father;
  Func writer;
  Generic* value;
};
Returncode st_new(Func writer, Generic* value, St* father, St** res) {
  St* self = malloc(sizeof(St)); if (self == NULL) RAISE
  self->next_brother = NULL;
  self->first_son = NULL;
  self->last_son = NULL;
  self->father = father;
  self->writer = writer;
  self->value = value;
  *res = self;
  if (father != NULL) {
    if (father->first_son == NULL) {
      father->first_son = self;
    }
    else {
      father->last_son->next_brother = self;
    }
    father->last_son = self;
  }
  return OK;
}
Returncode st_del(St* self) {
  if (self == NULL) {
    return OK;
  }
  CHECK(st_del(self->first_son))
  CHECK(st_del(self->next_brother))
  free(self);
  return OK;
}

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


Returncode read(String* ends, String* name, Char* end) {
  CHECK(string_clear(name))
  Char ch = EOF;
  Char q = '\0';
  Bool indent = true;
  while (true) {
    /* ignore indent */
    CHECK(file_getc(glob->infile, &ch))
    if (indent) {
      while (true) {
        if (not(ch == ' ')) break;
        CHECK(file_getc(glob->infile, &ch))
      }
      indent = false;
    }
    if (not(ch != EOF)) break;
    if (q != '\0') {
      if (ch == '\\') {
        CHECK(string_append(name, ch))
        CHECK(file_getc(glob->infile, &ch))
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
    CHECK(string_append(name, ch))
  }
  *end = ch;
  return OK;
}

Returncode write(String* text) {
  CHECK(file_write(glob->outfile, text))
  return OK;
}

Returncode write_sons() {
  St* son = glob->curr->first_son;
  while (true) {
    if (not(son != NULL)) break;
    glob->curr = son;
    CHECK(son->writer(son->value))
    son = son->next_brother;
  }
  return OK;
}

Returncode write_comment(String* text) {
  CHECK(write(&(String){4, 3, "/* "}))
  CHECK(write(text))
  CHECK(write(&(String){5, 4, " */\n"}))
  return OK;
}
Returncode add_text(String* text) {
  CHECK(string_length(text, &glob->length))
  String* new_text = new_string(glob->length + 1); if (new_text == NULL) RAISE
  CHECK(string_copy(new_text, text))
  St* node;
  CHECK(st_new(write_comment, new_text, glob->curr, &node))
  /* read rest of line */
  String* ignore_line = &(String){256, 0, (char[256]){0}};
  CHECK(read(&(String){1, 0, ""}, ignore_line, &glob->end))
  return OK;
}
Returncode parse_comment() {
  CHECK(add_text(&(String){8, 7, "comment"}))
  return OK;
}

Returncode parse_main() {
  CHECK(add_text(&(String){5, 4, "main"}))
  return OK;
}

Returncode parse_func() {
  CHECK(add_text(&(String){5, 4, "func"}))
  return OK;
}

Returncode parse_native() {
  CHECK(add_text(&(String){7, 6, "native"}))
  return OK;
}

Returncode parse_var() {
  CHECK(add_text(&(String){4, 3, "var"}))
  return OK;
}

Returncode parse_ref() {
  CHECK(add_text(&(String){4, 3, "ref"}))
  return OK;
}

Returncode parse_new() {
  CHECK(add_text(&(String){4, 3, "new"}))
  return OK;
}

Returncode parse_delete() {
  CHECK(add_text(&(String){7, 6, "delete"}))
  return OK;
}

Returncode parse_if() {
  CHECK(add_text(&(String){3, 2, "if"}))
  return OK;
}

Returncode parse_else() {
  CHECK(add_text(&(String){5, 4, "else"}))
  return OK;
}

Returncode parse_else_if() {
  CHECK(add_text(&(String){8, 7, "else-if"}))
  return OK;
}

Returncode parse_do() {
  CHECK(add_text(&(String){3, 2, "do"}))
  return OK;
}

Returncode parse_while() {
  CHECK(add_text(&(String){6, 5, "while"}))
  return OK;
}

Returncode parse_for() {
  CHECK(add_text(&(String){4, 3, "for"}))
  return OK;
}

Returncode parse_return() {
  CHECK(add_text(&(String){7, 6, "return"}))
  return OK;
}

Returncode parse_raise() {
  CHECK(add_text(&(String){6, 5, "raise"}))
  return OK;
}

Returncode parse_out() {
  CHECK(add_text(&(String){4, 3, "out"}))
  return OK;
}

Returncode parse_class() {
  CHECK(add_text(&(String){6, 5, "class"}))
  return OK;
}

Returncode parse_array() {
  CHECK(add_text(&(String){6, 5, "array"}))
  return OK;
}

Returncode parse_call() {
  CHECK(add_text(&(String){5, 4, "call"}))
  return OK;
}

Returncode parse_assign() {
  CHECK(add_text(&(String){7, 6, "assign"}))
  return OK;
}
  
Returncode parse_line(Bool* more_lines) {
  String* key_word = &(String){80, 0, (char[80]){0}};
  CHECK(read(&(String){3, 2, " ("}, key_word, &glob->end))
  if (glob->end == EOF) {
    *more_lines = false;
    return OK;
  }
  *more_lines = true;
  CHECK(string_equal(key_word, &(String){1, 0, ""}, &glob->flag)) if (glob->flag) {
    CHECK(add_text(&(String){1, 0, ""}))
    return OK;
  }
  Func parser;
  CHECK(kv_find(glob->key_word_map, key_word, &parser, &glob->flag)) if (glob->flag) {
    CHECK(parser())
  }
  else if (glob->end == '(') {
    CHECK(parse_call())
  }
  else {
    CHECK(parse_assign())
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

Returncode create_key_word_map() {
  Array* key_word_map = new_array(20, sizeof(Key_value)); if (key_word_map == NULL) RAISE
  CHECK(kv_add(key_word_map, 0, &(String){2, 1, "#"}, parse_comment))
  CHECK(kv_add(key_word_map, 1, &(String){5, 4, "main"}, parse_main))
  CHECK(kv_add(key_word_map, 2, &(String){5, 4, "func"}, parse_func))
  CHECK(kv_add(key_word_map, 3, &(String){7, 6, "native"}, parse_native))
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
  CHECK(st_new(write_sons, NULL, NULL, &root))
  CHECK(create_key_word_map())
  
  /* parse */
  CHECK(print(&(String){11, 10, "parsing..."}))
  CHECK(init_glob_state(root))
  CHECK(parse_lines())
  
  /* write */
  CHECK(print(&(String){11, 10, "writing..."}))
  CHECK(init_glob_state(root))
  CHECK(root->writer())
  
  /* close files */
  CHECK(file_close(glob->infile))
  CHECK(file_close(glob->outfile))
  
  CHECK(print(&(String){16, 15, "MR compiler end"}))
  return OK;
}

MAIN_FUNC
