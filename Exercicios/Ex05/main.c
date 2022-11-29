#include <stdio.h>
#include "large_number.h"

int main(){

    /* reads number of operations */
    int n_operations;
    scanf("%d ", &n_operations);

    /* reads and executes the requested operations */
    for (int i=0; i < n_operations; i++){
        read_operation();
    }

    return 0;
}
