
struct TestStruct {
  Int num;
  String* text;
};

Returncode TestStruct_set(Int x, String* s) {
  self.num = x;
  self.text = s;
}

Returncode TestStruct_get(Int* x, String** s) {
  x = self.num;
  s = self.text;
}


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

Int global_int;

Int CONSTANT_INT;

String* global_string;

String* CONSTANT_STRING;

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
