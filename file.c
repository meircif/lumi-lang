#include <stdio.h>
#include "mr-c-api.h"

typedef FILE* File;

Returncode print(String text) {
  printf("%*s\n", text.actual_length, text.chars);
  return OK;
}

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

Returncode file_read(void* file, String data) {
  int n = 0;
  while (1) {
    char c = fgetc((File)file);
    if (c == EOF) {
      data.actual_length = n;
      return OK;
    }
    if (n >= data.max_length) {
      data.actual_length = data.max_length;
      return ERR;
    }
    data.chars[n] = c;
    ++n;
  }
}

Returncode file_write(void* file, String data) {
  fprintf((File)file, "%*s", data.actual_length, data.chars);
  return OK;
}
