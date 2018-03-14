static char* _mr_file1_name = "common.2.lm";
#define LUMI_FILE_NAME _mr_file1_name
/* TL3 compiler - common stuff */


Sys* sys;

typedef void Object;


static char* _func_name_f_new_copy = "f-new-copy";
#define LUMI_FUNC_NAME _func_name_f_new_copy
Returncode f_new_copy(String* text, String** out_text) {
  if (!(NULL != text)) {
    (*out_text) = NULL;
    return OK;
  }
  String* new_text = new_string(text->length + 1);
  if (new_text == NULL) RAISE(13)
  CHECK(14, String_copy(new_text, text));
  (*out_text) = new_text;
  return OK;
}
#undef LUMI_FUNC_NAME

/* raising */
static char* _func_name_f_msg_raise = "f-msg-raise";
#define LUMI_FUNC_NAME _func_name_f_msg_raise
Returncode f_msg_raise(String* text, String* item) {
  String* msg = &(String){256, 0, (char[256]){0}};
  CHECK(20, String_copy(msg, text));
  CHECK(21, String_concat(msg, &(String){3, 2, " \""}));
  CHECK(22, String_concat(msg, item));
  CHECK(23, String_append(msg, '\"'));
  CHECK(24, Sys_print(sys, msg));
  RAISE(25)
}
#undef LUMI_FUNC_NAME

static char* _func_name_f_raise_on_null = "f-raise-on-null";
#define LUMI_FUNC_NAME _func_name_f_raise_on_null
Returncode f_raise_on_null(Object* obj, String* text, String* item) {
  if (!(NULL != obj)) {
    CHECK(29, f_msg_raise(text, item));
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#undef LUMI_FILE_NAME
