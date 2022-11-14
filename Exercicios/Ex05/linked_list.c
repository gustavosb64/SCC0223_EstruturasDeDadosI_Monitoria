#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "large_number.h"

struct node{
    elem val;
    struct node *next;
};

struct list{
    struct node *first; 
    struct node *last; 
    size_t n_elem;
};

List* create_list(){
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL){
        printf("create_list FAILED: Memory is full.\n");
        return NULL;
    }

    list->first = NULL;
    list->last = list->first;

    list->n_elem = 0;

    return list;
}

int is_empty_list(List *list){
    if (list->n_elem == 0) return 1;
    else return 0;
}

size_t get_list_size(List *list){
    return list->n_elem; 
}

int are_lists_equal(List *L1, List *L2){
    
    if (L1->n_elem != L2->n_elem) return 0;

    Node *aux_node_1 = L1->first; 
    Node *aux_node_2 = L2->first; 

    while(aux_node_1 != NULL){
        if (aux_node_1->val != aux_node_2->val) return 0;
        aux_node_1 = aux_node_1->next;
        aux_node_2 = aux_node_2->next;
    }

    return 1;
}

static int compare_nodes(Node *N1, Node *N2){
    
    int comp = 0;
    if (N1->next != NULL){
        comp = compare_nodes(N1->next, N2->next);
    }

    if (comp == 0){
        if (N1->val == N2->val) return 0;
        if (N1->val > N2->val) return 1;
        if (N1->val < N2->val) return -1;
    }

    return comp;
}

/* Return:
 *  return > 0: L1 is larger
 *  return < 0: L2 is larger
 *  return = 0: both are equal
*/
int compare_lists(List *L1, List *L2){

    if (L1->n_elem > L2->n_elem) return 1;
    if (L1->n_elem < L2->n_elem) return -1;

    /* if they cannot be compared by size, 
     * they are compared node to node */
    return compare_nodes(L1->first, L2->first);
}

int add_last_elem_list(List *list, elem e){
    Node *aux_node = (Node *) malloc(sizeof(Node));
    if (aux_node == NULL) return 1;

    if (is_empty_list(list)){
        list->first = aux_node;
    }
    else {
        list->last->next = aux_node;
    }

    list->last = aux_node;

    list->last->val = e;
    list->last->next = NULL;

    list->n_elem++;

    return 0;
}

int add_first_elem_list(List *list, elem e){
    Node *aux_node = (Node *) malloc(sizeof(Node));
    if (aux_node == NULL) return 1;

    if (is_empty_list(list))
        aux_node->next = NULL;
    else 
        aux_node->next = list->first;

    list->first = aux_node;
    list->first->val = e;

    list->n_elem++;
    return 0;
}

int print_list(List *list){

    if(is_empty_list(list)) return 1;

    Node *aux_node = list->first;

    while(aux_node!=NULL){
        printf("%d\n",aux_node->val);
        aux_node = aux_node->next;
    }

    return 0;
}

static void print_nodes_backwards(Node *node){

    if (node->next != NULL)
        print_nodes_backwards(node->next);
    else{
        printf("%d",node->val);
        return;
    }

    /* adds '0' between the numbers when needed */
    int i=1000;
    while(node->val < i && i > 1){
        printf("0");
        i = i/10;
    }
    printf("%d",node->val);

    return;
}

int print_list_no_space(List *list){

    if(list == NULL || is_empty_list(list)) return 1;

    print_nodes_backwards(list->first);
    printf("\n");

    return 0;
}

int free_list(List *list){

    if(is_empty_list(list)){
        free(list->first);
        free(list);
        return 1;
    }

    Node *aux_node = list->first;
    Node *aux_node2;
    while(aux_node!=NULL){
        aux_node2 = aux_node;
        aux_node = aux_node->next;
        free(aux_node2);
    }
    free(aux_node);
    free(list);

    return 0;
}

List* sum_lists(List *L1, List *L2){

    List *L_res = create_list();

    Node *aux_node_1 = L1->first;
    Node *aux_node_2 = L2->first;

    int cur_sum = 0, carry = 0;
    while (aux_node_1 != NULL && aux_node_2 != NULL){

        cur_sum = (aux_node_1->val + carry) + aux_node_2->val;

        /* if the sum has more than 4 digits, the carry 
         * value must be incremented to the next node */
        if (cur_sum >= 10000){
            carry = 1;
            cur_sum -= 10000;
        } 
        else{
            carry = 0;
        }
        
        add_last_elem_list(L_res, cur_sum);
        
        aux_node_1 = aux_node_1->next;
        aux_node_2 = aux_node_2->next;
    }

    /* if there are still nodes in one of the lists, they are copied
     * into the resulting list */
    while (aux_node_1 != NULL){
        aux_node_1->val += carry;
        carry = 0;
        add_last_elem_list(L_res, aux_node_1->val);
        aux_node_1 = aux_node_1->next;
    }
    while (aux_node_2 != NULL){
        aux_node_2->val += carry;
        carry = 0;
        add_last_elem_list(L_res, aux_node_2->val);
        aux_node_2 = aux_node_2->next;
    }

    /* if carry is not 0, it must be incremented 
     * to the resulting number */
    if(carry > 0){
        add_last_elem_list(L_res, carry);
    }

    return L_res;
}

List* subtract_lists(List *L1, List *L2){

    List *L_res = create_list();

    Node *aux_node_1 = L1->first;
    Node *aux_node_2 = L2->first;

    int cur_val = 0, carry = 0;
    while (aux_node_1 != NULL && aux_node_2 != NULL){
        
        cur_val = (aux_node_1->val - carry) - aux_node_2->val;
        //printf("cur_val before: %d\n",cur_val);

        if (cur_val < 0){
            carry = 1;
            cur_val += 10000;
            //printf("cur_val after: %d\n",cur_val);
        }
        else{
            carry = 0;
        }

        add_last_elem_list(L_res, cur_val);
        
        aux_node_1 = aux_node_1->next;
        aux_node_2 = aux_node_2->next;
    }

    /* if there are still nodes in one of the lists, they are copied
     * into the resulting list */
    while (aux_node_1 != NULL){
        aux_node_1->val -= carry;
        add_last_elem_list(L_res, aux_node_1->val);
        aux_node_1 = aux_node_1->next;
    }
    while (aux_node_2 != NULL){
        aux_node_2->val -= carry;
        add_last_elem_list(L_res, aux_node_2->val);
        aux_node_2 = aux_node_2->next;
    }

    return L_res;
}
