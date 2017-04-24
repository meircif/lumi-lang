#include "mr.1.h"

/* Builds executables from MR files */
/*  */
/* Gets input files as "<name>.<MR version>.mr", */
/* generates "<name>.c" files using <MR version> compiler, */
/* and compiles the last one to "<name>.exe" executable using "gcc". */
/* (MR0 and MR1 only supports one file) */
/*  */
/* Supports MR0, MR1, MR2 & MR3. */


Returncode print(String* text);

Returncode string_length(String* this, Int* length);
Returncode string_get(String* this, Int index, Char* ch);
Returncode string_copy(String* this, String* source);
Returncode string_append(String* this, Char ch);
Returncode string_concat(String* this, String* ext);
Returncode string_has(String* this, Char ch, Bool* found);

Returncode array_length(Array* arr, Int* length);

Returncode sys_system(String* command, Int* status);


Returncode func(Array* argv) {
  if (argv->length < 2) {
    CHECK(print(&(String){29, 28, "usage: mrb [MR file name]..."}))
    return OK;
  }
  String* mr_file;
  if (argv->length - 1 < 0 || argv->length - 1 >= argv->length) RAISE mr_file = ((String*)(argv->values)) + argv->length - 1;
  if (mr_file->actual_length < 6) {
    CHECK(print(&(String){23, 22, "MR file name too short"}))
    return OK;
  }
  Bool has;
  CHECK(string_has(mr_file, '"', &has)) if (has) {
    CHECK(print(&(String){33, 32, "Illegal \" character in file name"}))
    return OK;
  }
  if ((0) + (mr_file->actual_length - 4) > mr_file->actual_length) RAISE String* prefix = &(String){mr_file->actual_length - 4, mr_file->actual_length - 4, mr_file->chars + 0};
  Char version;
  CHECK(string_get(mr_file, mr_file->actual_length - 4, &version))
  if (version < '0' or version > '3') {
    CHECK(print(&(String){23, 22, "Unsupported MR version"}))
    return OK;
  }
  if (version < '2' and argv->length > 2) {
    CHECK(print(&(String){40, 39, "Multiple files not supported before MR2"}))
    return OK;
  }
  /* run MR compiler */
  String* command = &(String){512, 0, (char[512]){0}};
  CHECK(string_copy(command, &(String){3, 2, "mr"}))
  CHECK(string_append(command, version))
  CHECK(string_concat(command, &(String){14, 13, "-compiler.exe"}))
  Int index = 1;
  while (true) {
    if (not(index < argv->length)) break;
    if (index < 0 || index >= argv->length) RAISE mr_file = ((String*)(argv->values)) + index;
    CHECK(string_concat(command, &(String){3, 2, " \""}))
    CHECK(string_concat(command, mr_file))
    CHECK(string_concat(command, &(String){2, 1, "\""}))
    index = index + 1;
  }
  if (version < '2') {
    CHECK(string_concat(command, &(String){3, 2, " \""}))
    CHECK(string_concat(command, prefix))
    CHECK(string_concat(command, &(String){3, 2, "c\""}))
  }
  Int status = 0;
  CHECK(print(command))
  CHECK(sys_system(command, &status))
  if (status != 0) {
    CHECK(print(&(String){19, 18, "MR compiler failed"}))
    return OK;
  }
  /* run C compiler */
  CHECK(string_copy(command, &(String){9, 8, "gcc -g \""}))
  CHECK(string_concat(command, prefix))
  CHECK(string_concat(command, &(String){4, 3, "c\" "}))
  if (version == '0') {
    CHECK(string_concat(command, &(String){24, 23, "mr0-file.c mr0-string.c"}))
  }
  else {
    CHECK(string_concat(command, &(String){4, 3, "mr."}))
    CHECK(string_append(command, version))
    CHECK(string_concat(command, &(String){3, 2, ".c"}))
  }
  CHECK(string_concat(command, &(String){6, 5, " -o \""}))
  CHECK(string_concat(command, prefix))
  CHECK(string_concat(command, &(String){5, 4, "exe\""}))
  CHECK(print(command))
  CHECK(sys_system(command, &status))
  if (status != 0) {
    CHECK(print(&(String){18, 17, "C compiler failed"}))
  }
  return OK;
}

MAIN_FUNC
