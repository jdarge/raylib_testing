#include <stdio.h>

#include "foo.h"

int main(void) {
  char *s = bar();
  printf("%s\n", s);
  printf("EOF\n");
}
