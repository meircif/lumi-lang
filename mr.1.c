#include "mr.1.h"

typedef FILE* File;

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
Returncode file_open_read(String* name, void** file) {
  return open_file(file, name, "r");
}

Returncode file_open_write(String* name, void** file) {
  return open_file(file, name, "w");
}

Returncode open_file(void** file, String* name, char* mode) {
  *file = NULL;
  *file = fopen(name->chars, mode);
  if (*file == NULL) {
    return ERR;
  }
  return OK;
}

Returncode file_close(void* file) {
  if (fclose((File)file) == 0) {
    return OK;
  }
  return ERR;
}

Returncode file_getc(void* file, Char* out_char) {
  *out_char = getc((File)file);
  return OK;
}

Returncode file_putc(void* file, Char in_char) {
  int res = putc(in_char, (File)file);
  if (res != in_char) {
    return ERR;
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
    return ERR;
  }
  *out_char = this->chars[index];
  return OK;
}

Returncode string_append(String* this, Char in_char) {
  if (this->actual_length == this->max_length) {
    return ERR;
  }
  this->chars[this->actual_length] = in_char;
  ++this->actual_length;
  return OK;
}

Returncode string_replace(String* this, Char old, Char new) {
  for (int n = 0; n < this->actual_length; ++n) {
    if (this->chars[n] == old) {
      this->chars[n] = new;
    }
  }
  return OK;
}

Returncode int_to_string(Int value, String* out_str) {
  int res = snprintf(out_str->chars, out_str->max_length ,"%d", value);
  if (res <= 0 or res >= out_str->max_length) {
    out_str->actual_length = 0;
    return ERR;
  }
  out_str->actual_length = res;
  return OK;
}

/*Arrays*/
Returncode array_length(Array* this, Int* out_length) {
  *out_length = this->length;
  return OK;
}