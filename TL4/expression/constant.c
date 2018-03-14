#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/constant.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _mr_file10_name = "expression/constant.3.lm";
#endif
#define LUMI_FILE_NAME _mr_file10_name

/* TL4 compiler - Constant expressions */

/* Return whether `text` is a number of base with given `top-digit` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_is_number(String* text, Char top_digit, Bool* is_number);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_is_number = "f-is-number";
#define LUMI_FUNC_NAME _func_name_f_is_number
Returncode f_is_number(String* text, Char top_digit, Bool* is_number) {
  (*is_number) = true;
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(7)
    Char ch = ((text)->values[n]);
    if (ch < '0' || ch > top_digit) {
      (*is_number) = false;
      return OK;
    }
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

/* Return whether `text` is a binary number */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_is_binary(String* text, Bool* is_octal);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_is_binary = "f-is-binary";
#define LUMI_FUNC_NAME _func_name_f_is_binary
Returncode f_is_binary(String* text, Bool* is_octal) {
  CHECK(14, f_is_number(text, '1', &((*is_octal))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

/* Return whether `text` is an octal number */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_is_octal(String* text, Bool* is_octal);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_is_octal = "f-is-octal";
#define LUMI_FUNC_NAME _func_name_f_is_octal
Returncode f_is_octal(String* text, Bool* is_octal) {
  CHECK(18, f_is_number(text, '7', &((*is_octal))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

/* Return whether `text` is a decimal number */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_is_decimal(String* text, Bool* is_octal);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_is_decimal = "f-is-decimal";
#define LUMI_FUNC_NAME _func_name_f_is_decimal
Returncode f_is_decimal(String* text, Bool* is_octal) {
  CHECK(22, f_is_number(text, '9', &((*is_octal))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

/* Return whether `text` is a hexadecimal number */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_is_hex(String* text, Bool* is_hex);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_is_hex = "f-is-hex";
#define LUMI_FUNC_NAME _func_name_f_is_hex
Returncode f_is_hex(String* text, Bool* is_hex) {
  (*is_hex) = true;
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(28)
    Char ch = ((text)->values[n]);
    if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f') && (ch < 'A' || ch > 'F')) {
      (*is_hex) = false;
      return OK;
    }
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* A basic expression that has a single textual value */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct TextExpression TextExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct TextExpression {
  Expression _base;
  String* text;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TextExpression_write(TextExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TextExpression_write = "TextExpression.write";
#define LUMI_FUNC_NAME _func_name_TextExpression_write
Returncode TextExpression_write(TextExpression* self) {
  CHECK(40, write(self->text) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func TextExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func TextExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Constant integer expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct IntExpression IntExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct IntExpression {
  TextExpression _base;
/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode IntExpression_parse_new(IntExpression* self, String* text, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_IntExpression_parse_new = "IntExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_IntExpression_parse_new
Returncode IntExpression_parse_new(IntExpression* self, String* text, Expression** expression) {
  IntExpression* int_expression = malloc(sizeof(IntExpression));
  if (int_expression == NULL) RAISE(46)
  *int_expression = (IntExpression){IntExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL};
  int_expression->_base._base._base._dtl = IntExpression__dtl;
  CHECK(47, IntExpression_parse(int_expression, text) )
  (*expression) = &(int_expression->_base._base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode IntExpression_parse(IntExpression* self, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_IntExpression_parse = "IntExpression.parse";
#define LUMI_FUNC_NAME _func_name_IntExpression_parse
Returncode IntExpression_parse(IntExpression* self, String* text) {
  CHECK(52, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  String* number = text;
  if ((0) < 0 || (0) >= (number)->length) RAISE(54)
  if (((number)->values[0]) == '-') {
    if ((1) < 0 || (number->length - 1) < 0 || (1) + (number->length - 1) > (number)->length) RAISE(55)
    number = (&(String){number->length - 1, number->length - 1, (number)->values + (1)});
  }
  if ((0) < 0 || (0) >= (number)->length) RAISE(56)
  if (((number)->values[0]) == '0' && number->length > 1) {
    if ((1) < 0 || (1) >= (number)->length) RAISE(57)
    Char second = ((number)->values[1]);
    if (second >= '0' && second <= '7') {
      Bool _Bool32;
      CHECK(59, f_is_octal(number, &(_Bool32)) )
      if (!_Bool32) {
        CHECK(60, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){21, 20, "illegal octal number"}, text) )
      }
    }
    else {
      if ((2) < 0 || (number->length - 2) < 0 || (2) + (number->length - 2) > (number)->length) RAISE(62)
      number = (&(String){number->length - 2, number->length - 2, (number)->values + (2)});
      if (second == 'b' || second == 'B') {
        Bool _Bool33;
        CHECK(64, f_is_binary(number, &(_Bool33)) )
        if (!_Bool33) {
          CHECK(65, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal binary number"}, text) )
        }
        CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){36, 35, "binary numbers not supported yet..."}, text) )
      }
      else {
        if (second == 'x' || second == 'X') {
          Bool _Bool34;
          CHECK(69, f_is_hex(number, &(_Bool34)) )
          if (!_Bool34) {
            CHECK(70, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal hexadecimal number"}, text) )
          }
        }
        else {
          CHECK(72, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){15, 14, "illegal number"}, text) )
        }
      }
    }
  }
  else {
    Bool _Bool35;
    CHECK(73, f_is_decimal(number, &(_Bool35)) )
    if (!_Bool35) {
      CHECK(74, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){15, 14, "illegal number"}, text) )
    }
  }
  CHECK(75, Expression_set_simple_type(&(self->_base._base), glob->type_int) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  self->_base._base.constant = true;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func IntExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func IntExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Constant character expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct CharExpression CharExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct CharExpression {
  TextExpression _base;
/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode CharExpression_parse_new(CharExpression* self, String* text, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_CharExpression_parse_new = "CharExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_CharExpression_parse_new
Returncode CharExpression_parse_new(CharExpression* self, String* text, Expression** expression) {
  CharExpression* char_expression = malloc(sizeof(CharExpression));
  if (char_expression == NULL) RAISE(84)
  *char_expression = (CharExpression){CharExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL};
  char_expression->_base._base._base._dtl = CharExpression__dtl;
  CHECK(85, CharExpression_parse(char_expression, text) )
  (*expression) = &(char_expression->_base._base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode CharExpression_parse(CharExpression* self, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_CharExpression_parse = "CharExpression.parse";
#define LUMI_FUNC_NAME _func_name_CharExpression_parse
Returncode CharExpression_parse(CharExpression* self, String* text) {
  CHECK(90, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  Char ch = '\0';
  if (text->length == 3) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(93)
    ch = ((text)->values[1]);
    if (ch == '\'' || ch == '\\') {
      CHECK(95, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
    }
  }
  else {
    if (text->length == 4) {
      if ((1) < 0 || (1) >= (text)->length) RAISE(97)
      if (((text)->values[1]) != '\\') {
        CHECK(98, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
      if ((2) < 0 || (2) >= (text)->length) RAISE(99)
      Bool _Bool36;
      CHECK(99, String_has(&(String){12, 11, "'\"?\\abfnrtv"}, ((text)->values[2]), &(_Bool36)) )
      if (!_Bool36) {
        CHECK(100, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
    }
    else {
      if (text->length == 6) {
        if ((1) < 0 || (1) >= (text)->length) RAISE(102)
        if (((text)->values[1]) != '\\') {
          CHECK(103, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
        }
        if ((2) < 0 || (2) >= (text)->length) RAISE(104)
        ch = ((text)->values[2]);
        if (ch == 'x') {
          if ((3) < 0 || (2) < 0 || (3) + (2) > (text)->length) RAISE(106)
          Bool _Bool37;
          CHECK(106, f_is_hex((&(String){2, 2, (text)->values + (3)}), &(_Bool37)) )
          if (!_Bool37) {
            CHECK(107, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
          }
        }
        else {
          if ((2) < 0 || (3) < 0 || (2) + (3) > (text)->length) RAISE(109)
          Bool _Bool38;
          CHECK(109, f_is_octal((&(String){3, 3, (text)->values + (2)}), &(_Bool38)) )
          if (!_Bool38) {
            CHECK(110, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
          }
        }
      }
      else {
        CHECK(112, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
    }
  }
  if ((text->length - 1) < 0 || (text->length - 1) >= (text)->length) RAISE(113)
  if (((text)->values[text->length - 1]) != '\'') {
    CHECK(114, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
  }
  CHECK(115, Expression_set_simple_type(&(self->_base._base), glob->type_char) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func CharExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func CharExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Constant string expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct StringExpression StringExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct StringExpression {
  TextExpression _base;
  SymbolExpression* symbol;
/* parsing `"some string"` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_parse_new(StringExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_parse_new = "StringExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_StringExpression_parse_new
Returncode StringExpression_parse_new(StringExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  StringExpression* string_expression = malloc(sizeof(StringExpression));
  if (string_expression == NULL) RAISE(126)
  *string_expression = (StringExpression){StringExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL};
  string_expression->_base._base._base._dtl = StringExpression__dtl;
  CHECK(127, StringExpression_parse(string_expression, text, code_node) )
  (*expression) = &(string_expression->_base._base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `"some string"` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_parse(StringExpression* self, String* text, SyntaxTreeCode* code_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_parse = "StringExpression.parse";
#define LUMI_FUNC_NAME _func_name_StringExpression_parse
Returncode StringExpression_parse(StringExpression* self, String* text, SyntaxTreeCode* code_node) {
  self->_base._base.code_node = code_node;
  CHECK(133, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(134, SyntaxTreeNode_check_string(&(self->_base._base._base), text) )
  CHECK(135, Expression_set_simple_type(&(self->_base._base), glob->type_string) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  CHECK(138, StringExpression_m_strip_multilines(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_m_strip_multilines(StringExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_m_strip_multilines = "StringExpression.m-strip-multilines";
#define LUMI_FUNC_NAME _func_name_StringExpression_m_strip_multilines
Returncode StringExpression_m_strip_multilines(StringExpression* self) {
  Int index_write = 1;
  {int index_read; for (index_read = (1); index_read < (self->_base.text->length - 1); ++index_read) {
    if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(143)
    if (((self->_base.text)->values[index_read]) == '\n') {
      Bool skip_new_line = false;
      if (index_read > 0) {
        if ((index_read - 1) < 0 || (index_read - 1) >= (self->_base.text)->length) RAISE(146)
        skip_new_line = ((self->_base.text)->values[index_read - 1]) == '\\';
      }
      Int expected = self->_base._base.code_node->parent->_base.indentation_spaces + 4;
      Int indentation = 0;
      while (true) {
        index_read += 1;
        if (!(index_read < self->_base.text->length - 1)) break;
        if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(152)
        if (!(((self->_base.text)->values[index_read]) == ' ')) break;
        indentation += 1;
        if (!(indentation < expected)) break;
      }
      if (indentation < expected) {
        CHECK(156, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base._base.code_node->_base), indentation, expected) )
      }
      if (skip_new_line) {
        index_write -= 1;
      }
      else {
        if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(161)
        ((self->_base.text)->values[index_write]) = '\\';
        index_write += 1;
        if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(163)
        ((self->_base.text)->values[index_write]) = 'n';
        index_write += 1;
      }
    }
    else {
      if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(166)
      if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(166)
      ((self->_base.text)->values[index_write]) = ((self->_base.text)->values[index_read]);
      index_write += 1;
    }
  }}
  if (index_write < self->_base.text->length - 1) {
    if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(169)
    ((self->_base.text)->values[index_write]) = '"';
    index_write += 1;
    if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(171)
    ((self->_base.text)->values[index_write]) = '\0';
    self->_base.text->length = index_write;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_analyze(StringExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_analyze = "StringExpression.analyze";
#define LUMI_FUNC_NAME _func_name_StringExpression_analyze
Returncode StringExpression_analyze(StringExpression* self) {
  CHECK(175, Expression_add_aux_variable(&(self->_base._base), ACCESS_VAR, false, self->_base._base.result_type, &(self->symbol)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_write_preactions(StringExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_write_preactions = "StringExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_StringExpression_write_preactions
Returncode StringExpression_write_preactions(StringExpression* self) {
  /* `symbol`_Var.max_length = `string-length + 1`; */
  /* `symbol`_Var.length = `string-length`; */
  /* `symbol`_Var.values = "`text`"; */
  CHECK(182, Expression_write_init_var_ref(&(self->_base._base), self->symbol) )
  CHECK(183, Expression_write_refman_init(&(self->_base._base), self->symbol) )
  Int real_length = 1;
  {int index; for (index = (1); index < (self->_base.text->length - 1); ++index) {
    if ((index) < 0 || (index) >= (self->_base.text)->length) RAISE(186)
    if (((self->_base.text)->values[index]) == '\\') {
      index += 1;
    }
    real_length = real_length + 1;
  }}
  CHECK(189, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(190, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(191, write(&(String){19, 18, "_Var.max_length = "}) )
  CHECK(192, write_int(real_length) )
  CHECK(193, write(&(String){3, 2, ";\n"}) )
  CHECK(194, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(195, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(196, write(&(String){15, 14, "_Var.length = "}) )
  CHECK(197, write_int(real_length - 1) )
  CHECK(198, write(&(String){3, 2, ";\n"}) )
  CHECK(199, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(200, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(201, write(&(String){15, 14, "_Var.values = "}) )
  CHECK(202, write(self->_base.text) )
  CHECK(203, write(&(String){3, 2, ";\n"}) )
  CHECK(204, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode StringExpression_write(StringExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_StringExpression_write = "StringExpression.write";
#define LUMI_FUNC_NAME _func_name_StringExpression_write
Returncode StringExpression_write(StringExpression* self) {
  CHECK(207, (self->symbol)->_base._base._dtl[4](self->symbol) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func StringExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func StringExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)StringExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)StringExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)StringExpression_write_preactions};
#endif


/* Constant empty expression `_` */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct EmptyExpression EmptyExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct EmptyExpression {
  Expression _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EmptyExpression_parse_new(EmptyExpression* self, String* text, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EmptyExpression_parse_new = "EmptyExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_EmptyExpression_parse_new
Returncode EmptyExpression_parse_new(EmptyExpression* self, String* text, Expression** expression) {
  EmptyExpression* empty_expression = malloc(sizeof(EmptyExpression));
  if (empty_expression == NULL) RAISE(213)
  *empty_expression = (EmptyExpression){EmptyExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false};
  empty_expression->_base._base._dtl = EmptyExpression__dtl;
  CHECK(214, EmptyExpression_init(empty_expression) )
  (*expression) = &(empty_expression->_base);
  free(text);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EmptyExpression_init(EmptyExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EmptyExpression_init = "EmptyExpression.init";
#define LUMI_FUNC_NAME _func_name_EmptyExpression_init
Returncode EmptyExpression_init(EmptyExpression* self) {
  CHECK(219, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(220, Expression_set_simple_type(&(self->_base), glob->type_empty) )
  self->_base.access = ACCESS_OWNER;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EmptyExpression_write(EmptyExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EmptyExpression_write = "EmptyExpression.write";
#define LUMI_FUNC_NAME _func_name_EmptyExpression_write
Returncode EmptyExpression_write(EmptyExpression* self) {
  CHECK(224, write(&(String){5, 4, "NULL"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EmptyExpression_write_dynamic(EmptyExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EmptyExpression_write_dynamic = "EmptyExpression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_EmptyExpression_write_dynamic
Returncode EmptyExpression_write_dynamic(EmptyExpression* self) {
  CHECK(227, (self)->_base._base._dtl[4](self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EmptyExpression_write_refman(EmptyExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EmptyExpression_write_refman = "EmptyExpression.write-refman";
#define LUMI_FUNC_NAME _func_name_EmptyExpression_write_refman
Returncode EmptyExpression_write_refman(EmptyExpression* self) {
  CHECK(230, (self)->_base._base._dtl[4](self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func EmptyExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func EmptyExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)EmptyExpression_write, (void*)EmptyExpression_write_dynamic, (void*)EmptyExpression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#include "tl4-compiler.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
