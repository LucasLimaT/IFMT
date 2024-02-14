#include <stdio.h>
#include <stdlib.h>
#include "GrafoLista.h"

int main()
{
    // da onde/ para onde/ peso
    GRAFO *gr = criagrafo(5);
    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);
    
    imprime(gr);

    return 0;
}
