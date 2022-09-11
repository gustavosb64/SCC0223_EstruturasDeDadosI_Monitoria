#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int x;
    float y;
}Struct;

int main(){

    Struct *S;

    S.x = 1;
    S->y = 3.4;

    printf("%d, %f\n",S.x, S->y);


    return 0;
}
