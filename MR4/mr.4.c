#include "mr.4.h"

/*traceback*/
#define MR_FILE_NAME __FILE__
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
#define CRAISE USER_RAISE(__LINE__, NULL, NULL)
#define CCHECK(err) CHECK(__LINE__, err)
#define CHECK_NOT_NULL(ref) \
  if (ref == NULL || ref##_Refman->value == NULL) CRAISE

char* MR_raise_format = "Error raised in %s:%d %s()\n";
char* MR_assert_format = "Assert failed in %s:%d %s()\n";
char* MR_traceline_format = "  called from %s:%d %s()\n";
FILE* MR_trace_stream = NULL;
int MR_trace_ignore_count = 0;
char* MR_expected_error = NULL;
int MR_expected_error_trace_ignore_count = 0;
Generic_Type_Dynamic* dynamic_Void = NULL;

void MR_trace_print(
    char const* format,
    char const* filename,
    int line,
    char const* funcname,
    String* message,
    Ref_Manager* message_refman) {
  if (MR_trace_ignore_count == 0) {
    if (message != NULL && message_refman->value != NULL) {
      fprintf(
          MR_trace_stream, "Error: %.*s\n  ", message->length, message->values);
    }
    fprintf(MR_trace_stream, format, filename, line, funcname);
  }
  else if (MR_expected_error != NULL &&
      MR_expected_error_trace_ignore_count == MR_trace_ignore_count &&
      format != MR_traceline_format) {
    int n;
    if (message == NULL || message_refman->value == NULL) {
      MR_expected_error = NULL;
      if (MR_trace_ignore_count == 1) {
        fprintf(
            MR_trace_stream,
            "Assert failed: error with no message raised\n  ");
      }
      return;
    }
    for (n = 0; n <= message->length; ++n) {
      if (((n == message->length)? '\0': message->values[n]) !=
          MR_expected_error[n]) {
        MR_expected_error = NULL;
        if (MR_trace_ignore_count == 1) {
          fprintf(
              MR_trace_stream,
              "Assert failed: unexpected error message \"%.*s\"\n  ",
              message->length,
              message->values);
        }
        return;
      }
    }
  }
}

/*like strnlen*/
int cstring_length(char* cstring, int max_length) {
  int length = 0;
  while (cstring[length] != '\0' && length < max_length) {
    ++length;
  }
  return length;
}

/*main*/
Returncode MR_user_main();

int MR_main(int argc, char* argv[]) {
  String* args_strings;
  Array sys_argv;
  Sys sys_Var;
  int arg;
  Returncode err;
  MR_trace_stream = stderr;
  args_strings = malloc(argc * sizeof(String));
  sys_Var.argv_Refman = MR_new_ref(&sys_argv);
  sys_Refman = MR_new_ref(&sys_Var);
  stdout_Refman = MR_new_ref(stdout);
  stdin_Refman = MR_new_ref(stdin);
  stderr_Refman = MR_new_ref(stderr);
  if (args_strings == NULL || sys_Var.argv_Refman == NULL ||
      sys_Refman == NULL || stdout_Refman == NULL || stdin_Refman == NULL ||
      stderr_Refman == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  sys_argv.length = argc;
  sys_argv.values = args_strings;
  sys_Var.argv = &sys_argv;
  sys = &sys_Var;
  for (arg = 0; arg < argc; ++arg) {
    args_strings[arg].values = argv[arg];
    args_strings[arg].length = cstring_length(argv[arg], 1024);
    args_strings[arg].max_length = args_strings[arg].length;
    args_strings[arg].values[args_strings[arg].length] = '\0';
  }
  err = MR_user_main();
  if (err != OK) {
    fprintf(stderr, "  called from executable start\n");
  }
  return err;
}

/*tests*/
int MR_test_main(int argc, char* argv[]) {
  Returncode err;
  MR_trace_stream = stdout;
  printf("Running tests:\n");
  err = MR_user_main();
  if (err == OK) {
    printf("Tests passed\n");
  }
  else {
    printf("Tests failed\n");
    return ERR;
  }
  return OK;
}

Bool MR_run_test(char* test_name, Func test_func) {
  Returncode err;
  printf("testing %s... ", test_name);
  fflush(stdout);
  err = test_func();
  if (err == OK) {
    printf("OK\n");
    return true;
  }
  return false;
}

/*helpers*/
#define MR_FUNC_NAME "set_cstring"
Returncode set_cstring(String* str, Ref_Manager* str_Refman) {
  CHECK_NOT_NULL(str)
  if (str->length >= str->max_length) {
    if (cstring_length(str->values, str->max_length) >= str->max_length) {
      CRAISE
    }
  }
  else if (cstring_length(str->values, str->length + 1) > str->length) {
    str->values[str->length] = '\0';
  }
  return OK;
}
#undef MR_FUNC_NAME

/*reference counting*/
Ref_Manager* MR_new_ref(void* value) {
  Ref_Manager* ref = malloc(sizeof(Ref_Manager));
  if (ref != NULL) {
    ref->count = 1;
    ref->value = value;
    ref->ref = value;
  }
  return ref;
}

void MR_inc_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    ++ref->count;
  }
}

