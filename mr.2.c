#include "mr.2.h"


/*dynamic allocation*/
String* new_string(int length) {
  void* buff = malloc(sizeof(String) + length);
  if (buff == NULL) {
    return NULL;
  }
  String* str = buff;
  str->max_length = length;
  str->actual_length = 0;
  str->chars = (Byte*)buff + sizeof(String);
  return str;
}

Array* new_array(int length, int value_size) {
  void* buff = malloc(sizeof(Array) + length * value_size);
  if (buff == NULL) {
    return NULL;
  }
  Array* arr = buff;
  arr->length = length;
  arr->values = (Byte*)buff + sizeof(Array);
  return arr;
}

/*Files*/
Returncode open_file(File** file, String* name, char* mode) {
  *file = NULL;
  *file = fopen(name->chars, mode);
  if (*file == NULL) {
    RAISE
  }
  return OK;
}

Returncode file_open_read(String* name, File** file) {
  return open_file(file, name, "r");
}

Returncode file_open_write(String* name, File** file) {
  return open_file(file, name, "w");
}

Returncode File_close(File* file) {
  if (fclose(file) == 0) {
    return OK;
  }
  RAISE
}

Returncode File_getc(File* file, Char* out_char) {
  *out_char = getc(file);
  return OK;
}

Returncode File_putc(File* file, Char in_char) {
  int res = putc(in_char, file);
  if (res != in_char) {
    RAISE
  }
  return OK;
}

Returncode File_write(File* file, String* data) {
  fprintf(file, "%.*s", data->actual_length, data->chars);
  return OK;
}

/*Strings*/
Returncode String_clear(String* this) {
  this->actual_length = 0;
  return OK;
}

Returncode String_length(String* this, Int* out_length) {
  *out_length = this->actual_length;
  return OK;
}

Returncode String_equal(String* this, String* other, Bool* out_equal) {
  if (this == other) {
    *out_equal = true;
    return OK;
  }
  if (this->actual_length != other->actual_length) {
    *out_equal = false;
    return OK;
  }
  if (strncmp(this->chars, other->chars, this->actual_length) == 0) {
    *out_equal = true;
    return OK;
  }
  *out_equal = false;
  return OK;
}

Returncode String_get(String* this, Int index, Char* out_char) {
  if (index < 0 or index >= this->actual_length) {
    RAISE
  }
  *out_char = this->chars[index];
  return OK;
}

Returncode String_append(String* this, Char in_char) {
  if (this->actual_length == this->max_length) {
    RAISE
  }
  this->chars[this->actual_length] = in_char;
  ++this->actual_length;
  return OK;
}

Returncode String_replace(String* this, Char old, Char new) {
  if (old == new) {
    return OK;
  }
  int n;
  for (n = 0; n < this->actual_length; ++n) {
    if (this->chars[n] == old) {
      this->chars[n] = new;
    }
  }
  return OK;
}

Returncode Int_str(Int value, String* out_str) {
  int res = snprintf(out_str->chars, out_str->max_length ,"%d", value);
  if (res <= 0 or res >= out_str->max_length) {
    out_str->actual_length = 0;
    RAISE
  }
  out_str->actual_length = res;
  return OK;
}

Returncode String_copy(String* this, String* source) {
  if (this == source) {
    return OK;
  }
  if (source->actual_length > this->max_length) {
    RAISE
  }
  this->actual_length = source->actual_length;
  memcpy(this->chars, source->chars, this->actual_length);
  return OK;
}

Returncode String_concat(String* this, String* ext) {
  if (this->actual_length + ext->actual_length > this->max_length) {
    RAISE
  }
  memcpy(this->chars + this->actual_length, ext->chars, ext->actual_length);
  this->actual_length += ext->actual_length;
  return OK;
}

Returncode String_find(String* this, String* pattern, Int* out_index) {
  Int n;
  for (n = 0; n <= this->actual_length - pattern->actual_length; ++n) {
    if (strncmp(this->chars + n, pattern->chars, pattern->actual_length) == 0) {
      *out_index = n;
      return OK;
    }
  }
  RAISE
}

Returncode String_has(String* this, Char ch, Bool* found) {
  int n;
  for (n = 0; n < this->actual_length; ++n) {
    if (this->chars[n] == ch) {
      *found = true;
      return OK;
    }
  }
  *found = false;
  return OK;
}

/*Arrays*/
Returncode array_length(Array* this, Int* out_length) {
  *out_length = this->length;
  return OK;
}

/*System*/
Returncode Sys_print(Sys* _, String* text) {
  printf("%.*s\n", text->actual_length, text->chars);
  return OK;
}

Returncode Sys_exit(Sys* _, Int status) {
  exit(status);
  RAISE
}

Returncode set_cstring(String* str) {
  if (str->actual_length >= str->max_length) {
    if (strnlen(str->chars, str->max_length) >= str->max_length) {
      RAISE
    }
  }
  else if (strnlen(str->chars, str->actual_length + 1) > str->actual_length) {
    str->chars[str->actual_length] = '\0';
  }
  return OK;
}

Returncode Sys_system(Sys* _, String* command, Int* status) {
  CHECK(set_cstring(command));
  int res = system(command->chars);
  if (res == -1) {
    RAISE
  }
  *status = res;
  return OK;
}

Returncode Sys_getenv(Sys* _, String* name, Bool* exists, String* value) {
  CHECK(set_cstring(name));
  char* ret = getenv(name->chars);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->actual_length = strnlen(ret, value->max_length);
  strncpy(value->chars, ret, value->actual_length);
  *exists = true;
  return OK;
}
