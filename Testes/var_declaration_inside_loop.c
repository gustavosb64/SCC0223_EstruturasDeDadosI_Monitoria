#include <stdio.h>
#include <stdlib.h>

typedef struct tipo{
    int i;
    char c;
}Tipo;

Tipo* criar_tipo(int i){

    Tipo *T;

    if (i < 3) T = (Tipo *) malloc(sizeof(Tipo));
    else T = NULL;

    return T;
}

int main(){

    Tipo *T;

    Tipo *n_T;
    int i=0;
    while( (n_T = criar_tipo(i)) != NULL){
        printf("%d\n",i);
        i++;
    }




    return 0;
}

