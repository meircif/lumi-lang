#include "mr.3.h"

#define MR_FILE_NAME __FILE__
#define MR_FUNC_NAME __FUNCTION__
#define CRAISE RAISE(__LINE__)
#define CCHECK(err) CHECK(__LINE__, err)

Returncode set_cstring(String* str) {
  if (str->length >= str->max_length) {
    if (strnlen(str->chars, str->max_length) >= str->max_length) {
      CRAISE
    }
  }
  else if (strnlen(str->chars, str->length + 1) > str->length) {
    str->chars[str->length] = '\0';
  }
  return OK;
}

/*dynamic allocation*/
String* new_string(int length) {
  void* buff = malloc(sizeof(String) + length);
  if (buff == NULL) {
    return NULL;
  }
  String* str = buff;
  str->max_length = length;
  str->length = 0;
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
  CCHECK(set_cstring(name));
  *file = NULL;
  *file = fopen(name->chars, mode);
  if (*file == NULL) {
    CRAISE
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
  fprintf(file, "%.*s", data->length, data->chars);
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
  if (strncmp(this->chars, other->chars, this->length) == 0) {
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
  *out_char = this->chars[index];
  return OK;
}

Returncode String_append(String* this, Char in_char) {
  if (this->length == this->max_length) {
    CRAISE
  }
  this->chars[this->length] = in_char;
  ++this->length;
  return OK;
}

Returncode String_replace(String* this, Char old, Char new) {
  if (old == new) {
    return OK;
  }
  int n;
  for (n = 0; n < this->length; ++n) {
    if (this->chars[n] == old) {
      this->chars[n] = new;
    }
  }
  return OK;
}

Returncode Int_str(Int value, String* out_str) {
  int res = snprintf(out_str->chars, out_str->max_length ,"%d", value);
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
  memcpy(this->chars, source->chars, this->length);
  return OK;
}

Returncode String_concat(String* this, String* ext) {
  if (this->length + ext->length > this->max_length) {
    CRAISE
  }
  memcpy(this->chars + this->length, ext->chars, ext->length);
  this->length += ext->length;
  return OK;
}

Returncode String_find(String* this, String* pattern, Int* out_index) {
  Int n;
  for (n = 0; n <= this->length - pattern->length; ++n) {
    if (strncmp(this->chars + n, pattern->chars, pattern->length) == 0) {
      *out_index = n;
      return OK;
    }
  }
  CRAISE
}

Returncode String_has(String* this, Char ch, Bool* found) {
  int n;
  for (n = 0; n < this->length; ++n) {
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

/*voidtem*/
Returncode Sys_print(void* _, String* text) {
  printf("%.*s\n", text->length, text->chars);
  return OK;
}

Returncode Sys_exit(void* _, Int status) {
  exit(status);
  CRAISE
}

Returncode Sys_system(void* _, String* command, Int* status) {
  CCHECK(set_cstring(command));
  int res = system(command->chars);
  if (res == -1) {
    CRAISE
  }
  *status = res;
  return OK;
}

Returncode Sys_getenv(void* _, String* name, String* value, Bool* exists) {
  CCHECK(set_cstring(name));
  char* ret = getenv(name->chars);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->length = strnlen(ret, value->max_length);
  strncpy(value->chars, ret, value->length);
  *exists = true;
  return OK;
}
