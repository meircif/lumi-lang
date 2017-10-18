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

String* global_string;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);


/* types methods body */

Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  self.num = x;
  self.text = s;
  return OK;
}

Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  x = self.num;
  s = self.text;
  return OK;
}


/* global functions body */

Returncode test_simple_function(void) {
  return OK;
}

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  out_num = num;
  out_text = text;
  return OK;
}


/* main function */

USER_MAIN_HEADER {
  return OK;
}
MAIN_FUNC
