#ifndef CARTA_H
#define CARTA_H


typedef struct carta Carta;

Carta* inicializar_carta(char *nipe, char *simbolo);

Carta* ler_carta();

int get_simbolo(Carta *C);

void print_carta(Carta *C);

void free_carta(Carta *C);


#endif