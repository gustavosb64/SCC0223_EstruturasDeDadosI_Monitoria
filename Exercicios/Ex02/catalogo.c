#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "catalogo.h"
#include "utils.h"

struct catalogo{
    int n_jogos;
    Jogo **lista_jogos;
};

Catalogo* inicializar_catalogo(){

    Catalogo *C = (Catalogo *) malloc(sizeof(Catalogo));

    C->n_jogos = 0;
    C->lista_jogos = NULL;

    return C;
}

int add_jogo_catalogo(Catalogo *C, char *nome, char *empresa, int ano){

    // Atualiza tamanho de lista de jogos
    C->lista_jogos = (Jogo **) realloc(C->lista_jogos, sizeof(Jogo*) * (C->n_jogos+1));

    // Cadastra um jogo com os dados fornecidos e o adiciona à lista
    Jogo *jogo = cadastrar_jogo(nome, empresa, ano);
    
    C->lista_jogos[C->n_jogos] = jogo;
    C->n_jogos += 1;
    
    return 0;
}

int busca_por_empresa(Catalogo *C, char *this_empresa){

    int flag_found = 0;
    char *cur_empresa = NULL;

    for(int i=0; i<C->n_jogos; i++){

        cur_empresa = get_empresa(C->lista_jogos[i]);
        if (!strcmp(this_empresa, cur_empresa)){
            print_jogo_nome(C->lista_jogos[i]);
            flag_found = 1;
        }

    }

    return flag_found;
}

int busca_por_ano(Catalogo *C, int this_ano){

    int flag_found = 0;

    int cur_ano = -1;
    for (int i=0; i<C->n_jogos; i++){
        
        cur_ano = get_ano(C->lista_jogos[i]);
        if (this_ano == cur_ano){
            print_jogo_nome(C->lista_jogos[i]);
            flag_found = 1;
        }
    
    }

    return flag_found;
}

int buscar_catalogo(Catalogo *C, char opcao){

    int res = 0; 
    /* Valores de res:
     *  0: ainda há buscas
     *  1: buscas encerradas
    */

    int flag_found = 1;
    /*
     * Valores de flag_found:
     *  0: busca não foi bem sucedida
     *  1: busca foi bem sucedida
    */

    char *empresa = NULL;
    int ano = -1;
    switch(opcao){

        case 'A':
            scanf(" %d", &ano);
            flag_found = busca_por_ano(C, ano);
            break;

        case 'E':
            empresa = readline(stdin);
            flag_found = busca_por_empresa(C, empresa);
            free(empresa);

            break;

        case 'F':
            res = 1;
            break;
    }

    // Caso a busca não tenha retornado nenhum resultado
    if (!flag_found)
        printf("Nada encontrado\n");

    return res;
}

int print_catalogo(Catalogo *C){

    int N = C->n_jogos;
    for(int i=0; i<N; i++){
        print_jogo_total(C->lista_jogos[i]);
    }

    return 0;
}

int free_catalogo(Catalogo *C){

    for(int i=0; i<C->n_jogos; i++)
        free_jogo(C->lista_jogos[i]);
    free(C->lista_jogos);
    free(C);

    return 0;
}
