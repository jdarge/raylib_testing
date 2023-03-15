#include <stdlib.h>
#include <string.h>

#include "foo.h"

char *bar() {

    char *s = (char *)malloc(sizeof(char) * 12);
    strcpy(s, "Hello World\0");

    return s;
}