void Mock_delete(Ref);

void dec_ref(Ref_Manager* ref) {
  --ref->count;
  if (ref->count == 0) {
    Mock_delete(ref->ref);
    free(ref);
  }
}

void MR_dec_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    dec_ref(ref);
  }
}

void MR_owner_dec_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    free(ref->value);
    ref->value = NULL;
    dec_ref(ref);
  }
}

/*allocations*/
String* MR_new_string(int length) {
  void* buff;
  String* str;
  buff = malloc(sizeof(String) + length);
  if (buff == NULL) {
    return NULL;
  }
  str = buff;
  str->max_length = length;
  str->length = 0;
  str->values = ((char*)buff) + sizeof(String);
  return str;
}

Array* MR_new_array(int length, int value_size) {
  void* buff;
  Array* array;
  buff = calloc(1, sizeof(Array) + length * value_size);
  if (buff == NULL) {
    return NULL;
  }
  array = buff;
  array->length = length;
  array->values = ((Byte*)buff) + sizeof(Array);
  return array;
}

Array* MR_new_string_array(int array_length, int string_length) {
  void* buff;
  Array* array;
  int n;
  buff = MR_new_array(array_length, sizeof(String) + (string_length));
  if (buff == NULL) {
    return NULL;
  }
  array = buff;
  for (n = 0; n < array_length; ++n) {
    String* str;
    str = ((String*)(array->values)) + n;
    str->max_length = string_length;
    str->length = 0;
    str->values = ((char*)(array->values)) + array_length * sizeof(String) +
      string_length * n;
  }
  return array;
}

void MR_set_var_string_array(
    int array_length,
    int string_length,
    Array* array,
    char* chars) {
  int n;
  for (n = 0; n < array_length; ++n) {
    String* str;
    str = ((String*)(array->values)) + n;
    str->max_length = string_length;
    str->length = 0;
    str->values = chars + n * string_length;
  }
}

/*Files*/
#define MR_FUNC_NAME "open-file"
Returncode open_file(
    File** file, Ref_Manager** file_Refman,
    String* name, Ref_Manager* name_Refman,
    char* mode) {
  CCHECK(set_cstring(name, name_Refman));
  *file = fopen(name->values, mode);
  if (*file == NULL) {
    CRAISE
  }
  *file_Refman = MR_new_ref(*file);
  if (*file == NULL) {
    CRAISE
  }
  return OK;
}
#undef MR_FUNC_NAME

Returncode file_open_read(
    String* name, Ref_Manager* name_Refman,
    File** file, Ref_Manager** file_Refman) {
  return open_file(file, file_Refman, name, name_Refman, "r");
}

Returncode file_open_write(
    String* name, Ref_Manager* name_Refman,
    File** file, Ref_Manager** file_Refman) {
  return open_file(file, file_Refman, name, name_Refman, "w");
}

void File_Del(File* self) {
  fclose(self);
}
Generic_Type_Dynamic File_dynamic = { (Dynamic_Del)File_Del };

#define MR_FUNC_NAME "File.close"
Returncode File_close(File* file, Ref_Manager* file_Refman) {
  CHECK_NOT_NULL(file)
  if (fclose(file) == 0) {
    return OK;
  }
  CRAISE
}
#undef MR_FUNC_NAME

Bool getc_is_eof(int get, char* ch) {
  if (get == EOF) {
    return true;
  }
  else {
    *ch = get;
    return false;
  }
}

