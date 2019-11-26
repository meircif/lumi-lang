#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tl0-c-api.h"

typedef FILE* File;

Returncode print(String text) {
  printf("%.*s\n", text.actual_length, text.chars);
  return OK;
}

Returncode open_file(void** file, String name, char* mode) {
  *file = NULL;
  *file = fopen(name.chars, mode);
  if (*file == NULL) {
    return ERR;
  }
  return OK;
}

Returncode file_open_read(void** file, String name) {
  return open_file(file, name, "r");
}

Returncode file_open_write(void** file, String name) {
  return open_file(file, name, "w");
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
