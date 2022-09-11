#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "registro.h"

int main(){

    char *nome;
    int idade;
    int cpf;
    double v1;
    double v2;

    Registro *R = criar_registro();
    for (int i=0; i<2; i++){

        // A cada iteração, uma nova região de memória deve 
        // ser alocada para o nome
        nome = (char *) calloc(100, sizeof(char));

        scanf(" %[^\n]", nome); // lê os dados do stdin até encontrar um '\n'
        scanf(" %d", &idade);
        scanf(" %d", &cpf);
        scanf(" %lf", &v1);
        scanf(" %lf", &v2);

        R = adicionar_pessoa(R, nome, idade, cpf, v1, v2);
    }

    // Imprime dados do registro
    print_registro(R);

    // Libera memória do registro
    free_registro(R);

    return 0;
}
