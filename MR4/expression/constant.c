#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/constant.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file8_name = "expression/constant.3.mr";
#endif
#define MR_FILE_NAME _mr_file8_name

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


/* Constant integer expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct IntExpression IntExpression;
#elif MR_STAGE == MR_TYPES(2)
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
  if (int_expression == NULL) RAISE(38)
  *int_expression = (IntExpression){IntExpression__dtl, NULL, NULL};
  int_expression->_base._base._dtl = IntExpression__dtl;
  CHECK(39, IntExpression_parse(int_expression, text) )
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
  String* number = text;
  if ((0) < 0 || (0) >= (number)->length) RAISE(45)
  if (((number)->values[0]) == '-') {
    if ((1) < 0 || (number->length - 1) < 0 || (1) + (number->length - 1) > (number)->length) RAISE(46)
    number = (&(String){number->length - 1, number->length - 1, (number)->values + (1)});
  }
  if ((0) < 0 || (0) >= (number)->length) RAISE(47)
  if (((number)->values[0]) == '0' && number->length > 1) {
    if ((1) < 0 || (1) >= (number)->length) RAISE(48)
    Char second = ((number)->values[1]);
    if (second >= '0' && second <= '7') {
      Bool _Bool13;
      CHECK(50, f_is_octal(number, &(_Bool13)) )
      if (!_Bool13) {
        CHECK(51, f_syntax_error(&(String){21, 20, "illegal octal number"}, text) )
      }
    }
    else {
      if ((2) < 0 || (number->length - 2) < 0 || (2) + (number->length - 2) > (number)->length) RAISE(53)
      number = (&(String){number->length - 2, number->length - 2, (number)->values + (2)});
      if (second == 'b' || second == 'B') {
        Bool _Bool14;
        CHECK(55, f_is_binary(number, &(_Bool14)) )
        if (!_Bool14) {
          CHECK(56, f_syntax_error(&(String){22, 21, "illegal binary number"}, text) )
        }
      }
      else {
        if (second == 'x' || second == 'X') {
          Bool _Bool15;
          CHECK(58, f_is_hex(number, &(_Bool15)) )
          if (!_Bool15) {
            CHECK(59, f_syntax_error(&(String){27, 26, "illegal hexadecimal number"}, text) )
          }
        }
        else {
          CHECK(61, f_syntax_error(&(String){15, 14, "illegal number"}, text) )
        }
      }
    }
  }
  else {
    Bool _Bool16;
    CHECK(62, f_is_decimal(number, &(_Bool16)) )
    if (!_Bool16) {
      CHECK(63, f_syntax_error(&(String){15, 14, "illegal number"}, text) )
    }
  }
  CHECK(64, Expression_set_simple_type(&(self->_base._base), glob->type_int) )
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func IntExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func IntExpression__dtl[] = {(void*)TextExpression_write};
#endif


/* Constant character expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct CharExpression CharExpression;
#elif MR_STAGE == MR_TYPES(2)
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
  if (char_expression == NULL) RAISE(71)
  *char_expression = (CharExpression){CharExpression__dtl, NULL, NULL};
  char_expression->_base._base._dtl = CharExpression__dtl;
  CHECK(72, CharExpression_parse(char_expression, text) )
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
  Char ch = '\0';
  if (text->length == 3) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(79)
    ch = ((text)->values[1]);
    if (ch == '\'' || ch == '\\') {
      CHECK(81, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
    }
  }
  else {
    if (text->length == 4) {
      if ((1) < 0 || (1) >= (text)->length) RAISE(83)
      if (((text)->values[1]) != '\\') {
        CHECK(84, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
      }
      if ((2) < 0 || (2) >= (text)->length) RAISE(85)
      Bool _Bool17;
      CHECK(85, String_has(&(String){12, 11, "'\"?\\abfnrtv"}, ((text)->values[2]), &(_Bool17)) )
      if (!_Bool17) {
        CHECK(86, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
      }
    }
    else {
      if (text->length == 6) {
        if ((1) < 0 || (1) >= (text)->length) RAISE(88)
        if (((text)->values[1]) != '\\') {
          CHECK(89, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
        }
        if ((2) < 0 || (2) >= (text)->length) RAISE(90)
        ch = ((text)->values[2]);
        if (ch == 'x') {
          if ((3) < 0 || (2) < 0 || (3) + (2) > (text)->length) RAISE(92)
          Bool _Bool18;
          CHECK(92, f_is_hex((&(String){2, 2, (text)->values + (3)}), &(_Bool18)) )
          if (!_Bool18) {
            CHECK(93, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
          }
        }
        else {
          if ((2) < 0 || (3) < 0 || (2) + (3) > (text)->length) RAISE(95)
          Bool _Bool19;
          CHECK(95, f_is_octal((&(String){3, 3, (text)->values + (2)}), &(_Bool19)) )
          if (!_Bool19) {
            CHECK(96, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
          }
        }
      }
      else {
        CHECK(98, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
      }
    }
  }
  if ((text->length - 1) < 0 || (text->length - 1) >= (text)->length) RAISE(99)
  if (((text)->values[text->length - 1]) != '\'') {
    CHECK(100, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
  }
  CHECK(101, Expression_set_simple_type(&(self->_base._base), glob->type_char) )
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CharExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CharExpression__dtl[] = {(void*)TextExpression_write};
#endif


/* Constant string expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct StringExpression StringExpression;
#elif MR_STAGE == MR_TYPES(2)
struct StringExpression {
  TextExpression _base;
/* parsing `"some string"` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_parse_new(StringExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_parse_new = "StringExpression.parse-new";
#define MR_FUNC_NAME _func_name_StringExpression_parse_new
Returncode StringExpression_parse_new(StringExpression* self, String* text, Expression** expression) {
  StringExpression* string_expression = malloc(sizeof(StringExpression));
  if (string_expression == NULL) RAISE(108)
  *string_expression = (StringExpression){StringExpression__dtl, NULL, NULL};
  string_expression->_base._base._dtl = StringExpression__dtl;
  CHECK(109, StringExpression_parse(string_expression, text) )
  (*expression) = &(string_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `"some string"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode StringExpression_parse(StringExpression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_StringExpression_parse = "StringExpression.parse";
#define MR_FUNC_NAME _func_name_StringExpression_parse
Returncode StringExpression_parse(StringExpression* self, String* text) {
  if ((text->length - 1) < 0 || (text->length - 1) >= (text)->length) RAISE(114)
  if (((text)->values[text->length - 1]) != '\"') {
    CHECK(115, f_syntax_error(&(String){24, 23, "illegal string constant"}, text) )
  }
  CHECK(116, Expression_set_simple_type(&(self->_base._base), glob->type_string) )
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func StringExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func StringExpression__dtl[] = {(void*)TextExpression_write};
#endif


/* Constant empty expression `_` */
#if MR_STAGE == MR_TYPEDEFS
typedef struct EmptyExpression EmptyExpression;
#elif MR_STAGE == MR_TYPES(1)
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
  EmptyExpression* _EmptyExpression20 = malloc(sizeof(EmptyExpression));
  if (_EmptyExpression20 == NULL) RAISE(123)
  *_EmptyExpression20 = (EmptyExpression){EmptyExpression__dtl, NULL};
  _EmptyExpression20->_base._dtl = EmptyExpression__dtl;
  (*expression) = &(_EmptyExpression20->_base);
  free(text);
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
  CHECK(127, write(&(String){6, 5, "Empty"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func EmptyExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func EmptyExpression__dtl[] = {(void*)EmptyExpression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/function.c"
#include "syntax-tree/loop.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/variable.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
