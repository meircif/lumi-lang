static char* _mr_file3_name = "global.2.mr";
#define MR_FILE_NAME _mr_file3_name
/* MR3 compiler - global data */

/* global data object */
String* global_key_word_text = &(String){80, 0, (char[80]){0}};

typedef struct Parsed_key_word Parsed_key_word; struct Parsed_key_word {
  String* text;
  Int spaces;
  Char end;
};

Parsed_key_word* global_key_word = &(Parsed_key_word){0};

typedef struct Global_data Global_data; struct Global_data {
  /* data */
  File* infile;
  File* outfile;
  Array* key_word_map;
  Op_map* op_map;
  Type_map* type_map;
  Var_map* var_map;
  /* types */
  Mtype* type_char;
  Mtype* type_bool;
  Mtype* type_int;
  Mtype* type_type;
  Mtype* type_func;
  Mtype* type_string;
  Mtype* type_array;
  Mtype* type_file;
  Mtype* type_sys;
  /* state */
  Parsed_key_word* key_word;
  String* infile_name;
  Int line_num;
  Int spaces;
  Mtype* mclass;
  St* node;
};
static char* _func_name_Global_data_init_op_map = "Global-data.init-op-map";
#define MR_FUNC_NAME _func_name_Global_data_init_op_map
Returncode Global_data_init_op_map(Global_data* self) {
  Op_map* map = malloc(sizeof(Op_map));
  if (map == NULL) RAISE(40)
  self->op_map = map;
  CHECK(42, Name_map_init(&(map->_base)));
  CHECK(43, Op_map_add(map, &(String){2, 1, "."}, &(String){3, 2, "->"}));
  CHECK(44, Op_map_add(map, &(String){3, 2, ":="}, &(String){2, 1, "="}));
  CHECK(45, Op_map_add_copy(map, &(String){2, 1, "+"}));
  CHECK(46, Op_map_add_copy(map, &(String){2, 1, "-"}));
  CHECK(47, Op_map_add_copy(map, &(String){2, 1, "*"}));
  CHECK(48, Op_map_add_copy(map, &(String){2, 1, "/"}));
  CHECK(49, Op_map_add(map, &(String){2, 1, "="}, &(String){3, 2, "=="}));
  CHECK(50, Op_map_add_copy(map, &(String){3, 2, "!="}));
  CHECK(51, Op_map_add_copy(map, &(String){2, 1, ">"}));
  CHECK(52, Op_map_add_copy(map, &(String){2, 1, "<"}));
  CHECK(53, Op_map_add_copy(map, &(String){3, 2, ">="}));
  CHECK(54, Op_map_add_copy(map, &(String){3, 2, "<="}));
  CHECK(55, Op_map_add(map, &(String){4, 3, "not"}, &(String){2, 1, "!"}));
  CHECK(56, Op_map_add(map, &(String){3, 2, "or"}, &(String){3, 2, "||"}));
  CHECK(57, Op_map_add(map, &(String){4, 3, "and"}, &(String){3, 2, "&&"}));
  CHECK(58, Op_map_add(map, &(String){2, 1, "?"}, &(String){9, 8, "NULL != "}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Global_data_init_types = "Global-data.init-types";
#define MR_FUNC_NAME _func_name_Global_data_init_types
Returncode Global_data_init_types(Global_data* self) {
  Type_map* map = malloc(sizeof(Type_map));
  if (map == NULL) RAISE(61)
  self->type_map = map;
  CHECK(63, Name_map_init(&(map->_base)));
  CHECK(64, Type_map_add(map, &(String){5, 4, "Char"}, &(self->type_char)));
  CHECK(65, Type_map_add(map, &(String){5, 4, "Bool"}, &(self->type_bool)));
  CHECK(66, Type_map_add(map, &(String){4, 3, "Int"}, &(self->type_int)));
  CHECK(67, Type_map_add(map, &(String){5, 4, "Type"}, &(self->type_type)));
  CHECK(68, Type_map_add(map, &(String){5, 4, "Func"}, &(self->type_func)));
  CHECK(69, Type_map_add(map, &(String){7, 6, "String"}, &(self->type_string)));
  CHECK(70, Type_map_add(map, &(String){6, 5, "Array"}, &(self->type_array)));
  CHECK(71, Type_map_add(map, &(String){5, 4, "File"}, &(self->type_file)));
  CHECK(72, Type_map_add(map, &(String){4, 3, "Sys"}, &(self->type_sys)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_Global_data_init = "Global-data.init";
#define MR_FUNC_NAME _func_name_Global_data_init
Returncode Global_data_init(Global_data* self) {
  self->line_num = 0;
  global_key_word->text = global_key_word_text;
  self->key_word = NULL;
  CHECK(78, Global_data_init_op_map(self));
  CHECK(79, Global_data_init_types(self));
  return OK;
}
#undef MR_FUNC_NAME

Global_data* glob = &(Global_data){0};


/* read helpers */
static char* _func_name_read_c = "read-c";
#define MR_FUNC_NAME _func_name_read_c
Returncode read_c(Char* ch) {
  CHECK(86, File_getc(glob->infile, &((*ch))));
  if ((*ch) == '\n') {
    glob->line_num = glob->line_num + 1;
  }
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_read_ignore = "read-ignore";
#define MR_FUNC_NAME _func_name_read_ignore
Returncode read_ignore(Int chars) {
  Int n; for (n = 0; n < chars; ++n) {
    Char _Char0;
    CHECK(92, read_c(&(_Char0)));
  }
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_read_indent = "read-indent";
#define MR_FUNC_NAME _func_name_read_indent
Returncode read_indent(String* ends, Bool indent, String* text, Char* end, Int* spaces) {
  CHECK(95, String_clear(text));
  Char ch = EOF;
  Char q = '\0';
  (*spaces) = 0;
  while (true) {
    /* ignore indent */
    CHECK(101, read_c(&(ch)));
    if (indent) {
      while (true) {
        if (!(ch == ' ')) break;
        (*spaces) = (*spaces) + 1;
        CHECK(106, read_c(&(ch)));
      }
      indent = false;
    }
    if (!(ch != EOF)) break;
    if (q == '\0') {
      if (!(ch != '\n')) break;
      Bool _Bool1;
      CHECK(111, String_has(ends, ch, &(_Bool1)))
      if (!(!_Bool1)) break;
      if (ch == '\'' || ch == '"') {
        q = ch;
      }
    }
    else {
      if (ch == '\\') {
        CHECK(115, String_append(text, ch));
        CHECK(116, read_c(&(ch)));
      }
      else {
        if (ch == q) {
          q = '\0';
        }
      }
    }
    CHECK(119, String_append(text, ch));
  }
  (*end) = ch;
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_read = "read";
#define MR_FUNC_NAME _func_name_read
Returncode read(String* ends, String* text, Char* end) {
  Int _Int2;
  CHECK(123, read_indent(ends, false, text, &((*end)), &(_Int2)));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_read_new = "read-new";
#define MR_FUNC_NAME _func_name_read_new
Returncode read_new(String* ends, String** out_text, Char* end) {
  String* text = &(String){256, 0, (char[256]){0}};
  CHECK(127, read(ends, text, &((*end))));
  CHECK(128, f_new_copy(text, &((*out_text))));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_read_key_word = "read-key-word";
#define MR_FUNC_NAME _func_name_read_key_word
Returncode read_key_word() {
  if (NULL != glob->key_word) {
    return OK;
  }
  glob->key_word = global_key_word;
  CHECK(134, read_indent(&(String){5, 4, " .[("}, true, glob->key_word->text, &(glob->key_word->end), &(glob->key_word->spaces)));
  return OK;
}
#undef MR_FUNC_NAME


/* write helpers */
static char* _func_name_write_c = "write-c";
#define MR_FUNC_NAME _func_name_write_c
Returncode write_c(Char ch) {
  CHECK(139, File_putc(glob->outfile, ch));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write = "write";
#define MR_FUNC_NAME _func_name_write
Returncode write(String* text) {
  CHECK(143, File_write(glob->outfile, text));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_cstyle = "write-cstyle";
#define MR_FUNC_NAME _func_name_write_cstyle
Returncode write_cstyle(String* text) {
  if (!(NULL != text)) {
    RAISE(148)
  }
  Int index; for (index = 0; index < text->length; ++index) {
    Char _Char3;
    CHECK(150, String_get(text, index, &(_Char3)))
    Char ch = _Char3;
    if (ch == '-') {
      CHECK(152, write_c('_'));
    }
    else {
      CHECK(154, write_c(ch));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_line_num = "write-line-num";
#define MR_FUNC_NAME _func_name_write_line_num
Returncode write_line_num() {
  String* line_num_str = &(String){64, 0, (char[64]){0}};
  CHECK(158, Int_str(glob->line_num, line_num_str));
  CHECK(159, write(line_num_str));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_tb_raise = "write-tb-raise";
#define MR_FUNC_NAME _func_name_write_tb_raise
Returncode write_tb_raise() {
  CHECK(162, write(&(String){7, 6, "RAISE("}));
  CHECK(163, write_line_num());
  CHECK(164, write(&(String){2, 1, ")"}));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_tb_check = "write-tb-check";
#define MR_FUNC_NAME _func_name_write_tb_check
Returncode write_tb_check() {
  CHECK(167, write(&(String){7, 6, "CHECK("}));
  CHECK(168, write_line_num());
  CHECK(169, write(&(String){3, 2, ", "}));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_write_spaces = "write-spaces";
#define MR_FUNC_NAME _func_name_write_spaces
Returncode write_spaces() {
  Int n; for (n = 0; n < glob->spaces; ++n) {
    CHECK(173, write_c(' '));
  }
  return OK;
}
#undef MR_FUNC_NAME

/* syntax error */
static char* _func_name_f_syntax_error = "f-syntax-error";
#define MR_FUNC_NAME _func_name_f_syntax_error
Returncode f_syntax_error(String* text, String* item) {
  String* msg = &(String){256, 0, (char[256]){0}};
  CHECK(178, String_copy(msg, &(String){15, 14, "Code error in "}));
  CHECK(179, String_concat(msg, glob->infile_name));
  CHECK(180, String_concat(msg, &(String){2, 1, "["}));
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(182, Int_str(glob->line_num, line_num_str));
  CHECK(183, String_concat(msg, line_num_str));
  CHECK(184, String_concat(msg, &(String){3, 2, "] "}));
  CHECK(185, String_concat(msg, text));
  CHECK(186, String_concat(msg, &(String){3, 2, " \""}));
  CHECK(187, String_concat(msg, item));
  CHECK(188, String_append(msg, '\"'));
  CHECK(189, Sys_print(sys, msg));
  RAISE(190)
}
#undef MR_FUNC_NAME

static char* _func_name_f_syntax_error2 = "f-syntax-error2";
#define MR_FUNC_NAME _func_name_f_syntax_error2
Returncode f_syntax_error2(String* text1, String* item1, String* text2, String* item2) {
  String* msg = &(String){256, 0, (char[256]){0}};
  CHECK(194, String_copy(msg, text1));
  CHECK(195, String_concat(msg, &(String){3, 2, " \""}));
  CHECK(196, String_concat(msg, item1));
  CHECK(197, String_concat(msg, &(String){3, 2, "\" "}));
  CHECK(198, String_concat(msg, text2));
  CHECK(199, f_syntax_error(msg, item2));
  return OK;
}
#undef MR_FUNC_NAME

static char* _func_name_f_syntax_error_c = "f-syntax-error-c";
#define MR_FUNC_NAME _func_name_f_syntax_error_c
Returncode f_syntax_error_c(String* text, Char ch) {
  String* char_str = &(String){2, 0, (char[2]){0}};
  CHECK(203, String_append(char_str, ch));
  CHECK(204, f_syntax_error(text, char_str));
  return OK;
}
#undef MR_FUNC_NAME

/* other helpers */
static char* _func_name_get_node_type = "get-node-type";
#define MR_FUNC_NAME _func_name_get_node_type
Returncode get_node_type(String* key, Type* node_type, Bool* found) {
  Int n; for (n = 0; n < glob->key_word_map->length; ++n) {
    if ((n) < 0 || (n) >= glob->key_word_map->length) RAISE(209)
    Node_map_item* item = ((Node_map_item*)(glob->key_word_map->values)) + n;
    Bool _Bool4;
    CHECK(210, String_equal(item->key, key, &(_Bool4)))
    if (_Bool4) {
      (*node_type) = item->node_type;
      (*found) = true;
      return OK;
    }
  }
  (*found) = false;
  return OK;
}
#undef MR_FUNC_NAME


static char* _func_name_f_find_type = "f-find-type";
#define MR_FUNC_NAME _func_name_f_find_type
Returncode f_find_type(String* typename, Mtype** mtype) {
  CHECK(218, Type_map_find(glob->type_map, typename, &((*mtype))))
  if (!(NULL != (*mtype))) {
    CHECK(219, f_syntax_error(&(String){13, 12, "unknown type"}, typename));
  }
  return OK;
}
#undef MR_FUNC_NAME


/* basic syntax tree node */

typedef struct St St; struct St {
  Func* _dtl;
  St* next_brother;
  St* first_son;
  St* last_son;
  St* father;
  Int line_num;
  Var_map* var_map;
  Var_map* sons_var_map;
  /* analyze sons */
  /* analyze sons */
  /* write sons */
};
static char* _func_name_St_init = "St.init";
#define MR_FUNC_NAME _func_name_St_init
Returncode St_init(St* self, St* father) {
  self->next_brother = NULL;
  self->first_son = NULL;
  self->last_son = NULL;
  self->father = father;
  self->line_num = glob->line_num;
  CHECK(239, f_copy_new_var_map(NULL, &(self->sons_var_map)));
  self->var_map = NULL;
  if (NULL != father) {
    if (NULL != father->last_son) {
      father->last_son->next_brother = self;
    }
    father->last_son = self;
    if (!(NULL != father->first_son)) {
      father->first_son = self;
    }
    if (NULL != father->sons_var_map) {
      CHECK(248, f_copy_new_var_map(father->sons_var_map, &(self->var_map)));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_parse = "St.parse";
#define MR_FUNC_NAME _func_name_St_parse
Returncode St_parse(St* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_analyze_first = "St.analyze-first";
#define MR_FUNC_NAME _func_name_St_analyze_first
Returncode St_analyze_first(St* self) {
  St* son = self->first_son;
  while (true) {
    if (!(NULL != son)) break;
    glob->line_num = son->line_num;
    glob->node = son;
    CHECK(260, (*((Func**)(son)))[1](son));
    son = son->next_brother;
  }
  glob->node = self;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_analyze = "St.analyze";
#define MR_FUNC_NAME _func_name_St_analyze
Returncode St_analyze(St* self) {
  St* son = self->first_son;
  while (true) {
    if (!(NULL != son)) break;
    glob->line_num = son->line_num;
    glob->node = son;
    CHECK(271, (*((Func**)(son)))[2](son));
    son = son->next_brother;
  }
  glob->node = self;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_write = "St.write";
#define MR_FUNC_NAME _func_name_St_write
Returncode St_write(St* self) {
  St* son = self->first_son;
  while (true) {
    if (!(NULL != son)) break;
    glob->line_num = son->line_num;
    CHECK(281, (*((Func**)(son)))[3](son));
    son = son->next_brother;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_add_var = "St.add-var";
#define MR_FUNC_NAME _func_name_St_add_var
Returncode St_add_var(St* self, Mvar* mvar) {
  if (NULL != glob->mclass) {
    CHECK(286, add_var(glob->mclass->members, mvar));
  }
  else {
    if (NULL != self->father && NULL != self->father->sons_var_map) {
      CHECK(288, add_var(self->father->sons_var_map, mvar));
    }
    else {
      CHECK(290, add_var(glob->var_map, mvar));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_m_find_var = "St.m-find-var";
#define MR_FUNC_NAME _func_name_St_m_find_var
Returncode St_m_find_var(St* self, String* name, Mvar** mvar) {
  if (NULL != self->var_map) {
    CHECK(294, Var_map_find(self->var_map, name, &((*mvar))));
    if (NULL != (*mvar)) {
      return OK;
    }
  }
  if (NULL != self->father) {
    CHECK(298, St_m_find_var(self->father, name, &((*mvar))));
  }
  else {
    CHECK(300, Var_map_find(glob->var_map, name, &((*mvar))));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St__dtl[] = {St_parse, St_analyze_first, St_analyze, St_write};

static char* _func_name_m_find_var = "m-find-var";
#define MR_FUNC_NAME _func_name_m_find_var
Returncode m_find_var(String* name, Mvar** mvar) {
  CHECK(303, St_m_find_var(glob->node, name, &((*mvar))));
  return OK;
}
#undef MR_FUNC_NAME

#undef MR_FILE_NAME
