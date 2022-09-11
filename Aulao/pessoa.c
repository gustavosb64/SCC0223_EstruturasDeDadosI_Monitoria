#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

struct pessoa{
    char *nome;
    int idade;
    int cpf;
    double v1;
    double v2;
};

Pessoa* criar_pessoa(){

    Pessoa *P = (Pessoa *) malloc(sizeof(Pessoa));

    P->nome = NULL;
    P->idade = -1;
    P->cpf = -1;
    P->v1 = -1;
    P->v2 = -1;

    return P;
}

Pessoa* cadastrar_pessoa(char *nome, int idade, int cpf, double v1, double v2){

    Pessoa *P = (Pessoa *) malloc(sizeof(Pessoa));

    P->nome = nome;
    P->idade = idade;
    P->cpf = cpf;
    P->v1 = v1;
    P->v2 = v2;

    return P;
}

int print_pessoa(Pessoa *P){

    if (P == NULL) return -1;

    printf("Nome: %s\n", P->nome);
    printf("idade: %d\n", P->idade);
    printf("cpf: %d\n", P->cpf);
    printf("v1: %lf\n", P->v1);
    printf("v2: %lf\n", P->v2);

    printf("\n");

    return 0;
}

int free_pessoa(Pessoa *P){

    free(P->nome);
    free(P);

    return 0;
}
