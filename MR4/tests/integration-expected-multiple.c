#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;


typedef struct TopType TopType;


typedef struct BaseType BaseType;


typedef struct MiddleType MiddleType;



/* types struct */

struct TestStruct {
  Int num;
  String* text;
};

struct TopType {
  BaseType* top_base_ref;
  MiddleType* top_mid_ref;
};

struct BaseType {
  MiddleType* base_mid_ref;
  TopType* base_top_ref;
};

struct MiddleType {
  BaseType* mid_base_ref;
  TopType* mid_top_ref;
};


/* types methods declaration */


Returncode TestStruct_set(Int x, String* s);

Returncode TestStruct_get(Int* x, String** s);









/* types DTL */










/* global variables */

Int global_int;

Int CONSTANT_INT;

String* global_string;

String* CONSTANT_STRING;


/* functions declaration */

Returncode test_simple_function();

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);




/* types methods body */


Returncode TestStruct_set(Int x, String* s) {
  self.num = x;
  self.text = s;
}

Returncode TestStruct_get(Int* x, String** s) {
  x = self.num;
  s = self.text;
}









/* global functions body */

Returncode test_simple_function() {
  sys.print("I am test func");
}

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  out_num = num;
  out_text = text;
}

USER_MAIN_HEADER {
  test_simple_function();
}
MAIN_FUNC
