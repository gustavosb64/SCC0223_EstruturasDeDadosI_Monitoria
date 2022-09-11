#ifndef PONTO_H
#define PONTO_H


typedef struct ponto Ponto;

Ponto* initialize_point(float x, float y);

int print_point(Ponto* P);

double dist_between_points(Ponto *Pi, Ponto *Pf);


#endif