#include "mr.3.h"

/*traceback*/
#define MR_FILE_NAME __FILE__
#define MR_FUNC_NAME __FUNCTION__
#define CRAISE RAISE(__LINE__)
#define CCHECK(err) CHECK(__LINE__, err)

char* _mr_raise_format = "Error raised in %s:%d %s()\n";
char* _mr_assert_format = "Assert failed in %s:%d %s()\n";
char* _mr_traceline_format = "  called from %s:%d %s()\n";
FILE* _trace_stream = NULL;

void _trace_print(
    char const* format,
    char const* filename,
    int line,
    char const* funcname) {
  if (_trace_stream != NULL) {
    fprintf(_trace_stream, format, filename, line, funcname);
  }
}

/*main*/
Returncode func(Array*);

int _mr_main(int argc, char* argv[]) {
  _trace_stream = stderr;
  String* args_strings = malloc(argc * sizeof(String));
  if (args_strings == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  Array* args_array = &(Array){argc, args_strings};
  int arg;
  for (arg = 0; arg < argc; ++arg) {
    args_strings[arg].values = argv[arg];
    args_strings[arg].length = strnlen(args_strings[arg].values, 1024);
    args_strings[arg].max_length = args_strings[arg].length + 1;
  }
  Returncode err = func(args_array);
  if (err != OK) {
    fprintf(stderr, "  called from executable start\n");
  }
  return err;
}

/*tests*/
int _mr_test_main(int argc, char* argv[]) {
  _trace_stream = stderr;
  printf("Running tests:\n");
  Returncode err = func(NULL);
  if (err == OK) {
    printf("Tests passed\n");
  }
  else {
    printf("Tests failed\n");
  }
}

Bool _run_test(char* test_name, Func test_func) {
  printf("testing %s... ", test_name);
  fflush(stdout);
  _trace_stream = stdout;
  Returncode err = test_func();
  _trace_stream = stderr;
  if (err == OK) {
    printf("OK\n");
    return true;
  }
  return false;
}

/*helpers*/
Returncode _set_cstring(String* str) {
  if (str->length >= str->max_length) {
    if (strnlen(str->values, str->max_length) >= str->max_length) {
      CRAISE
    }
  }
  else if (strnlen(str->values, str->length + 1) > str->length) {
    str->values[str->length] = '\0';
  }
  return OK;
}

/*allocations*/
String* _new_string(int length) {
  void* buff = malloc(sizeof(String) + length);
  if (buff == NULL) {
    return NULL;
  }
  String* str = buff;
  str->max_length = length;
  str->length = 0;
  str->values = (Byte*)buff + sizeof(String);
  return str;
}

Array* _new_array(int length, int value_size) {
  void* buff = calloc(1, sizeof(Array) + length * value_size);
  if (buff == NULL) {
    return NULL;
  }
  Array* arr = buff;
  arr->length = length;
  arr->values = (Byte*)buff + sizeof(Array);
  return arr;
}

void _set_var_string_array(
    int array_length,
    int string_length,
    Array* array,
    char* chars) {
  int n;
  for (n = 0; n < array_length; ++n) {
    ((String*)(array->values))[n] =
      (String){string_length, 0, chars + n * string_length};
  }
}

void _set_new_string_array(int array_length, int string_length, Array* array) {
  int n;
  for (n = 0; n < array_length; ++n) {
    ((String*)(array->values))[n] = (String){
      string_length,
      0,
      (Byte*)(array->values) + array_length * sizeof(String) + string_length * n
    };
  }
}

/*Files*/
Returncode _open_file(File** file, String* name, char* mode) {
  CCHECK(_set_cstring(name));
  *file = NULL;
  *file = fopen(name->values, mode);
  if (*file == NULL) {
    CRAISE
  }
  return OK;
}

Returncode file_open_read(String* name, File** file) {
  return _open_file(file, name, "r");
}

Returncode file_open_write(String* name, File** file) {
  return _open_file(file, name, "w");
}

Returncode File_close(File* file) {
  if (fclose(file) == 0) {
    return OK;
  }
  CRAISE
}

Returncode File_getc(File* file, Char* out_char) {
  *out_char = getc(file);
  return OK;
}

Returncode File_putc(File* file, Char in_char) {
  int res = putc(in_char, file);
  if (res != in_char) {
    CRAISE
  }
  return OK;
}

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

Returncode String_get(String* this, Int index, Char* out_char) {
  if (index < 0 || index >= this->length) {
    CRAISE
  }
  *out_char = this->values[index];
  return OK;
}

Returncode String_append(String* this, Char in_char) {
  if (this->length == this->max_length) {
    CRAISE
  }
  this->values[this->length] = in_char;
  ++this->length;
  return OK;
}

Returncode String_replace(String* this, Char old, Char new) {
  if (old == new) {
    return OK;
  }
  int n;
  for (n = 0; n < this->length; ++n) {
    if (this->values[n] == old) {
      this->values[n] = new;
    }
  }
  return OK;
}

Returncode Int_str(Int value, String* out_str) {
  int res = snprintf(out_str->values, out_str->max_length ,"%d", value);
  if (res <= 0 || res >= out_str->max_length) {
    out_str->length = 0;
    CRAISE
  }
  out_str->length = res;
  return OK;
}

Returncode String_copy(String* this, String* source) {
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

Returncode String_concat(String* this, String* ext) {
  if (this->length + ext->length > this->max_length) {
    CRAISE
  }
  memcpy(this->values + this->length, ext->values, ext->length);
  this->length += ext->length;
  return OK;
}

Returncode String_concat_int(String* this, Int num) {
  String remain = {
    this->max_length - this->length,
    0,
    this->values + this->length};
  CCHECK(Int_str(num, &remain));
  this->length += remain.length;
  return OK;
}

Returncode String_find(String* this, String* pattern, Int* out_index) {
  Int n;
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

/*Arrays*/
/*Returncode _array_length(Array* this, Int* out_length) {
  *out_length = this->length;
  return OK;
}*/

/*system*/
Returncode Sys_print(void* _, String* text) {
  printf("%.*s\n", text->length, text->values);
  return OK;
}

Returncode Sys_exit(void* _, Int status) {
  exit(status);
  CRAISE
}

Returncode Sys_system(void* _, String* command, Int* status) {
  CCHECK(_set_cstring(command));
  int res = system(command->values);
  if (res == -1) {
    CRAISE
  }
  *status = res;
  return OK;
}

Returncode Sys_getenv(void* _, String* name, String* value, Bool* exists) {
  CCHECK(_set_cstring(name));
  char* ret = getenv(name->values);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->length = strnlen(ret, value->max_length);
  strncpy(value->values, ret, value->length);
  *exists = true;
  return OK;
}
