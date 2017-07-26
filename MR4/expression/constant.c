#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/constant.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file7_name = "expression/constant.3.mr";
#endif
#define MR_FILE_NAME _mr_file7_name

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
typedef struct Int_expression Int_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Int_expression {
  Text_expression _base;
/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Int_expression_parse_new(Int_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Int_expression_parse_new = "Int-expression.parse-new";
#define MR_FUNC_NAME _func_name_Int_expression_parse_new
Returncode Int_expression_parse_new(Int_expression* self, String* text, Expression** expression) {
  Int_expression* int_expression = malloc(sizeof(Int_expression));
  if (int_expression == NULL) RAISE(38)
  *int_expression = (Int_expression){Int_expression__dtl, NULL, NULL};
  int_expression->_base._base._dtl = Int_expression__dtl;
  CHECK(39, Int_expression_parse(int_expression, text) )
  (*expression) = &(int_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `123` or `-123` or `0b0012` or `0x3d4f` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Int_expression_parse(Int_expression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Int_expression_parse = "Int-expression.parse";
#define MR_FUNC_NAME _func_name_Int_expression_parse
Returncode Int_expression_parse(Int_expression* self, String* text) {
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
      Bool _Bool9;
      CHECK(50, f_is_octal(number, &(_Bool9)) )
      if (!_Bool9) {
        CHECK(51, f_syntax_error(&(String){21, 20, "illegal octal number"}, text) )
      }
    }
    else {
      if ((2) < 0 || (number->length - 2) < 0 || (2) + (number->length - 2) > (number)->length) RAISE(53)
      number = (&(String){number->length - 2, number->length - 2, (number)->values + (2)});
      if (second == 'b' || second == 'B') {
        Bool _Bool10;
        CHECK(55, f_is_binary(number, &(_Bool10)) )
        if (!_Bool10) {
          CHECK(56, f_syntax_error(&(String){22, 21, "illegal binary number"}, text) )
        }
      }
      else {
        if (second == 'x' || second == 'X') {
          Bool _Bool11;
          CHECK(58, f_is_hex(number, &(_Bool11)) )
          if (!_Bool11) {
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
    Bool _Bool12;
    CHECK(62, f_is_decimal(number, &(_Bool12)) )
    if (!_Bool12) {
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
extern Func Int_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Int_expression__dtl[] = {Text_expression_write};
#endif


/* Constant character expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Char_expression Char_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Char_expression {
  Text_expression _base;
/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Char_expression_parse_new(Char_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Char_expression_parse_new = "Char-expression.parse-new";
#define MR_FUNC_NAME _func_name_Char_expression_parse_new
Returncode Char_expression_parse_new(Char_expression* self, String* text, Expression** expression) {
  Char_expression* char_expression = malloc(sizeof(Char_expression));
  if (char_expression == NULL) RAISE(71)
  *char_expression = (Char_expression){Char_expression__dtl, NULL, NULL};
  char_expression->_base._base._dtl = Char_expression__dtl;
  CHECK(72, Char_expression_parse(char_expression, text) )
  (*expression) = &(char_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `'a'` or `'\n'` or `'\xf5'` or `'\270'` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Char_expression_parse(Char_expression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Char_expression_parse = "Char-expression.parse";
#define MR_FUNC_NAME _func_name_Char_expression_parse
Returncode Char_expression_parse(Char_expression* self, String* text) {
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
      Bool _Bool13;
      CHECK(85, String_has(&(String){12, 11, "'\"?\\abfnrtv"}, ((text)->values[2]), &(_Bool13)) )
      if (!_Bool13) {
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
          Bool _Bool14;
          CHECK(92, f_is_hex((&(String){2, 2, (text)->values + (3)}), &(_Bool14)) )
          if (!_Bool14) {
            CHECK(93, f_syntax_error(&(String){27, 26, "illegal character constant"}, text) )
          }
        }
        else {
          if ((2) < 0 || (3) < 0 || (2) + (3) > (text)->length) RAISE(95)
          Bool _Bool15;
          CHECK(95, f_is_octal((&(String){3, 3, (text)->values + (2)}), &(_Bool15)) )
          if (!_Bool15) {
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
extern Func Char_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Char_expression__dtl[] = {Text_expression_write};
#endif


/* Constant string expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct String_expression String_expression;
#elif MR_STAGE == MR_TYPES(2)
struct String_expression {
  Text_expression _base;
/* parsing `"some string"` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode String_expression_parse_new(String_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_String_expression_parse_new = "String-expression.parse-new";
#define MR_FUNC_NAME _func_name_String_expression_parse_new
Returncode String_expression_parse_new(String_expression* self, String* text, Expression** expression) {
  String_expression* string_expression = malloc(sizeof(String_expression));
  if (string_expression == NULL) RAISE(108)
  *string_expression = (String_expression){String_expression__dtl, NULL, NULL};
  string_expression->_base._base._dtl = String_expression__dtl;
  CHECK(109, String_expression_parse(string_expression, text) )
  (*expression) = &(string_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `"some string"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode String_expression_parse(String_expression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_String_expression_parse = "String-expression.parse";
#define MR_FUNC_NAME _func_name_String_expression_parse
Returncode String_expression_parse(String_expression* self, String* text) {
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
extern Func String_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func String_expression__dtl[] = {Text_expression_write};
#endif


/* Constant empty expression `_` */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Empty_expression Empty_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Empty_expression {
  Expression _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Empty_expression_parse_new(Empty_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Empty_expression_parse_new = "Empty-expression.parse-new";
#define MR_FUNC_NAME _func_name_Empty_expression_parse_new
Returncode Empty_expression_parse_new(Empty_expression* self, String* text, Expression** expression) {
  Empty_expression* _Empty_expression16 = malloc(sizeof(Empty_expression));
  if (_Empty_expression16 == NULL) RAISE(123)
  *_Empty_expression16 = (Empty_expression){Empty_expression__dtl, NULL};
  _Empty_expression16->_base._dtl = Empty_expression__dtl;
  (*expression) = &(_Empty_expression16->_base);
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Empty_expression_write(Empty_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Empty_expression_write = "Empty-expression.write";
#define MR_FUNC_NAME _func_name_Empty_expression_write
Returncode Empty_expression_write(Empty_expression* self) {
  CHECK(127, write(&(String){6, 5, "Empty"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Empty_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Empty_expression__dtl[] = {Empty_expression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
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