#define MR_FUNC_NAME "File.getc"
Returncode File_getc(
    File* file, Ref_Manager* file_Refman, Char* out_char, Bool* is_eof) {
  CHECK_NOT_NULL(file)
  *is_eof = getc_is_eof(getc(file), out_char);
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "File.putc"
Returncode File_putc(File* file, Ref_Manager* file_Refman, Char in_char) {
  int res;
  CHECK_NOT_NULL(file)
  res = putc(in_char, file);
  if (res != in_char) {
    CRAISE
  }
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "File.write"
Returncode File_write(
    File* file, Ref_Manager* file_Refman,
    String* data, Ref_Manager* data_Refman) {
  int n, ch, res;
  CHECK_NOT_NULL(file)
  CHECK_NOT_NULL(data)
  for (n = 0; n < data->length; ++n) {
    ch = data->values[n];
    res = putc(ch, file);
    if (ch != res) {
      CRAISE
    }
  }
  return OK;
}
#undef MR_FUNC_NAME

/*Strings*/
void String_Del(String* self) {}
Generic_Type_Dynamic String_dynamic = { (Dynamic_Del)String_Del };

#define MR_FUNC_NAME "String.clear"
Returncode String_clear(String* self, Ref_Manager* self_Refman) {
  CHECK_NOT_NULL(self)
  self->length = 0;
  return OK;
}
#undef MR_FUNC_NAME

Returncode String_equal(
    String* self, Ref_Manager* self_Refman,
    String* other, Ref_Manager* other_Refman,
    Bool* out_equal) {
  if ((self_Refman != NULL && self_Refman->value == NULL) ||
      (self_Refman != NULL && self_Refman->value == NULL)) {
    *out_equal = false;
    return OK;
  }
  if (self == other) {
    *out_equal = true;
    return OK;
  }
  if (self == NULL || other == NULL) {
    *out_equal = false;
    return OK;
  }
  if (self->length != other->length) {
    *out_equal = false;
    return OK;
  }
  if (strncmp(self->values, other->values, self->length) == 0) {
    *out_equal = true;
    return OK;
  }
  *out_equal = false;
  return OK;
}

#define MR_FUNC_NAME "String.get"
Returncode String_get(
    String* self, Ref_Manager* self_Refman,
    Int index,
    Char* out_char) {
  CHECK_NOT_NULL(self)
  if (index < 0 || index >= self->length) {
    CRAISE
  }
  *out_char = self->values[index];
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.append"
Returncode String_append(String* self, Ref_Manager* self_Refman, Char in_char) {
  CHECK_NOT_NULL(self)
  if (self->length == self->max_length) {
    CRAISE
  }
  self->values[self->length] = in_char;
  ++self->length;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Int.str"
Returncode Int_str(Int value, String* out_str, Ref_Manager* out_str_Refman) {
  Bool is_neg;
  int abs;
  int swap;
  char* next;
  char* last;
  CHECK_NOT_NULL(out_str)
  is_neg = value < 0;
  abs = value;
  if (is_neg) {
    abs = -value;
  }
  swap = 0;
  out_str->length = is_neg;
  do {
    swap *= 10;
    swap += abs % 10;
    abs /= 10;
    if (out_str->max_length <= out_str->length) {
      out_str->length = 0;
      CRAISE
    }
    ++out_str->length;
  } while (abs > 0);
  next = out_str->values;
  if (is_neg) {
    *next = '-';
    ++next;
  }
  last = out_str->values + out_str->length;
  while (next < last) {
    *next = '0' + swap % 10;
    ++next;
    swap /= 10;
  }
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.new"
Returncode String_new(
    String* self, Ref_Manager* self_Refman,
    String* source, Ref_Manager* source_Refman) {
  CHECK_NOT_NULL(self)
  if (source == NULL || source_Refman->value == NULL || self == source) {
    return OK;
  }
  if (source->length > self->max_length) {
    CRAISE
  }
  self->length = source->length;
  memcpy(self->values, source->values, self->length);
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.concat"
Returncode String_concat(
    String* self, Ref_Manager* self_Refman,
    String* ext, Ref_Manager* ext_Refman) {
  CHECK_NOT_NULL(self)
  if (ext == NULL || ext_Refman->value == NULL) {
    return OK;
  }
  if (self->length + ext->length > self->max_length) {
    CRAISE
  }
  memcpy(self->values + self->length, ext->values, ext->length);
  self->length += ext->length;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.concat-int"
Returncode String_concat_int(String* self, Ref_Manager* self_Refman, Int num) {
  String remain;
  String* remain_ref = &remain;
  Ref_Manager remain_Refman = { 1 , NULL };
  remain_Refman.value = remain_ref;
  remain.max_length = self->max_length - self->length;
  remain.length = 0;
  remain.values = self->values + self->length;
  CCHECK(Int_str(num, remain_ref, &remain_Refman));
  self->length += remain.length;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.find"
Returncode String_find(
    String* self, Ref_Manager* self_Refman,
    String* pattern, Ref_Manager* pattern_Refman,
    Int* out_index) {
  int n;
  CHECK_NOT_NULL(self)
  if (pattern == NULL || pattern_Refman->value == NULL) {
    *out_index = 0;
    return OK;
  }
  for (n = 0; n <= self->length - pattern->length; ++n) {
    if (strncmp(self->values + n, pattern->values, pattern->length)
        == 0) {
      *out_index = n;
      return OK;
    }
  }
  *out_index = self->length;
  return OK;
}
#undef MR_FUNC_NAME

Returncode String_has(
    String* self, Ref_Manager* self_Refman, Char ch, Bool* found) {
  int n;
  if (self == NULL || self_Refman->value == NULL) {
    *found = false;
    return OK;
  }
  for (n = 0; n < self->length; ++n) {
    if (self->values[n] == ch) {
      *found = true;
      return OK;
    }
  }
  *found = false;
  return OK;
}

/*system*/
Sys* sys;
Ref_Manager* sys_Refman;
Ref_Manager* stdout_Refman;
Ref_Manager* stdin_Refman;
Ref_Manager* stderr_Refman;

void Sys_Del(Sys* self) {}
Generic_Type_Dynamic Sys_dynamic = { (Dynamic_Del)Sys_Del };

Returncode Sys_print(
    Sys* _, Ref_Manager* __, String* text, Ref_Manager* text_Refman) {
  if (text != NULL && text_Refman->value != NULL) {
    int n, ch, res;
    for (n = 0; n < text->length; ++n) {
      ch = text->values[n];
      res = putchar(ch);
      if (ch != res) {
        return OK;
      }
    }
  }
  return OK;
}

Returncode Sys_println(
    Sys* _, Ref_Manager* __, String* text, Ref_Manager* text_Refman) {
  Sys_print(NULL, NULL, text, text_Refman);
  putchar('\n');
  return OK;
}

Returncode Sys_getchar(Sys* _, Ref_Manager* __, char* out_char, Bool* is_eof) {
  *is_eof = getc_is_eof(getchar(), out_char);
  return OK;
}

#define MR_FUNC_NAME "Sys.getline"
Returncode Sys_getline(
    Sys* _, Ref_Manager* __, String* line, Ref_Manager* line_Refman) {
  int ch;
  CHECK_NOT_NULL(line);
  line->length = 0;
  ch = getchar();
  while (ch != EOF && ch != '\n') {
    if (line->length >= line->max_length) {
      CRAISE
    }
    line->values[line->length] = ch;
    ++line->length;
    ch = getchar();
  }
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Sys.exit"
Returncode Sys_exit(Sys* _, Ref_Manager* __, Int status) {
  exit(status);
  CRAISE
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Sys.system"
Returncode Sys_system(
    Sys* _, Ref_Manager* __,
    String* command, Ref_Manager* command_Refman,
    Int* status) {
  int res;
  CCHECK(set_cstring(command, command_Refman));
  res = system(command->values);
  if (res == -1) {
    CRAISE
  }
  *status = res;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Sys.getenv"
Returncode Sys_getenv(
    Sys* _, Ref_Manager* __,
    String* name, Ref_Manager* name_Refman,
    String* value, Ref_Manager* value_Refman,
    Bool* exists) {
  char* ret;
  CCHECK(set_cstring(name, name_Refman));
  CHECK_NOT_NULL(value)
  ret = getenv(name->values);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->length = cstring_length(ret, value->max_length);
  strncpy(value->values, ret, value->length);
  *exists = true;
  return OK;
}
#undef MR_FUNC_NAME
