#ifndef ABB_H
#define ABB_H

#include "client.h"

typedef long int elem;

typedef struct node Node;

typedef struct tree Tree;

Tree* CreateTree();

int IsEmptyTree(Tree *T);

int TreeHeight(Node *node);

Node* search_abb(Tree *T, elem key);

int IsInABB(Tree *T, elem key);

int add_abb(Tree *T, Client *client);

int InsertNode(Node **node, elem key, Client *client);

Node* SearchLowest(Node *node, Node **aux_node_parent);

Node* SearchGreatest(Node *node, Node **aux_node_parent);

Node* SearchWithParent(Node *node, Node **parent, elem key);

int remove_from_abb(Tree *T, Client *client);

void print_pre_order(Node *node);

void PrintPosOrdem(Node *node);

void PrintEmOrdem(Node *p);

int print_node(Node *node);

void print_tree(Tree *T);

void free_tree(Tree *T);

void fill_abb(Tree *T);


#endif