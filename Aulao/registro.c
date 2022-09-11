#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "registro.h"

struct registro{
    int n_pessoas;
    Pessoa **lista_pessoas;
};

Registro* criar_registro(){

    Registro *R = (Registro *) malloc(sizeof(Registro));

    R->n_pessoas = 0;
    R->lista_pessoas = NULL;

    return R;
}

Registro* adicionar_pessoa(Registro *R, char *nome, int idade, int cpf, double v1, double v2){

    // Cadastra uma pessoa
    Pessoa *P = cadastrar_pessoa(nome, idade, cpf, v1, v2);

    // Incrementa o número de pessoas na lista em 1
    R->n_pessoas += 1;

    // Realoca a região para uma pessoa a mais
    int N = R->n_pessoas;
    R->lista_pessoas = (Pessoa **) realloc(R->lista_pessoas, N * sizeof(R->lista_pessoas));

    // Último elemento da lista passa a apontar para a pessoa recém cadastrada
    R->lista_pessoas[N-1] = P;

    return R;
}

void print_registro(Registro *R){

    for (int i=0; i< R->n_pessoas; i++){
        print_pessoa(R->lista_pessoas[i]);
    }

    return;
}

int free_registro(Registro *R){

    for (int i=0; i < R->n_pessoas; i++){
        free_pessoa(R->lista_pessoas[i]); // libera memória de cada ponteiro interno
    }
    free(R->lista_pessoas); // libera a memória do ponteiro mais externo

    free(R);

    return 0;
}
