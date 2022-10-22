#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "pilha_encadeada.h"
#include "carta.h"
#include "utils.h"

int main (int argc, char *argv[]){

    Stack *S = CreateStack();

    ler_todas_as_cartas(S);

    get_resultado(S);
    
    FreeStack(S);


    return 0;
}
