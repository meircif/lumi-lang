#include "mr.1.h"

/* Builds executables from MR files */
/*  */
/* Gets one input file as "<name>.<MR version>.mr", */
/* generates "<name>.c" file using <MR version> compiler, */
/* and compiles it to "<name>.exe" executable using "gcc". */
/*  */
/* Supports MR0, MR1 & MR2. */


Returncode print(String* text);

Returncode string_length(String* this, Int* length);
Returncode string_get(String* this, Int index, Char* ch);
Returncode string_copy(String* this, String* source);
Returncode string_append(String* this, Char ch);
Returncode string_concat(String* this, String* ext);

Returncode array_length(Array* arr, Int* length);

Returncode sys_system(String* command, Int* status);


Returncode func(Array* argv) {
  Int length = 0;
  CHECK(array_length(argv, &length))
  if (length != 2) {
    CHECK(print(&(String){26, 25, "usage: mrb [MR file name]"}))
    return OK;
  }
  String* mr_file;
  if (1 < 0 || 1 >= argv->length) RAISE mr_file = ((String*)(argv->values)) + 1;
  CHECK(string_length(mr_file, &length))
  if (length < 6) {
    CHECK(print(&(String){23, 22, "MR file name too short"}))
    return OK;
  }
  if ((0) + (length - 4) > mr_file->actual_length) RAISE String* prefix = &(String){length - 4, length - 4, mr_file->chars + 0};
  Char version;
  CHECK(string_get(mr_file, length - 4, &version))
  if (version < '0' or version > '2') {
    CHECK(print(&(String){23, 22, "Unsupported MR version"}))
    return OK;
  }
  /* run MR compiler */
  String* command = &(String){128, 0, (char[128]){0}};
  CHECK(string_copy(command, &(String){3, 2, "mr"}))
  CHECK(string_append(command, version))
  CHECK(string_concat(command, &(String){15, 14, "-compiler.exe "}))
  CHECK(string_concat(command, mr_file))
  CHECK(string_append(command, ' '))
  CHECK(string_concat(command, prefix))
  CHECK(string_append(command, 'c'))
  
  Int status = 0;
  CHECK(sys_system(command, &status))
  
  /* run C compiler */
  CHECK(string_copy(command, &(String){5, 4, "gcc "}))
  CHECK(string_concat(command, prefix))
  CHECK(string_concat(command, &(String){3, 2, "c "}))
  if (version == '0') {
    CHECK(string_concat(command, &(String){24, 23, "mr0-file.c mr0-string.c"}))
  }
  if (version == '1') {
    CHECK(string_concat(command, &(String){7, 6, "mr.1.c"}))
  }
  if (version == '2') {
    CHECK(string_concat(command, &(String){7, 6, "mr.1.c"}))
  }
  CHECK(string_concat(command, &(String){5, 4, " -o "}))
  CHECK(string_concat(command, prefix))
  CHECK(string_concat(command, &(String){4, 3, "exe"}))
  CHECK(sys_system(command, &status))
  
  return OK;
}

MAIN_FUNC
