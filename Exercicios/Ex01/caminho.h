#ifndef CAMINHO_H
#define CAMINHO_H


typedef struct caminho Caminho;

Caminho* initialize_caminho(int N);

int insert_new_point_in_caminho(Caminho *C, Ponto *P);

int print_caminho(Caminho *C);

float distancia_total(Caminho *C);

int free_caminho(Caminho *C);


#endif