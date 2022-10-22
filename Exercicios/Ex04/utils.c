#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "pilha_encadeada.h"
#include "carta.h"
#include "utils.h"

char* readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != ' ') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

void ler_todas_as_cartas(Stack *S){

    Carta *carta = ler_carta();
    while(carta != NULL){
        AddElem(S, carta);
        carta = ler_carta();    
    }
    return;
}

int soma_cartas(Stack *S){

    Carta *carta;

    int soma = 0;
    while(soma < 21 && !Pop(S, &carta)){
        soma += get_simbolo(carta); 
    }

    return soma;
}

void get_resultado(Stack *S){

    int soma = soma_cartas(S);
    
    if (soma == 21) 
        printf("Ganhou ;)\n");
    else{
        printf("Perdeu :(\n");
        printf("Soma :: %d\n", soma);
    }

    return;
}
