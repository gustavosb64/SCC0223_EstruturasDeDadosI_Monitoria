#ifndef RACIONAL_H
#define RACIONAL_H

typedef struct racional_ RACIONAL;

RACIONAL* criar(int numerador, int denominador);
RACIONAL* adicionar(RACIONAL *a, RACIONAL *b);
RACIONAL* multiplicar(RACIONAL *a, RACIONAL *b);
void imprimir(RACIONAL *racional);
void apagar(RACIONAL *racional);

#endif //RACIONAL_H