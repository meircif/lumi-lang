#include <stdio.h>
#include <string.h>

#include "mr0-c-api.h"

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
