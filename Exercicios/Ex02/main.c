#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "catalogo.h"

int main(int argc, char *argv[]){

    Catalogo *C = inicializar_catalogo();

    // Operação 1: adiciona jogos ao catálogo
    op_adicionar_jogos(C);

    // Operação 2: pesquisa jogos no catálogo
    op_pesquisar_jogos(C);

    // Libera memória
    free_catalogo(C);
     
    return 0;
}
