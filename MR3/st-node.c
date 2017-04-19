static char* _mr_file6_name = "st-node.2.mr";
#define MR_FILE_NAME _mr_file6_name
/* MR3 compiler - basic syntax tree node */

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
  self->sons_var_map = NULL;
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
      CHECK(27, f_copy_new_var_map(father->sons_var_map, &(self->var_map)));
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
static char* _func_name_St_analyze = "St.analyze";
#define MR_FUNC_NAME _func_name_St_analyze
Returncode St_analyze(St* self) {
  St* son = self->first_son;
  while (true) {
    if (!(NULL != son)) break;
    glob->line_num = son->line_num;
    glob->node = son;
    CHECK(39, (*((Func**)(son)))[1](son));
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
    CHECK(49, (*((Func**)(son)))[2](son));
    son = son->next_brother;
    
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_add_var = "St.add-var";
#define MR_FUNC_NAME _func_name_St_add_var
Returncode St_add_var(St* self, Mvar* mvar) {
  if (NULL != glob->mclass) {
    CHECK(54, add_var(glob->mclass->members, mvar));
  }
  else {
    if (NULL != self->father && NULL != self->father->sons_var_map) {
      CHECK(56, add_var(self->father->sons_var_map, mvar));
    }
    else {
      CHECK(58, add_var(glob->var_map, mvar));
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_m_find_var = "St.m-find-var";
#define MR_FUNC_NAME _func_name_St_m_find_var
Returncode St_m_find_var(St* self, String* name, Mvar** mvar) {
  if (NULL != self->var_map) {
    CHECK(62, Var_map_find(self->var_map, name, &((*mvar))));
    if (NULL != (*mvar)) {
      return OK;
    }
  }
  if (NULL != self->father) {
    CHECK(66, St_m_find_var(self->father, name, &((*mvar))));
  }
  else {
    CHECK(68, Var_map_find(glob->var_map, name, &((*mvar))));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St__dtl[] = {St_parse, St_analyze, St_write};

static char* _func_name_m_find_var = "m-find-var";
#define MR_FUNC_NAME _func_name_m_find_var
Returncode m_find_var(String* name, Mvar** mvar) {
  CHECK(71, St_m_find_var(glob->node, name, &((*mvar))));
  return OK;
}
#undef MR_FUNC_NAME


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
Func St_empty__dtl[] = {St_empty_parse, St_empty_analyze, St_empty_write};


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
    CHECK(91, f_new_copy(glob->key_word->text, &(self->kw)));
    self->end = glob->key_word->end;
    has_data = self->end != '\n' && self->end != EOF;
  }
  else {
    self->kw = NULL;
  }
  if (has_data) {
    Char _Char0;
    CHECK(97, read_new(&(String){1, 0, ""}, &(self->line), &(_Char0)));
  }
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
    CHECK(104, write(&(String){4, 3, "// "}));
    if (NULL != self->kw) {
      CHECK(106, write(self->kw));
      CHECK(107, write_c(self->end));
    }
    CHECK(108, write(self->line));
  }
  return OK;
}
#undef MR_FUNC_NAME
Func St_comment__dtl[] = {St_comment_parse, St_comment_analyze, St_comment_write};


typedef struct St_exp St_exp; struct St_exp {
  St _base;
  Mexp* exp;
};
static char* _func_name_St_exp_parse = "St-exp.parse";
#define MR_FUNC_NAME _func_name_St_exp_parse
Returncode St_exp_parse(St_exp* self) {
  Char _Char1;
  CHECK(115, parse_new_exp_with_kw(&(String){1, 0, ""}, &(self->exp), &(_Char1)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_analyze = "St-exp.analyze";
#define MR_FUNC_NAME _func_name_St_exp_analyze
Returncode St_exp_analyze(St_exp* self) {
  CHECK(118, Mexp_analyze(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_exp_write = "St-exp.write";
#define MR_FUNC_NAME _func_name_St_exp_write
Returncode St_exp_write(St_exp* self) {
  CHECK(121, Mexp_write_intro(self->exp));
  CHECK(122, Mexp_write_final(self->exp));
  return OK;
}
#undef MR_FUNC_NAME
Func St_exp__dtl[] = {St_exp_parse, St_exp_analyze, St_exp_write};


static char* _func_name_f_parse_new_node = "f-parse-new-node";
#define MR_FUNC_NAME _func_name_f_parse_new_node
Returncode f_parse_new_node(Type node_type, St* father) {
  if (node_type.size <= 0) RAISE(126)
  St* node = malloc(node_type.size);
  if (node == NULL) RAISE(126)
  if (node_type.dtl != NULL) { *((Func**)(node)) = node_type.dtl; }
  CHECK(127, St_init(node, father));
  CHECK(128, (*((Func**)(node)))[0](node));
  return OK;
}
#undef MR_FUNC_NAME


typedef struct St_node St_node; struct St_node {
  St _base;
  /* parse sons */
  /* write sons */
};
static char* _func_name_St_node_parse_line = "St-node.parse-line";
#define MR_FUNC_NAME _func_name_St_node_parse_line
Returncode St_node_parse_line(St_node* self, Int spaces, Bool* more_lines) {
  CHECK(133, read_key_word());
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
    Bool _Bool2;
    CHECK(143, get_node_type(glob->key_word->text, &(node_type), &(_Bool2)))
    if ((glob->key_word->end != ' ' && glob->key_word->end != '\n') || !_Bool2) {
      node_type = (Type){sizeof(St_exp), St_exp__dtl};
    }
    else {
      glob->key_word = NULL;
      erase_kw = false;
    }
  }
  CHECK(148, f_parse_new_node(node_type, &(self->_base)));
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
    CHECK(155, St_node_parse_line(self, spaces, &(_Bool3)))
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
  CHECK(161, f_copy_new_var_map(NULL, &(self->_base.sons_var_map)));
  CHECK(162, St_node_parse_block(self));
  glob->spaces = my_spaces;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_analyze = "St-node.analyze";
#define MR_FUNC_NAME _func_name_St_node_analyze
Returncode St_node_analyze(St_node* self) {
  CHECK(166, St_analyze(&(self->_base)));
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
    CHECK(173, write_spaces());
    CHECK(174, (*((Func**)(son)))[2](son));
    CHECK(175, write(&(String){2, 1, "\n"}));
    son = son->next_brother;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_node_write = "St-node.write";
#define MR_FUNC_NAME _func_name_St_node_write
Returncode St_node_write(St_node* self) {
  CHECK(180, write(&(String){4, 3, " {\n"}));
  Int my_spaces = glob->spaces;
  glob->spaces = my_spaces + 2;
  CHECK(183, St_node_write_block(self));
  glob->spaces = my_spaces;
  CHECK(185, write_spaces());
  CHECK(186, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_node__dtl[] = {St_node_parse, St_node_analyze, St_node_write};


typedef struct St_file St_file; struct St_file {
  St_node _base;
  String* infile_name;
  Array* argv;
  Int index;
};
static char* _func_name_St_file_init = "St-file.init";
#define MR_FUNC_NAME _func_name_St_file_init
Returncode St_file_init(St_file* self, St* root, Array* argv, Int index) {
  CHECK(195, St_init(&(self->_base._base), root));
  if ((index) < 0 || (index) >= argv->length) RAISE(196)
  self->infile_name = ((String*)(argv->values)) + index;
  self->argv = argv;
  self->index = index;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_parse = "St-file.parse";
#define MR_FUNC_NAME _func_name_St_file_parse
Returncode St_file_parse(St_file* self) {
  CHECK(201, Sys_print(sys, self->infile_name));
  Bool _Bool4;
  CHECK(202, String_has(self->infile_name, '"', &(_Bool4)))
  if (_Bool4) {
    CHECK(203, f_msg_raise(&(String){32, 31, "Illegal \" character in argument"}, self->infile_name));
  }
  if (self->infile_name->length < 6) {
    CHECK(205, f_msg_raise(&(String){19, 18, "too short argument"}, self->infile_name));
  }
  CHECK(206, file_open_read(self->infile_name, &(glob->infile)));
  glob->infile_name = self->infile_name;
  glob->key_word = NULL;
  glob->line_num = 0;
  glob->spaces = 0;
  glob->mclass = NULL;
  
  CHECK(213, St_node_parse_block(&(self->_base)));
  
  CHECK(215, File_close(glob->infile));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_analyze = "St-file.analyze";
#define MR_FUNC_NAME _func_name_St_file_analyze
Returncode St_file_analyze(St_file* self) {
  CHECK(218, Sys_print(sys, self->infile_name));
  glob->infile_name = self->infile_name;
  glob->node = &(self->_base._base);
  CHECK(221, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_file_write = "St-file.write";
#define MR_FUNC_NAME _func_name_St_file_write
Returncode St_file_write(St_file* self) {
  String* outfile_name = new_string(self->infile_name->length);
  if (outfile_name == NULL) RAISE(224)
  if ((0) < 0 || (self->infile_name->length - 4) < 0 || (0) + (self->infile_name->length - 4) > self->infile_name->length) RAISE(225)
  CHECK(225, String_copy(outfile_name, &(String){self->infile_name->length - 4, self->infile_name->length - 4, self->infile_name->chars + (0)}));
  CHECK(226, String_append(outfile_name, 'c'));
  CHECK(227, Sys_print(sys, outfile_name));
  CHECK(228, file_open_write(outfile_name, &(glob->outfile)));
  
  if (self->index == self->argv->length - 1) {
    CHECK(231, write(&(String){19, 18, "#include \"mr.2.h\"\n"}));
    Int index; for (index = 1; index < self->argv->length - 1; ++index) {
      if ((index) < 0 || (index) >= self->argv->length) RAISE(233)
      String* infile_name = ((String*)(self->argv->values)) + index;
      if ((0) < 0 || (infile_name->length - 4) < 0 || (0) + (infile_name->length - 4) > infile_name->length) RAISE(234)
      String* prefix = &(String){infile_name->length - 4, infile_name->length - 4, infile_name->chars + (0)};
      CHECK(235, write(&(String){11, 10, "#include \""}));
      CHECK(236, write(prefix));
      CHECK(237, write(&(String){4, 3, "c\"\n"}));
    }
    CHECK(238, write(&(String){2, 1, "\n"}));
  }
  
  String* index_str = &(String){64, 0, (char[64]){0}};
  CHECK(241, Int_str(self->index, index_str));
  CHECK(242, write(&(String){22, 21, "static char* _mr_file"}));
  CHECK(243, write(index_str));
  CHECK(244, write(&(String){10, 9, "_name = \""}));
  CHECK(245, write(self->infile_name));
  CHECK(246, write(&(String){33, 32, "\";\n#define MR_FILE_NAME _mr_file"}));
  CHECK(247, write(index_str));
  CHECK(248, write(&(String){8, 7, "_name\n\n"}));
  glob->infile_name = self->infile_name;
  
  CHECK(251, St_node_write_block(&(self->_base)));
  
  CHECK(253, write(&(String){22, 21, "\n#undef MR_FILE_NAME\n"}));
  
  CHECK(255, File_close(glob->outfile));
  free(outfile_name);
  return OK;
}
#undef MR_FUNC_NAME
Func St_file__dtl[] = {St_file_parse, St_file_analyze, St_file_write};


typedef struct St_func St_func; struct St_func {
  St_node _base;
  Mfunc* mfunc;
};
static char* _func_name_St_func_add_args_vars = "St-func.add-args-vars";
#define MR_FUNC_NAME _func_name_St_func_add_args_vars
Returncode St_func_add_args_vars(St_func* self, Arg_node* fisrt_arg) {
  Arg_node* arg = fisrt_arg;
  while (true) {
    if (!(NULL != arg)) break;
    Dec_arg* dec_arg;
    CHECK(267, (*((Func**)(arg)))[4](arg, &(dec_arg)));
    if (!(NULL != dec_arg)) break;
    CHECK(269, St_add_var(&(self->_base._base), dec_arg->mvar));
    arg = arg->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_parse = "St-func.parse";
#define MR_FUNC_NAME _func_name_St_func_parse
Returncode St_func_parse(St_func* self) {
  CHECK(273, parse_new_mfunc(&(self->mfunc)));
  CHECK(274, St_node_parse(&(self->_base)));
  Mvar* _Mvar5;
  CHECK(275, Mfunc_m_new_var(self->mfunc, &(_Mvar5)))
  CHECK(275, St_add_var(&(self->_base._base), _Mvar5));
  CHECK(276, St_func_add_args_vars(self, self->mfunc->args->first_param));
  CHECK(277, St_func_add_args_vars(self, self->mfunc->args->first_out));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_analyze = "St-func.analyze";
#define MR_FUNC_NAME _func_name_St_func_analyze
Returncode St_func_analyze(St_func* self) {
  CHECK(280, Mfunc_analyze(self->mfunc));
  CHECK(281, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_func_write = "St-func.write";
#define MR_FUNC_NAME _func_name_St_func_write
Returncode St_func_write(St_func* self) {
  CHECK(284, Mfunc_write(self->mfunc));
  CHECK(285, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_func__dtl[] = {St_func_parse, St_func_analyze, St_func_write};


typedef struct St_native St_native; struct St_native {
  St_comment _base;
};
static char* _func_name_St_native_parse = "St-native.parse";
#define MR_FUNC_NAME _func_name_St_native_parse
Returncode St_native_parse(St_native* self) {
  CHECK(290, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_analyze = "St-native.analyze";
#define MR_FUNC_NAME _func_name_St_native_analyze
Returncode St_native_analyze(St_native* self) {
  CHECK(292, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_native_write = "St-native.write";
#define MR_FUNC_NAME _func_name_St_native_write
Returncode St_native_write(St_native* self) {
  CHECK(294, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_native__dtl[] = {St_native_parse, St_native_analyze, St_native_write};


typedef struct St_main St_main; struct St_main {
  St_node _base;
};
static char* _func_name_St_main_parse = "St-main.parse";
#define MR_FUNC_NAME _func_name_St_main_parse
Returncode St_main_parse(St_main* self) {
  CHECK(299, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_analyze = "St-main.analyze";
#define MR_FUNC_NAME _func_name_St_main_analyze
Returncode St_main_analyze(St_main* self) {
  CHECK(301, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_main_write = "St-main.write";
#define MR_FUNC_NAME _func_name_St_main_write
Returncode St_main_write(St_main* self) {
  CHECK(303, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_main__dtl[] = {St_main_parse, St_main_analyze, St_main_write};


typedef struct St_dec St_dec; struct St_dec {
  St _base;
  Mvar* mvar;
  Mexp* value;
};
Returncode St_dec_parse_array(St_dec* self);
Returncode St_dec_parse_string(St_dec* self);
static char* _func_name_St_dec_parse = "St-dec.parse";
#define MR_FUNC_NAME _func_name_St_dec_parse
Returncode St_dec_parse(St_dec* self) {
  CHECK(314, init_new_var(NULL, &(self->mvar)));
  self->value = NULL;
  Char _Char6;
  CHECK(316, read_new(&(String){3, 2, " {"}, &(self->mvar->typename), &(_Char6)))
  if (_Char6 == '{') {
    Bool _Bool7;
    CHECK(317, String_equal(self->mvar->typename, &(String){6, 5, "Array"}, &(_Bool7)))
    if (_Bool7) {
      CHECK(318, (*((Func**)(self)))[3](self));
    }
    else {
      Bool _Bool8;
      CHECK(319, String_equal(self->mvar->typename, &(String){7, 6, "String"}, &(_Bool8)))
      if (_Bool8) {
        CHECK(320, (*((Func**)(self)))[4](self));
      }
      else {
        Char _Char9;
        CHECK(322, read_new(&(String){2, 1, "}"}, &(self->mvar->sub_typename), &(_Char9)));
      }
    }
    Char _Char10;
    CHECK(323, read_c(&(_Char10)));
  }
  Char _Char11;
  CHECK(324, read_new(&(String){2, 1, "("}, &(self->mvar->name), &(_Char11)))
  if (_Char11 == '(') {
    Char _Char12;
    CHECK(325, parse_new_exp(&(String){2, 1, ")"}, &(self->value), &(_Char12)));
    Char _Char13;
    CHECK(326, read_c(&(_Char13)));
  }
  CHECK(327, St_add_var(&(self->_base), self->mvar));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_analyze = "St-dec.analyze";
#define MR_FUNC_NAME _func_name_St_dec_analyze
Returncode St_dec_analyze(St_dec* self) {
  CHECK(330, Mvar_analyze(self->mvar));
  if (NULL != self->value) {
    CHECK(332, Mexp_analyze(self->value));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_write = "St-dec.write";
#define MR_FUNC_NAME _func_name_St_dec_write
Returncode St_dec_write(St_dec* self) {
  if (NULL != self->value) {
    CHECK(336, Mexp_write_intro(self->value));
  }
  CHECK(337, write_cstyle(self->mvar->typename));
  if (self->mvar->access != ACCESS_VAR) {
    CHECK(339, write(&(String){2, 1, "*"}));
  }
  CHECK(340, write(&(String){2, 1, " "}));
  CHECK(341, write_cstyle(self->mvar->name));
  if (NULL != self->value) {
    CHECK(343, write(&(String){4, 3, " = "}));
    CHECK(344, Mexp_write_final(self->value));
  }
  CHECK(345, write(&(String){2, 1, ";"}));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_parse_array = "St-dec.parse-array";
#define MR_FUNC_NAME _func_name_St_dec_parse_array
Returncode St_dec_parse_array(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dec_parse_string = "St-dec.parse-string";
#define MR_FUNC_NAME _func_name_St_dec_parse_string
Returncode St_dec_parse_string(St_dec* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
Func St_dec__dtl[] = {St_dec_parse, St_dec_analyze, St_dec_write, St_dec_parse_array, St_dec_parse_string};


typedef struct St_var St_var; struct St_var {
  St_dec _base;
  String* arr_length;
  String* str_length;
};
static char* _func_name_St_var_parse = "St-var.parse";
#define MR_FUNC_NAME _func_name_St_var_parse
Returncode St_var_parse(St_var* self) {
  self->arr_length = NULL;
  self->str_length = NULL;
  CHECK(361, St_dec_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_analyze = "St-var.analyze";
#define MR_FUNC_NAME _func_name_St_var_analyze
Returncode St_var_analyze(St_var* self) {
  CHECK(363, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_write = "St-var.write";
#define MR_FUNC_NAME _func_name_St_var_write
Returncode St_var_write(St_var* self) {
  CHECK(365, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_array = "St-var.parse-array";
#define MR_FUNC_NAME _func_name_St_var_parse_array
Returncode St_var_parse_array(St_var* self) {
  Char _Char14;
  CHECK(368, read_new(&(String){2, 1, ":"}, &(self->arr_length), &(_Char14)));
  Char _Char15;
  CHECK(369, read_new(&(String){3, 2, "{}"}, &(self->_base.mvar->sub_typename), &(_Char15)))
  if (_Char15 == '{') {
    Char _Char16;
    CHECK(370, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char16)));
    Char _Char17;
    CHECK(371, read_c(&(_Char17)));
  }
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_var_parse_string = "St-var.parse-string";
#define MR_FUNC_NAME _func_name_St_var_parse_string
Returncode St_var_parse_string(St_var* self) {
  Char _Char18;
  CHECK(374, read_new(&(String){2, 1, "}"}, &(self->str_length), &(_Char18)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_var__dtl[] = {St_var_parse, St_var_analyze, St_var_write, St_var_parse_array, St_var_parse_string};


typedef struct St_ref St_ref; struct St_ref {
  St_dec _base;
};
static char* _func_name_St_ref_parse = "St-ref.parse";
#define MR_FUNC_NAME _func_name_St_ref_parse
Returncode St_ref_parse(St_ref* self) {
  CHECK(379, St_dec_parse(&(self->_base)));
  self->_base.mvar->access = ACCESS_USER;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_analyze = "St-ref.analyze";
#define MR_FUNC_NAME _func_name_St_ref_analyze
Returncode St_ref_analyze(St_ref* self) {
  CHECK(382, St_dec_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_write = "St-ref.write";
#define MR_FUNC_NAME _func_name_St_ref_write
Returncode St_ref_write(St_ref* self) {
  CHECK(384, St_dec_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_array = "St-ref.parse-array";
#define MR_FUNC_NAME _func_name_St_ref_parse_array
Returncode St_ref_parse_array(St_ref* self) {
  Char _Char19;
  CHECK(387, read_new(&(String){2, 1, "}"}, &(self->_base.mvar->sub_typename), &(_Char19)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_ref_parse_string = "St-ref.parse-string";
#define MR_FUNC_NAME _func_name_St_ref_parse_string
Returncode St_ref_parse_string(St_ref* self) {
  CHECK(390, f_syntax_error(&(String){31, 30, "unexpected parameter to String"}, &(String){1, 0, ""}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_ref__dtl[] = {St_ref_parse, St_ref_analyze, St_ref_write, St_ref_parse_array, St_ref_parse_string};


typedef struct St_new St_new; struct St_new {
  St_var _base;
};
static char* _func_name_St_new_parse = "St-new.parse";
#define MR_FUNC_NAME _func_name_St_new_parse
Returncode St_new_parse(St_new* self) {
  CHECK(395, St_var_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_analyze = "St-new.analyze";
#define MR_FUNC_NAME _func_name_St_new_analyze
Returncode St_new_analyze(St_new* self) {
  CHECK(398, St_var_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_write = "St-new.write";
#define MR_FUNC_NAME _func_name_St_new_write
Returncode St_new_write(St_new* self) {
  CHECK(401, St_var_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_array = "St-new.parse-array";
#define MR_FUNC_NAME _func_name_St_new_parse_array
Returncode St_new_parse_array(St_new* self) {
  CHECK(404, St_var_parse_array(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_new_parse_string = "St-new.parse-string";
#define MR_FUNC_NAME _func_name_St_new_parse_string
Returncode St_new_parse_string(St_new* self) {
  CHECK(407, St_var_parse_string(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_new__dtl[] = {St_new_parse, St_new_analyze, St_new_write, St_new_parse_array, St_new_parse_string};


typedef struct St_delete St_delete; struct St_delete {
  St_comment _base;
};
static char* _func_name_St_delete_parse = "St-delete.parse";
#define MR_FUNC_NAME _func_name_St_delete_parse
Returncode St_delete_parse(St_delete* self) {
  CHECK(412, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_analyze = "St-delete.analyze";
#define MR_FUNC_NAME _func_name_St_delete_analyze
Returncode St_delete_analyze(St_delete* self) {
  CHECK(414, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_delete_write = "St-delete.write";
#define MR_FUNC_NAME _func_name_St_delete_write
Returncode St_delete_write(St_delete* self) {
  CHECK(416, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_delete__dtl[] = {St_delete_parse, St_delete_analyze, St_delete_write};


typedef struct St_if St_if; struct St_if {
  St_node _base;
  Mexp* condition;
};
static char* _func_name_St_if_parse = "St-if.parse";
#define MR_FUNC_NAME _func_name_St_if_parse
Returncode St_if_parse(St_if* self) {
  Char _Char20;
  CHECK(423, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char20)));
  CHECK(424, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_if_analyze = "St-if.analyze";
#define MR_FUNC_NAME _func_name_St_if_analyze
Returncode St_if_analyze(St_if* self) {
  CHECK(427, Mexp_analyze(self->condition));
  CHECK(428, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_if_write = "St-if.write";
#define MR_FUNC_NAME _func_name_St_if_write
Returncode St_if_write(St_if* self) {
  CHECK(431, Mexp_write_intro(self->condition));
  CHECK(432, write(&(String){5, 4, "if ("}));
  CHECK(433, Mexp_write_final(self->condition));
  CHECK(434, write(&(String){2, 1, ")"}));
  CHECK(435, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_if__dtl[] = {St_if_parse, St_if_analyze, St_if_write};


typedef struct St_else St_else; struct St_else {
  St_node _base;
};
static char* _func_name_St_else_parse = "St-else.parse";
#define MR_FUNC_NAME _func_name_St_else_parse
Returncode St_else_parse(St_else* self) {
  CHECK(440, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_analyze = "St-else.analyze";
#define MR_FUNC_NAME _func_name_St_else_analyze
Returncode St_else_analyze(St_else* self) {
  CHECK(443, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_write = "St-else.write";
#define MR_FUNC_NAME _func_name_St_else_write
Returncode St_else_write(St_else* self) {
  CHECK(446, write(&(String){5, 4, "else"}));
  CHECK(447, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_else__dtl[] = {St_else_parse, St_else_analyze, St_else_write};


typedef struct St_else_if St_else_if; struct St_else_if {
  St_if _base;
};
static char* _func_name_St_else_if_parse = "St-else-if.parse";
#define MR_FUNC_NAME _func_name_St_else_if_parse
Returncode St_else_if_parse(St_else_if* self) {
  CHECK(452, St_if_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_analyze = "St-else-if.analyze";
#define MR_FUNC_NAME _func_name_St_else_if_analyze
Returncode St_else_if_analyze(St_else_if* self) {
  CHECK(455, St_if_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_write = "St-else-if.write";
#define MR_FUNC_NAME _func_name_St_else_if_write
Returncode St_else_if_write(St_else_if* self) {
  CHECK(458, write(&(String){8, 7, "else { "}));
  CHECK(459, St_if_write(&(self->_base)));
  CHECK(460, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_else_if__dtl[] = {St_else_if_parse, St_else_if_analyze, St_else_if_write};


typedef struct St_do St_do; struct St_do {
  St_node _base;
};
static char* _func_name_St_do_parse = "St-do.parse";
#define MR_FUNC_NAME _func_name_St_do_parse
Returncode St_do_parse(St_do* self) {
  CHECK(465, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_analyze = "St-do.analyze";
#define MR_FUNC_NAME _func_name_St_do_analyze
Returncode St_do_analyze(St_do* self) {
  CHECK(468, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_write = "St-do.write";
#define MR_FUNC_NAME _func_name_St_do_write
Returncode St_do_write(St_do* self) {
  CHECK(471, write(&(String){13, 12, "while (true)"}));
  CHECK(472, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_do__dtl[] = {St_do_parse, St_do_analyze, St_do_write};


typedef struct St_while St_while; struct St_while {
  St_comment _base;
};
static char* _func_name_St_while_parse = "St-while.parse";
#define MR_FUNC_NAME _func_name_St_while_parse
Returncode St_while_parse(St_while* self) {
  CHECK(477, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_analyze = "St-while.analyze";
#define MR_FUNC_NAME _func_name_St_while_analyze
Returncode St_while_analyze(St_while* self) {
  CHECK(479, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_write = "St-while.write";
#define MR_FUNC_NAME _func_name_St_while_write
Returncode St_while_write(St_while* self) {
  CHECK(481, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_while__dtl[] = {St_while_parse, St_while_analyze, St_while_write};


typedef struct St_for St_for; struct St_for {
  St_node _base;
};
static char* _func_name_St_for_parse = "St-for.parse";
#define MR_FUNC_NAME _func_name_St_for_parse
Returncode St_for_parse(St_for* self) {
  CHECK(486, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_analyze = "St-for.analyze";
#define MR_FUNC_NAME _func_name_St_for_analyze
Returncode St_for_analyze(St_for* self) {
  CHECK(488, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_write = "St-for.write";
#define MR_FUNC_NAME _func_name_St_for_write
Returncode St_for_write(St_for* self) {
  CHECK(490, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_for__dtl[] = {St_for_parse, St_for_analyze, St_for_write};


typedef struct St_return St_return; struct St_return {
  St_comment _base;
};
static char* _func_name_St_return_parse = "St-return.parse";
#define MR_FUNC_NAME _func_name_St_return_parse
Returncode St_return_parse(St_return* self) {
  CHECK(495, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_analyze = "St-return.analyze";
#define MR_FUNC_NAME _func_name_St_return_analyze
Returncode St_return_analyze(St_return* self) {
  CHECK(497, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_write = "St-return.write";
#define MR_FUNC_NAME _func_name_St_return_write
Returncode St_return_write(St_return* self) {
  CHECK(499, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_return__dtl[] = {St_return_parse, St_return_analyze, St_return_write};


typedef struct St_raise St_raise; struct St_raise {
  St_comment _base;
};
static char* _func_name_St_raise_parse = "St-raise.parse";
#define MR_FUNC_NAME _func_name_St_raise_parse
Returncode St_raise_parse(St_raise* self) {
  CHECK(504, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_analyze = "St-raise.analyze";
#define MR_FUNC_NAME _func_name_St_raise_analyze
Returncode St_raise_analyze(St_raise* self) {
  CHECK(506, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_write = "St-raise.write";
#define MR_FUNC_NAME _func_name_St_raise_write
Returncode St_raise_write(St_raise* self) {
  CHECK(508, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_raise__dtl[] = {St_raise_parse, St_raise_analyze, St_raise_write};


typedef struct St_class St_class; struct St_class {
  St_node _base;
  Mtype* mtype;
};
static char* _func_name_St_class_parse = "St-class.parse";
#define MR_FUNC_NAME _func_name_St_class_parse
Returncode St_class_parse(St_class* self) {
  String* name = &(String){128, 0, (char[128]){0}};
  Char _Char21;
  CHECK(516, read(&(String){2, 1, "("}, name, &(_Char21)));
  CHECK(517, Type_map_add(glob->type_map, name, &(self->mtype)));
  Char _Char22;
  CHECK(518, read_new(&(String){2, 1, ")"}, &(self->mtype->base_typename), &(_Char22)));
  Char _Char23;
  CHECK(519, read_c(&(_Char23)));
  glob->mclass = self->mtype;
  CHECK(521, St_node_parse(&(self->_base)));
  glob->mclass = NULL;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_analyze = "St-class.analyze";
#define MR_FUNC_NAME _func_name_St_class_analyze
Returncode St_class_analyze(St_class* self) {
  CHECK(525, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_class_write = "St-class.write";
#define MR_FUNC_NAME _func_name_St_class_write
Returncode St_class_write(St_class* self) {
  CHECK(528, write(&(String){16, 15, "typedef struct "}));
  CHECK(529, write_cstyle(self->mtype->name));
  CHECK(530, write(&(String){2, 1, " "}));
  CHECK(531, write_cstyle(self->mtype->name));
  CHECK(532, write(&(String){3, 2, ";\n"}));
  CHECK(533, write_spaces());
  CHECK(534, write(&(String){8, 7, "struct "}));
  CHECK(535, write_cstyle(self->mtype->name));
  CHECK(536, St_node_write(&(self->_base)));
  CHECK(537, write(&(String){2, 1, ";"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_class__dtl[] = {St_class_parse, St_class_analyze, St_class_write};


typedef struct St_static_class St_static_class; struct St_static_class {
  St_class _base;
};
static char* _func_name_St_static_class_parse = "St-static-class.parse";
#define MR_FUNC_NAME _func_name_St_static_class_parse
Returncode St_static_class_parse(St_static_class* self) {
  CHECK(542, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_analyze = "St-static-class.analyze";
#define MR_FUNC_NAME _func_name_St_static_class_analyze
Returncode St_static_class_analyze(St_static_class* self) {
  CHECK(544, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_static_class_write = "St-static-class.write";
#define MR_FUNC_NAME _func_name_St_static_class_write
Returncode St_static_class_write(St_static_class* self) {
  CHECK(546, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_static_class__dtl[] = {St_static_class_parse, St_static_class_analyze, St_static_class_write};


typedef struct St_dynamic_class St_dynamic_class; struct St_dynamic_class {
  St_class _base;
};
static char* _func_name_St_dynamic_class_parse = "St-dynamic-class.parse";
#define MR_FUNC_NAME _func_name_St_dynamic_class_parse
Returncode St_dynamic_class_parse(St_dynamic_class* self) {
  CHECK(551, St_class_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_analyze = "St-dynamic-class.analyze";
#define MR_FUNC_NAME _func_name_St_dynamic_class_analyze
Returncode St_dynamic_class_analyze(St_dynamic_class* self) {
  CHECK(553, St_class_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_dynamic_class_write = "St-dynamic-class.write";
#define MR_FUNC_NAME _func_name_St_dynamic_class_write
Returncode St_dynamic_class_write(St_dynamic_class* self) {
  CHECK(555, St_class_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_dynamic_class__dtl[] = {St_dynamic_class_parse, St_dynamic_class_analyze, St_dynamic_class_write};

#undef MR_FILE_NAME
