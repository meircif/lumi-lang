static char* _mr_file8_name = "flow.2.mr";
#define MR_FILE_NAME _mr_file8_name
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
  CHECK(14, Mexp_analyze(self->condition));
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
  CHECK(27, St_node_parse(&(self->_base)));
  
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_analyze_first = "St-else.analyze-first";
#define MR_FUNC_NAME _func_name_St_else_analyze_first
Returncode St_else_analyze_first(St_else* self) {
  CHECK(30, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_analyze = "St-else.analyze";
#define MR_FUNC_NAME _func_name_St_else_analyze
Returncode St_else_analyze(St_else* self) {
  CHECK(33, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_write = "St-else.write";
#define MR_FUNC_NAME _func_name_St_else_write
Returncode St_else_write(St_else* self) {
  CHECK(36, write(&(String){5, 4, "else"}));
  CHECK(37, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_else__dtl[] = {St_else_parse, St_else_analyze_first, St_else_analyze, St_else_write};


typedef struct St_else_if St_else_if; struct St_else_if {
  St_if _base;
};
static char* _func_name_St_else_if_parse = "St-else-if.parse";
#define MR_FUNC_NAME _func_name_St_else_if_parse
Returncode St_else_if_parse(St_else_if* self) {
  CHECK(42, St_if_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_analyze_first = "St-else-if.analyze-first";
#define MR_FUNC_NAME _func_name_St_else_if_analyze_first
Returncode St_else_if_analyze_first(St_else_if* self) {
  CHECK(45, St_if_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_analyze = "St-else-if.analyze";
#define MR_FUNC_NAME _func_name_St_else_if_analyze
Returncode St_else_if_analyze(St_else_if* self) {
  CHECK(48, St_if_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_else_if_write = "St-else-if.write";
#define MR_FUNC_NAME _func_name_St_else_if_write
Returncode St_else_if_write(St_else_if* self) {
  CHECK(51, write(&(String){8, 7, "else { "}));
  CHECK(52, St_if_write(&(self->_base)));
  CHECK(53, write(&(String){2, 1, "}"}));
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
  CHECK(58, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_analyze_first = "St-do.analyze-first";
#define MR_FUNC_NAME _func_name_St_do_analyze_first
Returncode St_do_analyze_first(St_do* self) {
  CHECK(61, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_analyze = "St-do.analyze";
#define MR_FUNC_NAME _func_name_St_do_analyze
Returncode St_do_analyze(St_do* self) {
  CHECK(64, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_do_write = "St-do.write";
#define MR_FUNC_NAME _func_name_St_do_write
Returncode St_do_write(St_do* self) {
  CHECK(67, write(&(String){13, 12, "while (true)"}));
  CHECK(68, St_node_write(&(self->_base)));
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
  CHECK(75, parse_new_exp(&(String){1, 0, ""}, &(self->condition), &(_Char1)));
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
  CHECK(81, Mexp_analyze(self->condition));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_while_write = "St-while.write";
#define MR_FUNC_NAME _func_name_St_while_write
Returncode St_while_write(St_while* self) {
  CHECK(84, Mexp_write_intro(self->condition));
  CHECK(85, write(&(String){7, 6, "if (!("}));
  CHECK(86, Mexp_write_final(self->condition));
  CHECK(87, write(&(String){10, 9, ")) break;"}));
  return OK;
}
#undef MR_FUNC_NAME
Func St_while__dtl[] = {St_while_parse, St_while_analyze_first, St_while_analyze, St_while_write};


typedef struct St_for St_for; struct St_for {
  St_node _base;
};
static char* _func_name_St_for_parse = "St-for.parse";
#define MR_FUNC_NAME _func_name_St_for_parse
Returncode St_for_parse(St_for* self) {
  CHECK(92, St_node_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_analyze_first = "St-for.analyze-first";
#define MR_FUNC_NAME _func_name_St_for_analyze_first
Returncode St_for_analyze_first(St_for* self) {
  CHECK(94, St_node_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_analyze = "St-for.analyze";
#define MR_FUNC_NAME _func_name_St_for_analyze
Returncode St_for_analyze(St_for* self) {
  CHECK(96, St_node_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_for_write = "St-for.write";
#define MR_FUNC_NAME _func_name_St_for_write
Returncode St_for_write(St_for* self) {
  CHECK(98, St_node_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_for__dtl[] = {St_for_parse, St_for_analyze_first, St_for_analyze, St_for_write};


typedef struct St_return St_return; struct St_return {
  St_comment _base;
};
static char* _func_name_St_return_parse = "St-return.parse";
#define MR_FUNC_NAME _func_name_St_return_parse
Returncode St_return_parse(St_return* self) {
  CHECK(103, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_analyze_first = "St-return.analyze-first";
#define MR_FUNC_NAME _func_name_St_return_analyze_first
Returncode St_return_analyze_first(St_return* self) {
  CHECK(105, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_analyze = "St-return.analyze";
#define MR_FUNC_NAME _func_name_St_return_analyze
Returncode St_return_analyze(St_return* self) {
  CHECK(107, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_return_write = "St-return.write";
#define MR_FUNC_NAME _func_name_St_return_write
Returncode St_return_write(St_return* self) {
  CHECK(109, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_return__dtl[] = {St_return_parse, St_return_analyze_first, St_return_analyze, St_return_write};


typedef struct St_raise St_raise; struct St_raise {
  St_comment _base;
};
static char* _func_name_St_raise_parse = "St-raise.parse";
#define MR_FUNC_NAME _func_name_St_raise_parse
Returncode St_raise_parse(St_raise* self) {
  CHECK(114, St_comment_parse(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_analyze_first = "St-raise.analyze-first";
#define MR_FUNC_NAME _func_name_St_raise_analyze_first
Returncode St_raise_analyze_first(St_raise* self) {
  CHECK(116, St_comment_analyze_first(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_analyze = "St-raise.analyze";
#define MR_FUNC_NAME _func_name_St_raise_analyze
Returncode St_raise_analyze(St_raise* self) {
  CHECK(118, St_comment_analyze(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
static char* _func_name_St_raise_write = "St-raise.write";
#define MR_FUNC_NAME _func_name_St_raise_write
Returncode St_raise_write(St_raise* self) {
  CHECK(120, St_comment_write(&(self->_base)));
  return OK;
}
#undef MR_FUNC_NAME
Func St_raise__dtl[] = {St_raise_parse, St_raise_analyze_first, St_raise_analyze, St_raise_write};

#undef MR_FILE_NAME
