#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct grafo {
    int vertice;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criagrafo(int v);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);
void imprime(GRAFO *gr);