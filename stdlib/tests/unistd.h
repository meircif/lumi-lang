
#include <string.h>

#define F_OK 0
#define R_OK 1
#define W_OK 2
#define X_OK 3

int access(char * path, int amode) {
  return (strcmp(path, "/some/path") == 0) && (amode == F_OK);
}
