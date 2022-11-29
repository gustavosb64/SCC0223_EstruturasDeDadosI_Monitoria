#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "operations.h"

int main(int argc, char *argv[]){
    
    Tree *T = CreateTree(); 
    fill_abb(T);
    read_operation(T); 
    free_tree(T);

    return 0;
}
