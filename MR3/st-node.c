static char* _mr_file5_name = "st-node.2.mr";
#define MR_FILE_NAME _mr_file5_name
/* MR3 compiler - complex nodes */

typedef struct St_empty St_empty; struct St_empty {
  St _base;
};
static char* _func_name_St_empty_parse = "St-empty.parse";
#define MR_FUNC_NAME _func_name_St_empty_parse
Returncode St_empty_parse(St_empty* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_empty_analyze_first = "St-empty.analyze-first";
#define MR_FUNC_NAME _func_name_St_empty_analyze_first
Returncode St_empty_analyze_first(St_empty* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_empty_analyze = "St-empty.analyze";
#define MR_FUNC_NAME _func_name_St_empty_analyze
Returncode St_empty_analyze(St_empty* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_empty_write = "St-empty.write";
#define MR_FUNC_NAME _func_name_St_empty_write
Returncode St_empty_write(St_empty* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func St_empty__dtl[] = {St_empty_parse, St_empty_analyze_first, St_empty_analyze, St_empty_write};


typedef struct St_comment St_comment; struct St_comment {
  St _base;
  String* line;
  String* kw;
  Char end;
};
static char* _func_name_St_comment_parse = "St-comment.parse";
#define MR_FUNC_NAME _func_name_St_comment_parse
Returncode St_comment_parse(St_comment* self) {
  Bool has_data = true;
  if (NULL != glob->key_word) {
    CHECK(22, f_new_copy(glob->key_word->text, &(self->kw)));
    self->end = glob->key_word->end;
    has_data = self->end != '\n' && self->end != EOF;
  }
  else {
    self->kw = NULL;
  }
  if (has_data) {
    Char _Char0;
    CHECK(28, read_new(&(String){1, 0, ""}, &(self->line), &(_Char0)));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_comment_analyze_first = "St-comment.analyze-first";
#define MR_FUNC_NAME _func_name_St_comment_analyze_first
Returncode St_comment_analyze_first(St_comment* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_comment_analyze = "St-comment.analyze";
#define MR_FUNC_NAME _func_name_St_comment_analyze
Returncode St_comment_analyze(St_comment* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_comment_write = "St-comment.write";
#define MR_FUNC_NAME _func_name_St_comment_write
Returncode St_comment_write(St_comment* self) {
  if (NULL != self->line) {
    CHECK(38, write(&(String){4, 3, "// "}));
    if (NULL != self->kw) {
      CHECK(40, write(self->kw));
      CHECK(41, write_c(self->end));
    }
    CHECK(42, write(self->line));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_comment__dtl[] = {St_comment_parse, St_comment_analyze_first, St_comment_analyze, St_comment_write};


static char* _func_name_f_parse_new_node = "f-parse-new-node";
#define MR_FUNC_NAME _func_name_f_parse_new_node
Returncode f_parse_new_node(Type node_type, St* father) {
  if (node_type.size <= 0) RAISE(46)
  St* node = malloc(node_type.size);
  if (node == NULL) RAISE(46)
  if (node_type.dtl != NULL) { *((Func**)(node)) = node_type.dtl; }
  CHECK(47, St_init(node, father));
  CHECK(48, (*((Func**)(node)))[0](node));
  return OK;
}
#undef MR_FUNC_NAME


typedef struct St_node St_node; struct St_node {
  St _base;
  /* parse sons */
  /* write sons */
  /* write sons */
};
static char* _func_name_St_node_parse_line = "St-node.parse-line";
#define MR_FUNC_NAME _func_name_St_node_parse_line
Returncode St_node_parse_line(St_node* self, Int spaces, Bool* more_lines) {
  CHECK(53, read_key_word());
  (*more_lines) = false;
  if (glob->key_word->end == EOF || glob->key_word->spaces < spaces) {
    return OK;
  }
  
  (*more_lines) = true;
  Bool erase_kw = true;
  Type node_type;
  if (glob->key_word->text->length <= 0) {
    node_type = (Type){sizeof(St_empty), St_empty__dtl};
  }
  else {
    Bool _Bool1;
    CHECK(63, get_node_type(glob->key_word->text, &(node_type), &(_Bool1)))
    if ((glob->key_word->end != ' ' && glob->key_word->end != '\n') || !_Bool1) {
      node_type = (Type){sizeof(St_exp), St_exp__dtl};
    }
    else {
      glob->key_word = NULL;
      erase_kw = false;
    }
  }
  CHECK(68, f_parse_new_node(node_type, &(self->_base)));
  if (erase_kw) {
    glob->key_word = NULL;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_parse_block = "St-node.parse-block";
#define MR_FUNC_NAME _func_name_St_node_parse_block
Returncode St_node_parse_block(St_node* self) {
  Int spaces = glob->spaces;
  while (true) {
    Bool _Bool2;
    CHECK(75, St_node_parse_line(self, spaces, &(_Bool2)))
    if (!(_Bool2)) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_parse = "St-node.parse";
#define MR_FUNC_NAME _func_name_St_node_parse
Returncode St_node_parse(St_node* self) {
  Int my_spaces = glob->spaces;
  glob->spaces = my_spaces + 2;
  CHECK(81, St_node_parse_block(self));
  glob->spaces = my_spaces;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_analyze_first = "St-node.analyze-first";
#define MR_FUNC_NAME _func_name_St_node_analyze_first
Returncode St_node_analyze_first(St_node* self) {
  CHECK(85, St_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_analyze = "St-node.analyze";
#define MR_FUNC_NAME _func_name_St_node_analyze
Returncode St_node_analyze(St_node* self) {
  CHECK(88, St_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_write_block = "St-node.write-block";
#define MR_FUNC_NAME _func_name_St_node_write_block
Returncode St_node_write_block(St_node* self) {
  St* son = self->_base.first_son;
  while (true) {
    if (!(NULL != son)) break;
    glob->line_num = son->line_num;
    if (!(NULL != glob->mclass)) {
      CHECK(96, write_spaces());
    }
    CHECK(97, (*((Func**)(son)))[3](son));
    if (!(NULL != glob->mclass)) {
      CHECK(99, write(&(String){2, 1, "\n"}));
    }
    son = son->next_brother;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_write_indent_block = "St-node.write-indent-block";
#define MR_FUNC_NAME _func_name_St_node_write_indent_block
Returncode St_node_write_indent_block(St_node* self) {
  Int my_spaces = glob->spaces;
  glob->spaces = my_spaces + 2;
  CHECK(106, St_node_write_block(self));
  glob->spaces = my_spaces;
  CHECK(108, write_spaces());
  CHECK(109, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_write = "St-node.write";
#define MR_FUNC_NAME _func_name_St_node_write
Returncode St_node_write(St_node* self) {
  CHECK(113, write(&(String){4, 3, " {\n"}));
  CHECK(114, St_node_write_indent_block(self));
  return OK;
}
#undef MR_FUNC_NAME
Func St_node__dtl[] = {St_node_parse, St_node_analyze_first, St_node_analyze, St_node_write};


typedef struct St_file St_file; struct St_file {
  St_node _base;
  String* infile_name;
  Array* argv;
  Int index;
};
static char* _func_name_St_file_init = "St-file.init";
#define MR_FUNC_NAME _func_name_St_file_init
Returncode St_file_init(St_file* self, St* root, Array* argv, Int index) {
  CHECK(123, St_init(&(self->_base._base), root));
  if ((index) < 0 || (index) >= argv->length) RAISE(124)
  self->infile_name = ((String*)(argv->values)) + index;
  self->argv = argv;
  self->index = index;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_parse = "St-file.parse";
#define MR_FUNC_NAME _func_name_St_file_parse
Returncode St_file_parse(St_file* self) {
  CHECK(129, Sys_print(sys, self->infile_name));
  Bool _Bool3;
  CHECK(130, String_has(self->infile_name, '"', &(_Bool3)))
  if (_Bool3) {
    CHECK(131, f_msg_raise(&(String){32, 31, "Illegal \" character in argument"}, self->infile_name));
  }
  if (self->infile_name->length < 6) {
    CHECK(133, f_msg_raise(&(String){19, 18, "too short argument"}, self->infile_name));
  }
  CHECK(134, file_open_read(self->infile_name, &(glob->infile)));
  glob->infile_name = self->infile_name;
  glob->key_word = NULL;
  glob->line_num = 1;
  glob->spaces = 0;
  glob->mclass = NULL;
  
  CHECK(141, St_node_parse_block(&(self->_base)));
  
  CHECK(143, File_close(glob->infile));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_analyze_first = "St-file.analyze-first";
#define MR_FUNC_NAME _func_name_St_file_analyze_first
Returncode St_file_analyze_first(St_file* self) {
  glob->infile_name = self->infile_name;
  glob->node = &(self->_base._base);
  CHECK(148, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_analyze = "St-file.analyze";
#define MR_FUNC_NAME _func_name_St_file_analyze
Returncode St_file_analyze(St_file* self) {
  CHECK(151, Sys_print(sys, self->infile_name));
  glob->infile_name = self->infile_name;
  glob->node = &(self->_base._base);
  CHECK(154, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_write = "St-file.write";
#define MR_FUNC_NAME _func_name_St_file_write
Returncode St_file_write(St_file* self) {
  String* outfile_name = new_string(self->infile_name->length);
  if (outfile_name == NULL) RAISE(157)
  if ((0) < 0 || (self->infile_name->length - 4) < 0 || (0) + (self->infile_name->length - 4) > self->infile_name->length) RAISE(158)
  CHECK(158, String_copy(outfile_name, &(String){self->infile_name->length - 4, self->infile_name->length - 4, self->infile_name->chars + (0)}));
  CHECK(159, String_append(outfile_name, 'c'));
  CHECK(160, Sys_print(sys, outfile_name));
  CHECK(161, file_open_write(outfile_name, &(glob->outfile)));
  
  if (self->index == self->argv->length - 1) {
    CHECK(164, write(&(String){19, 18, "#include \"mr.3.h\"\n"}));
    Int index; for (index = 1; index < self->argv->length - 1; ++index) {
      if ((index) < 0 || (index) >= self->argv->length) RAISE(166)
      String* infile_name = ((String*)(self->argv->values)) + index;
      if ((0) < 0 || (infile_name->length - 4) < 0 || (0) + (infile_name->length - 4) > infile_name->length) RAISE(167)
      String* prefix = &(String){infile_name->length - 4, infile_name->length - 4, infile_name->chars + (0)};
      CHECK(168, write(&(String){11, 10, "#include \""}));
      CHECK(169, write(prefix));
      CHECK(170, write(&(String){4, 3, "c\"\n"}));
    }
    CHECK(171, write(&(String){2, 1, "\n"}));
  }
  
  CHECK(173, write(&(String){22, 21, "static char* _mr_file"}));
  CHECK(174, write_int(self->index));
  CHECK(175, write(&(String){10, 9, "_name = \""}));
  CHECK(176, write(self->infile_name));
  CHECK(177, write(&(String){33, 32, "\";\n#define MR_FILE_NAME _mr_file"}));
  CHECK(178, write_int(self->index));
  CHECK(179, write(&(String){8, 7, "_name\n\n"}));
  glob->infile_name = self->infile_name;
  
  CHECK(182, St_node_write_block(&(self->_base)));
  
  CHECK(184, write(&(String){22, 21, "\n#undef MR_FILE_NAME\n"}));
  
  CHECK(186, File_close(glob->outfile));
  free(outfile_name);
  return OK;
}
#undef MR_FUNC_NAME
Func St_file__dtl[] = {St_file_parse, St_file_analyze_first, St_file_analyze, St_file_write};


typedef struct St_root St_root; struct St_root {
  St _base;
  Array* argv;
};
static char* _func_name_St_root_init = "St-root.init";
#define MR_FUNC_NAME _func_name_St_root_init
Returncode St_root_init(St_root* self, Array* argv) {
  CHECK(194, St_init(&(self->_base), NULL));
  self->argv = argv;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_parse = "St-root.parse";
#define MR_FUNC_NAME _func_name_St_root_parse
Returncode St_root_parse(St_root* self) {
  Int index; for (index = 1; index < self->argv->length; ++index) {
    St_file* st_file = malloc(sizeof(St_file));
    if (st_file == NULL) RAISE(199)
    *((Func**)(st_file)) = St_file__dtl;
    CHECK(200, St_file_init(st_file, &(self->_base), self->argv, index));
    CHECK(201, (*((Func**)(st_file)))[0](st_file));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_analyze_first = "St-root.analyze-first";
#define MR_FUNC_NAME _func_name_St_root_analyze_first
Returncode St_root_analyze_first(St_root* self) {
  CHECK(204, St_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_analyze = "St-root.analyze";
#define MR_FUNC_NAME _func_name_St_root_analyze
Returncode St_root_analyze(St_root* self) {
  CHECK(207, (*((Func**)(self)))[1](self));
  CHECK(208, St_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_write = "St-root.write";
#define MR_FUNC_NAME _func_name_St_root_write
Returncode St_root_write(St_root* self) {
  St* son = self->_base.first_son;
  while (true) {
    if (!(NULL != son)) break;
    CHECK(214, (*((Func**)(son)))[3](son));
    son = son->next_brother;
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_root__dtl[] = {St_root_parse, St_root_analyze_first, St_root_analyze, St_root_write};


typedef struct St_native St_native; struct St_native {
  St_comment _base;
};
static char* _func_name_St_native_parse = "St-native.parse";
#define MR_FUNC_NAME _func_name_St_native_parse
Returncode St_native_parse(St_native* self) {
  CHECK(220, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_analyze_first = "St-native.analyze-first";
#define MR_FUNC_NAME _func_name_St_native_analyze_first
Returncode St_native_analyze_first(St_native* self) {
  CHECK(222, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_analyze = "St-native.analyze";
#define MR_FUNC_NAME _func_name_St_native_analyze
Returncode St_native_analyze(St_native* self) {
  CHECK(224, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_write = "St-native.write";
#define MR_FUNC_NAME _func_name_St_native_write
Returncode St_native_write(St_native* self) {
  CHECK(226, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_native__dtl[] = {St_native_parse, St_native_analyze_first, St_native_analyze, St_native_write};

#undef MR_FILE_NAME
