#ifndef JOGO_H
#define JOGO_H


typedef struct jogo Jogo;

Jogo* cadastrar_jogo(char *nome, char *empresa, int ano);

char *get_empresa(Jogo *jogo);

int get_ano(Jogo *jogo);

int print_jogo_total(Jogo *jogo);

int print_jogo_nome(Jogo *jogo);

int free_jogo(Jogo *jogo);


#endif