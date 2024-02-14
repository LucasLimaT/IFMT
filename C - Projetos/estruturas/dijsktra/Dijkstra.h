#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define true 1
#define false 0

typedef int bool;
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
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criagrafo(int v);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);
void inicializaD(GRAFO *g, int *d, int *p, int s);
void relaxa(GRAFO *g, int *d, int *p, int u, int v);
int *dijkstra(GRAFO *g, int s);
bool existeAberto(GRAFO *g, int *aberto);
int menorDist(GRAFO *g, int *aberto, int *d);