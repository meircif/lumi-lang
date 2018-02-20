#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/constant.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file10_name = "expression/constant.3.mr";
#endif
#define MR_FILE_NAME _mr_file10_name

/* MR4 compiler - Constant expressions */

/* Return whether `text` is a number of base with given `top-digit` */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_number(String* text, Char top_digit, Bool* is_number);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_number = "f-is-number";
#define MR_FUNC_NAME _func_name_f_is_number
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
#undef MR_FUNC_NAME
#endif

/* Return whether `text` is a binary number */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_binary(String* text, Bool* is_octal);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_binary = "f-is-binary";
#define MR_FUNC_NAME _func_name_f_is_binary
Returncode f_is_binary(String* text, Bool* is_octal) {
  CHECK(14, f_is_number(text, '1', &((*is_octal))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

/* Return whether `text` is an octal number */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_octal(String* text, Bool* is_octal);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_octal = "f-is-octal";
#define MR_FUNC_NAME _func_name_f_is_octal
Returncode f_is_octal(String* text, Bool* is_octal) {
  CHECK(18, f_is_number(text, '7', &((*is_octal))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

/* Return whether `text` is a decimal number */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_decimal(String* text, Bool* is_octal);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_decimal = "f-is-decimal";
#define MR_FUNC_NAME _func_name_f_is_decimal
Returncode f_is_decimal(String* text, Bool* is_octal) {
  CHECK(22, f_is_number(text, '9', &((*is_octal))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

/* Return whether `text` is a hexadecimal number */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_hex(String* text, Bool* is_hex);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_hex = "f-is-hex";
#define MR_FUNC_NAME _func_name_f_is_hex
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
#undef MR_FUNC_NAME
#endif


/* A basic expression that has a single textual value */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TextExpression TextExpression;
#elif MR_STAGE == MR_TYPES(2)
struct TextExpression {
  Expression _base;
  String* text;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TextExpression_write(TextExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TextExpression_write = "TextExpression.write";
#define MR_FUNC_NAME _func_name_TextExpression_write
Returncode TextExpression_write(TextExpression* self) {
  CHECK(40, write(self->text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TextExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TextExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
#endif


/* Constant integer expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct IntExpression IntExpression;
#elif MR_STAGE == MR_TYPES(3)
struct IntExpression {
  TextExpression _base;
/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode IntExpression_parse_new(IntExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_IntExpression_parse_new = "IntExpression.parse-new";
#define MR_FUNC_NAME _func_name_IntExpression_parse_new
Returncode IntExpression_parse_new(IntExpression* self, String* text, Expression** expression) {
  IntExpression* int_expression = malloc(sizeof(IntExpression));
  if (int_expression == NULL) RAISE(46)
  *int_expression = (IntExpression){IntExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, NULL};
  int_expression->_base._base._base._dtl = IntExpression__dtl;
  CHECK(47, IntExpression_parse(int_expression, text) )
  (*expression) = &(int_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */
#if MR_STAGE == MR_DECLARATIONS
Returncode IntExpression_parse(IntExpression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_IntExpression_parse = "IntExpression.parse";
#define MR_FUNC_NAME _func_name_IntExpression_parse
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
      Bool _Bool28;
      CHECK(59, f_is_octal(number, &(_Bool28)) )
      if (!_Bool28) {
        CHECK(60, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){21, 20, "illegal octal number"}, text) )
      }
    }
    else {
      if ((2) < 0 || (number->length - 2) < 0 || (2) + (number->length - 2) > (number)->length) RAISE(62)
      number = (&(String){number->length - 2, number->length - 2, (number)->values + (2)});
      if (second == 'b' || second == 'B') {
        Bool _Bool29;
        CHECK(64, f_is_binary(number, &(_Bool29)) )
        if (!_Bool29) {
          CHECK(65, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal binary number"}, text) )
        }
        CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){36, 35, "binary numbers not supported yet..."}, text) )
      }
      else {
        if (second == 'x' || second == 'X') {
          Bool _Bool30;
          CHECK(69, f_is_hex(number, &(_Bool30)) )
          if (!_Bool30) {
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
    Bool _Bool31;
    CHECK(73, f_is_decimal(number, &(_Bool31)) )
    if (!_Bool31) {
      CHECK(74, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){15, 14, "illegal number"}, text) )
    }
  }
  CHECK(75, Expression_set_simple_type(&(self->_base._base), &(glob->type_int->_base)) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func IntExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func IntExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
#endif


/* Constant character expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct CharExpression CharExpression;
#elif MR_STAGE == MR_TYPES(3)
struct CharExpression {
  TextExpression _base;
/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CharExpression_parse_new(CharExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CharExpression_parse_new = "CharExpression.parse-new";
#define MR_FUNC_NAME _func_name_CharExpression_parse_new
Returncode CharExpression_parse_new(CharExpression* self, String* text, Expression** expression) {
  CharExpression* char_expression = malloc(sizeof(CharExpression));
  if (char_expression == NULL) RAISE(83)
  *char_expression = (CharExpression){CharExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, NULL};
  char_expression->_base._base._base._dtl = CharExpression__dtl;
  CHECK(84, CharExpression_parse(char_expression, text) )
  (*expression) = &(char_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */
#if MR_STAGE == MR_DECLARATIONS
Returncode CharExpression_parse(CharExpression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CharExpression_parse = "CharExpression.parse";
#define MR_FUNC_NAME _func_name_CharExpression_parse
Returncode CharExpression_parse(CharExpression* self, String* text) {
  CHECK(89, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  Char ch = '\0';
  if (text->length == 3) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(92)
    ch = ((text)->values[1]);
    if (ch == '\'' || ch == '\\') {
      CHECK(94, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
    }
  }
  else {
    if (text->length == 4) {
      if ((1) < 0 || (1) >= (text)->length) RAISE(96)
      if (((text)->values[1]) != '\\') {
        CHECK(97, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
      if ((2) < 0 || (2) >= (text)->length) RAISE(98)
      Bool _Bool32;
      CHECK(98, String_has(&(String){12, 11, "'\"?\\abfnrtv"}, ((text)->values[2]), &(_Bool32)) )
      if (!_Bool32) {
        CHECK(99, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
    }
    else {
      if (text->length == 6) {
        if ((1) < 0 || (1) >= (text)->length) RAISE(101)
        if (((text)->values[1]) != '\\') {
          CHECK(102, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
        }
        if ((2) < 0 || (2) >= (text)->length) RAISE(103)
        ch = ((text)->values[2]);
        if (ch == 'x') {
          if ((3) < 0 || (2) < 0 || (3) + (2) > (text)->length) RAISE(105)
          Bool _Bool33;
          CHECK(105, f_is_hex((&(String){2, 2, (text)->values + (3)}), &(_Bool33)) )
          if (!_Bool33) {
            CHECK(106, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
          }
        }
        else {
          if ((2) < 0 || (3) < 0 || (2) + (3) > (text)->length) RAISE(108)
          Bool _Bool34;
          CHECK(108, f_is_octal((&(String){3, 3, (text)->values + (2)}), &(_Bool34)) )
          if (!_Bool34) {
            CHECK(109, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
          }
        }
      }
      else {
        CHECK(111, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
      }
    }
  }
  if ((text->length - 1) < 0 || (text->length - 1) >= (text)->length) RAISE(112)
  if (((text)->values[text->length - 1]) != '\'') {
    CHECK(113, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){27, 26, "illegal character constant"}, text) )
  }
  CHECK(114, Expression_set_simple_type(&(self->_base._base), &(glob->type_char->_base)) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CharExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CharExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)TextExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
#endif


/* Constant string expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct StringExpression StringExpression;
#elif MR_STAGE == MR_TYPES(3)
struct StringExpression {
  TextExpression _base;
  SymbolExpression* symbol;
/* parsing `"some string"` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_parse_new(StringExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_parse_new = "StringExpression.parse-new";
#define MR_FUNC_NAME _func_name_StringExpression_parse_new
Returncode StringExpression_parse_new(StringExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  StringExpression* string_expression = malloc(sizeof(StringExpression));
  if (string_expression == NULL) RAISE(125)
  *string_expression = (StringExpression){StringExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, NULL, NULL};
  string_expression->_base._base._base._dtl = StringExpression__dtl;
  CHECK(126, StringExpression_parse(string_expression, text, code_node) )
  (*expression) = &(string_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `"some string"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_parse(StringExpression* self, String* text, SyntaxTreeCode* code_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_parse = "StringExpression.parse";
#define MR_FUNC_NAME _func_name_StringExpression_parse
Returncode StringExpression_parse(StringExpression* self, String* text, SyntaxTreeCode* code_node) {
  self->_base._base.code_node = code_node;
  CHECK(132, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(133, SyntaxTreeNode_check_string(&(self->_base._base._base), text) )
  CHECK(134, Expression_set_simple_type(&(self->_base._base), &(glob->type_string->_base)) )
  self->_base._base.access = ACCESS_VAR;
  self->_base.text = text;
  CHECK(137, StringExpression_m_strip_multilines(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_m_strip_multilines(StringExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_m_strip_multilines = "StringExpression.m-strip-multilines";
#define MR_FUNC_NAME _func_name_StringExpression_m_strip_multilines
Returncode StringExpression_m_strip_multilines(StringExpression* self) {
  Int index_write = 1;
  {int index_read; for (index_read = (1); index_read < (self->_base.text->length - 1); ++index_read) {
    if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(142)
    if (((self->_base.text)->values[index_read]) == '\n') {
      Bool skip_new_line = false;
      if (index_read > 0) {
        if ((index_read - 1) < 0 || (index_read - 1) >= (self->_base.text)->length) RAISE(145)
        skip_new_line = ((self->_base.text)->values[index_read - 1]) == '\\';
      }
      Int expected = self->_base._base.code_node->parent->_base.indentation_spaces + 4;
      Int indentation = 0;
      while (true) {
        index_read += 1;
        if (!(index_read < self->_base.text->length - 1)) break;
        if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(151)
        if (!(((self->_base.text)->values[index_read]) == ' ')) break;
        indentation += 1;
        if (!(indentation < expected)) break;
      }
      if (indentation < expected) {
        CHECK(155, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base._base.code_node->_base), indentation, expected) )
      }
      if (skip_new_line) {
        index_write -= 1;
      }
      else {
        if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(160)
        ((self->_base.text)->values[index_write]) = '\\';
        index_write += 1;
        if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(162)
        ((self->_base.text)->values[index_write]) = 'n';
        index_write += 1;
      }
    }
    else {
      if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(165)
      if ((index_read) < 0 || (index_read) >= (self->_base.text)->length) RAISE(165)
      ((self->_base.text)->values[index_write]) = ((self->_base.text)->values[index_read]);
      index_write += 1;
    }
  }}
  if (index_write < self->_base.text->length - 1) {
    if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(168)
    ((self->_base.text)->values[index_write]) = '"';
    index_write += 1;
    if ((index_write) < 0 || (index_write) >= (self->_base.text)->length) RAISE(170)
    ((self->_base.text)->values[index_write]) = '\0';
    self->_base.text->length = index_write;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_analyze(StringExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_analyze = "StringExpression.analyze";
#define MR_FUNC_NAME _func_name_StringExpression_analyze
Returncode StringExpression_analyze(StringExpression* self) {
  CHECK(174, Expression_add_aux_variable(&(self->_base._base), ACCESS_VAR, false, self->_base._base.result_type, &(self->symbol)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_write_preactions(StringExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_write_preactions = "StringExpression.write-preactions";
#define MR_FUNC_NAME _func_name_StringExpression_write_preactions
Returncode StringExpression_write_preactions(StringExpression* self) {
  /* `symbol`_Var.max_length = `string-length + 1`; */
  /* `symbol`_Var.length = `string-length`; */
  /* `symbol`_Var.values = "`text`"; */
  CHECK(181, Expression_write_init_var_ref(&(self->_base._base), self->symbol) )
  CHECK(182, Expression_write_refman_init(&(self->_base._base), self->symbol) )
  Int real_length = 1;
  {int index; for (index = (1); index < (self->_base.text->length - 1); ++index) {
    if ((index) < 0 || (index) >= (self->_base.text)->length) RAISE(185)
    if (((self->_base.text)->values[index]) == '\\') {
      index += 1;
    }
    real_length = real_length + 1;
  }}
  CHECK(188, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(189, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(190, write(&(String){19, 18, "_Var.max_length = "}) )
  CHECK(191, write_int(real_length) )
  CHECK(192, write(&(String){3, 2, ";\n"}) )
  CHECK(193, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(194, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(195, write(&(String){15, 14, "_Var.length = "}) )
  CHECK(196, write_int(real_length - 1) )
  CHECK(197, write(&(String){3, 2, ";\n"}) )
  CHECK(198, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(199, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(200, write(&(String){15, 14, "_Var.values = "}) )
  CHECK(201, write(self->_base.text) )
  CHECK(202, write(&(String){3, 2, ";\n"}) )
  CHECK(203, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_write(StringExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_write = "StringExpression.write";
#define MR_FUNC_NAME _func_name_StringExpression_write
Returncode StringExpression_write(StringExpression* self) {
  CHECK(206, (self->symbol)->_base._base._dtl[3](self->symbol) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func StringExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func StringExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)StringExpression_analyze, (void*)StringExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)StringExpression_write_preactions};
#endif


/* Constant empty expression `_` */
#if MR_STAGE == MR_TYPEDEFS
typedef struct EmptyExpression EmptyExpression;
#elif MR_STAGE == MR_TYPES(2)
struct EmptyExpression {
  Expression _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EmptyExpression_parse_new(EmptyExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EmptyExpression_parse_new = "EmptyExpression.parse-new";
#define MR_FUNC_NAME _func_name_EmptyExpression_parse_new
Returncode EmptyExpression_parse_new(EmptyExpression* self, String* text, Expression** expression) {
  EmptyExpression* empty_expression = malloc(sizeof(EmptyExpression));
  if (empty_expression == NULL) RAISE(212)
  *empty_expression = (EmptyExpression){EmptyExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false};
  empty_expression->_base._base._dtl = EmptyExpression__dtl;
  CHECK(213, EmptyExpression_init(empty_expression) )
  (*expression) = &(empty_expression->_base);
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EmptyExpression_init(EmptyExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EmptyExpression_init = "EmptyExpression.init";
#define MR_FUNC_NAME _func_name_EmptyExpression_init
Returncode EmptyExpression_init(EmptyExpression* self) {
  CHECK(218, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(219, Expression_set_simple_type(&(self->_base), &(glob->type_empty->_base)) )
  self->_base.access = ACCESS_OWNER;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EmptyExpression_write(EmptyExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EmptyExpression_write = "EmptyExpression.write";
#define MR_FUNC_NAME _func_name_EmptyExpression_write
Returncode EmptyExpression_write(EmptyExpression* self) {
  CHECK(223, write(&(String){5, 4, "NULL"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EmptyExpression_write_dynamic(EmptyExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EmptyExpression_write_dynamic = "EmptyExpression.write-dynamic";
#define MR_FUNC_NAME _func_name_EmptyExpression_write_dynamic
Returncode EmptyExpression_write_dynamic(EmptyExpression* self) {
  CHECK(226, (self)->_base._base._dtl[3](self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode EmptyExpression_write_refman(EmptyExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_EmptyExpression_write_refman = "EmptyExpression.write-refman";
#define MR_FUNC_NAME _func_name_EmptyExpression_write_refman
Returncode EmptyExpression_write_refman(EmptyExpression* self) {
  CHECK(229, (self)->_base._base._dtl[3](self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func EmptyExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func EmptyExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)EmptyExpression_write, (void*)EmptyExpression_write_dynamic, (void*)EmptyExpression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#include "mr4-compiler.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
