#include "racional.h"

#include<stdlib.h>
#include<stdio.h>

struct racional_
{
    int numerador;
    int denominador;
};

//Cria um número racional a partir de dois inteiros
RACIONAL* criar(int numerador, int denominador)
{
    if(denominador == 0)
    {
        return NULL;
    }
    RACIONAL *racional = (RACIONAL*) malloc(sizeof(RACIONAL));
    racional->numerador = numerador;
    racional->denominador = denominador;
    return racional;
}

RACIONAL* adicionar(RACIONAL *a, RACIONAL *b)
{
    RACIONAL *resultado = (RACIONAL*) malloc(sizeof(RACIONAL));
    resultado->numerador = a->denominador * b->numerador + b->denominador * a->numerador;
    resultado->denominador = a->denominador * b->denominador;
    return resultado;
}

RACIONAL* multiplicar(RACIONAL *a, RACIONAL *b)
{
    RACIONAL *resultado = (RACIONAL*) malloc(sizeof(RACIONAL));
    resultado->denominador = a->denominador * b->denominador;
    resultado->numerador = a->numerador * b->numerador;
    return resultado;
}

void imprimir(RACIONAL *racional)
{
    printf("racional: %d/%d\n",
           racional->numerador, racional->denominador);
}

void apagar(RACIONAL *racional)
{
    if(racional != NULL)
    {
        free(racional);
    }
}