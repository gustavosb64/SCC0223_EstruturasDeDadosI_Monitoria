#ifndef CATALOGO_H
#define CATALOGO_H


typedef struct catalogo Catalogo;

Catalogo* inicializar_catalogo();

int add_jogo_catalogo(Catalogo *C, char *nome, char *empresa, int ano);

int busca_por_empresa(Catalogo *C, char *this_empresa);

int busca_por_ano(Catalogo *C, int this_ano);

int buscar_catalogo(Catalogo *C, char opcao);

int print_catalogo(Catalogo *C);

int free_catalogo(Catalogo *C);


#endif