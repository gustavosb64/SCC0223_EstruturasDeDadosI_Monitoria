#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "jogo.h"
#include "catalogo.h"
#include "utils.h"

#define BUFFER 4096
char *readline(FILE *stream) {
    char *string = 0;
    /*
    int pos = 0; 

	do{
        if (pos % BUFFER == 0) {
            string = (char *) realloc(string, (pos / BUFFER + 1) * BUFFER);
        }
        string[pos] = (char) fgetc(stream);

    }while(string[pos++] != '\n' && !feof(stream));

    / Checa se há a presença do caractere '\r'
     * e ajusta o espaço alocado para o tamanho exato da string /
    int n;
    if (string[pos-2] == '\r') n = 2;
    else n = 1;

    string[pos-n] = '\0';
    string = (char *) realloc(string, pos-(n-1)); // (pos-1) caso haja '\r'
    int n=1;
    string[pos-n] = '\0';
    string = (char *) realloc(string, pos-(n-1)); // (pos-1) caso haja '\r'
    */
    
    string = (char *) calloc(80, sizeof(char));
    scanf(" %[^\r\n]", string);
    //printf("string: %s\n",string);

    // Caso seja digitado um único caractere e seja 'F'
    if (strlen(string) == 1 && string[0] == 'F') 
        return NULL;

    return string;
}

int op_adicionar_jogos(Catalogo *C){

    // Lê dados do usuário
    int ano;
    char *nome;
    char *empresa;

    // Enquanto ainda há dados para a serem lidos, 
    // eles são lidos e adicionados ao catálogo
    while((nome = readline(stdin))){
        empresa = readline(stdin);
        scanf(" %d\n", &ano);

        add_jogo_catalogo(C, nome, empresa, ano);
    }

    return 0;
}

int op_pesquisar_jogos(Catalogo *C){

    char opcao;

    // Enquanto ainda há buscas a serem feitas
    do{
        scanf(" %c\n", &opcao);
    }while(!buscar_catalogo(C, opcao));

    return 0;
}
