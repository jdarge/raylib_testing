#include <stdio.h>
#include <stdlib.h>
#include "foo.h"

int main(void) {
    char *s = bar();
    printf("%s\n", s);
    
    free(s);
}
