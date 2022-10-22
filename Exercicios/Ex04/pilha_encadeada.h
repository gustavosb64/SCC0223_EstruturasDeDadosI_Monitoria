#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include "carta.h"

typedef Carta* elem;

typedef struct node Node;

typedef struct stack Stack;

Stack* CreateStack();

int IsEmpty(Stack *stack);

int AddElem(Stack *stack, elem e);

int Pop(Stack *stack, elem *e);

Node* SearchElem(Stack *stack, elem e, int *error);

int PrintStack(Stack *stack);

int FreeStack(Stack *stack);


#endif