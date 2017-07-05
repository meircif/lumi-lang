static char* _mr_file6_name = "flow.2.mr";
#define MR_FILE_NAME _mr_file6_name
/* MR3 compiler - flow control */

typedef struct St_if St_if; struct St_if {
  St_node _base;
  Mexp* condition;
};
static char* _func_name_St_if_parse = "St-if.parse";
#define MR_FUNC_NAME _func_name_St_if_parse
Returncode St_if_parse(St_if* self) {
  Char _Char0;
  CHECK(7, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char0)));
  CHECK(8, St_node_parse(&(self->_base)));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_if_analyze_first = "St-if.analyze-first";
#define MR_FUNC_NAME _func_name_St_if_analyze_first
Returncode St_if_analyze_first(St_if* self) {
  CHECK(11, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_if_analyze = "St-if.analyze";
#define MR_FUNC_NAME _func_name_St_if_analyze
Returncode St_if_analyze(St_if* self) {
  CHECK(14, Mexp_analyze_type(self->condition, glob->type_bool));
  CHECK(15, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_if_write = "St-if.write";
#define MR_FUNC_NAME _func_name_St_if_write
Returncode St_if_write(St_if* self) {
  CHECK(18, Mexp_write_intro(self->condition));
  CHECK(19, write(&(String){5, 4, "if ("}));
  CHECK(20, Mexp_write_final(self->condition));
  CHECK(21, write(&(String){2, 1, ")"}));
  CHECK(22, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_if__dtl[] = {St_if_parse, St_if_analyze_first, St_if_analyze, St_if_write};


typedef struct St_else St_else; struct St_else {
  St_node _base;
};
static char* _func_name_St_else_parse = "St-else.parse";
#define MR_FUNC_NAME _func_name_St_else_parse
Returncode St_else_parse(St_else* self) {
  self->_base._base.is_else = true;
  CHECK(28, St_node_parse(&(self->_base)));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_analyze_first = "St-else.analyze-first";
#define MR_FUNC_NAME _func_name_St_else_analyze_first
Returncode St_else_analyze_first(St_else* self) {
  CHECK(31, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_analyze = "St-else.analyze";
#define MR_FUNC_NAME _func_name_St_else_analyze
Returncode St_else_analyze(St_else* self) {
  CHECK(34, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_write = "St-else.write";
#define MR_FUNC_NAME _func_name_St_else_write
Returncode St_else_write(St_else* self) {
  CHECK(37, write(&(String){5, 4, "else"}));
  CHECK(38, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_else__dtl[] = {St_else_parse, St_else_analyze_first, St_else_analyze, St_else_write};


typedef struct St_else_if St_else_if; struct St_else_if {
  St_else _base;
};
static char* _func_name_St_else_if_parse = "St-else-if.parse";
#define MR_FUNC_NAME _func_name_St_else_if_parse
Returncode St_else_if_parse(St_else_if* self) {
  self->_base._base._base.is_else = true;
  St_if* st_if = malloc(sizeof(St_if));
  if (st_if == NULL) RAISE(44)
  *((Func**)(st_if)) = St_if__dtl;
  CHECK(45, St_init(&(st_if->_base._base), &(self->_base._base._base)));
  CHECK(46, (*((Func**)(st_if)))[0](st_if));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_analyze_first = "St-else-if.analyze-first";
#define MR_FUNC_NAME _func_name_St_else_if_analyze_first
Returncode St_else_if_analyze_first(St_else_if* self) {
  CHECK(49, St_else_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_analyze = "St-else-if.analyze";
#define MR_FUNC_NAME _func_name_St_else_if_analyze
Returncode St_else_if_analyze(St_else_if* self) {
  while (true) {
    if (!(NULL != self->_base._base._base.next_brother && self->_base._base._base.next_brother->is_else)) break;
    self->_base._base._base.last_son->next_brother = self->_base._base._base.next_brother;
    self->_base._base._base.last_son = self->_base._base._base.next_brother;
    self->_base._base._base.last_son->father = &(self->_base._base._base);
    self->_base._base._base.next_brother = self->_base._base._base.last_son->next_brother;
    self->_base._base._base.last_son->next_brother = NULL;
  }
  CHECK(59, St_else_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_write = "St-else-if.write";
#define MR_FUNC_NAME _func_name_St_else_if_write
Returncode St_else_if_write(St_else_if* self) {
  CHECK(62, St_else_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_else_if__dtl[] = {St_else_if_parse, St_else_if_analyze_first, St_else_if_analyze, St_else_if_write};


typedef struct St_do St_do; struct St_do {
  St_node _base;
};
static char* _func_name_St_do_parse = "St-do.parse";
#define MR_FUNC_NAME _func_name_St_do_parse
Returncode St_do_parse(St_do* self) {
  CHECK(67, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_analyze_first = "St-do.analyze-first";
#define MR_FUNC_NAME _func_name_St_do_analyze_first
Returncode St_do_analyze_first(St_do* self) {
  CHECK(70, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_analyze = "St-do.analyze";
#define MR_FUNC_NAME _func_name_St_do_analyze
Returncode St_do_analyze(St_do* self) {
  CHECK(73, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_write = "St-do.write";
#define MR_FUNC_NAME _func_name_St_do_write
Returncode St_do_write(St_do* self) {
  CHECK(76, write(&(String){13, 12, "while (true)"}));
  CHECK(77, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_do__dtl[] = {St_do_parse, St_do_analyze_first, St_do_analyze, St_do_write};


typedef struct St_while St_while; struct St_while {
  St _base;
  Mexp* condition;
};
static char* _func_name_St_while_parse = "St-while.parse";
#define MR_FUNC_NAME _func_name_St_while_parse
Returncode St_while_parse(St_while* self) {
  Char _Char1;
  CHECK(84, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char1)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_analyze_first = "St-while.analyze-first";
#define MR_FUNC_NAME _func_name_St_while_analyze_first
Returncode St_while_analyze_first(St_while* self) {
  /* nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_analyze = "St-while.analyze";
#define MR_FUNC_NAME _func_name_St_while_analyze
Returncode St_while_analyze(St_while* self) {
  CHECK(90, Mexp_analyze_type(self->condition, glob->type_bool));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_write = "St-while.write";
#define MR_FUNC_NAME _func_name_St_while_write
Returncode St_while_write(St_while* self) {
  CHECK(93, Mexp_write_intro(self->condition));
  CHECK(94, write(&(String){7, 6, "if (!("}));
  CHECK(95, Mexp_write_final(self->condition));
  CHECK(96, write(&(String){10, 9, ")) break;"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_while__dtl[] = {St_while_parse, St_while_analyze_first, St_while_analyze, St_while_write};


typedef struct St_for St_for; struct St_for {
  St_node _base;
  String* index_name;
  Mexp* start;
  Mexp* end;
};
static char* _func_name_St_for_parse = "St-for.parse";
#define MR_FUNC_NAME _func_name_St_for_parse
Returncode St_for_parse(St_for* self) {
  Char _Char2;
  CHECK(105, read_new(&(String){2, 1, " "}, &(self->index_name), &(_Char2)));
  CHECK(106, read_ignore(3));
  self->start = NULL;
  Char _Char3;
  CHECK(108, parse_new_exp(&(String){2, 1, ":"}, &(self->end), &(_Char3)))
  if (_Char3 == ':') {
    self->start = self->end;
    Char _Char4;
    CHECK(110, parse_new_exp(&(String){1, 0, ""}, &(self->end), &(_Char4)));
  }
  Mvar* mvar;
  CHECK(112, init_new_var(glob->type_int, &(mvar)));
  CHECK(113, f_new_copy(self->index_name, &(mvar->name)));
  CHECK(114, f_copy_new_var_map(self->_base._base.var_map, &(self->_base._base.sons_var_map)));
  CHECK(115, add_var(self->_base._base.sons_var_map, mvar));
  CHECK(116, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_analyze_first = "St-for.analyze-first";
#define MR_FUNC_NAME _func_name_St_for_analyze_first
Returncode St_for_analyze_first(St_for* self) {
  CHECK(119, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_analyze = "St-for.analyze";
#define MR_FUNC_NAME _func_name_St_for_analyze
Returncode St_for_analyze(St_for* self) {
  if (NULL != self->start) {
    CHECK(123, Mexp_analyze_type(self->start, glob->type_int));
  }
  CHECK(124, Mexp_analyze_type(self->end, glob->type_int));
  CHECK(125, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_write = "St-for.write";
#define MR_FUNC_NAME _func_name_St_for_write
Returncode St_for_write(St_for* self) {
  /* {int index; for (index = (start); index < (end); ++index) */
  if (NULL != self->start) {
    CHECK(130, Mexp_write_intro(self->start));
  }
  CHECK(131, Mexp_write_intro(self->end));
  CHECK(132, write(&(String){6, 5, "{int "}));
  CHECK(133, write_cstyle(self->index_name));
  CHECK(134, write(&(String){8, 7, "; for ("}));
  CHECK(135, write_cstyle(self->index_name));
  CHECK(136, write(&(String){5, 4, " = ("}));
  if (NULL != self->start) {
    CHECK(138, Mexp_write_final(self->start));
  }
  else {
    CHECK(140, write(&(String){2, 1, "0"}));
  }
  CHECK(141, write(&(String){4, 3, "); "}));
  CHECK(142, write_cstyle(self->index_name));
  CHECK(143, write(&(String){5, 4, " < ("}));
  CHECK(144, Mexp_write_final(self->end));
  CHECK(145, write(&(String){6, 5, "); ++"}));
  CHECK(146, write_cstyle(self->index_name));
  CHECK(147, write(&(String){2, 1, ")"}));
  CHECK(148, St_node_write(&(self->_base)));
  CHECK(149, write(&(String){2, 1, "}"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_for__dtl[] = {St_for_parse, St_for_analyze_first, St_for_analyze, St_for_write};


typedef struct St_return St_return; struct St_return {
  St _base;
};
static char* _func_name_St_return_parse = "St-return.parse";
#define MR_FUNC_NAME _func_name_St_return_parse
Returncode St_return_parse(St_return* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_analyze_first = "St-return.analyze-first";
#define MR_FUNC_NAME _func_name_St_return_analyze_first
Returncode St_return_analyze_first(St_return* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_analyze = "St-return.analyze";
#define MR_FUNC_NAME _func_name_St_return_analyze
Returncode St_return_analyze(St_return* self) {
  while (true) {
    St* next = self->_base.next_brother;
    if (!(NULL != next)) break;
    self->_base.next_brother = next->next_brother;
    free(next);
  }
  self->_base.father->last_son = &(self->_base);
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_write = "St-return.write";
#define MR_FUNC_NAME _func_name_St_return_write
Returncode St_return_write(St_return* self) {
  CHECK(168, write(&(String){11, 10, "return OK;"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_return__dtl[] = {St_return_parse, St_return_analyze_first, St_return_analyze, St_return_write};


typedef struct St_raise St_raise; struct St_raise {
  St_return _base;
};
static char* _func_name_St_raise_parse = "St-raise.parse";
#define MR_FUNC_NAME _func_name_St_raise_parse
Returncode St_raise_parse(St_raise* self) {
  self->_base._base.line_num = self->_base._base.line_num - 1;
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_analyze_first = "St-raise.analyze-first";
#define MR_FUNC_NAME _func_name_St_raise_analyze_first
Returncode St_raise_analyze_first(St_raise* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_analyze = "St-raise.analyze";
#define MR_FUNC_NAME _func_name_St_raise_analyze
Returncode St_raise_analyze(St_raise* self) {
  CHECK(179, St_return_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_write = "St-raise.write";
#define MR_FUNC_NAME _func_name_St_raise_write
Returncode St_raise_write(St_raise* self) {
  CHECK(182, write_tb_raise());
  return OK;
}
#undef MR_FUNC_NAME
Func St_raise__dtl[] = {St_raise_parse, St_raise_analyze_first, St_raise_analyze, St_raise_write};

#undef MR_FILE_NAME
