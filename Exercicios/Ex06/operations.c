#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "client.h"
#include "abb.h"
#include "operations.h"

int exe_op_insert(Tree *T){

    if (T == NULL) return 1;

    Client *C = register_client();
    add_abb(T, C);
    print_tree(T);
     
    return 0;
}

int exe_op_remove(Tree *T){

    if (T == NULL) return 1;

    Client *C = register_client();
    remove_from_abb(T, C);
    free_client(C);

    print_tree(T);

    return 0;
}

int exe_op_search(Tree *T){

    if (T == NULL) return 1;

    /* read cpf from stdin as a string and
     * converts it to longint */
    char* s_cpf = read_word();
    long int cpf = cpf_to_longint(s_cpf);
    free(s_cpf);

    Node *node = search_abb(T, cpf);
    print_node(node);

    return 0;
}

void read_operation(Tree *T){

    char op;
    scanf("%c ", &op);

    switch (op){
        case 'I':
            exe_op_insert(T);
            break;

        case 'R':
            exe_op_remove(T);
            break;

        case 'B':
            exe_op_search(T);
            break;
    }
}
