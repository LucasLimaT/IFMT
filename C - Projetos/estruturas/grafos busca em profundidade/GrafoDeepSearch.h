#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef enum { BRANCO, AMARELO, VERMELHO } cores;
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

void profundidade(GRAFO *g);
void visitaP(GRAFO *g, int u, int *cor);