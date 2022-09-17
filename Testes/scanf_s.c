#include <stdio.h>
#include <stdlib.h>

int main(){

    char *s = (char *) malloc(10*sizeof(char));

    scanf(" %s", s);

    printf("%s\n", s);

    return 0;
}
