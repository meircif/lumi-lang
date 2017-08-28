
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


Int global_int;

Int CONSTANT_INT;

String* global_string;

String* CONSTANT_STRING;

Returncode test_func() {
  sys.print("I am test func");
}

Returncode test_func(Int num, String* text, Int* out_num, String** out_text) {
  out_num = num;
  out_text = text;
}
