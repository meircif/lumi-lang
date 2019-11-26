#define _CRT_SECURE_NO_WARNINGS
#include "lumi.1.h"

typedef FILE* File;

/*like strnlen*/
int cstring_length(char* cstring, int max_length) {
  int length = 0;
  while (cstring[length] != '\0' && length < max_length) {
    ++length;
  }
  return length;
}

/*Print*/
Returncode print(String* text) {
  printf("%.*s\n", text->actual_length, text->chars);
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
  str->actual_length = 0;
  str->chars = (char*)buff + sizeof(String);
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
Returncode open_file(void** file, String* name, char* mode) {
  *file = NULL;
  *file = fopen(name->chars, mode);
  if (*file == NULL) {
    RAISE
  }
  return OK;
}

Returncode file_open_read(String* name, void** file) {
  return open_file(file, name, "r");
}

Returncode file_open_write(String* name, void** file) {
  return open_file(file, name, "w");
}

Returncode file_close(void* file) {
  if (fclose((File)file) == 0) {
    return OK;
  }
  RAISE
}

Returncode file_getc(void* file, Char* out_char) {
  *out_char = getc((File)file);
  return OK;
}

Returncode file_putc(void* file, Char in_char) {
  int res = putc(in_char, (File)file);
  if (res != in_char) {
    RAISE
  }
  return OK;
}

Returncode file_write(void* file, String* data) {
  fprintf((File)file, "%.*s", data->actual_length, data->chars);
  return OK;
}

/*Strings*/
Returncode string_clear(String* this) {
  this->actual_length = 0;
  return OK;
}

Returncode string_length(String* this, Int* out_length) {
  *out_length = this->actual_length;
  return OK;
}

Returncode string_equal(String* this, String* other, Bool* out_equal) {
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

Returncode string_get(String* this, Int index, Char* out_char) {
  if (index < 0 or index >= this->actual_length) {
    RAISE
  }
  *out_char = this->chars[index];
  return OK;
}

Returncode string_append(String* this, Char in_char) {
  if (this->actual_length == this->max_length) {
    RAISE
  }
  this->chars[this->actual_length] = in_char;
  ++this->actual_length;
  return OK;
}

Returncode string_replace(String* this, Char old, Char new) {
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

Returncode int_to_string(Int value, String* out_str) {
  Bool is_neg = value < 0;
  int abs = value;
  if (is_neg) {
    abs = -value;
  }
  int swap = 0;
  out_str->actual_length = is_neg;
  do {
    swap *= 10;
    swap += abs % 10;
    abs /= 10;
    if (out_str->max_length <= out_str->actual_length) {
      out_str->actual_length = 0;
      RAISE
    }
    ++out_str->actual_length;
  } while (abs > 0);
  char* next = out_str->chars;
  if (is_neg) {
    *next = '-';
    ++next;
  }
  char* last = out_str->chars + out_str->actual_length;
  while (next < last) {
    *next = '0' + swap % 10;
    ++next;
    swap /= 10;
  }
  return OK;
}

Returncode string_copy(String* this, String* source) {
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

Returncode string_concat(String* this, String* ext) {
  if (this->actual_length + ext->actual_length > this->max_length) {
    RAISE
  }
  memcpy(this->chars + this->actual_length, ext->chars, ext->actual_length);
  this->actual_length += ext->actual_length;
  return OK;
}

Returncode string_find(String* this, String* pattern, Int* out_index) {
  Int n;
  for (n = 0; n <= this->actual_length - pattern->actual_length; ++n) {
    if (strncmp(this->chars + n, pattern->chars, pattern->actual_length) == 0) {
      *out_index = n;
      return OK;
    }
  }
  RAISE
}

Returncode string_has(String* this, Char ch, Bool* found) {
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
Returncode sys_exit(Int status) {
  exit(status);
  RAISE
}

Returncode set_cstring(String* str) {
  if (str->actual_length >= str->max_length) {
    if (cstring_length(str->chars, str->max_length) >= str->max_length) {
      RAISE
    }
  }
  else if (cstring_length(str->chars, str->actual_length + 1) > str->actual_length) {
    str->chars[str->actual_length] = '\0';
  }
  return OK;
}

Returncode sys_system(String* command, Int* status) {
  CHECK(set_cstring(command));
  int res = system(command->chars);
  if (res == -1) {
    RAISE
  }
  *status = res;
  return OK;
}

Returncode sys_getenv(String* name, Bool* exists, String* value) {
  CHECK(set_cstring(name));
  char* ret = getenv(name->chars);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->actual_length = cstring_length(ret, value->max_length);
  strncpy(value->chars, ret, value->actual_length);
  *exists = true;
  return OK;
}
