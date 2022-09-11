#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

/*
 * Inicializa uma variável do tipo Pessoa*
 *  @return:
 *      Pessoa*: Pessoa* criada com os dados padrão
*/
Pessoa* criar_pessoa();

/*
 * Inicializa uma variável do tipo Pessoa* com os dados fornecidos
 *  @param:
 *      char *nome: nome da pessoa cadastrada 
 *      int idade: idade da pessoa cadastrada 
 *      int cpf: CPF da pessoa cadastrada 
 *      double v1: v1 da pessoa cadastrada 
 *      double v2: v2 da pessoa cadastrada 
 *  @return:
 *      Pessoa*: Pessoa* criada com os dados fornecidos
*/
Pessoa* cadastrar_pessoa(char *nome, int idade, int cpf, double v1, double v2);

/*
 * Imprime na tela os dados de uma Pessoa *P
 *  @param:
 *      Pessoa *P: pessoa a ter os dados printados
 *  @return:
 *      int 0: não ocorreu nenhum erro
*/
int print_pessoa(Pessoa *P);

/*
 * Libera a memória de uma variável Pessoa*
 *  @param:
 *      Pessoa *P: pessoa a ter a memória liberada
 *  @return:
 *      int 0: não ocorreu nenhum erro
*/
int free_pessoa(Pessoa *P);

#endif
