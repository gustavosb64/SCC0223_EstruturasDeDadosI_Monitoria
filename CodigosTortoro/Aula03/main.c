#include <stdio.h>
#include "Racional/racional.h"

int main()
{
    RACIONAL *racional1 = criar(5, 3);
    RACIONAL *racional2 = criar(2, 4);

    RACIONAL *soma = adicionar(racional1, racional2);
    RACIONAL *multiplicacao = multiplicar(racional1, racional2);

    imprimir(soma);
    imprimir(multiplicacao);

    apagar(racional1);
    apagar(racional2);
    apagar(soma);
    apagar(multiplicacao);

    return 0;
}
