typedef int DIR;

struct dirent {
  char d_name[50];
};

typedef struct dirent dirent;

DIR mock_state = -1;
dirent cur_ent;

DIR* opendir(const char* path) {
  if (strcmp(path, "illegal") == 0) {
    return NULL;
  }
  if (strcmp(path, "cant/close") == 0) {
    /* Iteration will work but close will fail. */
    mock_state = -1;
    return &mock_state;
  }
  mock_state = 0;
  return &mock_state;
}

int closedir(DIR* dir) {
  if (*dir < 0) {
    return -1;
  }

  *dir = -1;
  return 0;
}

struct dirent* readdir(DIR* dir) {
  switch (*dir) {
    case 0:
    strcpy(cur_ent.d_name, "file0");
    break;
    case 1:
    strcpy(cur_ent.d_name, "file1");
    break;
    case 2:
    strcpy(cur_ent.d_name, "file2");
    break;
    default:
    return NULL;
  }

  ++mock_state;
  return &cur_ent;
}
