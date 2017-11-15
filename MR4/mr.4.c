#include "mr.4.h"

/*traceback*/
#define MR_FILE_NAME __FILE__
#define CRAISE RAISE(__LINE__)
#define CCHECK(err) CHECK(__LINE__, err)

char* MR_raise_format = "Error raised in %s:%d %s()\n";
char* MR_assert_format = "Assert failed in %s:%d %s()\n";
char* MR_traceline_format = "  called from %s:%d %s()\n";
FILE* MR_trace_stream = NULL;

void MR_trace_print(
    char const* format, char const* filename, int line, char const* funcname) {
  if (MR_trace_stream != NULL) {
    fprintf(MR_trace_stream, format, filename, line, funcname);
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
  if (args_strings == NULL) {
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
  MR_trace_stream = stderr;
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
  MR_trace_stream = stdout;
  err = test_func();
  MR_trace_stream = stderr;
  if (err == OK) {
    printf("OK\n");
    return true;
  }
  return false;
}

/*helpers*/
#define MR_FUNC_NAME "set_cstring"
Returncode set_cstring(String* str) {
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
  int array_length, int string_length, Array* array, char* chars) {
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
#define MR_FUNC_NAME "open_file"
Returncode open_file(File** file, String* name, char* mode) {
  CCHECK(set_cstring(name));
  *file = NULL;
  *file = fopen(name->values, mode);
  if (*file == NULL) {
    CRAISE
  }
  return OK;
}
#undef MR_FUNC_NAME

Returncode file_open_read(String* name, File** file) {
  return open_file(file, name, "r");
}

Returncode file_open_write(String* name, File** file) {
  return open_file(file, name, "w");
}

#define MR_FUNC_NAME "File.close"
Returncode File_close(File* file) {
  if (fclose(file) == 0) {
    return OK;
  }
  CRAISE
}
#undef MR_FUNC_NAME

Returncode File_getc(File* file, Char* out_char) {
  *out_char = getc(file);
  return OK;
}

#define MR_FUNC_NAME "File.putc"
Returncode File_putc(File* file, Char in_char) {
  int res;
  res = putc(in_char, file);
  if (res != in_char) {
    CRAISE
  }
  return OK;
}
#undef MR_FUNC_NAME

Returncode File_write(File* file, String* data) {
  fprintf(file, "%.*s", data->length, data->values);
  return OK;
}

/*Strings*/
Returncode String_clear(String* this) {
  this->length = 0;
  return OK;
}

Returncode String_equal(String* this, String* other, Bool* out_equal) {
  if (this == other) {
    *out_equal = true;
    return OK;
  }
  if (this->length != other->length) {
    *out_equal = false;
    return OK;
  }
  if (strncmp(this->values, other->values, this->length) == 0) {
    *out_equal = true;
    return OK;
  }
  *out_equal = false;
  return OK;
}

#define MR_FUNC_NAME "String.get"
Returncode String_get(String* this, Int index, Char* out_char) {
  if (index < 0 || index >= this->length) {
    CRAISE
  }
  *out_char = this->values[index];
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.append"
Returncode String_append(String* this, Char in_char) {
  if (this->length == this->max_length) {
    CRAISE
  }
  this->values[this->length] = in_char;
  ++this->length;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Int.str"
Returncode Int_str(Int value, String* out_str) {
  Bool is_neg;
  int abs;
  int swap;
  char* next;
  char* last;
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
Returncode String_new(String* this, String* source) {
  if (this == source) {
    return OK;
  }
  if (source->length > this->max_length) {
    CRAISE
  }
  this->length = source->length;
  memcpy(this->values, source->values, this->length);
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.concat"
Returncode String_concat(String* this, String* ext) {
  if (this->length + ext->length > this->max_length) {
    CRAISE
  }
  memcpy(this->values + this->length, ext->values, ext->length);
  this->length += ext->length;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "String.concat-int"
Returncode String_concat_int(String* this, Int num) {
  String remain;
  remain.max_length = this->max_length - this->length;
  remain.length = 0;
  remain.values = this->values + this->length;
  CCHECK(Int_str(num, &remain));
  this->length += remain.length;
  return OK;
}
#undef MR_FUNC_NAME

Returncode String_find(String* this, String* pattern, Int* out_index) {
  int n;
  for (n = 0; n <= this->length - pattern->length; ++n) {
    if (strncmp(this->values + n, pattern->values, pattern->length) == 0) {
      *out_index = n;
      return OK;
    }
  }
  *out_index = this->length;
  return OK;
}

Returncode String_has(String* this, Char ch, Bool* found) {
  int n;
  for (n = 0; n < this->length; ++n) {
    if (this->values[n] == ch) {
      *found = true;
      return OK;
    }
  }
  *found = false;
  return OK;
}

/*system*/
Sys* sys;

Returncode Sys_print(Sys* _, String* text) {
  printf("%.*s", text->length, text->values);
  return OK;
}

Returncode Sys_println(Sys* _, String* text) {
  printf("%.*s\n", text->length, text->values);
  return OK;
}

#define MR_FUNC_NAME "Sys.exit"
Returncode Sys_exit(Sys* _, Int status) {
  exit(status);
  CRAISE
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Sys.system"
Returncode Sys_system(Sys* _, String* command, Int* status) {
  int res;
  CCHECK(set_cstring(command));
  res = system(command->values);
  if (res == -1) {
    CRAISE
  }
  *status = res;
  return OK;
}
#undef MR_FUNC_NAME

#define MR_FUNC_NAME "Sys.getenv"
Returncode Sys_getenv(Sys* _, String* name, String* value, Bool* exists) {
  char* ret;
  CCHECK(set_cstring(name));
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
