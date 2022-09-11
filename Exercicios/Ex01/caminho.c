#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "caminho.h"

struct caminho{
    int N;
    int cont;
    struct ponto **lista_pontos;
};

Caminho* initialize_caminho(int N){
    
    Caminho *C = (Caminho *) malloc(sizeof(Caminho));
    C->N = N;
    C->cont = 0;
    C->lista_pontos = (Ponto **) malloc(N * sizeof(Ponto*));

    return C;
}

int insert_new_point_in_caminho(Caminho *C, Ponto *P){

    int i = C->cont;

    C->lista_pontos[i] = P;
    C->cont += 1;

    return 0;
}

int print_caminho(Caminho *C){

    if (C == NULL) return -1;

    int N = C->cont;
    for(int i=0; i<N; i++){
        print_point(C->lista_pontos[i]);
    }

    return 0;
}

float distancia_total(Caminho *C){

    float D = 0.0;

    int N = C->cont-1;
    int i=0;
    do{
        D += dist_between_points(C->lista_pontos[i], C->lista_pontos[i+1]);
        i++;
    }while(--N);

    return D;
}

int free_caminho(Caminho *C){

    if (C == NULL) return -1;

    int N = C->cont;
    for(int i=0; i<N; i++)
        free(C->lista_pontos[i]);
    free(C->lista_pontos);
    free(C);

    return 0;
}
