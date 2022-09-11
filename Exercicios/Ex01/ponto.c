#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    float x;
    float y;
};

Ponto* initialize_point(float x, float y){

    Ponto* P = (Ponto *) malloc(sizeof(Ponto));
    P->x = x;
    P->y = y;

    return P;
}

int print_point(Ponto* P){

    printf("(%f, %f)\n",P->x, P->y);

    return 0;
}

double dist_between_points(Ponto *Pi, Ponto *Pf){

    float D_X = Pf->x - Pi->x;
    float D_Y = Pf->y - Pi->y;
    return sqrt(pow(D_X,2) + pow(D_Y,2));
}
