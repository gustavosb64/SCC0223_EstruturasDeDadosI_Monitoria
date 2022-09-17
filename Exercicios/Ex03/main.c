#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FAIL -1

//Function for a ITERATIVE binary search
int binary_search_iterative(int *v, int key, int start, int end){
    //0 - caso base (sem sucesso)

    while (start <= end){ //c
        int c = (int) ( (start + end) / (2.0)); //2a

        if (v[c] == key) return c; //c

        if (key < v[c]) end = c-1; //c + a

        if (key > v[c]) start = c+1; //c + a
    }

    return FAIL;

}

//Function for a RECURSIVE binary search (NOT RECOMMENDED)
int binary_search_recursive(int *v, int key, int start, int end){

    if (start > end) return FAIL; //c

    int c = (int) ( (start + end) / (2.0)); // 2a
    
    if (v[c] == key) return c;  //c
    
    if (key < v[c]) //c
        return binary_search_recursive(v, key, start, c-1); //b + a

    //if (key > v[c]) //c
    return binary_search_recursive(v, key, c+1, end);   //b + a
}

int sequencial_search(int *v, int key, int n){

    for (int i=0; i<n; i++)
        if (v[i] == key) return i;

    return FAIL;
}

int reverse_array(int *v, int n){

    int m = n/2;
    int aux = v[n-1];
    for (int i=0; i<m; i++){
        aux = v[i]; 
        v[i] = v[n-1-i];
        v[n-1-i] = aux;
    }

    return 0;
}

int print_array(int *v, int n){

    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[]){

    FILE *f_100 = fopen("numberlist5000.dat", "rb");
    int *v100 = (int *) malloc(5000 * sizeof(int)); 

    //time_t start, end;
    clock_t t;
    time_t start, end;

    for (int i=0; i<5000; i++){
        fread(&v100[i], 1, sizeof(int), f_100);
    }
    t = clock();
    start = time(NULL);

    //print_array(v100, 1000);
    sequencial_search(v100, 1003041923, 5000); 
    end = time(NULL);

    clock_t c = clock();
    printf("time: %ld - %ld = %ld", end, start, end-start);
    printf("\nclock: %ld-%ld = %ld", c, t, c-t);

    free(v100);
    fclose(f_100);

    return 0;
}
