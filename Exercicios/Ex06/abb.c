#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "client.h"

typedef struct node{
    elem key;
    Client *client;
    struct node *left;
    struct node *right;
}Node;

typedef struct tree{
    Node *root;
}Tree;

Tree* CreateTree(){
    Tree *T = (Tree *) malloc(sizeof(Tree));
    T->root = NULL;
    return T;
}

int IsEmptyTree(Tree *T){
    if (T->root == NULL) return 1;
    else return 0;
}

int TreeHeight(Node *node){
    int n_left = 0;
    int n_right = 0;

    if (node->left != NULL){
        n_left = TreeHeight(node->left);
    }
    if (node->right != NULL){
        n_right = TreeHeight(node->right);
    }

    if (n_left > n_right) return (n_left+1);
    else return (n_right+1);
}

static Node* search_node(Node *node, elem key){

    if (node == NULL) return NULL;
    
    if (node->key == key){ 
        return node;
    }

    if (node->key > key){
        return search_node(node->left, key);
    }

    return search_node(node->right, key);
}

Node* search_abb(Tree *T, elem key){
   return search_node(T->root, key);
}

int IsInABB(Tree *T, elem key){

    if (IsEmptyTree(T)) return 1;

    if (search_node(T->root, key) == NULL) return 2;
    return 0;
}

int add_abb(Tree *T, Client *client){

    if (T == NULL) return 1;
    if (client == NULL) return 2;

    char *s_cpf = get_cpf(client);
    elem key = cpf_to_longint(s_cpf);

    return InsertNode(&T->root, key, client);
}

int InsertNode(Node **node, elem key, Client *client){

    if (*node == NULL){
        (*node) = (Node *) malloc(sizeof(Node));
        (*node)->key = key;
        (*node)->client = client;
        (*node)->left = NULL;
        (*node)->right = NULL;

        return 0;
    }
    if (key == (*node)->key) return 1;

    if (key < (*node)->key) InsertNode(&(*node)->left, key, client);
    else InsertNode(&(*node)->right, key, client);

    return 0;
}

Node* SearchLowest(Node *node, Node **aux_node_parent){
    Node *aux_node = node;

    while (aux_node->left != NULL){    
        *aux_node_parent = aux_node;
        aux_node = aux_node->left;
    }

    return aux_node;
}

Node* SearchGreatest(Node *node, Node **aux_node_parent){
    Node *aux_node = node;

    while (aux_node->right != NULL){    
        *aux_node_parent = aux_node;
        aux_node = aux_node->right;
    }

    return aux_node;
}

Node* SearchWithParent(Node *node, Node **parent, elem key){

    if (node == NULL) return NULL;
    
    if (node->key == key){ 
        return node;
    }

    (*parent) = node; 

    if (node->key > key){
        return SearchWithParent(node->left, &(*parent), key);
    }

    return SearchWithParent(node->right,&(*parent), key);

}

static void free_node(Node *p){
    if (p != NULL){
        free_node(p->left); 
        Node *p_aux = p->right;
        free_client(p->client);
        free(p);
        free_node(p_aux); 
    }
    return;
}


static int remove_node(Tree *T, elem key){
    Node *aux_node;

    Node *parent = NULL;
    Node *node = SearchWithParent(T->root, &parent, key);

    print_node(node);

    if (node->left != NULL && node->right != NULL){

        Node *aux_node_parent = node; 
        aux_node = SearchLowest(node->right, &aux_node_parent);        

        if (aux_node->right != NULL){
            if (aux_node_parent == node) node->right = aux_node->right;
            else aux_node_parent->left = aux_node->right;
        }
        else{
            aux_node_parent->left = NULL;
        }

        free_client(node->client);
        node->key = aux_node->key;
        node->client = aux_node->client;

        free(aux_node);

        return 0;
    }

    if (node->left == NULL && node->right == NULL) aux_node = NULL; 
    else if (node->left != NULL && node->right == NULL) aux_node = node->left;
    else if (node->left == NULL && node->right != NULL) aux_node = node->right;

    if (parent != NULL){
        if (parent->key > node->key) parent->right = aux_node;
        else parent->left = aux_node;
    }
    else T->root = aux_node; 

    free(node);

    return 0;
}

int remove_from_abb(Tree *T, Client *client){

    if (T == NULL) return 1;
    if (client == NULL) return 2;

    char *s_cpf = get_cpf(client);
    elem key = cpf_to_longint(s_cpf);

    return remove_node(T, key);
}

void print_pre_order(Node *node){

    if(node == NULL) return;

    /* print zeros from CPF when necessary */
    long int li = 10000000000;
    while (node->key < li && li > 1){
        printf("0");
        li = li/10;
    }
    printf("%ld\n",node->key);

    if(node->left != NULL) print_pre_order(node->left);
    if(node->right != NULL) print_pre_order(node->right); 

    return;
}

void PrintPosOrdem(Node *node){

    if(node == NULL) return;
    if(node->left != NULL) print_pre_order(node->left);
    if(node->right != NULL) print_pre_order(node->right);
    //printf("%ld\n",node->key);
    print_client(node->client);

    return;
}

void PrintEmOrdem(Node *p){
    if (p != NULL){
        PrintEmOrdem(p->left); 
        //printf("%ld\n",p->key);
        print_client(p->client);
        PrintEmOrdem(p->right); 
    }

    return;
}

int print_node(Node *node){
    if (node == NULL) return 1;
    return print_client(node->client);;
}

void print_tree(Tree *T){
    printf("Preorder\n");
    print_pre_order(T->root);
    printf("\n");
    return;
}

void free_tree(Tree *T){
    free_node(T->root);
    free(T);
    return;
}

void fill_abb(Tree *T){

    int n;
    scanf("%d ", &n);
    for (int i=0; i<n; i++){
        Client *C = register_client();
        add_abb(T, C);
    }

    return;
}
