#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Dijkstra.h"

int main()
{
    GRAFO *gr = criagrafo(6);
    
    criaAresta(gr, 0, 1, 10);
    criaAresta(gr, 0, 2, 5);
    criaAresta(gr, 2, 1, 2);
    criaAresta(gr, 1, 3, 1);
    criaAresta(gr, 2, 3, 8);
    criaAresta(gr, 2, 4, 2);
    criaAresta(gr, 4, 5, 6);
    criaAresta(gr, 3, 5, 4);
    criaAresta(gr, 3, 4, 4);
    
    int *r = dijkstra(gr, 0);
    
    for (int i = 0; i < gr->vertices; i++)
        printf("D(v0 -> v%d) = %d\n", i, r[i]);

    return 0;
}
