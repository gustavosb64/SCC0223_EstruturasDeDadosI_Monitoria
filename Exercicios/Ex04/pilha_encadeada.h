#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

typedef int elem;

typedef struct node_ Node;

typedef struct stack_ Stack;

Stack* CreateStack();

int IsEmpty(Stack *stack);

int AddElem(Stack *stack, elem e);

int Pop(Stack *stack, elem *e);

Node* SearchElem(Stack *stack, elem e, int *error);

int PrintStack(Stack *stack);

#endif
