#include "foo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc >= 2) {
    printf("Argument 1: %s\n", argv[1]);
  }

  char *s = bar();
  printf("%s\n", s);

  free(s);

  return 0;
}
