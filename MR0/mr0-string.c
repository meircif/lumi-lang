#include <stdio.h>
#include <string.h>

#include "mr0-c-api.h"

/*like strnlen*/
int cstring_length(char* cstring, int max_length) {
  int length = 0;
  while (cstring[length] != '\0' && length < max_length) {
    ++length;
  }
  return length;
}

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
  int n;
  for (n = 0; n < this.actual_length; ++n) {
    if (this.chars[n] == old) {
      this.chars[n] = new;
    }
  }
  return OK;
}

Returncode int_to_string(String* str, Int value) {
  Bool is_neg = value < 0;
  int abs = value;
  if (is_neg) {
    abs = -value;
  }
  int swap = 0;
  str->actual_length = is_neg;
  do {
    swap *= 10;
    swap += abs % 10;
    abs /= 10;
    if (str->max_length <= str->actual_length) {
      str->actual_length = 0;
      return ERR;
    }
    ++str->actual_length;
  } while (abs > 0);
  char* next = str->chars;
  if (is_neg) {
    *next = '-';
    ++next;
  }
  char* last = str->chars + str->actual_length;
  while (next < last) {
    *next = '0' + swap % 10;
    ++next;
    swap /= 10;
  }
  return OK;
}
