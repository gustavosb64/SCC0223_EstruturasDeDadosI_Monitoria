#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct registro Registro;

/*
 * Inicializa uma variável do tipo Registro*
 *  @return:
 *      Registro*: Registro* criado com os dados padrão
*/
Registro* criar_registro();

/*
 * Adiciona uma pessoa com os dados fornecidos à lista de pessoas de Registro *R
 *  @param:
 *      Registro *R: registro onde se inserirá a nova Pessoa* 
 *      char *nome: nome da pessoa cadastrada 
 *      int idade: idade da pessoa cadastrada 
 *      int cpf: CPF da pessoa cadastrada 
 *      double v1: v1 da pessoa cadastrada 
 *      double v2: v2 da pessoa cadastrada 
 *  @return:
 *      Registro*: Registro* atualizado
*/
Registro* adicionar_pessoa(Registro *R, char *nome, int idade, int cpf, double v1, double v2);

/*
 * Imprime na tela os dados de uma Registro *R
 *  @param:
 *      Registro *R: registro a ter os dados as pessoas da lista printados
 *  @return:
 *      int 0: não ocorreu nenhum erro
*/
void print_registro(Registro *R);

/*
 * Libera a memória de uma variável Registro*
 *  @param:
 *      Registro *R: registro a ter a memória liberada
 *  @return:
 *      int 0: não ocorreu nenhum erro
*/
int free_registro(Registro *R);

#endif 
