#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"
#include "carta.h"
#include "utils.h"

struct carta{
    char *nipe;
    char *simbolo;
};

Carta* inicializar_carta(char *nipe, char *simbolo){

    Carta *C = (Carta *) malloc(sizeof(Carta));

    C->nipe = nipe;
    C->simbolo = simbolo;

    return C;
}

Carta* ler_carta(){

    char *nipe = readLine();
    if (nipe[0] == 0){
        free(nipe);
        return NULL;
    }

    char *simbolo = readLine();

    Carta *C = inicializar_carta(nipe, simbolo);

    return C;
}

int get_simbolo(Carta *C){

    int simbolo = atoi(C->simbolo);

    if(simbolo > 0) return simbolo;
    return 10;
}

void print_carta(Carta *C){

    printf("%s %s",C->nipe, C->simbolo);
    printf("\n");

    return;
}

void free_carta(Carta *C){

    free(C->nipe);
    free(C->simbolo);
    free(C);

    return;
}
