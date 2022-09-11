#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *f_10 = fopen("numberlist10.dat", "rb");

    int *v10 = (int *) malloc(10 * sizeof(int)); 

    for (int i=0; i<10; i++){
        fread(&v10[i], 1, sizeof(int), f_10);
    }

    free(v10);

    fclose(f_10);

    return 0;
}
