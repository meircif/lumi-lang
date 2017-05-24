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
  String* text;
};
static char* _func_name_St_comment_parse = "St-comment.parse";
#define MR_FUNC_NAME _func_name_St_comment_parse
Returncode St_comment_parse(St_comment* self) {
  Char _Char0;
  CHECK(18, read_new(&(String){1, 0, ""}, &(self->text), &(_Char0)));
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
  CHECK(27, write(&(String){4, 3, "// "}));
  CHECK(28, write(self->text));
  return OK;
}
#undef MR_FUNC_NAME
Func St_comment__dtl[] = {St_comment_parse, St_comment_analyze_first, St_comment_analyze, St_comment_write};


typedef struct St_multi_comment St_multi_comment; struct St_multi_comment {
  St_comment _base;
};
static char* _func_name_St_multi_comment_parse = "St-multi-comment.parse";
#define MR_FUNC_NAME _func_name_St_multi_comment_parse
Returncode St_multi_comment_parse(St_multi_comment* self) {
  String* text = &(String){64 * 1024, 0, (char[64 * 1024]){0}};
  CHECK(34, String_clear(text));
  Char prev = '\0';
  while (true) {
    Char curr;
    CHECK(38, read_c(&(curr)));
    if (!(curr != EOF && (prev != '#' || curr != ')'))) break;
    if (prev != '\0') {
      CHECK(41, String_append(text, prev));
    }
    prev = curr;
  }
  Char _Char1;
  CHECK(43, read_c(&(_Char1)));
  CHECK(44, f_new_copy(text, &(self->_base.text)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_comment_analyze_first = "St-multi-comment.analyze-first";
#define MR_FUNC_NAME _func_name_St_multi_comment_analyze_first
Returncode St_multi_comment_analyze_first(St_multi_comment* self) {
  CHECK(47, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_comment_analyze = "St-multi-comment.analyze";
#define MR_FUNC_NAME _func_name_St_multi_comment_analyze
Returncode St_multi_comment_analyze(St_multi_comment* self) {
  CHECK(50, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_comment_write = "St-multi-comment.write";
#define MR_FUNC_NAME _func_name_St_multi_comment_write
Returncode St_multi_comment_write(St_multi_comment* self) {
  CHECK(53, write(&(String){4, 3, "/* "}));
  CHECK(54, write(self->_base.text));
  CHECK(55, write(&(String){4, 3, " */"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_multi_comment__dtl[] = {St_multi_comment_parse, St_multi_comment_analyze_first, St_multi_comment_analyze, St_multi_comment_write};


typedef struct St_documentation St_documentation; struct St_documentation {
  St_comment _base;
};
static char* _func_name_St_documentation_parse = "St-documentation.parse";
#define MR_FUNC_NAME _func_name_St_documentation_parse
Returncode St_documentation_parse(St_documentation* self) {
  CHECK(60, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_documentation_analyze_first = "St-documentation.analyze-first";
#define MR_FUNC_NAME _func_name_St_documentation_analyze_first
Returncode St_documentation_analyze_first(St_documentation* self) {
  CHECK(62, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_documentation_analyze = "St-documentation.analyze";
#define MR_FUNC_NAME _func_name_St_documentation_analyze
Returncode St_documentation_analyze(St_documentation* self) {
  CHECK(64, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_documentation_write = "St-documentation.write";
#define MR_FUNC_NAME _func_name_St_documentation_write
Returncode St_documentation_write(St_documentation* self) {
  CHECK(66, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_documentation__dtl[] = {St_documentation_parse, St_documentation_analyze_first, St_documentation_analyze, St_documentation_write};


typedef struct St_multi_documentation St_multi_documentation; struct St_multi_documentation {
  St_multi_comment _base;
};
static char* _func_name_St_multi_documentation_parse = "St-multi-documentation.parse";
#define MR_FUNC_NAME _func_name_St_multi_documentation_parse
Returncode St_multi_documentation_parse(St_multi_documentation* self) {
  CHECK(71, St_multi_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_documentation_analyze_first = "St-multi-documentation.analyze-first";
#define MR_FUNC_NAME _func_name_St_multi_documentation_analyze_first
Returncode St_multi_documentation_analyze_first(St_multi_documentation* self) {
  CHECK(73, St_multi_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_documentation_analyze = "St-multi-documentation.analyze";
#define MR_FUNC_NAME _func_name_St_multi_documentation_analyze
Returncode St_multi_documentation_analyze(St_multi_documentation* self) {
  CHECK(75, St_multi_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_multi_documentation_write = "St-multi-documentation.write";
#define MR_FUNC_NAME _func_name_St_multi_documentation_write
Returncode St_multi_documentation_write(St_multi_documentation* self) {
  CHECK(77, St_multi_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_multi_documentation__dtl[] = {St_multi_documentation_parse, St_multi_documentation_analyze_first, St_multi_documentation_analyze, St_multi_documentation_write};


static char* _func_name_f_parse_new_node = "f-parse-new-node";
#define MR_FUNC_NAME _func_name_f_parse_new_node
Returncode f_parse_new_node(Type node_type, St* father) {
  if (node_type.size <= 0) RAISE(81)
  St* node = malloc(node_type.size);
  if (node == NULL) RAISE(81)
  if (node_type.dtl != NULL) { *((Func**)(node)) = node_type.dtl; }
  CHECK(82, St_init(node, father));
  CHECK(83, (*((Func**)(node)))[0](node));
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
  CHECK(88, read_key_word());
  (*more_lines) = false;
  if (glob->key_word->end == EOF || glob->key_word->spaces < spaces) {
    return OK;
  }
  
  (*more_lines) = true;
  Bool erase_kw = true;
  Type node_type;
  if (glob->key_word->text->length <= 0) {
    if (glob->key_word->end == '(') {
      Char ch;
      CHECK(99, read_c(&(ch)));
      if (ch != '#') {
        CHECK(101, f_syntax_error_c(&(String){31, 30, "unecpeted character after '(':"}, ch));
      }
      CHECK(102, read_c(&(ch)));
      if (ch == '#') {
        node_type = (Type){sizeof(St_multi_documentation), St_multi_documentation__dtl};
      }
      else {
        node_type = (Type){sizeof(St_multi_comment), St_multi_comment__dtl};
      }
    }
    else {
      node_type = (Type){sizeof(St_empty), St_empty__dtl};
    }
  }
  else {
    Bool _Bool2;
    CHECK(109, get_node_type(glob->key_word->text, &(node_type), &(_Bool2)))
    if ((glob->key_word->end != ' ' && glob->key_word->end != '\n') || !_Bool2) {
      node_type = (Type){sizeof(St_exp), St_exp__dtl};
    }
    else {
      glob->key_word = NULL;
      erase_kw = false;
    }
  }
  CHECK(114, f_parse_new_node(node_type, &(self->_base)));
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
    Bool _Bool3;
    CHECK(121, St_node_parse_line(self, spaces, &(_Bool3)))
    if (!(_Bool3)) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_parse = "St-node.parse";
#define MR_FUNC_NAME _func_name_St_node_parse
Returncode St_node_parse(St_node* self) {
  Int my_spaces = glob->spaces;
  glob->spaces = my_spaces + 2;
  CHECK(127, St_node_parse_block(self));
  glob->spaces = my_spaces;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_analyze_first = "St-node.analyze-first";
#define MR_FUNC_NAME _func_name_St_node_analyze_first
Returncode St_node_analyze_first(St_node* self) {
  CHECK(131, St_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_analyze = "St-node.analyze";
#define MR_FUNC_NAME _func_name_St_node_analyze
Returncode St_node_analyze(St_node* self) {
  CHECK(134, St_analyze(&(self->_base)));
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
      CHECK(142, write_spaces());
    }
    CHECK(143, (*((Func**)(son)))[3](son));
    if (!(NULL != glob->mclass)) {
      CHECK(145, write(&(String){2, 1, "\n"}));
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
  CHECK(152, St_node_write_block(self));
  glob->spaces = my_spaces;
  CHECK(154, write_spaces());
  CHECK(155, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_write = "St-node.write";
#define MR_FUNC_NAME _func_name_St_node_write
Returncode St_node_write(St_node* self) {
  CHECK(159, write(&(String){4, 3, " {\n"}));
  CHECK(160, St_node_write_indent_block(self));
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
  CHECK(169, St_init(&(self->_base._base), root));
  if ((index) < 0 || (index) >= argv->length) RAISE(170)
  self->infile_name = ((String*)(argv->values)) + index;
  self->argv = argv;
  self->index = index;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_parse = "St-file.parse";
#define MR_FUNC_NAME _func_name_St_file_parse
Returncode St_file_parse(St_file* self) {
  Bool _Bool4;
  CHECK(175, String_has(self->infile_name, '"', &(_Bool4)))
  if (_Bool4) {
    CHECK(176, f_msg_raise(&(String){32, 31, "Illegal \" character in argument"}, self->infile_name));
  }
  if (self->infile_name->length < 6) {
    CHECK(178, f_msg_raise(&(String){19, 18, "too short argument"}, self->infile_name));
  }
  CHECK(179, file_open_read(self->infile_name, &(glob->infile)));
  glob->infile_name = self->infile_name;
  glob->key_word = NULL;
  glob->line_num = 1;
  glob->spaces = 0;
  glob->mclass = NULL;
  
  CHECK(186, St_node_parse_block(&(self->_base)));
  
  CHECK(188, File_close(glob->infile));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_analyze_first = "St-file.analyze-first";
#define MR_FUNC_NAME _func_name_St_file_analyze_first
Returncode St_file_analyze_first(St_file* self) {
  glob->infile_name = self->infile_name;
  glob->node = &(self->_base._base);
  CHECK(193, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_analyze = "St-file.analyze";
#define MR_FUNC_NAME _func_name_St_file_analyze
Returncode St_file_analyze(St_file* self) {
  glob->infile_name = self->infile_name;
  glob->node = &(self->_base._base);
  CHECK(198, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_write_cfile_name = "St-file.write-cfile-name";
#define MR_FUNC_NAME _func_name_St_file_write_cfile_name
Returncode St_file_write_cfile_name(St_file* self, Int index) {
  if ((index) < 0 || (index) >= self->argv->length) RAISE(201)
  String* infile_name = ((String*)(self->argv->values)) + index;
  if ((0) < 0 || (infile_name->length - 4) < 0 || (0) + (infile_name->length - 4) > infile_name->length) RAISE(202)
  String* prefix = &(String){infile_name->length - 4, infile_name->length - 4, infile_name->chars + (0)};
  CHECK(203, write(&(String){3, 2, " \""}));
  CHECK(204, write(prefix));
  CHECK(205, write(&(String){4, 3, "c\"\n"}));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_write = "St-file.write";
#define MR_FUNC_NAME _func_name_St_file_write
Returncode St_file_write(St_file* self) {
  String* outfile_name = new_string(self->infile_name->length);
  if (outfile_name == NULL) RAISE(209)
  if ((0) < 0 || (self->infile_name->length - 4) < 0 || (0) + (self->infile_name->length - 4) > self->infile_name->length) RAISE(210)
  CHECK(210, String_copy(outfile_name, &(String){self->infile_name->length - 4, self->infile_name->length - 4, self->infile_name->chars + (0)}));
  CHECK(211, String_append(outfile_name, 'c'));
  CHECK(212, file_open_write(outfile_name, &(glob->outfile)));
  
  CHECK(214, write(&(String){21, 20, "#ifndef MR_MAINFILE\n"}));
  CHECK(215, write(&(String){20, 19, "#define MR_MAINFILE"}));
  CHECK(216, St_file_write_cfile_name(self, self->index));
  CHECK(217, write(&(String){15, 14, "#define DEPTH "}));
  CHECK(218, write_int(glob->max_type_depth + 1));
  CHECK(219, write(&(String){20, 19, "\n#include \"mr.3.h\"\n"}));
  CHECK(220, write(&(String){8, 7, "#else\n\n"}));
  
  CHECK(222, write(&(String){29, 28, "#if MR_STAGE == MR_TYPEDEFS\n"}));
  CHECK(223, write(&(String){22, 21, "static char* _mr_file"}));
  CHECK(224, write_int(self->index));
  CHECK(225, write(&(String){10, 9, "_name = \""}));
  CHECK(226, write(self->infile_name));
  CHECK(227, write(&(String){4, 3, "\";\n"}));
  CHECK(228, write(&(String){8, 7, "#endif\n"}));
  CHECK(229, write(&(String){30, 29, "#define MR_FILE_NAME _mr_file"}));
  CHECK(230, write_int(self->index));
  CHECK(231, write(&(String){8, 7, "_name\n\n"}));
  glob->infile_name = self->infile_name;
  
  CHECK(234, St_node_write_block(&(self->_base)));
  
  CHECK(236, write(&(String){23, 22, "\n#undef MR_FILE_NAME\n\n"}));
  
  if (self->argv->length > 2) {
    CHECK(239, write(&(String){21, 20, "#ifndef MR_INCLUDES\n"}));
    CHECK(240, write(&(String){21, 20, "#define MR_INCLUDES\n"}));
    Int n; for (n = 1; n < self->argv->length; ++n) {
      if (n != self->index) {
        CHECK(243, write(&(String){9, 8, "#include"}));
        CHECK(244, St_file_write_cfile_name(self, n));
      }
    }
    
  }
  Int depth; for (depth = 0; depth < glob->max_type_depth; ++depth) {
    if (depth == 0) {
      CHECK(248, write(&(String){5, 4, "#if "}));
    }
    else {
      CHECK(250, write(&(String){7, 6, "#elif "}));
    }
    CHECK(251, write(&(String){22, 21, "MR_STAGE == MR_TYPES("}));
    CHECK(252, write_int(depth + 1));
    CHECK(253, write(&(String){3, 2, ")\n"}));
    CHECK(254, write(&(String){17, 16, "#undef MR_STAGE\n"}));
    CHECK(255, write(&(String){27, 26, "#define MR_STAGE MR_TYPES("}));
    CHECK(256, write_int(depth + 2));
    CHECK(257, write(&(String){3, 2, ")\n"}));
    if (depth == glob->max_type_depth - 1) {
      CHECK(259, write(&(String){8, 7, "#endif\n"}));
    }
    
  }
  if (self->argv->length > 2) {
    CHECK(262, write(&(String){20, 19, "#undef MR_INCLUDES\n"}));
    CHECK(263, write(&(String){9, 8, "#endif\n\n"}));
  }
  
  CHECK(265, write(&(String){8, 7, "#endif\n"}));
  
  CHECK(267, File_close(glob->outfile));
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
  CHECK(275, St_init(&(self->_base), NULL));
  self->argv = argv;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_parse = "St-root.parse";
#define MR_FUNC_NAME _func_name_St_root_parse
Returncode St_root_parse(St_root* self) {
  Int index; for (index = 1; index < self->argv->length; ++index) {
    St_file* st_file = malloc(sizeof(St_file));
    if (st_file == NULL) RAISE(280)
    *((Func**)(st_file)) = St_file__dtl;
    CHECK(281, St_file_init(st_file, &(self->_base), self->argv, index));
    CHECK(282, (*((Func**)(st_file)))[0](st_file));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_analyze_first = "St-root.analyze-first";
#define MR_FUNC_NAME _func_name_St_root_analyze_first
Returncode St_root_analyze_first(St_root* self) {
  CHECK(285, St_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_analyze = "St-root.analyze";
#define MR_FUNC_NAME _func_name_St_root_analyze
Returncode St_root_analyze(St_root* self) {
  CHECK(288, (*((Func**)(self)))[1](self));
  CHECK(289, St_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_root_write = "St-root.write";
#define MR_FUNC_NAME _func_name_St_root_write
Returncode St_root_write(St_root* self) {
  St* son = self->_base.first_son;
  while (true) {
    if (!(NULL != son)) break;
    CHECK(295, (*((Func**)(son)))[3](son));
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
  CHECK(301, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_analyze_first = "St-native.analyze-first";
#define MR_FUNC_NAME _func_name_St_native_analyze_first
Returncode St_native_analyze_first(St_native* self) {
  CHECK(303, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_analyze = "St-native.analyze";
#define MR_FUNC_NAME _func_name_St_native_analyze
Returncode St_native_analyze(St_native* self) {
  CHECK(305, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_write = "St-native.write";
#define MR_FUNC_NAME _func_name_St_native_write
Returncode St_native_write(St_native* self) {
  CHECK(307, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_native__dtl[] = {St_native_parse, St_native_analyze_first, St_native_analyze, St_native_write};

#undef MR_FILE_NAME
