#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "jogo.h"

struct jogo{
    char *nome;
    char *empresa;
    int ano;
};

Jogo* cadastrar_jogo(char *nome, char *empresa, int ano){

    // Aloca espaço para jogo e checa se espaço foi alocado
    Jogo *jogo = (Jogo *) malloc(sizeof(Jogo));
    if (jogo == NULL)
        return NULL;

    // Atribui valores à estrutura
    jogo->nome = nome;
    jogo->empresa = empresa;
    jogo->ano = ano;

    return jogo;
}

char *get_empresa(Jogo *jogo){

    return jogo->empresa;
}

int get_ano(Jogo *jogo){

    return jogo->ano;
}

int print_jogo_total(Jogo *jogo){
        
    printf("%s\n",jogo->nome);
    printf("%s\n",jogo->empresa);
    printf("%d\n",jogo->ano);

    return 0;
}

int print_jogo_nome(Jogo *jogo){

    printf("%s\n",jogo->nome);

    return 0;
}

int free_jogo(Jogo *jogo){

    free(jogo->nome);
    free(jogo->empresa);
    free(jogo);

    return 0;
}
