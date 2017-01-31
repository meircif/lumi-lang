#include "mr.1.h"

typedef FILE* File;

/*Print*/
Returncode print(String text) {
  printf("%.*s\n", text.actual_length, text.chars);
  return OK;
}

/*dynamic allocation*/
String* new_string(int length) {
  void* buff = malloc(sizeof(String) + length);
  if (buff == 0) {
    return 0;
  }
  String* str = buff;
  str->max_length = length;
  str->actual_length = 0;
  str->chars = (Byte*)buff + sizeof(String);
  return str;
}

Array* new_array(int length, int value_size) {
  void* buff = malloc(sizeof(Array) + length * value_size);
  if (buff == 0) {
    return 0;
  }
  Array* arr = buff;
  arr->length = length;
  arr->values = (Byte*)buff + sizeof(Array);
  return arr;
}

/*Files*/
Returncode file_open_read(void** file, String name) {
  return open_file(file, name, "r");
}

Returncode file_open_write(void** file, String name) {
  return open_file(file, name, "w");
}

Returncode open_file(void** file, String name, char* mode) {
  *file = NULL;
  *file = fopen(name.chars, mode);
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

Returncode file_getc(Char* out_char, void* file) {
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

Returncode file_write(void* file, String data) {
  fprintf((File)file, "%.*s", data.actual_length, data.chars);
  return OK;
}

/*Strings*/
Returncode string_clear(String* this) {
  this->actual_length = 0;
  return OK;
}

Returncode string_length(Int* length, String this) {
  *length = this.actual_length;
  return OK;
}

Returncode string_equal(Bool* equal, String this, String other) {
  if (this.actual_length != other.actual_length) {
    *equal = false;
    return OK;
  }
  if (strncmp(this.chars, other.chars, this.actual_length) == 0) {
    *equal = true;
    return OK;
  }
  *equal = false;
  return OK;
}

Returncode string_get(Char* ch, String this, Int index) {
  if (index < 0 or index >= this.actual_length) {
    return ERR;
  }
  *ch = this.chars[index];
  return OK;
}

Returncode string_append(String* this, Char ch) {
  if (this->actual_length == this->max_length) {
    return ERR;
  }
  this->chars[this->actual_length] = ch;
  ++this->actual_length;
  return OK;
}

Returncode string_replace(String this, Char old, Char new) {
  for (int n = 0; n < this.actual_length; ++n) {
    if (this.chars[n] == old) {
      this.chars[n] = new;
    }
  }
  return OK;
}

Returncode int_to_string(String* str, Int value) {
  int res = snprintf(str->chars, str->max_length ,"%d", value);
  if (res <= 0 or res >= str->max_length) {
    str->actual_length = 0;
    return ERR;
  }
  str->actual_length = res;
  return OK;
}
