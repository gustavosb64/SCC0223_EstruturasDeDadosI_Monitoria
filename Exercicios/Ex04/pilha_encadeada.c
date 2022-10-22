#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"
#include "carta.h"

/*
    Escolhi manter o ponteiro *prev em Node para facilitar o processo de Pop.
    Caso não o fizesse, seria necessário percorrer toda a pilha sempre que fosse retirar um elemento com dois ponteiros, o que teria um grande custo de processamento.
    O custo de armazenamento de um ponteiro é 8 bytes, no caso da pilha, um total de n_elem*8 bytes a mais (mais possíveis bytes armazenados pelo compilador para otimização), custo baixo para a aplicação.
*/

struct node{
    elem val;
    struct node *next;
    struct node *prev;
};

struct stack{
    Node *first;
    Node *last;
    int n_elem;
};

Stack* CreateStack(){
    Stack *stack = (Stack *) malloc(sizeof(Stack)); 
    
    stack->first = NULL; 
    stack->last = stack->first; 

    stack->n_elem = 0; 

    return stack;
}

int IsEmpty(Stack *stack){
    if (stack->n_elem == 0) return 1;
    else return 0;
}

int AddElem(Stack *stack, elem e){
    Node *aux_node = (Node *) malloc(sizeof(Node));
    if (aux_node == NULL) return 1;

    if (IsEmpty(stack)){
        stack->first = aux_node;
        stack->first->prev = NULL;
    }
    else {
        stack->last->next = aux_node; 
        aux_node->prev = stack->last;
    }

    stack->last = aux_node;

    stack->last->val = e;
    stack->last->next = NULL;

    stack->n_elem++;

    return 0;
}

int Pop(Stack *stack, elem *e){

    if(IsEmpty(stack)) return 1;

    *e = stack->last->val;
    
    Node *aux_node = stack->last->prev;

    if (aux_node != NULL)
        aux_node->next = NULL; 

    free(stack->last);
    stack->last = aux_node;

    stack->n_elem--;

    return 0;
}

Node* SearchElem(Stack *stack, elem e, int *error){

    if(IsEmpty(stack)){
        *error = 1;
        return NULL;
    }

    Node *dest_node;
    dest_node = stack->first;

    while (dest_node != NULL){
        if (dest_node->val == e){
            return dest_node;
        }
        dest_node = dest_node->next;
    }
    
    *error = 2;
    return NULL;
}

int PrintStack(Stack *stack){

    if(IsEmpty(stack)) return 1;
    
    Node *aux_node = stack->first;
    
    while(aux_node!=NULL){
        print_carta(aux_node->val);
        aux_node = aux_node->next;
    }

    return 0;
}

int FreeStack(Stack *stack){
    
    if(IsEmpty(stack)){
        free(stack);
        return 1;
    }
    
    Node *aux_node = stack->first;
    Node *aux_node2 = stack->first;
    
    while(aux_node!=NULL){
        free_carta(aux_node->val);

        aux_node2 = aux_node->next;
        free(aux_node);

        aux_node = aux_node2;
    }

    free(stack);

    return 0;
}
