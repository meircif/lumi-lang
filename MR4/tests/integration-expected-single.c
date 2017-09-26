#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
};


/* types methods declaration */

Returncode TestStruct_set(TestStruct* self, Int x, String* s);

Returncode TestStruct_get(TestStruct* self, Int* x, String** s);


/* types global variables */


/* global variables */

Int global_int;

Int CONSTANT_INT;

String* global_string;

String* CONSTANT_STRING;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);


/* types methods body */

Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  self.num = x;
  self.text = s;
}

Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  x = self.num;
  s = self.text;
}


/* global functions body */

Returncode test_simple_function(void) {
  sys.print("I am test func");
}

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  out_num = num;
  out_text = text;
}


/* main function */

USER_MAIN_HEADER {
  test_simple_function();
}
MAIN_FUNC
