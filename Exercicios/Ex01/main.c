#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "caminho.h"

int main(int argc, char *argv[]){

    int n;
    scanf(" %d",&n);

    float x, y;
    Ponto *P;
    Caminho *C = initialize_caminho(n);
    for(int i=0; i<n; i++){
        scanf("%f %f",&x, &y); 

        P = initialize_point(x, y);
        insert_new_point_in_caminho(C, P);
    }

    //print_caminho(C);
    printf("%.2f\n",distancia_total(C));
    free_caminho(C);

    return 0;
}
