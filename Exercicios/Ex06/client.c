#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "utils.h"

struct client{
    char* cpf;
    char* nome;
    int idade;
    long double saldo;
};

Client* create_client(){

    Client *C = (Client *) malloc(sizeof(Client));
    C->cpf = NULL;
    C->nome = NULL;
    C->idade = -1;
    C->saldo = 0;

    return C;
}

Client* register_client(){

    Client *C = create_client();
    
    /* reads input from stdin */
    C->cpf = read_word();
    C->nome = read_word();
    scanf("%d;%Lf ", &C->idade, &C->saldo);

    return C;
}

char* get_cpf(Client *C){
    return C->cpf;
}

long int cpf_to_longint(char *cpf){

    char *aux_cpf = (char *) calloc(strlen(cpf)-2, sizeof(char));

    int aux_cont = 0;
    for (int i=0; i<strlen(cpf); i++){
        if (cpf[i] != '.' && cpf[i] != '-')
            aux_cpf[aux_cont++] = cpf[i];
    }

    long int i_cpf = strtoll(aux_cpf, NULL, 10);
    free(aux_cpf);

    return i_cpf;
}

int print_client(Client *C){

    if (C == NULL) return 1;

    printf("Conta :: %s\n", C->nome);
    printf("CPF :: %s\n", C->cpf);
    printf("Idade :: %d\n", C->idade);
    printf("Saldo atual :: R$ %.2Lf\n", C->saldo);

    return 0;
}

void free_client(Client *C){
    if (C == NULL) return;
    free(C->nome);
    free(C->cpf);
    free(C);
    return;
}
