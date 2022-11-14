#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef int elem;

typedef struct node Node;

typedef struct list List;

List* create_list();

int is_empty_list(List *list);

size_t get_list_size(List *list);

int are_lists_equal(List *L1, List *L2);

int compare_lists(List *L1, List *L2);

int add_last_elem_list(List *list, elem e);

int add_first_elem_list(List *list, elem e);

int print_list(List *list);

int print_list_no_space(List *list);

int free_list(List *list);

Node* get_next_node(List *list, Node *node);

List* sum_lists(List *L1, List *L2);

List* subtract_lists(List *L1, List *L2);


#endif