#include <stdio.h>
#include <stdlib.h>

int main(){

    // Aloca uma região de memória com a quantidade de BYTES fornecida
    //  Lembrar de realizar a multiplicação de N*sizeof(dado), onde
    //      * N: quantidade de elementos
    //      * dado: tipo de dados do ponteiro
    char *c = (char *) malloc(10*sizeof(char));

    // Aloca região e preenche todos os valroes alocados com 0
    char *string = (char *) calloc(10, sizeof(char));

    // Realoca o ponteiro, aumentando ou diminuindo o espaço alocado
    //  * Os dados contidos no ponteiro antes permanecem os mesmos.
    //  * Caso aloque para uma região menor, os dados são truncados.
    //  * Comando relativamente pesado.
    c = (char *) realloc(c, 30*sizeof(char));
    
    return 0;
}
